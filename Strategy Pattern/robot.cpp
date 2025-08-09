#include<bits/stdc++.h>
using namespace std;

class Walkable{
  public:
  virtual void walk()=0;
  virtual ~Walkable() {}
};

class Talkable{
  public:
  virtual void talk()=0;
  virtual ~Talkable() {}
};

class Flyable{
  public:
  virtual void fly()=0;
  virtual ~Flyable() {}
};

class NormalWalk: public Walkable {
  public:
  void walk() override {
    cout << "Walking normally 🚶"<<endl;
  }
};

class NoWalk: public Walkable {
  public:
  void walk() override {
    cout << "Cannot walk 🚫"<<endl;
  }
};

class NormalTalk: public Talkable {
  public:
  void talk() override {
    cout << "Talking normally 🗣️"<<endl;
  }
};

class NoTalk: public Talkable{
  public:
  void talk() override {
    cout << "Cannot talk" << endl;
  }
};

class NormalFly: public Flyable {
  public:
  void fly() override {
    cout << "Flying normally ✈️"<<endl;
  }
};

class NoFly: public Flyable {
  public:
  void fly() override {
    cout << "Cannot fly" << endl;
  }
};

class Robot {
  protected:
    Walkable* walkBehavior; // HAS-A relationship
    Talkable* talkBehavior; // HAS-A relationship
    Flyable* flyBehavior;   // HAS-A relationship
    public:
    Robot(Walkable* w, Talkable* t, Flyable* f){
        walkBehavior = w;
        talkBehavior = t;
        flyBehavior = f;
    }
    void walk() {
        walkBehavior->walk();
    }
    void talk() {
        talkBehavior->talk();
    }
    void fly() {
        flyBehavior->fly();
    }
    virtual void display() = 0; 
};

class CompanionRobot : public Robot {
  public:
  CompanionRobot(Walkable* w, Talkable* t, Flyable* f) : Robot(w, t, f) {}

  void display() override {
    cout << "I am a Companion Robot 🤖"<<endl;
  }
};

class ServiceRobot : public Robot {
  public:
  ServiceRobot(Walkable* w, Talkable* t, Flyable* f) : Robot(w, t, f) {}

  void display() override {
    cout << "I am a Service Robot 🤖"<<endl;
  }
};

int main(){
    Walkable* normalWalk = new NormalWalk();
    Talkable* normalTalk = new NormalTalk();
    Flyable* normalFly = new NormalFly();

    Walkable* noWalk = new NoWalk();
    Talkable* noTalk = new NoTalk();
    Flyable* noFly = new NoFly();

    Robot* companionRobot = new CompanionRobot(normalWalk, normalTalk, normalFly);
    companionRobot->display();
    companionRobot->walk(); // Walking normally 
    companionRobot->talk(); // Talking normally
    companionRobot->fly();  // Flying normally
    cout << endl;
    Robot* serviceRobot = new ServiceRobot(noWalk, noTalk, noFly);
    serviceRobot->display();
    serviceRobot->walk(); // Cannot walk
    serviceRobot->talk(); // Cannot talk
    serviceRobot->fly();  // Cannot fly
    cout << endl;
    return 0;
}