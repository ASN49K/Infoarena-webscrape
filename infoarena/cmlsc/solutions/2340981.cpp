#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
  ifstream infile("cmlsc.in");
  ofstream outfile("cmlsc.out");

  vector<int> Rezultat;

  int len1=0, len2=0, lenR=0, num1, num2, limita=0;;

  infile >> len1 >> len2;

  int sir1[len1] = {}, sir2[len2] = {};

  if((len1 >= 1) && (len2 <= 1024))
  {
    for(int i=0; i<len1; i++) //introduce numerele in primul sir
    {
      infile >> num1;
      if(num1 <= 256)
      {
        sir1[i] = num1;
      }
    }

    for(int i=0; i<len2; i++) //introduce numerele in al doilea sir
    {
      infile >> num2;
      if(num2 <= 256)
      {
        sir2[i] = num2;
      }
    }

    for(int i=0; i<len1; i++) //se adauga in vector numerele in comun
    {
      for(int j=0; j<len2; j++)
      {
        if(sir1[i] == sir2[j])
        {
          for(int x: Rezultat)
          {
            if(x == sir1[i])
            {
              goto fin;
            }
          }
          Rezultat.push_back(sir1[i]);
          lenR++;
          fin: continue;
        }
      }
    }
  }

  outfile << lenR << endl;  //scrie rezultatul in .out
  for(int x: Rezultat)
  {
    outfile << x << " ";
  }

  infile.close();
  outfile.close();

  return(0);
}
