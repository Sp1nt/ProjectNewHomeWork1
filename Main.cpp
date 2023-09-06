#include <iostream>
#include "Second.h"
#include "File.h"
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
            cout << "1. Add worker (Enter the number of worker first)" << endl;
        }
        else {
            cout << "Menu:" << endl;
            cout << "1. Add worker" << endl;
            cout << "2. Display information about all workers" << endl;
            cout << "3. Search by last name" << endl;
            cout << "4. Search by salary range" << endl;
            cout << "5. Delete worker" << endl;
            cout << "6. Sort by last name" << endl;
            cout << "7. Save data to file" << endl;
            cout << "8. Load data from file" << endl;
            cout << "9. Exit" << endl << endl;
        }
        cout << "Choose: ";
        cin >> choice;
        cin.ignore();
        cout << endl;

        if (!hasWorkers && choice != '1') {
            cout << "The number of workers is not specified, first press 1 to enter the number." << endl;
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
                    cout << ". Return to main menu, S. Continue searching: ";
                    cin >> subChoice;
                    cin.ignore();

                    if (subChoice == 'D' || subChoice == 'd') {
                        break; 
                    }
                    else if (subChoice == 'S' || subChoice == 's') {
                        cout << "Input key: ";
                        cin >> temp;

                        char* key = new char[strlen(temp)];
                        key = temp;

                        cout << endl;

                        searchByLastName(newWorker, quantity, key);
                    }
                    else {
                        cout << "Wrong choice. Please select 'D' or 'S'" << endl;
                    }
                }
            }
            break;

            case '4': 
            {
                char subChoice;
                cout << "B. Back to main menu, S. Continue to search: ";
                cin >> subChoice;
                cin.ignore();

                if (subChoice == 'D' || subChoice == 'd') {
                    break; 
                }
                else if (subChoice == 'S' || subChoice == 's') {
                double minSalary, maxSalary;
                cout << "Enter the minimum and maximum wages to search for: ";
                cin >> minSalary >> maxSalary;

                cout << "Result  searched:" << endl;
                searchBySalaryRange(newWorker, quantity, minSalary, maxSalary);
                }
                else {
                    cout << "Wrong choice. Please select 'D' or 'S'" << endl;
                }
            }
            break;
            case '5':
            {
                char subChoice;
                cout << "D. Return to main menu, S. Continue: ";
                cin >> subChoice;
                cin.ignore();

                if (subChoice == 'D' || subChoice == 'd') {
                    break; 
                }
                else if (subChoice == 'S' || subChoice == 's') {
                cout << "Index list worker:" << endl;
                printEmployeeList(newWorker, quantity);

                cout << endl << "Delete worker for index:" << endl;
                delWorker(newWorker, quantity);
                }
                else {
                    cout << "Wrong choice. Please select 'D' or 'S'" << endl;
                }
            }
            break;
            case '6': 
                sortByLastName(newWorker, quantity);
                cout << "compleated sort, check #2" << endl;
                break;

            case '7': 
                saveDataToFile(newWorker, quantity);

                break;
            case '8': 
                readFile();
                break;
            case '9': 

                cout << "Exit from the program." << endl;
                delete[] newWorker;
                newWorker = nullptr;
                return 0;
            default:
                cout << "Wrong choice, try again." << endl;
            }
        }
        else {
            cout << "Wrong choice, try again." << endl;
        }
    }

    delete[] newWorker;
    newWorker = nullptr;

    return 0;
}