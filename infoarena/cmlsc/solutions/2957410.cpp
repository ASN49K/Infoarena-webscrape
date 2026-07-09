#include <fstream>
#include <iostream>
#include <bitset>
#include <vector>

std::ifstream fin("cmlsc.in");
std::ofstream fout("cmlsc.out");

int n, m, N[1024], M[1024];
bool AappearsInB(int A[], int a, int B[], int b)
{
    int k = 0;
    for (int i = 0; i < b && k < a; i++)
    {
        if (A[k] == B[i])
        {
            k++;
        }
    }
    return k == a;
}

int SS[1024];
std::vector<int> longestSS;
std::bitset<1024> p;
void back(int k = 0, int inc = 0)
{
    for (int i = inc; i < n; i++)
    {
        SS[k] = N[i];
        if (k < n - 1)
        {
            back(k + 1, i + 1);
        }
        if (AappearsInB(SS, k + 1, M, m))
        {
            if (k + 1 > longestSS.size())
            {
                std::vector<int> V(SS, SS + k + 1);
                longestSS = V;
            }
        }
    }
}

int main()
{
    fin >> n >> m;
    for (int i = 0; i < n; i++)
        fin >> N[i];
    for (int i = 0; i < m; i++)
        fin >> M[i];
    back();

    fout << longestSS.size() << '\n';
    for (auto el : longestSS)
        fout << el << ' ';
    fout << '\n';
}