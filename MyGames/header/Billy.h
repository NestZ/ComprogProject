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
	int stat[5],difficult[6];
};
void monster
void upstat();
void battlephase(int n,int[][4],int g);
void edit ();
void init ();
									
	Player chara [6]; Monster[4];
	int main(){
		init();
		upstat();
		chara[1].inven[3]=1;
		chara[1].inven[4]=1;
		battlephase(1,mon,0);
	}
void init (){
		for(int i=0;i<6;i++){
		for(int j=0;j<3;j++){
			chara[i].lv[j]=0;
			chara[i].lv[0]=1;
		}
	}
	
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
	

	monster[0].stat[0]=5;monster[0].stat[1]=400;monster[0].stat[2]=4;monster[0].stat[3]=3;monster[0].stat[4]=7;
	monster[1].stat[0]=12;monster[1].stat[1]=800;monster[1].stat[2]=12;monster[1].stat[3]=6;monster[1].stat[4]=12;
	monster[2].stat[0]=17;monster[2].stat[1]=1600;monster[2].stat[2]=22;monster[2].stat[3]=18;monster[2].stat[4]=20;
	
	
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
		chara[nowplayer].lv[2]=(chara[i].lv[0]-1)*50+100;
		if(chara[nowplayer].lv[1]>=chara[nowplayer].lv[2]){
			chara[nowplayer].lv[0]++;
			chara[nowplayer].lv[1]=chara[nowplayer].lv[1]-chara[i].lv[2];

 int x;x=chara[i].lv[0];
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
}
	}

void battlephase (int n,int mon[][4],int g){
	cout<<"Your Stat "<<"Str "<<"Agi "<<"Luk "<<"ATK "<<"HP "<<endl<<"\t   "<<chara[n].stat[0]<<"  "<<chara[n].stat[1]<<"  "<<chara[n].stat[2]<<"  "<<chara[n].stat[4]<<"  "<<chara[n].stat[5]<<"  "<<chara[n].stat[6]<<endl;
	cout<<"Mons Stat "<<"Str "<<"Agi "<<"Luk "<<"ATK "<<"HP "<<endl<<"\t   "<<mon[g][0]<<"   "<<mon[g][2]<<"   "<<mon[g][3]<<"  "<<mon[g][4]<<"  "<<mon[g][1]<<endl;
	string p,mp, f[3]={"p","r","s"};
	int speed,speedmon,percri,percrimon,dam,damm,outputdam,b=0,maxhp,maxhpmon;cridam,cridamm;
	maxhp=character[now_player].hp_max;
	maxhpmon=mon[g][1];
	dam=character[now_player].atk;damm=mon[g][0];
	speed=character[now_player].agi;speedmon=mon[g][2];
while(mon[g][1]>0&&character[now_player].hp_max>0){
	percri=rand()%100;
	percrimon=rand()%100;
	if(speed>=speedmon){
		cout<<"Pls Select"<<endl<< "1.Attack "<<endl<<"2.Use Item"<<endl;
		cin>>p;
		if(p=="1"){
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
			mon[g][1]=mon[g][1]-(dam+cridam);
			outputdam=dam+cridam;
			}
			else if(p=="s"&&mp=="p"||p=="r"&&mp=="s"||p=="p"&&mp=="r"){
			mon[g][1]=mon[g][1]-((dam+cridam)*1.25);
			outputdam=((dam+cridam)*1.25);
			}
			else {
				mon[g][1]=mon[g][1]-(dam/2);
				outputdam=((dam+cridam)/2);
			}
			speedmon+=mon[g][2];
			speed=speed/2;
	cout<<" Damage "<<outputdam<<" Hp"<<chara[n].stat[5]<<" Target Hp"<<mon[g][1]<<"/"<<maxhpmon<<endl;
}
	//bag
	else if(p=="2"){
				cout<<"1.Use Red Potion "<<"Your have Red Potion "<<chara[n].inven[3]<<" EA"<<endl<<"2.Use Green Potion "<<"Your have Green Potion "<<chara[n].inven[4]<<"EA"<<endl;
			cin>>p;
			if(p=="1"){
				if(chara[nowplayer].invenpotion[0]>0){
					b=20;
					chara[nowplayer].invenpotion[0]-=1;
					if(character[nowplayer].hp+=20>maxhp){
					b=(maxhp-character[nowplayer].hp_max);
						}
				cout<<chara[nowplayer].stat[5]<<"+"<<b;
				chara[nowplayer].stat[5]+=b;
			}
				else {
				cout<<"You Not have a potion\n";
				continue;
		}
	}
			if(p=="2"){
				if(chara[nowplayer].invenpotion[1]>0){
					b=30;
					chara[nowplayer].invenpotion[1]-=1;
				if(character[nowplayer].hp+=30>maxhp){
					b=(maxhp-character[nowplayer].hp);
						}
				character[nowplayer].hp_max+=b;
			}
				else {
				cout<<"You Not have a potion\n";
				continue;
			}
	}
}
}
		
		if(percrimon<=mon[g][3]*3){
		cout<<"Monster Criticalhit";
		cridamm=mon[g][0]*1.5;
		}
		else{
			cridamm=0;
		}
		if((damm+cridam)-character[nowplayer].def<=0){
			damm+cridam=0;
		}
			character[nowplayer].hp-=((damm+cridam)-character[nowplayer].def);
		speedmon=speedmon/2;
		speed+=speed;
		cout<<" Monster Damage"<<damm<<" Hp"<<chara[n].stat[5]<<"/"<<maxhp<<" Target Hp"<<mon[g][1]<<"/"<<maxhpmon<<endl;
}
	
	if(mon[g][1]<0&&character[nowplayer].hp>0){
		chara[nowplayer].lv[1]+=100;
		cout<<"Your Win \n Recive Exp: "<<100;
	}
	else if(character[nowplayer].hp<0&&mon[g][1]>0){
		chara[nowplayer].lv[1]-=200;
		cout<<"Your Dead so Fucking noob\nExp :"<<-200;
			chara[nowplayer].vit=0;
	}

}

