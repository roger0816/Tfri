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
    ui->tableWidget->setColumnWidth(5,60);
    ui->tableWidget->setColumnWidth(9,60);
    ui->tableWidget->setColumnWidth(10,60);
    ui->tableWidget->setColumnWidth(12,60);

    ui->tableWidget->setColumnWidth(14,60);
    ui->tableWidget->setColumnWidth(16,60);
    ui->tableWidget->setColumnWidth(18,65);
    ui->tableWidget->setColumnWidth(19,140);
    ui->tableWidget->setColumnWidth(20,140);
    ui->tableWidget->setColumnWidth(21,200);

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

    startTimer(1000);
}

WTableAnalyze::~WTableAnalyze()
{
    delete ui;
}

void WTableAnalyze::refresh(bool bReload)
{
    m_bLockChangePage = true;

    GLOBAL.showBlockLoading(this);
    int iTotalDataCount = CSQL.getAnalyzeCount(ui->cbClass->currentText(),GLOBAL.m_sUser);

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


    QTimer::singleShot(300,[=]
    {
        m_bLockChangePage = false;
    });



}

void WTableAnalyze::showEvent(QShowEvent *)
{
    ui->lbUserName->setText(GLOBAL.m_sUser);
    GLOBAL.showBlockLoading(this);
    slotHeaderResize(1,1,1);

    ui->cbClass->clear();

    QTimer::singleShot(100,this,[=]()
    {

        refresh(true);

        CUserData dataCurrent ;

        dataCurrent.setData(CSQL.getUserData(GLOBAL.m_sUser).first());

        if(dataCurrent.listGroup.length()<1)
            dataCurrent.listGroup.append("Def");

        ui->cbClass->addItem("All");

        ui->cbClass->addItems(dataCurrent.listGroup);

    });

}

void WTableAnalyze::timerEvent(QTimerEvent *)
{

    int iCount = CAPI.INS().m_ai.getWaitCount();

    QString sTarget = CAPI.INS().m_ai.getCurrentTarget();

    if(iCount<=0)
        ui->lbWaitMsg->setText("");
    else
        ui->lbWaitMsg->setText(QString("正在解析%1，還有%2張等待解析。").arg(sTarget).arg(iCount));


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

    QWidget *w = ui->tableWidget->cellWidget(iRow,ui->tableWidget->columnCount()-1);



    if(sId=="")
        return;



    QGridLayout *lay = new QGridLayout;
    lay->setMargin(1);

    QSpacerItem *item = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    lay->addItem(item,0,0);


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
            lay->addWidget(lb,0,i+1);
        }
    }

    QSpacerItem *item2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    lay->addItem(item2,0,3);

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

    qDebug()<<" update : "<<bReload;
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

    DialogMsg dialog;

    dialog.setMsg("上傳圖片",QString("確定上傳到所選擇的分類 '%1' 嗎?").arg(ui->cbClass->currentText()),QStringList()<<"否"<<"是");

    if(dialog.exec()==1)
    {
        QStringList listFile = QFileDialog::getOpenFileNames(this,
                                                             tr("Open Image"), "", tr("Image Files (*.png *.jpg)"));
        uploadFile(ui->cbClass->currentText(),listFile);
    }
}


void WTableAnalyze::on_sbCount_valueChanged(int )
{

}

void WTableAnalyze::reload()
{
    qDebug()<<"reload";

    ui->tableWidget->hide();
    CAnalyzeData ana;

    QStringList listSid;

    QStringList listFileName;
    QVariantList list ;
    //  list.append(ana.mColor);

    int iStartIdx = qBound(0,ui->sbNowPage->value()-1,ui->lbTotalPage->text().toInt()-1)*ui->sbCount->value();

    list = CSQL.getAnalyzeData(GLOBAL.m_sUser,iStartIdx,ui->sbCount->value(),ui->cbClass->currentText());

    ui->tableWidget->setRowCount(0);

    if(list.length()<1)
    {

        return;
    }
    for(int i=0;i<list.length();i++)
    {
        QVariantMap dData = list.at(i).toMap();

        if(dData["User"] !=GLOBAL.m_sUser)
            continue;

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


        ui->tableWidget->setCellWidget(i,ui->tableWidget->columnCount()-1,new QWidget());


        //  ui->tableWidget->setCellWidget(i,iCol,scalePic(dData["Id"].toString(),dData["Name"].toString()));

    }

    setPicList(listSid,listFileName);

    ui->tableWidget->show();
}

