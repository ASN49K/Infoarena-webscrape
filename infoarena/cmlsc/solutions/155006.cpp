#include<fstream.h>
int m,n,v[1024],t[1024],st[1024],sol[1024],max;
ofstream g("cmlsc.out");

int bun(int k)
{int aux=0,ok;


 for(int i=0;i<=k;i++)
 {ok=0;
	for(int j=aux;j<m;j++)
		if(st[i]==t[j])
			{aux=j+1;
			 j=m;
			 ok=1;
			}
  if(ok==0)
	return 0;
  }



 return 1;


}

int solutie(int k)
{  if(k+1>max)
   {  max=k+1;
	  sol[k]=st[k];
   }
return 1;
}


void afisare()
{g<<max<<'\n';
 for(int i=0;i<max;i++)
	 g<<sol[i]<<" ";
}









void back(int k,int ok)
{
  for(int i=ok;i<n;i++)
  {	st[k]=v[i];
	if(bun(k))
	{	solutie(k);
		back(k+1,i);}
  }
}




int main()
{ifstream f("cmlsc.in");
 f>>n>>m;
 int i;
 for(i=0;i<n;i++)
	f>>v[i];
 for(i=0;i<m;i++)
	f>>t[i];
 f.close();

 back(0,0);

 afisare();

 return 0;
}