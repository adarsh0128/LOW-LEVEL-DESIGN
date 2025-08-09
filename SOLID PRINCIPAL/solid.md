What is SOLID?
SOLID is a set of five design principles that help you write clean, maintainable, and scalable code.

Why use SOLID?
Without SOLID:
Your C++ classes get bloated.
A small change can break many things.
Code becomes hard to test, extend, and reuse.

With SOLID:
Code is modular.
Easier to modify without breaking.
Follows good OOP practices.

### S → Single Responsibility Principle (SRP)

A class should have only one reason to change — meaning it should do only one job.

If a class tries to do too many things, it becomes messy, harder to maintain, and changes in one part can break another.

Why is SRP Important?
Easy to maintain → Fixing a bug in one function won’t accidentally break another.
Easy to test → You can test a class’s small job without setting up the whole system.
Reusability → You can reuse small focused classes in other projects.

Think of a restaurant chef:
If the chef is also answering phone calls, cleaning tables, and managing bills, it’s chaos.

Instead, you have:
Chef (cooks food)
Waiter (serves)
Cashier (handles bills)

Same in programming — one role per class.

#### O → Open/Closed Principle (OCP)

Definition:
A class should be open for extension but closed for modification.

Meaning in simple terms:
You should be able to add new features to a class without changing its existing code.

Why is this important?
If you keep modifying an existing class whenever requirements change:
You risk breaking working code.
Testing becomes harder.
The code becomes messy and full of if-else statements.

Instead, you design the class so that:
You can add new behavior by adding new classes or methods, not by editing the original one.

Real-life analogy
Think of a smartphone:
You don’t change the phone’s hardware every time you want a new app.
You just install a new app — the phone supports this without being rebuilt.

#### What is "L" in SOLID?

L = Liskov Substitution Principle (LSP)
Proposed by Barbara Liskov.

Definition (simple version):
If class B is a child of class A, you should be able to use B anywhere you use A, without breaking the program.

Why does LSP matter?
If a subclass changes the behavior in a way that breaks the parent’s expectations:
Your code becomes unpredictable.
Polymorphism fails.
Bugs appear when you replace the parent with the child.

In short:
A child class shouldn’t do anything that surprises code written for the parent.

Easy Real-Life Analogy
Suppose Bird can fly.
Penguin is a Bird but can’t fly.

If your program assumes all Birds can fly, replacing a Bird with a Penguin will break things.
This violates LSP.

Key Points to Remember
LSP Rule: Subclass objects should be able to replace superclass objects without breaking the program.
Avoid adding behavior in a child class that contradicts the parent’s contract.
If behavior doesn’t apply to all children, refactor into separate hierarchies.

#### "I" in SOLID

Interface Segregation Principle (ISP)
"Clients should not be forced to depend on interfaces they do not use."

What Does That Mean?
In simple words:
Don’t create one big fat interface with many functions.
Instead, split it into smaller, specific interfaces so that a class only needs to implement the methods it actually needs.

Think of it like a restaurant menu:
If the only thing you want is coffee, you shouldn’t have to learn all the rules for making pizzas, burgers, and sushi.

#### D → Dependency Inversion Principle (DIP)

It says:
High-level modules should not depend on low-level modules. Both should depend on abstractions.
Abstractions should not depend on details. Details should depend on abstractions.

Why this principle exists
Without DIP:
Your main logic (high-level) depends directly on implementation details (low-level).
If low-level code changes (e.g., database or file handling), you must modify high-level code too — which is risky and messy.

With DIP:
You code to interfaces (abstract classes), not concrete classes.
High-level code only cares about the contract (what should be done), not the how.

In simple words
Imagine you have a Remote Control (high-level) and a Light Bulb (low-level).
If the remote is built only for that one bulb model, you can’t use it for a fan or TV.
But if the remote works with an interface called Switchable, it can work with any device that follows that contract.

Key Benefits
Easy to swap implementations.
Low coupling between classes.
Code is more maintainable and testable.
