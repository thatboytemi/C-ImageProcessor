#include "PGMimageProcessor.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <queue>
#include <limits.h>
namespace ANXTEM001{
    // //Constructors
    // template <typename T> PGMimageProcessor<T>::PGMimageProcessor():filename("birds.pgm"){}
    // template <typename T> PGMimageProcessor<T>::PGMimageProcessor(const PGMimageProcessor<T> & other):identifier(other.identifier), imageWidth(other.imageWidth), imageHeight(other.imageHeight), filename(other.filename){
    //     components.clear();
    //     for(std::vector<std::unique_ptr<ConnectedComponent>>::const_iterator pointer = components.begin(); pointer!=components.end();++pointer){
    //         components.push_back(std::unique_ptr<ConnectedComponent>(new ConnectedComponent(**pointer)));
    //     }
    // }
    // template <typename T> PGMimageProcessor<T>::PGMimageProcessor(PGMimageProcessor<T> && other):identifier(other.identifier), imageWidth(other.imageWidth), imageHeight(other.imageHeight), filename(std::move(other.filename)), components(std::move(other.components)){
    //     //leaving other object in destructable state
    //     other.identifier = 0;
    //     other.imageHeight =0;
    //     other.imageWidth =0;
    // }
    // template <typename T> PGMimageProcessor<T> & PGMimageProcessor<T>::operator=(const PGMimageProcessor<T> & other){
    //     if (this!=&other){
    //         identifier = other.identifier;
    //         imageWidth = other.imageWidth;
    //         imageHeight = other.imageHeight;
    //         filename = other.filename;
    //         components.clear();
    //         for(std::vector<std::unique_ptr<ConnectedComponent>>::const_iterator pointer = components.begin(); pointer!=components.end();++pointer){ 
    //             components.push_back(std::unique_ptr<ConnectedComponent>(new ConnectedComponent(**pointer)));
    //         }
    //     }
        
    //     return (*this);
    // }
    // template <typename T> PGMimageProcessor<T> & PGMimageProcessor<T>::operator=(PGMimageProcessor<T> && other){
    //     if(this!=&other){
    //         identifier = other.identifier;
    //         imageWidth = other.imageWidth;
    //         imageHeight = other.imageHeight;
    //         filename = std::move(other.filename);
    //         components = std::move(other.components);
    //         other.identifier = 0;
    //         other.imageHeight =0;
    //         other.imageWidth =0;
    //     }
    //     return (*this);
    // }
    // template <typename T> PGMimageProcessor<T>::PGMimageProcessor(std::string filename):filename(filename){}
    // //No implementation needed since auto vars are used
    // template <typename T> PGMimageProcessor<T>::~PGMimageProcessor() = default;
    // //functions that enable me to get the intensity of current pixel (during iteration over image)
    // unsigned char getIntensity(Colour & colour){
    //     return 0.299*colour.pixels[0] + 0.587*colour.pixels[1] +0.114*colour.pixels[2];
    // }
    // unsigned char getIntensity(Gray gray){
    //     return gray;
    // }

    // void setColour(Colour & colour, unsigned char newColour){
    //     colour.pixels[0]=newColour;
    //     colour.pixels[1]=newColour;
    //     colour.pixels[2]=newColour;
    // }
    // void setColour(Gray & gray, unsigned char colour){
    //     gray=colour;
    // }
    // template<typename T> int PGMimageProcessor<T>::extractComponents(unsigned char threshold, int minValidSize){
    //     int offset = 1;
    //     if(typeid(T)==typeid(Colour)){
    //         offset =3;
    //     }
    //     T * image = readFile(filename,offset);
    //     int widthVal = imageWidth;
    //     int heightVal = imageHeight;
    //     int numEntries = widthVal * heightVal;
    //     //to avoid revisting pixel in BFS, will have to set pixel value to zero. Thus if the threshold value is zero, have to handle this case separately.
    //     if(threshold==0){
    //         std::unique_ptr<ConnectedComponent> pointer(new ConnectedComponent(identifier++)); 
    //         for (int i = 0; i < heightVal; i++){
    //             for (int j = 0; j < widthVal; j++){
    //                 pointer->addToCoordinates(std::pair{i,j});
    //             }
    //         }
    //         if(pointer->getNumPixels()>=minValidSize){
    //             components.push_back(std::move(pointer));
    //         }
    //         return components.size();
    //     }

