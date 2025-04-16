#pragma once
#include <string>
#include <iostream>
#include <limits>

class Animal {
public:
    enum class eType { CAT, DOG };

    virtual ~Animal() = default;

    virtual void Read(std::ostream& ostream, std::istream& istream);
    virtual void Write(std::ostream& ostream) const;

    std::string GetName() const { return name; }
    virtual eType GetType() const = 0;

protected:
    std::string name;
    int age;
};