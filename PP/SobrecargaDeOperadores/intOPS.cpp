#include <iostream>
using namespace std;

class DInt {
    int num;
public:
    DInt():num(0)
    {}
    DInt(int num): num(num)
    {}
    int getInt() const {
        return num;
    }
    //op adição
    DInt operator +(const DInt &other) const {
        DInt ret(num+other.num);
        return ret;
    }

    DInt operator -(const DInt &other) const {
        DInt ret(num-other.num);
        return ret;
    }

    DInt operator *(const DInt &other) const {
        DInt ret(num*other.num);
        return ret;
    }

    DInt operator /(const DInt &other) const {
        DInt ret(num/other.num);
        return ret;
    }

    DInt operator %(const DInt &other) const {
        DInt ret(num&other.num);
        return ret;
    }

    DInt operator ++() {//pré - ++x
        return DInt(++num);
    }

    DInt operator ++(int) {//pós - x++
        return DInt(num++);
    }

    DInt operator --() {//pré - --x
        return DInt(--num);
    }

    DInt operator --(int) {//pós - x--
        return DInt(num--);
    }

    bool operator ==(const DInt &other) {//pré - --x
        return (num==other.num);
    }

    bool operator !=(const DInt &other) {//pré - --x
        return (num!=other.num);
    }

    bool operator <(const DInt &other) {//pré - --x
        return (num<other.num);
    }

    bool operator >(const DInt &other) {//pré - --x
        return (num>other.num);
    }

    bool operator <=(const DInt &other) {//pré - --x
        return (num<=other.num);
    }

    bool operator >=(const DInt &other) {//pré - --x
        return (num>=other.num);
    }

    bool operator &&(const DInt &other) {
        return (num&&other.num);
    }

    bool operator ||(const DInt &other) {
        return (num||other.num);
    }

    bool operator !() const{
        return (!num);
    }

};

int main() {
    // DInt a(8), b(4), c, d, e, f, g;
    // c = a + b;
    // d = a * b;
    // e = a - b;
    // f = a / b;
    // g = a % b;

    // cout << "soma: " << c.getInt() << endl;
    // cout << "multiplicacao: " << d.getInt() << endl;
    // cout << "subtracao: " << e.getInt() << endl;
    // cout << "divisao: " << f.getInt() << endl;
    // cout << "resto: " << g.getInt() << endl;

    DInt a(1), b(2);
    b = ++a; cout << b.getInt() << endl;
    b = a++; cout << b.getInt() << endl; cout << a.getInt() << endl;
    b = --a; cout << b.getInt() << endl;
    b = a--; cout << b.getInt() << endl; cout << a.getInt() << endl;
    b = a==b; cout << b.getInt() << endl; 
    b = a!=b; cout << b.getInt() << endl;
    b = a<b; cout << b.getInt() << endl;
    b = a>b; cout << b.getInt() << endl;
    b = a<=b; cout << b.getInt() << endl;
    b = a>=b; cout << b.getInt() << endl;
    b = a&&b; cout << b.getInt() << endl;
    b = a||b; cout << b.getInt() << endl;
    b = !a; cout << b.getInt() << endl;       
     
    return 0;
}