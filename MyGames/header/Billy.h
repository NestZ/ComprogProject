#include<iostream>
#include<vector>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<string>
using namespace std;
struct chara{
	int stat[7],lv[3],inven[3],invenpotion[5];
	//[0]lv [1]nowexp//[2]need[exp] ,,statas str agi luk  vit atk hp
	int character;
	string clas;
};

struct monster{
	int stat[5],strig name;
};
void upstat();
void battlephase();
void edit ();
void init ();

	chara chara[6];monster Monster[4];
void init (){
	chara[0].clas="Berserker";chara[0].stat[0]=15;chara[0].stat[1]=5;chara[0].stat[2]=3;
	chara[0].stat[3]=7;chara[0].stat[4]=70;chara[0].stat[5]=75;chara[0].stat[6]=5;
	chara[1].clas="HolyKnight";chara[1].stat[0]=8;chara[1].stat[1]=7;chara[1].stat[2]=3;
	chara[1].stat[3]=13;chara[1].stat[4]=130;chara[1].stat[5]=40;chara[1].stat[6]=5;
	chara[2].clas="Thief";chara[2].stat[0]=5;chara[2].stat[1]=10;chara[2].stat[2]=14;
	chara[2].stat[3]=5;chara[2].stat[4]=50;chara[2].stat[5]=25;chara[2].stat[6]=5;
	chara[3].clas="B";chara[3].stat[0]=7;chara[3].stat[1]=3;chara[3].stat[2]=10;
	chara[3].stat[3]=10;chara[3].stat[4]=100;chara[3].stat[5]=35;chara[3].stat[6]=5;
	chara[4].clas="B1";chara[4].stat[0]=10;chara[4].stat[1]=10;chara[4].stat[2]=3;
	chara[4].stat[3]=7;chara[4].stat[4]=70;chara[4].stat[5]=50;chara[4].stat[6]=5;
	chara[5].clas="B2";chara[5].stat[0]=6;chara[5].stat[1]=6;chara[5].stat[2]=6;
	chara[5].stat[3]=6;chara[5].stat[4]=60;chara[5].stat[5]=30;chara[5].stat[6]=6;

	monster[0].name = "kak";monster[0].stat[0]=5;monster[0].stat[1]=400;monster[0].stat[2]=4;monster[0].stat[3]=3;monster[0].stat[4]=7;
	monster[1].name = "Shadow";monster[1].stat[0]=12;monster[1].stat[1]=800;monster[1].stat[2]=12;monster[1].stat[3]=6;monster[1].stat[4]=12;
	monster[2].name = "high";monster[2].stat[0]=17;monster[2].stat[1]=1600;monster[2].stat[2]=22;monster[2].stat[3]=18;monster[2].stat[4]=20;

	character[0].std_str=15; character[0].std_luk=5; character[0].std_agi=3; character[0].std_vit=7;
	character[0].std_HP=70; character[0].std_ATK=75; character[0].std_Defense=5;

	character[1].std_str=8; character[1].std_luk=7; character[1].std_agi=3; character[1].std_vit=13;
	character[1].std_HP=130; character[1].std_ATK=40; character[1].std_Defense=5;

	character[2].std_str=5; character[2].std_luk=10; character[2].std_agi=14; character[2].std_vit=5;
	character[2].std_HP=50; character[2].std_ATK=25; character[2].std_Defense=5;

	character[3].std_str=7; character[3].std_luk=3; character[3].std_agi=10; character[3].std_vit=10;
	character[3].std_HP=100; character[3].std_ATK=35; character[3].std_Defense=5;

	character[4].std_str=10; character[4].std_luk=10; character[4].std_agi=3; character[4].std_vit=7;
	character[4].std_HP=70; character[4].std_ATK=50; character[4].std_Defense=5;

	character[5].std_str=6; character[5].std_luk=6; character[5].std_agi=6; character[5].std_vit=6;
	character[5].std_HP=60; character[5].std_ATK=30; character[5].std_Defense=5;
}
void upstat(){
	//0 lv 1nowexp 2needexp
			int x=0;
			chara[now_player].lv[2]=(chara[now_player].lv[0]-1)*50+100;
			while(chara[now_player].lv[1]>=chara[now_player].lv[2]){
			chara[now_player].lv[0]++;
			chara[now_player].lv[1]=chara[now_player].lv[1]-chara[i].lv[2];
			chara[now_player].lv[2]=(chara[now_player].lv[0]-1)*50+100;
			x++;
			}
			while(chara[now_player].lv[1]<0){
				chara[now_player].lv[0]--;
				chara[now_player].lv[2]=(chara[now_player].lv[0]-1)*50+100;
				chara[nowplayer].lv[1]+=chara[now_player].lv[2];
				x--;
			}
	while(x>1){
	 	if(character[now_player].character_number==0){
			character[now_player].std_str+=3
			character[now_player].std_vit+=2
			character[now_player].std_agi+=2
			character[now_player].std_luk+=1
			character[now_player].std_Hp+=20
			character[now_player].std_Atk+=15
		}
	else if(character[now_player].character_number==1){
			character[now_player].std_str+=2
			character[now_player].std_vit+=3
			character[now_player].std_agi+=2
			character[now_player].std_luk+=1
			character[now_player].std_Hp+=30
			character[now_player].std_Atk+=10
		}
	else if(character[now_player].character_number==2){
			character[now_player].std_str+=2
			character[now_player].std_vit+=1
			character[now_player].std_agi+=3
			character[now_player].std_luk+=2
			character[now_player].std_Hp+=10
			character[now_player].std_Atk+=10
		}
	else if(character[now_player].character_number==3){
			character[now_player].std_str+=1
			character[now_player].std_vit+=3
			character[now_player].std_agi+=3
			character[now_player].std_luk+=1
			character[now_player].std_Hp+=10
			character[now_player].std_Atk+=5
		}
	else if(character[now_player].character_number==4){
			character[now_player].std_str+=3
			character[now_player].std_vit+=1
			character[now_player].std_agi+=1
			character[now_player].std_luk+=3
			character[now_player].std_Hp+=10
			character[now_player].std_Atk+=15
		}
	else if(character[now_player].character_number==5){
			character[now_player].std_str+=2
			character[now_player].std_vit+=2
			character[now_player].std_agi+=2
			character[now_player].std_luk+=2
			character[now_player].std_Hp+=20
			character[now_player].std_Atk+=10
		}
		x=x-1;
	}
		while(x<0){
	 	if(character[now_player].character_number--0){
			character[now_player].std_str-=3
			character[now_player].std_vit-=2
			character[now_player].std_agi-=2
			character[now_player].std_luk-=1
			character[now_player].std_Hp-=20
			character[now_player].std_Atk-=15
		}
	else if(character[now_player].character_number==1){
			character[now_player].std_str-=2
			character[now_player].std_vit-=3
			character[now_player].std_agi-=2
			character[now_player].std_luk-=1
			character[now_player].std_Hp-=30
			character[now_player].std_Atk-=10
		}
	else if(character[now_player].character_number==2){
			character[now_player].std_str-=2
			character[now_player].std_vit-=1
			character[now_player].std_agi-=3
			character[now_player].std_luk-=2
			character[now_player].std_Hp-=10
			character[now_player].std_Atk-=10
		}
	else if(character[now_player].character_number==3){
			character[now_player].std_str-=1
			character[now_player].std_vit-=3
			character[now_player].std_agi-=3
			character[now_player].std_luk-=1
			character[now_player].std_Hp-=10
			character[now_player].std_Atk-=5
		}
	else if(character[now_player].character_number==4){
			character[now_player].std_str-=3
			character[now_player].std_vit-=1
			character[now_player].std_agi-=1
			character[now_player].std_luk-=3
			character[now_player].std_Hp-=10
			character[now_player].std_Atk-=15
		}
	else if(character[now_player].character_number==5){
			character[now_player].std_str-=2
			character[now_player].std_vit-=2
			character[now_player].std_agi-=2
			character[now_player].std_luk-=2
			character[now_player].std_Hp-=20
			character[now_player].std_Atk-=10
		}
		x=x+1;
	}
}
	}

