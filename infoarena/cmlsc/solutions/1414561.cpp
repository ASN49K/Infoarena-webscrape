#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#define LL long long 
#define MAX 1030
 
using namespace std;

vector <int> a, b;
int dmax[MAX][MAX];
stack <int> s;

int main()
{
    int m, n, x;
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");
    fin >> m >> n;
    a.push_back(0);
    for(int i = 0; i < m; ++i){
        fin >> x;
        a.push_back(x);
    }
    b.push_back(0);
    for(int i = 0; i < n; ++i){
        fin >> x;
        b.push_back(x);
    }

    for(int i = 1; i <= m; ++i){
        for(int j = 1; j <= n; ++j){
            if(a[i] == b[j])
                dmax[i][j] = dmax[i-1][j-1] + 1;
            else
                dmax[i][j] = max(dmax[i-1][j], dmax[i][j-1]);
        }
    }
    fout << dmax[m][n] << '\n';

    while(m > 1 || n > 1){
        if(a[m] == b[n]){
            s.push(a[m]);
            m--;
            n--;
        }
        else{
            if(dmax[m-1][n] >= dmax[m][n-1])
                --m;
            else
                --n;
        }
        m = max(1, m);
        n = max(1, n);
    }
    while(!s.empty()){
        x = s.top();
        s.pop();
        fout << x << " ";
    }
    return 0;
}