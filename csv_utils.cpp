
#define TEST_WRITE

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
/**
 * CSV Reader class
*/
class CSVReader {
public:
    CSVReader(const std::string& filename, char delimiter = ',')
        : filename(filename), delimiter(delimiter) {}

    std::vector<std::vector<std::string>> readCSV() {
        std::vector<std::vector<std::string>> data;
        std::ifstream file(filename);

        if (!file.is_open()) {
            std::cerr << "Error: Could not open file " << filename << std::endl;
            return data;
        }

        std::string line;
        while (std::getline(file, line)) {
            std::vector<std::string> row = parseLine(line);
            data.push_back(row);
        }

        file.close();
        return data;
    }

private:
    std::string filename;
    char delimiter;

    std::vector<std::string> parseLine(const std::string& line) {
        std::vector<std::string> tokens;
        std::stringstream ss(line);
        std::string token;

        while (std::getline(ss, token, delimiter)) {
            tokens.push_back(token);
        }

        return tokens;
    }
};
/**
 * CSV writer class
*/
class CSVWriter {
public:
    CSVWriter(const std::string& filename, char delimiter = ',')
        : filename(filename), delimiter(delimiter) {}

    void addRow(const std::vector<std::string>& row) {
        data.push_back(row);
    }

    bool writeCSV() {
        std::ofstream file(filename);

        if (!file.is_open()) {
            std::cerr << "Error: Could not open file " << filename << " for writing." << std::endl;
            return false;
        }

        for (const auto& row : data) {
            for (size_t i = 0; i < row.size(); ++i) {
                file << row[i];
                if (i < row.size() - 1) {
                    file << delimiter;
                }
            }
            file << "\n";
        }

        file.close();
        return true;
    }

private:
    std::string filename;
    char delimiter;
    std::vector<std::vector<std::string>> data;
};
#ifdef TEST_WRITE
// Example usage
int main() {
    CSVWriter writer("output.csv");
    writer.addRow({"Name", "Age", "Country"});
    writer.addRow({"Alice", "30", "USA"});
    writer.addRow({"Bob", "25", "Canada"});

    if (writer.writeCSV()) {
        std::cout << "CSV file written successfully." << std::endl;
    } else {
        std::cout << "Failed to write CSV file." << std::endl;
    }

    return 0;
}
#elif defined(TEST_READ)
// Example usage
int main() {
    CSVReader reader("data.csv");
    std::vector<std::vector<std::string>> data = reader.readCSV();

    for (const auto& row : data) {
        for (const auto& col : row) {
            std::cout << col << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
#endif
