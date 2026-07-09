#include <fstream>

#define MAXLENGTH 1024


int main()
{
    int n, m;
    int first[MAXLENGTH];
    int second[MAXLENGTH];
    int length = 0;

    std::ifstream fin("cmlsc.in");

    fin >> n >> m;

    for (int i = 0; i < n; ++i)
        fin >> first[i];

    for (int i = 0; i < m; ++i)
        fin >> second[i];

    fin.close();

    for (int i = 0; i < n; ++i) {
        for (int j = 0, found = false; j < m && !found; ++j) {
            if (second[j] == first[i]) {
                ++length;
                found = true;
            }
        }
    }
    
    std::ofstream fout("cmlsc.out");

    fout << length << '\n';

    fout.close();

    return 0;
}
