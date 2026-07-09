#include <cstdio>
#include <algorithm>

using namespace std;

const int BLEJOI=(1<<18);
int pbb=BLEJOI;
char buf[BLEJOI];

char ju()
{
        if(pbb==BLEJOI)
        {
                pbb=0;
                fread(buf,1,BLEJOI,stdin);
        }
        return buf[pbb++];
}

int o()
{
        int jegg;
        scanf("%d",&jegg);
        return jegg;
        char jeg=ju();
        while(jeg==' ')
                jeg=ju();
        int num=0;
        while('0'<=jeg && jeg<='9')
        {
                num=10*num+jeg-'0';
                jeg=ju();
        }
        return num;
}

int main()
{
        freopen("nim.in","r",stdin);
        freopen("nim.out","w",stdout);

        int t=o();
        while(t--)
        {
                int n=o(),x,y=0;
                while(n--)
                {
                        x=o();
                        y^=x;
                }
                if(y) printf("DA\n");
                else printf("NU\n");
        }

        return 0;
}
