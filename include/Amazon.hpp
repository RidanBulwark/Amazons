#ifndef AMAZON_HPP_INCLUDED
#define AMAZON_HPP_INCLUDED

#include "Widget.hpp"

class Amazon : public Widget{
    protected:
        int _Amazon_x, _Amazon_y;
    public:
        Amazon(Application * parent, int x, int y, int sx, int sy, int aposx, int aposy);
        virtual void move();
};

#endif
