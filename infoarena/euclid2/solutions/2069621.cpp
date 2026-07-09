#include <iostream>
#include <fstream>
using namespace std;
int cmmdc(int a,int b)
{
    if(b)
        return cmmdc(b,a%b);
    return a;
}
int main()
{
    //ifstream in("euclid2.in");
    //ofstream out("euclid2.out");
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);

    int n,a,b;
    scanf("%d",&n);
    while(n)
    {
        scanf("%d",&a);
        scanf("%d",&b);
        a=cmmdc(a,b);
        printf("%d\n",a);
        n--;
    }
    return 0;
}
