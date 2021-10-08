#ifndef DIALOGSELECTFILTER_H
#define DIALOGSELECTFILTER_H

#include <QDialog>
#include <QDebug>
#include <QWidget>
#include <QShowEvent>
#include <QResizeEvent>
#include <QImage>
#include <QPainter>
#include <QSpinBox>
#include <QDir>

namespace Ui {
class DialogSelectFilter;
}



class DialogSelectFilter : public QDialog
{
    Q_OBJECT

public:
    explicit DialogSelectFilter(QWidget *parent = nullptr);
    ~DialogSelectFilter();

    void setData(QStringList listFilePath);

    void showEvent(QShowEvent * )override;

    void resizeEvent(QResizeEvent *) override;

    QList<QRect> m_listRect;



    QString m_sPath;

    QStringList m_listAfFile;


    bool m_bUpload = true;
private slots:
    void on_btnAdd_clicked();

    void on_btnSub_clicked();

    void on_btnSet_clicked();

    void on_btnCancel_clicked();

    void on_btnOk_clicked();


    void on_btnPrePic_clicked();

    void on_btnNextPic_clicked();

private:
    Ui::DialogSelectFilter *ui;

    QWidget *m_wFilter[6];

   QList<QMap<QString, QSpinBox* > > m_listSb;

    QList<QWidget*> m_listW;

    QStringList m_listOriginFile;




    int m_iCount = 6;

    void changeSb();

    void changeImage();

    int m_originIdx = 0;



};

#endif // DIALOGSELECTFILTER_H
