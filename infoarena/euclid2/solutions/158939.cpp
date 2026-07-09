#include <iostream.h>
#include <stdio.h>

int n, a[50], i, j;

int main ()

{
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
        cin>>n;
	for (i=1;i<=n*2;i++)
		cin>>a[i];
	for (i=1;i<=n*2;i=i+2)
		{
			if (a[i]>a[i+1])
				for (j=a[i+1];j>=1;j--)
					if ((a[i] % j == 0) && (a[i+1] % j == 0))
						{
							cout<<j;
                                                        break;
						}
			if (a[i]<a[i+1])
				for (j=a[i];j>=1;j--)
					if ((a[i+1] % j == 0) && (a[i] % j == 0))
						{
							cout<<j;
							break;
						}
        		if (a[i]==a[i+1]) cout<<a[i];
                	cout<<endl;
		}

	return 0;
}