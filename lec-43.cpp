#include<iostream>
using namespace std;

//                                     Encapsulation
/*
class Student {

    private:
        string name;
        int age;
        int height;

    public:
        int getAge() {
            return this->age;
        }
};
int main() {

    Student first;

    cout << "Sab sahi chalra hai" << endl;

    return 0;
}
*/

//                                  Inheritance
/*
class Human {

    public:
        int height;
        int weight;
        int age;

    public:
        int getAge() {

            return this->age;
        }
        void setWeight(int w) {

            this->weight = w;
        }
};
class Male: public Human {

    public:
        string color;

        void sleep() {
            cout << "Male Sleeping" << endl;
        }
};
int main() {

    Male object1;
    cout << object1.age << endl;
    cout << object1.weight << endl;
    cout << object1.height << endl;
    cout << object1.color << endl;

    object1.setWeight(84);
    cout << object1.weight << endl;

    object1.sleep();
    
    return 0;
}
*/

//                              Access Modifiers

// _______________________________________________________________________________________________
// | Base Class member Access Specifier  |  Public          |  Protected       |  Private        |
// |_____________________________________|__________________|__________________|_________________|
// | Public                              |  Public          |  Protected       |  Private        |
// |_____________________________________|__________________|__________________|_________________|
// | Protected                           |  Protected       |  Protected       |  Private        |
// |_____________________________________|__________________|__________________|_________________|
// | Private                             |  Not Accessible  |  Not Accessible  |  Not Accessible |
// |_____________________________________|__________________|__________________|_________________|

//                          Public -> Public = Public
/*
class Human {

    public:
        int height;
        int weight;

    private:
        int age;

    public:
        int getAge() {

            return this->age;
        }
        void setWeight(int w) {

            this->weight = w;
        }
};
class Male: public Human {

    public:
        string color;

        void sleep() {
            cout << "Male Sleeping" << endl;
        }
        int getHeight() {
            return this->height;
        }
};
int main() {

    Male m1;
    cout << m1.height << endl;

    return 0;
}
*/

//                          Public -> Protected = Protected
/*
class Human {

    public:
        int height;
        int weight;

    private:
        int age;

    public:
        int getAge() {

            return this->age;
        }
        void setWeight(int w) {

            this->weight = w;
        }
};
class Male: protected Human {

    public:
        string color;

        void sleep() {
            cout << "Male Sleeping" << endl;
        }
        int getHeight() {
            return this->height;
        }
};
int main() {

    Male m1;
    cout << m1.getHeight() << endl;
    // Error
    // cout << m1.height << endl;

    return 0;
}
*/

//                          Public -> Private = Private
/*
class Human {

    public:
        int height;
        int weight;

    private:
        int age;

    public:
        int getAge() {

            return this->age;
        }
        void setWeight(int w) {

            this->weight = w;
        }
};
class Male: private Human {

    public:
        string color;

        void sleep() {
            cout << "Male Sleeping" << endl;
        }
        int getHeight() {
            return this->height;
        }
};
int main() {

    Male m1;
    cout << m1.getHeight() << endl;
    // Error
    // cout << m1.height << endl;

    return 0;
}
*/

//                          Protected -> Public = Protected
/*
class Human {

    protected:
        int height;
    
    public:
        int weight;

    private:
        int age;

    public:
        int getAge() {

            return this->age;
        }
        void setWeight(int w) {

            this->weight = w;
        }
};
class Male: public Human {

    public:
        string color;

        void sleep() {
            cout << "Male Sleeping" << endl;
        }
        int getHeight() {
            return this->height;
        }
};
int main() {

    Male m1;
    cout << m1.getHeight() << endl;
    // Error
    // cout << m1.height << endl;

    return 0;
}
*/

//                          Protected -> Protected = Protected
/*
class Human {

    protected:
        int height;
    
    public:
        int weight;

    private:
        int age;

    public:
        int getAge() {

            return this->age;
        }
        void setWeight(int w) {

            this->weight = w;
        }
};
class Male: protected Human {

    public:
        string color;

        void sleep() {
            cout << "Male Sleeping" << endl;
        }
        int getHeight() {
            return this->height;
        }
};
int main() {

    Male m1;
    cout << m1.getHeight() << endl;
    // Error
    // cout << m1.height << endl;

    return 0;
}
*/

//                          Protected -> Private = Private
/*
class Human {

    protected:
        int height;
    
    public:
        int weight;

    private:
        int age;

    public:
        int getAge() {

            return this->age;
        }
        void setWeight(int w) {

            this->weight = w;
        }
};
class Male: private Human {

    public:
        string color;

        void sleep() {
            cout << "Male Sleeping" << endl;
        }
        int getHeight() {
            return this->height;
        }
};
int main() {

    Male m1;
    cout << m1.getHeight() << endl;
    // Error
    // cout << m1.height << endl;

    return 0;
}
*/

//                          Private -> Public = Not Accessible
/*
class Human {

    private:
        int height;
    
    public:
        int weight;

    private:
        int age;

    public:
        int getAge() {

            return this->age;
        }
        void setWeight(int w) {

            this->weight = w;
        }
};
class Male: public Human {

    public:
        string color;

        void sleep() {
            cout << "Male Sleeping" << endl;
        }
        // Error
        int getHeight() {
            return this->height;
        }
};
int main() {

    Male m1;
    // Error
    // cout << m1.height << endl;

    return 0;
}
*/

