#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;
int main()
{    ifstream fin("euclid2.in");
     ofstream fout("euclid2.out");
    int a,b,c;
   fin>>a;
   for(int i=1;i<=a;i++)
   {
    fin>>b>>c;
    while(b!=c)
    {
    if(b>c)
        b-=c;
    else
        c-=b;
    }
    fout<<b<<"\n";

   }

   fin.close();
   fout.close();
    return 0;

}
