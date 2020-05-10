#ifndef AMAZON_HPP_INCLUDED
#define AMAZON_HPP_INCLUDED

#include "Widget.hpp"
#include <functional>

class Amazon : public Widget{
    protected:
        std::function<void(int, int)> checkPositon;
        bool team, selected, wantsToMove;
    public:
        Amazon(Application * parent, int x, int y, int sx, int sy,
               std::function<void(int, int)> checkPositon, bool team);
        virtual void Draw();
        virtual void Handle(genv::event ev);
        virtual bool IsSelected(int posx, int posy);
        /* virtual void Move(int cx, int cy); */
};

#endif
