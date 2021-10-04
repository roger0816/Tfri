#include "Vkeybord.h"
#include "ui_Vkeybord.h"

Vkeybord *Vkeybord::m_pInstance = 0;



Vkeybord::Vkeybord(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Vkeybord)
{
    ui->setupUi(this);

    m_bIsLower = true;

    m_lbWaitKeyIn=NULL;
    m_listNumWord<<ui->btn1<<ui->btn2<<ui->btn3<<ui->btn4<<ui->btn5<<ui->btn6<<ui->btn7<<ui->btn8<<ui->btn9<<ui->btn0;

    m_listEnWord<<ui->a<<ui->b<<ui->c<<ui->d<<ui->e<<ui->f<<ui->g<<ui->h<<ui->i<<ui->j<<ui->k<<ui->l<<ui->m
               <<ui->n<<ui->o<<ui->p<<ui->q<<ui->r<<ui->s<<ui->t<<ui->u<<ui->v<<ui->w<<ui->x<<ui->y<<ui->z;


    m_listSpecailWord<<ui->space<<ui->back<<ui->end<<ui->mouse<<ui->add<<ui->sub<<ui->slice<<ui->enter<<ui->close<<ui->shift;



    for(int i=0;i<m_listEnWord.length();i++)
    {
        QString sUpper;
        QString sLower;
        sLower=m_listEnWord[i]->objectName();
        sUpper=m_listEnWord[i]->objectName().toUpper();
        //        QStringList listText;
        //        listText<<sLower<<sUpper;
        //        m_listEnWord[i]->setListText(listText);
        m_listEnWord[i]->setText(sLower);
        connect(m_listEnWord[i],SIGNAL(clicked()),this,SLOT(slotInput()));
    }

    for(int j=0;j<m_listNumWord.length();j++)
    {
        int iNum=j+1;
        if(iNum>9)
            iNum=0;
        QString st=QString::number(iNum);

        m_listNumWord[j]->setListText(QStringList(st));
        connect(m_listNumWord[j],SIGNAL(clicked()),this,SLOT(slotInput()));
    }

    ui->back->setText("backspace");
    ui->mouse->setText("@");
    ui->add->setText("+");
    ui->sub->setText("-");
    ui->slice->setText("/");
    ui->end->setText(".");

    ui->enter->setText("Enter");
    ui->close->setText("close");
    ui->shift->setText("shift");


    for(int k=0;k<m_listSpecailWord.length();k++)
    {
        connect(m_listSpecailWord[k],SIGNAL(clicked()),this,SLOT(slotInput()));
    }


    // connect(ui->btnClose,SIGNAL(released()),this,SLOT(hide()));
    // connect(ui->btnShift,SIGNAL(clicked(bool)),this,SLOT(slotChangeUpper(bool)));

    m_ani=new QPropertyAnimation(this,"pos");
    m_ani->setDuration(200);

    //ui->wBg->move(0,1920);



}

Vkeybord::~Vkeybord()
{
    delete ui;
}

void Vkeybord::setFontSize(QFont font)
{
    ui->lineEdit->setFont(font);

    foreach (ItemKey *item, m_listNumWord)
    {
        item->setFont(font);
    }

    foreach (ItemKey *item, m_listEnWord)
    {
        item->setFont(font);
    }

    foreach (ItemKey *item, m_listSpecailWord)
    {
        item->setFont(font);
    }
}

void Vkeybord::slotInput()
{
    ItemKey *key=dynamic_cast<ItemKey*>(sender());

    QString sOld=ui->lineEdit->text();

    QString sInput=key->text();

    qDebug()<<"key text : "<<sInput;

    if(key==ui->space)
        sInput=" ";
    else if(key==ui->end)
        sInput=".";
    else if(key==ui->mouse)
    {
        sInput="@";
    }
    else if(key==ui->add)
    {
        sInput="+";
    }
    else if(key==ui->sub)
    {
        sInput="-";
    }
    else if(key==ui->slice)
    {
        sInput="/";
    }
    else if(key==ui->enter)
    {
        slotEnter();
    }
    else if(key==ui->close)
    {
        hide();
    }
    else if(key==ui->shift)
    {
        slotChangeUpper();
    }


    if(key==ui->back)
    {
        ui->lineEdit->setText(sOld.left(sOld.length()-1));
    }
    else
    {
        ui->lineEdit->setText(sOld+sInput);
    }
}

void Vkeybord::slotEnter()
{
    m_lbWaitKeyIn->setText(ui->lineEdit->text());
    qDebug()<<"parent name : "<<m_lbWaitKeyIn->parent()->objectName()<<" ,lb objname : "<<m_lbWaitKeyIn->objectName()<<" lbText: "<<m_lbWaitKeyIn->text();

    ui->lineEdit->setText("");
    m_ani->setStartValue(QPoint(0,0));
    m_ani->setEndValue(QPoint(0,height()));

    QEventLoop loop;
    loop.connect(m_ani,SIGNAL(finished()),&loop,SLOT(quit()));
    m_ani->start();
    loop.exec();
    hide();

    loop.disconnect();
}

void Vkeybord::slotChangeUpper()
{

    for(int i=0;i<m_listEnWord.length();i++)
    {
        QString sText=m_listEnWord[i]->text();

        if(m_bIsLower)
            sText=sText.toUpper();
        else
            sText=sText.toLower();

        m_listEnWord[i]->setText(sText);
    }

    m_bIsLower = !m_bIsLower;
}

void Vkeybord::slotOpenKeyBord(QLabel *lb)
{
    // ui->wBg->move(0,height());
    ui->lineEdit->setText(lb->text());
    m_ani->setStartValue(QPoint(0,height()));
    m_ani->setEndValue(QPoint(0,0));
    m_ani->start();
    show();
    m_lbWaitKeyIn=NULL;
    m_lbWaitKeyIn=lb;


}
