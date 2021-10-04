#include "LayerWheel.h"


LayerWheel::LayerWheel(QWidget *parent) : QWidget(parent)
{

    m_iMargin = 0;

    m_iNowPage = 0;

    m_bLayoutH = true;

    m_wBg = new QWidget(this);

    m_wBg->setObjectName("m_wBg");

    m_wheel = new QWidget(this);

    m_wheel->setObjectName("m_wheel");

    m_wheel->setObjectName("m_wheel");

    m_ani.setTargetObject(m_wheel);

    m_ani.setDuration(100);

    m_ani.setPropertyName("pos");

}



void LayerWheel::setPage(QRect focus, bool bLayoutTypeH, int iCol, int iRow, QList<QWidget*> listItem, int iMargin, int iBorder)
{
    m_rect = focus;

    m_bLayoutH = bLayoutTypeH;

    m_iMargin = iMargin;

    int iOnePageCount = iCol * iRow ;

    m_iTotalPage = listItem.length()/iOnePageCount;

    if(listItem.length()%iOnePageCount>0)
        m_iTotalPage++;

    if(m_bLayoutH)
    {
        m_wheel->setGeometry(0,0,m_rect.x()+m_iTotalPage*m_rect.width(),m_rect.height());

        int iW = (m_rect.width()-iBorder*(iCol-1)-iMargin*2)/iCol;

        int iH = (m_rect.height()-iBorder*(iRow-1)-iMargin*2)/iRow;



        int iNowCol,iNowRow,iNowPage;

        m_wheel->raise();

        for(int i=0;i<listItem.length();i++)
        {

            iNowPage =(i+1)/iOnePageCount ;

            if((i+1)%(iOnePageCount)>0)
                iNowPage++;
            if(iNowPage>0)
                iNowPage--;

            iNowCol = (i%iOnePageCount)% iCol;

            iNowRow = (i%iOnePageCount)/ iCol;

            listItem[i]->setParent(m_wheel);

            listItem[i]->setObjectName("item_"+QString::number(i));

            listItem[i]->show();

            listItem[i]->resize(iW,iH);

            listItem[i]->move(m_rect.x()+iNowPage*m_rect.width()+iMargin+(iW+iBorder)*iNowCol,iMargin+(iH+iBorder)*iNowRow);


        }
    }
    else
    {
        m_wheel->setGeometry(0,0,m_rect.width(),m_rect.y()+m_iTotalPage*m_rect.height());

        int iW = (m_rect.width()-iBorder*(iCol-1)-iMargin*2)/iCol;

        int iH = (m_rect.height()-iBorder*(iRow-1)-iMargin*2)/iRow;

        int iNowCol,iNowRow,iNowPage;

        m_wheel->raise();

        for(int i=0;i<listItem.length();i++)
        {

            iNowPage =(i+1)/iOnePageCount ;

            if((i+1)%(iOnePageCount)>0)
                iNowPage++;
            if(iNowPage>0)
                iNowPage--;

            iNowCol = (i%iOnePageCount)% iCol;

            iNowRow = (i%iOnePageCount)/ iCol;

            listItem[i]->setParent(m_wheel);

            listItem[i]->setObjectName("item_"+QString::number(i));

            listItem[i]->show();

            listItem[i]->resize(iW,iH);

            listItem[i]->move(iMargin+(iW+iBorder)*iNowCol,m_rect.y()+iNowPage*m_rect.height()+iMargin+(iH+iBorder)*iNowRow);


        }
    }

    m_listItem = listItem;

}



bool LayerWheel::nextPage(int iMsec)
{

    goPage(m_iNowPage+1,iMsec);

    return m_iNowPage < m_iTotalPage;
}

bool LayerWheel::prePage(int iMsec)
{

    goPage(m_iNowPage-1,iMsec);

    return m_iNowPage > 0 ;
}

void LayerWheel::goPage(int iIdx, int iMsec)
{

    int iPreIdx = m_iNowPage;

    if(iIdx < 0 || iIdx >= m_iTotalPage )
    {
        return ;
    }

    m_iNowPage = iIdx;

    if(m_bLayoutH)
    {

        wheelMove(-(iIdx*m_rect.width()+m_rect.x())+m_rect.x(),0,iMsec);

    }
    else
    {

        wheelMove(0,-(iIdx*m_rect.height()+m_rect.y())+m_rect.y(),iMsec);
    }

    if(iPreIdx != m_iNowPage)
        emit signalChangePage(m_iNowPage);

    return ;
}


void LayerWheel::wheelMove(int iX, int iY, int iMsec)
{
    if(iMsec<=0)
    {
        m_wheel->move(iX,iY);
        return;
    }


    m_ani.setDuration(iMsec);

    m_ani.setStartValue(m_wheel->pos());

    m_ani.setEndValue(QPoint(iX,iY));

    QEventLoop loop;

    loop.connect(&m_ani,SIGNAL(finished()),&loop,SLOT(quit()));

    m_ani.start();

    loop.exec();
}

void LayerWheel::resizeEvent(QResizeEvent *)
{
    m_wBg->setGeometry(rect());
}
