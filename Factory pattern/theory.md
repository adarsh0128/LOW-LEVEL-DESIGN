The Main Idea
The Factory Pattern is about:
Creating objects without exposing the object creation logic to the client,
and letting a separate "factory" class decide which object to create.

In short:
You don’t use new directly in your main code.
You ask a factory to give you the right object.
The factory decides which class to instantiate.

Types of Factory Patterns
Simple Factory → One method decides which object to create.
Factory Method → Let subclasses decide which object to create.
Abstract Factory → Factory of factories (creates related objects).

Advantages
Loose coupling → client doesn’t know exact class names.
Easy to extend → just add a new class and update factory.
Centralized object creation → all new statements are in one place.

When to Use
When object creation is complex or depends on conditions.
When you want to hide creation logic from the client.
When you need to centralize object creation.

"The Factory Pattern is simply a way to centralize object creation so that the client code doesn’t need to know the exact class name or construction details."

"For example, imagine I’m building a drawing app. I have shapes like Circle, Square, and Triangle. Without a factory, everywhere in my code I’d be doing new Circle() or new Square(). This means if tomorrow the constructor changes or I add a new shape, I’d have to update multiple places in the code."

"With a Factory Pattern, I create a ShapeFactory with a method like createShape(type). I just pass 'circle' and it returns a Circle object. The client code only talks to the factory — it doesn’t care how the object is created or which class it belongs to. If I want to add Rectangle, I only change the factory, not the rest of the system."

Key points to hit in the interview:
Definition: Centralizes object creation in one place.

Problem solved: Avoids repetitive and scattered new calls, and keeps creation logic separate from business logic.

Advantages:
Easy to maintain (only change factory code when adding/modifying objects).
Hides complex creation logic from the client.
Makes it easy to switch or extend product types.
