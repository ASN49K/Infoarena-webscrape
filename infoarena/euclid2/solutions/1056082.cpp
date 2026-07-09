#include <fstream>
#include  <cstdio>
using namespace std;
//ifstream f ("euclid2.in");
//ofstream g ("euclid2.out");
int a,b,t,r1;

int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    //f>>t;
    scanf("%d",&t);

    for(;t;t--)
    {
        //f>>a>>b;
        scanf("%d%d",&a,&b);
        for(;b;)
        {
            r1=a%b;
            a=b;
            b=r1;
        }
        //g<<a<<endl;
        printf("%d\n",a);
    }


    return 0;
}
