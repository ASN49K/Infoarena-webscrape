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
    string freq2[l1+1][l2+1];
    for(int i=0; i<=l1; i++)
    {
        for(int k=0; k<=l2; k++)
        {
            if(!i||!k)
            {
                freq[i][k]=0;
                freq2[i][k]="";
            }
            else if(first[i-1]==last[k-1])
            {
                freq[i][k]=freq[i-1][k-1]+1;
                if(freq2[i-1][k-1]!="")
                    freq2[i][k]=freq2[i-1][k-1]+" "+to_string(first[i-1]);
                else
                    freq2[i][k]=to_string(first[i-1]);
            }
            else
            {
                if(freq[i-1][k]>=freq[i][k-1])
                {
                    freq[i][k]=freq[i-1][k];
                    freq2[i][k]=freq2[i-1][k];
                }
                else
                {
                    freq[i][k]=freq[i][k-1];
                    freq2[i][k]=freq2[i][k-1];

                }
            }
        }
    }
    out<<freq[l1][l2]<<endl;
    string result=freq2[l1][l2];
    out<<result<<endl;

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
