#define _CRT_NO_WARRINGS
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

// Zadanie 2: Nasledovanie
class Person {
protected:
    string name;
    int age;

public:
    Person(const string& name, int age) : name(name), age(age) {}
    void display() const {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

class Student : public Person {
private:
    string university;

public:
    Student(const string& name, int age, const string& university)
        : Person(name, age), university(university) {}
    void display() const {
        Person::display();
        cout << "University: " << university << endl;
    }
};

// Zadanie 3: Polimorfizm
class Animal {
public:
    virtual void speak() const {
        cout << "Animal sounds" << endl;
    }
    virtual ~Animal() = default;
};

class Dog : public Animal {
public:
    void speak() const override {
        cout << "Bark-Bark!" << endl;
    }
};

class Cat : public Animal {
public:
    void speak() const override {
        cout << "Meow-Meow!" << endl;
    }
};

// Zadanie 4: Abstrakciya
class Shape {
public:
    virtual double area() const = 0;
    virtual ~Shape() = default;
};

class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double area() const override {
        return width * height;
    }
};

class Circle : public Shape {
private:
    double radius;
    double PI = 3.14;
public:
    Circle(double r) : radius(r) {}
    double area() const override {
        return PI * radius * radius;
    }
};

// Zadanie 5: Polimorfizm
void demonstrateShapes() {
    vector<Shape*> shapes;
    shapes.push_back(new Rectangle(5.0, 3.0));
    shapes.push_back(new Circle(2.0));

    for (const Shape* shape : shapes) {
        cout << "Shape Area: " << shape->area() << endl;
    }

    for (Shape* shape : shapes) {
        delete shape;
    }
}

// Zadanie 6: Interface
class Printable {
public:
    virtual void print() const = 0;
    virtual ~Printable() = default;
};

class Book : public Printable {
private:
    string title;

public:
    Book(const string& title) : title(title) {}
    void print() const override {
        cout << "Book: " << title << endl;
    }
};

class Document : public Printable {
private:
    string name;

public:
    Document(const string& name) : name(name) {}
    void print() const override {
        cout << "Document: " << name << endl;
    }
};

// Zadanie 7: Mnozhestvennoe Nasledoavenie
class Logger {
public:
    virtual void log(const string& message) const {
        cout << "Log: " << message << endl;
    }
    virtual ~Logger() = default;
};

class Serializable {
public:
    virtual string serialize() const {
        return "Serialized data";
    }
    virtual ~Serializable() = default;
};

class User : public Logger, public Serializable {
private:
    string username;

public:
    User(const string& username) : username(username) {}
    void log(const string& message) const override {
        cout << "User " << username << ": " << message << endl;
    }
    string serialize() const override {
        return "Serialized user data: " + username;
    }
};

// Zadanie 8: Kompoziciya
class Engine {
public:
    void start() {
        cout << "Engine Online" << endl;
    }
};

class Car {
private:
    Engine engine;
    string model;

public:
    Car(const string& model) : model(model) {}
    void start() {
        cout << "Automobile " << model << ": ";
        engine.start();
    }
};

int main() {
    // Zadanie 2

    cout << "Zadanie 2: " << endl;
    Person person("Vovan", 20);
    Student student("Pyotr", 22, "UralSelMash");
    person.display();
    student.display();

    // Zadanie 3
    cout << endl << "Zadanie 3:" << endl;
    Animal* dog = new Dog();
    Animal* cat = new Cat();
    dog->speak();
    cat->speak();
    delete dog;
    delete cat;

    // Zadanie 4 i 5
    cout << endl << "Zadanie 4 i 5:" << endl;
    demonstrateShapes();

    // Zadanie 6
    cout << endl << "Zadanie 6: " << endl;
    Printable* book = new Book("In a country of lessons not learned");
    Printable* doc = new Document("Document.pdf");
    book->print();
    doc->print();
    delete book;
    delete doc;

    // Zadanie 7
    cout << endl << "Zadanie 7: " << endl;
    User user("Balbes");
    user.log("Enter in system");
    cout << user.serialize() << endl;

    // Zadanie 8
    cout << endl << "Zadanie 8: " << endl;
    Car car("Toyota");
    car.start();

    return 0;