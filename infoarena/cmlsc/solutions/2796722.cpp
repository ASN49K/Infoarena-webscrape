#include <fstream>
#include <cstring>
#include <vector>

using namespace std;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

int l, c, v[1099], u[1099], m[1099][1099] ;

/// in indicele f, e se afla lungimea celui mai lung sir comun pana la acei indici

vector<int> rez ;

void recur(int f, int e)
{
    if(!f || !e)return ;

    if(v[f] == u[e])rez.push_back(v[f]), recur(f - 1, e - 1) ;
        else
        {
            if(m[f - 1][e] >= m[f][e - 1])recur(f - 1, e) ;
                else recur(f, e - 1) ;
        }
}

int main()
{
    cin >> l >> c ;

    for(int f = 1 ; f <= l ; f ++)
        cin >> v[f] ;

    for(int f = 1 ; f <= c ; f ++)
        cin >> u[f] ;

    for(int f = 1 ; f <= l ; f ++)
        for(int e = 1 ; e <= c ; e ++)
            if(v[f] == u[e])m[f][e] = m[f - 1][e - 1] + 1 ;
                else m[f][e] = max(m[f - 1][e], m[f][e - 1]) ;

    recur(l, c) ;

    cout << rez.size() << endl ;

    for(int f = rez.size() - 1 ; f >= 0 ; f --)
        cout << rez[f] << " " ;

    return 0;
}
