#include "Dog.hpp"

Dog::Dog(void)
  : Animal("Dog") {
  _brain = new Brain();
  std::cout << "\033[1;33mDog born\033[0m" << std::endl;
}

Dog::Dog(const Dog& rhs) {
  *this = rhs;
  std::cout << "\033[1;33mDog cloned\033[0m" << std::endl;
}

Dog::~Dog(void) {
  std::cout << "\033[1;33mDog died\033[0m" << std::endl;
}

Dog&  Dog::operator=(const Dog& rhs) {
  this->_brain = new Brain(rhs._brain);
  this->_type = rhs.getType();
  return (*this);
}

void Dog::makeSound(void) const {
  delete _brain;
  std::cout << "bark bark" << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Dog& rhs) {
  out << "---------------\n";
  out << "Type: " << rhs.getType() << "\n";
  out << "---------------" << std::endl;
  return (out);
}

