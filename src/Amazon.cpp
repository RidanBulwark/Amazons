#include "graphics.hpp"
#include "Amazon.hpp"

Amazon::Amazon(Application * parent, int x, int y, int sx, int sy, int aposx, int aposy):
               Widget(parent, x,y,sx,sy), _Amazon_x(aposx), _Amazon_y(aposy){}

void Amazon::move(){}