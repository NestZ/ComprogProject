#include<iostream>
#include<vector>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<string>
using namespace std;
struct chara{
	int stat[7],lv[3],inven[3],invenpotion[5];
	//[0]lv [1]nowexp//[2]need[exp] ,,statas str agi luk  vit hp atk
	int character;
	string clas;
};

struct monster{
	int stat[7],strig name;
	int lv,maxhp;
};
void upstat();
void battlephase();
void edit ();
void init ();
									
	Player chara [6];Monster Monster[4];
void init (){
	
	chara[0].clas="Berserker";chara[0].stat[0]=15;chara[0].stat[1]=5;chara[0].stat[2]=3;
	chara[0].stat[3]=7;chara[0].stat[4]=5;chara[0].stat[5]=75;
	chara[1].clas="HolyKnight";chara[1].stat[0]=8;chara[1].stat[1]=7;chara[1].stat[2]=3;
	chara[1].stat[3]=13;chara[1].stat[4]=5;chara[1].stat[5]=40;
	chara[2].clas="Thief";chara[2].stat[0]=5;chara[2].stat[1]=10;chara[2].stat[2]=14;
	chara[2].stat[3]=5;chara[2].stat[4]=5;chara[2].stat[5]=25;
	chara[3].clas="B";chara[3].stat[0]=7;chara[3].stat[1]=3;chara[3].stat[2]=10;
	chara[3].stat[3]=10;chara[3].stat[4]=5;chara[3].stat[5]=35;
	chara[4].clas="B1";chara[4].stat[0]=10;chara[4].stat[1]=10;chara[4].stat[2]=3;
	chara[4].stat[3]=7;chara[4].stat[4]=5;chara[4].stat[5]=50;
	chara[5].clas="B2";chara[5].stat[0]=6;chara[5].stat[1]=6;chara[5].stat[2]=6;
	chara[5].stat[3]=6;chara[5].stat[4]=6;chara[5].stat[5]=30;
	
	str agi luk  vit atk hp def
	monster[0].stat[0]=3;monster[0].stat[1]=4;monster[0].stat[2]=3;monster[0].stat[3]=40;monster[0].stat[4]=15;monster[0].stat[5]=400;monster[0].stat[6]=6;monster[0].lv=5;
	monster[1].stat[0]=6;monster[1].stat[1]=12;monster[1].stat[2]=6;monster[1].stat[3]=80;monster[1].stat[4]=30;monster[1].stat[5]=800;monster[1].stat[6]=12;monster[1].lv=15;
	monster[2].stat[0]=10;monster[2].stat[1]=22;monster[2].stat[2]=18;monster[2].stat[3]=120;monster[2].stat[4]=50;monster[2].stat[5]=1200;monster[2].stat[6]=18;monster[2].lv=20;
	monster[3].stat[0]=16;monster[3].stat[1]=27;monster[3].stat[2]=22;monster[3].stat[3]=300;monster[3].stat[4]=80;monster[3].stat[5]=3000;monster[3].stat[6]=22;monster[3].lv=30;
	monster[4].stat[0]=20;monster[4].stat[1]=29;monster[3].stat[2]=25;monster[3].stat[3]=350;monster[3].stat[4]=100;monster[3].stat[5]=3500;monster[3].stat[6]=24;monster[4].lv=35;
	monster[5].stat[0]=24;monster[5].stat[1]=31;monster[3].stat[2]=27;monster[3].stat[3]=400;monster[3].stat[4]=120;monster[3].stat[5]=4000;monster[3].stat[6]=26;monster[5].lv=40;
	monster[0].maxhp=300;monster[1].maxhp=800;monster[2].maxhp=1200;monster[3]=3000;.maxhpmonster[4].maxhp=3500;monster[5].maxhp=4000;
	
	character[0].std_str=15; character[0].std_luk=3; character[0].std_agi=5; character[0].std_vit=7; 
	character[0].std_HP=70; character[0].std_ATK=75; character[0].std_Defense=5;
	
	character[1].std_str=8; character[1].std_luk=3; character[1].std_agi=7; character[1].std_vit=13; 
	character[1].std_HP=130; character[1].std_ATK=40; character[1].std_Defense=5;
	
	character[2].std_str=5; character[2].std_luk=14; character[2].std_agi=10; character[2].std_vit=5; 
	character[2].std_HP=50; character[2].std_ATK=25; character[2].std_Defense=5;
	
	character[3].std_str=7; character[3].std_luk=10; character[3].std_agi=3; character[3].std_vit=10; 
	character[3].std_HP=100; character[3].std_ATK=35; character[3].std_Defense=5;
	
	character[4].std_str=10; character[4].std_luk=3; character[4].std_agi=10; character[4].std_vit=7; 
	character[4].std_HP=70; character[4].std_ATK=50; character[4].std_Defense=5;
	
	character[5].std_str=6; character[5].std_luk=6; character[5].std_agi=6; character[5].std_vit=6; 
	character[5].std_HP=60; character[5].std_ATK=30; character[5].std_Defense=5;
	
}
void upstat(){
	//0 lv 1nowexp 2needexp
			int x=0;
			characterss[now_player].lv[2]=(characterss[now_player].lv[0]-1)*50+100;
			while(characterss[now_player].lv[1]>=chara[now_player].lv[2]){
			characters[now_player].lv[0]++;
			characters[now_player].lv[1]=characters[now_player].lv[1]-characters[now_players].lv[2];
			characters[now_player].lv[2]=(characters[now_player].lv[0]-1)*50+100;
			x++;
			}
			while(chara[now_player].lv[1]<0){
				characters[now_player].lv[0]--;
				characters[now_player].lv[2]=(characters[now_player].lv[0]-1)*50+100;
				characters[nowplayer].lv[1]+=characters[now_player].lv[2];
				x--;
			}
	while(x>1){
	 	if(characters[now_player].character_number==0){
			characters[now_player].std_str+=3
			characters[now_player].std_vit+=2
			characters[now_player].std_agi+=2
			characters[now_player].std_luk+=1
			characters[now_player].std_Hp+=20
			characters[now_player].std_Atk+=15
		}
	else if(characters[now_player].characters_number==1){
			characters[now_player].std_str+=2
			characters[now_player].std_vit+=3
			characters[now_player].std_agi+=2
			characters[now_player].std_luk+=1
			characters[now_player].std_Hp+=30
			characters[now_player].std_Atk+=10
		}
	else if(characters[now_player].characters_number==2){
			characters[now_player].std_str+=2
			characters[now_player].std_vit+=1
			characters[now_player].std_agi+=3
			characters[now_player].std_luk+=2
			characters[now_player].std_Hp+=10
			characters[now_player].std_Atk+=10
		}
	else if(characters[now_player].characters_number==3){
			characters[now_player].std_str+=1
			characters[now_player].std_vit+=3
			characters[now_player].std_agi+=3
			characters[now_player].std_luk+=1
			characters[now_player].std_Hp+=10
			characters[now_player].std_Atk+=5
		}
	else if(characters[now_player].characters_number==4){
			characters[now_player].std_str+=3
			characters[now_player].std_vit+=1
			characters[now_player].std_agi+=1
			characters[now_player].std_luk+=3
			characters[now_player].std_Hp+=10
			characters[now_player].std_Atk+=15
		}
	else if(characters[now_player].characters_number==5){
			characters[now_player].std_str+=2
			characters[now_player].std_vit+=2
			characters[now_player].std_agi+=2
			characters[now_player].std_luk+=2
			characters[now_player].std_Hp+=20
			characters[now_player].std_Atk+=10
		}
		x=x-1;
	}
		while(x<0){
	 	if(characters[now_player].characters_number--0){
			characters[now_player].std_str-=3
			characters[now_player].std_vit-=2
			characters[now_player].std_agi-=2
			characters[now_player].std_luk-=1
			characters[now_player].std_Hp-=20
			characters[now_player].std_Atk-=15
		}
	else if(characters[now_player].characters_number==1){
			characters[now_player].std_str-=2
			characters[now_player].std_vit-=3
			characters[now_player].std_agi-=2
			characters[now_player].std_luk-=1
			characters[now_player].std_Hp-=30
			characters[now_player].std_Atk-=10
		}
	else if(characters[now_player].characters_number==2){
			characters[now_player].std_str-=2
			characters[now_player].std_vit-=1
			characters[now_player].std_agi-=3
			characters[now_player].std_luk-=2
			characters[now_player].std_Hp-=10
			characters[now_player].std_Atk-=10
		}
	else if(characters[now_player].characters_number==3){
			characters[now_player].std_str-=1
			characters[now_player].std_vit-=3
			characters[now_player].std_agi-=3
			characters[now_player].std_luk-=1
			characters[now_player].std_Hp-=10
			characters[now_player].std_Atk-=5
		}
	else if(characters[now_player].characters_number==4){
			characters[now_player].std_str-=3
			characters[now_player].std_vit-=1
			characters[now_player].std_agi-=1
			characters[now_player].std_luk-=3
			characters[now_player].std_Hp-=10
			characters[now_player].std_Atk-=15
		}
	else if(characters[now_player].characters_number==5){
			characters[now_player].std_str-=2
			characters[now_player].std_vit-=2
			characters[now_player].std_agi-=2
			characters[now_player].std_luk-=2
			characters[now_player].std_Hp-=20
			characters[now_player].std_Atk-=10
		}
		x=x+1;
	}
}
	}

