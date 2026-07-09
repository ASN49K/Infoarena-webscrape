#include<bits/stdc++.h>
#include<conio.h>
#include <windows.h>
#include<stdlib.h>
#include <ctime>
#include <string.h>
#include <time.h>
using namespace std;
int n,m,i,j,v[30][30],ii,jj;
int di[]={0,0,-1,1};
int dj[]={1,-1,0,0};
vector<pair<int,int> > coada;
void update(int d)
{
    ii+=di[d];
    jj+=dj[d];
}

void boaba()
{
    while(true)
    {
        int i=rand()%n+1;
        int j=rand()%m+1;
        if(v[i][j]==0)
        {
            v[i][j]=3;
            break;
        }
    }
}

int main()
{
    srand(time(0));
    n=5;m=5;int bi=n+2,bj=m+2;
    for(i=0;i<=n+1;i++) v[0][i]=v[n+1][i]=v[i][0]=v[i][n+1]=1;
    ii=(1+n)/2;
    jj=(1+m)/2;
    boaba();
    while(true)
    {
        int aux=v[ii][jj];
        v[ii][jj]=2;
        if(aux==3)
            boaba();
        else if(aux!=0) break;
        else v[bi][bj]=0,bi=ii,bj=jj;
        for(i=0;i<=n+1;i++)
        {
            for(j=0;j<=m+1;j++)
                cout<<v[i][j]<<" ";
            cout<<"\n";
        }
        while(!kbhit());
        char D=getch();
        if(D=='a') update(1);
        if(D=='s') update(3);
        if(D=='d') update(0);
        if(D=='w') update(2);
        FlushConsoleInputBuffer(0);
        //Sleep(100);
        system ("CLS");
    }
    cout<<"Pierdut ai tu acuma";
    cin.ignore();
    return 0;
}
