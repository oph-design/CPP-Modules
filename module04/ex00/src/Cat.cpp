#include "Cat.hpp"

Cat::Cat(void)
  :  Animal("Cat") {
  std::cout << "\033[1;33mCat born\033[0m" << std::endl;
}

Cat::Cat(const Cat& rhs) {
  *this = rhs;
  std::cout << "\033[1;33mCat cloned\033[0m" << std::endl;
}

Cat::~Cat(void) {
  std::cout << "\033[1;33mCat died\033[0m" << std::endl;
}

Cat&  Cat::operator=(const Cat& rhs) {
  this->_type = rhs.getType();
  return (*this);
}

void Cat::makeSound(void) const {
  std::cout << "meow meow" << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Cat& rhs) {
  out << "---------------\n";
  out << "Type: " << rhs.getType() << "\n";
  out << "---------------" << std::endl;
  return (out);
}

