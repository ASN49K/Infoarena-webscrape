#include <fstream>

using namespace std;

#define NMax 1024

int m, n, a[NMax], b[NMax], d[NMax][NMax], sir[NMax], bst;

int maxim (int a, int b){

    if (a < b){
        return b;
    }

    return a;
}

int main()
{
    int i, j;
    ifstream cin ("cmlsc.in");
    ofstream cout ("cmlsc.out");

    cin >> m >> n;

    for (i = 1; i <= m; i++){
        cin >> a[i];
    }

    for (i = 1; i <= n; i++){
        cin >> b[i];
    }

    for (i = 1; i <= m; i++){

        for (j = 1; j <= n; j++){

            if (a[i] == b[j]){
                d[i][j] = 1 + d[i - 1][j - 1];
            }

            else {
                d[i][j] = maxim(d[i - 1][j], d[i][j - 1]);
            }

        }

    }

    for (i = m, j = n; i > 0; 1){

        if (a[i] == b[j]){
            sir[++bst] = a[i];
            i--;
            j--;
        }

        else if (d[i-1][j] < d[i][j-1]){
            j--;
        }

        else {
            i--;
        }

    }

    cout << bst << "\n";

    for (i = bst; i > 0; i--){
        cout << sir[i] << " ";
    }

    return 0;
}
