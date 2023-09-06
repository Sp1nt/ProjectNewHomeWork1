#include <iostream>


using namespace std;

struct worker {
	char* firstName = new char[150];
	char* lastName = new char[150];
	char* number = new char[150];
	double salary = 0;
};


void inputWorker(worker&);
void printWorker(const worker&);


void delWorker(worker* workers, int& quantity);


void searchByLastName(worker* newWorker, int size, char* searchLastName);

void sortByLastName(worker*, int);

void searchBySalaryRange(const worker* workers, int quantity, double minSalary, double maxSalary);


void printEmployeeList(const worker* workers, int quantity);
void searchWorker(const worker);



bool onlyDigits(const char*);
bool onlyLetters(const char*);
bool numberOfCharacters(const char*);