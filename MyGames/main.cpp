#include "header/James.h"
#include "header/NestZ.h"
#include "header/Pound.h"
#include "header/Billy.h"
#include "header/Titi.h"
#include <cstdlib>
#include <ctime>
using namespace sf;

Game game;

int main()
{
    int ab;
    srand(time(0));
    init ();
    inputstat_object();
    cout << chara[0].clas<<endl;
    cout << chara[0].stat[0] << " " <<chara[0].stat[1] <<" " << chara[0].stat[2] <<" " << chara[0].stat[3]<<" " << chara[0].stat[4]<<" " << chara[0].stat[5]<<endl;
    get_item("sword",0);
    cout << chara[0].stat[0] << " " <<chara[0].stat[1] <<" " << chara[0].stat[2] <<" " << chara[0].stat[3]<<" " << chara[0].stat[4]<<" " << chara[0].stat[5]<<endl;
    cin >> ab;
    use_potion(ab,0);
    cout << chara[0].stat[0] << " " <<chara[0].stat[1] <<" " << chara[0].stat[2] <<" " << chara[0].stat[3]<<" " << chara[0].stat[4]<<" " << chara[0].stat[5]<<endl;
    Game game;

    game.run();

    return 0;
}
