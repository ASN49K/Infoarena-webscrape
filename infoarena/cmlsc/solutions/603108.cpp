#include <iostream>
#include <fstream>

using namespace std;

#define maxim(a,b) ( (a>b) ? a:b )

int main()
{
    ifstream fin;
    ofstream fout;

    fin.open("cmlsc.in");
    fout.open("cmlsc.out");

    int b[100];
    int k = 0;
    int m, n;
    int x[100], y[100];
    fin >> m;
    fin >> n;
    x[0] = y[0] = 0;
    for(int i=1; i<=m; i++)
        fin >> x[i];
    for( int j=1;j<=n;j++)
        fin >> y[j];


    int c[100][100];

    c[0][0] = 0;
    for( int i=1; i<=m; i++)
        for( int j=1; j<=n; j++){
            if( x[i]==y[j])
                c[i][j] = c[i-1][j-1]+1;
            else c[i][j] = maxim(c[i-1][j], c[i][j-1]);
        }

   // cout << "Lungimea subsirului comun este " << c[m][n]<<endl;
   fout << c[m][n];

    int i=m, j=n;
    while(i,j)
    {
        if( x[i]==y[j])
        {
            b[k++]=x[i];
            i--, j--;
        }
        else if(c[i-1][j] > c[i][j-1])
        {
            --i;
        }
        else --j;
    }
   // cout << endl;

   // for( int contor=k-1; contor>=0; contor--)
      //  cout << b[contor] << " ";
      fout << endl;
    for( int contor=k-1; contor>=0;contor--)
        fout << b[contor] << " ";

    return 0;

}




