#include <iostream>
#include <fstream>
using namespace std;

int main(){
    int m,n,a[256], b[256], c = 0, v[256];

    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");

    f>>m>>n;

    for(int i = 0; i<m; i++){
        f>>a[i];
    }

    for(int i = 0; i< n; i++){
        f>>b[i];
    }

    for(int i = 0; i < m; i++){
        for( int j = 0 ; j < n; j++){
            if(a[i] == b[j]){
                v[c] = a[i];
                c++;
            }
        }
    }
    g<<c<<endl;

    for(int i = 0; i<c; i++){
        g<<v[i]<<" ";
    }
    f.close();
    g.close();
    return 0;
}
