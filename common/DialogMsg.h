#ifndef DIALOGMSG_H
#define DIALOGMSG_H

#include <QDialog>

namespace Ui {
class DialogMsg;
}

class DialogMsg : public QDialog
{
    Q_OBJECT

public:
    explicit DialogMsg(QWidget *parent = nullptr);
    ~DialogMsg();

    void setMsg(QString sTitle,QString sMsg,QStringList listBtn);

private:
    Ui::DialogMsg *ui;

    QList<QPushButton*> m_listBtn;

private slots:
    void slotBtn();
};

#endif // DIALOGMSG_H
