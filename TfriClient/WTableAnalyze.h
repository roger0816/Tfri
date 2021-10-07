#ifndef WTABLEANALYZE_H
#define WTABLEANALYZE_H

#include <QWidget>
#include <QLabel>
#include <QHeaderView>
#include <QAbstractItemDelegate>
#include "CCallApi.h"
#include <QDebug>
#include <QFileDialog>
#include <QShowEvent>
#include <QVBoxLayout>
#include <QGridLayout>
#include "Global.h"
#include "DialogMsg.h"
#include <QThread>
#include <QImage>
#include "DialogSelectFilter.h"
namespace Ui {
class WTableAnalyze;
}


class WTableAnalyze : public QWidget
{
    Q_OBJECT

public:
    explicit WTableAnalyze(QWidget *parent = nullptr);
    ~WTableAnalyze();

    void refresh(bool bReload = false);

    void showEvent(QShowEvent *) override;

    QWidget* scalePic(QString sId,QString sFileName);

    void setScalePic(int iRow, QString sId, QString sFileName);

    QList<QWidget*> m_listColorW;

    void setPicList(QStringList listSid,QStringList listName);


public slots:

    void slotUpdate(QString sId);

    void slotHeaderResize(int , int, int);
private slots:
    void on_btnTest_clicked();

    void on_btnUpload_clicked();

    void on_sbCount_valueChanged(int);

    void on_btnChangeCount_clicked();

    void on_btnNextPage_clicked();

    void on_sbNowPage_editingFinished();

    void on_btnPrePage_clicked();

    void on_btnClipPic_clicked();

private:
    Ui::WTableAnalyze *ui;

    void reload();

    void uploadFile(QStringList listFile);


    bool m_bFirst = true;

    int m_iPage = 0;
};

#endif // WTABLEANALYZE_H
