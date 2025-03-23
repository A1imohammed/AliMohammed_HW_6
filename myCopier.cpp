#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <source_file> <destination_file>" << endl;
        return 1;
    }
    
    string sourceFile = argv[1];
    string destinationFile = argv[2];

    ifstream source(sourceFile);
    if (!source) {
        cerr << "Error opening source file: " << sourceFile << endl;
        return 1;
    }

   
    ofstream destination(destinationFile);
    if (!destination) {
        cerr << "Error opening destination file: " << destinationFile << endl;
        return 1;
    }

    string line;
  
    while (getline(source, line)) {
        destination << line << endl;  // Write the line to the destination file
    }


    source.close();
    destination.close();

    cout << "File copied successfully from " << sourceFile << " to " << destinationFile << endl;

    return 0;
}