void WTableAnalyze::uploadFile(QString sGroup, QStringList listFile)
{
    if(listFile.length()<1)
        return;
    QVariantList listData = CSQL.getAnalyzeData(GLOBAL.m_sUser,"0",-1);

    if(listData.length()<1)
        return;

    QStringList listMerge,listNoMerge;

    for(int i=0;i<listFile.length();i++)
    {
        bool bHasOne = false;

        for(int j=0;j<listData.length();j++)
        {
            QString sFile = listFile.at(i).split("/").last();

            CAnalyzeData cData;

            cData.setData(listData.at(j).toMap());

            if(sFile == cData.sName && sGroup == cData.sClassGroup)
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


    CAPI.callAnylyze(GLOBAL.m_sUser, sGroup,listFile);
}


void WTableAnalyze::on_btnChangeCount_clicked()
{
    refresh(true);
}

void WTableAnalyze::on_btnNextPage_clicked()
{
    if(m_bLockChangePage)
        return ;

    if(ui->sbNowPage->value() >= ui->lbTotalPage->text().toInt() )
        return;

    m_iPage++;

    refresh(true);

}

void WTableAnalyze::on_sbNowPage_editingFinished()
{
    if(m_bLockChangePage)
        return ;


    if(m_iPage == ui->sbNowPage->value()-1)
        return;

    m_iPage = ui->sbNowPage->value()-1;

    refresh(true);


}

void WTableAnalyze::on_btnPrePage_clicked()
{
    if(m_bLockChangePage)
        return ;


    if(m_iPage<=0 )
        return;

    m_iPage--;

    refresh(true);

}


void WTableAnalyze::on_btnClipPic_clicked()
{
    DialogMsg dialog;

    dialog.setMsg("裁切上傳",QString("確定上傳到所選擇的分類 '%1' 嗎?").arg(ui->cbClass->currentText()),QStringList()<<"否"<<"是");

    if(dialog.exec()!=1)
    {
        return;
    }


    QStringList listFile = QFileDialog::getOpenFileNames(this,
                                                         tr("Open Image"), "", tr("Image Files (*.png *.jpg)"));


    if(listFile.length()<1)
        return;

    DialogSelectFilter dialogSelect;

    dialogSelect.setData(listFile);


    int iRe =dialogSelect.exec();

    if(iRe==1 && dialogSelect.m_bUpload)
    {

        uploadFile(ui->cbClass->currentText(),dialogSelect.m_listAfFile);


    }

}


void WTableAnalyze::on_btnOutput_clicked()
{
    QString sPath= QFileDialog::getExistingDirectory(this,"AA",".");


    QVariantList list = CSQL.getAnalyzeData(GLOBAL.m_sUser,"0",-1,ui->cbClass->currentText());



    if(!QDir(sPath+"/"+GLOBAL.m_sUser).exists())
        QDir().mkdir(sPath+"/"+GLOBAL.m_sUser);

    QFile file(sPath+"/"+GLOBAL.m_sUser+"/"+ui->cbClass->currentText()+"_"+QDateTime::currentDateTime().toString("yyyyMMddhhmmss")+".csv");

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



    DialogMsg msg;

    msg.setMsg("匯出資料","匯出完成",QStringList()<<"OK");

    msg.exec();

    qDebug()<<"path : "<<sPath;
}

void WTableAnalyze::on_btnClass_clicked()
{
    DialogUser dialog;

    QStringList listCurrentClass;

    QStringList listUser, listPass;

    foreach(QVariantMap data, CSQL.getUserData())
    {
        QString sName = data["Name"].toString();

        if(GLOBAL.m_sUser!= sName)
        {
            listUser.append(data["Name"].toString());

            listPass.append(data["Password"].toString());
        }
        else
        {
            listCurrentClass = data["ClassGroup"].toStringList();

            if(listCurrentClass.length()<1)
                listCurrentClass.append("Def");
        }
    }

    /**
    CUserData dataCurrent ;

    dataCurrent.setData(CSQL.getUserData(GLOBAL.m_sUser).first());

    if(dataCurrent.listGroup.length()<1)
        dataCurrent.listGroup.append("Def");

    dialog.setData(GLOBAL.m_sUser,GLOBAL.m_sPassword,dataCurrent.listGroup);
   */

    dialog.setData(GLOBAL.m_sUser,GLOBAL.m_sPassword,listCurrentClass);


    dialog.setUserList(CSQL.userList(),QStringList());

    int iRe = dialog.exec();

    if(iRe ==1 )
    {
        CSQL.changePassword(GLOBAL.m_sUser,dialog.m_sReData);

        DialogMsg msg;

        msg.setMsg("","密碼已變更",QStringList()<<"OK");

        msg.exec();
    }

    if(iRe ==2 )
    {
        CSQL.changeClassGroup(GLOBAL.m_sUser,dialog.m_listClass);

        DialogMsg msg;

        msg.setMsg("","分類已修改",QStringList()<<"OK");

        msg.exec();

        ui->cbClass->clear();
        ui->cbClass->addItem("All");
        ui->cbClass->addItems(dialog.m_listClass);
    }

    if(iRe ==4 )
    {

        QString sErrorMsg;

        bool b = CSQL.addUser(dialog.m_editUser.first,dialog.m_editUser.second,sErrorMsg);

        DialogMsg msg;

        if(b)
        {
            msg.setMsg("","已新增使用者 : "+dialog.m_editUser.first,QStringList()<<"OK");
        }
        else
        {
            msg.setMsg("Error",sErrorMsg,QStringList()<<"OK");
        }
        msg.exec();
    }

    if(iRe ==5 )
    {

        QString sErrorMsg;

        CSQL.delUser(dialog.m_editUser.first,dialog.m_editUser.second,sErrorMsg);

        DialogMsg msg;

        msg.setMsg("","已刪除使用者 : "+dialog.m_editUser.first,QStringList()<<"OK");

        msg.exec();
    }
}


void WTableAnalyze::on_cbClass_currentIndexChanged(int )
{
    //if(ui->cbClass->count()>=0)
    refresh(true);

}


void WTableAnalyze::on_btnDelRow_clicked()
{
    DialogMsg msg;

    if(ui->tableWidget->currentRow()<0)
    {
        msg.setMsg("刪除資料","請先選擇要刪除的資料",QStringList()<<"ok");
        msg.exec();

        return;
    }

    QString sId = ui->tableWidget->item(ui->tableWidget->currentRow(),0)->text();

    QString sName = ui->tableWidget->item(ui->tableWidget->currentRow(),1)->text();

    msg.setMsg("刪除資料",QString("確定刪除Sid ' %1 ' , ' %2 '?").arg(sId).arg(sName),QStringList()<<"取消"<<"確認");

    if(msg.exec()==1)
    {
        CSQL.deleteAnalyzeData(sId);

        refresh(true);
    }
}
