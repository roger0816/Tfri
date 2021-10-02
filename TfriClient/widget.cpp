#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

  //  m_api.query();

//    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");

//    db.setDatabaseName("tfri");

//    db.setUserName("root");

//    db.setPassword("Aa111111");

//    db.setPort(3306);

//    db.open();

//    qDebug()<<db.isDriverAvailable("QMYSQL");

qDebug()<<LIB.LibTest();



}

Widget::~Widget()
{
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


    for(int i=0;i<6;i++)
    {
        data.listName.append(QString("test0%1.jpg").arg(i));

        data.listData.append(imgData);
    }


    QByteArray input = data.enCodeJson();

    input.append(QString(END_DATA).toLatin1());


   QByteArray output;

   qDebug()<<"send size : "<<input.size();

   LIB.network()->connectHost("127.0.0.1","6000",input,output);
}

void Widget::on_pushButton_2_clicked()
{

    QByteArray input;

    QByteArray output;

    LIB.network()->connectHost("127.0.0.1","6000",input,output);

}
