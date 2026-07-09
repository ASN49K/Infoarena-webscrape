#include <fstream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <climits>

#define MOD 4001

using namespace std;

ifstream cin("cmlsc.in") ;
ofstream cout("cmlsc.out") ;

int m[1025][1025], v[1025], vv[1025] ;

vector<int> rez ;

void recur(int f, int e)
{

    if(!f || !e)return ;

    if(v[f] == vv[e])
    {

        recur(f - 1, e - 1) ;

        rez.push_back(v[f]) ;

        return ;

    }

    if(m[f - 1][e] < m[f][e - 1])recur(f, e - 1) ;
        else recur(f - 1, e) ;

    return ;
}

int main()
{

    int n, p ;

    cin >> n >> p ;

    for(int f = 1 ; f <= n ; f ++)
        cin >> v[f] ;

    for(int e = 1 ; e <= p ; e ++)
        cin >> vv[e] ;

    for(int f = 1 ; f <= n ; f ++)
        for(int e = 1 ; e <= p ; e ++)
            if(v[f] == vv[e])m[f][e] = m[f - 1][e - 1] + 1 ;
                else m[f][e] = max(m[f - 1][e], m[f][e - 1]) ;

    recur(n, p) ;

    cout << m[n][p] << endl ;

    for(int f = 0 ; f < rez.size() ; f ++)
        cout << rez[f] << " " ;

    return 0;

}
