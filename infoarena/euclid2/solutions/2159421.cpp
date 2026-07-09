#include <iostream>
#include <fstream>
using namespace std;


int main()
{
    ifstream fin("euclid2.in");
    ofstream ofs("euclid2.out");

    int n;
    fin >> n;
    int a,b;
    for(int i = 0; i < n; i++){
        fin >> a >> b;
        while(b%a != 0){
        b = (b%a)+a;
        a = b-a;
        b = b-a;
    }
        ofs << a << '\n';
    }
    fin.close();
    ofs.close();
    return 0;
}
