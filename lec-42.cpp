#include<iostream>
#include<string.h>
using namespace std;

//                                      Oops
/*
class Hero {
    
    // Properties
    private:
        int health;

    public:
        char level;

        // Methods
        int getHealth() {

            return health;
        }
        char getLevel() {

            return level;
        }
        void setHealth(int h) {

            health = h;
        }
        void setLevel(char ch) {

            level = ch;
        }
};
int main(){

    // Creation of Object
    Hero ramesh;   
    cout << "Size of Ramesh is " << sizeof(ramesh) << endl;
    
    // Use setter
    ramesh.setHealth(70);
    // Use getter
    cout << "Ramesh health is " << ramesh.getHealth() << endl;

    ramesh.level = 'A';
    cout << "Level is: " << ramesh.level << endl;
    //                     Or
    // ramesh.setLevel('A');
    // cout << "Level is: " << ramesh.getLevel() << endl; 

    return 0;
}
*/

/*
class Hero {
    
    // Properties
    private:
        int health;

    public:
        char level;

        // Methods
        int getHealth() {

            return health;
        }
        char getLevel() {

            return level;
        }
        void setHealth(int h) {

            health = h;
        }
        void setLevel(char ch) {

            level = ch;
        }
};
int main(){

    // Static Allocation
    Hero a;
    // Using Setters and Getters
    a.setHealth(80);
    a.setLevel('B');
    cout << "level is  " << a.getLevel() << endl;
    cout << " health is " << a.getHealth() << endl;
    //                     Or
    // a.level = 'B';
    // cout << "level is  " << a.level << endl;

    // Dynamicallly
    Hero *b = new Hero;
    // Using Getters and Setters
    b->setLevel('A');
    b->setHealth(70);
    cout << "level is  " << b->getLevel() << endl;
    cout << " health is " << b->getHealth() << endl;
    //                      Or
    // (*b).setLevel('A');
    // (*b).setHealth(70);
    // cout << "level is  " << (*b).getLevel() << endl;
    // cout << " health is " << (*b).getHealth() << endl;
    //                      Or
    // b->level = 'A';
    // cout << "level is " << b->level << endl;  
    //                      Or
    // (*b).level = 'A';
    // cout << "level is " << (*b).level << endl;  

    return 0;
}
*/

/*
class Hero {
    
    // Properties
    private:
        int health;

    public:
        char *name;
        char level;

        Hero() {

            cout << "Simple constructor called" << endl;
        }
        // Paramerterised Constructor
        Hero(int health) {

            this -> health = health;
        }
        Hero(int health, char level) {

            this -> level = level;
            this -> health = health;
        }
        void print(){

            cout << "health: " << this->health << endl;
            cout <<"level: " << this->level << endl;
        }
        int getHealth() {
            return health;
        }
        char getLevel() {
            return level;
        }
        void setHealth(int h) {
            health = h;
        }
        void setLevel(char ch) {
            level = ch;
        }
};
int main(){

    Hero tt;

    // Object Created Statically
    Hero ramesh(10);
    cout << "Address of ramesh " << &ramesh << endl;
    ramesh.print();

    // Object Created Dynamically
    Hero *h =  new Hero(11);
    h->print();

    Hero temp(22, 'B');
    temp.print();

    return 0;
}
*/

//                                  Copy Constructor
/*
class Hero {
    
    // Properties
    private:
        int health;

    public:
        char level;

        Hero() {

            cout << "Simple constructor called" << endl;
        }
        //Paramerterised Constructor
        Hero(int health) {

            this -> health = health;
        }
        Hero(int health, char level) {

            this -> level = level;
            this -> health = health;
        }
        // Copy constructor
        Hero(Hero& temp) {

            cout << "Copy constructor called" << endl;
            this->health = temp.health;
            this->level = temp.level;
        }
        void print(){

            cout << "health: " << this->health << endl;
            cout <<"level: " << this->level << endl;
        }

        int getHealth() {

            return health;
        }
        char getLevel() {

            return level;
        }
        void setHealth(int h) {

            health = h;
        }
        void setLevel(char ch) {

            level = ch;
        }
};
int main(){

    Hero S(70, 'C');
    S.print();

    Hero R(S);
    R.print();

    return 0;
}
*/

//                                   Shallow Copy
/*
class Hero {
    
    // Properties
    private:
        int health;

    public:
        char *name;
        char level;

        Hero() {

            cout << "Simple constructor called" << endl;
            name = new char[100];
        }
        void print(){

            cout << "[Name : " << this->name<< ", ";
            cout << "Health : " << this->health << ", ";
            cout <<"Level : " << this->level << "]";
            cout << endl;
        }
        int getHealth() {

            return health;
        }
        char getLevel() {

            return level;
        }
        void setHealth(int h) {

            health = h;
        }
        void setLevel(char ch) {

            level = ch;
        }
        void setName(char name[]) {

            this->name = name;
        }
};
int main() {

    Hero hero1;

    hero1.setHealth(12);
    hero1.setLevel('D');
    char name[7] = "Babbar";
    hero1.setName(name);

    // Use default copy constructor
    Hero hero2(hero1);
    // Hero hero2 = hero1;
    hero1.print();
    hero2.print();

    hero1.name[0] = 'G';
    hero1.print();
    hero2.print();

    return 0;
}
*/

