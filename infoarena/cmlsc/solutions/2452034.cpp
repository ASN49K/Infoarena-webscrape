#include <bits/stdc++.h>

using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
const int VAL_MAX=1030;
char a[VAL_MAX],b[VAL_MAX];
int size_a,size_b;
vector <char> v[VAL_MAX][VAL_MAX];

vector <char> compar(vector <char> &first,vector <char> &second)
{
    if(first.size()>second.size())
        return first;
    if(first.size()<second.size())
        return second;
    for(int i=0;i<first.size();i++){
        if(first[i]>second[i])
            return first;
        if(first[i]<second[i])
            return second;
    }
    return first;
}

int main()
{
    in>>size_a>>size_b;

    //in>>a+1>>b+1;
    in.get();
    for(int i=1;i<=size_a;i++)
    {
        char c;
        in.get(c);
        a[i]=c;
        in.get();
    }
    for(int i=1;i<=size_b;i++)
    {
        char c;
        in.get(c);
        b[i]=c;
        in.get();
    }
//    for(int i=1;i<=size_a;i++)
//        cout<<a[i];
    //cout<<a<<"\n"<<b<<"\n";
    //size_a=strlen(a+1);
    //size_b=strlen(b+1);
    //cout<<size_a<<"\n"<<size_b<<"\n";
    for(int i=1;i<=size_a;i++)
        for(int j=1;j<=size_b;j++){
            vector <char> act;
            if(a[i]==b[j]){
                act=v[i-1][j-1];
                act.push_back(a[i]);
            }
            act=compar(act,v[i][j-1]);
            act=compar(act,v[i-1][j]);
            v[i][j]=act;
        }
    out<<v[size_a][size_b].size()<<"\n";
    for(int i=0;i<v[size_a][size_b].size();i++)
        out<<v[size_a][size_b][i]<<" ";
    return 0;
}
