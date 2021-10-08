#include "WTableAnalyze.h"
#include "ui_WTableAnalyze.h"

WTableAnalyze::WTableAnalyze(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WTableAnalyze)
{
    ui->setupUi(this);


    ui->tableWidget->setSortingEnabled(true);

    ui->tableWidget->horizontalHeader()->setMinimumHeight(60);

    //  ui->tableWidget->resizeColumnsToContents();
    ui->tableWidget->setColumnWidth(0,60);
    ui->tableWidget->setColumnWidth(1,120);
    ui->tableWidget->setColumnWidth(2,60);
    ui->tableWidget->setColumnWidth(5,50);
    ui->tableWidget->setColumnWidth(9,50);
    ui->tableWidget->setColumnWidth(10,50);
    ui->tableWidget->setColumnWidth(12,50);

    ui->tableWidget->setColumnWidth(14,50);
    ui->tableWidget->setColumnWidth(16,60);
    ui->tableWidget->setColumnWidth(17,65);
    ui->tableWidget->setColumnWidth(18,140);
    ui->tableWidget->setColumnWidth(19,140);
    ui->tableWidget->setColumnWidth(20,200);

   // connect(ui->tableWidget,&QTabWidget::)

    connect(ui->tableWidget,&QTableWidget::cellClicked,this,&WTableAnalyze::slotCellClicked);

    connect(ui->tableWidget->horizontalHeader(),&QHeaderView::sectionResized,this,&WTableAnalyze::slotHeaderResize);

    connect(&CAPI,&CCallApi::updateData,this,&WTableAnalyze::slotUpdate);


    for(int i=0;i<ui->tableWidget->columnCount();i++)
    {
        QWidget *w = new QWidget(ui->wColorArea);

        w->hide();

        m_listColorW.append(w);
    }


}

WTableAnalyze::~WTableAnalyze()
{
    delete ui;
}

void WTableAnalyze::refresh(bool bReload)
{

    GLOBAL.showBlockLoading(this);
    int iTotalDataCount = CSQL.getAnalyzeCount();

    int iTotalPage = iTotalDataCount/ui->sbCount->value();

    if(iTotalDataCount%ui->sbCount->value()>0 || iTotalPage==0)
        iTotalPage++;


    ui->lbTotalCount->setText(QString::number(iTotalDataCount));

    ui->lbTotalPage->setText(QString::number(iTotalPage));

    ui->sbNowPage->setMaximum(iTotalPage);

    ui->sbNowPage->setValue(m_iPage+1);

    if(bReload)
        reload();


    GLOBAL.hideBlockLoading();




}

void WTableAnalyze::showEvent(QShowEvent *)
{

    GLOBAL.showBlockLoading(this);
    slotHeaderResize(1,1,1);
    QTimer::singleShot(100,this,[=]()
    {

        refresh(true);

    });

}

QWidget *WTableAnalyze::scalePic(QString sId, QString sFileName)
{
    QWidget *w = new QWidget;

    if(sId=="")
        return w;



    QGridLayout *lay = new QGridLayout;
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
            lb->setPixmap(QPixmap(listPic.at(i)).scaledToWidth(180));
            lay->addWidget(lb,i,0);
        }
    }

    w->setLayout(lay);

    return w;
}

void WTableAnalyze::setScalePic(int iRow,QString sId, QString sFileName)
{
    QWidget *w = ui->tableWidget->cellWidget(iRow,20);



    if(sId=="")
        return;



    QGridLayout *lay = new QGridLayout;
    lay->setMargin(1);
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
            lay->addWidget(lb,0,i);
        }
    }

    QSpacerItem *item = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    lay->addItem(item,0,2);

    w->setLayout(lay);

    //  ui->tableWidget->setCellWidget(iRow,20,w);
}

void WTableAnalyze::setPicList(QStringList listSid, QStringList listName)
{
    QTimer::singleShot(100,this,[=]()
    {
        for(int i=0;i<listSid.length() && i<listName.length();i++)
        {
            setScalePic(i,listSid.at(i),listName.at(i));
        }
    });
}

void WTableAnalyze::slotUpdate(QString sId)
{
    bool bReload =  ui->sbNowPage->value()==ui->lbTotalPage->text().toInt();

    refresh(bReload);


}

void WTableAnalyze::slotHeaderResize(int , int , int )
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

void WTableAnalyze::slotCellClicked(int iRow, int iCol)
{
    if(iCol !=20 || iRow<0)
        return;


   QString sId = ui->tableWidget->item(iRow,0)->text();

//   QString sFileName =ui->tableWidget->item(iRow,1)->text();

//   QString sPath =QApplication::applicationDirPath()+"/../data/%1/%2/"+sFileName.split(".").first();

  QVariantMap dData = CSQL.getAnalyzeFromId(sId);

  CAnalyzeData item;

  item.setData(dData);

  DialogDetail dialog;

  dialog.setData(item);

  dialog.exec();


}

