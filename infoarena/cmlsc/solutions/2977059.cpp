#include <bits/stdc++.h>
#define maxim 1024

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int n, m;
int a[maxim], b[maxim], sir[maxim], mat[maxim][maxim];

int main() {
    in >> n >> m;
    for(int i = 1;i <= n;i++){
        in >> a[i];
    }
    for(int j = 1;j <= m;j++){
        in >> b[j];
    }

    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            if(a[i] == b[j]){
                mat[i][j] = mat[i - 1][j - 1] + 1;
            }
            else{
                mat[i][j] = max(mat[i - 1][j], mat[i][j - 1]);
            }
        }
    }

    int count = 0;
    int i = n;
    int j = m;
    while(i > 0){
        if(a[i] == b[j]){
            sir[count++] = a[i];
            i --;
            j --;
        }
        else if(mat[i - 1][j] < mat[i][j - 1]){
            j --;
        }
        else{
            i--;
        }
    }
    out << count << '\n';
    for(int index = count - 1;index >= 0;index--){
        out << sir[index] << ' ';
    }
    return 0;
}
