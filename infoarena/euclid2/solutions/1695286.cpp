#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  int t, n1, n2;
  ifstream readFile;
  readFile.open("euclid2.in");
  ofstream writeFile;
  writeFile.open("euclid2.out");
  readFile >> t;
  for (int i = 0; i < t; i++)
  {
    readFile >> n1;
    readFile >> n2;
    if (n1 < n2) {
      n1 += n2;
      n2 = n1 - n2;
      n1 = n1 - n2;
    }
    // euclid prin impartiri succesive
    if (n1 != 0 && n2 != 0)
    {
      int r = n1 % n2;
      while (r != 0)
      {
        n1 = n2;
        n2 = r;
        r = n1 % n2;
      }
    }
    writeFile << n2 << endl;
  }

  readFile.close();
  writeFile.close();
  return 0;
}
