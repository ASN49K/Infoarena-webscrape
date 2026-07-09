#include <fstream>
#include <vector>
#define nmax 1026

using namespace std;

ifstream f("cmlsc.in");
ofstream o("cmlsc.out");

int n1, n2, dp[nmax][nmax], v1[nmax], v2[nmax];
vector <int> res;

void input()
{
    f >> n1 >> n2;
    for(int i = 1; i <= n1; ++i)
        f >> v1[i];
    for(int j = 1; j <= n2; ++j)
        f >> v2[j];
}

void din()
{
    for(int i = 1; i <= n1; ++i)
        for(int j = 1; j <= n2; ++j)
            if(v1[i] == v2[j])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
}

void back_din()
{
     int i = n1, j = n2;

     while(i > 0 && j > 0)
     {
         if(v1[i] == v2[j])
         {
             res.push_back(v1[i]);
             -- i;
             -- j;
         }
         else if(dp[i-1][j] > dp[i][j-1])
         {
             --i;
         }
         else
            -- j;
     }
}

void output()
{
    o  << res.size() << '\n';

    for(vector<int>::reverse_iterator it = res.rbegin(); it != res.rend(); ++it)
        o << *it << ' ';
}

int main()
{
    input();
    din();
    back_din();
    output();
    return 0;
}
