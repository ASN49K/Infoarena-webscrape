#include <iostream>
#include <fstream>
#define NRMAX 1050
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");


int n,m;
int a[NRMAX],b[NRMAX];
int LCS[NRMAX][NRMAX];
char unde[NRMAX][NRMAX];


void citire();
void pd();
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

fin>>n>>m;

for(i=1;i<=n;i++)
    fin>>a[i];
for(i=1;i<=n;i++)
    fin>>b[i];

}

void pd()
{
int i,j;



for(i=n;i>0;i--)
    for(j=m;j>0;j--)
        if(a[i]==b[j])
        {
            LCS[i][j]=1+LCS[i+1][j+1];
            unde[i][j]='1';

        }
        else
            if((LCS[i+1][j] >LCS[i][j+1]))
        {
            LCS[i][j]=LCS[i+1][j];
            unde[i][j]='2';
        }
        else
        {
            LCS[i][j]=LCS[i][j+1];
            unde[i][j]='3';
        }

}

void afisare()
{
int i,j;

    fout<<LCS[1][1]<<'\n';

    i=1;j=1;
while(i<=n && j<=m)
    {
     if(unde[i][j]=='1')
        {fout<<a[i]<<' ';i++;j++;}
     else
     if(unde[i][j]=='2')
        i++;
     else
        j++;
    }


}
