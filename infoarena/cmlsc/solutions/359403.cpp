#include<stdio.h>
int A,B,C,D,a[1025],b[1025],c[1025],d[1025][1025];
void read(), solve();
int main()
{
	read();
	solve();
	return 0;
}
void read()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%d%d",&A,&B);
	for(C=1;C<=A;C++)scanf("%d",&a[C]);
	for(C=1;C<=B;C++)scanf("%d",&b[C]);
}
void solve()
{
	for(C=1;C<=A;C++)
		for(D=1;D<=B;D++)
		{
			if(a[C]==b[D])d[C][D]=d[C-1][D-1]+1; 
			else d[C][D]=d[C][D-1]>d[C-1][D]?d[C][D-1]:d[C-1][D];
	}
	printf("%d\n",d[A][B]);
	for(C=0;d[A][B];)
	{
		if(a[A]==b[B]){c[++C]=a[A];A--;B--;}
		else if(d[A][B]==d[A-1][B])A--;
		else B--;
	}
	for(;C;C--)printf("%d ",c[C]);
}

