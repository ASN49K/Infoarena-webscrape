#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int t;
    fin>>t;
    while (t!=0)
    {
        int a,b;
        fin>>a>>b;
        while (a!=b)
        {
            if (a>b)
                a=a-b;
            else
                b=b-a;
        }
        fout<<a<<"\n";
        t--;
    }
    fin.close();
    fout.close();
}