    //     //extracting components
    //     std::vector<std::pair<int, int>> directions {{1,0}, {0,1}, {-1,0},{0,-1}};
    //     for (int i = 0; i < heightVal; i++){
    //         for (int j = 0; j < widthVal; j++){
    //             unsigned char intensity;
    //             intensity = getIntensity(image[(i*widthVal)+j]);
    //             if(intensity>=threshold){
    //                 std::unique_ptr<ConnectedComponent> pointer(new ConnectedComponent(identifier++)); 
    //                 pointer->addToCoordinates(std::pair{i,j});
    //                 std::queue<std::pair<int, int>> queue;  
    //                 queue.push({i, j});
    //                 setColour(image[(i*widthVal)+j],0);
    //                 while(!queue.empty()){ //BFS
    //                     std::pair<int, int> pair = queue.front();      
    //                     queue.pop();
    //                     for(std::pair<int, int> dir: directions){
    //                         int row = pair.first + dir.first;
    //                         int col = pair.second + dir.second;
    //                         if((0<=row && row <heightVal && col>=0 && col <widthVal)){ //checking if pixel is within the bounds of image
    //                             intensity = getIntensity(image[(row*widthVal)+col]);
    //                             if(intensity>=threshold){
    //                                 pointer->addToCoordinates(std::pair{row,col});
    //                                 queue.push({row, col});
    //                                 setColour(image[(row*widthVal)+col], 0);
    //                             }
    //                         }
    //                     } 
    //                 }
    //                 if(pointer->getNumPixels()>=minValidSize){
    //                     components.push_back(std::move(pointer));
    //                 }
    //             }   
    //         }    
    //     }
    //     delete [] image;
    //     return components.size();
    // }

    // template<typename T> bool PGMimageProcessor<T>::writeComponents(const std::string & outFileName){
    //     std::string extenstion = ".pgm";
    //     if(typeid(T)==typeid(Colour)){
    //         extenstion =".ppm";
    //     }
    //     std::string filename = outFileName+ extenstion;
    //     std::ofstream outputFile;
    //     outputFile.open(filename, std::ios::binary);
    //     if (!outputFile.is_open()) { 
    //         std::cout << "File open failed!";
    //         return false;
    //     }
    //     std::string filetype = "P5";
    //     if(typeid(T)==typeid(Colour)){
    //         filetype="P6";
    //     }
    //     outputFile << filetype <<  "\n" <<"#Generated by ANXTEM001" << "\n" << std::to_string(imageWidth) + " " + std::to_string(imageHeight) << "\n" << "255" <<"\n";
    //     int dimensions = imageWidth*imageHeight;
    //     T* outputImage = new T [dimensions];
    //     //iterate through all pixels in output image making all pixels initially black
    //     for (int i = 0; i < imageHeight; i++)
    //     {
    //         for (int j = 0; j < imageWidth; j++)
    //         {
    //             setColour(outputImage[(i*imageWidth)+j], 0);
    //         }
            
    //     }
    //     //overwrite black pixels to white if contained in a component
    //     //using iterators to iterate through all components and then iterate through all pixels in component to overwrite component pixels to white
    //     for (std::vector<std::unique_ptr<ConnectedComponent>>::const_iterator i = components.begin(); i!=components.end(); ++i)
    //     {
    //         for (std::vector<std::pair<int, int>>::const_iterator j = (*i)->begin(); j!=(*i)->end(); ++j)
    //         {
    //             setColour(outputImage[j->first*imageWidth+j->second],255);
    //         }
    //     }
    //     int offset =1;
    //     if(typeid(T)==typeid(Colour)){
    //         offset =3;
    //     }
    //     outputFile.write((char*) (outputImage), dimensions*offset);
    //     outputFile.close();
    //     delete [] outputImage;
    //     return true;
    // }


