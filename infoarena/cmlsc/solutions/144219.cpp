#include<fstream>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int m,n,A[1024],B[1024],s[1024],maxim=-2000,v[1024];
void citire();
void back(int);
void afisare();
void subsir();
int gasit(int,int[],int);
int main()
{
citire();
m<n?back(m):back(n);
out<<maxim<<endl;
for (int i=0;i<maxim;i++)
 out<<v[i]<<" ";
return 0;
}
void citire()
{in>>m>>n;
 int i;
  for (i=0;i<m;i++)
	  in>>A[i];
  for (i=0;i<n;i++)
	  in>>B[i];
}
void back(int min)
{int k=0;
 s[k]=-1;
  while(k>=0)
	  if (s[k]<1)
	  {s[k]++;
        if (k==min-1) subsir();
		else s[++k]=-1;
      }
	  else k--;
}
void afisare()
{int i;
for (i=0;i<(m<n?m:n);i++)
 out<<s[i]<<" ";
out<<endl;
}
int gasit (int x,int vct[],int k)
{int i;
  for (i=0;i<k;i++)
	  if (vct[i]==x) return 1;
 return 0;
}
void subsir()
{int i,g=1;
  if (m<n)
   for (i=0;i<m;i++)
    if (s[i]&&gasit(A[i],B,n)==0) g=0;
    else;
  else 
   for (i=0;i<n;i++)
    if (s[i]&&gasit(B[i],A,m)==0) g=0;
    else;
 int j=0;
 if (g) {for (i=0;i<(m<n?m:n);i++)
		  if (s[i]) v[j++]=(m<n?A[i]:B[i]);
        maxim=j;
       } 
}