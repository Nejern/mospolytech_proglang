#include <iostream>

using namespace std;

struct range {
  int first, second;
  void Init(int F, int S) {
    first = F;
    second = S;
  }
  void Read() {
    cout << "Введите начало диапазона: ";
    cin >> first;
    cout << "Введите конец диапазона: ";
    cin >> second;
  }
  void Display() { cout << "Диапазон: " << first << " - " << second << endl; }
  bool rangecheck(int x) {
    if (x >= first && x < second)
      return true;
    else
      return false;
  }
};

range make_range(int F, int S) {
  range r;
  r.Init(F, S);
  return r;
}

int main() {
  range r1;
  r1.Init(1, 10);
  r1.Read();
  r1.Display();
  int x;
  cout << "Введите число: ";
  cin >> x;
  if (r1.rangecheck(x))
    cout << "Число входит в диапазон" << endl;
  else
    cout << "Число не входит в диапазон" << endl;
  return 0;
}
