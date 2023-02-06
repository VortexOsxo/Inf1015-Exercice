#include <iostream>
#include <vector>
using namespace std;

vector<float> readInput() {
    cout << "How many values do you have?" << endl;
    vector<float> values;
    int nValues;
    cin >> nValues; 
    for (int i=0; i < nValues; i ++) {
        float value;
        cin >> value;
        values.push_back(value);
    }
    return values;
}

void writeInput(vector<float> values) {
    cout << "I will now post the values you gave me.... \nI know im uselesss" << endl;
    for (float value: values) {
        cout << value << endl;
    }
}

int main() {
    writeInput(readInput());
    return 0;
}