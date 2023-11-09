#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include "fileanalyzer.h"
#include "resulttable.h"

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private slots:
    void startAnalysis();
    void saveTableToFile();
    void loadTableFromFile();

private:
    FileAnalyzer fileAnalyzer;
    ResultTable* resultTable;
    QLineEdit* fileNameInput;
};

#endif
