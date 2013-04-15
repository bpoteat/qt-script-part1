#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QStringBuilder>
#include <QMessageBox>
#include <QFileDialog>
#include <QTextStream>
#include <QCloseEvent>
#include <QScriptValue>
#include <QtUiTools/QUiLoader>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionExecute, SIGNAL(triggered()), this, SLOT(ExecuteScript()));

    this->SetupScriptEngine();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::SetupScriptEngine(void)
{
    // expose this widget to the script
    QScriptValue appContext = fScriptEngine.newQObject(this);
    fScriptEngine.globalObject().setProperty("app", appContext);
}

void MainWindow::feedback(QString message)
{
    ui->textOutput->setPlainText(message);
}


void MainWindow::ExecuteScript(void)
{
    QString text = ui->textScript->toPlainText();
    QScriptValue result = fScriptEngine.evaluate(text);
    if (fScriptEngine.hasUncaughtException())
    {
        int line = fScriptEngine.uncaughtExceptionLineNumber();
        QString err = result.toString();
        QString msg = QString("Error at line %1: %2")
            .arg(line).arg(err);

        ui->textOutput->setPlainText(msg);
    }
}
