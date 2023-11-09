#ifndef FILEANALYZER_H
#define FILEANALYZER_H

#include <QString>

class FileAnalyzer {
public:
    FileAnalyzer();
    void setFileName(const QString& fileName);
    int countLetters() const;
    int countWords() const;
    int countSentences() const;

private:
    QString fileName;
};

#endif
