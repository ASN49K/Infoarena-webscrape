#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
long long int t, a, b;
int cmmdc(int a, int b)
{
    if(b==0)return a;
    else return cmmdc(b,a%b);


}
int main()
{   freeopen("eucli2.in","r",stdin);
    freeopen("euclid2.out","w",stdout);
    scanf("%d",&t);
    for(int i=1; i<=t; i++)
    {

        scanf("%lld %lld",&a, &b);
        printf("%d",cmmdc(a,b));
    }
    return 0;
}
