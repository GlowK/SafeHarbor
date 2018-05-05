#ifndef ADMINEDITMANAGER_H
#define ADMINEDITMANAGER_H

#include <QDialog>

namespace Ui {
class AdminEditManager;
}

class AdminEditManager : public QDialog
{
    Q_OBJECT

public:
    explicit AdminEditManager(QWidget *parent = 0);
    ~AdminEditManager();

private:
    Ui::AdminEditManager *ui;
};

#endif // ADMINEDITMANAGER_H
