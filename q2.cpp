#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main()
{
  ifstream inputFile("input.txt");
  int res,sum=0;
  char ch;
  while(inputFile.get(ch))
  {
    unsigned char c=static_cast<unsigned char>(ch);
    res=static_cast<int>(c);
    sum=sum+res;
  }
  cout<<"The sum is:"<<sum<<endl;
}
