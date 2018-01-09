/*************************************************************************
	> File Name: 17-10-20.3.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年10月20日 星期五 20时16分37秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

class Cat;
class Dog;
class Mouse;

class IAnimalVisitor {
public :
    virtual void Visit(Cat *animal) = 0;
    virtual void Visit(Dog *animal) = 0;
    virtual void Visit(Mouse *animal) = 0;
};

class Animal
{
private:
    string name;

public:
    Animal(const string& theName)
        :name{ theName }
    {
    }

    virtual ~Animal()
    {
    }

    const string& GetName()const
    {
        return name;
    }

    virtual string Introduce()const = 0;
    virtual void Accept(IAnimalVisitor* visitor) = 0;
};

class Cat : public Animal
{
public:
    Cat(const string& theName)
        :Animal{ theName }
    {
    }

    string Introduce()const override
    {
        return "我是一只猫，我的名字叫\"" + GetName() + "\"。";
    }
    
    virtual void Accept(IAnimalVisitor* visitor) {
        visitor->Visit(this);
    }
};

class Dog : public Animal
{
public:
    Dog(const string& theName)
        :Animal{ theName }
    {
    }

    string Introduce()const override
    {
        return "我是一只狗，我的名字叫\"" + GetName() + "\"。";
    }
    virtual void Accept(IAnimalVisitor* visitor) {
        visitor->Visit(this);
    }
};

class Mouse : public Animal
{
public:
    Mouse(const string& theName)
        :Animal{ theName }
    {
    }

    string Introduce()const override
    {
        return "我是一只老鼠，我的名字叫\"" + GetName() + "\"。";
    }
    
    virtual void Accept(IAnimalVisitor* visitor) {
        visitor->Visit(this);
    }
};

class IntroduceForCatVisitor : public IAnimalVisitor {
public :
    virtual void Visit(Cat *animal) {
        cout << animal->Introduce() << endl;
    }
    
    virtual void Visit(Dog *animal) {}
    
    virtual void Visit(Mouse *animal) {}
};

int main()
{
    shared_ptr<Cat> tom = make_shared<Cat>("Tom");
    shared_ptr<Mouse> jerry = make_shared<Mouse>("Jerry");
    shared_ptr<Dog> spike = make_shared<Dog>("Spike");
    shared_ptr<Cat> butch = make_shared<Cat>("Butch");
    shared_ptr<Cat> lightning = make_shared<Cat>("Lightning");
    vector<shared_ptr<Animal>> friends{ tom, jerry, spike, butch, lightning };
    IntroduceForCatVisitor visitor;
    for (auto animal : friends)
    {
        animal->Accept(&visitor);
    }
    return 0;
}
