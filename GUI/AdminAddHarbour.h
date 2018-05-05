#ifndef ADMINADDHARBOUR_H
#define ADMINADDHARBOUR_H

#include <QDialog>

namespace Ui {
class AdminAddHarbour;
}

class AdminAddHarbour : public QDialog
{
    Q_OBJECT

public:
    explicit AdminAddHarbour(QWidget *parent = 0);
    ~AdminAddHarbour();

private slots:
    void on_pushGeo_clicked();

private:
    Ui::AdminAddHarbour *ui;
};

#endif // ADMINADDHARBOUR_H
