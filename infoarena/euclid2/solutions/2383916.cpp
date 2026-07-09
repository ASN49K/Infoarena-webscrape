#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main()
{
    int a[100000], b[100000],i;int T;
    fin>>T;
    for(i=1;i<=T;i++){ fin>>a[i];
      fin>>b[i];}
      for(i=1;i<=T;i++)
        {if(b[i]<a[i])
   {
       while (b[i] != 0)
    {
        int t = b[i];
        b[i] = a[i] % b[i];
        a[i] = t;
    } fout<<a[i]<<endl;} else {while (a[i] != 0)
    {
        int t = a[i];
        a[i] = b[i] % a[i];
        b[i] = t; } fout<<b[i]<<endl;

}}}

