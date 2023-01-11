#include <iostream>
#include <math.h>

using namespace std;

class Angle {
  double angle;
  double minutes;

public:
  Angle() {
    angle = 0;
    minutes = 0;
  }

  Angle(double a, double m) {
    angle = a;
    minutes = m;
  }

  double getAngle() { return angle; }

  double getMinutes() { return minutes; }

  void setAngle(double a) { angle = a; }

  void setMinutes(double m) { minutes = m; }

  double getRadians() {
    return (angle + minutes * (1.0 / 60.0)) * (M_PI / 180.0);
  }

  double getRange() { return (angle + minutes * (1.0 / 60.0)); }
};

class Triangle {
  Angle a;
  Angle b;
  Angle c;
  float sideA;
  float sideB;
  float sideC;

public:
  Triangle() {
    a = Angle();
    b = Angle();
    c = Angle();
    sideA = 0;
    sideB = 0;
    sideC = 0;
  }
  Triangle(Angle a, Angle b, Angle c, float sideA, float sideB, float sideC) {
    this->a = a;
    this->b = b;
    this->c = c;
    this->sideA = sideA;
    this->sideB = sideB;
    this->sideC = sideC;
  }
  void setAngleA(Angle angle) { a = angle; }
  void setAngleB(Angle angle) { b = angle; }
  void setAngleC(Angle angle) { c = angle; }
  void setSideA(float side) { sideA = side; }
  void setSideB(float side) { sideB = side; }
  void setSideC(float side) { sideC = side; }
  Angle getAngleA() { return a; }
  Angle getAngleB() { return b; }
  Angle getAngleC() { return c; }
  float getSideA() { return sideA; }
  float getSideB() { return sideB; }
  float getSideC() { return sideC; }
  float getPerimeter() { return sideA + sideB + sideC; }
  float getArea() {
    float p = getPerimeter() / 2;
    return sqrt(p * (p - sideA) * (p - sideB) * (p - sideC));
  }
  float getHeighA() { return 2 * getArea() / sideA; }
  float getHeighB() { return 2 * getArea() / sideB; }
  float getHeighC() { return 2 * getArea() / sideC; }
  void printType() {
    cout << "Тип треугольника:" << endl;
    if (a.getAngle() == 90 || b.getAngle() == 90 || c.getAngle() == 90) {
      cout << "\tПрямоугольный" << endl;
    } else if (sideA == sideB && sideB == sideC) {
      cout << "\tРавносторонний" << endl;
    }
    if (sideA == sideB || sideB == sideC || sideA == sideC) {
      cout << "\tРавнобедренный" << endl;
    }
  }
  void print() {
    cout << "Углы треугольника:" << endl;
    cout << "\tA: " << a.getAngle() << "° " << a.getMinutes() << "'" << endl;
    cout << "\tB: " << b.getAngle() << "° " << b.getMinutes() << "'" << endl;
    cout << "\tC: " << c.getAngle() << "° " << c.getMinutes() << "'" << endl;
    cout << "Стороны треугольника:" << endl;
    cout << "\tAB: " << sideA << endl;
    cout << "\tBC: " << sideB << endl;
    cout << "\tCA: " << sideC << endl;
    cout << "Периметр треугольника: " << getPerimeter() << endl;
    cout << "Площадь треугольника: " << getArea() << endl;
    cout << "Высоты треугольника:" << endl;
    cout << "\tВысота, проведенная из угла A: " << getHeighA() << endl;
    cout << "\tВысота, проведенная из угла B: " << getHeighB() << endl;
    cout << "\tВысота, проведенная из угла C: " << getHeighC() << endl;
    printType();
  }
};

int main() {
  Triangle t;
  t.setAngleA(Angle(90, 0));
  t.setAngleB(Angle(45, 0));
  t.setAngleC(Angle(45, 0));
  t.setSideA(3);
  t.setSideB(4);
  t.setSideC(5);
  t.print();
}
