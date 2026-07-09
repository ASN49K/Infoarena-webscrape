#include <fstream>
#include <vector>

using namespace std;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

int n, m, r;
vector<int> a;
vector<int> b;
vector<int> s;
vector < vector <int> > d(1030);

// a[1030], b[1030], d[1030][1030], s[1030];

void citire()
{


    int x;
    cin >> n >> m;
    a.push_back(0);
    b.push_back(0);

    for(int i = 1 ; i <= n ; i++)
    {
        cin >> x;
        a.push_back(x);
    }

    for(int i = 1 ; i <= m ; i++)
    {
        cin >> x;
        b.push_back(x);
    }

    for ( int i = 0 ; i <= n ; i++ )
        d[i].resize(m+1);
}

void rez()
{
    for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= m ; j++)
            d[i][j] =  (a[i] == b[j]) ? d[i-1][j-1] + 1 : max(d[i-1][j], d[i][j-1])  ;

    for(int i = n, j = m ; i ; )
        if(a[i] == b[j])
        {
            s.push_back(a[i]);
            i--, j--;

        }
        else (d[i-1][j] > d[i][j-1]) ? i-- : j-- ;
}

void print()
{
    cout << s.size() << '\n';
    for(int i = s.size() - 1 ; i >= 0 ; i--)
        cout << s[i] << ' ';
}

int main()
{
    citire();
    rez();
    print();
    return 0;
}
