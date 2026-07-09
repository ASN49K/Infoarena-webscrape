#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main()
{
    int a[100], b[100],n,i;int t;
    fin>>n;
    for(i=1;i<=n;i++){ fin>>a[i];
      fin>>b[i];}
      for(i=1;i<=n;i++)
        {
    while (b[i] != 0)
    {
        t = b[i];
        b[i] = a[i] % b[i];
        a[i] = t;
    }
    fout<<a[i]<<" ";
}
}
