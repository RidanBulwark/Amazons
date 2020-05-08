#include "Field.hpp"

using namespace std;
using namespace genv;

Field::Field(Application * parent, int x, int y, int sx, int sy, int MapWid):
            Widget(parent, x,y,sx,sy), _Map_Wid(MapWid),
            _Have_Amazon(false), _Have_Arrow(false){}

/* Field::draw(){
    gout << move_to(_x, _y) << color();
} */

bool have_arrow(){}

bool have_amazon(){}