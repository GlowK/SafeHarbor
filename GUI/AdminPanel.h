#ifndef ADMINPANEL_H
#define ADMINPANEL_H

#include <QDialog>
#include <QString>
#include "MainClass/Port.h"

namespace Ui {
class AdminPanel;
}

class AdminPanel : public QDialog
{
    Q_OBJECT

public:
    explicit AdminPanel(QWidget *parent = 0);
    QString chosenPort;
    Port tempPort;
    ~AdminPanel();

private slots:
    void on_pushCreateNewHarbour_clicked();

    void on_pushEditHarbour_clicked();

    void on_pushClientAdd_clicked();

    void on_pushClientEdit_clicked();

    void on_pushManagerAdd_clicked();

    void on_pushManagerEdit_clicked();

    void on_pushLogOut_clicked();

    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_pushAcceptPort_clicked();

    void on_pushPlusAnchorage_clicked();

    void on_pushMinusAnchorage_clicked();

    void on_pushPlusTugboat_clicked();

    void on_pushMinusTugboat_clicked();

private:
    Ui::AdminPanel *ui;
    void populateComboBox();
    void populatePortInformation(QString);
};

#endif // ADMINPANEL_H
