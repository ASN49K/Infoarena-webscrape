int gcd(int a,int b)
{
	if(!b)
		retrun a;
	return(b,a mod b);
}

int main()
{
	int n,i;
	int a,b;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&a,&b);
		printf("%d\n",gcd(a,b));
	}
}