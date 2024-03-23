#include <iostream>
#define MULT(z,y) f_##z##x
int main(void){
    using namespace std;
    int x =20;
    int myx =4;
    int y =2;
    int f_valuex = 5;
    std::cout <<MULT(value,y);
}

// // C program to illustrate (##) operator 
// #include <stdio.h> 
  
// // Macro definition using the Token-pasting operator 
// #define concat(a, b) a##b 
// int main(void) 
// { 
//     int xy = 30; 
  
//     // Printing the concatenated value of x and y 
//     printf("%d", concat(x, y)); 
    
// }
