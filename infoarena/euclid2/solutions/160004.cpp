#include <fstream.h>
long int T,a,b,i,r,aux;
int main () 
{
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
fin>>T;
if ((T>=1) && (T<=100000))
  {for(i=0;i<T;i++)
     {fin>>a>>b;
     if ((a>=2) && (a<=2*1000000000))
		if ((b>=2) && (b<=2*1000000000))
		  if (a>b) {aux=a; a=b; b=aux;}
            while (b!=0) 
             {r=a%b;
              a=b;
			  b=r;}
     fout<<a<<endl;}}
     fin.close();  
     fout.close();  
     return 0; }