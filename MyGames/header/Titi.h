#ifndef TITI_H
#define TITI_H
#include <iostream>
#include <cstdlib>

using namespace std;

struct object{
    int sword_stat[3],potion_effect; // 0str 1agi 2luk
    string name_object;
};

void inoutstat_object();
void get_item(string name,object [],object [],char [],int xx);
void Equip_item(chara chara[],int n_2,object sword[],int xx);

object sword[10];
object potion[5];
void inputstat_object(){
    object sword[10];
    object potion[5];
    sword[0].name_object = "Kusanagi";          sword[0].sword_stat[0] = 3;sword[0].sword_stat[1] = 1;sword[0].sword_stat[2] = 2;
    sword[1].name_object = "Durandal";          sword[1].sword_stat[0] = 3;sword[1].sword_stat[1] = 1;sword[1].sword_stat[2] = 2;
    sword[2].name_object = "Muramasas";         sword[2].sword_stat[0] = 3;sword[2].sword_stat[1] = 1;sword[2].sword_stat[2] = 2;
    sword[3].name_object = "Murasame";          sword[3].sword_stat[0] = 3;sword[3].sword_stat[1] = 1;sword[3].sword_stat[2] = 2;
    sword[4].name_object = "Masamune";          sword[4].sword_stat[0] = 3;sword[4].sword_stat[1] = 1;sword[4].sword_stat[2] = 2;
    sword[5].name_object = "Shusui";            sword[5].sword_stat[0] = 3;sword[5].sword_stat[1] = 1;sword[5].sword_stat[2] = 2;
    sword[6].name_object = "Yubashiri";         sword[6].sword_stat[0] = 3;sword[6].sword_stat[1] = 1;sword[6].sword_stat[2] = 2;
    sword[7].name_object = "Kitetsu Sandai";    sword[7].sword_stat[0] = 3;sword[7].sword_stat[1] = 1;sword[7].sword_stat[2] = 2;
    sword[8].name_object = "Wado Ichimonji";    sword[8].sword_stat[0] = 3;sword[8].sword_stat[1] = 1;sword[8].sword_stat[2] = 2;
    sword[9].name_object = "Excalibur";         sword[9].sword_stat[0] = 3;sword[9].sword_stat[1] = 1;sword[9].sword_stat[2] = 2;

    potion[0].name_object ="extra vit";     potion[0].potion_effect = 3;
    potion[1].name_object ="extra atk";     potion[1].potion_effect = 3;
    potion[2].name_object ="extra luk";     potion[2].potion_effect = 3;
    potion[3].name_object ="Green potion";  potion[3].potion_effect = 3;
    potion[4].name_object ="Red potion";    potion[4].potion_effect = 3;
}

void get_item(string name ,object sword[],object potion[],chara chara[],int xx){
    int n = rand()%100+1;
    int a = rand()%5;
    int n_2,n_3,x;

    if(n >= 90){
        n_2 = rand()%2+8;
    }
    else if(n >=70 && n <90){
        n_2 = rand()%2+6;
    }
    else if(n >=40 && n <70){
        n_2 = rand()%2+4;
    }
    else if(n >=0 && n <50){
        n_2 = rand()%4;
    }


    if(name == "sword"){
        cout << "You get " << sword[n_2].name_object << endl;
        cout << "1 to Equip or 2 to Drop";
        cin >> x;
        switch(x){
            case 1: cout << "You Equip";
                    Equip_item(chara,n_2,sword,xx);
                    break;
            case 2: cout << "You Drop";
                    break;
            default:cin >> x;
        }
    }
    if(name == "potion"){
        cout << "you get " << potion[a].name_object;
    }
}

void Equip_item(chara chara[],int n_2,object sword[],int xx){
    chara[xx].stat[0] +=  sword[n_2].sword_stat[0];
    chara[xx].stat[1] +=  sword[n_2].sword_stat[1];
    chara[xx].stat[2] +=  sword[n_2].sword_stat[2];
}
#endif // TITI_H
