#ifndef ARROW_HPP_INCLUDED
#define ARROW_HPP_INCLUDED

#include "Widget.hpp"

class Arrow : public Widget{
    protected:
        int _Arrow_x, _Arrow_y;
    public:
        Arrow(Application * parent, int x, int y, int sx, int sy, int arposx, int arposy);
        void shoot(int x, int y);
};

#endif