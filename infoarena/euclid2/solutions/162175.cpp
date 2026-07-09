#include<fstream.h>
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

//typedef struct{int a,b;
//	      }nr;
//nr c[50];
int n,i,a,b;	        

int eucl(int a,int b)
{if(b==0) return a;
   return eucl(b,a%b);
 }
int main()
{
 fin>>n;
 for(i=1;i<=n;i++)
 {  fin>>a>>b;
 fout<<eucl(a,b)<<"\n";
 }

fin.close();
 fout.close();
 return 0;
}
