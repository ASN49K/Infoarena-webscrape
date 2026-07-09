#include <bits/stdc++.h>
#define for0(i,n) for(int i=0; i<n; i++)
#define for1(i,n) for(int i=1; i<=n; i++)
#define pb push_back
#define mp make_pair
#define all(v) v.begin(), v.end()
#define V vector<int>
#define VP vector<pair<int, int> >
#define clr(A,x) memset(A, x, sizeof(A))
#define cpy(A,B) memcpy(A, B, sizeof(B))
#define g(s) getline(cin, s) ///ai grija la fin/cin ///
#define FASTIO ios_base::sync_with_stdio(0)
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
/*template <typename T>
string to_string(const T& n){
    ostringstream os;
    os << n;
    return os.str();
}
*/

/*struct coord
{
    int x,y;

};
bool operator<(const coord &l, const coord &r)
{
    return (l.x<r.x || (l.x==r.x && l.y<r.y));
}*/

/*void invers_modular(int a, int b, int& d, int& x, int & y)
{
    if(!b)
    {
        d=a;
        x=1;
        y=0;
        return ;
    }
    int x0, y0;
    invers_modular(b, a%b, d, x0, y0);
    x=y0;
    y=x0-a/b*y0;
} // daca x<0 se aduna cu mod pana e mai mare, x fiind rezultatul*/

/*ull p(int baze, int exponent)
{
    if(exponent==0)
        return 1;

    if(exponent%2==0)
        return p(baze*baze, exponent/2);
    else return baze*p(baze, exponent-1);
}*/
ifstream fin("euclid2.in"); /// modifica cu numele corespunzator
ofstream fout("euclid2.out"); /// modifica cu numele corespunzator


int main()
{
    int n;
    fin>>n;
    int a, b;
    for1(i,n)
    {
        fin>>a>>b;
        fout<<__gcd(a,b)<<'\n';
    }



    return 0;
}







