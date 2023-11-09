#include "fileanalyzer.h"
#include <QFile>
#include <QTextStream>
#include <QRegularExpression>

FileAnalyzer::FileAnalyzer() {
    // Constructor
}

void FileAnalyzer::setFileName(const QString& fileName) {
    this->fileName = fileName;
}

int FileAnalyzer::countLetters() const {
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return -1; // Ошибка при открытии файла
    }

    QTextStream in(&file);
    QString content = in.readAll();
    file.close();

    // Подсчитываем буквы (исключая пробелы, знаки пунктуации и цифры)
    QRegularExpression letterRegex("[\\p{L}]");
    QRegularExpressionMatchIterator it = letterRegex.globalMatch(content);
    int letterCount = 0;
    while (it.hasNext()) {
        it.next();
        letterCount++;
    }

    return letterCount;
}

int FileAnalyzer::countWords() const {
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return -1; // Ошибка при открытии файла
    }

    QTextStream in(&file);
    QString content = in.readAll();
    file.close();

    // Подсчитываем слова (по пробелам)
    QRegularExpression wordRegex("\\S+");
    QRegularExpressionMatchIterator it = wordRegex.globalMatch(content);
    int wordCount = 0;
    while (it.hasNext()) {
        it.next();
        wordCount++;
    }

    return wordCount;
}

int FileAnalyzer::countSentences() const {
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return -1; // Ошибка при открытии файла
    }

    QTextStream in(&file);
    QString content = in.readAll();
    file.close();

    // Подсчитываем предложения (по знакам препинания)
    QRegularExpression sentenceRegex("[.!?]");
    QRegularExpressionMatchIterator it = sentenceRegex.globalMatch(content);
    int sentenceCount = 0;
    while (it.hasNext()) {
        it.next();
        sentenceCount++;
    }

    return sentenceCount;
}
