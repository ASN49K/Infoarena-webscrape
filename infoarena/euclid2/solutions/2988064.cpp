#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

inline int euclid(int a,int b) {
    if(b==0) {
        return a;
    }
    return euclid(b,a%b);
}
int main()
{
    int n,a,b;
    fin>>n;
    while(n--) {
        fin>>a>>b;
        fout<<euclid(a,b)<<"\n";
    }
}
