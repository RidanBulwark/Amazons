#include "graphics.hpp"
#include "Amazon.hpp"

using namespace std;
using namespace genv;


Amazon::Amazon(Application * parent, int x, int y, int sx, int sy,
               std::function<void(int, int)> checkPositon, bool team):
               Widget(parent, x,y,sx,sy), checkPositon(checkPositon), 
               team(team), selected(false){}

void Amazon::Draw(){
    if(team){
        gout << move_to(x+10, y+10) << color(0,200,200) << box(wid-20, hei-20);
        if(selected){
            gout << move_to(x+10, y+10) << color(0,250,250) << box(wid-20, hei-20);
        }
    }
    else{
        gout << move_to(x+10, y+10) << color(200,200,0) << box(wid-20, hei-20);
        if(selected){
            gout << move_to(x+10, y+10) << color(250,250,0) << box(wid-20, hei-20);
        }
    }
}

void Amazon::Handle(genv::event ev){
    if(Widget::IsSelected(ev.pos_x, ev.pos_y)){
        if(ev.button == btn_left){
            checkPositon(x, y);
        }
    }
}

bool Amazon::IsSelected(int posx, int posy){
    selected = Widget::IsSelected(posx, posy);
    return selected; 
}
