#include <iostream>
#include <fstream>
#include <bitset>
/* This function opens a binary file, reads each byte, and prints its binary representation.
Opens the file filename in binary read mode. Reads each byte into char c, casts it to std::bitset<8>(c)
to get an 8-bit binary string representation, and prints it with a space between each byte.
Closes the file after reading. */
void printBitSequenceFromFile(std::string filename) {
    std::fstream fhand(filename, std::ios::binary | std::ios::in); // Open file in binary read mode

    char c;
    while (fhand.read(reinterpret_cast<char*>(&c), sizeof(c))) {  // Read each byte from file
        std::cout << std::bitset<8>(c) << " "; // Print each byte as an 8-bit binary sequence
    }
    std::cout << std::endl;
    fhand.close(); // Close file
}
/* The main function prints a, b, and c to the console to show the initial values being written to the file.
Opens the file data.bin in binary write mode with trunc flag to clear any existing contents.
Writes the binary representation of a, b, and c to the file using fhand.write and reinterpret_cast<char*>
to interpret each variable as a sequence of bytes. Closes the file after writing.

Calls printBitSequenceFromFile(<filename>), which reads each byte from data.bin and prints its binary representation.
This provides a bit-level view of the file contents. Declares variables d, e, and f to store the values read back from the file.
Opens data.bin in binary read mode.

Reads each variable back from the file in the same order they were written, storing the results in d, e, and f.
Closes the file after reading.
Prints the values of d, e, and f to verify that the original values were written and read correctly from the binary file. */
int main() {
    std::string filename = "data.bin"; // File name to store binary data
    signed int a = -10000; // Signed integer value
    unsigned short b = 100; // Unsigned short integer value
    const char c[] = "WE"; // Character array
    const size_t str_size = sizeof(c); // Size of character array including null terminator

    std::cout << "Encoding values:" << std::endl;
    std::cout << a << std::endl; // Print integer a
    std::cout << b << std::endl; // Print unsigned short b
    std::cout << c << std::endl; // Print character array c

    std::fstream fhand;
    fhand.open(filename, std::ios::binary | std::ios::trunc | std::ios::out); // Open file in binary write mode and truncate
    fhand.write(reinterpret_cast<char*>(&a), sizeof(a)); // Write integer a as binary data
    fhand.write(reinterpret_cast<char*>(&b), sizeof(b)); // Write unsigned short b as binary data
    fhand.write(c, str_size); // Write character array c as binary data
    fhand.close(); // Close file after writing

    std::cout << "Bit sequence in the file: " << std::endl;
    printBitSequenceFromFile(filename); // Call function to print binary bit sequence from file

    signed int d; // Variable to read back integer a
    unsigned short e; // Variable to read back unsigned short b
    char f[str_size]; // Array to read back character array c
    fhand.open(filename, std::ios::binary | std::ios::in); // Open file in binary read mode
    fhand.read(reinterpret_cast<char*>(&d), sizeof(d)); // Read integer a from file
    fhand.read(reinterpret_cast<char*>(&e), sizeof(e)); // Read unsigned short b from file
    fhand.read(f, str_size); // Read character array c from file

    std::cout << "Decoded values:" << std::endl;
    std::cout << d << std::endl; // Print decoded integer d
    std::cout << e << std::endl; // Print decoded unsigned short e
    std::cout << f << std::endl; // Print decoded character array f
    fhand.close(); // Close file after reading
}

