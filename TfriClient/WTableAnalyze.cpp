#include "WTableAnalyze.h"
#include "ui_WTableAnalyze.h"

WTableAnalyze::WTableAnalyze(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WTableAnalyze)
{
    ui->setupUi(this);
}

WTableAnalyze::~WTableAnalyze()
{
    delete ui;
}

void WTableAnalyze::on_btnTest_clicked()
{


    CAPI.queryHistory();

}
