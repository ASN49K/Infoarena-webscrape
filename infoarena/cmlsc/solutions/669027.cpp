#include <iostream>
#include <fstream>

using namespace std;

ostream* out = &cout;
istream* in = &cin;

const int NO_PARENT = -666;

struct numData
{
  bool isFound;
  int parent;
  int maxLength;
  int indexInSeq;
};

int fstSize = 0;
int sndSize = 0; 
int* fstArray;
int* sndArray;

void printArray(int* a, int size);

void readArray(int*& array, int& size)
{
  //in >> size;
  array = new int[size];
  for (int i = 0; i < size; i++)
  {

    (*in) >> array[i];

  }
}

void readArrays()
{
  readArray(fstArray, fstSize);
  printArray(fstArray, fstSize);

  readArray(sndArray, sndSize);
  printArray(sndArray, sndSize);
}

void solveCase()
{
  struct numData numDatas[fstSize];  
  // init numData
  for (int i = 0; i < fstSize; i++)
  {
    numDatas[i].isFound = false; 
  }

  int absMaxLength = -1;
  int absParent = -1;
  int absPos = -1;

  for (int i = 0; i < fstSize; i++)
  {
    int parent = -1;
    int maxLength = -1;
    int pos = -1;

    for (int j = 0; j < sndSize; j++)
    {

     if (sndArray[j] == fstArray[i])
      {
        bool foundPrefix = false;
        for (int k = 0; k < i; k++)
        {

          if (numDatas[k].isFound && numDatas[k].indexInSeq < j && numDatas[k].maxLength + 1 > maxLength)
          { 
            maxLength = numDatas[k].maxLength + 1;
            pos = j;
            parent = k;
            foundPrefix = true;
          }            
        }
        if (!foundPrefix)
        {
           pos = j;
        }
      }
    }

      if (pos != -1)
      {
        if (maxLength != -1)
        {
          numDatas[i].parent = parent;
          numDatas[i].maxLength = maxLength;
          numDatas[i].indexInSeq = pos;
          numDatas[i].isFound = true;
        }
        else
        {
          numDatas[i].parent = NO_PARENT;
          numDatas[i].maxLength = 1;
          numDatas[i].indexInSeq = pos;
          numDatas[i].isFound = true;

        }
        if (numDatas[i].maxLength > absMaxLength)
        {
          absMaxLength = numDatas[i].maxLength; 
          absParent = numDatas[i].parent;
          absPos = i;
        }
                 
      }      
      else
      {
        // nothing to do it has not been found in the second seq
      }
  }

  (*out) << absMaxLength << endl;
  int index = absPos;

  if (absMaxLength < 0)
  {
    return;
  }
  int* rev = new int[absMaxLength];
  for (int i = 0; i < absMaxLength; i++)
  {
    rev[absMaxLength - 1 - i] = fstArray[index];
    index = numDatas[index].parent;
  } 

  

  for (int i = 0; i < absMaxLength; i++)
  {
    (*out) << rev[i] << " ";
  } 
  delete[] rev;
}

void printArray(int* a, int size)
{
  for (int i = 0; i < size; i++)
  {
    
    (cout) << a[i] << " ";
  }
  (cout) << endl;
}


int main()
{

  cout << "WTF" << endl;
  int testCases = 1;

  ifstream ifile;
  ifile.open("cmisc.in");
  ofstream ofile;
  ofile.open("cmisc.out");

  out = &ofile;
  in = &ifile;
  (*in) >> fstSize;
  (*in) >> sndSize;

  for (int i = 0; i < testCases; i++)
  {
    readArrays(); 

    solveCase();

  }   

  ofile.close();
	return 0;
}
