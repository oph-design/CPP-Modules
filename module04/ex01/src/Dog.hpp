#ifndef DOG_H
# define DOG_H

# include <iostream>
# include <string>

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal {
 private:
    Brain *_brain;

 public:
    Dog(void);
    Dog(const Dog &rhs);
    ~Dog(void);
    Dog& operator=(const Dog &rhs);
    void makeSound(void) const;
    Brain *getBrain(void) const;
};

std::ostream& operator<<(std::ostream& out, const Dog& rhs);

#endif
