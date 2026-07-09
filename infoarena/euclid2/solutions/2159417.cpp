#include <iostream>
#include <fstream>
using namespace std;
int euclid(int a, int b){
    while(b%a != 0){
        b = (b%a)+a;
        a = b-a;
        b = b-a;
    }
    return a;
}

int main()
{
    ifstream fin("euclid2.in");
    ofstream ofs("euclid2.out");

    int n;
    fin >> n;
    int a,b;
    for(int i = 0; i < n; i++){
        fin >> a >> b;
        ofs << euclid(a,b) << endl;;
    }
    fin.close();
    ofs.close();
    return 0;
}
