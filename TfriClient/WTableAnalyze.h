#ifndef WTABLEANALYZE_H
#define WTABLEANALYZE_H

#include <QWidget>
#include "CCallApi.h"
namespace Ui {
class WTableAnalyze;
}

class WTableAnalyze : public QWidget
{
    Q_OBJECT

public:
    explicit WTableAnalyze(QWidget *parent = nullptr);
    ~WTableAnalyze();

private slots:
    void on_btnTest_clicked();

private:
    Ui::WTableAnalyze *ui;
};

#endif // WTABLEANALYZE_H
