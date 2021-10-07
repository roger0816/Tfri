#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("TFRI環境辨視");
    Global::INS(dynamic_cast<QWidget*>(ui->wBg));
   // GLOBAL.showBlockLoading();
    //157.245.142.72
    CSQL.open("local.sqlite");

    CCallApi::INS().openConnect();

    ui->btnTestPage->hide();


    //    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");

    //    db.setDatabaseName("tfri");

    //    db.setUserName("root");

    //    db.setPassword("Aa111111");

    //    db.setPort(3306);

    //    db.open();

    //    qDebug()<<db.isDriverAvailable("QMYSQL");

    qDebug()<<LIB.LibTest();

    ui->stackedWidget->setCurrentIndex(0);

    ui->btnTestPage->hide();

}

Widget::~Widget()
{
    CCallApi::INS().closeConnect();
    delete ui;
}


void Widget::on_pushButton_clicked()
{


    CSendData data;

    data.sAciton = ACT_SEND_DATA;

    data.sUser ="rogerTest";


    QFile f("../test01.jpg");

    QByteArray imgData;
    if(f.open(QIODevice::ReadOnly))
    {
        imgData = f.readAll().toBase64();

        f.close();
    }


    for(int i=0;i<ui->spinBox->value();i++)
    {
        data.listName.append(QString("test0%1.jpg").arg(i));

        data.listData.append(imgData);
    }


    QByteArray input = data.enCodeJson();



    QByteArray output;

    qDebug()<<"send size : "<<input.size();

    LIB.network()->connectHost("157.245.142.72","6000",input,output);
}

void Widget::on_pushButton_2_clicked()
{

    CSendData data;

    data.sAciton = ACT_HISTORY_DATA;

    data.sUser ="rogerTest";

    QByteArray input = data.enCodeJson();


    QByteArray output;

    LIB.network()->connectHost("127.0.0.1","6000",input,output);

    qDebug()<<"get history re :"<<output;
}

void Widget::on_btnTestPage_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->pageTest);
}

void Widget::on_btnTestBack_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->pageLogin);
}

void Widget::on_btnLogin_clicked()
{
    bool bOk = false;

    if(ui->txUser->text().trimmed()=="" || ui->txPassword->text().trimmed() =="")
    {
        ui->lbMsg->setText("請輸入帳號/密碼");

        return ;
    }
    else
    {
        QString sErrorMsg;

        int iType = CCallApi::INS().callLogin(ui->txUser->text().trimmed(),ui->txPassword->text().trimmed(),sErrorMsg);

        if(iType!=0)
            bOk = true;

    }


    if(bOk)
    {
        ui->lbMsg->setText("登入成功");
        ui->stackedWidget->setCurrentWidget(ui->pageAnalyze);
    }
    else
    {
        ui->lbMsg->setText("帳號密碼錯誤");
    }
}
