#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void encode(const string& str, const string& outFile) {
    ofstream outfile(outFile);
    if (!outfile) {
        cerr << "Error: Cannot open output file '" << outFile << "'" << endl;
        return;
    }

    for (char ch : str) {
        outfile << (int)ch;
    }
    outfile << endl;
    outfile.close();
    cout << "Encoding complete. Output written to " << outFile << endl;
}

void decode(const string& str, const string& outFile) {
    ofstream outfile(outFile);
    if (!outfile) {
        cerr << "Error: Cannot open output file '" << outFile << "'" << endl;
        return;
    }

    int num = 0;
    for (char ch : str) {
        num = num * 10 + (ch - '0');
        if (num >= 32 && num <= 122) {
            outfile << (char)num;
            num = 0;
        }
    }
    outfile << endl;
    outfile.close();
    cout << "Decoding complete. Output written to " << outFile << endl;
}

int main(int argc, char* argv[]) {
    if (argc != 5) {
        cerr << "Usage: " << argv[0] << " <-e | -d> <input.txt> -f <output.txt>" << endl;
        return 1;
    }

    string option = argv[1];
    string inputFile = argv[2];
    string fileFlag = argv[3];
    string outputFile = argv[4];

    if (fileFlag != "-f") {
        cerr << "Error: Missing -f flag for output file." << endl;
        return 1;
    }

    ifstream infile(inputFile);
    if (!infile) {
        cerr << "Error: Cannot open input file '" << inputFile << "'" << endl;
        return 1;
    }

    string content((istreambuf_iterator<char>(infile)), istreambuf_iterator<char>());
    infile.close();

    if (option == "-e") {
        encode(content, outputFile);
    } else if (option == "-d") {
        decode(content, outputFile);
    } else {
        cerr << "Invalid option. Use -e to encode or -d to decode." << endl;
        return 1;
    }

    return 0;
}
