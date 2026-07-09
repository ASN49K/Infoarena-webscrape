#include <fstream>

using namespace std;
int A,B,r,i,T;
int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");

    fin>>T;
    for(i=1;i<=T;i++)
    {
        fin>>A>>B;
        while(B!=0)
        {
            r=A%B;
            A=B;
            B=r;
        }//while
        fout<<A<<'\n';
    }//for i

    fin.close ();
    fout.close();
    return 0;
}
