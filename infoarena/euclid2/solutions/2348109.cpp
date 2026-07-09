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

int euclid2(int x,int y)
{
    while(x!=y)
    {
        if(x>y)
            x=x-y;
        else
            y=y-x;
    }
    return x;
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
        fout<<euclid2(x,y)<<endl;
    }
    fin.close();
    fout.close();
}
