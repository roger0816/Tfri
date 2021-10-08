#include "DialogSelectFilter.h"
#include "ui_DialogSelectFilter.h"

DialogSelectFilter::DialogSelectFilter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogSelectFilter)
{
    ui->setupUi(this);

    for(int i=0;i<6;i++)
    {
        m_wFilter[i] = new QWidget(ui->scrollAreaWidgetContents);

        m_wFilter[i]->setStyleSheet("background-color:rgba(0,0,255,128);");

        m_wFilter[i]->hide();

    }

    m_listW<<ui->gb0<<ui->gb1<<ui->gb2<<ui->gb3<<ui->gb4<<ui->gb5;


    QMap<QString,QSpinBox*> v0;
    v0["x0"] = ui->sb0X0;
    v0["y0"] = ui->sb0Y0;
    v0["x1"] = ui->sb0X1;
    v0["y1"] = ui->sb0Y1;
    m_listSb.append(v0);

    QMap<QString,QSpinBox*> v1;
    v1["x0"] = ui->sb1X0;
    v1["y0"] = ui->sb1Y0;
    v1["x1"] = ui->sb1X1;
    v1["y1"] = ui->sb1Y1;
    m_listSb.append(v1);

    QMap<QString,QSpinBox*> v2;
    v2["x0"] = ui->sb2X0;
    v2["y0"] = ui->sb2Y0;
    v2["x1"] = ui->sb2X1;
    v2["y1"] = ui->sb2Y1;
    m_listSb.append(v2);

    QMap<QString,QSpinBox*> v3;
    v3["x0"] = ui->sb3X0;
    v3["y0"] = ui->sb3Y0;
    v3["x1"] = ui->sb3X1;
    v3["y1"] = ui->sb3Y1;
    m_listSb.append(v3);

    QMap<QString,QSpinBox*> v4;
    v4["x0"] = ui->sb4X0;
    v4["y0"] = ui->sb4Y0;
    v4["x1"] = ui->sb4X1;
    v4["y1"] = ui->sb4Y1;
    m_listSb.append(v4);

    QMap<QString,QSpinBox*> v5;
    v5["x0"] = ui->sb5X0;
    v5["y0"] = ui->sb5Y0;
    v5["x1"] = ui->sb5X1;
    v5["y1"] = ui->sb5Y1;
    m_listSb.append(v5);


    ui->txPath->setText(QApplication::applicationDirPath()+"/../data/clip");




    //    m_lisSb[0] <<ui->sbFrom0<<ui->sbFrom1<<ui->sbFrom2<<ui->sbFrom3
    //              <<ui->sbFrom4<<ui->sbFrom5<<ui->sbFrom6<<ui->sbFrom7<<ui->sbFrom8;


    //    m_lisSb[1]<<ui->sbTo0<<ui->sbTo1<<ui->sbTo2<<ui->sbTo3<<ui->sbTo4<<ui->sbTo5<<ui->sbTo6<<ui->sbTo7<<ui->sbTo8;



}

DialogSelectFilter::~DialogSelectFilter()
{
    delete ui;
}


void DialogSelectFilter::setData(QStringList listFilePath)
{
    m_listOriginFile = listFilePath;

    if(m_listOriginFile.length()<=0)
    {
        ui->btnOk->setEnabled(false);

        return;
    }
    changeImage();
}

void DialogSelectFilter::showEvent(QShowEvent *)
{

    on_btnSet_clicked();

    for(int i=0;i<6;i++)
    {
        m_wFilter[i]->move(ui->lbPic->pos());

        m_wFilter[i]->resize(ui->lbPic->size());

        m_wFilter[i]->raise();
    }
    //    m_wFilter->show();
}

void DialogSelectFilter::resizeEvent(QResizeEvent *)
{
    for(int i=0;i<6;i++)
    {
        m_wFilter[i]->move(ui->lbPic->pos());

        m_wFilter[i]->resize(ui->lbPic->size());

        m_wFilter[i]->raise();
    }

    //    m_wFilter->show();

    //    m_wFilter->setMask(QRect(30,30,100,150));

}



void DialogSelectFilter::changeSb()
{
    for(int i=0;i<m_listW.length();i++)
    {
        if(i<m_iCount)
        {
            m_listW[i]->show();
        }
        else
        {
            m_listW[i]->hide();
        }

    }
}

void DialogSelectFilter::changeImage()
{

    ui->lbPic->setPixmap(QPixmap(m_listOriginFile.at(m_originIdx)));

    ui->lbOriginFile->setText(m_listOriginFile.at(m_originIdx));

    ui->lbOriginCount->setText(QString("%1/%2").arg(m_originIdx+1).arg(m_listOriginFile.length()));

}



void DialogSelectFilter::on_btnAdd_clicked()
{
    if(m_iCount==m_listW.length())
        return;
    m_iCount++;

    changeSb();
    on_btnSet_clicked();
}


void DialogSelectFilter::on_btnSub_clicked()
{
    if(m_iCount==1)
        return;
    m_iCount--;

    changeSb();
    on_btnSet_clicked();
}


void DialogSelectFilter::on_btnSet_clicked()
{

    m_listRect.clear();
    //  m_list

    for(int i=0;i<m_listW.length();i++)
    {
        if(m_listW[i]->isVisible())
        {
            QRect rectT(QPoint(m_listSb.at(i)["x0"]->value(),m_listSb.at(i)["y0"]->value()),
                    QPoint(m_listSb.at(i)["x1"]->value(),m_listSb.at(i)["y1"]->value()));

            m_wFilter[i]->resize(ui->lbPic->size());
            m_listRect.append(rectT);

            m_wFilter[i]->setMask(rectT.marginsRemoved(QMargins(0,10,0,-10)));
            m_wFilter[i]->show();



        }
        else
        {

            m_wFilter[i]->clearMask();

            m_wFilter[i]->hide();
        }

        // rect.setTopLeft()

    }
}


void DialogSelectFilter::on_btnCancel_clicked()
{
    done(0);
}


void DialogSelectFilter::on_btnOk_clicked()
{
    m_sPath = ui->txPath->text().trimmed();


    QString sDir = m_sPath;

    QDir dir(sDir);
    dir.removeRecursively();

    QDir().mkdir(sDir);

    m_listAfFile.clear();

    for(int i=0;i<m_listOriginFile.length();i++)
    {
        QImage image;

        if(image.load(m_listOriginFile.at(i)))
        {
            for(int j=0;j<m_listRect.length();j++)
            {
                QImage img = image.copy(m_listRect.at(j));

                QString sTmp =m_listOriginFile.at(i).split("/").last();

                QString sFileName = sTmp.split(".").first();

                QString  sFilePath = sDir+"/"+sFileName+"_"+QString::number(j)+".png";

                m_listAfFile.append(sFilePath);
                img.save(sFilePath);
            }

        }

    }
    done(1);
}




void DialogSelectFilter::on_btnPrePic_clicked()
{
    if(m_originIdx==0)
        return;

    m_originIdx--;

    changeImage();
}


void DialogSelectFilter::on_btnNextPic_clicked()
{
    if(m_originIdx == m_listOriginFile.length()-1)
        return;

    m_originIdx++;

    changeImage();
}

