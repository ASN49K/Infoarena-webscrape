#include<fstream.h>
long a,b,t,i;
int main()
{long x,y,r;
 ifstream fin("euclid2.in");
  fin>>t;
 ofstream fout("euclid2.out"); 
for(i=1;i<=t;i++)
{fin>>a>>b;	
 while(b!=0)
 {r=a%b;
  a=b;
  b=r;
 }
 fout<<a<<'\n';
}
fin.close();
fout.close();
return 0;
}