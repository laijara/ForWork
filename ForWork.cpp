#include <iostream>

using namespace std;

void StartProgramm();
int SecurityInput(int);
void openAllAutoStart();

int main() {
	setlocale(LC_ALL, "ru");
	StartProgramm();
	return 0;
}

void StartProgramm() {
	int inp, SecInp;
	while (true)
	{
		cout << "0. Выход" << endl;
		cout << "1. Открыть папку автозагрузки" << endl;
		cout << "Выберите: ";
		cin >> inp;
		SecInp = SecurityInput(inp);
		if (SecInp != -1) {
			if (SecInp == 0) {
				break;
			}
			system("cls");
			openAllAutoStart();
		}
		else {
			system("cls");
			cout << "Некорректный ввод" << endl << endl;
			continue;
		}
	}
}

int SecurityInput(int inpp) {
	if (!cin.fail() && inpp == 0 || inpp == 1) {
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