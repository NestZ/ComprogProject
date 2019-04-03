#ifndef TITI_H
#define TITI_H
#include <iostream>
#include <cstdlib>

using namespace std;

struct object{
    int sword_stat[3],potion_effect; // 0str 1agi 2luk
    int shield_stat[3]; // 0vit 1def 2hp
    string name_object;
};

void inoutstat_object();
void get_item_boss();////////
void Equip_item(int n_2,int number_chara);
void use_potion(int number_potion);

object shield[10];
object sword[10];
object potion[2];

void inputstat_object(){

    sword[0].name_object = "hand";              sword[0].sword_stat[0] = 0;sword[0].sword_stat[1] = 0;sword[0].sword_stat[2] = 0;
    sword[1].name_object = "Durandal";          sword[1].sword_stat[0] = 3;sword[1].sword_stat[1] = 1;sword[1].sword_stat[2] = 2;
    sword[2].name_object = "Muramasas";         sword[2].sword_stat[0] = 3;sword[2].sword_stat[1] = 1;sword[2].sword_stat[2] = 2;
    sword[3].name_object = "Murasame";          sword[3].sword_stat[0] = 3;sword[3].sword_stat[1] = 1;sword[3].sword_stat[2] = 2;
    sword[4].name_object = "Masamune";          sword[4].sword_stat[0] = 3;sword[4].sword_stat[1] = 1;sword[4].sword_stat[2] = 2;
    sword[5].name_object = "Shusui";            sword[5].sword_stat[0] = 3;sword[5].sword_stat[1] = 1;sword[5].sword_stat[2] = 2;
    sword[6].name_object = "Yubashiri";         sword[6].sword_stat[0] = 3;sword[6].sword_stat[1] = 1;sword[6].sword_stat[2] = 2;
    sword[7].name_object = "Kitetsu Sandai";    sword[7].sword_stat[0] = 3;sword[7].sword_stat[1] = 1;sword[7].sword_stat[2] = 2;
    sword[8].name_object = "Wado Ichimonji";    sword[8].sword_stat[0] = 3;sword[8].sword_stat[1] = 1;sword[8].sword_stat[2] = 2;
    sword[9].name_object = "Excalibur";         sword[9].sword_stat[0] = 3;sword[9].sword_stat[1] = 1;sword[9].sword_stat[2] = 2;

    potion[0].name_object ="Green potion" ;      potion[0].potion_effect = 30;
    potion[1].name_object ="Red potion";        potion[1].potion_effect = 10;


    shield[0].name_object = "hand";              shield[0].shield_stat[0] = 0;shield[0].shield_stat[1]= 0;shield[0].shield_stat[2]= 0;
    shield[1].name_object = "Aegis Shield ";     shield[1].shield_stat[0] = 2;shield[1].shield_stat[1]= 2;shield[1].shield_stat[2]= 2;
    shield[2].name_object = "shield 3";          shield[2].shield_stat[0] = 2;shield[2].shield_stat[1]= 2;shield[2].shield_stat[2]= 2;
    shield[3].name_object = "shield 4";          shield[3].shield_stat[0] = 2;shield[3].shield_stat[1]= 2;shield[3].shield_stat[2]= 2;
    shield[4].name_object = "shield 5";          shield[4].shield_stat[0] = 2;shield[4].shield_stat[1]= 2;shield[4].shield_stat[2]= 2;
    shield[5].name_object = "shield 6";          shield[5].shield_stat[0] = 2;shield[5].shield_stat[1]= 2;shield[5].shield_stat[2]= 2;
    shield[6].name_object = "shield 7";          shield[6].shield_stat[0] = 2;shield[6].shield_stat[1]= 2;shield[6].shield_stat[2]= 2;
    shield[7].name_object = "shield 8";          shield[7].shield_stat[0] = 2;shield[7].shield_stat[1]= 2;shield[7].shield_stat[2]= 2;
    shield[8].name_object = "shield 9";          shield[8].shield_stat[0] = 2;shield[8].shield_stat[1]= 2;shield[8].shield_stat[2]= 2;
    shield[9].name_object = "shield 10";         shield[9].shield_stat[0] = 2;shield[9].shield_stat[1]= 2;shield[9].shield_stat[2]= 2;
}

void get_item_boss(){
    int b = character[now_player].luk()*0.7;
    int a = rand()%100+1;
    int c = a+b;
    int d;
    int ea;
    string e[3] = {"sword","potion","shield"};
    int i = rand()%3;
    int command_item_boss;
    int potion_random = rand()%2;

    if(potion_random = 0){
         ea = rand()%3+1;
    }
    if(potion_random = 1){
         ea = rand()%6+1;
    }


    if(c >95){     //5
        d = 9;
        i = 0;
    }
    if(c > 85 && c <= 95){  //10
        d = 8;
        i = 0;
    }
    if(c > 70 && c <= 85){ //15
        d = 7;
        i = 0;    }
    if(c > 50 && c <= 70){ //20
        d = rand()%3+4;
        i = 0;
    }
    if(c > 0 && c <= 50){ // 50
        d = rand()%3+1;
        i = 2;
    }
    if(e[i] == "sword"){
        cout << "You get the " << sword[d].name_object << "Stat : STR = " << sword[d].sword_stat[0] << "  AGI = " << sword[d].sword_stat[1] << "  Luk = " << sword[d].sword_stat[2] << endl;
        cout << "Choose (1):OK (2):Cancel " ;
        cin >> command_item_boss;
        if(command_item_boss = 1){
        character[now_player].weapon = d;
        }
        else character[now_player].weapon = character[now_player].weapon;

    }
    if(e[i] == "potion"){
        cout << "You get a " << potion[potion_random].name_object << "  " << ea << " EA"<< endl;
        if(potion_random = 0){
        character[now_player].green_potion += ea;
        }
        if(potion_random = 1){
        character[now_player].red_potion += ea;
        }
    }
    if(e[i] == "shield"){
        cout << "You get the " << shield[d].name_object << "Stat : VIT = " << shield[d].shield_stat[0] << "  DEF = " << shield[d].shield_stat[1] << "  HP = " << shield[d].shield_stat[2] << endl;
        cout << "Choose (1):OK (2):Cancel " ;
        cin >> command_item_boss;
        if(command_item_boss = 1){
        character[now_player].shield = d;
        }
        else character[now_player].shield = character[now_player].shield;
    }
}

#endif // TITI_H
