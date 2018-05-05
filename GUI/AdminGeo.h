#ifndef ADMINGEO_H
#define ADMINGEO_H

#include <QDialog>

namespace Ui {
class AdminGeo;
}

class AdminGeo : public QDialog
{
    Q_OBJECT

public:
    explicit AdminGeo(QWidget *parent = 0);
    ~AdminGeo();

private slots:
    void on_pushButtonShanghai_clicked();

private:
    Ui::AdminGeo *ui;
};

#endif // ADMINGEO_H
