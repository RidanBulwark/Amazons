#ifndef SETNUM_HPP_INCLUDED
#define SETNUM_HPP_INCLUDED

#include "Widget.hpp"

#include <string>

class SetNum : public Widget{
    protected:
        int _Value, _LowLim, _UpLim;
        bool _Focused;
    public:
        SetNum(Application * parent, int x, int y, int sx, int sy);
        virtual void draw();
        virtual bool is_selected(int posx, int posy);
        virtual void handle(genv::event ev);
        int get_value();
};

#endif