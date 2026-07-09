#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
int a,b,t;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int euclid(int x,int y)
{
    if(!y)
        return x;
    else
        return euclid (y,x%y);
}
int main()
{
    fin>>t;
    while(t)
    {
        {
            fin>>a>>b;
            if(a<b)
                swap(a,b);
            fout<<euclid(a,b)<<endl;
        }
        --t;
    }
    return 0;
}