void battlephase (){
	string p,mp, f[3]={"p","r","s"};
	int speed,speedmon,percri,percrimon,dam,damm,outputdam,b=0,maxhp,maxhpmon;cridam,cridamm,money,decress;
	maxhp=player[now_player].gethp_max;
	maxhpmon=monster[monsterIndex][1];
	speed=player[now_player].getagi;speedmon=mon[g][2];
while(monster[monsterIndex].stat[1]>0&&character[now_player].hp_max>0){
	dam=player[now_player].getatk;damm=monster[monsterIndex].stat[0];
	percri=rand()%100;
	percrimon=rand()%100;
	if(speed>=speedmon){
			mp=f[rand()%3];
			cout<<"Choose\n1.Paper\n2.Rock\n3.Scissor"<<endl;
			cin>>p;
			if(percri<=character[now_player].luk*3){
				cridam=character[now_player].atk*0.5;
				cout<<"Player Critcalhit";
				}
			else{
				cridam=0;
			}
			if(p=="1")p="p";else if(p=="2")p="r";else p="s";
			if(p==mp){
			monster[monsterIndex].stat[1]=monster[monsterIndex]-(dam+cridam);
			outputdam=dam+cridam;
			}
			else if(p=="s"&&mp=="p"||p=="r"&&mp=="s"||p=="p"&&mp=="r"){
			monster[monsterIndex].stat[1]=monster[monsterIndex].stat[1]-((dam+cridam)*1.25);
			outputdam=((dam+cridam)*1.25);
			}
			else {
				monster[monsterIndex].stat[1]=monster[monsterIndex].stat[1]-(dam/2);
				outputdam=((dam+cridam)/2);
			}
			speedmon+=monster[monsterIndex].stat[2];
			speed=speed/2;
	cout<<" Damage "<<outputdam<<" Hp"<<player[now_player].gethp<<" Target Hp"<<monster[monsterIndex].stat[1]<<"/"<<maxhpmon<<endl;
	}

		}
			}
		if(percrimon<=monster[monsterIndex].stat[3]*3){
		cout<<"Monster Criticalhit";
		cridamm=monster[monsterIndex].stat[0]*0.5;
		}
		else{
			cridamm=0;
		}
		if((damm+cridam)-player[now_player].getdef<=0){
			damm=0;cridam=0;
		}
			player[now_player].gethp-=((damm+cridamm)-player[now_player].getdef);
		speedmon=speedmon/2;
		speed+=speed;


	if(monster[monsterIndex].stat[1]<0&&character[now_player].hp>0){
		if(monster[monsterIndex]==0){
				chara[now_player].lv[1]+=100;
				money=rand()%10+1;
				player[now_player].money+=money;
				cout<<"Your Win \n Recive Exp: 100 ";
		}
		if(monster[monsterIndex]==1){
			chara[now_player].lv[1]+=400;
			money=rand()%31+20;
			player[now_player].money+=money;
			cout<<"Your Win\n Recvive Exp:400";
		}
		if(monster[monsterIndex]==2){
			chara[now_player].lv[1]+=700;
			money=rand()%61+40;
			player[now_player].money+=money;
			cout<<"Your Win\n Recive Exp 700";
		}
		if(monster[monsterIndex]==3)P
		chara[now_player].lv[1]+=2000;
		money=rand()%101+100;
		player[now_player].money+=money;
		player[now_player].star++;
		cout<<"Your win\n Recive Exp 2000 ";

	}
	else if(character[now_player].hp<0&&mon[g][1]>0){
		decress=(chara[now_player].lv[0]-1)*50+100*2;
		chara[now_player].lv[1]-=decress;
		cout<<"Your Dead so Fucking noob\nExp :"<<-200;
			chara[now_player].vit=0;
	}

}

