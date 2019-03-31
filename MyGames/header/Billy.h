#ifndef BILLY_H
#define BILLY_H
#include<iostream>
#include<vector>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<string>
using namespace std;
struct chara{
	int stat[6],lv[3];//[0]lv [1]nowexp//[2]need[exp] ,,statas str agi luk  vit atk hp
	string clas;
	int inven[3];
};
void upstat(chara a[]);
void battlephase(chara a,int[]);
	chara chara [6]
	int mon[5];
	for(int i=0;i<6;i++){
		for(int j=0;j<3;j++){
			chara[i].lv[j]=0;
			chara[i].lv[0]=1;
		}
	}

	chara[0].clas="Berserker";chara[0].stat[0]=15;chara[0].stat[1]=5;chara[0].stat[2]=3;chara[0].stat[3]=7;
	chara[1].clas="HolyKnight";chara[1].stat[0]=8;chara[1].stat[1]=7;chara[1].stat[2]=3;chara[1].stat[3]=13;
	chara[2].clas="Thief";chara[2].stat[0]=5;chara[2].stat[1]=10;chara[2].stat[2]=18;chara[2].stat[3]=5;

void upstat(chara a[]){
for(int i=0;i<3;i++){
		a[i].lv[2]=(a[i].lv[0]-1)*50+100;
		if(a[i].lv[1]>=a[i].lv[2]){
			a[i].lv[0]++;
			a[i].lv[1]=a[i].lv[1]-a[i].lv[2];
			a[i].iven[i]=0;
		}
 int x;x=a[i].lv[0];
	while(x>1){
	 if(i==0){
		for(int j=0;j<4;j++){
			a[i].stat[0]+=2;
			a[i].stat[j]+=1;
		}
}
	else if(i==1){
	
		for(int j=0;j<4;j++){
			a[i].stat[3]+=2;
			a[i].stat[j]+=1;
		}
	}
	else if(i==3){
		for(int j=0;j<4;j++){
			a[i].stat[1]+=2;
			a[i].stat[2]+=2;
			a[i].stat[j]+=1;
		}
	}
		}
			a[i].stat[4]=a[i].stat[0]*7.5;
			a[i].stat[5]=a[i].stat[3]*10;
			x--;
			}
				}
				
void battlephase (chara a,int mon[]){
	for(int i=0;i<5;i++){
		mon[i]=rand()%5+5;
	}
	mon[1]=rand()%400+100;
	mon[4]=mon[0]*5;
	cout<<"Your Stat "<<"Str "<<"Agi "<<"Luk "<<"ATK "<<"HP "<<endl<<"\t   "<<a.stat[0]<<"  "<<a.stat[1]<<"  "<<a.stat[2]<<"  "<<a.stat[5]<<"  "<<a.stat[4]<<"  "<<endl;
	cout<<"Mons Stat "<<"Str "<<"Agi "<<"Luk "<<"ATK "<<"HP "<<endl<<"\t   "<<mon[0]<<"   "<<mon[2]<<"   "<<mon[3]<<"  "<<mon[4]<<"  "<<mon[1]<<endl;
	string p,mp;
	int speed,speedmon,percri,percrimon,dam,damm;
	dam=a.stat[4];damm=mon[0];
	char g[3]={'p','s','r'};
	speed=a.stat[1];speedmon=mon[2];
while(mon[1]>0&&a.stat[5]>0){
	percri=rand()%100;
	percrimon=rand()%100;
	mp=g[rand()%3];
	if(speed>=speedmon){
		cout<<"Pls Enter p,r,s";
		cin>>p;
	if(percri<=a.stat[2]*3){
		dam=a.stat[4]*1.5;
		cout<<"Player Critcalhit";
	}
		if(p==mp){
			mon[1]=mon[1]-dam;
			speed=speed/2;
		}
		else if((p=="p"&&mp=="r")||(p=="s"&&mp=="p")||(p=="r"&&mp=="s")){
			dam=dam*1.25;
			mon[1]=mon[1]-dam;
			speed=speed/2;
		}
		else {
			dam=dam/2;
		mon[1]=mon[1]-dam;
		speed=speed/2;
	}
	speedmon+=mon[2];
	cout<<" Damage "<<dam<<" Hp"<<a.stat[5]<<" Target Hp"<<mon[1]<<endl<<p<<" "<<mp<<endl;
}
	else {
		
		if(percrimon<=mon[3]*3){
		cout<<"Monster Criticalhit";
		damm=mon[0]*1.5;
		}
		a.stat[5]=a.stat[5]-damm;
		speedmon=speedmon/2;
		cout<<" Monster Damage"<<damm<<" Hp"<<a.stat[5]<<" Target Hp"<<mon[1]<<endl;
	}
	dam=a.stat[4];
	damm-mon[0];
}
	
	if(mon[1]<0&&a.stat[5]>0){
		a.lv[1]+=100;
		cout<<"Your Win \n Recive Exp: "<<100;
	}
	else if(a.stat[5]<0&&mon[1]>0){
		a.lv[1]-=200;
		cout<<"Your Dead so Fucking noob\nExp :"<<-200;
		a.stat[5]=0;
	}
	else if(a.stat[5]==0&&mon[1]==0){
		cout<<"Draw";
	}

}

#endif // BILLY_H

