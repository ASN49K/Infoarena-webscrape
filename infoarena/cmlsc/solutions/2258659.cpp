#include <iostream>
#include <fstream>

using namespace std;

#define MAX 1024 + 1
typedef long long ll;

int main()
{
    ifstream in("cmlsc.in");
    ofstream out("cmlsc.out");

    int n, m;
    in >> n >> m;
    int a[MAX];
    int b[MAX];

    for(int i = 0; i < n; ++i){
        in >> a[i];
    }

    for(int i = 0; i < m; ++i){
        cin >> b[i];
    }

    int r = 0;
    int cs[MAX];

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(a[i] == b[j]){
                cs[r] = a[i];
                r++;
            }
        }
    }

    out << r << '\n';

    for(int i = 0; i < r; ++i){
        out << cs[i] << " ";
    }
}
