#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int euclid(int a,int b)
{
    int rest = 0;
    while(a!=0){
        rest = b%a;
        b = a;
        a = rest;
    }
    return b;
}

int main()
{
    int t, a, b;
    fin>>t;
    //while(t!=0){
    for(int i=1; i<=t; i++){
        fin>>a>>b;
        fout<<euclid(a, b)<<endl;
        //t--;
    }
    fin.close();
    fout.close();
    fout.flush();
    return 0;
}
