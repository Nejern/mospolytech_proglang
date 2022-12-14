#include <cstddef>
#include <ctime>
#include <time.h>
#include <fstream>
#include <iostream>

using namespace std;

int main() {
  int csize = sizeof(int) * 8 - 1;
  int max = 10000000;
  int len_bits = max / csize + 1;
  int bits[len_bits];
  clock_t tStart = clock();
  for (int i = 0; i < len_bits; i++) {
    bits[i] = (0 << (csize - 1));
  }
  int mask = (1 << (csize - 1));

  ifstream fIn("./file");
  while (fIn.eof() == 0) {
    int num;
    fIn >> num;
    int cindex = num / csize;
    int offset = num % csize;
    bits[cindex] = (bits[cindex] | (mask >> offset));
  }
  fIn.close();

  for (int i = 0; i < len_bits; i++) {
    for (int j = 0; j < csize; j++) {
      if ((bits[i] & (mask >> j)) == (mask >> j))
        cout << i * csize + j << endl;
    }
  }
  cout << "Время работы программы: " << (double)(clock() - tStart)/CLOCKS_PER_SEC << "с" << endl;
  return 0;
}
