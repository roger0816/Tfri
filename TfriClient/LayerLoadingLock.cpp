#include "LayerLoadingLock.h"
#include "ui_LayerLoadingLock.h"

LayerLoadingLock::LayerLoadingLock(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LayerLoadingLock)
{
    ui->setupUi(this);

    m_listRes<<":/loading/loading1-1.png"<<":/loading/loading1-2.png"
            <<":/loading/loading1-3.png"<<":/loading/loading1-4.png"
           <<":/loading/loading1-5.png"<<":/loading/loading1-6.png"
          <<":/loading/loading1-7.png"<<":/loading/loading1-8.png";

    ui->lbPic->setPixmap(QPixmap(m_listRes.at(m_iCurrent)).scaled(ui->lbPic->size()));
    startTimer(150);
}

LayerLoadingLock::~LayerLoadingLock()
{
    delete ui;
}

void LayerLoadingLock::timerEvent(QTimerEvent *)
{
    slotChange();
}

void LayerLoadingLock::slotChange()
{

    if(m_iCurrent>=m_listRes.length())
        m_iCurrent =0;


    ui->lbPic->setPixmap(QPixmap(m_listRes.at(m_iCurrent)).scaled(ui->lbPic->size()));

    m_iCurrent++;
}
