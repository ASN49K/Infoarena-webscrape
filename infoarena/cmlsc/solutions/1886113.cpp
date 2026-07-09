#include <iostream>
#include <fstream>

using namespace std;
int n1,n2;
int v[1025];
int w[1025];
int m[1025][1025];
void citire()
{
    ifstream f ("date.in");
    f>>n1>>n2;
    for(int i=1; i<=n1; i++)
    {
        f>>v[i];
        m[0][i]=0;
    }
    for(int i=1; i<=n2; i++)
    {
        f>>w[i];
        m[i][0]=0;
    }
}
void drum(int i,int j)
{
    if(i>0 && j>0)
    {
        if(v[i]==w[j])
        {
            drum(i-1,j-1);
            cerr<<v[i]<<" ";
        }
        else
        {
            if(m[i][j]==m[i][j-1])
                drum(i,j-1);
            else if(m[i][j]==m[i-1][j])
                drum(i-1,j);
        }
    }


}




int main()
{
    citire();
    for(int i=1; i<=n1; i++)
        for(int j=1; j<=n2; j++)
            if(v[i]==w[j])
                m[i][j]=m[i-1][j-1]+1;
            else
                m[i][j]=max(m[i-1][j],m[i][j-1]);
    cerr<<m[n1][n2]<<'\n';
    drum(n1,n2);


    return 0;
}
