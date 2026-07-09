#include <iostream>
#include <fstream>

using namespace std;
ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");
int Euclid (int a , int b){
    while (a != 0){
        int r = b % a;
        b = a;
        a = r;
    }
    return b;
}
int main()
{
    int N ;
    fin >> N ;
    for (int i = 1 ; i <= N ; ++i){
        long long  x , y;
        fin >> x >> y;
        fout << Euclid(x , y) << '\n';
    }
    return 0;
}
