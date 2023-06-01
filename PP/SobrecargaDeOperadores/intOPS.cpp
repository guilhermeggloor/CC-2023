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

    bool operator ==(const DInt &other) const{//pré - --x
        return (num==other.num);
    }

    bool operator !=(const DInt &other) const{//pré - --x
        return (num!=other.num);
    }

    bool operator <(const DInt &other) const{//pré - --x
        return (num<other.num);
    }

    bool operator >(const DInt &other) const{//pré - --x
        return (num>other.num);
    }

    bool operator <=(const DInt &other) const{//pré - --x
        return (num<=other.num);
    }

    bool operator >=(const DInt &other) const{//pré - --x
        return (num>=other.num);
    }

    bool operator &&(const DInt &other) const {
        return (num&&other.num);
    }

    bool operator ||(const DInt &other) const {
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

   

    DInt a(2), b(2);

    cout << "-----------------------sobrecarga-------------------" << endl;
    b = ++a; cout << b.getInt() << endl;
    b = a++; cout << b.getInt() << endl; cout << a.getInt() << endl;
    b = --a; cout << b.getInt() << endl;
    b = a--; cout << b.getInt() << endl; cout << a.getInt() << endl;
    b = a==b; cout << "é igual: " << b.getInt() << endl; 
    b = a!=b; cout << "é diferente: " <<  b.getInt() << endl;
    b = a<b; cout << "menor que: " << b.getInt() << endl;
    b = a>b; cout << "maior que: " << b.getInt() << endl;
    b = a<=b; cout << "menor igual que: " << b.getInt() << endl;
    b = a>=b; cout << "maior igual que: " << b.getInt() << endl;
    b = a&&b; cout << "a e b: " << b.getInt() << endl;
    b = a||b; cout << "a ou b: " << b.getInt() << endl;
    b = !a; cout << "a diferente de b: " << b.getInt() << endl;
    cout << "---------------------------------------------------" << endl;
        
     
    return 0;
}