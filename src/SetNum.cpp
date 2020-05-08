#include "SetNum.hpp"

#include <iostream>
#include <string>

using namespace std;
using namespace genv;

SetNum::SetNum(Application * parent, int x, int y, int sx, int sy):
               Widget(parent, x, y, sx, sy), _Value(6), _LowLim(6), _UpLim(12), 
               _Focused(false){}

void SetNum::draw(){
    gout << color(255,255,255);
    if(_Focused){
        gout << color(102, 255, 153);
    }
    gout << move_to(_x, _y) << box(_wid, _hei) 
            << move_to(_x+_wid-_hei/2, _y) << color(100,244,255) << box(_hei/2,_hei/2)                     //fölső állító négyzet
            << move_to(_x+_wid-_hei/2, _y+_hei/2) << color(0,0,0) << line(_hei/2, 0)                       // vonal
            << move_to(_x+_wid-_hei/2, _y+_hei/2+1) << color(0,204,255) << box(_hei/2,_hei/2-1);         // alsó állító négyzet
    gout << move_to(_x+_wid-_hei/2+(_hei/4-3), _y+gout.cascent()-1) << color(0,0,0) << text("+") // +
            << move_to(_x+_wid-_hei/2+(_hei/4-3), _y+_hei/2+gout.cascent()-1) << text("-");       // - 
    
    gout << move_to(_x + 3, _y + gout.cascent()) << text(to_string(_Value));

}

bool SetNum::is_selected(int posx, int posy){
    _Focused = Widget::is_selected(posx, posy);
    return _Focused; 
}

void SetNum::handle(genv::event ev){
    if(_Focused){
        if(ev.pos_x > _x+_wid-_hei/2 && ev.pos_x < _x+_wid  &&
           ev.pos_y > _y && ev.pos_y < _y+_hei/2){
               if(ev.type == ev_mouse && ev.button == btn_left){
               _Value = min(_Value+1, _UpLim);}
           }
        if(ev.pos_x > _x+_wid-_hei/2 && ev.pos_x < _x+_wid  &&
           ev.pos_y > _y+_hei/2 && ev.pos_y < _y+_hei){
               if(ev.type == ev_mouse && ev.button == btn_left){
               _Value = max(_Value-1, _LowLim);}
           }
        
        if(ev.type == ev_key && ev.keycode == key_up){
            _Value = min(_Value+1, _UpLim);
        }
        if(ev.type == ev_key && ev.keycode == key_down){
            _Value = max(_Value-1, _LowLim);
        }
    }
}


int SetNum::get_value(){
    return _Value;
}



