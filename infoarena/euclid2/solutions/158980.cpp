#include <iostream.h>
#include <stdio.h>

int n, a, b, c;

int main ()

{
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
        cin>>n;
	while (n>0)
		{
			cin>>a>>b;
			while (b)
				{
					c = a % b;  
					a = b;  
					b = c;
                                }
			cout<<a<<endl;
			n--;
                }

	return 0;
}