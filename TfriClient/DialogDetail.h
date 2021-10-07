#ifndef DIALOGDETAIL_H
#define DIALOGDETAIL_H

#include <QDialog>
#include "CDefine.h"
#include <QTimer>
#include <QResizeEvent>
namespace Ui {
class DialogDetail;
}

class DialogDetail : public QDialog
{
    Q_OBJECT

public:
    explicit DialogDetail(QWidget *parent = nullptr);
    ~DialogDetail();

    void setData(CAnalyzeData data);

    void resizeEvent(QResizeEvent *) override;
private slots:
    void on_btnClose_clicked();

private:
    Ui::DialogDetail *ui;

    QPixmap m_pic0;

    QPixmap m_pic1;
};

#endif // DIALOGDETAIL_H