    // template<> bool PGMimageProcessor<Gray>::writeBorder(const std::string & outFileName){
    //     int widthVal = imageWidth;
    //     int heightVal = imageHeight;
    //     int numEntries = widthVal * heightVal;
    //     Gray * image = readFile(filename,1);
    //     Colour * colourImage = new Colour[numEntries];
    //     for (int i = 0; i < heightVal; i++){
    //         for (int j = 0; j < widthVal; j++){
    //             colourImage[i*widthVal+j].pixels[0]=image[i*widthVal+j];
    //             colourImage[i*widthVal+j].pixels[1]=image[i*widthVal+j];
    //             colourImage[i*widthVal+j].pixels[2]=image[i*widthVal+j];
    //         }
    //     }
    //     delete [] image;
    //     //Creation of Green Border
    //     for (std::vector<std::unique_ptr<ConnectedComponent>>::const_iterator i = components.begin(); i!=components.end(); ++i){
    //         int yMin = (*i)->yMin;
    //         int yMax = (*i)->yMax;
    //         int xMin = (*i)->xMin;
    //         int xMax = (*i)->xMax;
    //         for(int j = (*i)->xMin; j<=(*i)->xMax; j++){
    //             int offset = yMin*widthVal+j;
    //             colourImage[offset].pixels[0]= 0;
    //             colourImage[offset].pixels[1]= 255;
    //             colourImage[offset].pixels[2]= 0;
    //         }
    //         for(int j = (*i)->xMin; j<=(*i)->xMax; j++){
    //             int offset = yMax*widthVal+j;
    //             colourImage[offset].pixels[0]= 0;
    //             colourImage[offset].pixels[1]= 255;
    //             colourImage[offset].pixels[2]= 0;
    //         }
    //         for(int j = (*i)->yMin; j<=(*i)->yMax; j++){
    //             int offset = j*widthVal+xMin;
    //             colourImage[offset].pixels[0]= 0;
    //             colourImage[offset].pixels[1]= 255;
    //             colourImage[offset].pixels[2]= 0;
    //         }
    //         for(int j = (*i)->yMin; j<=(*i)->yMax; j++){
    //             int offset = j*widthVal+xMax;
    //             colourImage[offset].pixels[0]= 0;
    //             colourImage[offset].pixels[1]= 255;
    //             colourImage[offset].pixels[2]= 0;
    //         }
    //     }
    //     std::string filename = outFileName+".ppm";
    //     std::ofstream outputFile;
    //     outputFile.open(filename, std::ios::binary);
    //     if (!outputFile.is_open()) { 
    //         std::cout << "File open failed!";
    //         return false;
    //     }
    //     std::string filetype = "P6";
    //     outputFile << filetype <<  "\n" <<"#Generated by ANXTEM001" << "\n" << std::to_string(imageWidth) + " " + std::to_string(imageHeight) << "\n" << "255" <<"\n";
    //     outputFile.write((char*) colourImage, numEntries*3);
    //     outputFile.close();
    //     delete [] colourImage;
    //     return true;
    // }

    template<> bool PGMimageProcessor<Colour>::writeBorder(const std::string & outFileName){
        Colour * colourImage = readFile(filename, 3);
        int widthVal = imageWidth;
        //Creation of Green Border
        for (std::vector<std::unique_ptr<ConnectedComponent>>::const_iterator i = components.begin(); i!=components.end(); ++i){
            int yMin = (*i)->yMin;
            int yMax = (*i)->yMax;
            int xMin = (*i)->xMin;
            int xMax = (*i)->xMax;
            for(int j = (*i)->xMin; j<=(*i)->xMax; j++){
                int offset = yMin*widthVal+j;
                colourImage[offset].pixels[0]= 0;
                colourImage[offset].pixels[1]= 255;
                colourImage[offset].pixels[2]= 0;
            }
            for(int j = (*i)->xMin; j<=(*i)->xMax; j++){
                int offset = yMax*widthVal+j;
                colourImage[offset].pixels[0]= 0;
                colourImage[offset].pixels[1]= 255;
                colourImage[offset].pixels[2]= 0;
            }
            for(int j = (*i)->yMin; j<=(*i)->yMax; j++){
                int offset = j*widthVal+xMin;
                colourImage[offset].pixels[0]= 0;
                colourImage[offset].pixels[1]= 255;
                colourImage[offset].pixels[2]= 0;
            }
            for(int j = (*i)->yMin; j<=(*i)->yMax; j++){
                int offset = j*widthVal+xMax;
                colourImage[offset].pixels[0]= 0;
                colourImage[offset].pixels[1]= 255;
                colourImage[offset].pixels[2]= 0;
            }
        }
        std::string filename = outFileName+".ppm";
        std::ofstream outputFile;
        outputFile.open(filename, std::ios::binary);
        if (!outputFile.is_open()) { 
            std::cout << "File open failed!";
            return false;
        }
        std::string filetype = "P6";
        outputFile << filetype <<  "\n" <<"#Generated by ANXTEM001" << "\n" << std::to_string(imageWidth) + " " + std::to_string(imageHeight) << "\n" << "255" <<"\n";
        outputFile.write((char*) colourImage, imageWidth*imageHeight*3);
        outputFile.close();
        delete [] colourImage;
        return true;
    }

