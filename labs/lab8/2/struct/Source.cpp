#include <iostream>

using namespace std;

struct Rational {
  int a;
  int b;
};

void reduce(Rational &r) {
  int a = r.a;
  int b = r.b;
  while (a != 0 && b != 0) {
    if (a > b) {
      a %= b;
    } else {
      b %= a;
    }
  }
  r.a /= a + b;
  r.b /= a + b;
}

void Init(Rational &r, int a, int b) {
  r.a = a;
  r.b = b;
  reduce(r);
}

void Read(Rational &r) {
  int a, b;
  cout << "Введите числитель: ";
  cin >> a;
  cout << "Введите знаменатель: ";
  cin >> b;
  Init(r, a, b);
}

void Display(Rational r) {
  cout << r.a << "/" << r.b << endl;
}

string toString(Rational &r) {
  return to_string(r.a) + "/" + to_string(r.b);
}

Rational add(Rational &r1, Rational &r2) {
  Rational r;
  int a = r1.a * r2.b + r2.a * r1.b;
  int b = r1.b * r2.b;
  if (a < 0 && b < 0) {
    a = -a;
    b = -b;
  }
  return r;
}

Rational sub(Rational &r1, Rational &r2) {
  Rational r;
  Init(r, r1.a * r2.b - r2.a * r1.b, r1.b * r2.b);
  return r;
}

Rational mul(Rational &r1, Rational &r2) {
  Rational r;
  Init(r, r1.a * r2.a, r1.b * r2.b);
  return r;
}

Rational div(Rational &r1, Rational &r2) {
  Rational r;
  Init(r, r1.a * r2.b, r1.b * r2.a);
  return r;
}

bool equal(Rational &r1, Rational &r2) {
  return r1.a == r2.a && r1.b == r2.b;
}

bool greate(Rational &r1, Rational &r2) {
  return r1.a * r2.b > r2.a * r1.b;
}

bool les(Rational &r1, Rational &r2) {
  return r1.a * r2.b < r2.a * r1.b;
}

int main() {
  Rational r1, r2;
  cout << "Введите первую дробь" << endl;
  Read(r1);
  cout << "-------------------" << endl;
  cout << "Введите вторую дробь" << endl;
  Read(r2);
  cout << "-------------------" << endl;
  cout << "Первая дробь: ";
  Display(r1);
  cout << "-------------------" << endl;
  cout << "Вторая дробь: ";
  Display(r2);
  cout << "-------------------" << endl;
  cout << "Сумма: ";
  Display(add(r1, r2));
  cout << "Разность: ";
  Display(sub(r1, r2));
  cout << "Произведение: ";
  Display(mul(r1, r2));
  cout << "Частное: ";
  Display(div(r1, r2));
  cout << "Равны: " << equal(r1, r2) << endl;
  cout << "Первая больше: " << greate(r1, r2) << endl;
  cout << "Первая меньше: " << les(r1, r2) << endl;
  return 0;
}
