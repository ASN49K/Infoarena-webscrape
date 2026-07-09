#include<fstream>
using namespace std;
int v[100005],n,i,L[100000],maxi,mx,k,t;

int main(){
ifstream f("scmax.in");
ofstream g("scmax.out");
f>>n;
for(i=1;i<=n;i++) f>>v[i];
L[n]=1; 
for(k=n-1;k>0;k--)
   {
	   mx=0;
   for(i=k+1;i<=n;i++)
	   if(L[i]>mx)
      if(v[i]>v[k]) 
         {
			 mx=L[i];
			 
	  }			 
   L[k]=mx+1;  
   
   if(L[k]>maxi) 
      {
		  maxi=L[k];
      t=k;
   } 
   }
g<<maxi<<" ";

g<<"\n"<<v[t]<<' ';
for(i=t+1;i<=n;i++)
  if ((v[i]>=v[t]) && (L[i]==maxi-1))
     {g<<v[i]<<' ';
     maxi--;}
return 0;
}