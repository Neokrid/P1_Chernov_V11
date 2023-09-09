#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;


struct Date
{
    int day;
    int month;
    int year;


    Date(int y, int m, int d) : year(y), month(m), day(d) {}


};

struct StudentTopic {
    string studentName;
    string topicName;
    Date issueDate;

    StudentTopic(const string& name, const string& topic, const Date& date)
        : studentName(name), topicName(topic), issueDate(date) {}
};

int main() {
    setlocale(LC_ALL, "Ru");
    vector<StudentTopic> objects;
    ifstream inputFile("input.txt");
    string input;

    while (getline(inputFile, input, ',')) {
        string studentName = input;

        if (getline(inputFile, input, ',')) {
            string topicName = input;
            int year, month, day;
            char dash;
            if (inputFile >> year >> dash >> month >> dash >> day) {
                objects.emplace_back(studentName, topicName, Date(year, month, day));
                inputFile.ignore();
            }
            else {
                cout << "Некорректный формат ввода." << endl;
                inputFile.close();
                return 1;
            }


        }

    }



    for (StudentTopic& obj : objects) {
        cout << "Имя студента: " << obj.studentName << endl;
        cout << "Название темы: " << obj.topicName << endl;
        cout << "Дата выдачи: " << obj.issueDate.year << "." << obj.issueDate.month << "." << obj.issueDate.day << endl;
        cout << "________________" << endl;
    }

    inputFile.close();


}