#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main(void){
  cout << "Программа, заменяющая в исходной строке символов" << endl;
  cout << "все единицы нулями, а все нули единицами," << endl;
  cout << "начиная с заданной позиции строки" << endl;
  cout << "------------------------------------------" << endl;

  char *s = (char*)malloc(sizeof(char));
  char input;
  int n = 0;
  cout << "Введите строку:" << endl;
  while ((input = getchar()) != '\n'){
    s = (char*)realloc(s, (n + 1) * sizeof(char));
    s[n] = input;
    n++;
  }

  int shag = 5;
  for (int i = 0; i < n; i++){
    if (i % shag == 0){
      cout << i;

      int razr = 0, I = i;
      do{
        razr++;
        I /= 10;
      }while (I != 0);

      for (int j = shag - razr; j != 0; j--){
        cout << " ";
      }
    }
  }
  cout << endl;

  int j;
  cout << "Введите позицию строки (начиная с 0) >"; cin >> j;
  for (int i = j; i < n; i++){
    if (s[i] == '0') s[i] = '1';
    else if (s[i] == '1') s[i] = '0';
  }

  cout << "Результат:" << endl;
  cout << s << endl;

  free(s);
  return 0;
}
