#include <ctime>
#include <iostream>

using namespace std;

void delFirstMethod(int *arr, int &n, int x);
void delSecondMethod(int *arr, int &n, int x);
void genEasyArray(int *arr, int n, int x);
void genMediumArray(int *arr, int n);
void genHardArray(int *arr, int n, int x);

int main() {
  srand(1);

  int n, x;
  float timeInSec;
  char choice;

  cout << "Enter the size of the array: ";
  cin >> n;
  int *arr = new int[n];

  cout << "Press 'e' to generate an easy array or 'm' to generate a medium or "
          "'h' to generate a hard array: ";
  cin >> choice;

  cout << "Enter the number to delete: ";
  cin >> x;

  if (choice == 'e') {
    genEasyArray(arr, n, x);
  } else if (choice == 'm') {
    genMediumArray(arr, n);
  } else if (choice == 'h') {
    genHardArray(arr, n, x);
  } else {
    cout << "Invalid choice" << endl;
    return 0;
  }

  cin.get();
  cout << "Press 1 to use the first method, 2 to use the second method: ";
  choice = cin.get();
  if (choice == '1') {
    clock_t start = clock();
    delFirstMethod(arr, n, x);
    clock_t end = clock();
    timeInSec = (float)(end - start) / CLOCKS_PER_SEC;
  } else if (choice == '2') {
    clock_t start = clock();
    delSecondMethod(arr, n, x);
    clock_t end = clock();
    timeInSec = (float)(end - start) / CLOCKS_PER_SEC;
  } else {
    cout << "Invalid choice!" << endl;
    return 0;
  }

  cout << "Time: " << timeInSec << endl;
  return 0;
}

void genEasyArray(int *arr, int n, int x) {
  for (int i = 0; i < n; i++) {
    arr[i] = rand() % 10;
    while (arr[i] == x) {
      arr[i] = rand() % 10;
    }
  }
}

void genMediumArray(int *arr, int n) {
  for (int i = 0; i < n; i++) {
    arr[i] = rand() % 10;
  }
}

void genHardArray(int *arr, int n, int x) {
  for (int i = 0; i < n; i++) {
    arr[i] = x;
  }
}

void delFirstMethod(int *arr, int &n, int x) {
  int i = 0;
  while (i <= n) {
    if (arr[i] == x) {
      for (int j = i; j < n - 1; j++) {
        arr[j] = arr[j + 1];
      }
      n--;
    } else {
      i++;
    }
  }
}

void delSecondMethod(int *arr, int &n, int x) {
  int j = 0;
  for (int i = 0; i < n; i++) {
    arr[j] = arr[i];
    if (arr[i] != x) {
      j++;
    }
  }
  n = j;
}
