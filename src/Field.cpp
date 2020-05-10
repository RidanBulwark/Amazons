#include "Field.hpp"

using namespace std;
using namespace genv;

Field::Field(Application * parent, int x, int y, int sx, int sy, bool colorindex):
            Widget(parent, x,y,sx,sy), colorIndex(colorindex),
            hasAmazon(false), hasArrow(false){}

void Field::Draw(){
    if(colorIndex){
        gout << move_to(x*wid, y*hei) << color(0,0,0) << box(wid, hei);    
    }
    else{
        gout << move_to(x*wid, y*hei) << color(255,255,255) << box(wid, hei);    
    }
}

void Field::Handle(event ev){
    
}

bool have_arrow(){}

bool have_amazon(){}