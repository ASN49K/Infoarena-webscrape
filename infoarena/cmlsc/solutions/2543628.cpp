#include <bits/stdc++.h>
#define nl '\n'
using namespace std;

short um[1026][1026];

int main(){
    ifstream cin("cmlsc.in");
    ofstream cout("cmlsc.out");
    string a, b;
    int n, m;
    cin >> n >> m;
    char c;
    for(int i = 1; i <= n; ++i)
        cin >> c, a += c;
    for(int i = 1; i <= m; ++i)
        cin >> c, b += c;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            if(a[i - 1] == b[j - 1])
                um[i][j] = um[i - 1][j - 1] + 1;
            else
                um[i][j] = max(um[i - 1][j], um[i][j - 1]);

    int i = n, j = m;
    stack<char> st;
    while(i){
        if(a[i - 1] == b[j - 1])
            st.push(a[i - 1]), --i, --j;
        else if(um[i - 1][j] > um[i][j - 1])
            --i;
        else
            --j;
    }
    cout << um[n][m] << nl;
    while(st.size())
        cout << st.top() << ' ', st.pop();
    cin.close(), cout.close();
}
