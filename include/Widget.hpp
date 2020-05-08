#ifndef WIDGET_HPP_INCLUDED
#define WIDGET_HPP_INCLUDED

#include "graphics.hpp"
#include "Application.hpp"

#include <string>

class Widget{
    protected:
        int _x, _y, _wid, _hei;
        Application * _parent;
    public:
        Widget(Application * parent, int x, int y, int wid, int hei);
        virtual bool is_selected(int mouse_x, int mouse_y);
        virtual void draw() = 0;
        virtual void handle(genv::event ev) = 0;
        /* virtual void set_OnScreen(bool set); */
};

#endif