#include <iostream>
#include <fstream>
using namespace std;

int t, a, b;

int cmmdc(int a, int b)
{
    if(b==0)
        return a;
    return cmmdc(b,a%b);

}

int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);

    scanf("%d",&t);


    for(int i=1; i<=t; i++)
    {

        scanf("%d %d \n",&a, &b);
        printf("%d \n",cmmdc(a,b));
    }
    return 0;

}
