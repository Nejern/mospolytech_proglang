#include <ctime>
#include <iostream>

using namespace std;

void qs(int *arr, int first, int last);

void printarr(int *mass);

int n, *arr;

int main(void){
  srand(time(NULL));
  cout << "Введите размер массива: "; cin >> n;
  arr = new int[n];
  for (int i; i < n; i++) arr[i] = rand() % 1000;

  printarr(arr);
  qs(arr, 0, n - 1);
  printarr(arr);

  return 0;
}

void qs(int *s_arr, int first, int last){
  int f = first, l = last, x = s_arr[(first + last) / 2];
  do {
    while (s_arr[f] < x) f++;
    while (s_arr[l] > x) l--;

    if (f < l){
      if (s_arr[f] < s_arr[l]) swap(s_arr[f], s_arr[l]);
      f++;
      l--;
    }
  } while (f <= l);
  if (f < last) qs(s_arr, f, last);
  if (l > first) qs(s_arr, first, l);
}

void printarr(int *mass){
  for (int i; i < n; i++){
    cout << mass << " ";
  }
}
