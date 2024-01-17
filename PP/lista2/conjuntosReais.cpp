#include <iostream>
#include <stdexcept>

using namespace std;

class Real {
    double value;
public:
    Real(double value) : value(value) {}

    double getValue() const {
        return value;
    }

    virtual void validate() const {
        
    }
};

class Natural : public Real{
public:
    Natural(double value) : Real(value) {
        validate();
    }

    void validate() const override {
        if (getValue <0 || getValue() != static_cast<int>(getValue())) {
            throw invalid_argument("Esse valor não é um numero natural! ");
        }
    }

};

class Integer : public Real {
public: 
    Integr(double value) : Real(value) {
        validate();
    }

    void validate() const override {
        if (getValue != static_cast<int>(getValue())) {
            throw invalid_argument("Esse valor não é um numero inteiro! ");
        }
    }
};

int main(){

    return 0;
}