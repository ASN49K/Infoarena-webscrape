#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
    ifstream in("cmlsc.in");
    ofstream out("cmlsc.out");

    int n,m;
    in >> n >> m;

    vector<vector<int> > length(n+1, vector<int>(m+1,0));
    vector<int> a;
    vector<int> b;

    for(int i=0; i < n; ++i) {
        int _a; in >> _a;
        a.push_back(_a);
    }

    for(int i=0; i < m; ++i) {
        int _b; in >> _b;
        b.push_back(_b);
    }

    for(int i=1;i<=n;++i) {
        for(int j=1;j<=m;++j) {
            if(a[i-1] == b[j-1])
                length[i][j] = 1 + length[i-1][j-1];
            else
                length[i][j] = max(length[i-1][j], length[i][j-1]);
        }
    }

    out << length[n][m] << "\n";

    vector<int> sol;
    int i = n;
    int j = m;

    while(i > 0 && j > 0)
    {
            if(a[i-1] == b[j-1])
            {
                sol.push_back(a[i-1]);
                --i;
                --j;
            }
            else
            {
                if(length[i][j] == length[i-1][j])
                    --i;
                else
                    --j;
            }
    }

    for(int i = sol.size()-1; i >= 0; --i)
    {
            out << sol[i] << " ";
    }
    out << "\n";

    return 0;
}
