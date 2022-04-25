#ifndef DIALOGUSER_H
#define DIALOGUSER_H

#include <QDialog>
#include <QDebug>
#include "DialogMsg.h"

namespace Ui {
class DialogUser;
}


class DialogUser : public QDialog
{
    Q_OBJECT

public:
    explicit DialogUser(QWidget *parent = nullptr);
    ~DialogUser();


    void setData(QString sUser, QString sPassword, QStringList listClass);

    void setUserList(QStringList listUser,QStringList listPass);

    QStringList m_listUser;

    QStringList m_listPass;


    QString m_sReData;

    QStringList m_listClass;


    QPair<QString ,QString> m_editUser;

private:
    Ui::DialogUser *ui;


    void checkData();

    bool checkPass();

    bool checkSetClass();

    bool checkEditUser();

    QString m_sPassword;

private slots:
    void changePage();

    void on_txtOld_textChanged(const QString &);
    void on_txtNew_textChanged(const QString &);
    void on_txtCheck_textChanged(const QString &);
    void on_btnCancel_clicked();
    void on_btnOk_clicked();
    void on_txAddClass_textChanged(const QString &);
    void on_btnDelClass_clicked();
    void on_btnAddClass_clicked();
    void on_btnAddUser_clicked();
    void on_btnDelUser_clicked();
};

#endif // DIALOGUSER_H
