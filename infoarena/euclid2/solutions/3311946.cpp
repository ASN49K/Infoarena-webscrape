
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int>v;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int euclid(int a, int b) {
    if (b == 0) {
        return a;
    }
    int r = a % b;
    a = b;
    b = r;
    return euclid(a, b);
}
int main()
{
    int n,a,b;
    fin >> n;
    for (int i = 0; i < n; ++i) {
        fin >> a >> b;
        fout << euclid(max(a,b), min(a,b))<<"\n";
    }
    return 0;
}
//=^..^=