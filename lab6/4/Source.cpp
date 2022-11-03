#include <iostream>
#include <inttypes.h>

using namespace std;

int main(void) {
  int n;
  int max = 0;
  cout << "Введите размер массива: ";
  cin >> n;
  int *numbers = new int[n];
  int len_numbers;
  cout << "Введите значения массива:" << endl;
  for (int i = 0; i < n; i++) {
    cin >> numbers[i];
    if (numbers[i] > max)
      max = numbers[i];
    len_numbers = i + 1;
  }
  unsigned char *bits = new unsigned char[max + 1];
  for (int i = 0; i < max + 1; i++) {
    bits[i] = 0;
  }
  for (int i = 0; i < len_numbers; i++) {
    bits[numbers[i]] = 1;
  }
  cout << "Результат:" << endl;
  for (int i = 0; i < max + 1; i++) {
    if ((int)bits[i] == 1) cout << i << " ";
  }
  cout << endl;

  free(bits);
  delete[] numbers;
  return 0;
}
