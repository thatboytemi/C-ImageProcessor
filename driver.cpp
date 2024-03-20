#include "PGMimageProcessor.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
using namespace std;
int main(int argc, char* argv[]){
    int min = stoi(argv[1]);
    int max = stoi(argv[2]);
    int threshold = stoi(argv[3]);
    string filename = argv[4];
    bool P6;
    P6=(strcmp(argv[5], "P6")==0);
    if(P6){
        PGMimageProcessor<Colour>(min, max, threshold, filename);
    }
    else{
        PGMimageProcessor<Gray>(min, max, threshold, filename);
    }
    return 0;
}