#include<iostream>
#include<fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");



int main() {


    int n,a,b,i;
    fin>>n;

    for(i = 1;i<=n;i++)
    {
        fin>>a>>b;
        while(b) {

            int r = a%b;
            a=b;
            b=r;

        }
        fout<<a<<endl;

    }


}
