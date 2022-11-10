#include <fstream>
#include <iostream>

using namespace std;

int main(void) {
  ifstream fIn("f");
  ofstream fOut("g");
  string line;
  while (not fIn.eof()) {
    getline(fIn, line);
    for (auto i = line.end() - 1; i >= line.begin(); i--) {
      fOut << *i;
    }
    fOut << endl;
  }

  fIn.close();
  fOut.close();
  return 0;
}
