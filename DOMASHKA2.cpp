#define CRT_NO_WARINGS
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cmath>

using namespace std;

// Zadanie 1: Failovaya sitema
class FileSystemNode {
public:
    virtual void display(int indent = 0) = 0;
    virtual ~FileSystemNode() {}
};

class File : public FileSystemNode {
    string name;
public:
    File(const string& n) : name(n) {}
    void display(int indent = 0) override {
        cout << string(indent, ' ') << name << endl;
    }
};

class Folder : public FileSystemNode {
    string name;
    vector<FileSystemNode*> children;
public:
    Folder(const string& n) : name(n) {}
    void add(FileSystemNode* node) {
        children.push_back(node);
    }
    void display(int indent = 0) override {
        cout << string(indent, ' ') << name << "/" << endl;
        for (auto* child : children) {
            child->display(indent + 2);
        }
    }
    ~Folder() {
        for (auto* child : children) {
            delete child;
        }
    }
};

// Zasanie 2: Redaktor figur
class Shape {
public:
    virtual void draw() = 0;
    virtual double area() = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}
    void draw() override {
        cout << "Risuem krug s radiusom " << radius << endl;
    }
    double area() override {
        return 3.14159 * radius * radius;
    }
};

class Rectangle : public Shape {
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    void draw() override {
        cout << "Risuem pryamougolnik s shirinoi " << width << " i visotoi " << height << endl;
    }
    double area() override {
        return width * height;
    }
};

class Triangle : public Shape {
    double base, height;
public:
    Triangle(double b, double h) : base(b), height(h) {}
    void draw() override {
        cout << "Risuem treugolnik s osnovaniem " << base << " i visitoi " << height << endl;
    }
    double area() override {
        return 0.5 * base * height;
    }
};

// Zadanie 3: Plagini dlya tekstovogo redaktora
class TextPlugin {
public:
    virtual string process(const string& text) = 0;
    virtual ~TextPlugin() {}
};

class UppercasePlugin : public TextPlugin {
public:
    string process(const string& text) override {
        string result = text;
        for (char& c : result) {
            c = toupper(c);
        }
        return result;
    }
};

class RemoveSpacesPlugin : public TextPlugin {
public:
    string process(const string& text) override {
        string result;
        for (char c : text) {
            if (c != ' ') {
                result += c;
            }
        }
        return result;
    }
};

class TextEditor {
    vector<TextPlugin*> plugins;
public:
    void addPlugin(TextPlugin* plugin) {
        plugins.push_back(plugin);
    }
    string processText(const string& text) {
        string result = text;
        for (auto* plugin : plugins) {
            result = plugin->process(result);
        }
        return result;
    }
    ~TextEditor() {
        for (auto* plugin : plugins) {
            delete plugin;
        }
    }
};

// Zadanie 4: Logirovanie v prilozhenii
class Logger {
public:
    virtual void log(const string& message) = 0;
    virtual ~Logger() {}
};

class ConsoleLogger : public Logger {
public:
    void log(const string& message) override {
        cout << "Log: " << message << endl;
    }
};

class FileLogger : public Logger {
    ofstream file;
public:
    FileLogger(const string& filename) {
        file.open(filename, ios::app);
    }
    void log(const string& message) override {
        if (file.is_open()) {
            file << "Log: " << message << endl;
        }
    }
    ~FileLogger() {
        if (file.is_open()) {
            file.close();
        }
    }
};

class NullLogger : public Logger {
public:
    void log(const string& message) override {}
};

// Задача 5: Система бонусов
class BonusCalculator {
public:
    virtual double calculateBonus(double amount) = 0;
    virtual ~BonusCalculator() {}
};

class FixedBonus : public BonusCalculator {
    double bonus;
public:
    FixedBonus(double b) : bonus(b) {}
    double calculateBonus(double amount) override {
        return bonus;
    }
};

class PercentageBonus : public BonusCalculator {
    double percentage;
public:
    PercentageBonus(double p) : percentage(p) {}
    double calculateBonus(double amount) override {
        return amount * percentage;
    }
};

class NoBonus : public BonusCalculator {
public:
    double calculateBonus(double amount) override {
        return 0.0;
    }
};

class Customer {
    BonusCalculator* bonusCalc;
public:
    Customer(BonusCalculator* bc) : bonusCalc(bc) {}
    double getBonus(double amount) {
        return bonusCalc->calculateBonus(amount);
    }
    ~Customer() {
        delete bonusCalc;
    }
};

int main() {
    Folder* root = new Folder("Koren");
    Folder* docs = new Folder("Dokumenti");
    File* file1 = new File("File1.txt");
    File* file2 = new File("File2.txt");
    docs->add(file1);
    root->add(docs);
    root->add(file2);
    root->display();

    vector<Shape*> shapes;
    shapes.push_back(new Circle(5.0));
    shapes.push_back(new Rectangle(4.0, 6.0));
    shapes.push_back(new Triangle(3.0, 8.0));
    double totalArea = 0.0;
    for (auto* shape : shapes) {
        shape->draw();
        totalArea += shape->area();
    }
    cout << "Obshaya ploshad: " << totalArea << endl;

    TextEditor editor;
    editor.addPlugin(new UppercasePlugin());
    editor.addPlugin(new RemoveSpacesPlugin());
    string text = "Welcome, MR. FREEMAN";
    cout << "Obrabotanii TEXT: " << editor.processText(text) << endl;

    Logger* logger = new FileLogger("Log.txt");
    logger->log("Prolozhenie On");
    logger->log("Rabota gotova");

    Customer regular(new FixedBonus(100.0));
    Customer premium(new PercentageBonus(0.1));
    Customer basic(new NoBonus());
    cout << "Bonus Obichnii klient: " << regular.getBonus(1000.0) << endl;
    cout << "Bonus Boyarina: " << premium.getBonus(1000.0) << endl;
    cout << "Bonus Bazovogo klienta: " << basic.getBonus(1000.0) << endl;

    for (auto* shape : shapes) {
        delete shape;
    }
    delete root;
    delete logger;
    return 0;