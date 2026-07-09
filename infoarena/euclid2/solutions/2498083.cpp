#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int T;
int a, b;

int CMMDC(int A, int B)
{
    if(!B)
        return A;
    return CMMDC(B, A%B);
}

int main()
{
    fin>> T;
    for(int i=0; i<T; i++)
    {
      fin >>a>>b;
      fout<<CMMDC(a, b)<<endl;
    }

   fin.close();
   fout.close();
    return 0;
}
