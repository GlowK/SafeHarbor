#ifndef ADMINPANEL_H
#define ADMINPANEL_H

#include <QDialog>

namespace Ui {
class AdminPanel;
}

class AdminPanel : public QDialog
{
    Q_OBJECT

public:
    explicit AdminPanel(QWidget *parent = 0);
    ~AdminPanel();

private slots:
    void on_pushCreateNewHarbour_clicked();

    void on_pushEditHarbour_clicked();

    void on_pushClientAdd_clicked();

    void on_pushClientEdit_clicked();

    void on_pushManagerAdd_clicked();

    void on_pushManagerEdit_clicked();

private:
    Ui::AdminPanel *ui;
};

#endif // ADMINPANEL_H
