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
            cout << "1. Добавить сотрудника (Укажите количество сотрудников сначала)" << endl;
        }
        else {
            cout << "Меню:" << endl;
            cout << "1. Добавить сотрудника" << endl;
            cout << "2. Вывести информацию о всех сотрудниках" << endl;
            cout << "3. Поиск по фамилии" << endl;
            cout << "4. Поиск по диапазону зарплаты" << endl;
            cout << "5. Удалить сотрудника" << endl;
            cout << "6. Сортировка по фамилии" << endl;
            cout << "7. Сохранить данные в файл" << endl;
            cout << "8. Загрузить данные из файла" << endl;
            cout << "9. Выход" << endl << endl;
        }
        cout << "Выберите действие: ";
        cin >> choice;
        cin.ignore();
        cout << endl;

        if (!hasWorkers && choice != '1') {
            cout << "Количество работников не указано, сначала нажмите 1 чтобы указать количество." << endl;
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
                    cout << "D. Вернуться в главное меню, S. Продолжить в поиске: ";
                    cin >> subChoice;
                    cin.ignore();

                    if (subChoice == 'D' || subChoice == 'd') {
                        break; 
                    }
                    else if (subChoice == 'S' || subChoice == 's') {
                        cout << "Введите ключ: ";
                        cin >> temp;

                        char* key = new char[strlen(temp)];
                        key = temp;

                        cout << endl;

                        searchByLastName(newWorker, quantity, key);
                    }
                    else {
                        cout << "Неверный выбор. Пожалуйста, выберите 'D' или 'S'." << endl;
                    }

                }

            }
            break;


            case '4': 
            {
                char subChoice;
                cout << "D. Вернуться в главное меню, S. Продолжить в поиске: ";
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
                cout << "D. Вернуться в главное меню, S. Продолжить в поиске: ";
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

            case '7': // Загрузить данные из файла
                /*if (readAllWorkersFromFile(newWorker, quantity)) {
                    cout << "Данные загружены из файла." << endl;
                }
                else {
                    cout << "Ошибка при чтении данных из файла." << endl;
                }*/

                break;
            case '8': // Сохранить данные в файл
                /*writeAllWorkersToFile(newWorker, quantity);
                cout << "Данные сохранены в файл." << endl;*/
                break;
            case '9': // Выход

                cout << "Выход из программы." << endl;
                delete[] newWorker;
                newWorker = nullptr;
                return 0;
            default:
                cout << "Неверный выбор, попробуйте снова." << endl;
            }
        }
        else {
            cout << "Неверный выбор, попробуйте снова." << endl;
        }
    }

    delete[] newWorker;
    newWorker = nullptr;

    return 0;
}