#include <iostream>
#include <fstream>

using namespace std;

class Fraction {
public:
    Fraction(int numerator = 0, int denominator = 1) {
        numerator_ = numerator;
        denominator_ = denominator;
    }


    Fraction operator+( const Fraction& autre) {
        int new_numerator_ = autre.denominator_ * numerator_ + denominator_ * autre.numerator_;
        int new_denominator = autre.denominator_ * denominator_;
        return {new_numerator_, new_denominator};
    }

    Fraction operator-( const Fraction& autre) {
        int new_numerator_ = autre.denominator_ * numerator_ - denominator_ * autre.numerator_;
        int new_denominator = autre.denominator_ * denominator_;
        return {new_numerator_, new_denominator};
    }

    friend Fraction operator+ (int, const Fraction&);
    friend ostream& operator<< (ostream&, const Fraction&);

    int operator[] (int index) {
        if (index == 0){
            return numerator_;
        }
        else {
            return denominator_;
        }
    }

private:
    int numerator_;
    int denominator_;
};

ostream& operator<< (ostream& stream, const Fraction& fraction) {
    return stream << fraction.numerator_ << "/" << fraction.denominator_;
}

Fraction operator+ (int number, const Fraction& fraction) {
    int new_numerator = fraction.numerator_ + number * fraction.denominator_;
    return {new_numerator, fraction.denominator_};
}

int main() {
    Fraction f2(3, 2);
    Fraction f3 = 3 + f2;
    cout << f3 << endl;
    return 0;
}