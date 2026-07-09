#include <fstream>
#include <iostream>
#define NMax 11

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int m,n,i,j,a[NMax],b[NMax],sol[NMax],mx,mxabs,solabs[NMax],k;

void citire()
{
 fin>>m>>n;
 for(i=1; i<=m; i++) fin>>a[i];
 for(i=1; i<=n; i++) fin>>b[i];
}


int main()
{

 citire();
 for (i=1; i<=n; i++)
  { for(j=i+1; j<=m; j++)
     if (b[i]==a[j])
	     {	mx++;
		sol[++k]=b[i];
		}

    if(mx>mxabs) { mxabs=mx;
		    for (int p=1; p<=k; p++) solabs[p]=sol[p];
		  }
   }
 fout<<mxabs<<endl;
 for(i=1; i<=mxabs; i++) fout<<solabs[i]<<" ";
 return 0;
}