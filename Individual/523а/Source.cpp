#include <algorithm>
#include <fstream>
#include <iostream>

using namespace std;

int main(void) {
  ifstream fIn("f");
  ofstream fOut("g");
  const int len = 24;
  string line;
  while (not fIn.eof()) {
    getline(fIn, line);
    reverse(line.begin(), line.end());
    fOut << line << endl;
  }

  fIn.close();
  fOut.close();
  return 0;
}
