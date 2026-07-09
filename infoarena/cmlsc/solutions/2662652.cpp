#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

std::string lcs(int a[], int n, int b[], int m)
{
    if (n < 0 || m < 0) return "";
    if (a[n] == b[m]) return lcs(a, n - 1, b, m - 1) + to_string(a[n]);
    const auto left = lcs(a, n - 1, b, m);
    const auto right = lcs(a, n, b, m - 1);
    if (left.length() >= right.length())
        return left;
    else
        return right;
}

int main()
{
    int n, m;
    int a[1030], b[1030];

    fin >> n >> m;

    for (auto i = 0; i < n; ++i) fin >> a[i];
    for (auto i = 0; i < m; ++i) fin >> b[i];

    const auto sol = lcs(a, n - 1, b, m - 1);

    fout << sol.size() << "\n";
    for_each(sol.cbegin(), sol.cend(), [](const char c) { fout << c << " "; });
    fout << "\n";
}
