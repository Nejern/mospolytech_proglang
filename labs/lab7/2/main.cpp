#include <iostream>

using namespace std;

long long insertionSort(int arr[], int n);
void genHardArray(int *arr, int n);
void genMediumArray(int *arr, int n);
void genEasyArray(int *arr, int n);

int main() {
  srand(time(NULL));
  int n = 10;
  int until = 100000;
  cout << "-------------------------------" << endl;
  cout << "Insertion Sort - Easy array" << endl;
  cout << "-------------------------------" << endl;
  while (n < until) {
    n *= 10;
    int arr[n];
    genEasyArray(arr, n);
    clock_t workTime = clock();
    long long crit = insertionSort(arr, n);
    cout << "n = " << n << " - "
         << (double)(clock() - workTime) / CLOCKS_PER_SEC << " seconds, ";
    cout << "Critical value: " << crit << endl;
  }
  cout << "-------------------------------" << endl;
  cout << "Insertion Sort - Medium array" << endl;
  cout << "-------------------------------" << endl;
  n = 10;
  while (n < until) {
    n *= 10;
    int arr[n];
    genMediumArray(arr, n);
    clock_t workTime = clock();
    long long crit = insertionSort(arr, n);
    cout << "n = " << n << " - "
         << (double)(clock() - workTime) / CLOCKS_PER_SEC << " seconds, ";
    cout << "Critical value: " << crit << endl;
  }
  cout << "-------------------------------" << endl;
  cout << "Insertion Sort - Hard array" << endl;
  cout << "-------------------------------" << endl;
  n = 10;
  while (n < until) {
    n *= 10;
    int arr[n];
    genHardArray(arr, n);
    clock_t workTime = clock();
    long long crit = insertionSort(arr, n);
    cout << "n = " << n << " - "
         << (double)(clock() - workTime) / CLOCKS_PER_SEC << " seconds, ";
    cout << "Critical value: " << crit << endl;
  }

  return 0;
}

long long insertionSort(int arr[], int n) {
  long long comparisons = 0;
  long long swaps = 0;
  int key, j;
  for (int i = 1; i < n; i++) {
    key = arr[i];
    j = i - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j--;
      swaps++;
      comparisons++;
    }
    arr[j + 1] = key;
    swaps++;
  }
  return comparisons + swaps;
}

void genMediumArray(int *arr, int n) {
  for (int i = 0; i < n; i++) {
    arr[i] = rand() % 10;
  }
}

void genEasyArray(int *arr, int n) {
  for (int i = 0; i < n; i++) {
    arr[i] = i;
  }
}

void genHardArray(int *arr, int n) {
  for (int i = 0; i < n; i++) {
    arr[i] = n - i;
  }
}
