#include "graphics.hpp"
#include "Amazon.hpp"

Amazon::Amazon(Application * parent, int x, int y, int sx, int sy, int aposx, int aposy,  std::function<void(int, int)> holvagyok):
               Widget(parent, x,y,sx,sy), amazonX(aposx), amazonY(aposy), holvagyok(holvagyok){}

void Amazon::Move(){}