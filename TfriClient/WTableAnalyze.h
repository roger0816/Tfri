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
namespace Ui {
class WTableAnalyze;
}

class WTableAnalyze : public QWidget
{
    Q_OBJECT

public:
    explicit WTableAnalyze(QWidget *parent = nullptr);
    ~WTableAnalyze();

    void refresh();

    void showEvent(QShowEvent *) override;

    QWidget* scalePic(QString sId,QString sFileName);

    QList<QWidget*> m_listColorW;

public slots:

    void slotUpdate(QString sId);

    void slotHeaderResize(int logicalIndex, int oldSize, int newSize);
private slots:
    void on_btnTest_clicked();

    void on_btnUpload_clicked();

    void on_sbCount_valueChanged(int);

private:
    Ui::WTableAnalyze *ui;

    int m_iPage = 0;
};

#endif // WTABLEANALYZE_H
