#ifndef VKEYBORD_H
#define VKEYBORD_H

#include <QWidget>
#include <QDebug>
#include <QLabel>
#include "ItemKey.h"
#include <QPropertyAnimation>
#include <QEventLoop>



namespace Ui {
class Vkeybord;
}

class Vkeybord : public QWidget
{
    Q_OBJECT

public:
    explicit Vkeybord(QWidget *parent = 0);
    ~Vkeybord();


    static Vkeybord& Instance()
    {
        if(m_pInstance==0)
            m_pInstance=new Vkeybord();
        return *m_pInstance;
    }

    void setFontSize(QFont font);

private:
    Ui::Vkeybord *ui;
    static Vkeybord *m_pInstance;
    QList<ItemKey*> m_listNumWord;
    QList<ItemKey*> m_listEnWord;
    QList<ItemKey*> m_listSpecailWord;
    QLabel *m_lbWaitKeyIn;
    QPropertyAnimation *m_ani;
    bool m_bIsLower;
private slots:
    void slotInput();
    void slotEnter();
    void slotChangeUpper();


public slots:
    void slotOpenKeyBord(QLabel *lb);
};

#endif // VKEYBORD_H
