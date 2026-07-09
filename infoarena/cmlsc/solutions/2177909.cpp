#include <fstream>
#include <deque>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m, v1[1025], v2[1025], lcs[1025][1025];

deque < int > results;

void constructLCS() {
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            if (v2[i] == v1[j])
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
            else
                if (lcs[i - 1][j] > lcs[i][j - 1])
                    lcs[i][j] = lcs[i - 1][j];
            else
                lcs[i][j] = lcs[i][j - 1];
}

void goReverseOnLCS() {
    int i = m, j = n;
    while (lcs[i][j]) {
        if (v2[i] == v1[j]) {
            results.push_front(v2[i]);
            --i;
            --j;
        }
        else {
            if (lcs[i - 1][j] > lcs[i][j - 1])
                --i;
            else
                --j;
        }
    }
}

int main()
{
    fin >> n >> m;
    for (int i = 1; i <= n; ++i)
        fin >> v1[i];
    for (int i = 1; i <= m; ++i)
        fin >> v2[i];
    constructLCS();
    goReverseOnLCS();
    fout << lcs[m][n] << "\n";
    while (!results.empty()) {
        fout << results.front() << " ";
        results.pop_front();
    }
    return 0;
}
