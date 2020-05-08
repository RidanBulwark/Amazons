#include "Widget.hpp"
#include "graphics.hpp"

#include <string>

Widget::Widget(Application * parent, int x, int y, int wid, int hei):
                _parent(parent), _x(x), _y(y), _wid(wid), _hei(hei)
                {
                    _parent->Application::register_widget(this);
                }

bool Widget::is_selected(int posx, int posy){
    return posx>_x && posx<_x+_wid && posy>_y && posy<_y+_hei;
}

/* void Widget::set_OnScreen(bool set){
    _OnScreen = set;
} */