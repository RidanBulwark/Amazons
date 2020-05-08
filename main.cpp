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

using namespace std;
using namespace genv;

class Amazons : public Application{
    protected:
        SetNum *SN1;
        Button *PlayBTN, *VSBotBTN;
        vector<Widget *> _Widgets;
        vector<vector<Field *>> _Fields;
        vector<Amazon *> _Amazons;
        vector<Arrow *> _Arrows;
        int State = 0;
        int Big = 0;
    public:
        Amazons(int Wid, int Hei): Application(Wid, Hei){}

        void Menu(){
            SN1 = new SetNum(this, 250, 350, 100, 30);
            _Widgets.push_back(SN1);
            PlayBTN = new Button(this, 250, 150, 100, 30, "Play");
            _Widgets.push_back(PlayBTN);
            VSBotBTN = new Button(this, 250, 150, 100, 30, "VS Bot");
            _Widgets.push_back(VSBotBTN);
            Big = SN1->get_value();
        }

        void Play(){
            for(int i = 0;i<Big;i++){
                vector<Field * > _TMP_Field;
                for(int j = 0;j<Big;j++){
                    /* Field *F = new Field(this, i, j, 20, 20, _Win_Wid);
                    _TMP_Field.push_back(F); */
                }
                _Fields.push_back(_TMP_Field);
            }
        }
        
        void GameOver(){}

        void StateCheck(int current){
            switch (current)
            {
            case 0:
                Menu();
                break;
            case 1:
                Play();
                break;
            case 9:
                GameOver();
                break;    
            default:
                break;
            }
        }

        void action(string param){

        }
};


int main(){
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

    Amazons Game(600, 600);
    Game.event_loop();
    return 0;
}

