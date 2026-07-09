#include <fstream>
#include <deque>
#include <vector>
#include <iomanip>
#include <queue>
#include <algorithm>
#include <cmath>
#include <climits>

#define MOD 104659

using namespace std ;

ifstream cin ("cmlsc.in") ;
ofstream cout ("cmlsc.out") ;

int v[1056], p[1056], dp[1056][1056] ;

vector<int> vv ;

void recur(int n, int m)
{
    if(!n || !m)return ;

    if(v[n] == p[m])
    {
        recur(n - 1, m - 1) ;

        vv.push_back(v[n]) ;

        return ;
    }

    if(dp[n - 1][m] > dp[n][m - 1])recur(n - 1, m) ;
        else recur(n, m - 1) ;
}


int main()
{
    int n, m ;

    cin >> n >> m ;

    for(int f = 1 ; f <= n ; f ++)
        cin >> v[f] ;

    for(int e = 1 ; e <= m ; e ++)
        cin >> p[e] ;

    for(int f = 1 ; f <= n ; f ++)
        for(int e = 1 ; e <= m ; e ++)
            if(v[f] == p[e])dp[f][e] = dp[f - 1][e - 1] + 1 ;
                else dp[f][e] = max(dp[f - 1][e], dp[f][e - 1]) ;

    recur(n, m) ;

    cout << vv.size() << endl ;

    for(int f = 0 ; f < vv.size() ; f ++)
        cout << vv[f] << " " ;

    return 0 ;
}
/*
7
10 1 7 2 2 6 10 7
*/
