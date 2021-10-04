#include "ItemLoadingBarA.h"






QVector<QPixmap*> ItemLoadingBarA::m_pixArray;

ItemLoadingBarA::ItemLoadingBarA(QWidget *parent) :
    QWidget(parent)
{
    this->setGeometry(525,674,230,36);
    this->setParent(parent);
    QWidget *w=new QWidget(this);
    w->resize(this->size());
    // this->setStyleSheet("background-color: rgb(255, 255, 255);");
    this->raise();


    m_label= new QLabel(this);//初始化Label容器
    m_label->resize(this->size());
    m_label->setStyleSheet("background-color:rgb(0,0,0,0)");
    //    if (m_pixArray.size() == 0)
    //    {

    //        QStringList stringFilter;
    //        stringFilter<<"*.png";
    //        QString path=QApplication::applicationDirPath();
    //        //  QDir dir(":/global/WaitingAnimation/");
    //        QDir dir(path+"/res/WaitingAnimation/");
    //        QStringList fileList = dir.entryList(stringFilter);

    //        for(int i=0;i<fileList.count();i++)
    //        {
    //            m_pixArray.push_back(new QPixmap(path+"/res/WaitingAnimation/"+ fileList[i]));
    //            // m_pixArray.push_back(new QPixmap(QString(":/global/WaitingAnimation/") + fileList[i]));
    //        }

    //    }


    QObject::connect(&m_thread.m_timer, SIGNAL(timeout()), this, SLOT(animation()));

    m_thread.run();


    showPic();
}

ItemLoadingBarA::~ItemLoadingBarA()
{

}

void ItemLoadingBarA::setPixmap(QList<QPixmap*> listPix)
{
    for(int i=0;i<listPix.length();i++)
    {
        m_pixArray.push_back(listPix[i]);
    }

}



//-----------------------------------------------------------------------------
//
void ItemLoadingBarA::animation()
{
    m_label->setPixmap(m_pixArray[k]->scaled(m_label->size()));
    k = (k+1)%(m_pixArray.size());
}


//-----------------------------------------------------------------------------
//
void ItemLoadingBarA::showPic()
{
    if(m_pixArray.length()<1)
        return;

    k=0;
    this->raise();



}

//-----------------------------------------------------------------------------
//
void ItemLoadingBarA::showEvent(QShowEvent *)
{

    k=0;
    emit signalEventLock(true);
}

//-----------------------------------------------------------------------------
//
void ItemLoadingBarA::hideEvent(QHideEvent *)
{

    emit signalEventLock(false);
}

void ItemLoadingBarA::resizeEvent(QResizeEvent *)
{
    m_label->resize(this->size());

}

//-----------------------------------------------------------------------------
//


//-----------------------------------------------------------------------------
//

void ItemLoadingBarA::releasePixArray()
{
    if (m_pixArray.size() > 0)
    {
        for (int i = 0; i < m_pixArray.size(); ++i)
            delete m_pixArray.at(i);
    }
}
