#ifndef BUTTON_HPP_INCLUDED
#define BUTTON_HPP_INCLUDED

#include "Widget.hpp"
#include <string>

class Button : public Widget{
    protected:
        std::string _Param;
        bool _Pushed;
    public:
        Button(Application * parent, int x, int y, int sx, int sy, std::string param);
        ~Button(){}
        virtual void draw();
        virtual void handle(genv::event ev);
        virtual std::string action();
        /* virtual bool is_selected(int posx, int posy); */
};

#endif