#ifndef FIELD_HPP_INCLUDED
#define FIELD_HPP_INCLUDED

#include "Widget.hpp"

class Field : public Widget{
    protected:
        int _F_pos_x, _F_pos_y, _Map_Wid;
        bool _Have_Amazon, _Have_Arrow;
    public:
        Field(Application * parent, int x, int y, int sx, int sy, int MapWid);
        virtual void draw();
        bool have_arrow();
        bool have_amazon();
};

#endif