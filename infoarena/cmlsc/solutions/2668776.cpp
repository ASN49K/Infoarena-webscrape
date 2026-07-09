#include <bits/stdc++.h>
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int mat[1025][1025];
int v1[1025],v2[1025];
int n1,n2;
stack < int > s;

int main()
{
    f >> n1 >> n2;
    for (int i=1;i<=n1;i++) {
        f >> v1[i];
    }
    for (int i=1;i<=n2;i++) {
        f >> v2[i];
    }
    for (int i=1;i<=n1;i++) {
        for (int j=1;j<=n2;j++) {
            if (v1[i]==v2[j]) {
                mat[i][j] = mat[i-1][j-1] + 1;
            }
            else {
                mat[i][j] = max(mat[i-1][j], mat[i][j-1]);
            }
        }
    }
    g << mat[n1][n2] << '\n';
    while (n1!=0 && n2!=0) {
        if (v1[n1]==v2[n2]) {
            s.push(v1[n1]);
            n1--;
            n2--;
        }
        else {
            if (mat[n1][n2]==mat[n1-1][n2]) {
                n1--;
            }
            else {
                n2--;
            }
        }
    }
    while (s.empty()==0) {
        g << s.top() << " " ;
        s.pop();
    }
    return 0;
}
