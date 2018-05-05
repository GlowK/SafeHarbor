#ifndef ADMINCORPORATION_H
#define ADMINCORPORATION_H

#include <QDialog>

namespace Ui {
class AdminCorporation;
}

class AdminCorporation : public QDialog
{
    Q_OBJECT

public:
    explicit AdminCorporation(QWidget *parent = 0);
    ~AdminCorporation();

private:
    Ui::AdminCorporation *ui;
};

#endif // ADMINCORPORATION_H
