#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QDebug>
#include <QMessageBox>
#include <QProgressDialog>
#include <QAbstractTableModel>
#include <QLabel>
#include <QFont>
#include <QHash>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionAbrir_arquivo_de_treinamento_triggered();

    void on_actionAbrir_arquivo_de_teste_triggered();

private:
    Ui::MainWindow *ui;

    QFile *traningFile;
    QFile *testFile;
    QHash<int, QList<double> > *tempList;

    QHash<int, QList<double> > *fileParse(QString fn);
    double normalize(QStringList &l);

    int qtyInput;
    int qtyHidden;
    int qtyOutput;


signals:
    void tableUpdated();

};

#endif // MAINWINDOW_H
