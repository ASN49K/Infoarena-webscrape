#include<fstream>
 
int T, A, B;
 
int gcd(int a, int b)
{
    if (!b) return a;
    return gcd(b, a % b);
}
 
int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
 
    fin>>T;

    for (int i = 1; i <= T; i++)
    {
        fin>>A>>B;
        fout<<gcd(A, B)<<endl;
    }        
 
    return 0;
}

