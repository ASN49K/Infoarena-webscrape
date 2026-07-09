#include <bits/stdc++.h>
using namespace std;
ifstream f ("cmlsc.in") ;
ofstream g ("cmlsc.out") ;
int M , N , A[1030] , B[1030], k = 0;
int Max = -1 ;
int C[1030][1030] ;
void afisare(int i , int j)
{
    if (i == 0 || j == 0) return ;
    if (C[i-1][j] == C[i][j]) afisare(i-1,j);
    else if (C[i][j-1] == C[i][j]) afisare (i,j-1) ;
    else
    {
        afisare(i-1 , j-1) ;
        g << A[i] << ' ';
    }
}
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

        afisare(N,M) ;


        f.close();
        g.close();
        return 0;

}
