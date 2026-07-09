#include <fstream>
using namespace std;
int n,x,c,smax,y,t,m;
void quicksort(int v[],int p[],int st,int dr)
{
    if(st < dr)
    {
        int m = (st+dr)/2;
        swap(v[st],v[m]);
        swap(p[st],p[m]);
        int i = st, j = dr, d = 0;
        while(i < j)
        {
            if(v[i] > v[j])
            {
                swap(v[i], v[j]);
                swap(p[i], p[j]);
                d = 1 - d;
            }
            i+= d;
            j -= 1-d;
        }
        quicksort(v,p, st, i-1);
        quicksort(v,p, i+1, dr);
    }
}

int bin(int v[],int p[], int st, int dr, int x)
{
    while(st <= dr)
    {int m = (st + dr)/2;
        if(v[m] == x)
            return p[m];
        if(x > v[m])
            st = m +1;
        else
            dr = m - 1;
    }
    return 0;
}
int main()
{
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");
    fin >> n >> m;
    int i,j,v1[1025],v2[1025],p1[1025],p2[1025],k = 0;
    for(i =1 ; i <=n; i++)
    {
        fin >> v1[i];
        p1[i] = i;
    }
    quicksort(v1,p1, 1, n);
    for(i =1 ; i <=m; i++)
    {
        fin >> y;
        c = bin(v1, p1, 1, n, y);
        if(c)
            if(k == 0)
            {
                v2[++k] = y;
                p2[k] = c;
            }
            else if(c > p2[k])
            {
                v2[++k] = y;
                p2[k] = c;
            }
    }
    fout << k  << "\n";
    for(i =1 ; i <=k; i++)
    {
        fout << v2[i] << " ";
    }

    return 0;
}
