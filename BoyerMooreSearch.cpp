#include <iostream>
#include <string>

using namespace std;

string userText, userSubString;

int shiftTable[1000], userStringLenght, userSubStringLenght;

static void shiftPrepare() {

	for (int i = 0; i < 1000; i++) {
		shiftTable[i] = userSubStringLenght;
	}
	for (int i = 0; i < userSubStringLenght; i++) {
		shiftTable[userSubString[i]] = userSubStringLenght - i - 1;
	}
}

static int boyerMoore() {

	int border = 0;

	while (border <= userStringLenght - userSubStringLenght) {

		int lastSymOfString = userSubStringLenght - 1;

		while (lastSymOfString >= 0 && userText[border + lastSymOfString] == userSubString[lastSymOfString]) {
			lastSymOfString--;
		}

		if (lastSymOfString == -1) {
			return border;
		}
		border += shiftTable[userText[border + lastSymOfString]];
	}
	return -1;
}
int main() {

	system("chcp 1251 > Null");

	cout << "Введите строку: "; getline(cin, userText);
	cout << "\nВведите искомую подстроку: "; getline(cin, userSubString);

	userStringLenght = userText.length();
	userSubStringLenght = userSubString.length();

	shiftPrepare();

	int position = boyerMoore();
	if (position == -1) {
		cout << "\nПодстрока " << userSubString << " отсутствует в строке " << userText << endl;
	}
	else {
		cout << "\nПодстрока " << userSubString << " найдена. Начинается с позиции " << position + 1 << endl;
	}
	return 0;
}

