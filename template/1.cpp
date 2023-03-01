#include <iostream>
#include <string>

template <typename T, int N>
class Array {
public:
    Array(T donnée[]) {
        for (int i = 0; i < N; i ++){
            _donnée[i] = donnée[i];
        }
    }

    void afficher() {
        for (int i=0; i<N;i++) {
            std::cout << _donnée[i] << std::endl;
        }
    }
private:
    T _donnée[N];
};

int main() {
    int a[3] = {1,2,3};
    Array<int, 3> arr{a};
    arr.afficher();
    return 0;
}