        #include <cstdio>
        using namespace std;
        int euclid (int x, int y)
        {
            if (y==0) return x;
            else return euclid(y,x%y);
        }
        int main()
        {
            int t, x, y, i;
            freopen("euclid2.in","r",stdin);
            freopen("euclid2.out","w",stdout);
            scanf("%d",&t);
            for (i=1; i<=t; i++)
            {
                scanf("%d%d",&x,&y);
                printf("%d\n",euclid(y,x%y));
            }
            fclose(stdin);
            fclose(stdout);
            return 0;
        }
