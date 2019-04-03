#ifndef JAMES_H
#define JAMES_H
#include <iostream>
#include <SFML/Graphics.hpp>
//#include <Titi.h>
#include <cmath>
#include <cstdlib>
#include <string>
#include <ctime>
#include <vector>

int path_number = 3;

struct path_st
{
    int number = 0 ;
    float pos_x = 0;
    float pos_y = 0;
    vector<int> nextpath;
};

struct Special_item{
    int extra_vit = 0;
    int extra_atk = 0;
    int extra_luck = 0;
    int extra_str = 0;
    int extra_agi = 0;
};

Special_item specialitem[5];
specialitem[0] = {1,1,1,1,1};
specialitem[1] = {2,2,2,2,2};
specialitem[2] = {10,0,0,0,0};
specialitem[3] = {0,10,0,0,0};
specialitem[4] = {5,5,5,5,5};

/*
class Hero_item{
    public:
        int Green_potion = 0;
        int Red_potion = 0;
        int Sword = 0;
        Special_item sp_item;
        int Armor = 0;
        int HP = 99;
};
*/

class Player{
    public:
        int hp,weapon,shield,specialitem_number;
        int std_str,std_vid,std_agi,std_luk,std_atk,std_def;
        int red_potion,green_potion;
        int pos_x,pos_y,now_player_path;
        int atk();
        int def();
        int str();
        int vit();
        int agi();
        int luk();
};
int Player::atk(){
    return std_atk + str()/2 + specialitem[specialitem_number].extra_atk;
}
int Player::def(){
    return
}
int Player::agi(){
    return std_agi + specialitem[specialitem_number].extra_agi;
}
int Player::str(){
    return  std_str + specialitem[specialitem_number].extra_str + sword[weapon].sword_stat[0];
}
int Player::luk(){
    return std_luk + specialitem[specialitem_number].extra_luck;
}

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
        void Item();
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

void path_set(path_st path[]){
    /*
    int temp_number,i=0,end;
    float temp_pos_x,temp_pos_y;
    string temp_text,str_temp_nextpath;
    char temp_str_temp_nextpath[100];
    vector<string> str_temp_nextpath;
    ifstream path_text;
    path_text.open("path.txt");
    while(getline(path_text,temp_text)){
        sscanf(temp_text.c_str(),"%d,%f,%f:%s",temp_number,temp_pos_x,temp_pos_y,temp_str_temp_nextpath);
        path[i].number = temp_number;
        path[i].pos_x = temp_pos_x;
        path[i].pos_y = temp_pos_y;
        str_temp_nextpath = temp_str_temp_nextpath;
        while(temp_str_temp_nextpath != ""){
            path[i].nextpath.push_back(atoi(str_temp_nextpath.substr(0,0).c_str()));
            str_temp_nextpath.erase(0,1);
        }
        i++;
    }
    */

    path[0].number = 0;
    path[0].nextpath.push_back(1);

    path[1].number = 1;
    path[1].nextpath.push_back(2);

    path[2].number = 2;
    path[2].nextpath.push_back(1);
    path[2].nextpath.push_back(0);
}

void cal_path(path_st nowpath,path_st allpath[], int can_walk){
    path_st next_path;
    if(can_walk == 0){
        //write funtion here!!!!
        //cout << nowpath.number;
    }else{
        for(int i = 0 ; i < nowpath.nextpath.size() ; i++){
            for(int j = 0 ; j < path_number ;j++){
                if(nowpath.nextpath[i] == allpath[j].number){
                    next_path = allpath[j];
                    cal_path(next_path,allpath,can_walk-1);
                }
            }

        }
    }
}

void find_path(int can_walk,path_st allpath[],int nowpath_of_player){
    path_st now_path;
    for(int i = 0 ; i < path_number ; i++){
        if(allpath[i].number == nowpath_of_player){
            now_path = allpath[i];
            break;
        }
    }
    cout << now_path.number << endl;
    cal_path(now_path,allpath,can_walk);


}

#endif // JAMES_H

//titi add char number
//nestz add now player by number
