# C++ Assignment 3

## Author: Temi Aina

This program reads in an image (which can be a .pgm/.ppm file) and extracts all foreground components of the image with a pixel value that is higher than the user-supplied threshold.

## Class Structure

To make this program, I created 2 classes:

### 1) Connected Component

This class contains all the information on a component of an image such as its size (number of pixels), its identifier, and a vector of pairs called "coordinates" which stores the position of all the pixels which belong to the component.

### 2) PGMimageProcessor

This class does all the heavy work. It has methods to read in the image, extract all the components from the image(storing only those above a minimum size), filter components by size, create an output where all stored component pixels are white (everything else is black). It also contains methods to get infomation about the components like getLargestSize() and getSmallestSize() which returns the number of pixels in the largest and smallest components. There is also a method called printCompnentData() which prints all the information about the components.

## File Structure

There are 5 files needed for the runnning of this program:

### 1) driver.cpp

This file contains the main function which is the entry point into this program.

### 2) PGMimageProcessor.h

This file contains the class declarations for the PGMimageProcessor class.

### 3) ConnectedComponent.h

This file contains the class declarations for the ConnectedComponent class.

### 4) PGMimageProcessor.cpp

This file contains implementation of the PGMimageProcessor class.

### 5) PGMimageProcessor.cpp

This file contains implementation of the ConnectedComponent class.

### Additional File: tester.cpp

There is an additional class called tester which contains unit tests for the main functions implemented in PGMimageProcessor.cpp.

## How To Run This Program

To compile this program, type "make" ensuring that you are within the folder which contains the Makefile.

To run this program, type "./driver -s <int> <int> {sets the minimum and maximum valid components size [min default = 3, max = unlimited]} -t <int> {sets the threshold, must be between 0-255(inclusive of bounds), default = 128} -b <outPGMfile> {writes original image to output file with green border to show the detected components}  -p {prints out component data} -w <outFileName> {writes output image to a file} <inputImageName>"
For example "./driver -s 10 10000 -b borderImage -t 50 -w outputFile -p Birds.pgm". 
ONLY ADD THE .pgm/.ppm EXTENSION WHEN SPECIFYING THE NAME OF THE INPUT IMAGE! 
What you should expect when running the example input are files called outputFile.pgm and borderImage.ppm to be created as well as console output showing the component data.
Failure to adhere to this structure will cause an error to be thrown.

You can use an image manipulation tool like GIMP to view the output images.

## How To run Tests

To compile the test file, type "make test" ensuring that you are within the folder which contains the Makefile. 
To run the tests type "./tester".