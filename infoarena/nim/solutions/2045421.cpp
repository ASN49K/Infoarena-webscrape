#include <cstdio>

using namespace std;

/*xor
a^a = 0

suma xor a tuturor size-urilor de gramezi = S

S = 0
=> daca sunt 0 pietre in toate gramzile => LOSE
=> o stare din care oricum as lua p pietre as ajung in ceva cu S' != 0
=> LOSE

S != 0
=> mereu pot lua x pietre in asa fel incat sa ajung la S' = 0
=> WIN

o gramada cu size X
eu voi lua ( X - ceva ) din gramada
iau X - S ^ X

 S^X ^ ( S^X ) = 0
*/
int t;
FILE * f= fopen("nim.in","r");
FILE * g= fopen("nim.out","w");

int main()
{
    fscanf(f,"%d",&t);
    while(t)
    {
        int n,rez=0;
        fscanf(f,"%d",&n);
        while(n)
        {
            int x;
            fscanf(f,"%d",&x);
            rez^=x;
            n--;
        }
        if(rez==0)
            fprintf(g,"NU\n");
        else fprintf(g,"DA\n");
        t--;
    }
    return 0;
}
