#include <fstream>
#include <stack>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n, m, v[1030],w[1030], a[1030][1030],nr,x,y;
stack<int> s;
int main()
{
     fin >> n >> m;
     for(int i = 1; i <= n; i++)
        fin >> v[i];
     for(int  i = 1; i <= m ; i++)
        fin >> w[i];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        {
             if(v[i] == w[j])
                a[i][j] = a[i-1][j-1] + 1;
            else
                a[i][j] = max(a[i-1][j], a[i][j-1]);
        }
    fout << a[n][m] <<"\n";
    nr=a[n][m];
    x= n;
    y= m;
    while(nr)
    {
        if(v[x] == w[y])
        {
            s.push(v[x]);
            x--; y--; nr--;
        }
        else
        {
            if(a[x-1][y]<a[x][y-1])
                y--;
            else
            {
                if(a[x-1][y] > a[x][y-1])
                    x--;
                else
                {
                     if(x>0)
                        x--;
                    else
                        y--;
                }
            }
        }
    }
    while(!s.empty())
        fout<<s.top()<<" ",s.pop();
    return 0;
}
