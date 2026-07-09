#include<stdio.h>
void main()
{
	FILE *f, *g;
	int i,n,m,j,a[250],b[256],ok,subs[250], aux[250],max,k=0,k1;
	f=fopen("cmlsc.in","r");
	g=fopen("cmlsc.out","w");
	fscanf(f,"%d%d",&m,&n);
	for(i=0;i<m;i++)
		fscanf(f,"%d",&a[i]);
	for(j=0;j<n;j++)
		fscanf(f,"%d",&b[j]);
	max=0;
	k1=0;
	ok=0;
	while(k1<m)
	{	
	for(i=k1;i<m;i++)
		for(j=ok;j<n;j++)
			if(a[i]==b[j])
			{
				ok=j;
				aux[k]=a[i];
				k++;
				break;
			}
			ok=0;
		if(max<k)
		{
			max=k;
			for(i=0;i<=max;i++)
				subs[i]=aux[i];
		}
		k=0;
		k1++;
}
	fprintf(g,"%d\n",max);
	for(i=0;i<max;i++)
		fprintf(g,"%d ",subs[i]);
	fclose(f);
	fclose(g);

}
