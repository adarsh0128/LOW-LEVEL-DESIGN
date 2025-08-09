### Strategy Design Pattern

#### The Main Problem

The Main Problem
You are building a program for different vehicles:
Cars
Airplanes
Boats
Bicycles

If you put all movement logic in one Vehicle class like this:

<!--
class Vehicle {
public:
    void move() {
        if (type == "Car") cout << "Drive on the road";
        else if (type == "Plane") cout << "Fly in the air";
        else if (type == "Boat") cout << "Sail in water";
    }
}; -->

#### You face problems:

Too many if-else → code is messy and hard to read.
Adding new movement means changing old code → breaks the Open/Closed Principle.
Mixing vehicle data and logic → violates Single Responsibility Principle.
Cannot change movement of just one vehicle at runtime.

#### What is the Strategy Pattern? (Simple definition)

A Strategy Pattern is simply:

Putting different behaviors in separate classes and making them interchangeable.
You remove the "movement" code from the Vehicle class.
You put it into strategy classes like DriveStrategy, FlyStrategy, SailStrategy.
The Vehicle has-a strategy (composition).
You can swap strategies anytime without changing the Vehicle code.

#### How Strategy Pattern Solves the Problem

Without Strategy Pattern:
Vehicle decides how to move (messy).

With Strategy Pattern:
Vehicle just says: “Hey strategy, you handle the moving.”
Each strategy knows its own way of moving.
Adding a new movement type is just creating a new strategy class — no old code changes needed.

#### step-by-Step Example in C++

##### Step 1 — Define the Strategy Interface

<!-- #include <iostream>
#include <string>
using namespace std;

class MoveStrategy {
public:
    virtual void move() = 0; // pure virtual
    virtual ~MoveStrategy() {}
}; -->

This is like a contract — every movement type must have a move() function.

##### Step 2 — Create Concrete Strategies

<!-- class DriveStrategy : public MoveStrategy {
public:
    void move() override {
        cout << "Driving on the road 🚗" << endl;
    }
};

class FlyStrategy : public MoveStrategy {
public:
    void move() override {
        cout << "Flying in the sky ✈️" << endl;
    }
};

class SailStrategy : public MoveStrategy {
public:
    void move() override {
        cout << "Sailing in the water ⛵" << endl;
    }
}; -->

##### Step 3 — Create the Context Class (Vehicle)

<!-- class Vehicle {
private:
    MoveStrategy* strategy; // HAS-A relationship
public:
    Vehicle(MoveStrategy* s) : strategy(s) {}

    void setStrategy(MoveStrategy* s) { // change at runtime
        strategy = s;
    }

    void performMove() { // delegate
        strategy->move();
    }
}; -->

##### Step 4 — Use It

<!-- int main() {
    DriveStrategy drive;
    FlyStrategy fly;
    SailStrategy sail;

    Vehicle myCar(&drive);
    myCar.performMove(); // Driving on the road 🚗

    myCar.setStrategy(&fly);
    myCar.performMove(); // Flying in the sky ✈️

    myCar.setStrategy(&sail);
    myCar.performMove(); // Sailing in the water ⛵

    return 0;
} -->

##### Benefits

Benefits
Open/Closed Principle → Add new movement types without touching old code.
Single Responsibility → Vehicle handles only vehicle-related work, movement is separate.
Flexibility → Can change movement at runtime.
Reusability → Same movement strategy can be used by different classes.

#### When to Use

When you have many ways to do one thing (like moving).
When you want to avoid long if-else or switch statements.
When you want to easily add new behaviors without breaking old code.
When you want to change behavior while the program is running.
