#include<bits/stdc++.h>
using namespace std;

class Burger {
  public:
  virtual void prepare() = 0;
  virtual ~Burger() {}
};

class BasicBurger : public Burger {
  public:
  void prepare() override {
    cout << "Preparing Basic Burger" << endl;
  }
};

class StandardBurger : public Burger {
  public:
  void prepare() override {
    cout << "Preparing Standard Burger" << endl;
  }
};

class PremiumBurger : public Burger {
  public:
  void prepare() override {
    cout << "Preparing Premium Burger" << endl;
  }
};

class BasicWheatBurger : public Burger {
  public:
  void prepare() override {
    cout << "Preparing Basic Wheat Burger" << endl;
  }
};

class StandardWheatBurger : public Burger {
  public:
  void prepare() override {
    cout << "Preparing Standard Wheat Burger" << endl;
  }
};

class PremiumWheatBurger : public Burger {
  public:
  void prepare() override {
    cout << "Preparing Premium Wheat Burger" << endl;
  }
};

class Bread {
  public:
  virtual void prepare() = 0;
  virtual ~Bread() {}
};

class BasicBread : public Bread {
  public:
  void prepare() override {
    cout << "Preparing Basic Bread" << endl;
  }
};

class CheeseBread : public Bread {
  public:
  void prepare() override {
    cout << "Preparing Cheese Bread" << endl;
  }
};

class GarlicBread : public Bread {
  public:
  void prepare() override {
    cout << "Preparing Garlic Bread" << endl;
  }
};

class BasicWheatBread : public Bread {
  public:
  void prepare() override {
    cout << "Preparing Basic Wheat Bread" << endl;
  }
};

class CheeseWheatBread : public Bread {
  public:
  void prepare() override {
    cout << "Preparing Cheese Wheat Bread" << endl;
  }
};

class GarlicWheatBread : public Bread {
  public:
  void prepare() override {
    cout << "Preparing Garlic Wheat Bread" << endl;
  }
};

class MealFactory {
  public:
  virtual Burger* createBurger(string &type) = 0;
  virtual Bread* createBread(string &type) = 0;
};

class SinghsMealFactory : public MealFactory {
  public:
  Burger* createBurger(string &type) override {
    if (type == "Basic") return new BasicBurger();
    else if (type == "Standard") return new StandardBurger();
    else if (type == "Premium") return new PremiumBurger();
    else {
      cout << "Invalid Burger Type" << endl;
      return nullptr;
    }
  }

  Bread* createBread(string &type) override {
    if (type == "Basic") return new BasicBread();
    else if (type == "Cheese") return new CheeseBread();
    else if (type == "Garlic") return new GarlicBread();
    else {
      cout << "Invalid Bread Type" << endl;
      return nullptr;
    }
  }
};

class SinghsWheatMealFactory : public MealFactory {
  public:
  Burger* createBurger(string &type) override {
    if (type == "Basic") return new BasicWheatBurger();
    else if (type == "Standard") return new StandardWheatBurger();
    else if (type == "Premium") return new PremiumWheatBurger();
    else {
      cout << "Invalid Wheat Burger Type" << endl;
      return nullptr;
    }
  }

  Bread* createBread(string &type) override {
    if (type == "Basic") return new BasicWheatBread();
    else if (type == "Cheese") return new CheeseWheatBread();
    else if (type == "Garlic") return new GarlicWheatBread();
    else {
      cout << "Invalid Wheat Bread Type" << endl;
      return nullptr;
    }
  }
};

int main() {
  string burgerType, breadType;
  cout << "Enter Burger Type (Basic/Standard/Premium): ";
  cin >> burgerType;
  cout << "Enter Bread Type (Basic/Cheese/Garlic): ";
  cin >> breadType;

  MealFactory* factory = new SinghsMealFactory();
  Burger* burger = factory->createBurger(burgerType);
  Bread* bread = factory->createBread(breadType);

  if (burger) burger->prepare();
  if (bread) bread->prepare();

  delete burger;
  delete bread;
  delete factory;

  cout << "Now, let's try with Wheat options." << endl;

  cout << "Enter Wheat Burger Type (Basic/Standard/Premium): ";
  cin >> burgerType;
  cout << "Enter Wheat Bread Type (Basic/Cheese/Garlic): ";
  cin >> breadType;

  factory = new SinghsWheatMealFactory();
  burger = factory->createBurger(burgerType);
  bread = factory->createBread(breadType);

  if (burger) burger->prepare();
  if (bread) bread->prepare();

  delete burger;
  delete bread;
  delete factory;

  return 0;
}