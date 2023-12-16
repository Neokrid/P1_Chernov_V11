#include <iostream>
#include <fstream>
#include "file_reader.h"
#include "printer.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "Ru");

    try {
        std::ifstream in("input.txt");
        vector<StudentTopic> objects = FileReader::readStudentTopics(in);
        Printer::printStudentTopics(objects);
    }
    catch (const exception& ex) {
        cerr << "Îøèáêà: " << ex.what() << endl;
        return 1;
    }

    return 0;
}
