#include "LayerKeyborad.h"
#include "ui_LayerKeyborad.h"

LayerKeyborad* LayerKeyborad::m_kb = 0;

LayerKeyborad *LayerKeyborad::Instance(QWidget *parent)
{
    if(m_kb == 0 )
        m_kb = new LayerKeyborad();

    if(parent != 0)
        m_kb->setParent(parent);

    return m_kb;
}

void LayerKeyborad::setBinding(QLineEdit *lineEdit)
{

    disconnect();
    if(lineEdit)
    {

        connect(this,SIGNAL(signalText(QString)),lineEdit,SLOT(setText(QString)));

        setShow(lineEdit->text());
    }
    else
    {
        qDebug()<<"lineEdit null !!??";
    }
}

void LayerKeyborad::setBinding(QLabel *lb)
{
    disconnect();
    if(lb)
    {

        connect(this,SIGNAL(signalText(QString)),lb,SLOT(setText(QString)));

        setShow(lb->text());
    }
    else
    {
        qDebug()<<"label null !!??";
    }
}



LayerKeyborad::LayerKeyborad(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LayerKeyborad)
{
    ui->setupUi(this);
    m_lbTooltip = new QLabel(this);

    QFont f;

    f.setPointSize(30);

    m_lbTooltip->setFont(f);

    m_lbTooltip->setAlignment(Qt::AlignHCenter | Qt::AlignCenter);

    m_lbTooltip->move(0,0);


    m_lbTooltip->setStyleSheet(QLatin1String("background-color: rgb(255,255,255);\n"
                                             "    border-style: outset;\n"
                                             "    border-top-width: 2px;\n"
                                             "  border-right-width: 2px;\n"
                                             "  border-left-width: 2px;\n"
                                             "    border-radius: 10px;\n"
                                             "    border-color: gray;\n"
                                             "\n"
                                             "\n"
                                             "    padding: 2px;"));


    m_lbTooltip->hide();


    m_btnClear = new QPushButton(ui->lineEdit);

    m_btnClear->setStyleSheet(QLatin1String("background-color: rgba(255,255,255,0);\n"
                                            "    border-style: outset;\n"
                                            "    border-top-width: 2px;\n"
                                            "  border-right-width: 2px;\n"
                                            "  border-left-width: 2px;\n"
                                            "    border-radius: 10px;\n"
                                            "    border-color: rgba(255,255,255,0);\n"
                                            " font: bold 28px; \n"
                                            "    padding: 2px;"));

    m_btnClear->setText("×");

    m_btnClear->setFocusPolicy(Qt::NoFocus);

    m_btnClear->connect(m_btnClear,SIGNAL(clicked()),this,SLOT(slotClear()));


    iniWord();

    iniSpWord();

    ui->stackedWidget->setCurrentIndex(0);

    m_ani.setTargetObject(ui->wBg);

    m_ani.setDuration(100);

    m_ani.setPropertyName("pos");

    m_ani.connect(&m_ani,SIGNAL(finished()),this,SLOT(slotAniFinish()));

    m_wBlockUi = new QWidget(this);

    hide();

}

LayerKeyborad::~LayerKeyborad()
{
    delete ui;
}


void LayerKeyborad::setShow(QString sText)
{
    ui->lineEdit->setText(sText);

    ui->lineEdit->setCursorPosition(sText.length());

    ui->lineEdit->setFocus();

    show();

    aniShow();

}

void LayerKeyborad::slotWordPressed()
{

    QPushButton *btn = dynamic_cast<QPushButton*>(sender());
    if(btn!=ui->btnSpace)
        callToolTip(true,btn);

}

void LayerKeyborad::slotWordReleased()
{
    callToolTip(false);

    QPushButton *btn=dynamic_cast<QPushButton*>(sender());

    QString sKeyin=" ";


    if(btn!=ui->btnSpace)
        sKeyin = btn->text();

    if(btn==ui->btnPoint)
        sKeyin = ".";

    QString st=ui->lineEdit->text();

    int iIdx= ui->lineEdit->cursorPosition();

    qDebug()<<iIdx;

    st.insert(iIdx,sKeyin);

    ui->lineEdit->setText(st);

    ui->lineEdit->setCursorPosition(iIdx+sKeyin.length());

    ui->lineEdit->setFocus();
}

void LayerKeyborad::callToolTip(bool bShow, QPushButton *target)
{

    if(bShow && target!=0)
    {

        m_lbTooltip->resize(target->size()*1.5);

        m_lbTooltip->setText(target->text());

        QPoint p=target->mapTo(this,QPoint(0,0));

        m_lbTooltip->move(p.x()+(target->width()-m_lbTooltip->width())/2,p.y()-m_lbTooltip->height()+5);

    }

    m_lbTooltip->setVisible(bShow);

}

void LayerKeyborad::iniWord()
{
    m_listBtnWord<<ui->btnA<<ui->btnB<<ui->btnC<<ui->btnD<<ui->btnE<<ui->btnF<<ui->btnG<<ui->btnH<<ui->btnI \
                <<ui->btnJ<<ui->btnK<<ui->btnL<<ui->btnM<<ui->btnN<<ui->btnO<<ui->btnP<<ui->btnQ<<ui->btnR \
               <<ui->btnS<<ui->btnT<<ui->btnU<<ui->btnV<<ui->btnW<<ui->btnX<<ui->btnY<<ui->btnZ;


    foreach(QPushButton *btn ,m_listBtnWord)
    {
        btn->connect(btn,SIGNAL(pressed()),this,SLOT(slotWordPressed()));

        btn->connect(btn,SIGNAL(released()),this,SLOT(slotWordReleased()));

    }


    ui->btnSpace->connect(ui->btnSpace,SIGNAL(pressed()),this,SLOT(slotWordPressed()));

    ui->btnSpace->connect(ui->btnSpace,SIGNAL(released()),this,SLOT(slotWordReleased()));

    ui->btnPoint->connect(ui->btnPoint,SIGNAL(pressed()),this,SLOT(slotWordPressed()));

    ui->btnPoint->connect(ui->btnPoint,SIGNAL(released()),this,SLOT(slotWordReleased()));
}

