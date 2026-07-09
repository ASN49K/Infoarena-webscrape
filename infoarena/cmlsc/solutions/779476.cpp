#include<fstream>
using namespace std; 
ifstream in("cmlsc.in");
ofstream out("cmlsc.out"); 
int a[1025],b[1025],c[1025][1025],n,m,i,j;
int main ()
{   int k=0;
   in>>n>>m; 
 for(i=1;i<=n;i++)
	  in>>a[i]; 
 for(j=1;j<=m;j++) 
	 in>>b[j];  
  for(i=1;i<=n;i++)
	  for(j=1;j<=m;j++)
		  if(a[i]==b[j]) 
		     c[i][j]=c[i-1][j-1]+1; 
          else
       		c[i][j]=max(c[i-1][j],c[i][j-1]); 

		  out<<c[n][m]<<'\n';  
		  if(c[1][1]!=0) 
			out<<c[1][1]<<" ";
		for(i=1;i<=n;i++)
            for(j=1;j<=m;j++) 
               if(c[i][j]>c[i][j-1]&&c[i][j]>k) 
                 {   k=c[i][j];
					 out<<b[j]<<" ";
				 }					 
                    				   
		  
}		