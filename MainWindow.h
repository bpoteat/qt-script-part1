#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QScriptEngine>
#include <QScriptEngineDebugger>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void feedback(QString message);

private slots:
    void ExecuteScript(void);

    
private:
    Ui::MainWindow *ui;

    QScriptEngine fScriptEngine;
    QScriptEngineDebugger fScriptDebugger;

    void SetupScriptEngine(void);

};

#endif // MAINWINDOW_H
