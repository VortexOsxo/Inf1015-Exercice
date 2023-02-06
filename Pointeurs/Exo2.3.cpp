#include <iostream>
#include <vector>
using namespace std;

struct Table {
    float* values;
    int size;
};

Table readInput() {
    cout << "How many values do you have?" << endl;
    int nValues;
    cin >> nValues;
    float* values = new float[nValues];
    for (int i=0; i < nValues; i ++) {
        cin >> values[i];
    }
    return Table{values, nValues};
}

void writeInput(Table table) {
    cout << "I will now post the values you gave me.... \nI know im uselesss" << endl;
    for (int i=0; i < table.size; i++) {
        cout << table.values[i] << endl;
    }
}

int main() {
    Table table = readInput();
    writeInput(table);
    delete[] table.values;
    table.values = nullptr;
    return 0;
}