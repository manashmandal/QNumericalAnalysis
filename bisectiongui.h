#ifndef BISECTIONGUI_H
#define BISECTIONGUI_H

#include <QDialog>
#include "bisectionmethod.h"


namespace Ui {
class BisectionGUI;
}

class BisectionGUI : public QDialog, public BisectionMethod
{
    Q_OBJECT

public:
    explicit BisectionGUI(QWidget *parent = 0);
    ~BisectionGUI();

private:
    Ui::BisectionGUI *ui;
};

#endif // BISECTIONGUI_H
