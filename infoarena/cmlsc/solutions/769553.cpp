#include<fstream>
using namespace std;

int a[1024], b[1024];
int m[1024][1024];
int s[1024];
int p,n,i,j,psi; 

int main()
{ifstream f("cmlsc.in");
 f>>p>>n;
 for(i=1; i<=p; i++)
   f>>a[i];
 for(j=1; j<=n; j++)
   f>>b[j];
 f.close();  
 for(i=1; i<=p; i++)
   for(j=1; j<=n; j++)
     if(a[i]==b[j])
       m[i][j]=m[i-1][j-1]+1;
     else
       m[i][j]=max(m[i-1][j],m[i][j-1]);  
       
 ofstream g("cmlsc.out");
 g<<m[p][n]<<endl;         
 
 psi=m[p][n]+1; 
 i=p;  j=n;
 while(psi>1)
 {if(a[i]==b[j])
        {psi--; s[psi]=a[i];  i--;  j--;  }
  else
     {if(m[i-1][j]<m[i][j-1])
        j--;
     else 
        i--;}
  }              

  for(i=1; i<=m[p][n]; i++)
    g<<s[i]<<" ";

 g.close();
 return 0;}
