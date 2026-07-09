#include<iostream>
#include<conio.h>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int cmmdc (int a,int b)
{
 while (a!=b)
 {

if (a>b)
   a=a-b;
  else
   b=b-a;
}
 return a;
}
int main()
{
 int a,b,t;
 fin>>t;
 while(t--)
 {
    fin>>a;
    fin>>b;
    fout<<cmmdc(a,b)<<"\n";
 }
 return 0;
}
