class Animal {
public:
  // Default constructor
  Animal() {}

  // Copy constructor
  Animal(const Animal& other) {
    type = other.type;
  }

  // Overloaded assignment operator
  Animal& operator=(const Animal& other) {
    if (this != &other) {
      type = other.type;
    }
    return *this;
  }

  // Getter and setter for type
  std::string getType() const {
    return type;
  }

  void setType(const std::string& newType) {
    type = newType;
  }

private:
  std::string type;
};


class Dog : public Animal {
public:
  Dog() {}
};


int main() {
  Animal *origin = new Dog();
  Animal *copy = new Dog();

  std::cout << origin->getType() << std::endl;
  std::cout << copy->getType() << std::endl;

  std::cout << std::endl;

  *origin = *copy;  // Use overloaded assignment operator for deep copy
  origin->setType("DOOOOG");

  std::cout << origin->getType() << std::endl;
  std::cout << copy->getType() << std::endl;

  delete origin;
  delete copy;
  return 0;
}