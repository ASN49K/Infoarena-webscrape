#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid.in");
ofstream fout("euclid.out");

int cmmdc(int a , int b){
    if(!b) return a;
    else cmmdc(b , a % b);
}

int main()
{
    long long a , b;
    int n;
    fin >> n;
    for(int i = 1 ; i <= n ; i++)
    {
        fin >> a >> b;
        fout << cmmdc(a , b) << '\n';
    }
    fout.close();
    return 0;
}
