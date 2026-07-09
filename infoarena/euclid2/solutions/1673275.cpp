#include <iostream>
#include <fstream>
using namespace std;
int i,n,a,b,r;
int main()
{
    ifstream fin("euclid2.in");
    ofstream fout ("euclid2.out");
    fin>>n;
    for (i=1;i<=n;i++)
     {fin>>a>>b;
      r=a%b;
      while (r!=0)
      { a=b;
        b=r;
        r=a%b;
      }
      fout<<b<<endl;}


    return 0;
}
