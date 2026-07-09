#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main()
{
    int a, b,i;int T;
    fin>>T;
    for(i=1;i<=T;i++){ fin>>a;
      fin>>b;}
      for(i=1;i<=T;i++)
        {if(b<a)
   {
       while (b != 0)
    {
        int t = b;
        b = a % b;
        a = t;
    } fout<<a<<" ";} else {while (a != 0)
    {
        int t = a;
        a = b % a;
        b = t; } fout<<b<<" ";

}}}
