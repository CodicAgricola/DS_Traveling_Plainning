#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream fin((string("./") + argv[1] + "/matrix.data").c_str());
    
    ofstream outFile;
    outFile.open("result.")
}