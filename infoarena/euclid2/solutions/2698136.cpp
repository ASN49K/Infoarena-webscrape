#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    long long int T, a, b, r;
    fin>>T;
    while(T){
        fin>>a>>b;
        while(b){
            r=a%b;
            a=b;
            b=r;
        }
        fout<<a<<endl;
        T--;
    }
}