void WTableAnalyze::on_btnTest_clicked()
{

    CAPI.queryHistory();

}

void WTableAnalyze::on_btnUpload_clicked()
{
    QStringList listFile = QFileDialog::getOpenFileNames(this,
                                                         tr("Open Image"), "", tr("Image Files (*.png *.jpg)"));

    uploadFile(listFile);

}


void WTableAnalyze::on_sbCount_valueChanged(int )
{

}

void WTableAnalyze::reload()
{
    ui->tableWidget->hide();
    CAnalyzeData ana;

    QStringList listSid;

    QStringList listFileName;
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

            item->setData(Qt::DisplayRole, QVariant(v));

            item->setTextAlignment(Qt::AlignCenter);
            ui->tableWidget->setRowHeight(i,60);

            ui->tableWidget->setItem(i,iCol,item);

            iCol++;
        }

        listSid.append(dData["Id"].toString());

        listFileName.append(dData["Name"].toString());


        ui->tableWidget->setCellWidget(i,20,new QWidget());


        //  ui->tableWidget->setCellWidget(i,iCol,scalePic(dData["Id"].toString(),dData["Name"].toString()));

    }

    setPicList(listSid,listFileName);

    ui->tableWidget->show();
}

void WTableAnalyze::uploadFile(QStringList listFile)
{
    if(listFile.length()<1)
        return;
    QVariantList listData = CSQL.getAnalyzeData("0",-1);

    QStringList listMerge,listNoMerge;

    for(int i=0;i<listFile.length();i++)
    {
        bool bHasOne = false;

        for(int j=0;j<listData.length();j++)
        {
            QString sFile = listFile.at(i).split("/").last();

            CAnalyzeData cData;

            cData.setData(listData.at(j).toMap());

            if(sFile == cData.sName)
            {
                bHasOne = true;
                break;
            }

        }

        if(bHasOne)
            listMerge.append(listFile.at(i));
        else
            listNoMerge.append(listFile.at(i));
    }

    if(listMerge.length()>0)
    {
        DialogMsg msg;

        msg.setMsg("存在重複的檔名，請選擇處理方式",listMerge.join("\n"),QStringList()<<"新增"<<"略過"<<"取消");

        int iRe =msg.exec();

        if(iRe==2)
            return;
        else if(iRe==1)
        {
            listFile = listNoMerge;
        }

    }


    CAPI.callAnylyze(listFile);
}


void WTableAnalyze::on_btnChangeCount_clicked()
{
    refresh(true);
}

void WTableAnalyze::on_btnNextPage_clicked()
{
    if(m_iPage+1>= ui->lbTotalPage->text().toInt() )
        return;

    m_iPage++;

    refresh(true);


}

void WTableAnalyze::on_sbNowPage_editingFinished()
{
    if(m_iPage == ui->sbNowPage->value()-1)
        return;
    qDebug()<<"edit page";
    m_iPage = ui->sbNowPage->value()-1;

    refresh(true);


}

void WTableAnalyze::on_btnPrePage_clicked()
{
    if(m_iPage<=0 )
        return;

    m_iPage--;

    refresh(true);

}


void WTableAnalyze::on_btnClipPic_clicked()
{
    QStringList listFile = QFileDialog::getOpenFileNames(this,
                                                         tr("Open Image"), "", tr("Image Files (*.png *.jpg)"));


    if(listFile.length()<1)
        return;

    DialogSelectFilter dialogSelect;

    dialogSelect.setData(listFile);


    int iRe =dialogSelect.exec();

    if(iRe==1 && dialogSelect.m_bUpload)
    {

        uploadFile(dialogSelect.m_listAfFile);


    }

}


void WTableAnalyze::on_btnOutput_clicked()
{
   QString sPath= QFileDialog::getExistingDirectory(this,"AA",".");


   QVariantList list = CSQL.getAnalyzeData("0",-1);

   QFile file(sPath+"/"+QDateTime::currentDateTime().toString("yyyyMMddhhmmss")+".csv");

   if(file.open(QIODevice::WriteOnly))
   {




       QTextStream outStream(&file);



       for(int i=0;i<list.length();i++)
       {
            CAnalyzeData d ;

            d.setData(list.at(i).toMap());

            if(i==0)
            {
                outStream<<d.listKey.join(",");
            }

            outStream<<"\n";

            outStream<<d.toList().join(",");

       }

       file.flush();

       file.close();

   }




   qDebug()<<"path : "<<sPath;
}
