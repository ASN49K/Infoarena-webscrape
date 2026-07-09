    #include <iostream>
    #include <stdio.h>

    using namespace std;


    int cmmdc(int x, int y)
    {
        int r;
        while(y!=0)
        {
            r=x%y;
            x=y;
            y=r;
        }
        return x;
    }

    int main()
    {
        int x,y,t;
        freopen("euclid2.in","r",stdin);
        freopen("euclid2.out","w",stdout);
        scanf("%d\n",&t);
        for(int i=0;i<t;i++)
        {
            scanf("%d %d\n",&x,&y);
            printf("%d\n",cmmdc(x,y));
        }


        return 0;
    }
