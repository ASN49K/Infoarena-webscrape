#include <iostream>
#include <fstream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");


int main()
{
    int n1,n2;
    fin>>n1>>n2;
    vector<int> x1(n1+1), x2(n2+1);
    int j,i;
    for(i=1;i<=n1;i++)
    {
        fin>>x1[i];
    }
    for(i=1;i<=n1;i++)
    {
        fin>>x2[i];
    }
    sort(x1.begin()+1,x1.end());
    sort(x2.begin()+1,x2.end());

    j=1;
    i=1;
    vector<int> o;
    while(i<=n1 && j<=n2)
    {
        if(x1[i]==x2[j])
        {
            o.push_back(x1[i]);
            i++;
            j++;
        }
        else
        if(x1[i]>x2[j]) j++;
        else
        i++;
    }
    cout<<o.size()<<"\n";
    for(auto &e : o) cout<<e<<" ";

}
