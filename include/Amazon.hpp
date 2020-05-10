#ifndef AMAZON_HPP_INCLUDED
#define AMAZON_HPP_INCLUDED

#include "Widget.hpp"
#include <functional>

class Amazon : public Widget{
    protected:
        int amazonX, amazonY;
        std::function<void(int, int)> holvagyok;
    public:
        Amazon(Application * parent, int x, int y, int sx, int sy, int aposx, int aposy, 
               std::function<void(int, int)> holvagyok);
        virtual void Move();
};

#endif
