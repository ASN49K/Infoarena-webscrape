#include<iostream>
#include<string.h>
#include<fstream>
#include<stdio.h>

int cmmdc(int a,int b)
{
  if (b==0) return a;
  return cmmdc(b,a%b);
}

int main(int nr,char* arg[])
{
  int a,b,t;
  std::ifstream in("euclid2.in");
  std::ofstream out("euclid2.out");
  in>>t;
  for(int i=0;i<t;i++)
  {
    in>>a;
    in>>b;
    out<<cmmdc(a,b)<<"\n";
  }
  in.close();
  out.close();
}
