#include <fstream>

using namespace std;

int euclid(int a, int b){
    if (b == 0)
        return a;
    return euclid(b, a%b);
}

int main() {
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int n;
    fin>>n;
    for(int i=0;i<n;i++){
        int x,y;
        fin>>x>>y;
        fout<<euclid(x,y)<<"\n";
    }
    return 0;
}