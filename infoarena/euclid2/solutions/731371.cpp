#include <cstdio>
#include <math.h>
using namespace std;
int cmmdc(int a,int b){
	int r;
	while(b){
		r=a%b;
		a=b;
		b=r;
	}
	return a;
}
int main()
{
    freopen("file.in","r",stdin);
    freopen("file.out","w",stdout);
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    int a,b,t;
    scanf("%d",&t);
    for(int i = 1; i<=t; i++)
    {
        scanf("%d %d",&a,&b);
        printf("%d\n",cmmdc(a,b));
    }
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    fclose(stdin);
    fclose(stdout);
    return 0;
}
