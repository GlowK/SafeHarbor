#ifndef MANAGERPANEL_H
#define MANAGERPANEL_H

#include <QDialog>

namespace Ui {
class ManagerPanel;
}

class ManagerPanel : public QDialog
{
    Q_OBJECT

public:
    explicit ManagerPanel(QWidget *parent = 0);
    ~ManagerPanel();

private:
    Ui::ManagerPanel *ui;
};

#endif // MANAGERPANEL_H
