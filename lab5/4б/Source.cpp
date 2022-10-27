#include <cstdio>
#include <ctime>
#include <iostream>

using namespace std;

void qs(int *s_arr, int first, int last);

void print_arr(int *arr, int len);

int main(void) {
  cout << "Программа для сортировки массива методом быстрой сортировки" << endl;
  cout << "--------------------------------------" << endl;
  int len_mass, until;
  char c;
  cout << "Введите размер массива: ";
  cin >> len_mass;
  int *mass = new int[len_mass];
  getchar();
  cout << "Случайное заполнение массива (r) Ввод массива (i) Выход (any key): ";
  if ((c = getchar()) == 'r') {
    srand(time(NULL));
    cout << "Введите максимальное значение элементов массива: ";
    cin >> until;
    for (int i = 0; i < len_mass; i++)
      mass[i] = rand() % until + 1;
    cout << "Сгенерированный массив: " << endl;
    print_arr(mass, len_mass);
  } else if (c == 'i') {
    cout << "Введите значения элементов массива: " << endl;
    for (int i = 0; i < len_mass; i++) {
      cin >> mass[i];
    }
  } else {
    cout << "Выход..." << endl;
    return 0;
  }
  qs(mass, 0, len_mass - 1);
  cout << "Результат:" << endl;
  print_arr(mass, len_mass);
  return 0;
}

void qs(int *s_arr, int first, int last) {
  int f = first, l = last, x = s_arr[(first + last) / 2];
  do {
    while (s_arr[f] < x)
      f++;
    while (s_arr[l] > x)
      l--;
    if (f <= l) {
      if (s_arr[f] > s_arr[l]) {
        s_arr[f] = s_arr[f] + s_arr[l];
        s_arr[l] = s_arr[f] - s_arr[l];
        s_arr[f] = s_arr[f] - s_arr[l];
      }
      f++;
      l--;
    }
  } while (f <= l);
  if (f < last)
    qs(s_arr, f, last);
  if (l > first)
    qs(s_arr, first, l);
}

void print_arr(int *arr, int len) {
  for (int i = 0; i < len; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}
