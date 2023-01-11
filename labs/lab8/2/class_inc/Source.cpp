#include <iostream>

using namespace std;

struct RationalStruct {
  int a;
  int b;
  void Read() {
    cout << "Введите числитель: ";
    cin >> a;
    cout << "Введите знаменатель: ";
    cin >> b;
  }
  void Display() { cout << toString() << endl; }
  string toString() { return to_string(a) + "/" + to_string(b); }
};

class Rational {
public:
  RationalStruct r;
  void reduce() {
    int c = r.a;
    int d = r.b;
    while (c != 0 && d != 0) {
      if (c > d) {
        c %= d;
      } else {
        d %= c;
      }
    }
    r.a /= c + d;
    r.b /= c + d;
  }
  Rational add(Rational r2) {
    Rational result;
    result.r.a = r.a * r2.r.b + r.b * r2.r.a;
    result.r.b = r.b * r2.r.b;
    result.reduce();
    return result;
  }
  Rational sub(Rational r2) {
    Rational result;
    result.r.a = r.a * r2.r.b - r.b * r2.r.a;
    result.r.b = r.b * r2.r.b;
    if (result.r.a < 0) {
      result.r.a *= -1;
    }
    if (result.r.b < 0) {
      result.r.b *= -1;
    }
    result.reduce();
    return result;
  }
  Rational mul(Rational r2) {
    Rational result;
    result.r.a = r.a * r2.r.a;
    result.r.b = r.b * r2.r.b;
    result.reduce();
    return result;
  }
  Rational div(Rational r2) {
    Rational result;
    result.r.a = r.a * r2.r.b;
    result.r.b = r.b * r2.r.a;
    result.reduce();
    return result;
  }
  bool equal(Rational r2) { return r.a == r2.r.a && r.b == r2.r.b; }
  bool greate(Rational r2) { return r.a * r2.r.b > r.b * r2.r.a; }
  bool les(Rational r2) { return r.a * r2.r.b < r.b * r2.r.a; }
};

int main() {
  Rational r1, r2;
  cout << "Введите первую дробь" << endl;
  r1.r.Read();
  cout << "---------------------" << endl;
  cout << "Введите вторую дробь" << endl;
  r2.r.Read();
  cout << "---------------------" << endl;
  cout << "Первая дробь: ";
  r1.reduce();
  r1.r.Display();
  cout << "Вторая дробь: ";
  r2.reduce();
  r2.r.Display();
  cout << "---------------------" << endl;
  cout << "Сложение: " << r1.add(r2).r.toString() << endl;
  if (r1.greate(r2)) {
    cout << "Вычитание: " << r1.sub(r2).r.toString() << endl;
  } else {
    cout << "Вычитание: -" << r2.sub(r1).r.toString() << endl;
  }
  cout << "Умножение: " << r1.mul(r2).r.toString() << endl;
  cout << "Деление: " << r1.div(r2).r.toString() << endl;
  cout << "---------------------" << endl;
  cout << "Равны: " << r1.equal(r2) << endl;
  cout << "Первая больше: " << r1.greate(r2) << endl;
  cout << "Первая меньше: " << r1.les(r2) << endl;
  return 0;
}
