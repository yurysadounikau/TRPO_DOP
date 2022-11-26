#include <iostream>
#include <locale.h>


struct Notebook{
	char name[100];
	char memory[100];
	char display_size[100];
	char price[100];
};


FILE* file;
Notebook* OurNotebooks = 0;
int notebookAmmount = 0;


Notebook* addStruct();
int menu();
void addNew();
void search();
void changeParametr();
void sort();
void output(const Notebook* Obj, const int ammount);
void saveInFile();
void takeFromFile();
void setData();


int main(){

    setlocale(LC_ALL, "ru");
    menu();


	return 0;
}



int menu() {
	std::cout << "����:\n\n";
	std::cout << "1 - �������� ������ � ������.\n";
	std::cout << "2 - �����.\n";
	std::cout << "3 - �������� ��������.\n";
	std::cout << "4 - ����������.\n";
	std::cout << "5 - �����.\n";
	std::cout << "6 - ������ ������� �������� � ����.\n";
	std::cout << "7 - �������� ������ �������� �� �����.\n";
	std::cout << "0 - ����� �� ���������.\n";


	int choice = 0;
	bool IsIncorrect;
	do {
		std::cout << "\n��� �����: ";
		IsIncorrect = false;
		std::cin >> choice;
		if (std::cin.fail())
		{
			std::cin.clear();
			while (std::cin.get() != '\n');
			IsIncorrect = true;
			std::cout << "����������� ��������� ��� ������ (�������� �������� ������ ���� ����� ������)" << std::endl;
		}
		if (!IsIncorrect && std::cin.get() != '\n')
		{
			std::cin.clear();
			while (std::cin.get() != '\n');

			std::cout << "������ �����, ������� ����� �� 0 �� 7" << std::endl;
			IsIncorrect = true;
		}
		if (!IsIncorrect && (choice < 0||choice>7))
		{
			IsIncorrect = true;
			std::cout << "������� ��������� �����(�������� �� 0 �� 7)" << std::endl;
		}
	} while (IsIncorrect);


	
	if (choice == 0){
		std::cout << "\n\n�� ����� �� ���������, �������� ���!\n";
		return 0;
	}
	if (choice == 1){
		std::cout << "\n\n\n==========================================\n\n\n";
		addNew();
	}
	if (choice == 2){
		std::cout << "\n\n\n==========================================\n\n\n";
		search();
	}
	if (choice == 3){
		std::cout << "\n\n\n==========================================\n\n\n";
		changeParametr();
	}
	if (choice == 4){
		std::cout << "\n\n\n==========================================\n\n\n";
		sort();
	}	
	if (choice == 5){
		std::cout << "\n\n\n==========================================\n\n\n";
		output(OurNotebooks, notebookAmmount);
	}
	if (choice == 6){
		std::cout << "\n\n\n==========================================\n\n\n";
		saveInFile();
	}
	if (choice == 7){
		std::cout << "\n\n\n==========================================\n\n\n";
		takeFromFile();
	}
}


Notebook* addStruct(Notebook* Obj, const int amount) {
	if (amount == 0) {
		Obj = new Notebook[amount + 1];
	}
	else {
		Notebook* tempObj = new Notebook[amount + 1];

		for (int i = 0; i < amount; ++i) {
			tempObj[i] = Obj[i];
		}
		delete[]Obj;
		Obj = tempObj;
	}
	return Obj;
}


void setData(Notebook* Obj, const int ammount){
	std::cout << "������� �������� ��������: ";
	std::cin.getline(Obj[ammount].name, 100);
	std::cout << "\n������� ���������� ������ ��������: ";
	std::cin.getline(Obj[ammount].memory, 100);
	std::cout << "\n������� ������ ������� ��������: ";
	std::cin.getline(Obj[ammount].display_size, 100);
	std::cout << "\n������� ���� ��������: ";
	std::cin.getline(Obj[ammount].price, 100);
	std::cout << std::endl;
}


void addNew(){
	int choice = 0;
	do{
		OurNotebooks = addStruct(OurNotebooks, notebookAmmount);
		setData(OurNotebooks, notebookAmmount);

		++notebookAmmount;
		std::cout << "\n������ ���������� ��������� �������� � ������?\n";
		std::cout << "1 - ��.";
		std::cout << "\n2 - ���.";
		bool IsIncorrect;
		do {
			std::cout << "\n\n��� �����: ";
			IsIncorrect = false;
			std::cin >> choice;
			if (std::cin.fail()){
				std::cin.clear();
				while (std::cin.get() != '\n');
				IsIncorrect = true;
				std::cout << "����������� ��������� ��� ������ (�������� �������� ������ ���� ����� ������)" << std::endl;
			}
			if (!IsIncorrect && std::cin.get() != '\n'){
				std::cin.clear();
				while (std::cin.get() != '\n');

				std::cout << "������ �����, ������� ����� 1 ��� 2" << std::endl;
				IsIncorrect = true;
			}
			if (!IsIncorrect && (choice < 0 || choice>7)){
				IsIncorrect = true;
				std::cout << "������� ��������� �����(�������� �� 1 ��� 2)" << std::endl;
			}
		} while (IsIncorrect);
		
		if (choice == 2) std::cout << "�� ��������� ��������� �������� � ������.";
	} while (choice != 2);



	std::cout << "\n\n\n=======================\n\n";
	menu();
}


void search() {

}


void changeParametr() {

}


void sort() {

}


void output(const Notebook*Obj, const int ammount) {
	system("cls");
	std::cout << "#  " << "��������\t" << "������ ������\t" << "������ ������\t" << "���������\n\n";
	for (int i = 0; i < ammount; ++i) {
		std::cout << i + 1 << Obj[i].name << "\t" << Obj[i].memory << "\t" << Obj[i].display_size << "\t" << Obj[i].price << std::endl;
	}


	std::cout << "\n\n\n=======================\n\n";
	menu();
}


void saveInFile() {

}


void takeFromFile() {

}