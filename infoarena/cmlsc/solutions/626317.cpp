#include<cstdio>
#include<iostream>
using namespace std;
int fa[1025][3],fb[1025][3],vec[1025];
void citire(int v[],int n,int &min,int &max,int f[][3])
{
for(int i=1;i<=n;i++)
	{
	cin>>v[i];
	min=(v[i]<min)?v[i]:min;
	max=(v[i]>max)?v[i]:max;
	f[v[i]][1]++;
	f[v[i]][2]=i;
	}
}
int main ()
{
freopen("cmlsc.in","r",stdin);
freopen("cmlsc.out","w",stdout);
	int n,m,i,j,k=0,minA=257,minB=257,maxA=-1,maxB=-1,l;
cin>>n>>m;
if(m>n){l=m;m=n;n=l;}
	int a[n+1],b[m+1];
citire(a,n,minA,maxA,fa);
citire(b,m,minB,maxB,fb);
i=(minA<minB)?minA:minB;
j=(maxA>maxB)?maxA:maxB;
for(;i<=j;i++)
	if(fa[i][1]!=0 and fb[i][1]!=0)k++;
if(k==m){
		for(i=2,l=1;i<=m and l==1;i++){
			if(fa[b[i]][2]<fa[b[i-1]][2])l=0;
			}
		if(l){cout<<k<<"\n";for(i=1;i<=m;i++)cout<<b[i]<<" ";cout<<"\n";return 0;}
		}
if(k==0){cout<<"0\n";return 0;}
if(k==1){for(;j>=1;j--)if(fa[j][1]!=0 and fb[j][1]!=0){cout<<"1\n"<<j<<"\n";return 0;}}

for(;k>=2;k--)
{
for(i=1;i<=m;i++)
	{
	
	if(fa[b[i]][1])
		{
		l=1; vec[l]=fa[b[i]][2];
		for(j=i+1;j<=m;j++)
			if(fa[b[j]][1])
				if(fa[b[j]][2]>=vec[l])
				{
					l++;
				vec[l]=fa[b[j]][2];
				if(l==k){cout<<l<<"\n";for(i=1;i<=l;i++)cout<<a[vec[i]]<<" ";return 0;}
				}
		}
	}

}
return 0;
}