void battlephase (){
	string p,mp, f[3]={"p","r","s"};
	int speed,speedmon,percri,percrimon,dam,damm,outputdam,b=0,maxhp,maxhpmon;cridam,cridamm,money,decress;
	maxhp=player[now_player].getHp_max;
	maxhpmon=monster[monsterIndex][1];
	speed=player[now_player].getAgi;speedmon=mon[monsterIndex].stat[2];
while(monster[monsterIndex].stat[1]>0&&character[now_player].hp_max>0){
	dam=player[now_player].getAtk;damm=monster[monsterIndex].stat[0];
	percri=rand()%100;
	percrimon=rand()%100;
	if(speed>=speedmon){
			mp=f[rand()%3+1];
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
			monster[monsterIndex].stat[1]=(monster[monsterIndex].stat[1])-(dam+cridam-monster[monsterIndex].stat[4]);
			outputdam=dam+cridam;
			}
			else if(p=="s"&&mp=="p"||p=="r"&&mp=="s"||p=="p"&&mp=="r"){
			monster[monsterIndex].stat[1]=monster[monsterIndex].stat[1]-((dam+cridam-monster[monsterIndex].stat[4])*1.25);
			outputdam=((dam+cridam)*1.25);
			}
			else {
				monster[monsterIndex].stat[1]=monster[monsterIndex].stat[1]-((dam+cridam-monster[monsterIndex].stat[4])/2);
				outputdam=((dam+cridam-monster[monsterIndex].stat[4])/2);
			}
			speedmon+=monster[monsterIndex].stat[2];
			speed=speed/2;
	cout<<" Damage "<<outputdam<<" Hp"<<player[now_player].getHp<<" Target Hp"<<monster[monsterIndex].stat[1]<<"/"<<maxhpmon<<endl;
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
		if((damm+cridam)-player[now_player].getDef<=0){
			damm=0;cridam=0;
		}
			player[now_player].getHp-=((damm+cridamm)-player[now_player].getDef);
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

