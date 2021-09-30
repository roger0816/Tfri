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

