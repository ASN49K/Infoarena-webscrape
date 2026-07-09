#include <fstream>
#include <vector>
using namespace std;
char const in [] = "cmlsc.in";
char const out [] = "cmlsc.out";
ifstream f (in);
ofstream g (out);
int const NM = 1024;
int dp [NM][NM] , v1 [NM] , v2 [NM];
vector <int> v;
int main()
{
    int n , m , i , j;
    f >> n >> m;
    for(i = 1 ; i <= n ; ++ i)
        f >> v1 [i];
    for(j = 1 ; j <= m ; ++ j)
        f >> v2 [j];
    for(i = 1 ; i <= n ; ++ i)
        for(j = 1 ; j <= m ; ++ j)
            if(v1 [i] == v2 [j])
                dp [i][j] = 1 + dp [i - 1][j - 1];
            else
                dp [i][j] = max (dp [i - 1][j] , dp [i][j - 1]);
    for(i = n , j = m ; i >= 1 && j >= 1 ; i , j )
        if(v1 [i] == v2 [j])
            v . push_back (v1 [i]) , -- i , -- j;
        else
            if (dp [i - 1][j] < dp [i][j - 1])
                -- j;
            else
                -- i;
    int sz = v . size ();
    g << sz << '\n';
    for(i = sz - 1 ; i > -1 ; -- i)
        g << v [i] << ' ' ;
    return 0;
}
