#include <iostream>
#include <cmath>

using namespace std;

char* s = (char*)malloc(sizeof(char));

int main() {
  cout << "Программа для нахождения количества вхождений строки aba в заданную строку" << endl;
  cout << "-----------------------------------" << endl;

  cout << "Введите все s: ";
  char c;
  int n = 0;
  while ((c = getchar()) != '\n') {
    s[n] = c;
    s = (char*)realloc(s, pow(n+2, 2) * sizeof(char));
      n++;
  }

  int counter = 0, j = 0;
  cout << "Вхождения пересекаются? (y/n): ";
    if ((c = getchar()) == 'y') {
      while (j <= n - 3) {
        if (s[j] == 'a' && s[j + 1] == 'b' && s[j + 2] == 'a') {
          counter++;
        }
        j++;
      }
    }
    else if (c == 'n') {
      while (j <= n - 3) {
        if (s[j] == 'a' && s[j + 1] == 'b' && s[j + 2] == 'a') {
          counter++;
          j += 2;
        }
        j++;
      }
    }

    cout << "Результат: " << counter << endl;
    free(s);
    return 0;
}
