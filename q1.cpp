#include<iostream>
#include<fstream>
using namespace std;
bool copyfile(const string& sourceFile,const string& destFile)
{
  ifstream input(sourceFile,ios::in);
  ofstream output(destFile,ios::out);
  if(!input.is_open()||!output.is_open())
  {
    cout<<"Error in opening files"<<endl;
    return false;
  }
  string line;
  while(getline(input,line))
  {
    output<<line<<endl;
  }
  cout<<"file copied successfully"<<endl;
  return true;
}
int main()
{
  copyfile("input.txt","output.txt");
}
