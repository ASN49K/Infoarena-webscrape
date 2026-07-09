#include <iostream>
#include <fstream.h>
//#include <conio.h>

#define IN "euclid2.in"
#define OUT "euclid2.out"

using namespace std;

ifstream fin(IN);
ofstream fout(OUT);

long euclid(long,long);

int main()
{
 long teste;
 long a,b;
 
 fin>>teste;
 
 while(teste)
 {
  teste--;
  fin>>a>>b;
  fout<<euclid(a,b);
  fout<<endl;
 }
 fin.close();
 fout.close();
 
 return 0;
}

long euclid(long a,long b)
{
 if(b==0)
   return a;
 else 
   return euclid(b,a%b);
}
