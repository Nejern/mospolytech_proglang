#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>

using namespace std;

int main() {
  srand(time(NULL));
  const int max = 100000;
  int arr[max];
  for (int i = 0; i < max; i++) {
    arr[i] = i;
  }

  for (int i = 0; i < max; i++) {
    swap(arr[random() % max], arr[random() % max]);
  }
  ofstream fOut("file");
  for (int i = 0; i < max; i++) {
    fOut << arr[i] << endl;
  }
  return 0;
}
