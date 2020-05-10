#ifndef FIELD_HPP_INCLUDED
#define FIELD_HPP_INCLUDED

#include "Widget.hpp"

class Field : public Widget{
    protected:
        int coordX, coordY;
        bool hasAmazon, hasArrow, colorIndex;
    public:
        Field(Application * parent, int x, int y, int sx, int sy, bool colorIndex);
        void Draw();
        void Handle(genv::event ev);
        bool have_arrow();
        bool have_amazon();
};

#endif