#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDebug>
#include "Library.h"
#include "CDefine.h"
#include "CCallApi.h"
#include "CQueryData.h"
#include "Global.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();


private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_btnTestPage_clicked();

    void on_btnTestBack_clicked();

    void on_btnLogin_clicked();

private:
    Ui::Widget *ui;

};
#endif // WIDGET_H
