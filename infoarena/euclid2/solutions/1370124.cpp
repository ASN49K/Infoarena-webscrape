#include <iostream>
#include <fstream>
#include<cmath>
using namespace std;

int main()
{
    long long n,i,x,y,r,a,b;
    ifstream fin("euclid2.in");
    fin>>n;
    ofstream fout("euclid2.out");
    for(i=1;i<=n;i++)
 {
     fin>>x>>y;
     while(y!=0)
     {
         r=x%y;
         x = y;;
         y = r;
     }
     fout<<x<<"\n";
 }

    return 0;
}
