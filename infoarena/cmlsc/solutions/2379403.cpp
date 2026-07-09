#include <bits/stdc++.h>

using namespace std;

vector<int> best_seq;
vector<int> v1;
vector<int> v2;

void lcs(int i, int j, vector<int>& seq) {

    if(i < 0 || j < 0) {
        if(seq.size() > best_seq.size()) {
            best_seq = seq;
        }
    return;
    }
    if(v1[i] == v2[j]) {
        seq.push_back(v1[i]);
        lcs(i-1,j-1,seq);
        seq.pop_back();
    }
    else {
        lcs(i,j-1,seq);
        lcs(i-1,j,seq);
    }
}

int main()
{
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");

    int n, m;

    fin>>m>>n;
    for(int i=1; i<=m; i++) {
        int x;
        fin>>x;
        v1.push_back(x);
    }
    for(int i=1; i<=n; i++) {
        int x;
        fin>>x;
        v2.push_back(x);
    }

    vector<int> p;
    lcs(m-1, n-1, p);

    fout<<best_seq.size()<<endl;

    for(int i = best_seq.size()-1; i>=0; i--) {
        fout<<best_seq[i]<<" ";
    }

    /*
    int dp[1001][1001];
    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) {
            if(v[i]==w[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    fout<<dp[m][n]<<endl;
    */


    return 0;
}
