#include <iostream>

using namespace std;

class Fahrenheit;

class Celsius {
    float temp;

public:
    Celsius(float temp=0.0f): 
        temp(temp)
    {};

    float getTemp() const { 
        return temp;
    }
    
    void setTemp(float temp) {
        this->temp = temp;
    } //pode ser Celsius::temp = temp;
};

class Fahrenheit {
    float temp;

    
public:
    Fahrenheit(float temp = 32.0): 
        temp(temp)
    {};

    Fahrenheit(const Celsius &other) {
        temp = 1.8 * other.getTemp() + 32.0;
    }

    float getTemp() { 
        return temp;
    }

    void setTemp(float temp) {
        this->temp = temp;
    }

    operator Celsius(){
        return Celsius((temp - 32.0)/1.8);
    }

};

int main() {

    Fahrenheit f(100.f);
    Celsius c(37.8f);

    f = c;  //construtor de cópia
    
    cout << "Temperatura em Fahrenheit: " << f.getTemp() << endl;

    f.setTemp(32.0);

    c = f; //operador de casting

    cout << "Temperatura em Celsius: " << c.getTemp() << endl;

    return 0;
}