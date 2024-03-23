#include <iostream>
#include <string>
#include <memory>
class Sample{
    private:
        int y=0;
    public:
        int x;
        Sample(int x=1){
            std::cout <<"Default\n";
        }
        Sample(const Sample& other){
            std::cout << "copy constructed" << std::endl;
            x = other.x;
        }
        Sample(Sample&& other){
            std::cout << "move constructed" << std::endl;
            x = other.x;
        }
        Sample& method(const Sample& sample){
            return *this;
        }
        // Sample method(Sample&& sample){
        //     std::cout << "r";
        //     Sample x;
        //     return x;
        // }
        Sample& operator=(const Sample& sample)
        {
            (*this).x= sample.x;
            std::cout << "copied" << std::endl;
            return *this;
        }
        Sample& operator=(Sample&& sample)
        {
            std::cout << "moved"<< std::endl;
            return *this;
        }
       
};
 void myMethod(int & num){
    num = 2;
}
main(void){
    // int a[] = {1,2,3};
    // std::cout << &a <<std::endl;
    // std::cout << a <<std::endl;
    // std::cout << &a[0] <<std::endl;
    // std::cout << &a[1] <<std::endl;
    Sample x;
//    Sample *y = new Sample;
//    x.method(Sample());
    // int ** arr;
    // arr = new int*[2];
    // // create array
    // for(int i=0;i<2;i++)
    // arr[i] = new int[3];
    // int* row1 = *arr;
    // *row1 =1;
    // *(row1+1) = 5;
    // *(row1+2) = 2;
    // int* row2 = *(arr+1);
    // *row2 =1;
    // *(row2+1) = 3;
    // *(row2+2) = 7;
    // //*(arr+4)= *(arr+4)+5;
    // arr[1][1]+=5;
    // std::cout << arr[1][1];
    // int  *ptr, *ptr2;
    // //*ptr =5;
    // std::cout << ptr<<std::endl;
    // std::cout << ptr2<<std::endl;

}
