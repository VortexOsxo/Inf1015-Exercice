#include <iostream>

int main () {
    int** ptr = new int*{new int{3}};
    std::cout << **ptr << std::endl << ptr << "\n\n";

    int* ptr2 = new int[2];
    ptr2[0] = 4; ptr2[1] = 5;
    std::cout << ptr2[0] << "-" << ptr2[1] << "\n\n";

    int** ptr3 = new int*;
    *ptr3 = new int[2];
    *ptr3[0] = 6, *ptr3[1] = 7;
    std::cout << "ptr3: " << ptr3 << std::endl;
    std::cout << "*ptr3: " << *ptr3 << std::endl;
    std::cout << *ptr3[0] << "-" << *ptr3[1] << "\n\n";
    
    int** ptr4 = new int*[2];
    ptr4[0] = new int[2]; ptr4[1] = new int[2];
    ptr4[0][0] = 10; ptr4[0][1] = 11; ptr4[1][0] = 12; ptr4[1][1] = 13;
    std::cout << ptr4[0][0] << "-" << ptr4[0][1] << ptr4[1][0] << "-" << ptr4[1][1] << "\n\n";
    std::cout << "wtf" << std::endl;
    return 0;
}