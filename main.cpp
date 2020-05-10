#include "graphics.hpp"
#include "Widget.hpp"
#include "Application.hpp"
#include "SetNum.hpp"
#include "Button.hpp"
#include "Amazon.hpp"
#include "Arrow.hpp"
#include "Field.hpp"

#include <string>
#include <vector>
#include <iostream>
#include <functional>

using namespace std;
using namespace genv;

class Amazons : public Application{
    protected:
        SetNum *boardSizeSet;
        Button *playButton, *vsBotButton;
        /* vector<vector<Field *>> _Fields;
        vector<Amazon *> _Amazons;
        vector<Arrow *> _Arrows;  */
        int state = 0;
        int boardSize = 0;
    public:
        Amazons(int Wid, int Hei): Application(Wid, Hei){}

        void Menu(){
            boardSizeSet = new SetNum(this, 250, 350, 100, 30);
            function<void()> play = [=](){
                widgets.clear();
                state = 1;
                boardSize = boardSizeSet->GetValue();
                StateCheck();
            };
            playButton = new Button(this, 250, 150, 100, 30, "Play", play);
            /* vsBotButton = new Button(this, 250, 190, 100, 30, "VS Bot"); */
        }

        void Play(){
            for(int i = 0;i<boardSize;i++){
                for(int j = 0;j<boardSize;j++){
                    Field *F = new Field(this, i, j, 50, 50, (i+j)%2);
                    widgets.push_back(F);
                }
            }
        }
        
        void GameOver(){}

        void Action(string param){
        }

        void StateCheck(){
            switch (state)
            {
            case 0:
                Menu();
                Amazons::EventLoop();
                break;
            case 1:
                Play();
                Amazons::EventLoop();
                break;
            case 9:
                GameOver();
                Amazons::EventLoop();
                break;    
            default:
                break;
            }
        }


};


int main(){
    Amazons Game(600, 600);
    Game.StateCheck();
    
    return 0;
}

/*     gout.open(400,400);
     gout << color(255, 200, 170) << move_to(20,20) << box(20,20) << refresh; 
    event ev;
    int x = 0;
    while (gin>> ev)
    {
        if(ev.pos_x > 20 && ev.pos_x < 40 && ev.pos_y > 20 && ev.pos_y < 40){
            x += 1;
            cout << "benne van" << x <<'\n';
        }
    }
     */