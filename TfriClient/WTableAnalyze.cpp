#include "WTableAnalyze.h"
#include "ui_WTableAnalyze.h"

WTableAnalyze::WTableAnalyze(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WTableAnalyze)
{
    ui->setupUi(this);


}

WTableAnalyze::~WTableAnalyze()
{
    delete ui;
}

void WTableAnalyze::refresh()
{

    int iTotalDataCount = CSQL.getAnalyzeCount();

    int iTotalPage = iTotalDataCount/ui->sbCount->value();

    if(iTotalDataCount%ui->sbCount->value()>0)
        iTotalPage++;


    ui->lbTotalPage->setText(QString::number(iTotalPage));

    ui->sbNowPage->setValue(m_iPage+1);

   QVariantList list = CSQL.getAnalyzeData(0,ui->sbCount->value());

   for(int i=0;i<list.length();i++)
   {
        QVariantMap dData = list.at(i).toMap();

       ui->tableWidget->setRowCount(i+1);

       CAnalyzeData tmp;

       int iCol=0;

       for(int j=0;j<tmp.listKey.length();j++)
       {
           QString sKey = tmp.listKey.at(j);

           if(sKey=="Image_Width" || sKey=="Image_Height")
               continue;

           QString sSt = dData[sKey].toString();

           QTableWidgetItem*item = new QTableWidgetItem(sSt);

           ui->tableWidget->setItem(i,iCol,item);

           iCol++;
       }

   }





}

void WTableAnalyze::showEvent(QShowEvent *)
{
    refresh();
}

void WTableAnalyze::on_btnTest_clicked()
{

    CAPI.queryHistory();

}

void WTableAnalyze::on_btnUpload_clicked()
{
    QStringList listFile = QFileDialog::getOpenFileNames(this,
tr("Open Image"), "", tr("Image Files (*.png *.jpg)"));


//    QStringList listFile;

//    for(int i=0;i<500;i++)
//    {
//        listFile.append("../test01.jpg");
//    }

    CAPI.callAnylyze(listFile);

}


void WTableAnalyze::on_sbCount_valueChanged(int )
{
    refresh();
}

