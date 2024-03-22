#include "ConnectedComponent.h"
#include <algorithm> //for min and max (see line 41)
//constructors
ConnectedComponent::ConnectedComponent():identifier(0){}
ConnectedComponent::ConnectedComponent(const ConnectedComponent & other):identifier(other.identifier){
    coordinates = other.coordinates;
}
ConnectedComponent::ConnectedComponent(ConnectedComponent && other):identifier(other.identifier), coordinates(std::move(other.coordinates)){
    other.identifier =0;
}
ConnectedComponent& ConnectedComponent::operator=(const ConnectedComponent & rhs){
    if(this!=&rhs){
        identifier = rhs.identifier;
        coordinates = rhs.coordinates;
    }
    return *this;
}
ConnectedComponent& ConnectedComponent::operator=(ConnectedComponent && rhs){
    if(this!=&rhs){
        identifier = rhs.identifier;
        rhs.identifier = 0;
        coordinates = std::move(rhs.coordinates);
    }
    return *this;
}
 
//no implementation needed since auto vars are used
ConnectedComponent::~ConnectedComponent()=default;
ConnectedComponent::ConnectedComponent(int identifier): identifier(identifier){
    numPixels = 0;
}
int ConnectedComponent::getNumPixels() const{
    return numPixels;
}
int ConnectedComponent::getIdentifier() const{
    return identifier;
}
void ConnectedComponent::addToCoordinates(std::pair<int, int> && coordinate){
    numPixels++;
    coordinates.push_back(coordinate);
    xMin = std::min(coordinate.second, xMin);
    xMax = std::max(coordinate.second, xMax);
    yMin = std::min(coordinate.first, yMin);
    yMax = std::max(coordinate.first, yMax);
}
std::vector<std::pair<int, int>>::const_iterator ConnectedComponent::begin(){
    return coordinates.begin();
}
std::vector<std::pair<int, int>>::const_iterator ConnectedComponent::end(){
    return coordinates.end();
}