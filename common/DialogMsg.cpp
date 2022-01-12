#include "DialogMsg.h"
#include "ui_DialogMsg.h"

DialogMsg::DialogMsg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogMsg)
{
    ui->setupUi(this);

    setWindowTitle("");

//    setWindowOpacity(1);

//    setWindowFlag(Qt::FramelessWindowHint);


    m_listBtn<<ui->btn0<<ui->btn1<<ui->btn2<<ui->btn3;

    foreach(QPushButton *btn ,m_listBtn)
    {
        connect(btn,&QPushButton::clicked,this,&DialogMsg::slotBtn);
    }

    ui->stackedWidget->setCurrentIndex(0);
}

DialogMsg::~DialogMsg()
{
    delete ui;
}

void DialogMsg::setMsg(QString sTitle, QString sMsg, QStringList listBtn)
{
    ui->lbTitle->setText(sTitle);

    ui->lbMsg->setText(sMsg);

    for(int i=0;i<m_listBtn.length();i++)
    {

        if(i<listBtn.length())
        {
            m_listBtn.at(i)->show();

            m_listBtn.at(i)->setText(listBtn.at(i));
        }
        else
        {
            m_listBtn.at(i)->hide();
        }


    }



}

void DialogMsg::setInput(QString sTitle, QString sMsg, QStringList listBtn)
{
     ui->stackedWidget->setCurrentWidget(ui->pageInput);

     ui->lbTitle->setText(sTitle);

     ui->lbInputMsg->setText(sMsg);

     for(int i=0;i<m_listBtn.length();i++)
     {

         if(i<listBtn.length())
         {
             m_listBtn.at(i)->show();

             m_listBtn.at(i)->setText(listBtn.at(i));
         }
         else
         {
             m_listBtn.at(i)->hide();
         }


     }
}

QString DialogMsg::getInput()
{
    return ui->lineEdit->text();
}

void DialogMsg::slotBtn()
{
    QPushButton *btn = dynamic_cast<QPushButton*>(sender());

    int iRe =m_listBtn.indexOf(btn);

    done(iRe);
}
