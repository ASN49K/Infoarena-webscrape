#include <fstream>
#include <vector>

using namespace std;

ifstream cin ("cmlsc.in");
ofstream cout ("cmlsc.out");

int dx[]= {-1, 0, 1, 0, -1, -1, 1, 1};
int dy[]= {0, 1, 0, -1, -1, 1, 1, -1};

const int Nmax=1025;
int n, m;
int a[Nmax], b[Nmax], pd[Nmax][Nmax];

vector <int> v;

int main()
{
    cin >> n >> m;
    for(int i=1; i<=n; i++)
    {
        cin >> a[i];
    }
    for(int j=1; j<=m; j++)
    {
        cin >> b[j];
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(a[i]==b[j])
            {
                pd[i][j]=pd[i-1][j-1]+1;
            }
            else
            {
                pd[i][j]=max(pd[i-1][j], pd[i][j-1]);
            }
        }
    }
    int i=n, j=m;
    while (i && j)
    {
        if(a[i]==b[j])
        {
            v.push_back(a[i]);
            i--;
            j--;
        }
        else if(pd[i-1][j]>pd[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    cout << v.size() << "\n";
    for(int i=v.size()-1; i>=0; i--)
    {
        cout << v[i] << " ";
    }
    return 0;
}
