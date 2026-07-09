
#include <fstream>
#include <stdio.h>

using namespace std;
int main()
{

    int T,a,b,r;
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    scanf("%d\n",&T);
    for(int i=1;i<=T;i++)
    {
        scanf("%d %d\n",&a,&b);
        while(b)
        {
                r=a%b;
                a=b;
                b=r;
        }

        printf("%d\n",a);
    }
    //cout << "Hello world!" << endl;
    return 0;
}
