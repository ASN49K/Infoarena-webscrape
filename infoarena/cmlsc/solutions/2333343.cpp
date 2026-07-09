#include <iostream>
#include<fstream>
#include<string>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int*first;
int l1;
int*second;
int l2;
void lcs(int*first,int*last,int l1,int l2)
{
    int freq[l1+1][l2+1];
    for(int i=0; i<=l1; i++)
    {
        for(int k=0; k<=l2; k++)
        {
            if(!i||!k)
            {
                freq[i][k]=0;
            }
            else if(first[i-1]==last[k-1])
            {
                freq[i][k]=freq[i-1][k-1]+1;
            }
            else
            {
                freq[i][k]=max(freq[i-1][k],freq[i][k-1]);
            }
        }
    }
    int x=l1,y=l2;
    int a[10000];
    int p=0;
    out<<freq[x][y]<<endl;
    while(x&&y)
    {
        if(first[x-1]==second[y-1])
        {
            a[p]=first[x-1];
            p++;
            x--;
            y--;
        }
        else
        {
            if(freq[x-1][y]>=freq[x][y-1])
            {
                x--;
            }
            else
                y--;
        }
        //cout<<x<<" "<<y<<endl;
    }
    for(int i=p-1; i>=0; i--)
        out<<a[i]<<" ";

}
void citire()
{
    in>>l1>>l2;
    first=new int[l1];
    second=new int[l2];
    int i;
    for(i=0; i<l1; i++)
        in>>first[i];
    for(i=0; i<l2; i++)
        in>>second[i];
}
int main()
{
    citire();
    lcs(first,second,l1,l2);
}
