#include <fstream>
#include <vector>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int d[1050][1050], v1[1050], v2[1050];

vector<int>rez;

int main()
{
    int n, m;
    in >> n >> m;
    for(int i = 1; i <= n; i++)in >> v1[i];
    for(int i = 1; i <= m; i++)in >> v2[i];
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(v1[i] == v2[j])d[i][j] = d[i-1][j-1]+1;
            else if(v1[i] != v2[j])d[i][j] = max(d[i-1][j], d[i][j-1]);
        }
    }
    int i=n;
    int j=m;
    while(i >= 1 && j >= 1)
    {
        if(v1[i] == v2[j])
        {
            rez.push_back(v1[i]);
            i--;
            j--;
        }
        else if(d[i-1][j] > d[i][j-1])i--;
        else j--;
    }
    while(!rez.empty())
    {
        out << rez.back() << ' ';
        rez.pop_back();
    }
}
