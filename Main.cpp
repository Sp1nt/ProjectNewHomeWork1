#include <iostream>
#include "Second.h"
#include <string>

using namespace std;

int main() {
    setlocale(0, "");

    char* temp = new char[100];
    int quantity = 0;
    char choice = 0;
    bool hasWorkers = false;

    worker* newWorker = nullptr;


    while (true) {
        if (!hasWorkers) {
            cout << "1. �������� ���������� (������� ���������� ����������� �������)" << endl;
        }
        else {
            cout << "����:" << endl;
            cout << "1. �������� ����������" << endl;
            cout << "2. ������� ���������� � ���� �����������" << endl;
            cout << "3. ����� �� �������" << endl;
            cout << "4. ����� �� ��������� ��������" << endl;
            cout << "5. ������� ����������" << endl;
            cout << "6. ���������� �� �������" << endl;
            cout << "7. ��������� ������ � ����" << endl;
            cout << "8. ��������� ������ �� �����" << endl;
            cout << "9. �����" << endl << endl;
        }
        cout << "�������� ��������: ";
        cin >> choice;
        cin.ignore();
        cout << endl;

        if (!hasWorkers && choice != '1') {
            cout << "���������� ���������� �� �������, ������� ������� 1 ����� ������� ����������." << endl;
            continue;
        }


        if (isdigit(choice) && choice >= '1' && choice <= '9') {
            switch (choice) {
            case '1': 
                do {
                    cout << "n worker: ";
                    cin >> temp;

                    if (!onlyDigits(temp)) {
                        quantity = stod(temp);
                    }
                } while (quantity <= 0);

                newWorker = new worker[quantity];
                hasWorkers = true;
                for (int i = 0; i < quantity; i++)
                    inputWorker(newWorker[i]);
                cout << endl;
                break;
            case '2': 
                for (int i = 0; i < quantity; i++)
                {
                    cout << endl;
                    printWorker(newWorker[i]);
                }
                cout << endl << endl;
                break;
            case '3': 
            {
                while (true) {
                    char subChoice;
                    cout << "D. ��������� � ������� ����, S. ���������� � ������: ";
                    cin >> subChoice;
                    cin.ignore();

                    if (subChoice == 'D' || subChoice == 'd') {
                        break; 
                    }
                    else if (subChoice == 'S' || subChoice == 's') {
                        cout << "������� ����: ";
                        cin >> temp;

                        char* key = new char[strlen(temp)];
                        key = temp;

                        cout << endl;

                        searchByLastName(newWorker, quantity, key);
                    }
                    else {
                        cout << "�������� �����. ����������, �������� 'D' ��� 'S'." << endl;
                    }

                }

            }
            break;


            case '4': 
            {
                char subChoice;
                cout << "D. ��������� � ������� ����, S. ���������� � ������: ";
                cin >> subChoice;
                cin.ignore();

                if (subChoice == 'D' || subChoice == 'd') {
                    break; 
                }

                double minSalary, maxSalary;
                cout << "Enter the minimum and maximum wages to search for: ";
                cin >> minSalary >> maxSalary;

                cout << "Result  searched:" << endl;
                searchBySalaryRange(newWorker, quantity, minSalary, maxSalary);
            }
            break;
            case '5':
            {
                char subChoice;
                cout << "D. ��������� � ������� ����, S. ���������� � ������: ";
                cin >> subChoice;
                cin.ignore();

                if (subChoice == 'D' || subChoice == 'd') {
                    break; 
                }

                cout << "Index list worker:" << endl;
                printEmployeeList(newWorker, quantity);

                cout << endl << "Delete worker for index:" << endl;
                delWorker(newWorker, quantity);
            }
            break;
            case '6': 
                sortByLastName(newWorker, quantity);
                cout << "compleated sort, check #2" << endl;
                break;

            case '7': // ��������� ������ �� �����
                /*if (readAllWorkersFromFile(newWorker, quantity)) {
                    cout << "������ ��������� �� �����." << endl;
                }
                else {
                    cout << "������ ��� ������ ������ �� �����." << endl;
                }*/

                break;
            case '8': // ��������� ������ � ����
                /*writeAllWorkersToFile(newWorker, quantity);
                cout << "������ ��������� � ����." << endl;*/
                break;
            case '9': // �����

                cout << "����� �� ���������." << endl;
                delete[] newWorker;
                newWorker = nullptr;
                return 0;
            default:
                cout << "�������� �����, ���������� �����." << endl;
            }
        }
        else {
            cout << "�������� �����, ���������� �����." << endl;
        }
    }

    delete[] newWorker;
    newWorker = nullptr;

    return 0;
}