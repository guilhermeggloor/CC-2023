#include <iostream>

using namespace std;

class Metro {
    float val;
public:
    Metro(float val=0.0):val(val)
    {}
    float getVal() const {
        return val;
    }
    void setVal(float val) {
        Metro::val = val;
    }
    Metro operator+(const Metro &other) const{
        return Metro(val + other.val);
    }
    Metro operator-(const Metro &other) const{
        return Metro(val - other.val);
    }
    Metro operator++(){
        return Metro(++val);
    }
    Metro operator++(int){
        return Metro(val++);
    }
    bool operator==(const Metro &other) const{
        return val==other.val;
    }
    bool operator!=(const Metro &other) const{
        return val!=other.val;
    }
    bool operator<(const Metro &other) const{
        return val<other.val;
    }
    bool operator<=(const Metro &other) const{
        return val<=other.val;
    }
    bool operator>(const Metro &other) const{
        return val>other.val;
    }
    bool operator>=(const Metro &other) const{
        return val>=other.val;
    }
};
class Milha {
    float val;
    const float MilhaMetros = 1609.34;
public:
    Milha(float val=0.0): val(val){}
    Milha(const Metro &metro){
        val = metro.getVal()/MilhaMetros;
    }
    float getVal() const {
        return val;
    }
    void setVal(float val) {
        Milha::val = val;
    }
    operator Metro() const{
        return Milha(val*MilhaMetros);
    }
};

int main()
{


    return 0;
}