#ifndef ADMINEDITHARBOUR_H
#define ADMINEDITHARBOUR_H

#include <QDialog>

namespace Ui {
class AdminEditHarbour;
}

class AdminEditHarbour : public QDialog
{
    Q_OBJECT

public:
    explicit AdminEditHarbour(QWidget *parent = 0);
    ~AdminEditHarbour();

private slots:
    void on_pushGeo_clicked();

private:
    Ui::AdminEditHarbour *ui;
};

#endif // ADMINEDITHARBOUR_H