//                                      Deep Copy
/*
class Hero {
    
    // Properties
    private:
        int health;

    public:
        char *name;
        char level;

        Hero() {

            cout << "Simple constructor called" << endl;
            name = new char[100];
        }
        //copy constructor
        Hero(Hero& temp) {

            char *ch = new char[strlen(temp.name) + 1];
            strcpy(ch, temp.name);
            this->name = ch;

            cout << "Copy constructor called" << endl;
            this->health = temp.health;
            this->level = temp.level;
        }
        void print(){

            cout << "[Name : " << this->name<< ", ";
            cout << "Health : " << this->health << ", ";
            cout <<"Level : " << this->level << "]";
            cout << endl;
        }
        int getHealth() {

            return health;
        }
        char getLevel() {

            return level;
        }
        void setHealth(int h) {

            health = h;
        }
        void setLevel(char ch) {

            level = ch;
        }
        void setName(char name[]) {

            this->name = name;
        }
};
int main() {

    Hero hero1;

    hero1.setHealth(12);
    hero1.setLevel('D');
    char name[7] = "Babbar";
    hero1.setName(name);

    // Use user-defined copy constructor
    Hero hero2(hero1);
    // Hero hero2 = hero1;
    hero1.print();
    hero2.print();

    hero1.name[0] = 'G';
    hero1.print();
    hero2.print();

    return 0;
}
*/

//                              Copy Assignment Operator
/*
class Hero {
    
    // Properties
    private:
        int health;

    public:
        char *name;
        char level;

        Hero() {

            cout << "Simple constructor called" << endl;
            name = new char[100];
        }
        // Copy constructor
        Hero(Hero& temp) {

            char *ch = new char[strlen(temp.name) + 1];
            strcpy(ch, temp.name);
            this->name = ch;

            cout << "Copy constructor called" << endl;
            this->health = temp.health;
            this->level = temp.level;
        }
        void print(){

            cout << "[Name : " << this->name<< ", ";
            cout << "Health : " << this->health << ", ";
            cout <<"Level : " << this->level << "]";
            cout << endl;
        }
        int getHealth() {

            return health;
        }
        char getLevel() {

            return level;
        }
        void setHealth(int h) {

            health = h;
        }
        void setLevel(char ch) {

            level = ch;
        }
        void setName(char name[]) {

            this->name = name;
        }
};
int main() {

    Hero hero1;

    hero1.setHealth(12);
    hero1.setLevel('D');
    char name[7] = "Babbar";
    hero1.setName(name);

    // Use user-defined copy constructor
    Hero hero2(hero1);
    // Hero hero2 = hero1;
    hero1.print();
    hero2.print();

    hero1.name[0] = 'G';
    hero1.print();
    hero2.print();

    hero2 = hero1;
    hero1.print();
    hero2.print();

    return 0;
}
*/

//                                      Destructor
/*
class Hero {
    
    // Properties
    private:
        int health;

    public:
        char level;

        // Methods
        int getHealth() {

            return health;
        }
        char getLevel() {

            return level;
        }
        void setHealth(int h) {

            health = h;
        }
        void setLevel(char ch) {

            level = ch;
        }
        // Destructor
        ~Hero() {   
            cout << "Destructor called" << endl;
        }
};
int main(){

    // Static(destructor called automatically)
    Hero a;

    // Dynamic(destructor called manually)
    Hero *b = new Hero();
    delete b;
}
*/

//                                   Static Keyword
// -> No need to create object
/*
class Hero {
    
    // Properties
    private:
        int health;

    public:
        char *name;
        char level;
        static int timeToComplete;
};
int Hero::timeToComplete = 5;
int main() {

    cout << Hero::timeToComplete << endl;

    Hero a;
    cout << a.timeToComplete << endl;

    Hero b;
    b.timeToComplete = 10 ;

    cout  << a.timeToComplete << endl;
    cout << b.timeToComplete << endl;

    return 0;
}
*/

//                          Static Funtions
// -> No need to create object
// -> Can only access static members
// -> Dont have this keyword
/*
class Hero {
    
    // Properties
    private:
        int health;

    public:
        char *name;
        char level;
        static int timeToComplete;

        // Methods
        int getHealth() {

            return health;
        }
        char getLevel() {

            return level;
        }
        void setHealth(int h) {

            health = h;
        }
        void setLevel(char ch) {

            level = ch;
        }
        static int random() {
            return timeToComplete ;
        }
};
// Initialising
int Hero::timeToComplete; // (Scope Resolution operator -> ::)
int main() {

    cout << Hero::timeToComplete << endl;
    Hero::timeToComplete = 20;
    cout << Hero::random() << endl;

    return 0;
}
*/
