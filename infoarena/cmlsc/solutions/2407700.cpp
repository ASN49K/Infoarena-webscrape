#define NUMBERS_OF_VECTORS 2
#include <fstream>
#include <map>
using namespace std;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

map < int, int > DP;
int n, m, x, k;

int main()
{
    cin>>m>>n;
    for(int i = 0; i < m; i++) {
        cin>>x;
        DP[x]++;
    }
    for(int i = 0; i < n; i++) {
        cin>>x;
        DP[x]++;

        if(DP[x] == NUMBERS_OF_VECTORS) k++;
    }

    cout<<k<<'\n';
    for(auto it = DP.begin(); it != DP.end(); it++)
        if(it->second == NUMBERS_OF_VECTORS)
            cout<<it->first<<' ';

    cin.close();
    cout.close();
    return 0;
}
