#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int t,a,i,b,r,d=1,v[100000];
    ifstream fin("euclid2.in");
      fin>>t;
    for(i=1;i<=t;i++)
    {
        fin>>a;
        fin>>b;
        r=a%b;
        while (a%b!=0)
        {
            a=b;
            b=r;
            r=a%b;
        }
          v[d]=b;
          d=d+1;
    }
    ofstream fout("euclid2.out");
    for(i=1;i<d;i++)
       fout<<v[i]<<endl;
    return 0;
}
