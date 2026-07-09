#include <iostream>
#include <fstream>
using namespace std;
int euclid(int a, int b){
    int d = 0;
    if(a < b){
        d = a;
        a = b;
        b = d;
    }
    while(b != 0){
        d = a % b;
        a = b;
        b = d;
    }
    return a;
}

int main()
{
    ifstream fin("euclid2.in");
    ofstream ofs("euclid2.out");

    int n;
    fin >> n;
    int v[n];
    int a,b;
    for(int i = 0; i < n; i++){
        fin >> a >> b;
        ofs << euclid(a,b) << " ";
        ofs << endl;
    }
    fin.close();
    ofs.close();
    return 0;
}