void LayerKeyborad::iniSpWord()
{
    m_listBtnSpWord<<ui->btnSp00<<ui->btnSp01<<ui->btnSp02<<ui->btnSp03<<ui->btnSp04<<ui->btnSp05<<ui->btnSp06\
                  <<ui->btnSp07<<ui->btnSp08<<ui->btnSp09<<ui->btnSp10<<ui->btnSp11<<ui->btnSp12<<ui->btnSp13\
                 <<ui->btnSp14<<ui->btnSp15<<ui->btnSp16<<ui->btnSp18<<ui->btnSp19<<ui->btnSp20\
                <<ui->btnSp21<<ui->btnSp22<<ui->btnSp23;

    //特殊字有二種，所以.ui上寫的只是方式辨視，真正值寫在這

    m_listTextSp[0]<<"1"<<"2"<<"3"<<"4"<<"5"<<"6"<<"7"<<"8"<<"9"<<"0"<<"-"<<"/"<<":"<<";"<<"("<<")"<<"$"<<"@"<<"\""<<","<<"?"<<"!"<<"'";

    m_listTextSp[1]<<"["<<"]"<<"{"<<"}"<<"#"<<"%"<<"^"<<"*"<<"+"<<"="<<"_"<<"\\"<<"|"<<"~"<<"<"<<">"<<"£"<<"¥"<<"•"<<","<<"?"<<"!"<<"'";


    foreach(QPushButton *btn ,m_listBtnSpWord)
    {
        btn->connect(btn,SIGNAL(pressed()),this,SLOT(slotWordPressed()));

        btn->connect(btn,SIGNAL(released()),this,SLOT(slotWordReleased()));
    }


    on_btnSpChange_clicked(false);


}




void LayerKeyborad::resizeEvent(QResizeEvent *)
{
    m_wBlockUi->setGeometry(rect());

    m_wBlockUi->setVisible(false);
}

void LayerKeyborad::showEvent(QShowEvent *)
{
    m_btnClear->resize(ui->lineEdit->height(),ui->lineEdit->height());

    m_btnClear->move(ui->lineEdit->width()-m_btnClear->width()-10,(ui->lineEdit->height()-m_btnClear->height())/2);

    ui->lineEdit->setFocus();

}

void LayerKeyborad::aniShow()
{

    raise();

    ui->wBg->move(QPoint(0,height()+10));

    m_wBlockUi->setVisible(true);

    m_ani.setStartValue(QPoint(0,height()+10));

    m_ani.setEndValue(QPoint(0,0));

    m_ani.start();
}

void LayerKeyborad::aniHide()
{
    m_wBlockUi->setVisible(true);

    m_ani.setStartValue(QPoint(0,0));

    m_ani.setEndValue(QPoint(0,height()+10));

    m_ani.start();
}

void LayerKeyborad::slotAniFinish()
{

    if(ui->wBg->pos()!=QPoint(0,0))
    {
        ui->lineEdit->setText("");
        hide();
    }

    m_wBlockUi->setVisible(false);
}





void LayerKeyborad::on_btnChange_clicked(bool checked)
{
    if(checked)
    {
        ui->btnChange->setText("ABC");
        ui->stackedWidget->setCurrentIndex(1);
    }
    else
    {
        ui->btnChange->setText("123");
        ui->stackedWidget->setCurrentIndex(0);
    }
}

void LayerKeyborad::on_btnSpace_clicked()
{

}



void LayerKeyborad::on_btnReturn_clicked()
{
    qDebug()<<"send : "<<ui->lineEdit->text();

    emit signalText(ui->lineEdit->text());

    aniHide();
}


void LayerKeyborad::on_btnSpChange_clicked(bool checked)
{
    int iSpIdx=0;

    if(checked)
    {
        ui->btnSpChange->setText("123");
        iSpIdx=1;
    }
    else
    {
        ui->btnSpChange->setText("#+=");
    }

    for(int i=0;i<m_listBtnSpWord.length();i++)
    {
        m_listBtnSpWord[i]->setText(m_listTextSp[iSpIdx].at(i));
    }
}

void LayerKeyborad::on_btnShift_clicked(bool checked)
{

    foreach (QPushButton *btn, m_listBtnWord)
    {
        if(checked)
            btn->setText(btn->text().toLower());
        else
            btn->setText(btn->text().toUpper());
    }

}

void LayerKeyborad::on_btnSub2_clicked()
{
    on_btnSub_clicked();
}

void LayerKeyborad::on_btnSub_clicked()
{
    QString st=ui->lineEdit->text();

    int iIdx= ui->lineEdit->cursorPosition();

    if(iIdx>0)
        iIdx--;

    st.remove(iIdx,1);

    ui->lineEdit->setText(st);

    ui->lineEdit->setCursorPosition(iIdx);
}

void LayerKeyborad::slotClear()
{
    ui->lineEdit->setText("");
}


void LayerKeyborad::on_btnCancel_clicked()
{
    ui->lineEdit->setText("");
    aniHide();
}
