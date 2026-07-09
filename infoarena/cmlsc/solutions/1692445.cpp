#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ifstream in("cmlsc.in");
    ofstream out("cmlsc.out");
 
    int m, n;
    in >> m >> n;
    
    int A[m];
    int B[n];
    int appmat[m][n];
    int comseqlen;
    if (n > m)
        comseqlen = n;
    else
        comseqlen = m;
    int comseq[comseqlen];
    
    for (int i = 0; i < m; i++) {
        in >> A[i];
        
        if (comseqlen == m)
            comseq[i] = -1;
    }
    
    for (int i = 0; i < n; i++) {
        in >> B[i];
        
        if (comseqlen == n && m != n)
            comseq[i] = -1;
    }
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            appmat[i][j] = 0;
        }
    }
    
    
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (A[i - 1] == B[j - 1])
                appmat[i][j] = 1 + appmat[i - 1][j - 1];
            else
                appmat[i][j] = max(appmat[i - 1][j], appmat[i][j - 1]);
        }
    }
    int maxlen = appmat[m - 1][n - 1];
    
    for (int i = m, j = n, k = maxlen; i;) {
        if (A[i - 1] == B[j - 1])
            comseq[k--] = A[i - 1], --i, --j;
        else if (appmat[i - 1][j] < appmat[i][j - 1])
            j--;
        else
            i--;
    }
    
    out << maxlen + 1 << "\n";
    for (int i = 0; i < comseqlen && comseq[i] != -1; i++) {
        out << comseq[i] << " ";
    }
    out << "\n";
    
    in.close();
    out.close();
    
    return 0;
}
