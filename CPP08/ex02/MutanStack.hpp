#ifndef MUTANSTACK_HPP
#define MUTANSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>
#include <list>

template <typename T, typename container = std::deque<T> >
class MutantStack : public std::stack<T, container>
{
public:
    MutantStack()
    {
    }
    MutantStack(const MutantStack &obj)
    {
        *this = obj;
    }
    ~MutantStack()
    {
    }
    MutantStack &operator=(const MutantStack &obj)
    {
        (void)obj;
        return *this;
    }
    typedef typename std::stack<T, container>::container_type::iterator iterator;
    typedef typename std::stack<T, container>::container_type::const_iterator const_iterator;
    typedef typename std::stack<T, container>::container_type::reverse_iterator reverse_iterator;
    typedef typename std::stack<T, container>::container_type::const_reverse_iterator const_reverse_iterator;

    iterator begin()
    {
        return (std::stack<T, container>::c.begin());
    }

    iterator end()
    {
        return (std::stack<T, container>::c.end());
    }

    reverse_iterator rbegin()
    {
        return (std::stack<T, container>::c.rbegin());
    }

    reverse_iterator rend()
    {
        return (std::stack<T, container>::c.rend());
    }

    const_iterator cbegin()
    {
        return (std::stack<T, container>::c.cbegin());
    }

    const_iterator cend()
    {
        return (std::stack<T, container>::c.cend());
    }

    const_reverse_iterator crbegin()
    {
        return (std::stack<T, container>::c.crbegin());
    }

    const_reverse_iterator crend()
    {
        return (std::stack<T, container>::c.crend());
    }
};

#endif