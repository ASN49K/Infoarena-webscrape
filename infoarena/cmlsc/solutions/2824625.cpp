#include <fstream>
#include <vector>

int main() {
    std::ifstream fin("cmisc.in");
    std::ofstream fout("cmisc.out");

    int sa, sb;
    fin >> sa >> sb;

    std::vector<int> a(sa), b(sb);
    for (int i = 0; i < sa; i++)
        fin >> a[i];
    for (int i = 0; i < sb; i++)
        fin >> b[i];

    std::vector<std::vector<int>> c(sa, std::vector<int>(sb));
    for (int i = 0; i < sa; i++)
        c[i][0] = a[i] == b[0] ? 1 : 0;
    for (int i = 0; i < sb; i++)
        c[0][i] = a[0] == b[i] ? 1 : 0;
    for (int i = 1; i < sa; i++)
        for (int j = 1; j < sb; j++)
            c[i][j] = a[i] == b[j] ? c[i - 1][j - 1] + 1 
                                   : std::max(c[i - 1][j], c[i][j - 1]);

    auto mlen = c[sa-1][sb-1];
    // std::vector<int> rec(mlen);
    // int x = sa-1, y = sb-1;
    // while (mlen) {
    //     if (a[x] == b[y]) {
    //         rec[--mlen] = a[x];
    //         x--;
    //         y--;
    //     } else if (x > 0 && c[x-1][y] == c[x][y]) {
    //         x--;
    //     } else {
    //         y--;
    //     }
    // }

    fout << c[sa-1][sb-1] << std::endl;
    // for (const auto& r : rec)
        // fout << r << " ";

    return 0;
}
