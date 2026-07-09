#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int a[1025][1025];
int A[1025],B[1025];
vector <int> sir;

int main() {
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    ios_base::sync_with_stdio(false);
    size_t n,m;
    cin >> n >> m;
    for(size_t i = 1;i<=n;++i){
        cin >> A[i];
    }
    for(size_t i = 1;i<=m;++i){
        cin >> B[i];
    }

    for(size_t i = 1;i<=n;++i){
        for(size_t j = 1; j<=m;++j){
            if(A[i]==B[j])
                a[i][j] = 1 + a[i-1][j-1];
            else
                a[i][j] = max(a[i-1][j],a[i][j-1]);
        }
    }
    for(size_t i = n, j = m;i>0; ){
        if(A[i]==B[j]){
            sir.push_back(A[i]);
            --i;
            --j;
        }
        else if(a[i-1][j]<a[i][j-1])
            --j;
        else
            --i;
    }
    cout << a[n][m] << '\n';
    for(auto it = sir.rbegin(); it!=sir.rend();++it){
        cout << *it << ' ' ;
    }


    return 0;
}