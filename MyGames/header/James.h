#ifndef JAMES_H
#define JAMES_H
#include <iostream>
#include <SFML/Graphics.hpp>
//#include <Titi.h>
#include <cmath>
#include <cstdlib>
#include <string>
#include <ctime>

class Special_item{
    public:
        int extra_vit = 0;
        int extra_atk = 0;
        int extra_luck = 0;
        Special_item(int v,int a,int l){
            extra_vit = v;
            extra_atk = a;
            extra_luck = l;
        }
};

class Hero_item{
    public:
        int Green_potion = 0;
        int Red_potion = 0;
        int Sword = 0;
        Special_item sp_item;
        int Armor = 0;
        int HP = 99;
};

class Path_Ef{
    private :
        int lucky_cons = 10;
    public :

        int Return_Coin(int lu){
            if(lu >= lucky_cons){
                return (rand()%20)+1;
            }else{
                return (rand()%10)+1;
            }
        }

        void Open_Shop(sf::RenderWindow *gameWindow);

        int Get_Heal(int cha_no);

        void House(int hero_number,int house_number);

};
void Path_Ef::Open_Shop(sf::RenderWindow *gameWindow){
    sf::Texture shop_texture;
    if(!shop_texture.loadFromFile("texture/store.png")){

    }
    sf::Sprite shop_sprite;
    shop_sprite.setTexture(shop_texture);
    shop_sprite.setTextureRect(sf::IntRect(0,0,64,64));

    gameWindow->draw(shop_sprite);
}

int Path_Ef::Get_Heal(int cha_no){
    if(cha_no == 1){    //เลขตัวละคร
        return 10;
    }else{
        return 5;
    }
}

void Path_Ef::House(int hero_number, int house_number){
    if(hero_number == house_number){
        //nowplayer.redpotion ++++++
    }
}



void Specialitem_Setup(){
    Special_item health(5,0,0);
    Special_item atk(0,5,0);
    Special_item lucky(0,0,5);
}

#endif // JAMES_H

//titi add char number
//nestz add now player by number

