#include <iostream>

using std::cout;
using std::endl;

enum BREED {GOLDEN, BB, CC, DD};

struct Mammal {
public:
    Mammal() : itsAge(2), itsWeight(5) {}
    // Mammal(int age) : itsAge(age), itsWeight(5); // 不用指定列表
    Mammal(int age);
    ~Mammal() {}

    int GetAge() const { return itsAge; }
    void SetAge(int age) { itsAge = age; }
    int GetWeight() { return itsWeight; }
    void SetWeight(int weight) { itsWeight = weight; }

    void CallFunc (int ccc) { sleep(); }

    void speak() const { cout << "Mammal sound!" << endl; }
    void sleep() const { cout << "Shhh. I'm sleeping." << endl; }

// private:
protected:
    int itsAge;
    int itsWeight;
};

struct Dog: public Mammal {
public:
    Dog() : itsBreed(GOLDEN) {}
    ~Dog() {}
    BREED GetBreed() const { return itsBreed; }
    void WagTail() { cout << "Wagging Tail..." << endl; }

protected:
    BREED itsBreed;
};

Mammal::Mammal(int age) : itsAge(age), itsWeight(5) {
    itsAge = age;
}


int main(int argc, char* argv[]) {
    Mammal amam;
    amam.speak();

    Mammal m2(7);
    m2.speak();
    cout << m2.GetAge() << endl;
    m2.SetAge(8);
    cout << m2.GetAge() << endl;
    m2.CallFunc(3);

    cout << "ccccccccc" << endl;
    Dog adog;
    adog.speak();
    cout << adog.GetBreed() << endl;;
    adog.WagTail();
}
