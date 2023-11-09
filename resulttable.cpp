#include "resulttable.h"
#include <QDataStream>
#include <QFile>

ResultTable::ResultTable(QWidget* parent) : QTableWidget(parent) {
    setRowCount(1);
    setColumnCount(3);
    setHorizontalHeaderLabels({ "Letters", "Words", "Sentences" });
}

void ResultTable::setResults(int letters, int words, int sentences) {
    setItem(0, 0, new QTableWidgetItem(QString::number(letters)));
    setItem(0, 1, new QTableWidgetItem(QString::number(words)));
    setItem(0, 2, new QTableWidgetItem(QString::number(sentences)));
}

bool ResultTable::saveTable(const QString& fileName) {
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly)) {
        return false; // Ошибка при открытии файла для записи
    }

    QDataStream out(&file);
    out << rowCount() << columnCount(); // Сохраняем количество строк и столбцов

    for (int row = 0; row < rowCount(); ++row) {
        for (int col = 0; col < columnCount(); ++col) {
            QTableWidgetItem* item = this->item(row, col);
            QString text = item ? item->text() : "";
            out << text; // Сохраняем содержимое ячеек
        }
    }

    file.close();
    return true;
}

bool ResultTable::loadTable(const QString& fileName) {
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)) {
        return false; // Ошибка при открытии файла для чтения
    }

    QDataStream in(&file);
    int rowCount, colCount;
    in >> rowCount >> colCount; // Загружаем количество строк и столбцов

    setRowCount(rowCount);
    setColumnCount(colCount);

    for (int row = 0; row < rowCount; ++row) {
        for (int col = 0; col < colCount; ++col) {
            QString text;
            in >> text; // Загружаем содержимое ячеек
            QTableWidgetItem* item = new QTableWidgetItem(text);
            setItem(row, col, item);
        }
    }

    file.close();
    return true;
}
