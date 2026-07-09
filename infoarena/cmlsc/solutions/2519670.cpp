#include <iostream>
#include <fstream>

using namespace std;

int x[1025][1025];
int a[1025],b[1025];
int m,n;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

void tombBe(int *tomb,int hossz){
    for (int i=1;i<=hossz;i++){
        f>>tomb[i];
    }
}

int cmlsc(){
    int maximum=0;
    for (int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if (a[i]==b[j]){
                x[i][j]=x[i-1][j-1]+1;
                if (x[i][j]>maximum){
                    maximum=x[i][j];
                }
            }
            else{
                x[i][j]=max(x[i-1][j],x[i][j-1]);
            }
        }
    }
    return maximum;
}

void visszaKeres(int maximum){
    int tmp[maximum+1];
    int q=maximum;
    for (int i=m;i>0;i--){
        for (int j=n;j>0;j--){
            if (x[i][j]==q&&a[i]==b[j]){
                tmp[q]=a[i];
                q--;
            }
        }
    }
    for (int i=1;i<=maximum;i++){
        g<<tmp[i]<<' ';
    }
    g<<'\n';
}

int main()
{
    int hossz;
    f>>m>>n;
    tombBe(a,m);
    tombBe(b,n);
    hossz=cmlsc();
    g<<hossz<<'\n';
    visszaKeres(hossz);
    return 0;
}
