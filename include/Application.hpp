#ifndef APPLICATION_HPP_INCLUDED
#define APPLICATION_HPP_INCLUDED

#include <vector>
#include <string>

class Widget;

class Application{
    protected:
        std::vector<Widget *> _widgets;
        int _Win_Wid, _Win_Hei;
    public:
        Application(int Wid, int Hei);
        virtual ~Application(){};
        void register_widget(Widget *);
        void event_loop();
        virtual void action(std::string param) = 0;
        virtual void OGOUT();
        virtual void CLS();
        virtual void DRAW(std::vector<Widget *> _widgets);
};


#endif