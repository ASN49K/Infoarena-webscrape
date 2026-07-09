#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int n,a,b;
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    fin>>n;
    for (int i=0; i<n; i++)
      {
          fin>>a>>b;
          while (b)
    {
        int c=a%b;
        a=b;
        b=c;
    }
    fout<<a<<endl;
      }
}
