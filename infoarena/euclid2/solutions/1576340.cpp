#include <fstream>

using namespace std;

int main()
{
    int S,N,P;
    ifstream fin ("suma.in");
    ofstream fout ("suma.out");
    fin>>N>>P;
    if((N-1)%3==0)
    {
        S=(N-1)/3;
        S=(1LL *S*N)%P;
        S=(1LL*S*(N+1))%P;
    }
    else if (N%3==0)
    {
        S=N/3;
        S=(1LL*S*(N-1))%P;
        S=(1LL*S*(N+1))%P;
    }
    else if((N+1)%3==0)
    {
        S=(N+1)/3;
        S=(1LL*S*N)%P;
        S=(1LL*S*(N-1))%P;
    }

    fout<<S;

    fin.close ();
    fout.close ();

    return 0;
}
