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
    int this_path_is = 0;
    std::vector<int> nextpath;
};

path_st path[3];

struct Special_item{
    int extra_vit = 0;
    int extra_atk = 0;
    int extra_luck = 0;
    int extra_str = 0;
    int extra_agi = 0;
};

Special_item specialitem[5];

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
        int character_number,now_path;
        int hp,weapon = 0,shield_number = 0,specialitem_number = 0,star = 0,money = 0;
        int std_str,std_vid,std_agi,std_luk,std_atk,std_def;
        int red_potion = 0,green_potion = 0;
        int pos_x,pos_y,now_player_path;
        int atk();
        int def();
        int str();
        int vit();
        int agi();
        int luk();
        int hp_max();
};

int Player::atk(){
    return std_atk + str()/2 + specialitem[specialitem_number].extra_atk;
}
int Player::def(){
    return std_def + vit() + shield[shield_number].shield_stat[1];
}
int Player::agi(){
    return std_agi + specialitem[specialitem_number].extra_agi + sword[weapon].sword_stat[1];
}
int Player::str(){
    return  std_str + specialitem[specialitem_number].extra_str + sword[weapon].sword_stat[0];
}
int Player::luk(){
    return std_luk + specialitem[specialitem_number].extra_luck + sword[weapon].sword_stat[2];
}
int Player::vit(){
    return std_vid + specialitem[specialitem_number].extra_vit + shield[shield_number].shield_stat[0];
}
int hp_max(){
    return vit()*5;
}


void useThisItem(Player & that_player,bool high_grade){
    int x = rand()%100+1;
    if(high_grade == false){
        if(x > 30){
            std::cout << "pick weapon 1 ??";
            std::cin >> x;
            if(x) that_player.weapon = 1;
        }else if(x > 50){
            std::cout << "pick weapon 2 ??";
            std::cin >> x;
            if(x) that_player.weapon = 2;
        }else if(x > 60){
            std::cout << "pick weapon 3 ??";
            std::cin >> x;
            if(x) that_player.weapon = 3;
        }else if(x > 70){
            std::cout << "pick weapon 4 ??";
            std::cin >> x;
            if(x) that_player.weapon = 4;
        }else if(x > 80){
            std::cout << "pick weapon 5 ??";
            std::cin >> x;
            if(x) that_player.weapon = 5;
        }else if(x > 90){
            std::cout << "pick weapon 6 ??";
            std::cin >> x;
            if(x) that_player.weapon = 6;
        }else if(x > 95){
            std::cout << "pick weapon 7 ??";
            std::cin >> x;
            if(x) that_player.weapon = 7;
        }
    }else{
        if(x > 50){
            std::cout << "pick weapon 8 ??";
            std::cin >> x;
            if(x) that_player.weapon = 8;
        }else if(x > 80){
            std::cout << "pick weapon 9 ??";
            std::cin >> x;
            if(x) that_player.weapon = 9;
        }else{
            std::cout << "pick weapon 10 ??";
            std::cin >> x;
            if(x) that_player.weapon = 10;
        }
    }
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
        void Item(Player &);
        void Open_Shop(sf::RenderWindow *gameWindow);

        void Get_Heal(Player &);

        void House(Player &,int house_number);

};

/*void Path_Ef::Open_Shop(sf::RenderWindow *gameWindow){

    sf::Texture shop_texture;
    if(!shop_texture.loadFromFile("texture/store.png")){

    }
    sf::Sprite shop_sprite;
    shop_sprite.setTexture(shop_texture);
    shop_sprite.setTextureRect(sf::IntRect(0,0,64,64));

    gameWindow->draw(shop_sprite);

}*/

void Path_Ef::Get_Heal(Player & that_player){
    int x;
    if(that_player.character_number == 1){
        x = (rand()%20)+1;
        if(that_player.hp + x >  that_player.hp_max()){
            that_player.hp = that_player.hp_max();
        }else{
            that_player.hp += x;
        }
    }else{
        x = (rand()%10)+1;
        if(that_player.hp + x > that_player.hp_max()){
            that_player.hp = that_player.hp_max();
        }else{
            that_player.hp += x;
        }
    }
}

void Path_Ef::House(Player & that_player, int house_number){
    if(that_player.character_number == house_number){
        that_player.green_potion += 1;
        that_player.red_potion += 3;
    }
}

void Path_Ef::Item(Player & that_player){
    int x = (rand()%80)+1;
    x += (rand()%that_playerluk());
    if(x <= 50){
        std::cout << "1 red potion";
        that_player.red_potion += 1;
    }else if(x <= 60){
        std::cout << "1 green potion";
        that_player.green_potion += 1;
    }else if(x <= 65){
        std::cout << "money!";
        that_player.money += (rand()%10)+6;
    }else if(x <= 75){
        std::cout << "money!!";
        that_player.money += (rand()%20)+10;
    }else if(x <= 90){
        useThisItem(that_player,false);
    }else if(x == 100){
        std::cout << "star!!!!";
        that_player.star++;
    }else if(x <= 100){
        std::cout << "money!!!";
        that_player.money += (rand()%30)+20;
    }else{
        useThisItem(that_player,true);
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
    //cout << now_path.number << endl;
    cal_path(now_path,allpath,can_walk);


}

#endif // JAMES_H
