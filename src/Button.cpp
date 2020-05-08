#include "Button.hpp"
#include "graphics.hpp"
#include "Widget.hpp"

#include <string>
#include <iostream>

using namespace std;
using namespace genv;

Button::Button(Application * parent, int x, int y, int sx, int sy, string param):
                Widget(parent, x, y, sx, sy), _Param(param), _Pushed(false){}

void Button::draw(){
    gout << color(255, 255, 255);
    if(_Pushed){
        gout << color(102, 255, 153);
    }
    gout << move_to(_x,_y)  << box(_wid, _hei)
         << move_to(_x+3,_y+gout.cascent()+1) << color(0,0,0) << text(_Param);
}

string Button::action(){
    if(_Pushed){
        return _Param;}
}

void Button::handle(genv::event ev){
    if(Widget::is_selected(ev.pos_x, ev.pos_y)){
        if(ev.pos_x > _x && ev.pos_x < _x+_wid  &&
           ev.pos_y > _y && ev.pos_y < _y+_hei){
               if(ev.type == ev_mouse && ev.button == btn_left){
                _Pushed = true;
           }
        }
    }
}



/* bool Button::is_selected(int posx, int posy){
    _Pushed = Widget::is_selected(posx, posy);
    return _Pushed;
} */
