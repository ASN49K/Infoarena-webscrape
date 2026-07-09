#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int get(int a,int b)
{   if(b==0)return a;
    return get(b,b%a);
}
int main()
{
    int n,a,b;
    fin>>n;
    while(fin>>a>>b)fout<<get(a,b)<<endl;
    return 0;
}
