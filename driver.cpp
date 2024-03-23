#include "PGMimageProcessor.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <limits.h>
using namespace std;
using namespace ANXTEM001;
int main(int argc, char* argv[]){
    int min = 3;
    int max = INT_MAX;
    int threshold = 128;
    bool print = false;
    bool write = false;
    bool border = false;
    string borderName;
    string filename = argv[argc-1];
    string outFileName;
    bool colour = filename.find(".ppm") != std::string::npos;
    for (int i = 0; i < argc; i++)
    {
        if (strcmp(argv[i], "-s")==0){
            min = stoi(argv[++i]);
            max = stoi(argv[++i]);
            continue;
        }
        if(strcmp(argv[i], "-t")==0){
            threshold = stoi(argv[++i]);
            if(!(threshold>=0 &&threshold<=255)){
                std::cout << "Threshold must be between 0 and 255!";
                return 1;
            }
            continue;
        }
        if(strcmp(argv[i], "-w")==0){
            outFileName = argv[++i];
            write  = true;
            continue;
        }
        if(strcmp(argv[i], "-p")==0){
            print = true;
            continue;
        }
        if(strcmp(argv[i], "-b")==0){
            border = true;
            borderName = argv[++i];
            continue;
        }
    } 
    if(colour){
        PGMimageProcessor<Colour> processor(filename);
        processor.extractComponents(threshold, min);
        processor.filterComponentsBySize(min, max);
        if (write) processor.writeComponents(outFileName);
        if (print) processor.getString();
        if (border) processor.writeBorder(borderName);
    }
    else{
        PGMimageProcessor<Gray> processor(filename);
        processor.extractComponents(threshold, min);
        processor.filterComponentsBySize(min, max);
        if (write) processor.writeComponents(outFileName);
        if (print) processor.getString();
        if (border) processor.writeBorder(borderName);
    }
    
    return 0;
}