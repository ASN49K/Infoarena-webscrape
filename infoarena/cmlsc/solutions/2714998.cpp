#include <iostream>
#include <string.h>
#include <fstream>
#include <vector>
using namespace std;
ifstream f("cmlsc.in");
ofstream o("cmlsc.out");

vector<int> lcs(vector<int> a, vector<int> b, int i, int j)
{
    int au;
    if (i == 0 || j == 0)
        return {};
    if (a.at(i - 1) == b.at(j - 1))
    {
        au = a.at(i - 1);
        a.pop_back();
        b.pop_back();
        vector<int> aux1 = lcs(a, b, i - 1, j - 1);
        aux1.push_back(au);
        return aux1;
    }

    au = b.at(j - 1);
    b.pop_back();
    vector<int> aux1 = lcs(a, b, i, j - 1);
    b.push_back(au);
    au = a.at(i - 1);
    a.pop_back();
    vector<int> aux2 = lcs(a, b, i - 1, j);
    if (aux1.size() < aux2.size())
        return aux2;
    return aux1;
}

int main()
{

    int m, n, aux;
    f >> m >> n;
    vector<int> a, b;
    for (int i = 0; i < m; i++)
    {
        f >> aux;
        a.push_back(aux);
    }
    for (int i = 0; i < n; i++)
    {
        f >> aux;
        b.push_back(aux);
    }
    vector<int> result = lcs(a, b, m, n);
    cout << result.size() << "\n";
    for (auto i = result.begin(); i != result.end(); ++i)
        o << *i << " ";
}