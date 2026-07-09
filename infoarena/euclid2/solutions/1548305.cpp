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
    pair <long long , long long> nr[100005];
    int n;
    fin >> n;
    for(int i = 1 ; i <= n ; i++)
    {
        fin >> nr[i].first >> nr[i].second;
        fout << cmmdc(nr[i].first , nr[i].second) << '\n';
    }
    return 0;
}
