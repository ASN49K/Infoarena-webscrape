#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("euclid2.in");
ofstream fout ("euclid2.in");

int euclid(int a,int b)
{
    int r=a%b;
    while(r)
    {
        a=b;b=r;r=a%b;
    }
    return b;
}

int main()
{
    int nrofpairs;
    pair<int,int> apair;
    fin>>nrofpairs;
    for(int i=nrofpairs;i;--i)
    {
        fin>>apair.first>>apair.second;
        fout<<euclid(apair.first,apair.second)<<'\n';
    }

    return 0;
}
