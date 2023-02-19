#include <iostream>
class Fraction {
public:
    Fraction(int numerator = 0, int denominator = 1) {
        numerator_ = numerator;
        denominator_ = denominator;
    }

    void afficherFraction() {
        std::cout << numerator_ << "/" << denominator_ << std::endl;
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

private:
    int numerator_;
    int denominator_;
};

Fraction operator+ (int number, const Fraction& fraction) {
    int new_numerator = fraction.numerator_ + number * fraction.denominator_;
    return {new_numerator, fraction.denominator_};
}

int main() {
    Fraction f2(3, 2);
    Fraction f3 = 3 + f2;
    f3.afficherFraction();
    return 0;
}