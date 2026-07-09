#include <iostream>
#include <fstream>

using namespace std;
ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");
char s1[1027], s2[1027], v[1027]; int z;
int ma[1027][1027];

int main()
{
    int n1, n2;
    fin >> n1 >> n2;
    for(int i = 1; i<=n1; i++)
        fin >> s1[i];
    for(int i = 1; i<=n2; i++)
        fin >> s2[i];
    for(int i = 1; i<=n1; i++)
    {
        for(int j = 1; j<=n2; j++)
        {
            if(s1[i] == s2[j])
            {
                ma[i][j] = ma[i-1][j-1] + 1;
            }
            else
            ma[i][j] = max(ma[i-1][j], ma[i][j-1]);
        }
    }
    fout << ma[n1][n2] << '\n';
    int i = n1, j = n2;
    while(i!=0 && j != 0)
    {
        if(s1[i] == s2[j]) i--, j--, v[++z] = s1[i+1];
        else
        {
            if(ma[i-1][j] > ma[i][j-1])
            {
                i--;
            }
            else
            j--;
        }
    }
    for(int i = z; i > 0; i--) fout << v[i] << ' ';
    fin.close();
    fout.close();
    return 0;
}
