#ifndef ADMINGEO_H
#define ADMINGEO_H

#include <QDialog>
#include <QString>

namespace Ui {
class AdminGeo;
}

    /*
     * Dodajemy klase parent // parent class forward declatarion
     * */

class AdminAddHarbour;

class AdminGeo : public QDialog
{
    Q_OBJECT

    /*
     * zamiast AdminGe(QWidget * parent = 0) wstawiamy nasz parent class
     * */

public:
    explicit AdminGeo(AdminAddHarbour *parent = 0);
    ~AdminGeo();

    /*
     * dodajemy sygnał  na ktorym będziemy wysyłac informacje (typ)
     * */

signals:
    void sendGeoLocation(QString);

private slots:
    void on_pushButtonShanghai_clicked();

private:
    Ui::AdminGeo *ui;
};

#endif // ADMINGEO_H
