#ifndef ADMINADDHARBOUR_H
#define ADMINADDHARBOUR_H

#include <QDialog>
#include <QString>

namespace Ui {
class AdminAddHarbour;
}

class AdminAddHarbour : public QDialog
{
    Q_OBJECT

public:
    explicit AdminAddHarbour(QWidget *parent = 0);
    ~AdminAddHarbour();

    /*
     * Dodajemy slot na którym będziemy przyjemować dane, w deklaracji tylko typy
     * */

public slots:
    void receiveGeoLocation(QString);

private slots:
    void on_pushGeo_clicked();

private:
    Ui::AdminAddHarbour *ui;
};

#endif // ADMINADDHARBOUR_H
