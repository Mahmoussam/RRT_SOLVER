#ifndef CSV_UTILS_H
#define CSV_UTILS_H

#include <string>
#include <vector>


class CSVReader {
public:
    CSVReader(const std::string& filename, char delimiter = ',');
    std::vector<std::vector<std::string>> readCSV();

private:
    std::string filename;
    char delimiter;
    std::vector<std::string> parseLine(const std::string& line);
};

class CSVWriter {
public:
    CSVWriter(const std::string& filename, char delimiter = ',');
    void addRow(const std::vector<std::string>& row);
    bool writeCSV();

private:
    std::string filename;
    char delimiter;
    std::vector<std::vector<std::string>> data;
};

#endif // CSV_UTILS_H
