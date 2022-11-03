#include <ctime>
#include <fstream>
#include <iostream>

using namespace std;

int main(void) {
  srand(time(NULL));
  ofstream fOut;

  fOut.open("random.txt");
  for (int i = 0; i < 25; i++){
    fOut << rand() << endl;
  }

  return 0;
}
