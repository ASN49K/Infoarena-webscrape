#include <bits/stdc++.h>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int rez[1200][1200];
int main()
{
    //ios::sync_with_stdio(0);
    //cin.tie(NULL);

    int len1, len2;
    fin >> len1 >> len2;
    vector<int> sir1(len1 + 1), sir2(len2 + 1);
    for (int i = 1; i <= len1; i++)
        fin >> sir1[i];
    for (int i = 1; i <= len2; i++)
        fin >> sir2[i];



    vector<int> sol;
    unordered_map<int, bool> frecv;
    for (int i = 1; i <= len1; i++)
        for (int j = 1; j <= len2; j++)
            if (sir1[i] == sir2[j])
            {
                rez[i][j] = rez[i-1][j-1] + 1;
                if (frecv[sir1[i]] == 0)
                    sol.push_back(sir1[i]), frecv[sir1[i]] = 1;
                if (frecv[sir2[j]] == 0)
                    sol.push_back(sir2[j]), frecv[sir2[j]] = 1;
            }
            else
                rez[i][j] = max(rez[i-1][j], rez[i][j-1]);

    fout << rez[len1][len2] << "\n";
    for (int x:sol)
        fout << x << " ";


    return 0;
}
