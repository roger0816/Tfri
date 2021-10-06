#ifndef LAYERLOADINGLOCK_H
#define LAYERLOADINGLOCK_H

#include <QWidget>
#include <QDebug>
#include <QTimerEvent>
namespace Ui {
class LayerLoadingLock;
}

class LayerLoadingLock : public QWidget
{
    Q_OBJECT

public:
    explicit LayerLoadingLock(QWidget *parent = nullptr);
    ~LayerLoadingLock();

    void timerEvent(QTimerEvent *) override;
private:
    Ui::LayerLoadingLock *ui;
      int m_iCurrent =0;
      QStringList m_listRes;

public slots:
      void slotChange();
};

#endif // LAYERLOADINGLOCK_H
