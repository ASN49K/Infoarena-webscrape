#include<fstream>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
const int DMAX = 1030;

int v[DMAX][DMAX],n,m,a[DMAX],b[DMAX],sir[DMAX];

void solve()
{

    in>>n>>m;
    int i,j;
    for(i = 1 ; i <= n ; i++)
        in>>a[i];
    for(i = 1 ; i <=m ; i++)
        in>>b[i];
    for(i = 1 ; i <= n ; i++)
        for(j = 1 ; j <= m ; j++)
            if(a[i] == b[j])
                v[i][j] = 1+v[i-1][j-1];
            else
                v[i][j] = max(v[i-1][j],v[i][j-1]);
    i = n;j = m;
    int bst = 0;
    while(i){
        if(a[i] == b[j])
        {
            sir[++bst] = a[i];
            i--;
            j--;
        }
        else if(v[i-1][j] < v[i][j-1])
            j--;
        else
            i--;
    }
    out<<bst<<"\n";
    for(i = bst ; i >= 1 ; i--)
        out<<sir[i]<<" ";
    out.close();
}

int main()
{

    solve();
    return 0;
}