    template <typename T> T* PGMimageProcessor<T>::readFile(const std::string filename, int offset){
        std::ifstream myfile;
        std::string str;
        std::string width;
        std::string height;
        myfile.open(filename, std::ios::binary);
        if (!myfile.is_open()) { 
            std::cout << "File open failed!";
            return nullptr;
        }
        std::getline(myfile, str); //read first line 
        while(getline(myfile, str)){ 
            if(str[0]!='#'){
                std::istringstream s(str);
                s >> width >> height;
                break;
            }
        }
        getline(myfile, str); //read last line before binary block (255)
        int widthVal = stoi(width);
        int heightVal = stoi(height);
        imageWidth = widthVal;
        imageHeight = heightVal;
        int numEntries = widthVal * heightVal;
        T * image = new T[numEntries];
        myfile.read((char*)(image),numEntries*offset);
        myfile.close();
        return image;
    }

    template<typename T>  int PGMimageProcessor<T>::getLargestSize(void) const{
        int max =0;
        for (std::vector<std::unique_ptr<ConnectedComponent>>::const_iterator i = components.begin(); i!=components.end(); ++i){
            if((*i)->getNumPixels()>max){
                max = (*i)->getNumPixels();
            }
        }
        return max;
    }

    template<typename T> int PGMimageProcessor<T>::getSmallestSize(void) const{
        int min = INT_MAX;
        for (std::vector<std::unique_ptr<ConnectedComponent>>::const_iterator i = components.begin(); i!=components.end(); ++i){
            if((*i)->getNumPixels()<min){
                min = (*i)->getNumPixels();
            }
        }
        return min;
    }
    template<typename T> void PGMimageProcessor<T>::printComponentData(const ConnectedComponent & theComponent) const{
        std::stringstream stream;
        stream << "Component ID: " << theComponent.getIdentifier() << " Number of Pixels: " << theComponent.getNumPixels()<<"\n";
        std::cout << stream.str();
    }

    template<typename T> int PGMimageProcessor<T>::filterComponentsBySize(int minSize, int maxSize){
        for (std::vector<std::unique_ptr<ConnectedComponent>>::const_iterator i = components.begin(); i!=components.end();){
            if((*i)->getNumPixels()<minSize || (*i)->getNumPixels()> maxSize){
                components.erase(i);
            }
            else{
                ++i;
            }
        }
        return components.size();
    }

    template<typename T> void PGMimageProcessor<T>::getString(){
        if (components.size()>0){
            for (int i = 0; i < components.size(); i++)
            {
                printComponentData(*components[i]);
            }
            std::cout << "Total number of components: " << getComponentCount() <<std::endl;
            std::cout << "Size of largest component: " <<getLargestSize() <<std::endl;
            std::cout << "Size of smallest component: " <<getSmallestSize() <<std::endl;
        }
    }
    template<typename T> int PGMimageProcessor<T>::getComponentCount() const{
        return components.size();
    }

    //explicitly stating how class will be templated for compilation purposes
    template class PGMimageProcessor<Colour>;
    template class PGMimageProcessor<Gray>;
}
