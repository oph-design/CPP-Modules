#ifndef SPAN_H
# define SPAN_H

# include <iostream>
# include <string>
# include <vector>
# include <climits>
# include <algorithm>
# include <ctime>
# include <cstdlib>

class Span {
 private:
    std::vector<int> _vec;
    unsigned int _size;

 public:
    Span(void);
    Span(const Span &rhs);
    Span(unsigned int size);
    ~Span(void);
    Span& operator=(const Span &rhs);
    std::vector<int> getVec(void) const;
    void setVec(std::vector<int> newVec);
    void addNumber(int value);
    void addNumberPlusPlus();
    int shortestSpan();
    int longestSpan();
};

// std::ostream& operator<<(std::ostream& out, const Span& rhs);

#endif
