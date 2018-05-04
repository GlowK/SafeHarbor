#ifndef ADMINADDMANAGER_H
#define ADMINADDMANAGER_H

#include <QDialog>

namespace Ui {
class AdminAddManager;
}

class AdminAddManager : public QDialog
{
    Q_OBJECT

public:
    explicit AdminAddManager(QWidget *parent = 0);
    ~AdminAddManager();

private:
    Ui::AdminAddManager *ui;
};

#endif // ADMINADDMANAGER_H
