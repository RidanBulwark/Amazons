#include "Field.hpp"

#include <iostream>

using namespace std;
using namespace genv;

Field::Field(Application * parent, int x, int y, int sx, int sy, bool color, 
            std::function<void(int, int)> newAmazon):
            Widget(parent, x,y,sx,sy), colorBool(color),
            hasAmazon(false), hasArrow(false), newAmazon(newAmazon), pushed(false){}

void Field::Draw(){
    if(colorBool){
        gout << move_to(x, y) << color(0,0,0) << box(wid, hei);    
    }
    else{
        gout << move_to(x, y) << color(255,255,255) << box(wid, hei);    
    }
    if(pushed){
        gout << move_to(x, y) << color(160,20,160) << box(wid, hei);    
    }
}

void Field::Handle(event ev){
    if(Widget::IsSelected(ev.pos_x, ev.pos_y)){
        if(ev.button == btn_left){
            pushed = true;
            newAmazon(x,y);
        }
        if(ev.button == -btn_left){
            pushed = false;
        }
    }
}

bool Field::IsSelected(int posx, int posy){
    pushed = Widget::IsSelected(posx, posy);
    return pushed;
}

void Field::Colored(int inx, int iny){ //PushYourself
    if(x == inx){
        pushed = true;
    }
    if(y == iny){
        pushed = true;
    }
    if(x+y == inx+iny){
        pushed = true;
    }
    if(x-y == inx-iny){
        pushed = true;
    }
}
