#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>
using namespace std;

int main() {
    ifstream inputfile("input.txt", ios::binary);

    if (!inputfile) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    uint64_t sum = 0;
    const size_t bufferSize = 1024;
    char buffer[bufferSize];

    // Read and process the file in chunks
    while (inputfile.read(buffer, bufferSize) || inputfile.gcount() > 0) {
        size_t bytesRead = inputfile.gcount();
        for (size_t i = 0; i < bytesRead; ++i) {
            sum += static_cast<unsigned char>(buffer[i]);
        }
    }

    cout << "Total sum of characters: " << sum << endl;

    inputfile.close();
    return 0;
}