//                          Private -> Protected = Not Accessible
/*
class Human {

    private:
        int height;
    
    public:
        int weight;

    private:
        int age;

    public:
        int getAge() {

            return this->age;
        }
        void setWeight(int w) {

            this->weight = w;
        }
};
class Male: protected Human {

    public:
        string color;

        void sleep() {
            cout << "Male Sleeping" << endl;
        }
        // Error
        int getHeight() {
            return this->height;
        }
};
int main() {

    Male m1;
    // Error
    // cout << m1.height << endl;

    return 0;
}
*/

//                          Private -> Private = Not Accessible
/*
class Human {

    private:
        int height;
    
    public:
        int weight;

    private:
        int age;

    public:
        int getAge() {

            return this->age;
        }
        void setWeight(int w) {

            this->weight = w;
        }
};
class Male: private Human {

    public:
        string color;

        void sleep() {
            cout << "Male Sleeping" << endl;
        }
        // Error
        int getHeight() {
            return this->height;
        }
};
int main() {

    Male m1;
    // Error
    // cout << m1.height << endl;

    return 0;
}
*/

//                                 Single Inheritance
/*
class Animal {

    public:
        int age;
        int weight;

        void speak() {
            cout << "Speaking " << endl;
        }
};
class Dog: public Animal {

};
int main() {

    Dog d;
    d.speak();
    cout << d.age << endl;

    return 0;
}
*/

//                               Multi-level inheritance
/*
class Animal {

    public:
        int age;
        int weight;

        void speak() {
            cout << "Speaking " << endl;
        }
};
class Dog: public Animal {

};
class GermanShepherd: public Dog {

};
int main() {

    GermanShepherd g;
    g.speak();

    return 0;
}
*/

//                                 Multiple Inheritance
/*
class Animal {

    public:
        int age;
        int weight;

        void bark() {
            cout << "Barking " << endl;
        }
};
class Human {

    public:
        string color;

        void speak() {
            cout << "Speaking " << endl;
        }
};
class Hybrid: public Animal, public Human {

};
int main() {

    Hybrid obj1;
    obj1.speak();
    obj1.bark();

    return 0;
}
*/

//                              Hierarchical Inheritance
/*
class A {

    public:
        void func1() {
            cout << "Inside Function 1" << endl;
        }
};
class B: public A {

    public:
        void func2() {
            cout << "Inside Function 2" << endl;
        }
};
class C: public A {

    public:
        void func3() {
            cout << "Inside Funcion 3" << endl;
        }
};
int main() {

    A object1;
    object1.func1();

    B object2;
    object2.func1();
    object2.func2();

    C object3;
    object3.func1();
    object3.func3();

    return 0;
}
*/

//                              Hybrid Inheritance
//                           (Hierarchical + Multiple)
/*
class A {

    public:
        void funcA() {
            cout << "Inside Function A" << endl;
        }
};
class D {

    public:
        void funcD() {
            cout << "Inside Function D" << endl;
        }
};
class B: public A {

    public:
        void funcB() {
            cout << "Inside Function B" << endl;
        }
};
class C: public A, public D {

    public:
        void funcC() {
            cout << "Inside Funcion C" << endl;
        }
};
int main() {

    A object1;
    object1.funcA();

    B object2;
    object2.funcA();
    object2.funcB();

    C object3;
    object3.funcA();
    object3.funcC();
    object3.funcD();

    D object4;
    object4.funcD();

    return 0;
}
*/

//                                 Ambiguity inheritance
/*
class A {

    public:
        void func() {
            cout << " I am A" << endl;
        }
};
class B {

    public:
        void func() {
            cout << " I am B" << endl;
        }
};

class C: public A, public B {

};
int main() {

    C obj;
    // Error
    // obj.func();

    obj.A::func() ;
    obj.B::func();

    return 0;
}
*/

//                                  Polymorphism

//                          1. Compile time Polymorphism
//                                     (Static)

//                              1. Function Overloading
/*
class A {

    public:
        void sayHello() {
            cout << "Hello" << endl;
        }  
        int sayHello(char name) {
            cout << "Hello " << name << endl;
            return 1;
        }
        void sayHello(string name) {
            cout << "Hello " << name  << endl;
        }
};
int main(){

    A obj;
    obj.sayHello();
    obj.sayHello('B');
    obj.sayHello("Babbar");

    return 0;
}
*/

//                              2. Operator Overloading
/*
class B {

    public:
        int a;
        int b;

        int add() {
            return a+b;
        }
        void operator+ (B &obj) {
            int value1 = this -> a;
            int value2 = obj.a;
            cout << "output " << value2 - value1 << endl; 
            cout << "Hello Babbar" << endl;
        }
        void operator() () {
            cout << "main Bracket hu " << this->a << endl;
        }
};
int main() {

    B obj1, obj2;

    obj1.a = 4;
    obj2.a = 7;

    obj1 + obj2;
    obj1();

    return 0;
}
*/

//                                 2. Runtime Polymorphism
//                                         (Dynamic)

//                                   1. Method Overriding
/*
class Animal {

    public:
        void speak() {
            cout << "Speaking "<< endl;
        }
};

class Dog: public Animal {

    public:
        void speak() {
            cout << "Barking " << endl;
        }
};
int main() {

    Dog obj;
    obj.speak();
}
*/