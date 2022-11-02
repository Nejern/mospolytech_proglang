#include <iostream>

using namespace std;

int main() {

	unsigned char ch = 0;

	cout << "Программа, преобразующая прописные буквы в строчные и наоборот" << endl;
	cout << "---------------------------" << endl;

	while ((int)ch != 48) {
		cout << "Введите букву (0 для выхода): ";
		cin >> ch;
		if ((int)ch != 48) {
			if ((int)ch == 168) {
				cout << (char)(ch + 16);
			}
			else if ((int)ch == 184) {
				cout << (char)(ch - 16);
			}
			else if (((int)ch < 91) || (((int)ch > 191) && (((int)ch < 224)))) {
				cout << (char)(ch + 32);
			}
			else if (((int)ch > 96 && (((int)ch < 123))) || (((int)ch > 223) && (((int)ch <= 255)))) {
				cout << (char)(ch - 32);
			}
		}
		else {
			cout << "Выход...";
		}
		cout << endl;
	}
	return 0;
}