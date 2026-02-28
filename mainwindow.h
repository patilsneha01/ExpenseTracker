#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "expensemanager.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    ExpenseManager m_manager;
    void ApplyStyle();

private slots:
    void OnAddButtonClicked();
};

#endif // MAINWINDOW_H
