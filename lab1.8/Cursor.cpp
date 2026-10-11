//cursor.cpp
#include "Cursor.h"
#include<iostream>

using namespace std;
long long Cursor::LongLong::toInt64() const {
    return ((long long)high << 32) | (low & 0xFFFFFFFFULL);
}

Cursor::LongLong Cursor::LongLong::fromInt64(long long val) {
    Cursor::LongLong res;
    res.setHigh((long)(val >> 32));
    res.setLow((unsigned long)(val & 0xFFFFFFFFULL));
    return res;
}

bool Cursor::LongLong::Init(long h, unsigned long l) {
    setHigh(h);
    setLow(l);
    return true;
}

void Cursor::LongLong::Read() {
    long h;
    unsigned long l;
    cout << "  Введіть high (старша частина): ";
    cin >> h;
    cout << "  Введіть low (молодша частина): ";
    cin >> l;
    Init(h, l);
}

std::string Cursor::LongLong::toString() const {
    std::stringstream sout;
    sout << toInt64();
    return sout.str();
}

void Cursor::LongLong::Display() const {
    std::cout << toString();
}

Cursor::LongLong Cursor::LongLong::add(const Cursor::LongLong& r) const {
    return fromInt64(this->toInt64() + r.toInt64());
}

Cursor::LongLong Cursor::LongLong::sub(const Cursor::LongLong& r) const {
    return fromInt64(this->toInt64() - r.toInt64());
}

Cursor::LongLong Cursor::LongLong::mul(const Cursor::LongLong& r) const {
    return fromInt64(this->toInt64() * r.toInt64());
}

Cursor::LongLong Cursor::LongLong::div(const Cursor::LongLong& r) const {
    if (r.toInt64() == 0) {
        cerr << "Помилка: ділення на нуль!\n";
        return fromInt64(0);
    }
    return fromInt64(this->toInt64() / r.toInt64());
}

Cursor::LongLong Cursor::LongLong::mod(const Cursor::LongLong& r) const {
    if (r.toInt64() == 0) {
       cerr << "Помилка: ділення на нуль!\n";
        return fromInt64(0);
    }
    return fromInt64(this->toInt64() % r.toInt64());
}

bool Cursor::LongLong::isGreater(const Cursor::LongLong& r) const { return toInt64() > r.toInt64(); }
bool Cursor::LongLong::isLess(const Cursor::LongLong& r) const { return toInt64() < r.toInt64(); }
bool Cursor::LongLong::isEqual(const Cursor::LongLong& r) const { return toInt64() == r.toInt64(); }
bool Cursor::LongLong::isNotEqual(const Cursor::LongLong& r) const { return toInt64() != r.toInt64(); }

bool Cursor::setX(const Cursor::LongLong& newX) {
    if (newX.toInt64() >= 0) {
        x = newX;
        return true;
    }
   cerr << "Помилка: координата X має бути додатною!\n";
    return false;
}

bool Cursor::setY(const Cursor::LongLong& newY) {
    if (newY.toInt64() >= 0) {
        y = newY;
        return true;
    }
    cerr << "Помилка: координата Y має бути додатною!\n";
    return false;
}

bool Cursor::setView(const std::string& newView) {
    if (newView == "horizontal" || newView == "vertical") {
        view = newView;
        return true;
    }
    cerr << "Помилка: вид має бути 'horizontal' або 'vertical'!\n";
    return false;
}

bool Cursor::setSize(int newSize) {
    if (newSize >= 1 && newSize <= 15) {
        size = newSize;
        return true;
    }
    cerr << "Помилка: розмір курсору повинен бути від 1 до 15!\n";
    return false;
}

bool Cursor::Init(Cursor::LongLong nx, Cursor::LongLong ny, std::string nView, int nSize) {
    visible = true;
    return setX(nx) && setY(ny) && setView(nView) && setSize(nSize);
}

void Cursor::Read() {
    Cursor::LongLong tempX, tempY;
    string tempView;
    int tempSize;

    do {
        cout << "Введення параметрів курсору "<<endl;
        cout << "Введіть координату X:" ;
        tempX.Read();
        cout << "Введіть координату Y:";
        tempY.Read();
        cout << "Введіть вигляд курсору (horizontal/vertical): ";
        cin >> tempView;
        cout << "Введіть розмір курсору (1-15): ";
        cin >> tempSize;
    } while (!Init(tempX, tempY, tempView, tempSize));
}

string Cursor::toString() const {
    stringstream sout;
    sout << "Координата X: " << x.toString()
        << ", Координата Y: " << y.toString()
        << ", Вигляд: " << view
        << ", Розмір: " << size
        << ", Видимий: " << (visible ? "Так" : "Ні");
    return sout.str();
}

void Cursor::Display() const {
    cout << toString() << std::endl;
}

void Cursor::changeCoords(const Cursor::LongLong& nx, const Cursor::LongLong& ny) {
    setX(nx);
    setY(ny);
}

void Cursor::changeView(const std::string& nView) {
    setView(nView);
}

void Cursor::changeSize(int nSize) {
    setSize(nSize);
}

void Cursor::hide() {
    visible = false;
}

void Cursor::restore() {
    visible = true;
}
