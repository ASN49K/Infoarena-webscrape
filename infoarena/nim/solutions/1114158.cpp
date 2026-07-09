    #include<cstdio>
    using namespace std;
    int T, N , x, y;

    int main()
    {
        freopen("nim.in" , "r" , stdin );
        freopen("nim.out" , "w" , stdout );
        scanf("%d" , &T );
        for(int i = 1; i <= T ; ++ i)
        {
            scanf("%d" , &N );
            int x = 0;
            for(int j = 1 ; j <= N ; ++j)
            {
                scanf("%d" , &y);
                x = x^y;
            }
            if(x)printf("DA\n");
            else printf("NU\n");
        }
        return 0;
    }
