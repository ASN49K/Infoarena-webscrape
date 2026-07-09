#include <iostream>
#include <fstream>
using namespace std;


int main()
{
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");
    int i,j,l,M,N , x[1024],y[1024],z[1024];
    fin >> M >> N;
    for (i=0;i<M;++i) fin >> x[i];
    for (i=0;i<N;++i) fin >> y[i];
    // CITIRE
    l=0;
    for (i=0;i<M;++i)
    for (j=0;j<N;++j){
        if (x[i]==y[j]) {z[l]=x[i];x[i]=0;++l;}
    }

    fout << l << endl;
    for (i=0;i<l;++i) fout << z[i] << " ";

    return 0;

}
