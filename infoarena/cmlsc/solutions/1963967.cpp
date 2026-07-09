#include <fstream>

using namespace std;
int N,M,i,j,Maxi,A[1025],B[1025],C[1027][1027],Rez[1025],Maxitot,imax,jmax,k;
int main()
{
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");

    fin>>N>>M;
    for(i=1;i<=N;i++)
        fin>>A[i];
    for(i=1;i<=M;i++)
        fin>>B[i];
    Maxitot=0;
    for(i=1;i<=N;i++)
    {
        for(j=1;j<=M;j++)
        {
            if(A[i]==B[j])
                C[i][j]=C[i-1][j-1]+1;
            else
            {
                if(C[i-1][j]>C[i][j-1])
                    Maxi=C[i-1][j];
                else
                    Maxi=C[i][j-1];
                C[i][j]=Maxi;
            }//else
          //  fout<<C[i][j]<<" ";
            if(C[i][j]>Maxitot)
            {
                Maxitot=C[i][j];
                imax=i;
                jmax=j;
            }//if
        }//for j
        //fout<<'\n';
    }//for i
    k=0;
    i=imax;
    j=jmax;
    while(k<Maxitot)
    {
        if(A[i]==B[j])
        {
            k++;
            Rez[k]=A[i];
            i--;
            j--;
        }//if
        else
            if(C[i-1][j]>C[i][j-1])
                i--;
            else
                j--;
    }//while
    fout<<Maxitot<<'\n';
    for(i=Maxitot;i>=1;i--)
        fout<<Rez[i]<<' ';

    fin.close ();
    fout.close();
    return 0;
}
