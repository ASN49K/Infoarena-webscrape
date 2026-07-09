#include<fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int A,B,M;

int Euclid(int A,int B)
{
    if(B==0)
        return A;
    return (B,A%B);
}

int main()
{
    fin>>M;
    for(int i=1;i<=M;i++)
    {
        fin>>A>>B;
        fout<<Euclid(A,B)<<'\n';
    }
}
