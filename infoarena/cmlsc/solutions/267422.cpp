#include <fstream.h>
#include <iostream.h>
#define NMax 1025




int m,n,i,j,a[NMax],b[NMax],poz,sol[NMax],mx,mxabs,solabs[NMax],k;

void citire()
{ifstream fin("cmlsc.in");
 fin>>m>>n;
 for(i=1; i<=m; i++) fin>>a[i];
 for(i=1; i<=n; i++) fin>>b[i];
}


int main()
{
ofstream fout("cmlsc.out");
 citire();
 i=1;
 while(i<=n)
  { j=1;
    while (j<=m)
      { if(b[i]==a[j] && poz<j)
	    {	mx++;
		sol[++k]=b[i];
		poz=j;// int curent=i;
		j++; i++;

	    }

	 else { i++;}

       }
     if(mx>mxabs) { mxabs=mx;
		    for (int p=1; p<=k; p++) solabs[p]=sol[p];
		   }
  }

/* for (i=1; i<=n; i++)
  { for(j=1; j<=m; j++)
     if (b[i]==a[j] && poz<i)
	     {	mx++;
		sol[++k]=b[i];
		poz=i;
		}

    if(mx>mxabs) { mxabs=mx;
		    for (int p=1; p<=k; p++) solabs[p]=sol[p];
		  }
   }    */
 fout<<mxabs<<endl;
 for(i=1; i<=mxabs; i++) fout<<solabs[i]<<" ";
 return 0;
}