#include <fstream>
#define N 1<<10

using namespace std;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

int n, m, r;
int a[1030], b[1030], d[1030][1030], s[1030];

void citire()
{
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++)
        cin >> a[i];
    for(int i = 1 ; i <= m ; i++)
        cin >> b[i];
}

void rez()
{
    for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= m ; j++)
            d[i][j] =  (a[i] == b[j]) ? d[i-1][j-1] + 1 : max(d[i-1][j], d[i][j-1])  ;

    for(int i = n , j = m ; i; )
        if(a[i] == b[j]) s[++r] = a[i], i--, j--;
        else (d[i-1][j] > d[i][j-1]) ? i-- : j-- ;
}

void print()
{
    cout << r << '\n';
    for(int i = r ; i ; i--)
        cout << s[i] << ' ';
}

int main()
{
   citire();
   rez();
   print();
   return 0;
}
