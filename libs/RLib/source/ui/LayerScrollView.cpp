#include "LayerScrollView.h"

LayerScrollView::LayerScrollView(QWidget *parent) : LayerWheel(parent)
{
    m_rect= QRect(0,0,0,0);

    m_iUseH = 0;

    m_iUseV = 0;

    m_iMoveArrow = -1;

    m_iIdxY = 0;

    m_iIdxX = 0;

    m_bHmove = true;

    m_bVmove = true;

    m_bAutePage = false;

    m_wBg = new QWidget (this);

    m_wBg->setObjectName("m_wBg");

    m_wContent = m_wheel;

    m_wTouch = new TouchObj (this);

    m_wTouch->setObjectName("m_wTouch");

    m_wTouch->connect(m_wTouch,SIGNAL(signalPress(QMouseEvent*)),this,SLOT(touchPressEvent(QMouseEvent*)));

    m_wTouch->connect(m_wTouch,SIGNAL(signalMove(QMouseEvent*)),this,SLOT(touchMoveEvent(QMouseEvent*)));

    m_wTouch->connect(m_wTouch,SIGNAL(signalRelease(QMouseEvent*)),this,SLOT(touchReleaseEvent(QMouseEvent*)));

    m_wTouch->connect(m_wTouch,SIGNAL(signalClick(QMouseEvent*)),this,SLOT(touchClick(QMouseEvent*)));

    m_wTouch->hide();

    m_ani.setDuration(100);

    m_ani.setPropertyName("pos");
    //test

}

void LayerScrollView::setPage(QRect focus, bool bLayoutIsH, int iCol, int iRow, QList<QWidget *> listItem, int iMargin, int iBorder)
{
    m_rect = focus;

    m_iRowCount = iRow;

    m_iColCount = iCol;

    LayerWheel::setPage(focus, bLayoutIsH, iCol,  iRow,listItem, iMargin,iBorder);
}

void LayerScrollView::setContent(bool bHmove,bool bVmove ,bool bAutePage,QWidget *wContent)
{
    //m_wContent = wContent;

    if(wContent == 0 || wContent == NULL)
        m_wContent = m_wheel;
    else
        m_wContent = wContent;

    m_wTouch->show();

    m_wContent->move(0,0);

    m_wContent->setParent(this);

    m_wContent->raise();

    m_wTouch->raise();

    m_bHmove = bHmove;

    m_bVmove = bVmove;

    m_bAutePage = bAutePage;
}



void LayerScrollView::setTouchFlag(bool bIsUse)
{
    if(!bIsUse)
        goPage(m_iNowPage,0);
    m_wTouch->setVisible(bIsUse);
}

//void LayerScrollView::mousePressEvent(QMouseEvent *event)
//{
//    m_pOldPress = event->pos();
//    m_pOldContent = m_wContent->pos();

//}

//void LayerScrollView::mouseMoveEvent(QMouseEvent *event)
//{

//    QPoint tmpP(event->pos()-m_pOldPress+m_pOldContent);

//    float x = qBound(-m_wContent->width()-m_frameBorder.width()+width(),tmpP.x(),m_frameBorder.width());

//    float y = qBound(-m_wContent->height()-m_frameBorder.height()+height(),tmpP.y(),m_frameBorder.height());

//    QPoint p(x,y);

//    if(!m_bHmove)
//        x = m_pOldContent.x();

//    if(!m_bVmove)
//        y = m_pOldContent.y();


//    m_wContent->move(x,y);
//}

//void LayerScrollView::mouseReleaseEvent(QMouseEvent *)
//{

//}

void LayerScrollView::resizeEvent(QResizeEvent *)
{

    m_wBg->setGeometry(rect());

    m_wTouch->setGeometry(rect());


    QSize sizePage;

    if(m_rect.size()== QSize(0,0))
        sizePage = size();
    else
        sizePage = m_rect.size();

    m_frameBorder.setWidth(sizePage.width()/3);

    m_frameBorder.setHeight(sizePage.height()/3);
}



void LayerScrollView::aniToIdx(QPoint sPre, QPoint sNext)
{
    m_ani.setTargetObject(m_wContent);

    m_ani.setStartValue(QPoint(sPre));

    m_ani.setEndValue(QPoint(sNext));

    QEventLoop loop;

    loop.connect(&m_ani,SIGNAL(finished()),&loop,SLOT(quit()));

    m_ani.start();

    loop.exec();
}

void LayerScrollView::touchPressEvent(QMouseEvent *event)
{


    m_pOldPress = event->pos();

    m_pOldContent = m_wContent->pos();

    //    QMouseEvent *event = new QMouseEvent(type, QPoint(x, y), mouse_button, mouse_buttons,
    //        Qt::NoModifier);
    //  QCoreApplication::sendEvent(this, event);
}

