#include <iostream>
#include <fstream>

using namespace std;

unsigned long long sumBytesInFile(const string& filePath)
{
    unsigned long long total = 0;
    char byte;

    ifstream file(filePath, ios::binary);
    if (!file.is_open())
    {
        cerr << "Error opening file: " << filePath << endl;
        return 0;
    }

    //cout << "The ASCII values of the characters are: ";

    bool first = true;

    while (file.get(byte))
    {

        if (!first)
        {
            //cout << ", ";
        }
        //cout << static_cast<int>(static_cast<unsigned char>(byte));

        total += static_cast<unsigned char>(byte);

        first = false;
    }

    //cout << "." << endl;
    file.close();

    return total;
}

int main()
{
    string filePath = "input.txt";
    unsigned long long totalSum = sumBytesInFile(filePath);
    cout << "The total sum of all bytes in the file is: " << totalSum << endl;
    return 0;
}
