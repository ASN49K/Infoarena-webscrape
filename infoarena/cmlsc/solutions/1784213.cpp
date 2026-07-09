#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int a[1005],b[1005],m[1005][1005],w[1005];

int main()
{
    ifstream fin ("cmlsc.in");
    ofstream fout("cmlsc.out");

    int i,j;
    int n_a,n_b,max_i,max_j,maxx=0;

    fin>>n_a>>n_b;

    for(i=1;i<=n_a;i++)
        fin>>a[i];

    for(i=1;i<=n_b;i++)
        fin>>b[i];

    for(j=1;j<=n_a;j++){
        for(i=1;i<=n_b;i++){
            if(a[j]==b[i]){
                m[i][j]=m[i-1][j-1]+1;
                if(maxx<m[i][j]){
                    max_i=i,max_j=j;
                    maxx=m[i][j];
                }

            }else{
                m[i][j]=max(m[i-1][j],m[i][j-1]);

            }
        }
    }

//    for(i=1;i<=n_b;i++){
//        for(j=1;j<=n_a;j++)
//            fout<<m[i][j]<<" ";
//        fout<<"\n";
//    }

    i=max_i,j=max_j;

//    cout<<i<<j;
    int q=0;

    while(i!=0 && j!=0){
        if(a[j]==b[i]){
             w[++q]=a[j];
             i--;j--;
        }

        else{
            int maxx=max(m[i-1][j],m[i][j-1]);
            if(maxx==m[i-1][j])
                i--;
            else
                j--;
        }
    }

    reverse(w+1,w+q+1);

    fout<<q<<"\n";

    for(i=1;i<=q;i++)
        fout<<w[i]<<" ";


    return 0;
}
