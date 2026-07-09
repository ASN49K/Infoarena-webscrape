#include<cstdio>
int n,m,i,f,j,k,max,maxl,v[1025],w[1025],v1[260],w1[260],d1[260],max1,max2,r[1025];
int main()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%d",&v[i]);
		if(v1[v[i]]==0)v1[v[i]]=i;
		if(v[i]>max)max=v[i];
	}
	for(i=1;i<=m;i++){
		scanf("%d",&w[i]);
		if(w1[w[i]]==0)w1[w[i]]=i;
		if(w[i]>max)max=w[i];
	}
	for(i=1;i<=max;i++)if(v1[i]!=0 && w1[i]!=0) d1[i]=1;
	
	for(i=2;i<=max;i++){
		max1=0;
		max2=0;
		for(j=1;j<i;j++)
			if(d1[j]==1){
			if (v1[j]<v1[i])max1++;
			if (w1[j]<w1[i])max2++;
		}
		if(max1<max2){
			if(max1>maxl){
				maxl=max1;
				k=i;
				f=1;
			}
		}
			else{
				if(max2>maxl){
					maxl=max2;
					k=i;
					f=2;
				}
			}
	}
	maxl=0;
	if(f==1){
		for(i=1;i<k;i++)
			if(v1[i]<v1[k] && d1[i]==1){
				maxl++;
				r[maxl]=v[v1[i]];
			}
			maxl++;
			r[maxl]=k;
	}
	else{
		for(i=1;i<k;i++)
			if(w1[i]<w1[k] && d1[i]==1){
				maxl++;
				r[maxl]=w[w1[i]];
			}
			maxl++;
			r[maxl]=k;
	}
	printf("%d\n",maxl);
	for(i=1;i<=maxl;i++)printf("%d ",r[i]);
	return 0;
}
	