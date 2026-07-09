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

char m[1025][1025] ;

vector<char> v ;

int main()
{
    int n, mm ;

    cin >> n >> mm ;

    for(int f = 1 ; f <= n ; f ++)
        cin >> m[0][f] ;

    for(int f = 1 ; f <= mm ; f ++)
        cin >> m[f][0] ;

    for(int f = 1 ; f <= n ; f ++)
        for(int e = 1 ; e <= mm ; e ++)
    {

        if(m[0][f] == m[e][0])m[f][e] = m[f - 1][e - 1] + 1 ;
            else m[f][e] = max(m[f - 1][e], m[f][e - 1]) ;

    }

    for(int f = n ; f >= 1 ; f --)
        for(int e = mm ; e >= 1 ; e --)
    {

        if(m[0][f] == m[e][0])v.push_back(m[0][f]), f -- ;

    }

    cout << v.size() << endl ;

    for(int f = v.size() - 1 ; f >= 0 ; f --)
        cout << v[f] << " " ;

    return 0 ;
}
