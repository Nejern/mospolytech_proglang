#include <iostream>

using namespace std;

int main(void){
  short x;
  unsigned char mask = 0x01;
  cin >> x;
  x = x | (mask << 6);
  cout << (int)x << endl;
  return 0;
}
