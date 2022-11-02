#include <iostream>
#include <cstring>

using namespace std;

int main() {
  const int len = 81;
  char text[len], search[len];
  cout << "Введите строку: ";
  cin.getline(text, len);
  cout << "Введите строку для поиска: ";
  cin.getline(search, len);

  if (strstr(text, search)) {
    cout << "Присутствует!" << endl;
  }
  else {
    cout << "Отсутствует!" << endl;
  }
  return 0;
}
