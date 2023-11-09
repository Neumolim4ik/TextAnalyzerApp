#include "mainwindow.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QFileDialog>

MainWindow::MainWindow(QWidget* parent) : QWidget(parent) {
    setWindowTitle("Text Analyzer");

    resultTable = new ResultTable(this);

    fileNameInput = new QLineEdit(this);
    QPushButton* startButton = new QPushButton("Старт", this);
    QPushButton* saveButton = new QPushButton("Сохранить", this);
    QPushButton* loadButton = new QPushButton("Загрузить", this);

    connect(startButton, &QPushButton::clicked, this, &MainWindow::startAnalysis);
    connect(saveButton, &QPushButton::clicked, this, &MainWindow::saveTableToFile);
    connect(loadButton, &QPushButton::clicked, this, &MainWindow::loadTableFromFile);

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(fileNameInput);
    layout->addWidget(resultTable);
    layout->addWidget(startButton);
    layout->addWidget(saveButton);
    layout->addWidget(loadButton);

    setLayout(layout);
}

void MainWindow::startAnalysis() {
    QString fileName = fileNameInput->text();
    fileAnalyzer.setFileName(fileName);
    int letters = fileAnalyzer.countLetters();
    int words = fileAnalyzer.countWords();
    int sentences = fileAnalyzer.countSentences();
    resultTable->setResults(letters, words, sentences);
}

void MainWindow::saveTableToFile() {
    QString saveFileName = QFileDialog::getSaveFileName(this, "Сохранить таблицу", "", "Binary Files (*.bin)");
    if (!saveFileName.isEmpty()) {
        if (resultTable->saveTable(saveFileName)) {

        } else {

        }
    }
}

void MainWindow::loadTableFromFile() {
    QString loadFileName = QFileDialog::getOpenFileName(this, "Загрузить таблицу", "", "Binary Files (*.bin)");
    if (!loadFileName.isEmpty()) {
        if (resultTable->loadTable(loadFileName)) {

        } else {

        }
    }
}
