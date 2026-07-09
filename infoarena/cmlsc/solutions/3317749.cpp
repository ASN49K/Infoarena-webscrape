#include <fstream>
#include <vector>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int n, i, m, b[1030], a[1030], best, best_pos_i, best_pos_j, fin[1030], fin_lg;
struct pseudo_pair
{
    int prev_pos_i, prev_pos_j, nr;
};
pseudo_pair c[1030][1030];
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
            if (c[i-1][j].nr > c[i][j-1].nr)
                c[i][j] = {i-1, j, c[i-1][j].nr};
            else
                c[i][j] = {i, j-1, c[i][j-1].nr};
            if (a[i] == b[j])
                c[i][j].nr++;
            if (best < c[i][j].nr)
            {
                best = c[i][j].nr;
                best_pos_i = i;
                best_pos_j = j;
            }
        }
    out << best << '\n';
    while(best_pos_i > 0 && best_pos_j > 0)
    {
        if (a[best_pos_i] == b[best_pos_j])
            fin[++fin_lg] = a[best_pos_i];
        int aux_i = c[best_pos_i][best_pos_j].prev_pos_i;
        int aux_j = c[best_pos_i][best_pos_j].prev_pos_j;
        best_pos_i = aux_i;
        best_pos_j = aux_j;
    }
    for (int k = fin_lg; k >= 1; k--)
        out << fin[k] << ' ';
    return 0;
}
