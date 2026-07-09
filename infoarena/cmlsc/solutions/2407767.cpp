#define OK_CODE 257
#define I_CODE 258
#define J_CODE 259

#include <fstream>
#include <vector>
using namespace std;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

int m, n, x;
vector < int > a, b;
vector < vector < int > > C, S;

void printLCS(int i, int j) {
    if(!i || !j) return;
    if(S[i][j] == OK_CODE) {
        printLCS(i-1, j-1);
        cout<<a[i]<<' ';
    }
    else if(S[i][j] == J_CODE) printLCS(i, j-1);
    else printLCS(i-1, j);
}

void LCS() {

    for(unsigned int i = 0; i < a.size(); i++) {
        C.push_back(vector < int > (b.size(), 0));
        S.push_back(vector < int > (b.size()));
    }

    for(unsigned int i = 1; i < a.size(); i++)
        for(unsigned int j = 1; j < b.size(); j++) {
            if(a[i] == b[j]) {
                C[i][j] = C[i-1][j-1] + 1;
                S[i][j] = OK_CODE;
            }
            else if(C[i][j-1] > C[i-1][j])  {
                C[i][j] = C[i][j-1];
                S[i][j] = J_CODE;
            }
            else {
                C[i][j] = C[i-1][j];
                S[i][j] = I_CODE;
            }
        }

    cout<<C[a.size()-1][b.size()-1]<<'\n';
    printLCS(a.size()-1, b.size()-1);
}

int main() {
    cin>>m>>n;

    a.push_back(-1);
    b.push_back(-1);

    for(int i = 0; i < m; i++) {
        cin>>x;
        a.push_back(x);
    }
    for(int i = 0; i < n; i++) {
        cin>>x;
        b.push_back(x);
    }
    LCS();
    cin.close();
    cout.close();
    return 0;
}
