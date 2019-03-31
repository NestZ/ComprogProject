#include<iostream>
#include<vector>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<string>
using namespace std;
struct chara{
	int stat[6],lv[3],inven[5];//[0]lv [1]nowexp//[2]need[exp] ,,statas str agi luk  vit atk hp
	string clas;
};
void upstat(chara []);
void battlephase(int n,int[]);
void edit ();
void init (chara);
	chara chara [6];int mon[5];
void init (){
		for(int i=0;i<6;i++){
		for(int j=0;j<3;j++){
			chara[i].lv[j]=0;
			chara[i].lv[0]=1;
			chara[i].inven[i]=0;
		}
	}

	chara[0].clas="Berserker";chara[0].stat[0]=15;chara[0].stat[1]=5;chara[0].stat[2]=3;chara[0].stat[3]=7;
	chara[1].clas="HolyKnight";chara[1].stat[0]=8;chara[1].stat[1]=7;chara[1].stat[2]=3;chara[1].stat[3]=13;
	chara[2].clas="Thief";chara[2].stat[0]=5;chara[2].stat[1]=10;chara[2].stat[2]=18;chara[2].stat[3]=5;
}
void upstat(){
	for(int i=0;i<3;i++){
		chara[i].lv[2]=(chara[i].lv[0]-1)*50+100;
		if(chara[i].lv[1]>=chara[i].lv[2]){
			chara[i].lv[0]++;
			chara[i].lv[1]=chara[i].lv[1]-chara[i].lv[2];
		}
 int x;x=chara[i].lv[0];
	while(x>1){
	 	if(i==0){
			for(int j=0;j<4;j++){
			chara[i].stat[0]+=2;
			chara[i].stat[j]+=1;
				}
		}
	else if(i==1){
		for(int j=0;j<4;j++){
			chara[i].stat[3]+=2;
			chara[i].stat[j]+=1;
		}
	}
	else if(i==3){
		for(int j=0;j<4;j++){
			chara[i].stat[1]+=2;
			chara[i].stat[2]+=2;
			chara[i].stat[j]+=1;
		}
	}
}
	chara[i].stat[4]=chara[i].stat[0]*7.5;
	chara[i].stat[5]=chara[i].stat[3]*10;
	x--;
		}
			}
void battlephase (int n,int mon[]){
	for(int i=0;i<5;i++){
		mon[i]=rand()%5+5;
	}
	mon[1]=rand()%400+100;
	mon[4]=mon[0]*5;
	cout<<"Your Stat "<<"Str "<<"Agi "<<"Luk "<<"ATK "<<"HP "<<endl<<"\t   "<<chara[n].stat[0]<<"  "<<chara[n].stat[1]<<"  "<<chara[n].stat[2]<<"  "<<chara[n].stat[4]<<"  "<<chara[n].stat[5]<<"  "<<endl;
	cout<<"Mons Stat "<<"Str "<<"Agi "<<"Luk "<<"ATK "<<"HP "<<endl<<"\t   "<<mon[0]<<"   "<<mon[2]<<"   "<<mon[3]<<"  "<<mon[4]<<"  "<<mon[1]<<endl;
	string p,mp;
	int speed,speedmon,percri,percrimon,dam,damm,cds=0;
	dam=chara[n].stat[4];damm=mon[0];
	char g[3]={'p','s','r'};
	speed=chara[n].stat[1];speedmon=mon[2];
while(mon[1]>0&&chara[n].stat[5]>0){
	percri=rand()%100;
	percrimon=rand()%100;
	mp=g[rand()%3];
	if(speed>=speedmon){
		cout<<"Pls Enter p,r,s";
		cin>>p;
	if(percri<=chara[n].stat[2]*3){
		dam=chara[n].stat[4]*1.5;
		cout<<"Player Critcalhit";
	}
		if(p=="a"){
			mon[1]=mon[1]-dam;
			speed=speed/2;
		}
		else if(p=="s"){
			cout<<"Using Skill"<<endl<<"1.Rage";
			cin>>p;
			if(p=="1"&&cds==0){
				dam=dam*2;
				cds=4;
			}
			mon[1]=mon[1]-dam;
			speed=speed/2;
		}
		else {
			dam=dam/2;
		mon[1]=mon[1]-dam;
		speed=speed/2;
	}
	speedmon+=mon[2];
	cout<<" Damage "<<dam<<" Hp"<<chara[n].stat[5]<<" Target Hp"<<mon[1]<<endl<<p<<" "<<mp<<endl;
}
	else {
		
		if(percrimon<=mon[3]*3){
		cout<<"Monster Criticalhit";
		damm=mon[0]*1.5;
		}
		chara[n].stat[5]=chara[n].stat[5]-damm;
		speedmon=speedmon/2;
		cout<<" Monster Damage"<<damm<<" Hp"<<chara[n].stat[5]<<" Target Hp"<<mon[1]<<endl;
	}
	dam=chara[n].stat[4];
	damm-mon[0];
	cds--;
}
	
	if(mon[1]<0&&chara[n].stat[5]>0){
		chara[n].lv[1]+=100;
		cout<<"Your Win \n Recive Exp: "<<100;
	}
	else if(chara[n].stat[5]<0&&mon[1]>0){
		chara[n].lv[1]-=200;
		cout<<"Your Dead so Fucking noob\nExp :"<<-200;
		chara[n].stat[5]=0;
	}
	else if(chara[n].stat[5]==0&&mon[1]==0){
		cout<<"Draw";
	}

}
