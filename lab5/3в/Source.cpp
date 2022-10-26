#include <iostream>
#include <cmath>

using namespace std;

int converter(string n);

int main(void){
  string s;
  cout << "Шестнадцатиричное значение: "; cin >> s;
  cout << "Десятичное значение: " << converter(s) << endl;
  
  return 0;
}

int converter(string n){
  int N = 0, mlt = 0;
  while (n.length() > 0) {
    if (isdigit(n[n.length() - 1])) {
      N += pow(16, mlt++) * (n[n.length() - 1] - '0');
    }
    else {
      N += pow(16, mlt++) * (10 + n[n.length() - 1] - 'A');
    }
      n.pop_back();
    }

    return N;
}
