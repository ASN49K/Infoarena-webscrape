#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int a,b,r,k;
    fin>>k;
    while(k!=0)
    {
        fin>>a>>b;
        while(a!=b)
        {
            if(b>a) b=b-a;
            if(a>b) a=a-b;
        }
        k--;
        fout<<a<<"\n";
    }
    fin.close();
    fout.close();
    return 0;
}
