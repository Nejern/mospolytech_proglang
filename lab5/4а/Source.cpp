#include <iostream>

using namespace std;

unsigned long long int factorial(int n);

int main(void){
  int n;
  cout << "Введите число для нахождения его факториала: "; cin >> n;
  cout << "Результат: " << factorial(n) << endl;
  return 0;
}

unsigned long long int factorial(int num){
  if (num == 1){
    return 1;
  }
  return num * factorial(num - 1);
}
