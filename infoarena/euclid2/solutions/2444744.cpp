#include <fstream>
using namespace std;

int euclid(int a, int b){
    if(b == 0) return a;
    return euclid(b, b%a);
}
int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");

    int a, b;
    fin>>a>>b;
    fout<<euclid(a, b);
}
