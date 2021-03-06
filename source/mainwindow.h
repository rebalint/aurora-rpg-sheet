#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include "character.h"
#include "prace.h"
#include "racemodifier.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    Character ch;

private slots:

    void on_raceSet_clicked();

private:
    Ui::MainWindow *ui;
    QVector<PRace *> allRaces;

    void raceLoader();

};
#endif // MAINWINDOW_H
