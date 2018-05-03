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

private:
    Ui::AdminPanel *ui;
};

#endif // ADMINPANEL_H
