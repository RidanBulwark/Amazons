#include "Application.hpp"
#include "graphics.hpp"
#include "Widget.hpp"

#include <iostream>

using namespace std;
using namespace genv;

bool Gout_Opened = false;

Application::Application(int Wid, int Hei): _Win_Wid(Wid), _Win_Hei(Hei){}

void Application::CLS(){
    gout << move_to(0,0) << color(0,0,0) << box(_Win_Wid, _Win_Hei);
}

void Application::OGOUT(){
    gout.open(_Win_Wid, _Win_Hei);
}

void Application::DRAW(vector<Widget *> widgetVect){
    Application::CLS();
    for(Widget * w : widgetVect){
        w->draw();
    }
    gout << refresh;
}

void Application::event_loop(){
    if(!Gout_Opened){
        OGOUT();
        Gout_Opened = true;
    }

    Application::DRAW(_widgets);    

    event ev;
    int focus = -1;
    while (gin >> ev){
        if(ev.type == ev_mouse && ev.button == btn_left){
            for(size_t i = 0;i<_widgets.size();i++){
                if(_widgets[i]->is_selected(ev.pos_x, ev.pos_y)){
                    focus = i;
                }
            }
        }
    
        if(focus!=-1){
            _widgets[focus]->handle(ev);
        } 
        
        Application::DRAW(_widgets);

/*         if(ev.type == ev_key){
            if(ev.keycode ==){
                action();
            }
            if(ev.keycode ==){
                action();
            }
            if(ev.keycode ==){
                action();
            }
            if(ev.keycode ==){
                action();
            }
            if(ev.keycode ==){
                action();
            }
        } */

        if(ev.type == ev_key && ev.keycode == key_escape){
            break;
        }
    
    
    }
}


void Application::register_widget(Widget * Widget){
    _widgets.push_back(Widget);
}






