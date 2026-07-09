/*
100p
*/
#include<fstream.h>

int a,b;

void citire()
{
  ifstream in("euclid2.in");
  in>>a;
  in>>b;
  in.close();
}

int main()
{ int r;
  citire();
  while (b!=0)
   { r=a%b;
     a=b;
     b=r;
   }
  ofstream out("euclid2.out");
  if (a!=1)  out<<a;
    else out<<0;
  out.close();
  return 0;
}