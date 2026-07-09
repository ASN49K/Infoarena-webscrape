#include <iostream>
#include <fstream>

using namespace std;

int euclid (int x,int y)
{
    if(y==0)
        return x;
    else
        return euclid(y,x%y);
}

int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int x,y,t;
    fin>>t;
    for(;t>0;t--){
        fin>>x>>y;
        fout<<euclid(x,y)<<'\n';
    }
    return 0;
}
