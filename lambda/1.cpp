#include <iostream>
#include <string>
#include <functional>

using namespace std;

struct employé {
    string nom;
    int salaire;
};

class entreprise {
public:
    entreprise(employé t1, employé t2, employé t3) {
        employés[0] = t1;
        employés[1] = t2;
        employés[2] = t3;
    }

    employé find(const function<bool(employé)>& critere) {
        for (int i = 0; i < 3; i++) {
            if (critere(employés[i])) {
                return employés[i];
            }
        }
        return employés[0];
    }

    employé employés[3];
};

int main() {
    employé t1 = {"Bobby", 100};
    employé t2 = {"Fisher", 150};
    employé t3 = {"Robbert", 500};
    entreprise e1 = {t1, t2, t3};
    t1 = e1.find([](auto e) {return e.salaire >= 250;});
    std::cout << t1.nom;
    return 0;
}