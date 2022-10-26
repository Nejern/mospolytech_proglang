#include <cmath>
#include <iostream>

using namespace std;

inline bool isprime(int num);

int main() {
  for (int i = 0; i <= 100; i++){
    if (isprime(i)) cout << i << " ";
  }
  cout << endl;

  return 0;
}

bool isprime(int num){
  if (num < 2) return false;
  else for (int i = 2; i <= sqrt(num); i++) if (num % i == 0) return false;
  return true;
}
