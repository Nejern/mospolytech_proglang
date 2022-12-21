#include <cmath>
#include <ctime>
#include <iostream>

using namespace std;

bool isprime(int num);

int maxnum(int *arr[], int arr_size);

void printarr(int *arr[], int arr_size);

int main() {
  srand(time(NULL));
  int n;
  cout << "Введите n: "; cin >> n;
  int **mass = new int *[n];
  for (int i = 0; i < n; ++i) {
    mass[i] = new int[n];
    for (int j = 0; j < n; ++j) {
      mass[i][j] = rand() % 100;
    }
  }
  printarr(mass, n);
  cout << maxnum(mass, n) << endl;
  return 0;
}
bool isprime(int num){
  if (num < 2) return false;
  else for (int i = 2; i <= sqrt(num); i++) if (num % i == 0) return false;
  return true;
}
int maxnum(int *arr[], int arr_size){
  int max = 0;
  for (int i = 0; i < arr_size; ++i) {
    for (int j = 0; j < arr_size; ++j) {
      if (isprime(arr[i][j]) && arr[i][j] > max) {
        max = arr[i][j];
      }
    }
  }
  return max;
}
void printarr(int *arr[], int arr_size){
  for (int i = 0; i < arr_size; ++i) {
    for (int j = 0; j < arr_size; ++j) {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
}
