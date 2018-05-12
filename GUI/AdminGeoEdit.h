#ifndef ADMINGEOEDIT_H
#define ADMINGEOEDIT_H

#include <QDialog>

namespace Ui {
class AdminGeoEdit;
}

    /*
     * Dodajemy klase parent // parent class forward declatarion
     * */

class AdminEditHarbour;

class AdminGeoEdit : public QDialog
{
    Q_OBJECT

    /*
     * zamiast AdminGe(QWidget * parent = 0) wstawiamy nasz parent class
     * */

public:
    explicit AdminGeoEdit(AdminEditHarbour *parent = 0);
    ~AdminGeoEdit();

    /*
     * dodajemy sygnał  na ktorym będziemy wysyłac informacje (typ)
     * */

signals:
    void sendGeoLocation(QString,double, double);
    void sendGeoLocationName(QString);

private slots:
    void on_pushButtonShanghai_clicked();

    void on_pushButtonSingapore_clicked();

    void on_pushButtonBoston_clicked();

    void on_pushButtonRotterdam_clicked();

    void on_pushButtonSydney_clicked();

    void on_pushButtonHouston_clicked();

private:
    Ui::AdminGeoEdit *ui;
    double * getGeoCoordinates(QString name);
    void connectGeoSS(QString cityName, double latitude, double longitude);
    void connectGeoNameSS(QString cityName);
    int isCreated(QString cityName);
    void isButtonVisible(QString cityName, int j);
    void checkButtonsVisibilitie(QString arr[]);


private:
    const int NUMBER_OF_CITIES = 6;
};

#endif // ADMINGEO_H
