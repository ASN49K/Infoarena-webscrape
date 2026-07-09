#include <fstream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    ifstream in("cmlsc.in");
    vector <int> s1, s2;
    int m, n, temp;
    in >> m >> n;
    for (int i = 0; i < m; ++i)
    {
        in >> temp;
        s1.push_back(temp);
    }
    for (int i = 0; i < n; ++i)
    {
        in >> temp;
        s2.push_back(temp);
    }

    in.close();
    int M[500][500];

    for (int i = 0; i <= m; ++i)
        M[0][i] = 0;
    for (int i = 0; i <= n; ++i)
        M[i][0] = 0;

    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
        {
            if (s1[i-1] == s2[j-1])
                M[i][j] = M[i-1][j-1] + 1;
            else
                M[i][j] = max(M[i-1][j], M[i][j-1]);
        }

    int i = m, j = n, max = 0;
    stack <int> sol;

    while(i>1&&max<M[m][n])
    {
        if(s1[i-1] == s2[j-1])
        {
            sol.push(s1[i-1]);
            --i;
            --j;
            ++max;
        }
        else
            if (M[i-1][j] > M[i][j-1])
                --i;
            else
                --j;
    }

    ofstream out("cmlsc.out");
    out << M[m][n] << endl;
    while(!sol.empty())
    {
        out << sol.top() << " ";
        sol.pop();
    }
    out.close();
    return 0;
}
