#include "ItemSelectNumber.h"

ItemSelectNumber::ItemSelectNumber(QWidget *parent) : QWidget(parent)
{
    m_wScrollView = new LayerScrollView(this);

    QWidget *w;

    QLabel *lb;

    QSize s(30,30);

    QFont f;

    f.setPointSize(26);

    for(int i=0;i<9;i++)
    {
        w = new QWidget(this);

        w->resize(s);

        lb = new QLabel(w);

        lb->setGeometry(0,0,30,30);

        lb->setText(QString::number(i));

        lb->resize(QSize(30,30));

        lb->setFont(f);

        m_listItem.append(w);
    }

    QRect focus(0,45,30,30);

    m_wScrollView->setPage(focus,false,1,1,m_listItem,0,0);

    m_wScrollView->setContent(false,true,true);

}

void ItemSelectNumber::setNumber(int iMin, int iMax, int iStep)
{
    Q_UNUSED(iMin);

    Q_UNUSED(iMax);

    Q_UNUSED(iStep);
}

void ItemSelectNumber::resizeEvent(QResizeEvent *)
{
    m_wScrollView->resize(size());
}

void ItemSelectNumber::showEvent(QShowEvent *)
{

}
