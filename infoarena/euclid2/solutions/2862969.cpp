#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int euclid(int a,int b)
{
    while(a!=b){
        if(a>b)
            a = a-b;
        else
            b = b-a;
    }
    return a;
}

int main()
{
    int t, a, b;
    fin>>t;
    while(t!=0){
        fin>>a>>b;
        fout<<euclid(a, b)<<endl;
        t--;
    }
    fin.close();
    fout.close();
    return 0;
}
