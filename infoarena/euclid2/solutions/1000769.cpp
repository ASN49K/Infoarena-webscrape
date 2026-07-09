#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int gcd(int a, int b)
{
    while(a!=b){
        if(a>b)
            a = a-b;
        else
            b=b-a;
    }
    return a;
}

int main()
{
    int n;
    fin >> n;

    for(int i=0;i<n;i++){
        int a,b;
        fin >> a;
        fin >> b;
        fout << gcd(a,b) << '\n';
    }
    return 0;
}

