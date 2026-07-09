#include <iostream>
#include <fstream>
#define inFile "euclid2.in"
#define outFile "euclid2.out"

using namespace std;

int rezolvare(int a,int b)
{
    if(b==0) return a;
    return rezolvare(b,a%b);
}

int main()
{
    int t,a,b;

    ifstream fin(inFile);
    ofstream fout(outFile);

    fin>>t;
    for(int i=1;i<=t;i++)
    {
        fin>>a>>b;
        fout<<rezolvare(a,b)<<"\n";
    }

    fin.close();
    fout.close();
}
