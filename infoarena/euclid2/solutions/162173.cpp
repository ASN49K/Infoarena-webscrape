#include<fstream.h>
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

typedef struct{int a,b;
	      }nr;
nr c[50];
int n,i;	        

int eucl(int a,int b)
{if(b==0) return a;
   return eucl(b,a%b);
 }
int main()
{
 fin>>n;
 for(i=1;i<=n;i++)
 fin>>c[i].a>>c[i].b;
 for(i=1;i<=n;i++)
 fout<<eucl(c[i].a,c[i].b)<<"\n";

fin.close();
 fout.close();
 return 0;
}
