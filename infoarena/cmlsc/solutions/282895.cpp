#include<fstream.h>
void cmlsc()
{
 int l[1000],p[1000],i,j;
 l[n]=1;
 p[n]=-1;
 for(i=n-1;i>0;i--)
    {
     l[i]=1;
     p[i]=-1;
     for(j=i+1;j<=n;j++)
	if(v[i]<v[j]&&l[i]>l[j]+1)
	{
	 l[i]=l[j]+1;
	 p[i]=j;
	}
    }
 int max=-1,poz;
 for(i=1;i<=n;i++)
     if(l[i]>max){max=l[i];poz=i;}
 while(poz!=-1)
	{
	 cout<<v[poz]<<" ";
	 poz=p[poz];

	}

}
int main()
{


 return 0;
}