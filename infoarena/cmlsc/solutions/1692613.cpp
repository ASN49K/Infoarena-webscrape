#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int A[1025], B[1025];
int lenmat[1025][1025];

int main()
{
    ifstream in("cmlsc.in");
    ofstream out("cmlsc.out");

    int m, n;
    in >> m >> n;
    
    for (int i = 1; i <= m; i++) {
        in >> A[i];
        lenmat[i][0] = 0;
        lenmat[i][1] = 0;
    }
        
    for (int i = 1; i <= n; i++) {
        in >> B[i];
        lenmat[0][i] = 0;
        lenmat[1][i] = 0;
    }
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (A[i] == B[j])
                lenmat[i][j] = 1 + lenmat[i - 1][j - 1];
            else
                lenmat[i][j] = max(lenmat[i - 1][j], lenmat[i][j - 1]);
        }
    }
    out << lenmat[m][n] << "\n";
    vector<int> comseq;
    comseq.reserve(lenmat[m][n]);
    
    for (int i = m, j = n; i > 0, j > 0;) {
        if (A[i] == B[j]) {
            comseq.push_back(A[i]);
            i--;
            j--;
        } else if (lenmat[i][j - 1] < lenmat[i - 1][j]) {
            i--;
        } else {
            j--;
        }
    }  

    for (int i = lenmat[m][n] - 1; i >= 0; i--)
        out << comseq[i] << " ";
    out << "\n";

    in.close();
    out.close();
    
    return 0;
}
