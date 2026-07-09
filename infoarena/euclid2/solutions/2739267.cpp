#include<bits/stdc++.h>
#define INFILE fin("euclid2.in");
#define OUTFILE fout("euclid2.out");

using namespace std;

ifstream INFILE
ofstream OUTFILE

const int NRBITI = 32;
int BINAR[NRBITI] = {0};

void resetBinar(){
    int i;
    for(i=0;i<NRBITI;i++)
    {
        BINAR[i] = 0;
    }
}

// reprezentare numar in baza 2

int calculBinar(int n)
{
    resetBinar();
    int i;
    for(i=0;n>0;i++)
    {
        BINAR[i] = n%2;
        n=n/2;
    }
    return i+1;
}

int calculBinar2(int n)
{
    resetBinar();
    int i = 0;
    while(n)
    {
        BINAR[i] = n & 1;
        n>>=1;
        i++;
    }
    return i;
}

//determminare grad nnumar

int determinareGrad(int n)
{
    int grad = 0;
    int nrCifre = calculBinar2(n);
    for(int i = nrCifre;i>=2;i--)
    {
        if(BINAR[i] == 1 && BINAR[i-1] == 0 && BINAR[i-2] == 1)
            grad++;
    }
    return grad;
}

int determinareGrad2(int n)
{
    int grad = 0;
    while(n)
    {
        if ((n&7) == 5)
        {
            grad++;
            n >>= 2;
        }
        else{
            n >>= 1;
        }
    }
    return  grad;
}

int sumaPatrate(int n)
{
    int suma = 0;
    while(n)
    {
        suma= suma + (n%10)*(n%10);
        n=n/10;
    }
    return suma;
}

bool eNumarZambaret(int n)
{
    int nr1,nr2;
    nr1=nr2 = n;
    do{
        nr1= sumaPatrate(nr1);
        nr2 = sumaPatrate(sumaPatrate(nr2));
    }while(nr1!=nr2);
    return (nr1==1);
}

int adunareModulo(int a,int b,int n)
{
    return (a+b)%n;
}

int determinareCastig(int n)
{
    int curse;
    int castig = 0;
    int castig_cursa;
    cin>>curse;
    while(n)
    {
        cin>>castig_cursa;
        castig = adunareModulo(castig,castig_cursa,n);
        curse--;
    }
    return castig;
}

unsigned DEtNumarCifre(unsigned long long n)
{
    int nrCif = 0;
    do{
        nrCif++;
        n=n/10;
    }while(n!=0);
    return nrCif;
}
unsigned DetNumarCifre2(unsigned long long n)
{
    if(n==0)
        return 1;
    return 1+DetNumarCifre2(n/10);
}

long long RidicarePutereLogaritmica(long long n,long long p)
{
    long long r = 1;
    while(p)
    {
        if(p%2==1)
            r=r*n;
        p=p/2;
        n=n*n;
    }
    return r;
}

void Formula1_partea1(long long a){
    long long rezultat = RidicarePutereLogaritmica(2*a-1,2);
    fout<<rezultat;
}

void Formula1_partea2(long long n){
    long long A = (n*(n+1)*(2*n+1))/3-n*(n+1);
    long long x = (int)sqrt(2*A+1);
    if(x%2==0)
        x=x-1;
    fout<<RidicarePutereLogaritmica(x,2);
}

void Formula1()
{
    unsigned c;
    long long k,n;
    fin>>c;
    fin>>k>>n;
    if(c==1)
    {
        Formula1_partea1(k);
    }
    else if(c==2){
        Formula1_partea2(n);
    }
}

void euclid2()
{
    long long T,a,b;
    fin>>T;
    while(T)
    {
        fin>>a>>b;
        long long r;
        while(b)
        {
            r=a%b;
            a=b;
            b=r;
        }
        cout<<a<<'\n';
        T--;
    }
}

int main()
{
    euclid2();
	return 0;
}

