#include <iostream>
#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
unsigned M,N,A[1024],B[1024],C[1024],MAX;
void citire()
{
    f>>M>>N;
    for(int i=1;i<=M;i++)
        f>>A[i];
    for(int j=1;j<=N;j++)
        f>>B[j];
}
void afisare()
{
    for(int i=1;i<=M;i++)
        g<<A[i]<<" ";
    g<<"\n";
    for(int j=1;j<=N;j++)
        g<<B[j]<<" ";
}
void cmls()
{
    int ela,elb;
    for(int i=1;i<=M;i++)
    {
        for(int j=1;j<=M;j++)
        {
        if(A[i]==B[j])
            {
                ela=i;
                elb=j;
                C[MAX]=A[i];
                MAX++;
                break;
            }
        }
    }
    for(int i=ela+1;i<=M;i++)
    {
        for( int j=elb+1;j<=N;j++)
        {
            if(A[i]==B[j])
                {
                    C[MAX]=A[i];
                    MAX++;
                }
        }
    }
    g<<MAX<<"\n";
    for(int i=0;i<MAX;i++)
        g<<C[i]<<" ";



}
int main()
{
 citire();
 cmls();

}
