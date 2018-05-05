#ifndef ADMINEDITCLIENT_H
#define ADMINEDITCLIENT_H

#include <QDialog>

namespace Ui {
class AdminEditClient;
}

class AdminEditClient : public QDialog
{
    Q_OBJECT

public:
    explicit AdminEditClient(QWidget *parent = 0);
    ~AdminEditClient();

private slots:
    void on_pushButtonCorporation_clicked();

private:
    Ui::AdminEditClient *ui;
};

#endif // ADMINEDITCLIENT_H
