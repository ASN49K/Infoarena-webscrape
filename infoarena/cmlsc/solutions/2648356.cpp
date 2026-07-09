#include <fstream>
#include <deque>
#include <vector>
#include <bitset>
#include <queue>
#include <unordered_set>
#include <algorithm>
#include <cmath>

#define MOD 666013

using namespace std ;

ifstream cin ("cmlsc.in") ;
ofstream cout ("cmlsc.out") ;

int x[1025], y[1025] ;

int m[1025][1025] ;

vector<int> v ;

void recur(int f, int e)
{

    if(!f || !e || !m[f][e])return ;

    if(x[f] == y[e])
        {
            v.push_back(x[f]) ;
            recur(f - 1, e - 1) ;
            return ;
        }

    if(m[f - 1][e] >= m[f][e - 1])
    {

        recur(f - 1, e) ;

        return ;
    }

    recur(f, e - 1) ;

}

int main()
{
    int n, mm ;

    cin >> n >> mm ;

    for(int f = 1 ; f <= n ; f ++)
        cin >> x[f] ;

    for(int f = 1 ; f <= mm ; f ++)
        cin >> y[f] ;

    for(int f = 1 ; f <= n ; f ++)
        for(int e = 1 ; e <= mm ; e ++)
            if(x[f] == y[e])m[f][e] = m[f - 1][e - 1] + 1 ;
                else m[f][e] = max(m[f - 1][e], m[f][e - 1]) ;

    recur(n, mm) ;

    cout << m[n][mm] << endl ;

    for(int f = v.size() - 1 ; f >= 0 ; f --)
        cout << v[f] << " " ;

    return 0 ;
}
