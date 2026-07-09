#include <bits/stdc++.h>
using namespace std;
ifstream f ("cmlsc.in") ;
ofstream g ("cmlsc.out") ;
int M , N , A[1024] , B[1024] , sir[1024] , k = 0;
int Max = -1 ;
int C[1024][1024] ;
int main()
{
        f >> N >> M ;
        for (int i = 1 ; i <= N ; ++i)
            f >> A[i] ;
        for (int j = 1 ; j <= M ; ++j)
            f >> B[j] ;

        for (int i = 1 ; i <= N ; ++i)
        {
            for (int j = 1 ; j <= M ; ++j)
            {
                    if (A[i] == B[j])
                        C[i][j] = 1 + C[i-1][j-1] ;
                    else
                        C[i][j] = max(C[i][j-1] , C[i-1][j]) ;

                    if (C[i][j] > Max) Max = C[i][j];
            }
        }
        g << Max << '\n';
                int i = N ;
                int j = M ;
        while (i != 0 || j != 0)
        {
            if (A[i] == B[j])
                {sir[++k] = A[i] ;
            i -- ;
            j -- ;}
            else
            {
                if (C[i-1][j] < C[i][j-1])
                    --j;
                else --i;
            }
        }
        for (int i = 1 ; i <= k ; ++i)
            g << sir[i] << ' ';


        f.close();
        g.close();
        return 0;

}
