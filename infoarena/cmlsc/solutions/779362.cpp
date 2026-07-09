#include<fstream>
using namespace std; 
ifstream in("cmlsc.in");
ofstream out("cmlsc.out"); 
int main ()
{ int a[1025],b[1025],c[1025],n,m,i,j; 
   in>>n>>m; 
 for(i=1;i<=n;i++)
	  in>>a[i]; 
 for(j=1;j<=m;j++) 
	 in>>b[j];  
  for(i=1;i<=n;i++)
	  for(j=1;j<=m;j++)
		  if(a[i]==b[j]) 
		     c[i]=c[i-1]+1; 
          else
       		c[i]=max(c[i],c[i-1]); 

		  out<<c[n]<<'\n';
	if(c[1]!=0)
  out<<a[1]<<" "; 
for(i=2;i<=n;i++)
    if(c[i]!=c[i-1])
      out<<a[i]<<" ";		
}		