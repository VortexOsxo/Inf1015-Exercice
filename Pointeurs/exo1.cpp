#include <iostream>
void f(int* p) {
    *p = 6;
    p = new int(7);
};

void g(int*& p) {
    *p = 9;
    p = new int(10);
};

int main() {
    int* x = new int;
    *x = 3;
    std::cout << *x << std::endl;
    int* y = x;
    std::cout << *y << std::endl;
    *y = 4;
    std::cout << *x << std::endl;
    int* z = new int(*x);
    *x = 5;
    std::cout << *x << " " << *z << std::endl;
    f(x);
    std::cout << *x << " " << *y << std::endl;
    g(x);
    std::cout << *x << " " << *y << std::endl;

}
//Copie le int pointé par 'x' dans une nouvelle mémoire allouée dynamiquement et conserve le pointeur 'z'.