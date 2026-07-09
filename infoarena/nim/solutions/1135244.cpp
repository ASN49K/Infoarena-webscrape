#include <fstream>

using namespace std;

FILE* f=freopen("nim.in","r",stdin);
FILE* o=freopen("nim.out","w",stdout);

int n,t;

int main()
{
    int s;
    scanf("%d",&t);
    for(int i=0;i<t;++i)
    {
        scanf("%d",&n);
        s=0;
        for(int j=0;j<n;++j)
        {
            int x;
            scanf("%d",&x);
            s^=x;
        }
        if(s==0)
            printf("NU\n");
        else
            printf("DA\n");
    }

    return 0;
}
