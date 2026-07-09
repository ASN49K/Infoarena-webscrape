
#include<iostream>
#include<fstream>
#include<queue>

using namespace std;

ifstream f("clms.in");
ofstream g("clms.out");

int *a, *b;
int n,m;
void afisare(int *x, int dim)
{
    int i;
    for(i=0;i<dim;i++)
        cout<<x[i]<<" ";
    cout<<endl;
}
void validare()
{


}
void backtracking(int k)
{

}
int gasit(int x)
{
    for(int l=0;l<n;l++)
        if(x==b[l])
            return l;
    return -1;
}
int cautam(int poz, int val)
{
     for(int l=poz;l<n;l++)
        if(val==b[l])
            return l;
    return -1;

}
int main()
{
    queue<int> Q, finalSolution;
    int i,j,k;
    int sol[256];
    int finalSol[256];


    f>>m>>n;

     a = new int[m+1];
     b = new int[n+1];

    for(i=0;i<m;i++)
        f>>a[i];
    for(j=0;j<n;j++)
        f>>b[j];

    cout<<m<<" "<<n<<endl;
    afisare(a,m);
    afisare(b,n);

    for(int p=0; p<m; p++)
    {
        int index = gasit(a[p]);
        if(index!= -1)
        {
            //elementul p din A se afla si in B
            j=index;

            Q.push(b[index]);//add element b[index] to the potential solution
            for(k=p+1; k<m; k++)
            {
                index = cautam(j+1,a[k]);//search for the next element
                if(index != -1)
                {//cautam mai departe
                    Q.push(b[index]);
                    j=index;

                }
            }
            if(Q.size() > finalSolution.size())
            {
                finalSolution = Q;
            }

            while(Q.size()!=0)
                Q.pop();
        }
    }

    g<<finalSolution.size()<<endl;
    while(finalSolution.size())
    {
        int x = finalSolution.front();
        cout<<x<<" ";
        g<<x<<" ";
        finalSolution.pop();
    }
    return 0;
}
