#include <iostream>
#include <tuple>

void readNote(int result[], int size) {
    std::cout << "Entrez les dix valeurs des juges" << std::endl;
    for (int i = 0; i < size; i ++) {
        std::cin >> result[i];
    }
}

std::tuple<int, int> findMinMax(int result[], int size) {
    int min = result[0], max = result[0];
    for (int i = 1; i < size; i ++) {
        if (result[i] > max) {
            max = result[i];
        }
        else if (result[i] < min) {
            min = result[i];
        }
    }
    return std::tuple(min, max);
}

void findMinMax(int result[], int size, int& min, int&max) {
    min = result[0], max = result[0];
    for (int i = 1; i < size; i ++) {
        if (result[i] > max) {
            max = result[i];
        }
        else if (result[i] < min) {
            min = result[i];
        }
    }
}

int resultSum(int result[], int size, int min, int max) {
    int sum = -(min + max);
    for (int i = 0; i < size; i ++) {
        sum += result[i];
    }
    return sum;
}

int main() {
    const int resultNb = 10;
    int results[resultNb];
    readNote(results, resultNb);

    int min, max;
    findMinMax(results, resultNb, min, max);
    int sum = resultSum(results, resultNb, min, max);
    std::cout << sum << std::endl;
    
}