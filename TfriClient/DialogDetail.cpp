#include "DialogDetail.h"
#include "ui_DialogDetail.h"



DialogDetail::DialogDetail(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogDetail)
{
    ui->setupUi(this);
}

DialogDetail::~DialogDetail()
{
    delete ui;
}

void DialogDetail::setData(CAnalyzeData data)
{
        ui->lbSid->setText(data.sId);

    qDebug()<<"origin file :"<<qApp->applicationDirPath()+"/../data/input/"+data.sName;
        ui->lbName->setText(data.sName);

        m_pic0 = QPixmap(qApp->applicationDirPath()+"/../data/input/"+data.sId+"/"+data.sName);

        m_pic1 =QPixmap(qApp->applicationDirPath()+"/../data/output/"+data.sId+"/"+data.sName.split(".").first()+".png");
        QTimer::singleShot(100,this,[=]()
        {
            ui->lbPic0->setPixmap(m_pic0.scaledToHeight(ui->lbPic0->height()));

            ui->lbPic1->setPixmap(m_pic1.scaledToHeight(ui->lbPic1->height()));
        });

        ui->lbBuildding->setText(data.sBuilding);
        ui->lbBicyclist->setText(data.sBicyclist);
        ui->lbCar->setText(data.sCar);
        ui->lbFence->setText(data.sFence);
        ui->lbPavement->setText(data.sPavement);

        ui->lbPedestrian->setText(data.sPedestrian);
        ui->lbPole->setText(data.sPole);
        ui->lbRoad->setText(data.sRoad);
        ui->lbRoadMarking->setText(data.sRoadMarking);
        ui->lbSky->setText(data.sSky);

        ui->lbSignSymbol->setText(data.sSignSymbol);
        ui->lbTree->setText(data.sTree);
        ui->lbUnlabelled->setText(data.sUnlabelled);


}

void DialogDetail::resizeEvent(QResizeEvent *)
{
    if(ui->lbPic0->width()*2 < width()*0.9)
    {
    ui->lbPic0->setPixmap(m_pic0.scaledToHeight(ui->lbPic0->height()));

    ui->lbPic1->setPixmap(m_pic1.scaledToHeight(ui->lbPic1->height()));
    }
    else
    {
        ui->lbPic0->setPixmap(m_pic0.scaledToWidth(ui->lbPic0->width()));

        ui->lbPic1->setPixmap(m_pic1.scaledToWidth(ui->lbPic1->width()));
    }

    qDebug()<<size();
}

void DialogDetail::on_btnClose_clicked()
{
    reject();
}
