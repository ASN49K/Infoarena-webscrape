#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int a[1024],b[1024];//vectorii care se citesc
int lcs[1024][1024];//LCS i,j={max dintre LCS[i+1][j],LCS[i][j+1], daca a[i]!=b[j] sau LCS i,j=1+LCS(i+1,j+1), daca a[i]=b[j]
int constr[1024];//vectorul in care construim subsirul comun
int lg,m,n;

void citire();
void pd();
int maxim(int x,int y);
void afisare();

int main()
{
    citire();
    pd();
    afisare();
    return 0;
}

void citire()
{
    int i;
    //citim m si n si cei doi vectori
    fin>>m>>n;
    for(i=1;i<=m;i++)
        fin>>a[i];
    for(i=1;i<=n;i++)
        fin>>b[i];
}

void pd()
{
    int i,j;
    //programare dinamica dupa relatia de recurenta gandita
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
            if(a[i]==b[j])//suntem pe cazul in care cele doua elemente sunt egale
                lcs[i][j]=1+lcs[i-1][j-1];
            else
                lcs[i][j]=maxim(lcs[i-1][j],lcs[i][j-1]);//suntem pe cazul in care cele doua elemente din vectori nu sunt egale
    //reconstituim solutia folosindu-ne de matricea LCS
    i=m;j=n;//pornim de la sfarsit
    while(i!=0)//cat timp nu am ajuns la inceputul vectorului
    {
        if(a[i]==b[j])
        {
            lg++;//numarul de elemente din cel mai lung subsir comun creste
            constr[lg]=a[i];//retinem elementul
            //trecem mai departe
            i--;
            j--;
        }
        else
        //daca nu sunt egale elementele trecem mai departe numai intr-unul din vectori
            if(lcs[i-1][j]<lcs[i][j-1])
                j--;
            else
                i--;
    }
}

int maxim(int x,int y)
{
    //calculam maximul dintre x si y
    if(x>y)
        return x;
        else
            return y;
}


void afisare()
{
    int i;
    fout<<lg<<'\n';//afisam lungimea
    //afisam vectorul de la coada la cap
    for(i=lg;i!=0;i--)
        fout<<constr[i]<<' ';
    fout.close();
}
