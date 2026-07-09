#include <iostream>#include <fstream>
using namespace std;
int main()
{
    //Dandu-se T perechi de numere naturale (a, b), sa se calculeze cel mai mare divizor comun al numerelor din fiecare pereche in parte.
    int a, b, cmmdc, n;
    ifstream fin;
    fin.open ("euclid2.in");
	
    ofstream fout;
    fout.open ("euclid2.out");
	
    fin>>n>>a>>b;
	
    for (int i=0; i<=n; i++)
    {
        while (b>0)
        {
            cmmdc=a%b;
            a=b;
            b=cmmdc;
        }
        fout<<a;
        fin>>a>>b;
    }
    /*
    //Sa se determine subsirul de lungime maxima care apare atat in A cat si in B.
    int a[100], b[100], c[200], n1, n2, dm, elem;
    //cout<<"Introduceti nr de elem din primul sir: ";
    //cin>>n1;
    //cout<<"Introduceti nr de elem din cel de-al doilea sir: ";
    //cin>>n2;

    ifstream.cmlsc_in;
    cmlsc_in.open ("cmlsc_in.txt");

    ofstream.cmlsc_out;
    cmlsc_out.open ("cmlsc_out.txt");

    for (int i=0; i<n1; i++)
    {
        cmlsc_in>>a[i];
    }
     for (int i=0; i<n2; i++)
    {
        cmlsc_in>>b[i];
    }

    if (n1<n2)
    {
         dm=n1;
    }
    else
    {
         dm=n2;
    }
    for (int i=0; i<n1; i++)
    {
        for(int j=0; j<n2; j++)
        {
            if (a[i]=b[i])
            {
                elem=a[i];
                c[i]=elem;
            }
        }
    }
    for (int i=0; i<dm; i++)
    {
        cmlsc_out<<c[i];
    }
    */

    /*
    //Sa se determine un subsir al lui a care este ordonat strict crescator si care are lungimea maxima.
    int a[100], b[100], n, k=0;
    int temp = 0;
    //cout<<"Introduceti nr de elem din primul sir: ";

    ifstream scmax_in;
    scmax_in.open ("scmax_in.txt");

    ofstream scmax_out;
    scmax_out.open ("scmax_out.txt");

    scmax_in>>n;
    for (int i=0; i<n; i++)
    {
        scmax_in>>a[i];
    }
    b[0] = 0;
    for (int i=0; i<n; i++)
    {
        if (a[i] > temp)
        {
            b[k]=a[i];
            temp = b[k];
            k++;
        }
    }
    for (int i=0; i<k; i++)
    {
        scmax_out<<b[i]<<" ";
    }
    */

    /*
    //Sa se genereze toate permutarile multimii {1, 2, ...N}, in ordine lexicografica.
    int a[100], b[100], i, n;
    cout<<"Introduceti nr de elemenete din sir: ";
    cin>>n;
    for (i=0; i<n; i++)
    {
        cout<<"a["<<i<<"]="<<a[i];
        cin>a[i];
    }
    for (i=0; i<n; i++)
    {
        cout<<a[i];
    }
    for ()
    */

    /*
    //A+B --> Adunare simplă.
    int a, b;
    ifstream fin;
    fin.open ("fin.txt")
    ofstream fout;
    fout.open ("fout.txt")
    fin>>a>>b;
    fout<<a+b;
    */

    /*
    int n, p=1;
    ifstream fin;
    fin.open ("fin.txt")
    ofstream fout;
    fout.open ("fout.txt")
    fin>>n;
    for (int i=1; i<=n; i++)
    {
        p*=i;
    }
    fout<<p;
    */
    return 0;
}
