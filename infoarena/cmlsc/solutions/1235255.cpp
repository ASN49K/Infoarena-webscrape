    #include<cstdio>
    using namespace std;
    #define MAX 1025
    int N , M , A[MAX][MAX] , v1[MAX] , v2[MAX] , rez[MAX];

    int max(int a , int b)
    {
        if(a>b)return a;
        return b;
    }

    int main()
    {
        freopen("cmlsc.in" ,"r" , stdin );
        freopen("cmlsc.out" , "w" , stdout );

        scanf("%d%d" , &N , &M );
        for(int i = 1 ; i<= N ; ++i ) scanf("%d" , &v1[i] );
        for(int i = 1 ; i <= M ; ++i ) scanf("%d" , &v2[i] );

        for(int i = 1 ; i <= N ; ++i )
            for(int j = 1 ; j <= M ; ++j )
                if(v1[i] == v2[j])
                    A[i][j] = A[i-1][j-1] + 1;
                else
                    A[i][j] = max(A[i-1][j],A[i][j-1]);

        int x = N , y = M , i = A[N][M] ;
        while(i)
        {
            if(v1[x] == v2[y])
            {
                rez[i--] = v1[x];
                x--;y--;
            }
            else
                if(A[x-1][y] > A[x][y-1])
                    x--;
                else y--;
        }

        printf("%d\n" , A[N][M]);
        for(int i = 1 ; i <= A[N][M] ; ++i )
            printf("%d " , rez[i]);
        return 0;
    }
