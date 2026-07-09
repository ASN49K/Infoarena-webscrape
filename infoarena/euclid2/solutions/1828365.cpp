#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int t;
int euclid(int a, int b)
{
    int c;
    if(a==0 || b==0)
    return a+b;
    else
    {
        while(b)
          {c=a%b;
          a=b;
          b=c;}
          return a;
}}
int main()
{
    int a,b,i,sol;
    fin>>t;
    for(i=1;i<=t;i++)
        {
            fin>>a>>b;
            sol=euclid(a,b);
            fout<<sol<<"\n";
        }
    return 0;
}
