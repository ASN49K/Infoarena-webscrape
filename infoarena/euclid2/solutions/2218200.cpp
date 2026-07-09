#include <iostream>
#include <fstream>

using namespace std;

int divizor(int x, int y){
int i,z=1;
if (x<y) {i=x;x=y;y=i;};
for (i=1;i<=y;++i)
    if (x%i==0 && y%i==0)  z=i;
return z;
}

int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int a,b,t,i;
    fin >> t;
    for (i=0;i<t;++i){
        fin >> a >> b;
        fout << divizor(a,b) << "\n";
    }

    return 0;
}
