#include <iostream>
#include <string>
using namespace std;

// class MoveStrategy {
// public:
//     virtual void move() = 0; // pure virtual
//     virtual ~MoveStrategy() {}
// };

// class DriveStrategy : public MoveStrategy {
// public:
//     void move() override {
//         cout << "Driving on the road 🚗" << endl;
//     }
// };

// class FlyStrategy : public MoveStrategy {
// public:
//     void move() override {
//         cout << "Flying in the sky ✈️" << endl;
//     }
// };

// class SailStrategy : public MoveStrategy {
// public:
//     void move() override {
//         cout << "Sailing in the water ⛵" << endl;
//     }
// };

// class Vehicle {
// private:
//     MoveStrategy* strategy; // HAS-A relationship
// public:
//     Vehicle(MoveStrategy* s) : strategy(s) {}

//     // void setStrategy(MoveStrategy* s) { // change at runtime
//     //     strategy = s;
//     // }

//     void performMove() { // delegate
//         strategy->move();
//     }
// };
// int main() {
//    MoveStrategy* drive = new DriveStrategy();
//     MoveStrategy* fly = new FlyStrategy();
//     MoveStrategy* sail = new SailStrategy();
//     Vehicle myCar(drive);
//     myCar.performMove(); // Driving on the road 🚗

//     Vehicle myPlane(fly);
//     myPlane.performMove(); // Flying in the sky ✈️

//     Vehicle myBoat(sail);
//     myBoat.performMove(); // Sailing in the water ⛵

//     return 0;
// }

class MoveStrategy{
    public:
    virtual void move()=0;
    virtual ~MoveStrategy() {}
};

class Drive :public MoveStrategy {
    public:
    void move() override {
        cout << "Driving on the road 🚗"<<endl;
    }
};

class Fly :public MoveStrategy {
    public:
    void move() override {
        cout << "Flying in the sky ✈️"<<endl;
    }
};

class Vechile {
    MoveStrategy* strategy; 
    public:
    Vechile(MoveStrategy* s){
        strategy = s;
    }

    void performMove() {
        strategy->move();
    }
};

int main() {
    MoveStrategy*  d=new Drive();
    MoveStrategy*  f=new Fly();
    Vechile myCar(d);
    Vechile myPlane(f);
    myCar.performMove();
    myPlane.performMove();
    return 0;
}
    
