#include <iostream.h>
#include <stdio.h>

using namespace std;
int i,t,r,a,b;

int main()
{
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	scanf("%d",&t);
	i=1;
	while(i<=t)
	{
		scanf("%d%d",&a,&b);
		while(b!=0)
	    {
			r=a%b;
		    a=b;
		    b=r;
		}
        if (a==1)
	    {
			cout<<"1";
	    }else
	    {
		cout<<a<<endl;
        }
		i++;
	}
}


