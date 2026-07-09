#include <cstdio>
#define LE 3000
using namespace std;
int l[LE],n,m,i,a[LE],b[LE],V[LE],PMAX,good[LE],w,fr[LE];

void check()
   {
	int j,p=0,poz=1;
	
      for(j=1;j<=n;++j) if (l[j])
			V[++p]=a[j];
	   
	  for(j=1;j<=m;++j)
		  if (b[j]==V[poz]&&poz<=p)
			  ++poz;
		  
	  if (poz==p+1&&p>PMAX) 
		for(j=1,PMAX=p;j<=p;++j)
		     good[j]=V[j];
   }

void back (int k) 
   {
	 if (k>n) check();
	 else 
	  {
		l[k]=0;
		back(k+1);
		l[k]=1;
		back(k+1);
	  }
   }

int main(){
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	
	scanf("%ld%ld",&n,&m);
	
	for(i=1;i<=n;++i)
		scanf("%ld",&a[i]);
	
	for(i=1;i<=m;++i)
		scanf("%ld",&b[i]);
	
	
	for(i=1;i<=n;++i)
		fr[a[i]]=1;
	
    for(i=1;i<=m;++i)
	if (fr[b[i]])
		b[++w]=b[i];
	
	m=w;
	 back(1);
	 
	 printf("%ld\n",PMAX);
	 
	 for(i=1;i<=PMAX;++i) 
		 printf("%ld ",good[i]);
	return 0;
}
