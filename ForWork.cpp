#include <iostream>

using namespace std;

void StartProgramm();
int SecurityInput(int);
void Choise();
void openAllAutoStart();
void copyShortCut();

int main() {
	setlocale(LC_ALL, "ru");
	StartProgramm();
	return 0;
}

void StartProgramm() {
	int inp, SecInp;
	while (true)
	{
		Choise();
		cin >> inp;
		SecInp = SecurityInput(inp);
		if (SecInp != -1) {
			system("cls");
			switch (SecInp)
			{
			case 0:
				return;
				break;
			case 1:
				openAllAutoStart();
				break;
			case 2:
				copyShortCut();
				break;
			default:
				cout << "Нет такого варианта!";
				break;
			}
		}
		else {
			system("cls");
			cout << "Некорректный ввод" << endl << endl;
			continue;
		}
	}
}

void Choise() {
	cout << "-------------------------------" << endl;
	cout << "0. Выход" << endl;
	cout << "1. Открыть папку автозагрузки" << endl;
	cout << "2. Копировать ярлыки на рабочий" << endl;
	cout << "Выберите: ";
}

int SecurityInput(int inpp) {
	if (!cin.fail()) {
		return inpp;
	}
	else {
		cin.clear();
		cin.ignore();
		return -1;
	}
}

void openAllAutoStart() {
	system("explorer \"%ProgramData%\\Microsoft\\Windows\\Start Menu\\Programs\\StartUp\"");
}

void copyShortCut() {
	system("if not exist files mkdir files && copy files\\* \"%USERPROFILE%\\Desktop\" /Y");
}