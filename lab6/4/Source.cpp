#include <fstream>
#include <iostream>

using namespace std;

int main() {
  int array[] = {33, 0, 31, 16, 6, 1, 30};
  int len_array = 7;

  int max = -1;
  int csize = sizeof(int) * 8 - 1;
  cout << "csize: " << csize << endl;
  for (int i = 0; i < len_array; i++) {
    if (max < array[i])
      max = array[i];
  }
  int len_bits = max / csize + 1;
  int bits[len_bits];

  for (int i = 0; i < len_bits; i++) {
    bits[i] = (0 << (csize - 1));
  }
  int mask = (1 << (csize - 1));

  for (int i = 0; i < len_array; i++) {
    int num = array[i];
    int cindex = num / csize;
    int offset = num % csize;
    bits[cindex] = (bits[cindex] | (mask >> offset));
  }

  for (int i = 0; i < len_bits; i++) {
    for (int j = 0; j < csize; j++) {
      if ((bits[i] & (mask >> j)) == (mask >> j))
        cout << i * csize + j << " ";
    }
  }
  cout << endl;
  return 0;
}
