#include <iostream>
//#include <fstream.h>
//#include <conio.h>

#define IN "euclid2.in"
#define OUT "euclid2.out"

using namespace std;

long euclid(long,long);

int main()
{
 freopen(IN, "r", stdin);  
 freopen(OUT, "w", stdout);    
 
 long teste;
 long a,b;
 
 scanf("%d", &teste);
 
 while(teste)
 {
  teste--;
  scanf("%d %d", &a, &b);
  printf("%d\n",euclid(a,b));
 }
 return 0;
}

long euclid(long a,long b)
{
 if(b==0)
   return a;
 else 
   return euclid(b,a%b);
}
