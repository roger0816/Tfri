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
#include <QTableWidget>
#include <QImage>
#include "DialogSelectFilter.h"
#include "DialogDetail.h"
#include <QFileDialog>
#include <QTimerEvent>

#include "DialogUser.h"
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

    void timerEvent(QTimerEvent *) override;
    QWidget* scalePic(QString sId,QString sFileName);

    void setScalePic(int iRow, QString sId, QString sFileName);

    QList<QWidget*> m_listColorW;

    void setPicList(QStringList listSid,QStringList listName);


public slots:

    void slotUpdate(QString sId);

    void slotHeaderResize(int , int, int);

    void slotCellClicked(int iRow,int iCol);
private slots:
    void on_btnTest_clicked();

    void on_btnUpload_clicked();

    void on_sbCount_valueChanged(int);

    void on_btnChangeCount_clicked();

    void on_btnNextPage_clicked();

    void on_sbNowPage_editingFinished();

    void on_btnPrePage_clicked();

    void on_btnClipPic_clicked();

    void on_btnOutput_clicked();

    void on_btnClass_clicked();

    void on_cbClass_currentIndexChanged(int);

    void on_btnDelRow_clicked();

private:
    Ui::WTableAnalyze *ui;

    void reload();

    void uploadFile(QString sGroup,QStringList listFile);


    bool m_bFirst = true;

    int m_iPage = 0;

    bool m_bLockChangePage = false;
};

#endif // WTABLEANALYZE_H
