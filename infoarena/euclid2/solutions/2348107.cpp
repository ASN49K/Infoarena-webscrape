#include <iostream>
#include <fstream>

using namespace std;

int euclid(int a,int b)
{
    int c;
    while(b)
    {
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}

int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int T,i,x,y;
    fin>>T;
    for(i=1;i<=T;i++)
    {
        fin>>x>>y;
        fout<<euclid(x,y)<<endl;
    }
    fin.close();
    fout.close();
}
