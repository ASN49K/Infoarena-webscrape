#include <iostream>
#include <fstream>


using namespace std;
int euclid(int x,int y)
{
    int t,r;
    if(x<y)
    {
        t=x;
        x=y;
        y=t;
    }
    do{
    r=x%y;
    x=y;
    y=r;
    }while(r);
    return x;
}

int main()
{
    int x,y,z;
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    fin>>x;
    for(int i=0;i<x;++i)
    {
        fin>>y>>z;
        fout<<euclid(y,z)<<endl;
    }


    return 0;
}
