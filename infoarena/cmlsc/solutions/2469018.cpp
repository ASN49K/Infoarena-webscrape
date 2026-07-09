#include <fstream>
using namespace std;

#define max(a, b) ( a > b ? a : b )
#define MAX 1030

int a[MAX], b[MAX], arr[MAX][MAX], sir[MAX], m, n, index;

int main() {
    ifstream in("cmlsc.in");
    ofstream out("cmlsc.out");

    in>>m>>n;

    for(int i = 1; i <= m; i++)
        in>>a[i];

    for(int i = 1; i <= n; i++)
        in>>b[i];

    for(int i = 0; i <= n; i++)
        arr[i][0] = 0;
    for(int i = 0; i <= m; i++)
        arr[0][i] = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[j] == b[i]){
                arr[i][j] = 1 + arr[i - 1][j - 1];
            } else {
                arr[i][j] = max(arr[i][j - 1], arr[i - 1][j]);
            }
        }
    }

    out<<arr[n][m]<<"\n";

    index = -1;

    while(n >= 1 || m >= 1){
        int i = n, j = m;
        if(a[j] == b[i]){
            sir[++index] = a[j];
            m--,n--;
        } else {
            if(arr[i][j - 1] > arr[i - 1][j]){
                m--;
            } else {
                n--;
            }
        }
    }

    for(int i = index; i >= 0; i--){
        out<<sir[i]<<" ";
    }


    return 0;
}

