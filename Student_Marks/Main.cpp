#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <string.h>

class student {
	int rollnmb;
	char name[50];
	int eng_mark, cmp_science_mark, rus_mark, physic_mark, biolog_mark;
	double average;
	char grade;
public:
	void CalcAverage();
	void getdata();
	void showdata() const;
	int retrollno() const;
	void editdata();
	int search(char[20]);
};


int main() {
	student* s[20];
	int choice, i = 0, t, ch;
	char Name[20];
	while (1) {
		std::cout << "\n\t1.Record Student";
		std::cout << "\n\t2.Show Student Record";
		std::cout << "\n\t3.Search Student";
		std::cout << "\n\t4.EXIT";
		std::cout << "\n\tEnter ur choice: ";
		std::cin >> choice;

		switch (choice)
		{
		case 1:
			s[i] = new student;
			s[i]->getdata();
			i++;
			break;
		case 2:
			std::cin.ignore();
			std::cout << "\nEnter Student name: ";
			std::cin.getline(Name, 20);
			for (t = 0; t < i; t++) {
				if (s[t]->search(Name)) {
					s[t]->showdata();
					break;
				}
			}
			if (t == i)
				std::cout << "Student not record in base";
			break;
		case 3:
			std::cin.ignore();
			std::cout << "\nEnter Student Name: ";
			std::cin.getline(Name, 20);
			for (t = 0; t < i; t++) {
				if (s[t]->search(Name)) {
					std::cout << "\nThe student is recorded in the database";
					std::cout << "\nWould you like to know more about the student?";
					std::cout << "\n\t1.YES";
					std::cout << "\n\t2.NO" << std::endl;
					std::cin >> ch;
					if (ch == 1)
						s[t]->showdata();
					else if (ch == 2)
						return 1;
					break;

				}

			}
			if (t == i)
				std::cout << "\nThe student is not recorded in the database";
			break;
		case 4:
			exit(0);
		default: std::cout << "\nInvalid number of choice!";
		}
	}



	return 0;
}

void student::CalcAverage() {
	average = (eng_mark + cmp_science_mark + rus_mark + physic_mark + biolog_mark) / 5.0;
	if (average >= 90)
		grade = '5';
	else if (average >= 75)
		grade = '4';
	else if (average >= 50)
		grade = '3';
	else
		grade = '2';

}

void student::getdata() {
	std::cout << "\nEnter student Roll Number: ";
	std::cin >> rollnmb;
	std::cout << "\nEnter name student: ";
	std::cin.ignore();
	std::cin.getline(name, 50);
	std::cout << "\nEnter English Mark: ";
	std::cin >> eng_mark;
	std::cout << "\nEnter Computer Science Mark: ";
	std::cin >> cmp_science_mark;
	std::cout << "\nEnter Russian Mark: ";
	std::cin >> rus_mark;
	std::cout << "\nEnter Physic Mark: ";
	std::cin >> physic_mark;
	std::cout << "\nEnter Biolog Mark: ";
	std::cin >> biolog_mark;
	CalcAverage();
}

void student::showdata() const {
	std::cout << "\nStudent Roll Number: " << rollnmb;
	std::cout << "\nStudent Name: " << name;
	std::cout << "\nEnglish mark: " << eng_mark;
	std::cout << "\nComputer Science Mark: " << cmp_science_mark;
	std::cout << "\nRussian Mark: " << rus_mark;
	std::cout << "\nPhysic Mark: " << physic_mark;
	std::cout << "\nBiolog Mark: " << biolog_mark;
	std::cout << "\nAverage: " << average;
	std::cout << "\nGrade: " << grade;
}

int student::retrollno() const {
	return rollnmb;
}



int student::search(char rnamestud[20]) {
	if (strcmp(rnamestud, name) == 0)
		return 1;
	else
		return 0;
}


