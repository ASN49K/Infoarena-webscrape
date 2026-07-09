#include <fstream>
#include <algorithm>
#include <vector>
#include <array>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
static bool cmp(int a, int b)
{
    return (a<b);
}
int coinChange(vector<int> coins,int cap, int sum)
{
    int table[cap][sum+1];
    for(int i = 0; i < cap; i++)
        table[i][0] = 0;
    if(coins[0]==sum)
        return 1;
    if(coins[0]>sum)
        return -1;
    for(int i = 0; i < cap; i++)
    {
        for(int j = 1; j < sum + 1; j++)
        {
            if(i == 0)
            {
                if(j%coins[0]==0)
                    table[0][j] = j/coins[0];
                else table[0][j] = 0;
            }
            else
            {
                if(coins[i]>j)
                        table[i][j] = table[i-1][j];
                else
                    table[i][j] = min(table[i-1][j],table[i][j-coins[i]]+1);
            }
        }
    }

    for(int i = 0 ; i< cap;i++)
    {
        for(int j=0; j< sum+1;j++)
            out<<table[i][j]<<" ";
        out<<endl;
    }

    return table[cap-1][sum];
}
    int parsing(vector<int> a, vector<int> b, int size1, int size2)
    {
        int table[size1+1][size2+1]={0};
        for(int i = 0; i <= size1; i++)
        {
            for(int j = 0; j <= size2; j++)
            {
                if(i == 0 || j == 0)
                    table[i][j] = 0;
                else if(a[i-1]==b[j-1] )
                {
                    table[i][j]=table[i-1][j-1]+1;
                }
                else
                    table[i][j]=max(table[i-1][j],table[i][j-1]);
            }
        }

        for(int i = 0; i <= size1; i++)
        {
            for(int j = 0; j <= size2; j++)
                cout<<table[i][j]<<" ";
            cout<<endl;
        }
        int i = size1, j = size2;
        vector<int> seq;
        while(table[i][j])
        {
            if(a[i-1]==b[j-1])
            {
                seq.push_back(a[i-1]);
                i--;j--;
            }
            else if(table[i-1][j]>table[i][j-1])
                i--;
            else j--;
        }
        for(int k = seq.size()-1; k >= 0; k--)
            out<<seq[k]<<" ";
        return table[size1][size2];
    }
int main()
{
    int S = 69;
    int n,m;
    in>>n>>m;
    vector<int> v,w;
    for(int i = 0,e ; i< n;i++)
    {
        in>>e;
        v.push_back(e);
    }
    for(int i = 0,e ; i< m;i++)
    {
        in>>e;
        w.push_back(e);
    }
    int length = parsing(v,w,n,m);
    out<<length;
    return 0;
}