void LayerScrollView::touchMoveEvent(QMouseEvent *event)
{

    QSize sizePage;
    //設移動邊界限制
    if(m_rect.size()== QSize(0,0))
        sizePage = size();
    else
        sizePage = m_rect.size();

    QPoint tmpP(event->pos()-m_pOldPress+m_pOldContent);

    float x = qBound(-m_wContent->width()-m_frameBorder.width()+sizePage.width()+m_iUseH*sizePage.width()+m_rect.x(),tmpP.x(),m_frameBorder.width()+m_iUseH*sizePage.width());

    float y = qBound(-m_wContent->height()-m_frameBorder.height()+sizePage.height()+m_iUseV*sizePage.height()+m_rect.y(),tmpP.y(),m_frameBorder.height()+m_iUseV*sizePage.height());

    QPoint p(x,y);

    if(!m_bHmove)
        x = m_pOldContent.x();

    if(!m_bVmove)
        y = m_pOldContent.y();


    m_wContent->move(x,y);



}

void LayerScrollView::touchReleaseEvent(QMouseEvent *event)
{

    if(!m_bAutePage)
        return;

    bool bSlot=false;

    int iPreIdx = m_iNowPage;

    //設自動邊界彈回
    QSize sizePage;

    if(m_rect.size() == QSize(0,0))
        sizePage = size();
    else
        sizePage = m_rect.size();

    int x = m_wContent->x();

    int y = m_wContent->y();

    //    m_iIdxX = qAbs(x/sizePage.width());

    //    m_iIdxY = qAbs(y/sizePage.height());


    QPoint end;

    if(m_bLayoutH)  //橫拉
    {

        if(event->x() < m_pOldPress.x()) //左拉
        {
            m_iNowPage+=qAbs((m_pOldPress.x()-event->x())/sizePage.width());
            if(qAbs(x%sizePage.width())>= sizePage.width()/3)
            {

                bSlot = true;
                m_iNowPage++;
            }
        }
        else
        {
            m_iNowPage-=qAbs((event->x()-m_pOldPress.x())/sizePage.width());
            if(sizePage.width()-qAbs(x%sizePage.width()) > sizePage.width()/3)
            {

                bSlot = true;
                m_iNowPage--;
            }
        }

        m_iNowPage=qBound(0,m_iNowPage,m_iTotalPage-1);

        end.setX(-m_iNowPage*sizePage.width());

        end.setY(0);
    }


    else
    {

        if(event->y() < m_pOldPress.y())
        {
            m_iNowPage += qAbs((m_pOldPress.y()-event->y())/sizePage.height());
            if(qAbs(y%sizePage.height()) >= sizePage.height()/3)
            {
                bSlot = true;
                m_iNowPage++;
            }
        }
        else
        {
            m_iNowPage -= qAbs((event->y()-m_pOldPress.y())/sizePage.height());
            if(sizePage.height()-qAbs(y%sizePage.height()) > sizePage.height()/3)
            {
                bSlot = true;
                m_iNowPage--;
            }
        }

        m_iNowPage=qBound(0,m_iNowPage,m_iTotalPage-1);

        end.setY(-m_iNowPage*sizePage.height());

        end.setX(0);

    }


    aniToIdx(m_wContent->pos(),end);

    if(bSlot || m_iNowPage != iPreIdx)
        emit signalChangePage(m_iNowPage);
}


void LayerScrollView::touchClick(QMouseEvent *event)
{

    QPoint pos=event->pos();

    QSize sizePage;

    if(m_rect.size()== QSize(0,0))
        sizePage = size();
    else
        sizePage = m_rect.size();

    QPoint p ((-m_wContent->pos())+pos);

    int iPageH = qAbs(p.x()/sizePage.width());

    int iPageV = qAbs(p.y()/sizePage.height());

    int iPageIdx= iPageV;

    if(m_bLayoutH)
        iPageIdx = iPageH;


        int iCol;

        int iRow;

        int iIndex;

        // (超出前一單頁的x值) 不能直接抓clicked pos，有可能會移動半頁
        int iArrowX =(p.x()%sizePage.width());

        // (單頁width/ 單頁col數量)  得該頁每一個range佔的width
        int iRangeW = (sizePage.width()/m_iColCount);

        //獲取當頁的col index
        iCol = iArrowX/iRangeW;

        //row (y) 算法同上推類
        int iArrowY = (p.y()%sizePage.height());

        int iRangeH = (sizePage.height()/m_iRowCount);

        iRow = iArrowY/iRangeH;


        //得知第幾頁、col、row，即能求索引值
        iIndex = m_iColCount*m_iRowCount*iPageIdx+ iRow*m_iColCount+iCol;


        if(iIndex>=0 && iIndex<m_listItem.length())
        {
        emit signalClick(iIndex);
      //  qDebug()<<"cell Index : "<<iIndex<<" ,page index : "<<iPageIdx<<" ,col : "<<iCol<<" ,row : "<<iRow;

        emit signalClick(iPageIdx,iCol,iRow);
        }




}


//==============================
TouchObj::TouchObj(QWidget *parent):QWidget(parent)
{
    // setAttribute(Qt::WA_TransparentForMouseEvents,true);

    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
}

void TouchObj::mousePressEvent(QMouseEvent *event)
{
    emit signalPress(event);
    m_pOldpress = event->pos();
}

void TouchObj::mouseMoveEvent(QMouseEvent *event)
{
    emit signalMove(event);
}

void TouchObj::mouseReleaseEvent(QMouseEvent *event)
{
    int iDiff =5;

    emit signalRelease(event);

    if(qAbs(event->pos().x()-m_pOldpress.x())<iDiff && qAbs(event->pos().x()-m_pOldpress.x())<iDiff )
        emit signalClick(event);


}
