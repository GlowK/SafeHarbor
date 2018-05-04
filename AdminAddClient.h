#ifndef ADMINADDCLIENT_H
#define ADMINADDCLIENT_H

#include <QDialog>

namespace Ui {
class AdminAddClient;
}

class AdminAddClient : public QDialog
{
    Q_OBJECT

public:
    explicit AdminAddClient(QWidget *parent = 0);
    ~AdminAddClient();

private slots:
    void on_pushButtonCorporation_clicked();

private:
    Ui::AdminAddClient *ui;
};

#endif // ADMINADDCLIENT_H
