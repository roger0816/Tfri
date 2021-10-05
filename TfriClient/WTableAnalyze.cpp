#include "WTableAnalyze.h"
#include "ui_WTableAnalyze.h"

WTableAnalyze::WTableAnalyze(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WTableAnalyze)
{
    ui->setupUi(this);

    ui->tableWidget->setSortingEnabled(true);

    ui->tableWidget->horizontalHeader()->setMinimumHeight(60);

    ui->tableWidget->resizeColumnsToContents();
    ui->tableWidget->setColumnWidth(0,60);
    ui->tableWidget->setColumnWidth(1,120);
    ui->tableWidget->setColumnWidth(2,60);
    ui->tableWidget->setColumnWidth(18,180);
    ui->tableWidget->setColumnWidth(19,180);


    connect(ui->tableWidget->horizontalHeader(),&QHeaderView::sectionResized,this,&WTableAnalyze::slotHeaderResize);

    connect(&CAPI,&CCallApi::updateData,this,&WTableAnalyze::slotUpdate);



    for(int i=0;i<ui->tableWidget->columnCount();i++)
    {
        QWidget *w = new QWidget(ui->wColorArea);

        w->hide();

        m_listColorW.append(w);
    }

    //    CAnalyzeData tmp;

    //    for(int i=0; i<tmp.listKey.length();i++)
    //    {

    //        QString sKey =tmp.listKey.at(i);

    //        QString sColor =tmp.mColor[sKey].name();

    //        if(sColor =="#000000")
    //            continue;

    //        QWidget *wColor = new QWidget(ui->wColorArea);

    //        wColor->setStyleSheet("background-color:"+sColor);

    //        wColor->show();

    //        m_listColorW.append(wColor);
    //    }

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

    CAnalyzeData ana;

    QVariantList list ;
    //  list.append(ana.mColor);
    list.append(CSQL.getAnalyzeData(0,ui->sbCount->value()));

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

            QVariant v = dData[sKey];


            if(sKey=="CreateTime" || sKey=="UpdateTime")
            {
                v = QDateTime::fromString(v.toString(),"yyyyMMddhhmmss").toString("yyyy/MM/dd hh:mm:ss");
            }

            QTableWidgetItem*item = new QTableWidgetItem();


            //            if(i==0 && v.toString().trimmed()!="")
            //            {
            //                item->setBackground(QColor(v.toString()));

            //            }
            //            else
            {

                item->setData(Qt::DisplayRole, QVariant(v));

                item->setTextAlignment(Qt::AlignCenter);
                ui->tableWidget->setRowHeight(i,60);

            }
            ui->tableWidget->setItem(i,iCol,item);



            iCol++;
        }


        ui->tableWidget->setCellWidget(i,iCol,scalePic(dData["Id"].toString(),dData["Name"].toString()));

    }



    slotHeaderResize(1,1,1);

}

void WTableAnalyze::showEvent(QShowEvent *)
{
    refresh();
}

QWidget *WTableAnalyze::scalePic(QString sId, QString sFileName)
{
    QWidget *w = new QWidget;

    if(sId=="")
        return w;



    QHBoxLayout *lay = new QHBoxLayout;
    lay->setMargin(2);
    QStringList listPic;

    QString sTmp =QString::number(sId.toInt());  //  00001  to   1

    listPic<<"../data/input/"+sTmp+"/"+sFileName;
    listPic<<"../data/output/"+sTmp+"/"+sFileName.split(".").first()+".png";

    for(int i=0;i<listPic.length();i++)
    {
        if(QFileInfo(listPic.at(i)).exists())
        {
            QLabel *lb = new QLabel(w);
            lb->setPixmap(QPixmap(listPic.at(i)).scaledToHeight(60));
            lay->addWidget(lb);
        }
    }

    w->setLayout(lay);

    return w;
}

void WTableAnalyze::slotUpdate(QString sId)
{
    refresh();
}

void WTableAnalyze::slotHeaderResize(int logicalIndex, int oldSize, int newSize)
{

    QHeaderView *header = ui->tableWidget->horizontalHeader();

//    int iW= header->sectionSize(1);

//    int iX= header->sectionPosition(1);

    //   ui->wColor0->move(iX,ui->wColor0->y());

    //    ui->wColor0->resize( iW,ui->wColor0->height());

    for(int i=0;i<m_listColorW.length();i++)
    {
        int iW= header->sectionSize(i);

        int iX= header->sectionPosition(i);

        QString sKey = ui->tableWidget->horizontalHeaderItem(i)->text().trimmed();

        m_listColorW[i]->move(iX,0);

        m_listColorW[i]->resize( iW,ui->wColorArea->height());

        CAnalyzeData tmp;

        QString sKeyTmp = sKey.replace(" ","_");

        if(tmp.mColor.keys().indexOf(sKeyTmp)>=0)
        {
            m_listColorW[i]->setStyleSheet("background-color:"+tmp.mColor[sKey].name());

            m_listColorW[i]->show();
        }
        else
        {
            m_listColorW[i]->hide();
        }

    }
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

    QStringList ll;
    for(int i=0;i<500;i++)
    {
        ll.append(listFile);
    }


    CAPI.callAnylyze(ll);

}


void WTableAnalyze::on_sbCount_valueChanged(int )
{
    refresh();
}

