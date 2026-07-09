#include <iostream>
#include <fstream>
using namespace std;
ifstream fi("cmlsc.in");
ofstream fo("cmlsc.out");

int a , b, i,sir1[1025],sir2[1025],k,v[1025],j;

int main()
{
  fi >> a >> b;
  for ( i = 1; i <= a; i++)
    fi >> sir1[i];
  for (i = 1; i <= b; i++)
    fi >> sir2[i];
  while (j <= a){
    while(i <= b)
      if (sir1[j] == sir2[i]) {
        i++; j++; k++;
        v[k] == sir1[i - 1];
      }
      else i++;
  j++;
  }
  fo<< k<<endl;
  for (i=1;i<=k;i++)
  fo <<v[i]<<' ' << endl;
  return 0;
}
