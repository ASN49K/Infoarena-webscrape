#include <iostream>

using namespace std;

int a[1025], b[1025], d[1025][1025], sol[1025];

int main()
{
    int n, m, j, i;
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    cin>>n>>m;
    for(i = 1; i <= n; i++){
        cin>>a[i];
    }
    for(i = 1; i <= m; i++){
        cin>>b[i];
    }
    for(i = 1; i <= n; i++){
        for(j = 1; j<= m; j++){
            if(a[i] == b[j]){
                d[i][j] = d[i - 1][j - 1] + 1;
            }
            else{
                d[i][j] = max(d[i][j - 1], d[i - 1][j]);
            }
        }
    }
    cout<<d[n][m]<<endl;

    i = n;
    j = m;

    int k = 0;
    while(i >= 1 && j >= 1){
        if(a[i] == b[j]){
            sol[++k] = a[i];
            //cout<<a[i]<<' ';
            i--;
            j--;
        }
        else{

            if(d[i - 1][j] > d[i][j - 1]){
                i--;
            }
            else
                j--;
        }
    }
    for(i = k; i >= 1; i--){
        cout<<sol[i]<<' ';
    }

    return 0;
}
