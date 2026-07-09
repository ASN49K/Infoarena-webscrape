#include <iostream>
#include<fstream>

using namespace std;

int euclid2(int a, int b)
{
    int r;
    r=a%b;
    while(r)
    {
        a=b;
        b=r;
        r=a%b;
    }
    return b;
}

int main()
{
    int n,x,y,i;
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    fin>>n;
    while(n)
    {
        fin>>x>>y;
        fout<<euclid2(x,y);
        fout<<endl;
        n--;
    }

}
