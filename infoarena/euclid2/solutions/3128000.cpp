#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main()
{
    int N, a, b, c;
    fin>>N;
    for(int i = 0; i<N; i++){
        fin>>a>>b;
        if(a<b)
            swap(a, b);
        while(b>0){
            c = a%b;
            a = b;
            b = c;
        }
        fout<<a<<'\n';
    }
    return 0;
}
