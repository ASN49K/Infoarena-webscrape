#include <fstream>
#include <vector>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int n, i, m, b[1030], a[1030], best, best_pos_i, best_pos_j;
vector<char> c[1030][1030];
int main()
{
    in >> n >> m;
    for (int i= 1; i <= n; i++)
        in >> a[i];
    for (int j = 1; j <= m; j++)
        in >> b[j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            if (c[i-1][j].size() > c[i][j-1].size())
                for (auto ind : c[i-1][j])
                    c[i][j].push_back(ind);
            else
                for (auto ind : c[i][j-1])
                    c[i][j].push_back(ind);
            if (a[i] == b[j])
                c[i][j].push_back(a[i]);
            if (best < c[i][j].size())
            {
                best = c[i][j].size();
                best_pos_i = i;
                best_pos_j = j;
            }
        }
    out << best << '\n';
    for (auto ind : c[best_pos_i][best_pos_j])
    {
        out << (int)ind << ' ';
    }
    return 0;
}
