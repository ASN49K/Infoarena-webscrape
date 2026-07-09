#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

#define max(a, b) ( a > b ? a : b )

int main() {
    ifstream in("cmlsc.in");
    ofstream out("cmlsc.out");

    int m, n;
    in>>m>>n;
    int a[m + 1], b[n + 1];

    for(int i = 1; i <= m; i++)
        in>>a[i];

    for(int i = 1; i <= n; i++)
        in>>b[i];

    int arr[n + 1][m + 1];

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

    int sir[1025];
    int index = 0;

    while(n >= 1 || m >= 1){
        int i = n, j = m;
        if(a[j] == b[i]){
            sir[index++] = a[j];
            m--,n--;
        } else {
            if(arr[i][j - 1] > arr[i - 1][j]){
                m--;
            } else {
                n--;
            }
        }
    }

    for(int i = index - 1; i >= 0; i--){
        out<<sir[i]<<" ";
    }


    return 0;
}

