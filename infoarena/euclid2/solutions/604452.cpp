#include<iostream>
#include<string.h>
#include<fstream>
#include<stdio.h>

int cmmdc(int a,int b)
{
  if (a<b)
  {
    int aux=a;
    a=b;
    b=aux;
  }
  do
  {
    int r;
    r=a-b;
    a=b;
    b=r;
    if (a<b)
  {
    int aux=a;
    a=b;
    b=aux;
  }
  }
  while (b!=0);
  return a;
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
