#include <fstream>
#include <iostream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int a[1025], b[1025], c[1025][1025];

void drum(int i, int j)
{
    if(c[i][j] == 0)
        return;
    else if(c[i][j] != c[i-1][j] &&
            c[i][j] != c[i][j-1]){
        fout << a[i] << " ";
        drum(i-1,j-1);
    }
    else if(c[i][j] == c[i-1][j])
        drum(i-1,j);
    else drum(i,j-1);

}

int main()
{
    int maxa, maxb;
    fin >> maxa >> maxb;

    for(int i = 1; i <= maxa; i++)
        fin >> a[i];
    for(int i = 1; i <= maxb; i++)
        fin >> b[i];

    for(int i = 1; i <= maxa; i++)
        for(int j = 1; j <= maxb; j++)
            if(a[i] == b[j])
                c[i][j] = c[i-1][j-1] + 1;
            else if(c[i-1][j] > c[i][j-1])
                c[i][j] = c[i-1][j];
            else
                c[i][j] = c[i][j-1];


    fout << c[maxa][maxb] << "\n";


    drum(maxa, maxb);

    return 0;
}
