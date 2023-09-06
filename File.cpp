#include <iostream>
#include <fstream>
#include "Second.h"
#include "File.h"

using namespace std;

// Определение функции для записи данных в файл
void saveDataToFile(worker* workers, int quantity) {
    ofstream outFile("data.txt");

    if (!outFile) {
        cerr << "Failed to open file for writing." << endl;
        return;
    }

    for (int i = 0; i < quantity; i++) {
        outFile << "name: " << workers[i].firstName << endl;
        outFile << "lastName: " << workers[i].lastName << endl;
        outFile << "number: " << workers[i].number << endl;
        outFile << "salary: " << workers[i].salary << endl;
        outFile << endl;
    }

    outFile.close();
    cout << "Data received successfully." << endl<< endl;
}

void readFile()
{
    ifstream textFile("data.txt");

    if (!textFile) {
        cerr << "Failed to open file for writing." << endl;
        return;
    }

    cout << textFile.rdbuf();

    textFile.close();

}

