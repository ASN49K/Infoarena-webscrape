#include <iostream>

using namespace std;

int main()
{
    int n,m, a[100],b[100], s[100][100];
    for (int i=1; i<=n; i++;) cin>>a[i];
    for (int j=1; j<=n; j++;) cin>>b[j];
    for (int i=1; i<=n; i++;)
        for (int j=1; j<=n; j++;)
    if(a[i]==b[j]){
        s[i][j]== s[i-1][j-1]+1;
        cout<<a[i]<<"";
        else
            s[i][j]== max(s[i+1][j], s[i][j+1]);
            cout<< s[n][m];
    }
    return 0;
}
