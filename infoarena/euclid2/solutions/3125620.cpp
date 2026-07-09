#include <fstream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int s[100],n;
int valid(int k)
{
    int i;
    for(i=1; i<k; i++)
        if(s[i]==s[k])
            return 0;
    return 1;
}
void tipar(int k)
{
    int i;
    for(i=1; i<=k; i++)
        g<<s[i]<<" ";
    g<<endl;
}
void back(int k)
{
    int i;
    for(i=1; i<=n; i++)
    {
        s[k]=i;
        if(valid(k))
            if(k==n)
                tipar(k);
            else back(k+1);
    }
}
int main()
{
    f>>n;
    back(1);
    return 0;
}

