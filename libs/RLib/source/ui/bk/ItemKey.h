#ifndef ITEMKEY_H
#define ITEMKEY_H

#include <QWidget>

namespace Ui {
class ItemKey;
}

class ItemKey : public QWidget
{
    Q_OBJECT

public:
    explicit ItemKey(QWidget *parent = 0);
    ~ItemKey();
    void setListText(QStringList listText);
    void setText(QString sText);
    QString text();

    void setFont(const QFont &font);
private:
    Ui::ItemKey *ui;
    QStringList m_listText;
    void mouseReleaseEvent(QMouseEvent *);

signals:
    void clicked();

private slots:
    void on_pushButton_clicked();
};

#endif // ITEMKEY_H
