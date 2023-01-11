#include <iostream>

using namespace std;

class Rational {
private:
  int a;
  int b;
public:
  void reduce() {
    int c = a;
    int d = b;
    while (c != 0 && d != 0) {
      if (c > d) {
        c %= d;
      } else {
        d %= c;
      }
    }
    a /= c + d;
    b /= c + d;
  }
  void Read(){
    cout << "Введите числитель: ";
    cin >> a;
    cout << "Введите знаменатель: ";
    cin >> b;
    reduce();
  }
  void Display(){
    cout << a << "/" << b << endl;
  }
  string toString(){
    return to_string(a) + "/" + to_string(b);
  }
  Rational add(Rational r){
    Rational result;
    result.a = a * r.b + b * r.a;
    result.b = b * r.b;
    result.reduce();
    return result;
  }
  Rational sub(Rational r){
    Rational result;
    result.a = a * r.b - b * r.a;
    result.b = b * r.b;
    if (result.a < 0) {
      result.a *= -1;
    }
    if (result.b < 0) {
      result.b *= -1;
    }
    result.reduce();
    return result;
  }
  Rational mul(Rational r){
    Rational result;
    result.a = a * r.a;
    result.b = b * r.b;
    result.reduce();
    return result;
  }
  Rational div(Rational r){
    Rational result;
    result.a = a * r.b;
    result.b = b * r.a;
    result.reduce();
    return result;
  }
  bool equal(Rational r){
    return a == r.a && b == r.b;
  }
  bool greate(Rational r){
    return a * r.b > b * r.a;
  }
  bool les(Rational r){
    return a * r.b < b * r.a;
  }
};

int main() {
  Rational r1, r2;
  cout << "Введите первую дробь" << endl;
  r1.Read();
  cout << "---------------------" << endl;
  cout << "Введите вторую дробь" << endl;
  r2.Read();
  cout << "---------------------" << endl;
  cout << "Первая дробь: ";
  r1.Display();
  cout << "Вторая дробь: ";
  r2.Display();
  cout << "---------------------" << endl;
  cout << "Сложение: " << r1.add(r2).toString() << endl;
  if (r1.greate(r2)) {
    cout << "Вычитание: " << r1.sub(r2).toString() << endl;
  }
  else {
    cout << "Вычитание: -" << r2.sub(r1).toString() << endl;
  }
  cout << "Умножение: " << r1.mul(r2).toString() << endl;
  cout << "Деление: " << r1.div(r2).toString() << endl;
  cout << "---------------------" << endl;
  cout << "Равны: " << r1.equal(r2) << endl;
  cout << "Первая больше: " << r1.greate(r2) << endl;
  cout << "Первая меньше: " << r1.les(r2) << endl;
  return 0;
}
