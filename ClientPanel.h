#ifndef CLIENTPANEL_H
#define CLIENTPANEL_H

#include <QDialog>

namespace Ui {
class ClientPanel;
}

class ClientPanel : public QDialog
{
    Q_OBJECT

public:
    explicit ClientPanel(QWidget *parent = 0);
    ~ClientPanel();

private:
    Ui::ClientPanel *ui;
};

#endif // CLIENTPANEL_H
