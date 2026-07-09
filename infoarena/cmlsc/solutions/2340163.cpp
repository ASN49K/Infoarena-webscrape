#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    ifstream infile("test.in");
    ofstream outfile("test.out");
    
    vector<int> rezultat;
    
    int len1, len2, lenR=0;
    int num1, num2;
    
    infile >> len1 >> len2;
    
    int sir1[len1] = {}, sir2[len2] = {};
    
    for(int i=0; i<len1; i++)
    {
        infile >> num1;
        sir1[i] = num1;
    }
    
    for(int i=0; i<len2; i++)
    {
        infile >> num2;
        sir2[i] = num2;
    }
    
    if((len1 > len2) && (len1 >= 1) && (len2 <= 1024) && (lenR > 256))
    {
        for(int l1=0; l1<len1; l1++)
        {
            for(int l2=0; l2<len2; l2++)
            {
                if(sir1[l1] == sir2[l2])
                {
                    rezultat.push_back(sir1[l1]);
                    lenR++;
                }
            }
        }
    }
    
    else if((len1 < len2) && (len1 >= 1) && (len2 <= 1024) && (lenR > 256))
    {
        for(int l2=0; l2<len2; l2++)
        {
            for(int l1=0; l1<len1; l1++)
            {
                if(sir2[l2] == sir1[l1])
                {
                    rezultat.push_back(sir2[l2]);
                    lenR++;
                }
            }
        }
    }
    
    outfile << lenR << endl;
    for(int i=0; i<lenR; i++)
    {
        outfile << rezultat[i] << " ";
    }
    
    infile.close();
    infile.close();

    return(0);
}
