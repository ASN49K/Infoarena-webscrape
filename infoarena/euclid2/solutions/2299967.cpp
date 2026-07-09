#include <bits/stdc++.h>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int cmmdc(int,int);
int n,a,b;

int main()
{
 fin>>n;
 while (n!=0)
 {
  n--;
  fin>>a>>b;
  fout<<cmmdc(a,b)<<"\n";
 }
 return 0;
}

int cmmdc(int x,int y)
{
 if (y==0)
  return x;
 else
  return cmmdc(y,x%y);
}
