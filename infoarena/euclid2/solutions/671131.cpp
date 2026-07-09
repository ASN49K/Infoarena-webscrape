#include <fstream>
using namespace std;

int main()
{   int t,a,i,b,r;
    ifstream fin("euclid2.in");
      fin>>t;
    ofstream fout("euclid2.out");
    for(i=1;i<=t;i++)
    {fin>>a>>b;
     while (b!=0)
        {r=a%b;
         a=b;
         b=r;}
     fout<<a<<endl;}
    return 0;}
