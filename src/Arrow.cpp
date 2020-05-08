#include "Arrow.hpp"

Arrow::Arrow(Application * parent, int x, int y, int sx, int sy, int arposx, int arposy):
            Widget(parent, x,y,sx,sy), _Arrow_x(arposx), _Arrow_y(arposy){}

void Arrow::shoot(int posx, int posy){}