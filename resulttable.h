#ifndef RESULTTABLE_H
#define RESULTTABLE_H

#include <QTableWidget>

class ResultTable : public QTableWidget {
    Q_OBJECT

public:
    ResultTable(QWidget* parent = nullptr);
    void setResults(int letters, int words, int sentences);

    // Методы для сохранения и загрузки
    bool saveTable(const QString& fileName);
    bool loadTable(const QString& fileName);
};

#endif
