#include <iostream>
#include <fstream>

using namespace std;

int a, b, T;

int cm(int A, int B)
{
    if(!B)return A;
    return cm(B, A % B);
}

int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");

    fin>>T;

    for(; T; --T)
    {
        fin>>a>>b;

        fout<<cm(a, b)<<endl;
    }

    fin.close();
    fout.close();

    return 0;
}
