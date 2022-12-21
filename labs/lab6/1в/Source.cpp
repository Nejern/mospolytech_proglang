#include <fstream>
#include <iostream>

using namespace std;

int main(void) {
  ifstream fIn("input.txt");
  ofstream fOut("output.txt");
  int line;
  while (not fIn.eof()) {
    fIn >> line;
    if (not fIn.eof())
      fOut << line * 2 << endl;
  }
  fIn.close();
  fOut.close();

  return 0;
}
