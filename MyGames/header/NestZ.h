#ifndef NESTZ_GAME_H
#define NESTZ_GAME_H
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <stack>
#include <vector>
#include <fstream>
#include <cmath>

using namespace std;
using namespace sf;

class Game;
class Player;
struct itemStat;
struct accessory;
struct chara;
struct monster;
class NestZpath;

typedef class NestZpath{
    public:
        int pathEf;
        double X;
        double Y;
        int goPath_1;
        int goPath_2;
        int lastPathCon = 0;
        vector<int> nextPathNum_1;
        vector<int> nextPathNum_2;
        vector<int> nextPath(int);
}P;
P Path[76];

vector<int> NestZpath::nextPath(int lastPath){
    if(lastPathCon == 0){
        if(lastPath == goPath_1)return nextPathNum_1;
        else if(lastPath == goPath_2) return nextPathNum_2;
    }
    else if(lastPathCon != 0){
        if(lastPath == goPath_1)return nextPathNum_1;
        else if(lastPath == goPath_2 || lastPath == lastPathCon) return nextPathNum_2;
    }
    return nextPathNum_1;
}

struct chara{
	int stat[6],lv[3];
	string clas;
};
chara characters[6];

struct monster{
	int stat[7]; //str agi luk vit atk hp def
	int lv;
	int maxhp;
	string name;
}monster[6];

struct itemStat{
    int sword_stat[3];
    int potion_effect;
    int shield_stat[3];
    int price;
    string name_object;
    string Des;
};
itemStat sword[10];
itemStat shield[10];
itemStat potion[2];

struct accessory{
    string name;
    string Des;
    int price;
    int extra_vit = 0;
    int extra_atk = 0;
    int extra_luck = 0;
    int extra_str = 0;
    int extra_agi = 0;
}accessory[10];

class Player{
    public:
        //Variables
        int character_number;
        int level;
        int exp;
        int NestZ_nowPath;
        int hp;
        int weaponIndex;
        int shieldIndex;
        int accessoryIndex;
        int star;
        int money;
        int std_str;
        int std_vit;
        int std_agi;
        int std_luk;
        int std_atk;
        int std_def;
        int red_potion;
        int green_potion;
        int moveNum;
        int bossIndex;
        vector<int> allPath;
        //Function
        Player();
        int getAtk();
        int getDef();
        int getStr();
        int getVit();
        int getAgi();
        int getLuk();
        int HpMax();
};

Player::Player(){
    level = 1;
    exp = 0;
    money = 1000;
    red_potion = 10;
    green_potion = 10;
    star = 0;
    weaponIndex = 0;
    shieldIndex = -1;
    accessoryIndex = -1;
    NestZ_nowPath = 0;
    bossIndex = 3;
    allPath.push_back(0);
}

int Player::getAtk(){
    return std_atk + getStr() * 500 + (accessoryIndex > -1 ? accessory[accessoryIndex].extra_atk:0);
}
int Player::getDef(){
    return std_def + getVit() + (shieldIndex > -1 ? shield[shieldIndex].shield_stat[1]:0);
}
int Player::getAgi(){
    return std_agi * 200 + (accessoryIndex > -1 ? accessory[accessoryIndex].extra_agi:0) + sword[weaponIndex].sword_stat[1];
}
int Player::getStr(){
    return  std_str + (accessoryIndex > -1 ? accessory[accessoryIndex].extra_str:0) + sword[weaponIndex].sword_stat[0];
}
int Player::getLuk(){
    return std_luk + (accessoryIndex > -1 ? accessory[accessoryIndex].extra_luck:0) + sword[weaponIndex].sword_stat[2];
}
int Player::getVit(){
    return std_vit + (accessoryIndex > -1 ? accessory[accessoryIndex].extra_vit:0) + (shieldIndex > -1 ? shield[shieldIndex].shield_stat[0]:0);
}
int Player::HpMax(){
    return getVit() * 10;
}

class Game{
    public:
        //Window
        Game();
        void run();
        void initWindow();
        void initVariables();
        void initWindowVariables();
        void initGlobalVariables();
        void initFont();
        void update();
        Event updateSfmlEvent();
        void render();
        bool checkMouseClick();
        double windowMidWidth();
        double windowMidHeight();
        template <typename T>
        double getObjWidth(T);
        template <typename T>
        double getObjHeight(T);
        template <typename T>
        void Swap(T &, T&);
        void updateMouseIcon();
        bool checkEscape();
        //Menu
        void initMenuVariables();
        void checkMouseClick(int);
        void setMenuButton(Text &, int);
        void drawMenu();
        void updateMousePos();
        void updateMenuButton();
        //Setting
        void initSettingVariables();
        void drawSetting();
        void updateBackButtonST();
        void updatePlusMinus(int);
        void updateSettingValue();
        void updateSettingIni();
        //ChoosePlayers
        void drawChoosePlayers();
        void setChoosePlayersButton(Text &, int);
        void initChoosePlayersVariables();
        void updateChoosePlayersButton();
        void updateBackButtonHMP();
        //ChooseCharacters
        void initChooseCharactersVariables();
        void drawChooseCharacters();
        void updateCharacterIcon();
        void setCharacterIcon(Sprite &, int);
        void chooseState(int);
        void randomPick(vector<string> &);
        void updateChoosingState();
        void updateChoosed();
        void updateBackButtonCC();
        void resetCC();
        void setPlayerStat();
        //InsertName
        void initInsertNameVariables();
        void drawInsertName();
        void setInsertNameText();
        void updateInsertNameTextBoxEvent(Event);
        void updateInsertedName(char);
        void setCinText(Text &, int);
        void updateBackButtonIPN();
        void resetIPN();
        bool isValidCharacter(char);
        bool checkUsedName(string);
        void initMob();
        //Playing
        int loseExp(int);
        int loseMoney(int);
        void drawPlaying();
        void initPlayingVariables();
        void updateView();
        void updateEscape();
        void updateMiniMenuClick();
        void drawUI();
        void updateUI();
        void updateTurn();
        void diceState();
        void randomDice();
        void updateLevel();
        void updatePlayingState();
        void usePotion(int);
        void waitDiceAni(unsigned int);
        void ask(int,int,bool = true);
        void updateAsk();
        void dunAsk(int);
        void updateDunAsk(int);
        void shopAsk();
        void updateShopAsk();
        void updateShop();
        void updateAskBuy(int);
        void askBuy(int);
        void dungeon(int);
        void updateDungeon();
        void waitRPSAni(unsigned int);
        void randomRPS();
        void checkDeath();
        void resetMonster();
        void upgradeBoss();
        void death();
        void updateDeath();
        void updateMonDes();
        void getItem();
        void updateGetItem();
        int getMoney(int);
        int getExp(int);
        void initStat();
        void setItemStat();
        void RandomMoney();
        void useThisItem(bool);
        int Get_Heal(Player &);
        void updateAskGo();
        void NestZwalk(int &);
        void setPath();
        void moveDelay(int &);
        void moveDelayJunction(int &);
        void upstat();
        void checkwin();
        void get_item_boss();
        void Heal();
        int ranMoney();
    private:
        //Menu
        Vector2i mousePosView;
        Vector2f mousePos;
        int menuFontSize;
        Font menuFont;
        Text menuButton[3];
        Texture menuBGTexture;
        Sprite menuBGSprite;
        //Setting
        int horizontalScrollSpeed;
        int verticalScrollSpeed;
        int setting[3];
        char temp[20];
        string settingString;
        Texture settingBGTexture;
        Sprite settingBGSprite;
        Text settingText[3];
        Text settingValue[3];
        int settingFontSize;
        int settingIndex;
        int soundVolume;
        Texture plusT;
        Sprite plusS[3];
        Texture minusT;
        Sprite minusS[3];
        //Window
        enum States {Menu, ChoosePlayers, ChooseCharacters, Setting, InsertName, Playing};
        Texture backButtonTexture;
        Sprite backButtonSprite;
        Texture mouseIconTexture;
        Sprite mouseIconSprite;
        bool MouseReleased;
        bool keyReleased;
        int windowWidth;
        int windowHeight;
        const string GameName = "MyGame";
        RenderWindow *gameWindow;
        Event sfEvent;
        stack<States> state;
        //ChoosePlayers
        Texture choosePlayersBGTexture;
        Sprite choosePlayersBGSprite;
        Text chooseButton[3];
        int choosePlayersFontSize;
        int players;
        //ChooseCharacters
        int choosingCharacterFontSize;
        bool choosed[6];
        Texture charTexture[6];
        Sprite charSprite[6];
        Text className[6];
        Texture chooseCharacterBGTexture;
        Sprite chooseCharacterBGSprite;
        Texture choosedIconTexture;
        Sprite choosedIconSprite[6];
        Sprite spriteIcon;
        int randomIndexST;
        int randomIndexND;
        int chooseIndex;
        Text mainPlayerNameText;
        string mainPlayerNameString;
        Text playerChoosedName[4];
        int playerChoosedFontSize;
        //InsertName
        int cinTextFontSize;
        int insertedNameFontSize;
        bool isNameUsed;
        Text cinText;
        Text nameUsed;
        Event textInputEvent;
        char textEntered;
        const unsigned int MAX_TEXT = 6;
        vector<char> character;
        Text InsertedName;
        string name;
        vector<string> playerName;
        int playerNamingIndex;
        Texture insertNameBGTexture;
        Sprite insertNameBGSprite;
        //Playing
        Clock clock;
        float deltaTime;
        float totalTime;
        float animationSpeed;
        int diceNum;
        int shopPriceValue[24];
        int itemBuyIndex;
        int dunStates;
        int playerRPS;
        int monsterRPS;
        int fightTurn;
        int playerDes;
        int enemyDes;
        int now_player;
        int isPlayerWin;
        int playerSpeed;
        int monsterSpeed;
        int playerDamage;
        int monsterDamage;
        int critP;
        int defhp;
        int loseMon;
        int loseE;
        int getm;
        int gete;
        int healValue;
        int getMonValue;
        bool randomStart;
        bool isBagOpen;
        bool isDesOpen;
        bool isMenuOpen;
        bool isAskOpen;
        bool isDunAskOpen;
        bool isShopAskOpen;
        bool isShopOpen;
        bool isAskBuyOpen;
        bool isDeathOpen;
        bool isDun;
        bool isMonDes;
        bool isGetItem;
        bool isAskGo;
        bool isHealOpen;
        bool isGetMonOpen;
        bool canUsePotion;
        bool askTemp;
        bool issetstat=true;
        bool stateChange;
        Font cordiaFont;
        //vector<int> expMax;
        vector<int> needexp;
        vector<int> diceTemp;
        vector<int> timeTemp;
        vector<int> RPStempMon;
        vector<int> nextPath;
        int startExp;
        int UIFontSize;
        Texture mapTexture;
        Sprite mapSprite;
        Texture miniMenuT;
        Sprite miniMenuS;
        View camera;
        Text miniMenuText[3];
        int miniMenuFontSize;
        int arrIndex[3] = {-1,0,1};
        int turn;
        Player *player;
        int gameStates;
        int askKind;
        int askIndex;
        int buyNum;
        int playerChoosedPath;
        int x = 0;
        unsigned int moveTemp;
        Text UI_name;
        Text UI_hpText;
        Text UI_level;
        Text UI_class;
        Text UI_expText;
        Text UI_hpValue;
        Text UI_expValue;
        Text UI_diceValue;
        Text UI_hpSValue;
        Text UI_hpLValue;
        Text UI_swordName[10];
        Text UI_shieldName[10];
        Text UI_accName[10];
        Text UI_potionName[2];
        Text UI_swordDes[10];
        Text UI_shieldDes[10];
        Text UI_accDes[10];
        Text UI_potionDes[10];
        Text UI_playerNameDes;
        Text UI_statDes;
        Text UI_statDesR;
        Text UI_yes;
        Text UI_no;
        Text UI_ask;
        Text UI_dunYes;
        Text UI_dunNo;
        Text UI_dunAsk;
        Text UI_shopAsk;
        Text UI_shopYes;
        Text UI_shopNo;
        Text UI_quitShop;
        Text UI_playerMoney;
        Text UI_money;
        Text UI_shopPrice[24];
        Text UI_shopDes[24];
        Text UI_shopName[24];
        Text UI_askBuyOk;
        Text UI_askBuyCancle;
        Text UI_askBuy;
        Text UI_buyNum;
        Texture UI_DArrowT;
        Sprite UI_DArrowS;
        Texture UI_UArrowT;
        Sprite UI_UArrowS;
        Sprite UI_askBuyS[24];
        Sprite UI_askBuyWin;
        Sprite UI_shopItem[24];
        Texture UI_shopWinT;
        Sprite UI_shopWinS;
        Sprite UI_shopAskWin;
        Texture UI_shopIconT;
        Sprite UI_shopIconS;
        Texture UI_dunAskMonT[6];
        Sprite UI_dunAskMonS;
        Sprite UI_dunAskWin;
        Sprite UI_askWeaponS;
        Sprite UI_askShieldS;
        Sprite UI_askAccS;
        Sprite UI_askWin;
        Sprite UI_playerDesCharS;
        Texture UI_playerDesBGT;
        Sprite UI_playerDesBGS;
        Texture UI_accT[10];
        Sprite UI_accS;
        Texture UI_shieldT[10];
        Sprite UI_shieldS;
        Texture UI_swordT[10];
        Sprite UI_swordS;
        Texture UI_HpST;
        Sprite UI_HpSS;
        Texture UI_HpLT;
        Sprite UI_HpLS;
        Texture UI_bagT;
        Sprite UI_bagS;
        Texture UI_invenT;
        Sprite UI_invenS;
        Texture UI_diceT;
        Sprite UI_diceS;
        Texture UI_starT;
        Sprite UI_starS[3];
        Texture UI_maxExpT;
        Sprite UI_maxExpS;
        Texture UI_expBarT;
        Sprite UI_expBarS;
        Texture UI_expBorderT;
        Sprite UI_expBorderS;
        Texture UI_hpBorderT;
        Sprite UI_hpBorderS;
        Texture UI_maxHpT;
        Sprite UI_maxHpS;
        Texture UI_hpBarT;
        Sprite UI_hpBarS;
        Texture UI_charFaceT[6];
        Sprite UI_charFaceS;
        int monsterIndex;
        Text D_Turn;
        Text D_monHpValue;
        Text D_monHpText;
        Text D_monName;
        Text D_monLevel;
        Text D_deathText;
        Text D_deathOk;
        Text D_deathExp;
        Text D_deathExpValue;
        Text D_deathMoney;
        Text D_deathMoneyValue;
        Text D_monNameDes;
        Text D_monStatDes;
        Text D_monStatDesR;
        Text D_getText;
        Text D_getOk;
        Text D_getExp;
        Text D_getExpValue;
        Text D_getMoney;
        Text D_getMoneyValue;
        Sprite D_playerChar;
        Texture D_bgT;
        Sprite D_bgS;
        Sprite D_selectR;
        Sprite D_selectP;
        Sprite D_selectS;
        Texture D_rockT;
        Texture D_paperT;
        Texture D_scissorsT;
        Texture D_monRockT;
        Texture D_monPaperT;
        Texture D_monScissorsT;
        Sprite D_playerRPS;
        Sprite D_monsterRPS;
        Texture D_monsterFace[6];
        Sprite D_monsterFaceS;
        Sprite D_monHpBar;
        Sprite D_monHpBorder;
        Sprite D_monMaxHp;
        Texture D_monChar[6];
        Sprite D_monCharS;
        Sprite D_deathWin;
        Texture D_coin;
        Sprite D_coinS;
        Sprite D_monDesCharS;
        Sprite D_monDesBGS;
        Sprite D_getWin;
        Sprite D_getCoin;
        Sprite charOnMap[6];
        Sprite UI_askGoWin;
        Text UI_askGoPath[2];
        Text UI_askGoText;
        Texture UI_shopStarT;
        Text nameOnMap[4];
        Sprite healWin;
        Text healText;
        Text healOk;
        Sprite getMonWin;
        Text getMonText;
        Text getMonOk;
};

Game::Game(){
    initVariables();
    initWindow();
}

/*#############################################################################################################
##########                                                                                          ###########
##########                                       GAME WINDOW                                        ###########
##########                                                                                          ###########
#############################################################################################################*/

void Game::initVariables(){
    initFont();
    initMenuVariables();
    initInsertNameVariables();
    initChoosePlayersVariables();
    initChooseCharactersVariables();
    initWindowVariables();
    initSettingVariables();
    initGlobalVariables();
    initPlayingVariables();
}

void Game::initFont(){
    menuFontSize = 55;
    choosePlayersFontSize = 45;
    cinTextFontSize = 40;
    insertedNameFontSize = 45;
    choosingCharacterFontSize = 50;
    playerChoosedFontSize = 25;
    settingFontSize = 40;
    miniMenuFontSize = 40;
    UIFontSize = 35;
    menuFont.loadFromFile("font/ka1.ttf");
    cordiaFont.loadFromFile("font/cordia_0.ttf");
}

void Game::initWindow(){
    gameWindow = new RenderWindow(VideoMode(),GameName,Style::Fullscreen);
    this->gameWindow->setVerticalSyncEnabled(false);
    this->gameWindow->setFramerateLimit(60);
    this->gameWindow->setKeyRepeatEnabled(true);
    this->gameWindow->setMouseCursorGrabbed(true);
    this->gameWindow->setMouseCursorVisible(false);
}

void Game::initWindowVariables(){
    state.push(Menu);
    player = NULL;
    gameWindow = NULL;
    windowWidth = 1920;
    windowHeight = 1080;
    MouseReleased = true;
    keyReleased = true;
}

void Game::initGlobalVariables(){
    deltaTime = 0.0f;
    totalTime = 0.0f;
    backButtonTexture.loadFromFile("img/BackButton.png");
    backButtonTexture.setSmooth(true);
    backButtonSprite.setTexture(backButtonTexture);
    backButtonSprite.setOrigin(getObjWidth(backButtonSprite) / 2.0,getObjHeight(backButtonSprite) / 2.0);
    backButtonSprite.setPosition(50,windowHeight - 50);
    backButtonSprite.setScale(0.7,0.7);
    backButtonSprite.setRotation(-45);
    mouseIconTexture.loadFromFile("img/MouseCursor.png");
    mouseIconTexture.setSmooth(true);
    mouseIconSprite.setTexture(mouseIconTexture);
    mouseIconSprite.setOrigin(10,10);
    mouseIconSprite.setScale(0.6,0.6);
    animationSpeed = 0.2f;
    startExp = 100;
    now_player = 0;
    turn = 0;
}

void Game::render(){
        this->gameWindow->clear();
        switch(state.top()){
            case Menu:
                drawMenu();
                break;
            case ChoosePlayers:
                drawChoosePlayers();
                break;
            case InsertName:
                drawInsertName();
                break;
            case ChooseCharacters:
                drawChooseCharacters();
                break;
            case Playing:
                drawPlaying();
                break;
            case Setting:
                drawSetting();
                break;
        }
        this->gameWindow->display();
}

void Game::run(){
    while(this->gameWindow->isOpen()){
        update();
        render();
    }
}

void Game::update(){
    //Window
    deltaTime = clock.restart().asSeconds();
    updateSfmlEvent();
    updateMouseIcon();
    updateMousePos();
}

Event Game::updateSfmlEvent(){
    while (this->gameWindow->pollEvent(sfEvent))
        {
            switch(state.top()){
                case InsertName:
                    updateInsertNameTextBoxEvent(sfEvent);
                    break;
                default:
                    break;
            }
            if(sfEvent.type == Event::Closed){
                this->gameWindow->close();
            }
        }
    return sfEvent;
}

double Game::windowMidWidth(){
    return windowWidth / 2.0;
}

double Game::windowMidHeight(){
    return windowHeight / 2.0;
}

void Game::updateMouseIcon(){
    mouseIconSprite.setPosition(mousePos);
}

template <typename T>
double Game::getObjWidth(T obj){
    return obj.getLocalBounds().width;
}

template <typename T>
double Game::getObjHeight(T obj){
    return obj.getLocalBounds().height;
}

template <typename T>
void Game::Swap(T &a, T&b){
    T temp;
    temp = a;
    a = b;
    b = temp;
}

/*#############################################################################################################
##########                                                                                          ###########
##########                                       MENU                                               ###########
##########                                                                                          ###########
#############################################################################################################*/

void Game::initMenuVariables(){
    menuBGTexture.loadFromFile("img/bg.jpg");
    menuBGSprite.setTexture(menuBGTexture);
    menuButton[0].setString("PLAY");
    menuButton[1].setString("SETTING");
    menuButton[2].setString("QUIT");
    for(int i = 0;i < 3;i++){
        menuButton[i].setFillColor(Color::Black);
    }
}

void Game::drawMenu(){
    for(int i = 0;i < 3;i++){
        setMenuButton(menuButton[i],i);
    }

    updateMenuButton();

    this->gameWindow->draw(menuBGSprite);
    for(int i = 0;i < 3;i++){
        this->gameWindow->draw(menuButton[i]);
    }
    this->gameWindow->draw(mouseIconSprite);
}

void Game::setMenuButton(Text &text, int index){
    text.setFont(menuFont);
    text.setOutlineColor(Color::White);
    text.setOutlineThickness(4);
    text.setLetterSpacing(1.5);
    text.setCharacterSize(menuFontSize);
    text.setOrigin(getObjWidth(text)/2.0,getObjHeight(text)/2.0);
    text.setPosition(windowMidWidth(),(windowMidHeight() + index*100) + 15);
}

void Game::updateMousePos(){
    mousePosView = Mouse::getPosition(*this->gameWindow);
    mousePos = this->gameWindow->mapPixelToCoords(mousePosView);
}

void Game::updateMenuButton(){
    for(int i = 0;i < 3;i++){
        if(menuButton[i].getGlobalBounds().contains(mousePos)){
            menuButton[i].setScale(1.02,1.02);
            if(checkMouseClick()){
                switch(i){
                    case 0: //play
                        state.push(ChoosePlayers);
                        break;
                    case 1: //setting
                        state.push(Setting);
                        break;
                    case 2: //quit
                        this->gameWindow->close();
                }
            }
        }
        else menuButton[i].setScale(1,1);
    }
}

bool Game::checkMouseClick(){
    if(Mouse::isButtonPressed(Mouse::Left) && MouseReleased){
        MouseReleased = false;
        return true;
    }
    else if(!(Mouse::isButtonPressed(Mouse::Left))){
        MouseReleased = true;
        return false;
    }
    return false;
}

bool Game::checkEscape(){
    if(Keyboard::isKeyPressed(Keyboard::Escape) && keyReleased){
        keyReleased = false;
        return true;
    }
    else if(!Keyboard::isKeyPressed(Keyboard::Escape)){
        keyReleased = true;
        return false;
    }
    return false;
}

/*#############################################################################################################
##########                                                                                          ###########
##########                                       SETTING                                            ###########
##########                                                                                          ###########
#############################################################################################################*/

void Game::initSettingVariables(){
    plusT.loadFromFile("img/Plus.png");
    minusT.loadFromFile("img/Minus.png");
    settingIndex = 3;
    settingBGTexture.loadFromFile("img/SettingBG.jpg");
    settingBGSprite.setTexture(settingBGTexture);
    settingText[0].setString("Vertical Scroll Speed ");
    settingText[1].setString("Horizontal Scroll Speed ");
    settingText[2].setString("Sound Volume ");
    for(int i = 0;i < settingIndex;i++){
        settingText[i].setFont(menuFont);
        settingText[i].setOutlineColor(Color::White);
        settingText[i].setOutlineThickness(3);
        settingText[i].setFillColor(Color::Black);
        settingText[i].setCharacterSize(settingFontSize);
        settingText[i].setPosition(300,(windowHeight / 4) * (i + 1));
    }
    for(int i = 0;i < 3;i++){
        plusS[i].setTexture(plusT);
        minusS[i].setTexture(minusT);
        plusS[i].setOrigin(getObjWidth(plusS[i]) / 2,getObjHeight(plusS[i]) / 2);
        minusS[i].setOrigin(getObjWidth(minusS[i]) / 2,getObjHeight(minusS[i]) / 2);
        plusS[i].setPosition(windowWidth - 300,settingText[i].getPosition().y);
        minusS[i].setPosition(windowWidth - 500,settingText[i].getPosition().y);
        plusS[i].setScale(0.8,0.8);
        minusS[i].setScale(0.8,0.8);
    }
    int i = 0;
    char format[] = "%s : %d";
    ifstream fileIn("Setting.ini");
    while(getline(fileIn,settingString)){
        sscanf(settingString.c_str(),format,temp,&setting[i]);
        i++;
    }
    fileIn.close();

    updateSettingValue();

    for(int i = 0;i < settingIndex;i++){
        settingValue[i].setFont(menuFont);
        settingValue[i].setOutlineColor(Color::White);
        settingValue[i].setOutlineThickness(3);
        settingValue[i].setFillColor(Color::Black);
        settingValue[i].setCharacterSize(settingFontSize);
        settingValue[i].setPosition(windowWidth - 400,settingText[i].getPosition().y);
    }
}

void Game::drawSetting(){
    this->gameWindow->draw(settingBGSprite);
    for(int i = 0;i < settingIndex;i++){
        settingText[i].setOrigin(0,getObjHeight(settingText[i]) / 2);
        this->gameWindow->draw(settingText[i]);
        settingValue[i].setOrigin(getObjWidth(settingValue[i]) / 2,getObjHeight(settingValue[i]) / 2);
        this->gameWindow->draw(settingValue[i]);
    }
    for(int i = 0;i < settingIndex;i++){
        updatePlusMinus(i);
        this->gameWindow->draw(plusS[i]);
        this->gameWindow->draw(minusS[i]);
    }
    updateSettingValue();
    updateBackButtonST();
    this->gameWindow->draw(backButtonSprite);
    updateMouseIcon();
    this->gameWindow->draw(mouseIconSprite);
}

void Game::updatePlusMinus(int index){
        if(plusS[index].getGlobalBounds().contains(mousePos)){
            plusS[index].setScale(0.9,0.9);
            if(checkMouseClick()){
                if(index != 2 && setting[index] < 40){
                    setting[index]++;
                }
                else if(index == 2 && setting[index] < 100){
                    setting[index]++;
                }
            }
        }
        else plusS[index].setScale(0.8,0.8);
        if(minusS[index].getGlobalBounds().contains(mousePos)){
            minusS[index].setScale(0.9,0.9);
            if(checkMouseClick()){
                if(setting[index] > 0){
                    setting[index]--;
                }
            }
        }
        else minusS[index].setScale(0.8,0.8);
}

void Game::updateSettingValue(){
    verticalScrollSpeed = setting[0];
    horizontalScrollSpeed = setting[1];
    soundVolume = setting[2];

    settingValue[0].setString(to_string(verticalScrollSpeed));
    settingValue[1].setString(to_string(horizontalScrollSpeed));
    settingValue[2].setString(to_string(soundVolume));
}

void Game::updateSettingIni(){
    ofstream fileOut("Setting.ini");
    fileOut << "VerticalScrollSpeed : " << setting[0] << "\n";
    fileOut << "HorizontalScrollSpeed : " << setting[1] << "\n";
    fileOut << "SoundVolume : " << setting[2] << "\n";
    fileOut.close();
}

void Game::updateBackButtonST(){
    if(backButtonSprite.getGlobalBounds().contains(mousePos)){
        backButtonSprite.setScale(0.7,0.7);
        if(checkMouseClick()){
            updateSettingIni();
            state.pop();
        }
    }
    else backButtonSprite.setScale(0.6,0.6);
    if(checkEscape()){
        updateSettingIni();
        state.pop();
    }
}

/*#############################################################################################################
##########                                                                                          ###########
##########                                   CHOOSE HOW MANY PLAYER                                 ###########
##########                                                                                          ###########
#############################################################################################################*/

void Game::initChoosePlayersVariables(){
    choosePlayersBGTexture.loadFromFile("img/choosePlayersBG.jpg");
    choosePlayersBGSprite.setTexture(choosePlayersBGTexture);
    chooseButton[0].setString("2 Players");
    chooseButton[1].setString("3 Players");
    chooseButton[2].setString("4 Players");
}

void Game::drawChoosePlayers(){
    updateChoosePlayersButton();
    updateBackButtonHMP();
    this->gameWindow->draw(choosePlayersBGSprite);
    this->gameWindow->draw(backButtonSprite);
    for(int i = 0;i < 3;i++){
        setChoosePlayersButton(chooseButton[i],i);
        this->gameWindow->draw(chooseButton[i]);
    }
    this->gameWindow->draw(mouseIconSprite);
}

void Game::setChoosePlayersButton(Text &text,int index){
    text.setFont(menuFont);
    text.setFillColor(Color::Black);
    text.setCharacterSize(choosePlayersFontSize);
    text.setOutlineColor(Color::White);
    text.setOutlineThickness(4);
    text.setLetterSpacing(1.5);
    text.setOrigin(getObjWidth(text)/2.0,getObjHeight(text)/2.0);
    text.setPosition(windowMidWidth(),windowHeight / 2 + 150 * arrIndex[index]);
}

void Game::updateChoosePlayersButton(){
    for(int i = 0;i < 3;i++){
        if(chooseButton[i].getGlobalBounds().contains(mousePos)){
            chooseButton[i].setScale(1.02,1.02);
            if(checkMouseClick()){
                switch(i){
                    case 0: //2 players
                        players = 2;
                        player = new Player[2];
                        break;
                    case 1: //3 players
                        players = 3;
                        player = new Player[3];
                        break;
                    case 2: //4 players
                        players = 4;
                        player = new Player[4];
                }
                state.push(InsertName);
            }
        }
        else chooseButton[i].setScale(1,1);
    }
}

void Game::updateBackButtonHMP(){
    if(backButtonSprite.getGlobalBounds().contains(mousePos)){
        backButtonSprite.setScale(0.7,0.7);
        if(checkMouseClick()){
            state.pop();
        }
    }
    else backButtonSprite.setScale(0.6,0.6);
    if(checkEscape()){
        state.pop();
    }
}

/*#############################################################################################################
##########                                                                                          ###########
##########                                       INSERT NAME                                        ###########
##########                                                                                          ###########
#############################################################################################################*/

void Game::initInsertNameVariables(){
    isNameUsed = false;
    playerNamingIndex = 0;
    setCinText(cinText,0);
    name = "";
    insertNameBGTexture.loadFromFile("img/insertNameBG.jpg");
    insertNameBGSprite.setTexture(insertNameBGTexture);
}

void Game::setCinText(Text &cinText,int index){
    cinText.setString("Enter player " + to_string(index + 1) + " name");
}

void Game::setInsertNameText(){
    cinText.setFont(menuFont);
    cinText.setFillColor(Color::Black);
    cinText.setCharacterSize(cinTextFontSize);
    cinText.setOutlineColor(Color::White);
    cinText.setOutlineThickness(4);
    cinText.setLetterSpacing(1.5);
    cinText.setOrigin(getObjWidth(cinText)/2.0,getObjHeight(cinText)/2.0);
    cinText.setPosition(windowMidWidth(),windowMidHeight() - 100);
    InsertedName.setFont(menuFont);
    InsertedName.setLetterSpacing(2);
    InsertedName.setFillColor(Color::White);
    InsertedName.setCharacterSize(insertedNameFontSize);
    InsertedName.setOrigin(getObjWidth(InsertedName)/2.0,getObjHeight(InsertedName)/2.0);
    InsertedName.setPosition(windowMidWidth(),windowMidHeight() + 100);
    nameUsed.setString("This name was used");
    nameUsed.setFont(menuFont);
    nameUsed.setFillColor(Color::Red);
    nameUsed.setCharacterSize(cinTextFontSize - 10);
    nameUsed.setOutlineColor(Color::White);
    nameUsed.setOutlineThickness(4);
    nameUsed.setOrigin(getObjWidth(nameUsed)/2.0,getObjHeight(nameUsed)/2.0);
    nameUsed.setPosition(windowMidWidth(),windowMidHeight() + 350);
}

void Game::drawInsertName(){
    setInsertNameText();
    this->gameWindow->draw(insertNameBGSprite);
    this->gameWindow->draw(backButtonSprite);
    updateBackButtonIPN();
    this->gameWindow->draw(cinText);
    this->gameWindow->draw(InsertedName);
    if(isNameUsed)this->gameWindow->draw(nameUsed);
    this->gameWindow->draw(mouseIconSprite);
}

void Game::updateInsertNameTextBoxEvent(Event InsertNameEvent){
    if(InsertNameEvent.type == Event::TextEntered){
        isNameUsed = false;
        textEntered = InsertNameEvent.text.unicode;
        updateInsertedName(textEntered);
    }
}

bool Game::isValidCharacter(char character){
    return  (character >= 48 && character <= 57)  ||  //Numbers
            (character >= 65 && character <= 90)  ||  //Uppercase
            (character >= 97 && character <= 122) ||  //Lowercase
            character == 32;    //Space
}

void Game::updateInsertedName(char insertedChar){
    if(isValidCharacter(insertedChar) && character.size() < MAX_TEXT){
        character.push_back(insertedChar);
    }
    else if(insertedChar == 8 && character.size() > 0){
        character.pop_back();
    }
    name = "";
    for(unsigned int i = 0;i < character.size();i++){
        name += character[i];
    }
    InsertedName.setString(name);
    if(insertedChar == 13 && name.size() > 0 && checkUsedName(name)){
        playerName.push_back(name);
        InsertedName.setString("");
        while(!character.empty()){
                character.pop_back();
        }
        if(playerNamingIndex < players - 1){
            playerNamingIndex++;
            setCinText(cinText,playerNamingIndex);
        }
        else {
            randomPick(playerName);
            initMob();
            state.push(ChooseCharacters);
        }
    }
    else if(insertedChar == 13 && name.size() > 0 && !checkUsedName(name)){
        isNameUsed = true;
    }
}

bool Game::checkUsedName(string checkingName){
    for(unsigned int i = 0;i < playerName.size();i++){
        if(checkingName == playerName[i])return false;
    }
    return true;
}

void Game::updateBackButtonIPN(){
    if(backButtonSprite.getGlobalBounds().contains(mousePos)){
        backButtonSprite.setScale(0.7,0.7);
        if(checkMouseClick()){
            resetIPN();
            state.pop();
        }
    }
    else backButtonSprite.setScale(0.6,0.6);
    if(checkEscape()){
        resetIPN();
        state.pop();
    }
}

void Game::resetIPN(){
    playerNamingIndex = 0;
    name = "";
    InsertedName.setString("");
    setCinText(cinText,playerNamingIndex);
    while(!playerName.empty()){
        playerName.pop_back();
    }
    while(!character.empty()){
        character.pop_back();
    }
}

/*#############################################################################################################
##########                                                                                          ###########
##########                                       CHOOSE CHARACTER                                   ###########
##########                                                                                          ###########
#############################################################################################################*/

void Game::initChooseCharactersVariables(){
    chooseIndex = 0;
    for(int i = 0;i < 6;i++)choosed[i] = false;
    charTexture[0].loadFromFile("img/Char1.png");
    charTexture[1].loadFromFile("img/Char2.png");
    charTexture[2].loadFromFile("img/Char3.png");
    charTexture[3].loadFromFile("img/Char4.png");
    charTexture[4].loadFromFile("img/Char5.png");
    charTexture[5].loadFromFile("img/Char6.png");
    for(int i = 0;i < 6;i++)charSprite[i].setTexture(charTexture[i]);
    chooseCharacterBGTexture.loadFromFile("img/chooseCharacterBG.jpg");
    chooseCharacterBGSprite.setTexture(chooseCharacterBGTexture);
    choosedIconTexture.loadFromFile("img/ChoosedArrow.png");
    for(int i = 0;i < 6;i++){
        choosedIconSprite[i].setTexture(choosedIconTexture);
        choosedIconSprite[i].setOrigin(getObjWidth(choosedIconSprite[i]) / 2.0,getObjHeight(choosedIconSprite[i]) / 2.0);
        choosedIconSprite[i].setScale(0.4,0.4);
    }
    mainPlayerNameText.setFillColor(Color::Black);
    mainPlayerNameText.setOutlineColor(Color::White);
    mainPlayerNameText.setOutlineThickness(4);
    for(int i = 0;i < 4;i++){
        playerChoosedName[i].setPosition(-300,-300);
    }
}

void Game::drawChooseCharacters(){
    for(int i = 0;i < 6;i++){
        className[i].setString(characters[i].clas);
        className[i].setFillColor(Color::Black);
        className[i].setOutlineColor(Color::White);
        className[i].setOutlineThickness(2.5);
        className[i].setFont(cordiaFont);
        className[i].setCharacterSize(UIFontSize + 10);
        className[i].setLetterSpacing(1.3);
    }
    this->gameWindow->draw(chooseCharacterBGSprite);
    this->gameWindow->draw(backButtonSprite);
    updateBackButtonCC();
    updateChoosingState();
    updateChoosed();
    this->gameWindow->draw(mainPlayerNameText);
    for(int i = 0;i < 6;i++){
        setCharacterIcon(charSprite[i],i);
        this->gameWindow->draw(charSprite[i]);
        this->gameWindow->draw(className[i]);
    }
    this->gameWindow->draw(mouseIconSprite);
}

void Game::setCharacterIcon(Sprite &sprite, int index){
    sprite.setOrigin(getObjWidth(sprite) / 2.0,getObjHeight(sprite) / 2.0);
    sprite.setPosition((index + 1) * (windowWidth / 7),windowMidHeight());
    className[index].setOrigin(getObjWidth(className[index]) / 2.0,getObjHeight(className[index]) / 2.0);
    className[index].setPosition((index + 1) * (windowWidth / 7),windowMidHeight() + 200);
}

void Game::randomPick(vector<string> &playerName){
    for(int i = 0;i < rand() % 100 + 1;i++){
        randomIndexST = rand() % players;
        do{
            randomIndexND = rand() % players;
        }while(randomIndexND == randomIndexST);
        Swap(playerName[randomIndexST],playerName[randomIndexND]);
    }
}

void Game::updateCharacterIcon(){
    for(int i = 0;i < 6;i++){
        if(charSprite[i].getGlobalBounds().contains(mousePos) && !choosed[i]){
            charSprite[i].setScale(1.1,1.1);
            if(checkMouseClick()){
                choosed[i] = true;
                player[chooseIndex].character_number = i;
                playerChoosedName[chooseIndex].setPosition(charSprite[i].getPosition().x,charSprite[i].getPosition().y - 130);
                if(chooseIndex < players - 1)chooseIndex++;
                else {

                    if(issetstat) {
                    	setPlayerStat();
                    	issetstat=false;
					}
                    state.push(Playing);
                }
            }
        }
        else charSprite[i].setScale(1,1);
        if(choosed[i] == true)charSprite[i].setColor(Color(128,128,128,255));
        else charSprite[i].setColor(Color(255,255,255,255));
    }
}

void Game::setPlayerStat(){
    for(int i = 0;i < players;i++){
        player[i].std_agi = characters[player[i].character_number].stat[1];
        player[i].std_atk = characters[player[i].character_number].stat[5];
        player[i].std_def = characters[player[i].character_number].stat[4];
        player[i].std_luk = characters[player[i].character_number].stat[2];
        player[i].std_str = characters[player[i].character_number].stat[0];
        player[i].std_vit = characters[player[i].character_number].stat[3];
        player[i].hp = player[i].HpMax();
    }
}

void Game::updateChoosingState(){
    updateCharacterIcon();
    mainPlayerNameString = playerName[chooseIndex] + " pick turn";
    mainPlayerNameText.setString(mainPlayerNameString);
    mainPlayerNameText.setCharacterSize(choosingCharacterFontSize);
    mainPlayerNameText.setFont(menuFont);
    mainPlayerNameText.setOrigin(getObjWidth(mainPlayerNameText) / 2,getObjHeight(mainPlayerNameText) / 2);
    mainPlayerNameText.setPosition(windowMidWidth(),120);
    for(int i = 0;i < players;i++){
        playerChoosedName[i].setFillColor(Color::Black);
        playerChoosedName[i].setOutlineColor(Color::White);
        playerChoosedName[i].setOutlineThickness(2.1);
        playerChoosedName[i].setFont(menuFont);
        playerChoosedName[i].setCharacterSize(playerChoosedFontSize);
        playerChoosedName[i].setString(playerName[i]);
        playerChoosedName[i].setOrigin(getObjWidth(playerChoosedName[i]) / 2.0,getObjHeight(playerChoosedName[i]) / 2.0);
        this->gameWindow->draw(playerChoosedName[i]);
    }
}

void Game::updateChoosed(){
    for(int i = 0;i < 6;i++){
        if(choosed[i] == true){
            choosedIconSprite[i].setPosition(charSprite[i].getPosition().x,charSprite[i].getPosition().y - 100);
            this->gameWindow->draw(choosedIconSprite[i]);
        }
    }
}

void Game::updateBackButtonCC(){
    if(backButtonSprite.getGlobalBounds().contains(mousePos)){
        backButtonSprite.setScale(0.7,0.7);
        if(checkMouseClick()){
            resetCC();
            resetIPN();
            state.pop();
        }
    }
    else backButtonSprite.setScale(0.6,0.6);
    if(checkEscape()){
        resetCC();
        resetIPN();
        state.pop();
    }
}

void Game::resetCC(){
    chooseIndex = 0;
    for(int i = 0;i < 6;i++)choosed[i] = false;
    for(int i = 0;i < 4;i++){
        playerChoosedName[i].setPosition(-300,-300);
    }
}

/*#############################################################################################################
##########                                                                                          ###########
##########                                       PLAYING                                            ###########
##########                                                                                          ###########
#############################################################################################################*/
void Game::initPlayingVariables(){
    isBagOpen = false;
    randomStart = false;
    isMenuOpen = false;
    isDesOpen = false;
    isAskOpen = false;
    isDunAskOpen = false;
    isShopAskOpen = false;
    isShopOpen = false;
    isAskBuyOpen = false;
    isDeathOpen = false;
    isGetItem = false;
    isAskGo = false;
    isHealOpen = false;
    isGetMonOpen = false;
    canUsePotion = true;
    askTemp = true;
    gameStates = 1;
    buyNum = 1;
    diceTemp.push_back(-1);
    RPStempMon.push_back(-1);
    int sum;
    int n;
    for(int i=0;i<29;i++){
        n=i*50+100;
        sum=sum+n;
        needexp.push_back(n);
    }
    setPath();
    setItemStat();
    mapTexture.loadFromFile("img/Map.jpg");
    mapSprite.setTexture(mapTexture);
    mapSprite.setPosition(0,0);
    miniMenuT.loadFromFile("img/miniMenuBG.png");
    miniMenuS.setTexture(miniMenuT);
    miniMenuS.setOrigin(getObjWidth(miniMenuS) / 2,getObjHeight(miniMenuS) / 2);
    miniMenuS.setScale(0.9,0.7);
    miniMenuS.setColor(Color(255,255,255,140));
    camera.setCenter(Vector2f(windowMidWidth(),windowMidHeight()));
    camera.setSize(Vector2f(1920,1080));
    camera.setViewport(FloatRect(0,0,1,1));
    miniMenuText[0].setString("Reseum");
    miniMenuText[1].setString("Setting");
    miniMenuText[2].setString("Main Menu");
    for(int i = 0;i < 3;i++){
        miniMenuText[i].setFillColor(Color::Black);
        miniMenuText[i].setOutlineColor(Color::White);
        miniMenuText[i].setOutlineThickness(3.5);
        miniMenuText[i].setFont(menuFont);
        miniMenuText[i].setCharacterSize(miniMenuFontSize);
    }
    UI_starT.loadFromFile("img/Star.png");
    UI_starT.setSmooth(true);
    for(int i = 0;i < 3;i++){
        UI_starS[i].setTexture(UI_starT);
        UI_starS[i].setScale(0.7,0.7);
    }
    UI_charFaceT[0].loadFromFile("img/Face1.png");
    UI_charFaceT[1].loadFromFile("img/Face2.png");
    UI_charFaceT[2].loadFromFile("img/Face3.png");
    UI_charFaceT[3].loadFromFile("img/Face4.png");
    UI_charFaceT[4].loadFromFile("img/Face5.png");
    UI_charFaceT[5].loadFromFile("img/Face6.png");
    UI_charFaceS.setPosition(110,110);
    UI_name.setFillColor(Color::Black);
    UI_name.setOutlineColor(Color::White);
    UI_name.setOutlineThickness(3.5);
    UI_name.setFont(menuFont);
    UI_name.setCharacterSize(UIFontSize);
    UI_name.setPosition(UI_charFaceS.getPosition().x,UI_charFaceS.getPosition().y + 130);
    UI_level.setFillColor(Color::Black);
    UI_level.setOutlineColor(Color::White);
    UI_level.setOutlineThickness(3.5);
    UI_level.setFont(menuFont);
    UI_level.setCharacterSize(UIFontSize);
    UI_level.setPosition(230,30);
    UI_hpBorderT.loadFromFile("img/HpBorder.png");
    UI_hpBorderS.setTexture(UI_hpBorderT);
    UI_hpBorderS.setPosition(360,85);
    UI_maxHpT.loadFromFile("img/HpBarMax.png");
    UI_maxHpS.setTexture(UI_maxHpT);
    UI_maxHpS.setPosition(360,85);
    UI_hpBarT.loadFromFile("img/HpBar.png");
    UI_hpBarS.setTexture(UI_hpBarT);
    UI_hpBarS.setPosition(362,85);
    UI_hpText.setString("HP");
    UI_hpText.setFillColor(Color::Black);
    UI_hpText.setOutlineColor(Color::White);
    UI_hpText.setOutlineThickness(3.5);
    UI_hpText.setFont(menuFont);
    UI_hpText.setCharacterSize(UIFontSize);
    UI_hpValue.setFillColor(Color::Black);
    UI_hpValue.setOutlineColor(Color::White);
    UI_hpValue.setOutlineThickness(2);
    UI_hpValue.setFont(cordiaFont);
    UI_hpValue.setCharacterSize(UIFontSize);
    UI_expBorderT.loadFromFile("img/HpBorder.png");
    UI_expBorderS.setTexture(UI_expBorderT);
    UI_expBorderS.setPosition(UI_hpBorderS.getPosition().x,UI_hpBorderS.getPosition().y + 55);
    UI_maxExpT.loadFromFile("img/HpBarMax.png");
    UI_maxExpS.setTexture(UI_maxHpT);
    UI_maxExpS.setPosition(UI_expBorderS.getPosition().x,UI_expBorderS.getPosition().y);
    UI_expBarT.loadFromFile("img/ExpBar.png");
    UI_expBarS.setTexture(UI_expBarT);
    UI_expBarS.setPosition(UI_hpBarS.getPosition().x,UI_expBorderS.getPosition().y);
    UI_expText.setString("EXP");
    UI_expText.setFillColor(Color::Black);
    UI_expText.setOutlineColor(Color::White);
    UI_expText.setOutlineThickness(3.5);
    UI_expText.setFont(menuFont);
    UI_expText.setCharacterSize(UIFontSize);
    UI_expValue.setFillColor(Color::Black);
    UI_expValue.setOutlineColor(Color::White);
    UI_expValue.setOutlineThickness(2);
    UI_expValue.setFont(cordiaFont);
    UI_expValue.setCharacterSize(UIFontSize);
    UI_diceT.loadFromFile("img/DiceIcon.png");
    UI_diceT.setSmooth(true);
    UI_diceS.setTexture(UI_diceT);
    UI_diceS.setOrigin(getObjWidth(UI_diceS) / 2,getObjHeight(UI_diceS) / 2);
    UI_diceS.setPosition(windowMidWidth(),windowMidHeight());
    UI_diceValue.setString("1");
    UI_diceValue.setFillColor(Color::Black);
    UI_diceValue.setOutlineColor(Color::White);
    UI_diceValue.setOutlineThickness(3.5);
    UI_diceValue.setFont(menuFont);
    UI_diceValue.setCharacterSize(UIFontSize + 30);
    UI_invenT.loadFromFile("img/Inventory.png");
    UI_invenT.setSmooth(true);
    UI_invenS.setTexture(UI_invenT);
    UI_invenS.setOrigin(getObjWidth(UI_invenS) / 2,getObjHeight(UI_invenS) / 2);
    UI_invenS.setPosition(350,1015);
    UI_invenS.setScale(1.3,1.1);
    UI_invenS.setColor(Color(255,255,255,200));
    UI_bagT.loadFromFile("img/Bag.png");
    UI_bagT.setSmooth(true);
    UI_bagS.setTexture(UI_bagT);
    UI_bagS.setOrigin(getObjWidth(UI_bagS) / 2,getObjHeight(UI_bagS) / 2);
    UI_bagS.setPosition(70,1015);
    UI_bagS.setScale(0.8,0.8);
    UI_HpST.loadFromFile("img/HpS.png");
    UI_HpSS.setTexture(UI_HpST);
    UI_HpSS.setOrigin(getObjWidth(UI_HpSS) / 2,getObjHeight(UI_HpSS) / 2);
    UI_HpSS.setPosition(UI_invenS.getPosition().x,UI_invenS.getPosition().y);
    UI_HpSS.setScale(0.65,0.65);
    UI_HpLT.loadFromFile("img/HpL.png");
    UI_HpLT.setSmooth(true);
    UI_HpLS.setTexture(UI_HpLT);
    UI_HpLS.setOrigin(getObjWidth(UI_HpLS) / 2,getObjHeight(UI_HpLS) / 2);
    UI_HpLS.setPosition(UI_invenS.getPosition().x + 68,UI_invenS.getPosition().y);
    UI_HpLS.setScale(0.65,0.65);
    UI_hpSValue.setFillColor(Color::Black);
    UI_hpSValue.setOutlineColor(Color::White);
    UI_hpSValue.setOutlineThickness(2.5);
    UI_hpSValue.setFont(cordiaFont);
    UI_hpSValue.setCharacterSize(UIFontSize - 5);
    UI_hpLValue.setFillColor(Color::Black);
    UI_hpLValue.setOutlineColor(Color::White);
    UI_hpLValue.setOutlineThickness(2.5);
    UI_hpLValue.setFont(cordiaFont);
    UI_hpLValue.setCharacterSize(UIFontSize - 5);
    UI_swordT[0].loadFromFile("img/Fist.png");
    UI_swordT[1].loadFromFile("img/Sword1.png");
    UI_swordT[2].loadFromFile("img/Sword2.png");
    UI_swordT[3].loadFromFile("img/Sword3.png");
    UI_swordT[4].loadFromFile("img/Sword4.png");
    UI_swordT[5].loadFromFile("img/Sword5.png");
    UI_swordT[6].loadFromFile("img/Sword6.png");
    UI_swordT[7].loadFromFile("img/Sword7.png");
    UI_swordT[8].loadFromFile("img/Sword8.png");
    UI_swordT[9].loadFromFile("img/Sword9.png");
    UI_shieldT[0].loadFromFile("img/Shield1.png");
    UI_shieldT[1].loadFromFile("img/Shield2.png");
    UI_shieldT[2].loadFromFile("img/Shield3.png");
    UI_shieldT[3].loadFromFile("img/Shield4.png");
    UI_shieldT[4].loadFromFile("img/Shield5.png");
    UI_shieldT[5].loadFromFile("img/Shield6.png");
    UI_shieldT[6].loadFromFile("img/Shield7.png");
    UI_shieldT[7].loadFromFile("img/Shield8.png");
    UI_shieldT[8].loadFromFile("img/Shield9.png");
    UI_shieldT[9].loadFromFile("img/Shield10.png");
    UI_accT[0].loadFromFile("img/Accessory1.png");
    UI_accT[1].loadFromFile("img/Accessory2.png");
    UI_accT[2].loadFromFile("img/Accessory3.png");
    UI_accT[3].loadFromFile("img/Accessory4.png");
    UI_accT[4].loadFromFile("img/Accessory5.png");
    UI_accT[5].loadFromFile("img/Accessory6.png");
    UI_accT[6].loadFromFile("img/Accessory7.png");
    UI_accT[7].loadFromFile("img/Accessory8.png");
    UI_accT[8].loadFromFile("img/Accessory9.png");
    UI_accT[9].loadFromFile("img/Accessory10.png");
    for(int i = 0;i < 10;i++){
        UI_swordName[i].setString(sword[i].name_object);
        UI_shieldName[i].setString(shield[i].name_object);
        UI_accName[i].setString(accessory[i].name);
        UI_swordDes[i].setString(sword[i].Des);
        UI_shieldDes[i].setString(shield[i].Des);
        UI_accDes[i].setString(accessory[i].Des);
        if(i < 2){
            UI_potionName[i].setString(potion[i].name_object);
            UI_potionName[i].setFillColor(Color::Black);
            UI_potionName[i].setOutlineColor(Color::White);
            UI_potionName[i].setOutlineThickness(2.5);
            UI_potionName[i].setFont(cordiaFont);
            UI_potionName[i].setCharacterSize(UIFontSize - 5);
            UI_potionDes[i].setString(potion[i].Des);
            UI_potionDes[i].setFillColor(Color::Black);
            UI_potionDes[i].setOutlineColor(Color::White);
            UI_potionDes[i].setOutlineThickness(2.5);
            UI_potionDes[i].setFont(cordiaFont);
            UI_potionDes[i].setCharacterSize(UIFontSize - 15);
            UI_potionDes[i].setLineSpacing(0.7);
        }
        UI_swordName[i].setFillColor(Color::Black);
        UI_swordName[i].setOutlineColor(Color::White);
        UI_swordName[i].setOutlineThickness(2.5);
        UI_swordName[i].setFont(cordiaFont);
        UI_swordName[i].setCharacterSize(UIFontSize - 5);
        UI_shieldName[i].setFillColor(Color::Black);
        UI_shieldName[i].setOutlineColor(Color::White);
        UI_shieldName[i].setOutlineThickness(2.5);
        UI_shieldName[i].setFont(cordiaFont);
        UI_shieldName[i].setCharacterSize(UIFontSize - 5);
        UI_accName[i].setFillColor(Color::Black);
        UI_accName[i].setOutlineColor(Color::White);
        UI_accName[i].setOutlineThickness(2.5);
        UI_accName[i].setFont(cordiaFont);
        UI_accName[i].setCharacterSize(UIFontSize - 5);
        UI_swordDes[i].setFillColor(Color::Black);
        UI_swordDes[i].setOutlineColor(Color::White);
        UI_swordDes[i].setOutlineThickness(2.5);
        UI_swordDes[i].setFont(cordiaFont);
        UI_swordDes[i].setCharacterSize(UIFontSize - 15);
        UI_swordDes[i].setLineSpacing(0.7);
        UI_shieldDes[i].setFillColor(Color::Black);
        UI_shieldDes[i].setOutlineColor(Color::White);
        UI_shieldDes[i].setOutlineThickness(2.5);
        UI_shieldDes[i].setFont(cordiaFont);
        UI_shieldDes[i].setCharacterSize(UIFontSize - 15);
        UI_shieldDes[i].setLineSpacing(0.7);
        UI_accDes[i].setFillColor(Color::Black);
        UI_accDes[i].setOutlineColor(Color::White);
        UI_accDes[i].setOutlineThickness(2.5);
        UI_accDes[i].setFont(cordiaFont);
        UI_accDes[i].setCharacterSize(UIFontSize - 15);
        UI_accDes[i].setLineSpacing(0.7);
    }
    UI_playerDesBGT.loadFromFile("img/miniMenuBG.png");
    UI_playerDesBGS.setTexture(UI_playerDesBGT);
    UI_playerDesBGS.setOrigin(getObjWidth(UI_playerDesBGS) / 2,getObjHeight(UI_playerDesBGS) / 2);
    UI_playerDesBGS.setPosition(windowMidWidth(),windowMidHeight());
    UI_playerDesBGS.setScale(1.1,1.1);
    UI_playerNameDes.setFillColor(Color::Black);
    UI_playerNameDes.setOutlineColor(Color::White);
    UI_playerNameDes.setOutlineThickness(3.5);
    UI_playerNameDes.setFont(cordiaFont);
    UI_playerNameDes.setCharacterSize(UIFontSize + 10);
    UI_statDes.setFillColor(Color::Black);
    UI_statDes.setOutlineColor(Color::White);
    UI_statDes.setOutlineThickness(2.5);
    UI_statDes.setFont(cordiaFont);
    UI_statDes.setCharacterSize(UIFontSize - 5);
    UI_statDes.setLineSpacing(1.2);
    UI_statDesR.setFillColor(Color::Black);
    UI_statDesR.setOutlineColor(Color::White);
    UI_statDesR.setOutlineThickness(2.5);
    UI_statDesR.setFont(cordiaFont);
    UI_statDesR.setCharacterSize(UIFontSize - 5);
    UI_statDesR.setLineSpacing(1.2);
    UI_askWin.setTexture(miniMenuT);
    UI_askWin.setOrigin(getObjWidth(UI_askWin) / 2,getObjHeight(UI_askWin) / 2);
    UI_askWin.setPosition(windowMidWidth(),windowMidHeight());
    UI_askWin.setScale(1.7,0.6);
    UI_askWin.setColor(Color(255,255,255,128));
    UI_ask.setString("Do you want to equip this item");
    UI_ask.setFillColor(Color::Black);
    UI_ask.setOutlineColor(Color::White);
    UI_ask.setOutlineThickness(2.5);
    UI_ask.setFont(menuFont);
    UI_ask.setCharacterSize(UIFontSize - 5);
    UI_yes.setString("YES");
    UI_yes.setFillColor(Color::Black);
    UI_yes.setOutlineColor(Color::White);
    UI_yes.setOutlineThickness(2.5);
    UI_yes.setFont(menuFont);
    UI_yes.setCharacterSize(UIFontSize - 5);
    UI_no.setString("NO");
    UI_no.setFillColor(Color::Black);
    UI_no.setOutlineColor(Color::White);
    UI_no.setOutlineThickness(2.5);
    UI_no.setFont(menuFont);
    UI_no.setCharacterSize(UIFontSize - 5);
    UI_dunAskWin.setTexture(miniMenuT);
    UI_dunAskWin.setOrigin(getObjWidth(UI_dunAskWin) / 2,getObjHeight(UI_dunAskWin) / 2);
    UI_dunAskWin.setPosition(windowMidWidth(),windowMidHeight());
    UI_dunAskWin.setScale(1.9,0.6);
    UI_dunAskWin.setColor(Color(255,255,255,128));
    UI_dunAsk.setString("Do you want to enter this dungeon");
    UI_dunAsk.setFillColor(Color::Black);
    UI_dunAsk.setOutlineColor(Color::White);
    UI_dunAsk.setOutlineThickness(2.5);
    UI_dunAsk.setFont(menuFont);
    UI_dunAsk.setCharacterSize(UIFontSize - 5);
    UI_dunYes.setString("YES");
    UI_dunYes.setFillColor(Color::Black);
    UI_dunYes.setOutlineColor(Color::White);
    UI_dunYes.setOutlineThickness(2.5);
    UI_dunYes.setFont(menuFont);
    UI_dunYes.setCharacterSize(UIFontSize - 5);
    UI_dunNo.setString("NO");
    UI_dunNo.setFillColor(Color::Black);
    UI_dunNo.setOutlineColor(Color::White);
    UI_dunNo.setOutlineThickness(2.5);
    UI_dunNo.setFont(menuFont);
    UI_dunNo.setCharacterSize(UIFontSize - 5);
    UI_dunAskMonT[0].loadFromFile("img/Green Circle.png");
    UI_dunAskMonT[1].loadFromFile("img/Yellow Circle.png");
    UI_dunAskMonT[2].loadFromFile("img/Red Circle.png");
    UI_dunAskMonT[3].loadFromFile("img/Boss Circle.png");
    UI_dunAskMonT[4].loadFromFile("img/Boss Circle.png");
    UI_dunAskMonT[5].loadFromFile("img/Boss Circle.png");
    UI_shopIconT.loadFromFile("img/Shop Icon.png");
    UI_shopIconS.setTexture(UI_shopIconT);
    UI_shopIconS.setOrigin(getObjWidth(UI_shopIconS) / 2,getObjHeight(UI_shopIconS) / 2);
    UI_shopIconS.setPosition(windowMidWidth(),windowMidHeight());
    UI_shopAsk.setString("Do you want to enter market");
    UI_shopAsk.setFillColor(Color::Black);
    UI_shopAsk.setOutlineColor(Color::White);
    UI_shopAsk.setOutlineThickness(2.5);
    UI_shopAsk.setFont(menuFont);
    UI_shopAsk.setCharacterSize(UIFontSize - 5);
    UI_shopYes.setString("YES");
    UI_shopYes.setFillColor(Color::Black);
    UI_shopYes.setOutlineColor(Color::White);
    UI_shopYes.setOutlineThickness(2.5);
    UI_shopYes.setFont(menuFont);
    UI_shopYes.setCharacterSize(UIFontSize - 5);
    UI_shopNo.setString("NO");
    UI_shopNo.setFillColor(Color::Black);
    UI_shopNo.setOutlineColor(Color::White);
    UI_shopNo.setOutlineThickness(2.5);
    UI_shopNo.setFont(menuFont);
    UI_shopNo.setCharacterSize(UIFontSize - 5);
    UI_shopAskWin.setTexture(miniMenuT);
    UI_shopAskWin.setOrigin(getObjWidth(UI_shopAskWin) / 2,getObjHeight(UI_shopAskWin) / 2);
    UI_shopAskWin.setPosition(windowMidWidth(),windowMidHeight());
    UI_shopAskWin.setScale(1.9,0.6);
    UI_shopAskWin.setColor(Color(255,255,255,128));
    UI_shopWinT.loadFromFile("img/Shop.png");
    UI_shopWinS.setTexture(UI_shopWinT);
    UI_shopWinS.setOrigin(getObjWidth(UI_shopWinS) / 2,getObjHeight(UI_shopWinS) / 2);
    UI_shopWinS.setPosition(windowMidWidth(),windowMidHeight());
    UI_quitShop.setString("QUIT");
    UI_quitShop.setFillColor(Color::Black);
    UI_quitShop.setOutlineColor(Color::White);
    UI_quitShop.setOutlineThickness(2.5);
    UI_quitShop.setFont(menuFont);
    UI_quitShop.setCharacterSize(UIFontSize);
    UI_playerMoney.setFillColor(Color::Black);
    UI_playerMoney.setOutlineColor(Color::White);
    UI_playerMoney.setOutlineThickness(2.5);
    UI_playerMoney.setFont(menuFont);
    UI_playerMoney.setCharacterSize(UIFontSize - 5);
    UI_money.setString("MONEY");
    UI_money.setFillColor(Color::Black);
    UI_money.setOutlineColor(Color::White);
    UI_money.setOutlineThickness(2.5);
    UI_money.setFont(menuFont);
    UI_money.setCharacterSize(UIFontSize - 5);
    UI_money.setPosition(windowMidWidth() + 70,windowMidHeight() + 202);
    UI_shopStarT.loadFromFile("img/Star.png");
    UI_shopItem[0].setTexture(UI_HpST);       UI_shopItem[1].setTexture(UI_HpLT);       UI_shopItem[2].setTexture(UI_swordT[1]);   UI_shopItem[3].setTexture(UI_swordT[2]);   UI_shopItem[4].setTexture(UI_swordT[3]);   UI_shopItem[5].setTexture(UI_swordT[4]);
    UI_shopItem[6].setTexture(UI_swordT[5]);  UI_shopItem[7].setTexture(UI_swordT[6]);  UI_shopItem[8].setTexture(UI_shieldT[0]);  UI_shopItem[9].setTexture(UI_shieldT[1]);  UI_shopItem[10].setTexture(UI_shieldT[2]); UI_shopItem[11].setTexture(UI_shieldT[3]);
    UI_shopItem[12].setTexture(UI_shieldT[4]);UI_shopItem[13].setTexture(UI_shieldT[5]);UI_shopItem[14].setTexture(UI_shieldT[6]); UI_shopItem[15].setTexture(UI_shieldT[7]); UI_shopItem[16].setTexture(UI_accT[0]);    UI_shopItem[17].setTexture(UI_accT[1]);
    UI_shopItem[18].setTexture(UI_accT[2]);   UI_shopItem[19].setTexture(UI_accT[3]);   UI_shopItem[20].setTexture(UI_accT[4]);    UI_shopItem[21].setTexture(UI_accT[5]);    UI_shopItem[22].setTexture(UI_accT[6]);    UI_shopItem[23].setTexture(UI_shopStarT);
    UI_askBuyS[0].setTexture(UI_HpST);       UI_askBuyS[1].setTexture(UI_HpLT);       UI_askBuyS[2].setTexture(UI_swordT[1]);   UI_askBuyS[3].setTexture(UI_swordT[2]);   UI_askBuyS[4].setTexture(UI_swordT[3]);   UI_askBuyS[5].setTexture(UI_swordT[4]);
    UI_askBuyS[6].setTexture(UI_swordT[5]);  UI_askBuyS[7].setTexture(UI_swordT[6]);  UI_askBuyS[8].setTexture(UI_shieldT[0]);  UI_askBuyS[9].setTexture(UI_shieldT[1]);  UI_askBuyS[10].setTexture(UI_shieldT[2]); UI_askBuyS[11].setTexture(UI_shieldT[3]);
    UI_askBuyS[12].setTexture(UI_shieldT[4]);UI_askBuyS[13].setTexture(UI_shieldT[5]);UI_askBuyS[14].setTexture(UI_shieldT[6]); UI_askBuyS[15].setTexture(UI_shieldT[7]); UI_askBuyS[16].setTexture(UI_accT[0]);    UI_askBuyS[17].setTexture(UI_accT[1]);
    UI_askBuyS[18].setTexture(UI_accT[2]);   UI_askBuyS[19].setTexture(UI_accT[3]);   UI_askBuyS[20].setTexture(UI_accT[4]);    UI_askBuyS[21].setTexture(UI_accT[5]);    UI_askBuyS[22].setTexture(UI_accT[6]);    UI_askBuyS[23].setTexture(UI_shopStarT);
    for(int i = 0;i < 24;i++){
        UI_shopItem[i].setOrigin(getObjWidth(UI_shopItem[i]) / 2,getObjHeight(UI_shopItem[i]) / 2);
        UI_shopItem[i].setPosition(710 + 100 * (i % 6),340 + 100 * (i / 6));
        UI_askBuyS[i].setOrigin(getObjWidth(UI_askBuyS[i]) / 2,getObjHeight(UI_askBuyS[i]) / 2);
        if(i > 1)UI_askBuyS[i].setPosition(windowMidWidth(),windowMidHeight() + 10);
        else UI_askBuyS[i].setPosition(windowMidWidth() - 50,windowMidHeight() + 10);
    }
    UI_shopPrice[0].setString("Price : " + to_string(potion[0].price) + " Coins");       UI_shopPrice[1].setString("Price : " + to_string(potion[1].price) + " Coins");  UI_shopPrice[2].setString("Price : " + to_string(sword[1].price) + " Coins");  UI_shopPrice[3].setString("Price : " + to_string(sword[2].price) + " Coins");  UI_shopPrice[4].setString("Price : " + to_string(sword[3].price) + " Coins");  UI_shopPrice[5].setString("Price : " + to_string(sword[4].price) + " Coins");
    UI_shopPrice[6].setString("Price : " + to_string(sword[5].price) + " Coins");        UI_shopPrice[7].setString("Price : " + to_string(sword[6].price) + " Coins");  UI_shopPrice[8].setString("Price : " + to_string(shield[0].price) + " Coins");  UI_shopPrice[9].setString("Price : " + to_string(shield[1].price) + " Coins");  UI_shopPrice[10].setString("Price : " + to_string(shield[2].price) + " Coins");  UI_shopPrice[11].setString("Price : " + to_string(shield[3].price) + " Coins");
    UI_shopPrice[12].setString("Price : " + to_string(shield[4].price) + " Coins");      UI_shopPrice[13].setString("Price : " + to_string(shield[5].price) + " Coins");  UI_shopPrice[14].setString("Price : " + to_string(shield[6].price) + " Coins");  UI_shopPrice[15].setString("Price : " + to_string(shield[7].price) + " Coins");  UI_shopPrice[16].setString("Price : " + to_string(accessory[0].price) + " Coins");  UI_shopPrice[17].setString("Price : " + to_string(accessory[1].price) + " Coins");
    UI_shopPrice[18].setString("Price : " + to_string(accessory[2].price) + " Coins");   UI_shopPrice[19].setString("Price : " + to_string(accessory[3].price) + " Coins");  UI_shopPrice[20].setString("Price : " + to_string(accessory[4].price) + " Coins");  UI_shopPrice[21].setString("Price : " + to_string(accessory[5].price) + " Coins");  UI_shopPrice[22].setString("Price : " + to_string(accessory[6].price) + " Coins");  UI_shopPrice[23].setString("Price : " + to_string(accessory[7].price) + " Coins");
    UI_shopName[0].setString(potion[0].name_object);       UI_shopName[1].setString(potion[1].name_object);     UI_shopName[2].setString(sword[1].name_object);     UI_shopName[3].setString(sword[2].name_object);     UI_shopName[4].setString(sword[3].name_object);     UI_shopName[5].setString(sword[4].name_object);
    UI_shopName[6].setString(sword[5].name_object);        UI_shopName[7].setString(sword[6].name_object);      UI_shopName[8].setString(shield[0].name_object);    UI_shopName[9].setString(shield[1].name_object);    UI_shopName[10].setString(shield[2].name_object);   UI_shopName[11].setString(shield[3].name_object);
    UI_shopName[12].setString(shield[4].name_object);      UI_shopName[13].setString(shield[5].name_object);    UI_shopName[14].setString(shield[6].name_object);   UI_shopName[15].setString(shield[7].name_object);   UI_shopName[16].setString(accessory[0].name);UI_shopName[17].setString(accessory[1].name);
    UI_shopName[18].setString(accessory[2].name);   UI_shopName[19].setString(accessory[3].name); UI_shopName[20].setString(accessory[4].name);UI_shopName[21].setString(accessory[5].name);UI_shopName[22].setString(accessory[6].name);UI_shopName[23].setString("Star");
    UI_shopDes[0].setString(potion[0].Des);       UI_shopDes[1].setString(potion[1].Des);     UI_shopDes[2].setString(sword[1].Des);     UI_shopDes[3].setString(sword[2].Des);     UI_shopDes[4].setString(sword[3].Des);     UI_shopDes[5].setString(sword[4].Des);
    UI_shopDes[6].setString(sword[5].Des);        UI_shopDes[7].setString(sword[6].Des);      UI_shopDes[8].setString(shield[0].Des);    UI_shopDes[9].setString(shield[1].Des);    UI_shopDes[10].setString(shield[2].Des);   UI_shopDes[11].setString(shield[3].Des);
    UI_shopDes[12].setString(shield[4].Des);      UI_shopDes[13].setString(shield[5].Des);    UI_shopDes[14].setString(shield[6].Des);   UI_shopDes[15].setString(shield[7].Des);   UI_shopDes[16].setString(accessory[0].Des);UI_shopDes[17].setString(accessory[1].Des);
    UI_shopDes[18].setString(accessory[2].Des);   UI_shopDes[19].setString(accessory[3].Des); UI_shopDes[20].setString(accessory[4].Des);UI_shopDes[21].setString(accessory[5].Des);UI_shopDes[22].setString(accessory[6].Des);UI_shopDes[23].setString("The Shining Star");
    for(int i = 0;i < 24;i++){
        UI_shopName[i].setFillColor(Color::Black);
        UI_shopName[i].setOutlineColor(Color::White);
        UI_shopName[i].setOutlineThickness(2.5);
        UI_shopName[i].setFont(cordiaFont);
        UI_shopName[i].setCharacterSize(UIFontSize - 5);
        UI_shopPrice[i].setFillColor(Color::Black);
        UI_shopPrice[i].setOutlineColor(Color::White);
        UI_shopPrice[i].setOutlineThickness(2.5);
        UI_shopPrice[i].setFont(cordiaFont);
        UI_shopPrice[i].setCharacterSize(UIFontSize - 15);
        UI_shopDes[i].setFillColor(Color::Black);
        UI_shopDes[i].setOutlineColor(Color::White);
        UI_shopDes[i].setOutlineThickness(2.5);
        UI_shopDes[i].setFont(cordiaFont);
        UI_shopDes[i].setCharacterSize(UIFontSize - 15);
        UI_shopDes[i].setLineSpacing(0.7);
    }
    UI_askBuyWin.setTexture(miniMenuT);
    UI_askBuyWin.setOrigin(getObjWidth(UI_askBuyWin) / 2,getObjHeight(UI_askBuyWin) / 2);
    UI_askBuyWin.setPosition(windowMidWidth(),windowMidHeight());
    UI_askBuyWin.setScale(1.7,0.6);
    UI_askBuyWin.setColor(Color(255,255,255,210));
    UI_askBuy.setString("Do you want to buy this item");
    UI_askBuy.setFillColor(Color::Black);
    UI_askBuy.setOutlineColor(Color::White);
    UI_askBuy.setOutlineThickness(2.5);
    UI_askBuy.setFont(menuFont);
    UI_askBuy.setCharacterSize(UIFontSize - 5);
    UI_askBuyOk.setString("Ok");
    UI_askBuyOk.setFillColor(Color::Black);
    UI_askBuyOk.setOutlineColor(Color::White);
    UI_askBuyOk.setOutlineThickness(2.5);
    UI_askBuyOk.setFont(menuFont);
    UI_askBuyOk.setCharacterSize(UIFontSize - 5);
    UI_askBuyCancle.setString("Cancle");
    UI_askBuyCancle.setFillColor(Color::Black);
    UI_askBuyCancle.setOutlineColor(Color::White);
    UI_askBuyCancle.setOutlineThickness(2.5);
    UI_askBuyCancle.setFont(menuFont);
    UI_askBuyCancle.setCharacterSize(UIFontSize - 5);
    shopPriceValue[0] = 10; shopPriceValue[1] = 10; shopPriceValue[2] = 10; shopPriceValue[3] = 10; shopPriceValue[4] = 10; shopPriceValue[5] = 10;
    shopPriceValue[6] = 10; shopPriceValue[7] = 10; shopPriceValue[8] = 10; shopPriceValue[9] = 10; shopPriceValue[10] = 10;shopPriceValue[11] = 10;
    shopPriceValue[12] = 10;shopPriceValue[13] = 10;shopPriceValue[14] = 10;shopPriceValue[15] = 10;shopPriceValue[16] = 10;shopPriceValue[17] = 10;
    shopPriceValue[18] = 10;shopPriceValue[19] = 10;shopPriceValue[20] = 10;shopPriceValue[21] = 10;shopPriceValue[22] = 10;shopPriceValue[23] = 10;
    UI_UArrowT.loadFromFile("img/UArrow.png");
    UI_UArrowS.setTexture(UI_UArrowT);
    UI_UArrowS.setOrigin(getObjWidth(UI_UArrowS) / 2,getObjHeight(UI_UArrowS) / 2);
    UI_UArrowS.setPosition(windowMidWidth() + 27,windowMidHeight() - 23);
    UI_DArrowT.loadFromFile("img/DArrow.png");
    UI_DArrowS.setTexture(UI_DArrowT);
    UI_DArrowS.setOrigin(getObjWidth(UI_DArrowS) / 2,getObjHeight(UI_DArrowS) / 2);
    UI_DArrowS.setPosition(windowMidWidth() + 27,windowMidHeight() + 55);
    UI_buyNum.setFillColor(Color::Black);
    UI_buyNum.setOutlineColor(Color::White);
    UI_buyNum.setOutlineThickness(2.5);
    UI_buyNum.setFont(menuFont);
    UI_buyNum.setCharacterSize(UIFontSize + 5);
    D_rockT.loadFromFile("img/Rock.png");
    D_paperT.loadFromFile("img/Paper.png");
    D_scissorsT.loadFromFile("img/Scissors.png");
    D_monRockT.loadFromFile("img/MonRock.png");
    D_monPaperT.loadFromFile("img/MonPaper.png");
    D_monScissorsT.loadFromFile("img/MonScissors.png");
    D_selectR.setTexture(D_rockT);
    D_selectR.setOrigin(getObjWidth(D_selectR) / 2,getObjHeight(D_selectR) / 2);
    D_selectR.setPosition(windowMidWidth() - 300,windowMidHeight());
    D_selectP.setTexture(D_paperT);
    D_selectP.setOrigin(getObjWidth(D_selectP) / 2,getObjHeight(D_selectP) / 2);
    D_selectP.setPosition(windowMidWidth(),windowMidHeight());
    D_selectS.setTexture(D_scissorsT);
    D_selectS.setOrigin(getObjWidth(D_selectS) / 2,getObjHeight(D_selectS) / 2);
    D_selectS.setPosition(windowMidWidth() + 300,windowMidHeight());
    D_Turn.setFillColor(Color::Black);
    D_Turn.setOutlineColor(Color::White);
    D_Turn.setOutlineThickness(3.5);
    D_Turn.setFont(menuFont);
    D_Turn.setCharacterSize(UIFontSize + 20);
    D_monHpBorder.setTexture(UI_hpBorderT);
    D_monHpBorder.setPosition(360,85);
    D_monMaxHp.setTexture(UI_maxHpT);
    D_monMaxHp.setPosition(360,85);
    D_monHpBar.setTexture(UI_hpBarT);
    D_monHpBar.setPosition(362,85);
    D_monHpText.setString("HP");
    D_monHpText.setFillColor(Color::Black);
    D_monHpText.setOutlineColor(Color::White);
    D_monHpText.setOutlineThickness(3.5);
    D_monHpText.setFont(menuFont);
    D_monHpText.setCharacterSize(UIFontSize);
    D_monHpValue.setFillColor(Color::Black);
    D_monHpValue.setOutlineColor(Color::White);
    D_monHpValue.setOutlineThickness(2);
    D_monHpValue.setFont(cordiaFont);
    D_monHpValue.setCharacterSize(UIFontSize);
    D_monsterFace[0].loadFromFile("img/MonFace1.png");
    D_monsterFace[1].loadFromFile("img/MonFace2.png");
    D_monsterFace[2].loadFromFile("img/MonFace3.png");
    D_monsterFace[3].loadFromFile("img/MonFace4.png");
    D_monsterFace[4].loadFromFile("img/MonFace5.png");
    D_monsterFace[5].loadFromFile("img/MonFace6.png");
    D_monChar[0].loadFromFile("img/Mon1.png");
    D_monChar[1].loadFromFile("img/Mon2.png");
    D_monChar[2].loadFromFile("img/Mon3.png");
    D_monChar[3].loadFromFile("img/Mon4.png");
    D_monChar[4].loadFromFile("img/Mon5.png");
    D_monChar[5].loadFromFile("img/Mon6.png");
    D_monName.setFillColor(Color::Black);
    D_monName.setOutlineColor(Color::White);
    D_monName.setOutlineThickness(3.5);
    D_monName.setFont(menuFont);
    D_monName.setCharacterSize(UIFontSize);
    D_bgT.loadFromFile("img/DungeonBG.jpg");
    D_bgS.setTexture(D_bgT);
    D_playerRPS.setTexture(D_rockT);
    D_monsterRPS.setTexture(D_rockT);
    D_monLevel.setFillColor(Color::Black);
    D_monLevel.setOutlineColor(Color::White);
    D_monLevel.setOutlineThickness(3.5);
    D_monLevel.setFont(menuFont);
    D_monLevel.setCharacterSize(UIFontSize);
    D_deathText.setString("You are death");
    D_deathText.setFillColor(Color::Black);
    D_deathText.setOutlineColor(Color::White);
    D_deathText.setOutlineThickness(2.5);
    D_deathText.setFont(menuFont);
    D_deathText.setCharacterSize(UIFontSize + 5);
    D_deathOk.setString("OK");
    D_deathOk.setFillColor(Color::Black);
    D_deathOk.setOutlineColor(Color::White);
    D_deathOk.setOutlineThickness(2.5);
    D_deathOk.setFont(menuFont);
    D_deathOk.setCharacterSize(UIFontSize - 5);
    D_deathWin.setTexture(miniMenuT);
    D_deathWin.setOrigin(getObjWidth(D_deathWin) / 2,getObjHeight(D_deathWin) / 2);
    D_deathWin.setPosition(windowMidWidth(),windowMidHeight());
    D_deathWin.setScale(1.6,0.7);
    D_deathWin.setColor(Color(255,255,255,200));
    D_deathExp.setString("EXP");
    D_deathExp.setFillColor(Color::Black);
    D_deathExp.setOutlineColor(Color::White);
    D_deathExp.setOutlineThickness(2.5);
    D_deathExp.setFont(menuFont);
    D_deathExp.setCharacterSize(UIFontSize - 5);
    D_deathMoney.setString("MONEY");
    D_deathMoney.setFillColor(Color::Black);
    D_deathMoney.setOutlineColor(Color::White);
    D_deathMoney.setOutlineThickness(2.5);
    D_deathMoney.setFont(menuFont);
    D_deathMoney.setCharacterSize(UIFontSize - 5);
    D_deathMoneyValue.setFillColor(Color::Red);
    D_deathMoneyValue.setOutlineColor(Color::White);
    D_deathMoneyValue.setOutlineThickness(2.5);
    D_deathMoneyValue.setFont(menuFont);
    D_deathMoneyValue.setCharacterSize(UIFontSize - 5);
    D_deathExpValue.setFillColor(Color::Red);
    D_deathExpValue.setOutlineColor(Color::White);
    D_deathExpValue.setOutlineThickness(2.5);
    D_deathExpValue.setFont(menuFont);
    D_deathExpValue.setCharacterSize(UIFontSize - 5);
    D_coin.loadFromFile("img/Coin.png");
    D_coin.setSmooth(true);
    D_coinS.setTexture(D_coin);
    D_coinS.setOrigin(getObjWidth(D_coinS) / 2,getObjHeight(D_coinS) / 2);
    D_coinS.setScale(0.55,0.55);
    D_monDesBGS.setTexture(UI_playerDesBGT);
    D_monDesBGS.setOrigin(getObjWidth(D_monDesBGS) / 2,getObjHeight(D_monDesBGS) / 2);
    D_monDesBGS.setPosition(windowMidWidth(),windowMidHeight());
    D_monDesBGS.setScale(1.1,1);
    D_monNameDes.setFillColor(Color::Black);
    D_monNameDes.setOutlineColor(Color::White);
    D_monNameDes.setOutlineThickness(3.5);
    D_monNameDes.setFont(cordiaFont);
    D_monNameDes.setCharacterSize(UIFontSize + 10);
    D_monStatDes.setFillColor(Color::Black);
    D_monStatDes.setOutlineColor(Color::White);
    D_monStatDes.setOutlineThickness(2.5);
    D_monStatDes.setFont(cordiaFont);
    D_monStatDes.setCharacterSize(UIFontSize - 5);
    D_monStatDes.setLineSpacing(1.2);
    D_monStatDesR.setFillColor(Color::Black);
    D_monStatDesR.setOutlineColor(Color::White);
    D_monStatDesR.setOutlineThickness(2.5);
    D_monStatDesR.setFont(cordiaFont);
    D_monStatDesR.setCharacterSize(UIFontSize - 5);
    D_monStatDesR.setLineSpacing(1.2);
    D_getText.setString("You Win");
    D_getText.setFillColor(Color::Black);
    D_getText.setOutlineColor(Color::White);
    D_getText.setOutlineThickness(2.5);
    D_getText.setFont(menuFont);
    D_getText.setCharacterSize(UIFontSize + 5);
    D_getOk.setString("OK");
    D_getOk.setFillColor(Color::Black);
    D_getOk.setOutlineColor(Color::White);
    D_getOk.setOutlineThickness(2.5);
    D_getOk.setFont(menuFont);
    D_getOk.setCharacterSize(UIFontSize - 5);
    D_getWin.setTexture(miniMenuT);
    D_getWin.setOrigin(getObjWidth(D_getWin) / 2,getObjHeight(D_getWin) / 2);
    D_getWin.setPosition(windowMidWidth(),windowMidHeight());
    D_getWin.setScale(1.6,0.7);
    D_getWin.setColor(Color(255,255,255,200));
    D_getExp.setString("EXP");
    D_getExp.setFillColor(Color::Black);
    D_getExp.setOutlineColor(Color::White);
    D_getExp.setOutlineThickness(2.5);
    D_getExp.setFont(menuFont);
    D_getExp.setCharacterSize(UIFontSize - 5);
    D_getMoney.setString("MONEY");
    D_getMoney.setFillColor(Color::Black);
    D_getMoney.setOutlineColor(Color::White);
    D_getMoney.setOutlineThickness(2.5);
    D_getMoney.setFont(menuFont);
    D_getMoney.setCharacterSize(UIFontSize - 5);
    D_getMoneyValue.setFillColor(Color(0,160,0,255));
    D_getMoneyValue.setOutlineColor(Color::White);
    D_getMoneyValue.setOutlineThickness(2.5);
    D_getMoneyValue.setFont(menuFont);
    D_getMoneyValue.setCharacterSize(UIFontSize - 5);
    D_getExpValue.setFillColor(Color(0,160,0,255));
    D_getExpValue.setOutlineColor(Color::White);
    D_getExpValue.setOutlineThickness(2.5);
    D_getExpValue.setFont(menuFont);
    D_getExpValue.setCharacterSize(UIFontSize - 5);
    D_getCoin.setTexture(D_coin);
    D_getCoin.setOrigin(getObjWidth(D_getCoin) / 2,getObjHeight(D_getCoin) / 2);
    D_getCoin.setScale(0.55,0.55);
    charOnMap[0].setTexture(charTexture[0]);
    charOnMap[0].setOrigin(getObjWidth(charOnMap[0]) / 2,getObjHeight(charOnMap[0]));
    charOnMap[1].setTexture(charTexture[1]);
    charOnMap[1].setOrigin(getObjWidth(charOnMap[1]) / 2,getObjHeight(charOnMap[1]));
    charOnMap[2].setTexture(charTexture[2]);
    charOnMap[2].setOrigin(getObjWidth(charOnMap[2]) / 2,getObjHeight(charOnMap[2]));
    charOnMap[3].setTexture(charTexture[3]);
    charOnMap[3].setOrigin(getObjWidth(charOnMap[3]) / 2,getObjHeight(charOnMap[3]));
    charOnMap[4].setTexture(charTexture[4]);
    charOnMap[4].setOrigin(getObjWidth(charOnMap[4]) / 2,getObjHeight(charOnMap[4]));
    charOnMap[5].setTexture(charTexture[5]);
    charOnMap[5].setOrigin(getObjWidth(charOnMap[5]) / 2,getObjHeight(charOnMap[5]));
    UI_askGoWin.setTexture(miniMenuT);
    UI_askGoWin.setOrigin(getObjWidth(UI_askGoWin) / 2,getObjHeight(UI_askGoWin) / 2);
    UI_askGoWin.setPosition(windowMidWidth(),windowMidHeight());
    UI_askGoWin.setScale(1.7,0.6);
    UI_askGoWin.setColor(Color(255,255,255,210));
    UI_askGoText.setString("Which Path do you want to go");
    UI_askGoText.setFillColor(Color::Black);
    UI_askGoText.setOutlineColor(Color::White);
    UI_askGoText.setOutlineThickness(2.5);
    UI_askGoText.setFont(menuFont);
    UI_askGoText.setCharacterSize(UIFontSize - 5);
    UI_askGoPath[0].setFillColor(Color::Black);
    UI_askGoPath[0].setOutlineColor(Color::White);
    UI_askGoPath[0].setOutlineThickness(2.5);
    UI_askGoPath[0].setFont(menuFont);
    UI_askGoPath[0].setCharacterSize(UIFontSize - 5);
    UI_askGoPath[1].setFillColor(Color::Black);
    UI_askGoPath[1].setOutlineColor(Color::White);
    UI_askGoPath[1].setOutlineThickness(2.5);
    UI_askGoPath[1].setFont(menuFont);
    UI_askGoPath[1].setCharacterSize(UIFontSize - 5);
    for(int i = 0;i < 4;i++){
        nameOnMap[i].setFillColor(Color::Black);
        nameOnMap[i].setOutlineColor(Color::White);
        nameOnMap[i].setOutlineThickness(2);
        nameOnMap[i].setFont(menuFont);
        nameOnMap[i].setCharacterSize(UIFontSize - 10);
    }
    healWin.setTexture(miniMenuT);
    healWin.setOrigin(getObjWidth(healWin) / 2,getObjHeight(healWin) / 2);
    healWin.setPosition(windowMidWidth(),windowMidHeight());
    healWin.setScale(1.1,0.4);
    healWin.setColor(Color(255,255,255,210));
    healText.setFillColor(Color(0,160,0,255));
    healText.setOutlineColor(Color::White);
    healText.setOutlineThickness(2.5);
    healText.setFont(menuFont);
    healText.setCharacterSize(UIFontSize - 5);
    healOk.setFillColor(Color::Black);
    healOk.setOutlineColor(Color::White);
    healOk.setOutlineThickness(3);
    healOk.setFont(menuFont);
    healOk.setCharacterSize(UIFontSize - 5);
    getMonWin.setTexture(miniMenuT);
    getMonWin.setOrigin(getObjWidth(getMonWin) / 2,getObjHeight(getMonWin) / 2);
    getMonWin.setPosition(windowMidWidth(),windowMidHeight());
    getMonWin.setScale(1.1,0.4);
    getMonWin.setColor(Color(255,255,255,210));
    getMonText.setFillColor(Color(230,230,0,255));
    getMonText.setOutlineColor(Color::White);
    getMonText.setOutlineThickness(3.2);
    getMonText.setFont(menuFont);
    getMonText.setCharacterSize(UIFontSize - 5);
    getMonOk.setFillColor(Color::Black);
    getMonOk.setOutlineColor(Color::White);
    getMonOk.setOutlineThickness(2.5);
    getMonOk.setFont(menuFont);
    getMonOk.setCharacterSize(UIFontSize - 5);
}

void Game::drawPlaying(){
    updateTurn();
    upstat();
    checkwin();
    this->gameWindow->setView(camera);
    if(!isDun){
        this->gameWindow->draw(mapSprite);
        for(int i = 0;i < players;i++){
            nameOnMap[i].setString(playerName[i]);
            nameOnMap[i].setOrigin(getObjWidth(nameOnMap[i]) / 2,getObjHeight(nameOnMap[i]) / 2);
            charOnMap[player[i].character_number].setPosition(Path[player[i].NestZ_nowPath].X,Path[player[i].NestZ_nowPath].Y);
            nameOnMap[i].setPosition(charOnMap[player[i].character_number].getPosition().x,charOnMap[player[i].character_number].getPosition().y - 170);
            this->gameWindow->draw(charOnMap[player[i].character_number]);
            this->gameWindow->draw(nameOnMap[i]);
        }
    }
    this->gameWindow->setView(this->gameWindow->RenderTarget::getDefaultView());
    updateEscape();
    updatePlayingState();
    if(isHealOpen){
        this->gameWindow->draw(healWin);
        this->gameWindow->draw(healOk);
        this->gameWindow->draw(healText);
        if(healOk.getGlobalBounds().contains(mousePos)){
            healOk.setScale(1.05,1.05);
            if(checkMouseClick()){
                player[now_player].hp += healValue;
                isHealOpen = false;
                gameStates = 7;
            }
        }
        else healOk.setScale(1,1);
    }
    if(isGetMonOpen){
        this->gameWindow->draw(getMonWin);
        this->gameWindow->draw(getMonOk);
        this->gameWindow->draw(getMonText);
        if(getMonOk.getGlobalBounds().contains(mousePos)){
            getMonOk.setScale(1.05,1.05);
            if(checkMouseClick()){
                player[now_player].money += getMonValue;
                isGetMonOpen = false;
                gameStates = 7;
            }
        }
        else getMonOk.setScale(1,1);
    }
    if(isDun){
        this->gameWindow->draw(D_bgS);
        this->gameWindow->draw(D_monsterFaceS);
        this->gameWindow->draw(D_monCharS);
        this->gameWindow->draw(D_monMaxHp);
        this->gameWindow->draw(D_monHpBar);
        this->gameWindow->draw(D_monHpBorder);
        this->gameWindow->draw(D_monHpText);
        this->gameWindow->draw(D_monName);
        this->gameWindow->draw(D_monLevel);
        this->gameWindow->draw(D_playerChar);
        updateDungeon();
    }
    drawUI();
    if(isDeathOpen){
        updateDeath();
        this->gameWindow->draw(D_deathWin);
        this->gameWindow->draw(D_deathOk);
        this->gameWindow->draw(D_deathText);
        this->gameWindow->draw(D_deathExp);
        this->gameWindow->draw(D_deathExpValue);
        this->gameWindow->draw(D_deathMoney);
        this->gameWindow->draw(D_deathMoneyValue);
        this->gameWindow->draw(D_coinS);
    }
    if(isAskGo){
        updateAskGo();
        this->gameWindow->draw(UI_askGoWin);
        this->gameWindow->draw(UI_askGoPath[0]);
        this->gameWindow->draw(UI_askGoPath[1]);
        this->gameWindow->draw(UI_askGoText);
    }
    if(isGetItem){
        updateGetItem();
        this->gameWindow->draw(D_getWin);
        this->gameWindow->draw(D_getOk);
        this->gameWindow->draw(D_getText);
        this->gameWindow->draw(D_getExp);
        this->gameWindow->draw(D_getExpValue);
        this->gameWindow->draw(D_getMoney);
        this->gameWindow->draw(D_getMoneyValue);
        this->gameWindow->draw(D_getCoin);
    }
    if(isShopOpen){
        this->gameWindow->draw(UI_shopWinS);
        this->gameWindow->draw(UI_quitShop);
        this->gameWindow->draw(UI_playerMoney);
        this->gameWindow->draw(UI_money);
        for(int i = 0;i < 24;i++){
            this->gameWindow->draw(UI_shopItem[i]);
        }
        updateShop();
    }
    if(isAskBuyOpen){
        updateAskBuy(itemBuyIndex);
        this->gameWindow->draw(UI_askBuyWin);
        this->gameWindow->draw(UI_askBuyS[itemBuyIndex]);
        this->gameWindow->draw(UI_askBuy);
        this->gameWindow->draw(UI_askBuyOk);
        this->gameWindow->draw(UI_askBuyCancle);
        if(itemBuyIndex < 2){
            this->gameWindow->draw(UI_UArrowS);
            this->gameWindow->draw(UI_DArrowS);
            this->gameWindow->draw(UI_buyNum);
        }
    }
    if(isDesOpen){
            this->gameWindow->draw(UI_playerDesBGS);
            this->gameWindow->draw(UI_playerDesCharS);
            this->gameWindow->draw(UI_playerNameDes);
            this->gameWindow->draw(UI_statDes);
            this->gameWindow->draw(UI_statDesR);
    }
    if(isMonDes){
        updateMonDes();
        this->gameWindow->draw(D_monDesBGS);
        this->gameWindow->draw(D_monDesCharS);
        this->gameWindow->draw(D_monNameDes);
        this->gameWindow->draw(D_monStatDes);
        this->gameWindow->draw(D_monStatDesR);
    }
    if(isAskOpen){
        for(int i = 0;i < 10;i++){
            if(player[now_player].weaponIndex != -1){
                UI_swordName[i].setPosition(mouseIconSprite.getPosition().x,mouseIconSprite.getPosition().y - 90);
                UI_swordDes[i].setPosition(mouseIconSprite.getPosition().x,mouseIconSprite.getPosition().y - 60);
            }
            if(player[now_player].shieldIndex != -1){
                UI_shieldName[i].setPosition(mouseIconSprite.getPosition().x,mouseIconSprite.getPosition().y - 90);
                UI_shieldDes[i].setPosition(mouseIconSprite.getPosition().x,mouseIconSprite.getPosition().y - 60);
            }
            if(player[now_player].accessoryIndex != -1){
                UI_accDes[i].setPosition(mouseIconSprite.getPosition().x,mouseIconSprite.getPosition().y - 92);
                UI_accName[i].setPosition(mouseIconSprite.getPosition().x,mouseIconSprite.getPosition().y - 122);
            }
            if(i < 2){
                UI_potionName[i].setPosition(mouseIconSprite.getPosition().x,mouseIconSprite.getPosition().y - 60);
                UI_potionDes[i].setPosition(mouseIconSprite.getPosition().x,mouseIconSprite.getPosition().y - 30);
            }
        }
        updateAsk();
        this->gameWindow->draw(UI_askWin);
        this->gameWindow->draw(UI_ask);
        switch(askKind){
            case 0:
                this->gameWindow->draw(UI_askWeaponS);
                if(UI_askWeaponS.getGlobalBounds().contains(mousePos)){
                    this->gameWindow->draw(UI_swordName[askIndex]);
                    this->gameWindow->draw(UI_swordDes[askIndex]);
                }
                break;
            case 1:
                this->gameWindow->draw(UI_askShieldS);
                if(UI_askShieldS.getGlobalBounds().contains(mousePos)){
                    this->gameWindow->draw(UI_shieldName[askIndex]);
                    this->gameWindow->draw(UI_shieldDes[askIndex]);
                }
                break;
            case 2:
                this->gameWindow->draw(UI_askAccS);
                if(UI_askAccS.getGlobalBounds().contains(mousePos)){
                    this->gameWindow->draw(UI_accName[askIndex]);
                    this->gameWindow->draw(UI_accDes[askIndex]);
                }
                break;
        };
        this->gameWindow->draw(UI_yes);
        this->gameWindow->draw(UI_no);
    }
    if(isDunAskOpen){
        this->gameWindow->draw(UI_dunAskWin);
        this->gameWindow->draw(UI_dunAsk);
        this->gameWindow->draw(UI_dunYes);
        this->gameWindow->draw(UI_dunNo);
        this->gameWindow->draw(UI_dunAskMonS);
    }
    if(isShopAskOpen){
        this->gameWindow->draw(UI_shopAskWin);
        this->gameWindow->draw(UI_shopAsk);
        this->gameWindow->draw(UI_shopYes);
        this->gameWindow->draw(UI_shopNo);
        this->gameWindow->draw(UI_shopIconS);
    }
    if(isMenuOpen){
        miniMenuS.setPosition(windowWidth / 2,windowHeight / 2);
        this->gameWindow->draw(miniMenuS);
        for(int i = 0;i < 3;i++){
            miniMenuText[i].setOrigin(getObjWidth(miniMenuText[i]) / 2.0,getObjHeight(miniMenuText[i]) / 2.0);
            miniMenuText[i].setPosition(windowWidth / 2,windowHeight / 2 + 100 * arrIndex[i]);
            updateMiniMenuClick();
            this->gameWindow->draw(miniMenuText[i]);
        }
    }
    else {
        if(!isDun)updateView();
    }
    this->gameWindow->draw(mouseIconSprite);
}

void Game::updateMonDes(){//str agi luk vit atk hp def
    int monIndex;
    if(monsterIndex<3){
        monIndex=monsterIndex;
    }
    else {
        monIndex=player[now_player].bossIndex;

    }
        D_monDesCharS.setTexture(D_monChar[monIndex]);
        D_monDesCharS.setOrigin(getObjWidth(D_monDesCharS) / 2,getObjHeight(D_monDesCharS) / 2);
        D_monDesCharS.setPosition(D_monDesBGS.getPosition().x,D_monDesBGS.getPosition().y - 140);
        D_monNameDes.setString(monster[monIndex].name);
        D_monNameDes.setOrigin(getObjWidth(D_monNameDes) / 2,getObjHeight(D_monNameDes) / 2);
        D_monNameDes.setPosition(D_monDesBGS.getPosition().x + 5,D_monDesBGS.getPosition().y - 50);
        D_monStatDes.setString("Level  :     " + to_string(monster[monIndex].lv) + '\n' +
                             "ATK  :     " + to_string(monster[monIndex].stat[4]) + '\n' +
                             "Max HP  :     " + to_string(monster[monIndex].maxhp) + '\n' +
                             "STR  :     " + to_string(monster[monIndex].stat[0]) + '\n' +
                             "VIT  :     " + to_string(monster[monIndex].stat[3])
                             );
        D_monStatDesR.setString("DEF  :     " + to_string(monster[monIndex].stat[6]) + "\n\n" +
                              "AGI  :     " + to_string(monster[monIndex].stat[1]) + '\n' +
                              "LUK  :     " + to_string(monster[monIndex].stat[2])
                              );
        D_monStatDes.setPosition(D_monDesBGS.getPosition().x - 210,D_monDesBGS.getPosition().y);
        D_monStatDesR.setPosition(D_monDesBGS.getPosition().x + 35,D_monDesBGS.getPosition().y + 37);
}

void Game::checkwin(){
    if(player[now_player].star > 2){
        while(state.top() != Menu)state.pop();
    }
}

void Game::dungeon(int monster){
    monsterIndex = monster;
}

void Game::updateDungeon(){
    D_monName.setString(monster[monsterIndex].name);
    D_monName.setOrigin(getObjWidth(D_monName) / 2,getObjHeight(D_monName) / 2);
    D_monName.setPosition(D_monsterFaceS.getPosition().x,UI_name.getPosition().y);
    D_monLevel.setString("LV. " + to_string(monster[monsterIndex].lv));
    D_monLevel.setOrigin(getObjWidth(D_monLevel),0);
    D_monLevel.setPosition(windowWidth - UI_level.getPosition().x,UI_level.getPosition().y);
    D_playerChar.setTexture(charTexture[player[now_player].character_number]);
    D_playerChar.setOrigin(getObjWidth(D_playerChar) / 2,getObjHeight(D_playerChar) / 2);
    D_playerChar.setPosition(windowMidWidth() - 700,windowMidHeight());
    D_monCharS.setTexture(D_monChar[monsterIndex]);
    D_monCharS.setOrigin(getObjWidth(D_monCharS) / 2,getObjHeight(D_monCharS) / 2);
    D_monCharS.setPosition(windowMidWidth() + 700,windowMidHeight());
    D_monsterFaceS.setTexture(D_monsterFace[monsterIndex]);
    D_monsterFaceS.setOrigin(getObjWidth(D_monsterFaceS) / 2,getObjHeight(D_monsterFaceS) / 2);
    D_monsterFaceS.setPosition(windowWidth - 110,110);
    D_monHpBar.setScale((double)monster[monsterIndex].stat[5] / monster[monsterIndex].maxhp,1);
    D_monHpBar.setPosition(windowWidth - UI_hpBarS.getPosition().x - getObjWidth(D_monHpBar) + 130,UI_hpBarS.getPosition().y);
    D_monHpBorder.setOrigin(getObjWidth(D_monHpBorder),0);
    D_monHpBorder.setPosition(windowWidth - UI_hpBorderS.getPosition().x + 130,UI_hpBorderS.getPosition().y);
    D_monMaxHp.setOrigin(getObjWidth(D_monMaxHp),0);
    D_monMaxHp.setPosition(windowWidth - UI_maxHpS.getPosition().x + 130,UI_maxHpS.getPosition().y);
    D_monHpValue.setString(to_string(monster[monsterIndex].stat[5]) + "/" + to_string(monster[monsterIndex].maxhp));
    D_monHpValue.setOrigin(getObjWidth(D_monHpValue),0);
    D_monHpValue.setPosition(D_monMaxHp.getPosition().x - 55,UI_hpValue.getPosition().y);
    D_monHpText.setOrigin(getObjWidth(D_monHpText),0);
    D_monHpText.setPosition(windowWidth - UI_hpText.getPosition().x - 230,UI_hpText.getPosition().y);
    D_playerRPS.setOrigin(getObjWidth(D_playerRPS) / 2,getObjHeight(D_playerRPS) / 2);
    D_playerRPS.setPosition(windowMidWidth() - 500,windowMidHeight());
    D_monsterRPS.setOrigin(getObjWidth(D_monsterRPS) / 2,getObjHeight(D_monsterRPS) / 2);
    D_monsterRPS.setPosition(windowMidWidth() + 500,windowMidHeight());
    if(fightTurn == 0)D_Turn.setString("Your Turn");
    else D_Turn.setString("Enemy Turn");
    D_Turn.setOrigin(getObjWidth(D_Turn) / 2,getObjHeight(D_Turn) / 2);
    D_Turn.setPosition(windowMidWidth(),windowMidHeight() - 400);
    this->gameWindow->draw(D_Turn);
    if(D_monMaxHp.getGlobalBounds().contains(mousePos)){
        this->gameWindow->draw(D_monHpValue);
    }
    switch(dunStates){
        case 7:
            playerDamage = player[now_player].getAtk();
            monsterDamage = monster[monsterIndex].stat[4];
            if(playerSpeed >= monsterSpeed){
                fightTurn = 0;
                critP = rand() % 100 + 1;
                if(critP <= player[now_player].getLuk() * 3)playerDamage *= 1.5;
            }
            else{
                fightTurn = 1;
                critP = rand() % 100 + 1;
                if(critP <= monster[monsterIndex].stat[2] * 3)monsterDamage *= 2;
            }
            loseE = loseExp(monsterIndex);
            loseMon = loseMoney(monsterIndex);
            getm=getMoney(monsterIndex);
            gete=getExp(monsterIndex);
            dunStates = 0;
            break;
        case 0:
            if(fightTurn == 0){
                this->gameWindow->draw(D_selectR);
                this->gameWindow->draw(D_selectP);
                this->gameWindow->draw(D_selectS);
                if(D_selectR.getGlobalBounds().contains(mousePos) && !isMenuOpen && !isDesOpen && !isMonDes){
                    D_selectR.setScale(1.05,1.05);
                    if(checkMouseClick()){
                        D_playerRPS.setTexture(D_rockT);
                        dunStates = 1;
                    }
                }
                else D_selectR.setScale(1,1);
                if(D_selectP.getGlobalBounds().contains(mousePos) && !isMenuOpen && !isDesOpen && !isMonDes){
                    D_selectP.setScale(1.05,1.05);
                    if(checkMouseClick()){
                        D_playerRPS.setTexture(D_paperT);
                        dunStates = 1;
                    }
                }
                else D_selectP.setScale(1,1);
                if(D_selectS.getGlobalBounds().contains(mousePos) && !isMenuOpen && !isDesOpen && !isMonDes){
                    D_selectS.setScale(1.05,1.05);
                    if(checkMouseClick()){
                        D_playerRPS.setTexture(D_scissorsT);
                        dunStates = 1;
                    }
                }
                else D_selectS.setScale(1,1);
            }
            else dunStates = 4;
            break;
        case 1:
            randomRPS();
            this->gameWindow->draw(D_playerRPS);
            this->gameWindow->draw(D_monsterRPS);
            break;
        case 2:
            this->gameWindow->draw(D_playerRPS);
            this->gameWindow->draw(D_monsterRPS);
            waitRPSAni(15);
            break;
        case 3:
            if(playerDes == enemyDes)isPlayerWin = 3;//draw
            else if(playerDes == 0 && enemyDes == 1)isPlayerWin = 0;//enemy win
            else if(playerDes == 1 && enemyDes == 2)isPlayerWin = 0;//enemy win
            else if(playerDes == 2 && enemyDes == 0)isPlayerWin = 0;//enemy win
            else isPlayerWin = 1;//player win
            dunStates = 4;
            break;
        case 4:
            if(fightTurn == 0){
                if(isPlayerWin == 1)playerDamage *= 1.25;
                else if(isPlayerWin == 0)playerDamage *= 0.75;
                playerDamage -= monster[monsterIndex].stat[6];
                if(playerDamage > 0)monster[monsterIndex].stat[5] -= playerDamage;
                cout << "pd " << playerDamage << "\n";
                if(monster[monsterIndex].stat[5] < 0)monster[monsterIndex].stat[5] = 0;
                playerSpeed /= 2;
                monsterSpeed += monster[monsterIndex].stat[1];
            }
            else if(fightTurn == 1){
                monsterDamage -= player[now_player].getDef();
                if(monsterDamage > 0)player[now_player].hp -= monsterDamage;
                if(player[now_player].hp < 0)player[now_player].hp = 0;
                monsterSpeed /= 2;
                playerSpeed += player[now_player].getAgi();
            }
            dunStates = 5;
            break;
        case 5:
            checkDeath();
            break;
        case 6:
            dunStates = 7;
            break;
    };
    if(D_monsterFaceS.getGlobalBounds().contains(mousePos)){
        D_monsterFaceS.setScale(1.05,1.05);
        if(checkMouseClick()){
            if(!isMonDes){
                isMonDes = true;
                isDesOpen = false;
            }
            else isMonDes = false;
        }
    }
    else D_monsterFaceS.setScale(1,1);
}

void Game::checkDeath(){
    if(player[now_player].hp == 0){
        canUsePotion = false;
        death();
    }
    else if(monster[monsterIndex].stat[5] == 0){
        dunStates = 8;
        gameStates = 8;
        isDun = false;
        if(monsterIndex < 3)getItem();
        else{
            player[now_player].bossIndex++;
            player[now_player].star++;
            getItem();
            get_item_boss();
        }
    }
    else{
        dunStates = 6;
    }
}

void Game::getItem(){
    isGetItem = true;
}

void Game::updateGetItem(){
    D_getText.setOrigin(getObjWidth(D_getText) / 2,getObjHeight(D_getText) / 2);
    D_getText.setPosition(windowMidWidth(),windowMidHeight() - 110);
    D_getOk.setOrigin(getObjWidth(D_getOk) / 2,getObjHeight(D_getOk) / 2);
    D_getOk.setPosition(windowMidWidth(),windowMidHeight() + 110);
    D_getExp.setOrigin(getObjWidth(D_getExp) / 2,getObjHeight(D_getExp) / 2);
    D_getExp.setPosition(windowMidWidth() - 150,windowMidHeight() - 20);
    D_getExpValue.setString(to_string(gete));
    D_getExpValue.setOrigin(getObjWidth(D_getExpValue) / 2,getObjHeight(D_getExpValue) / 2);
    D_getExpValue.setPosition(windowMidWidth() + 150,D_getExp.getPosition().y);
    D_getMoney.setOrigin(getObjWidth(D_getMoney) / 2,getObjHeight(D_getMoney) / 2);
    D_getMoney.setPosition(windowMidWidth() - 150,windowMidHeight() + 30);
    D_getMoneyValue.setString(to_string(getm));
    D_getMoneyValue.setOrigin(getObjWidth(D_getMoneyValue) / 2,getObjHeight(D_getMoneyValue) / 2);
    D_getMoneyValue.setPosition(windowMidWidth() + 150,D_getMoney.getPosition().y);
    D_getCoin.setPosition(D_getMoneyValue.getPosition().x + 110,D_getMoneyValue.getPosition().y + 3);
    if(D_getOk.getGlobalBounds().contains(mousePos) && !isMenuOpen && !isDesOpen && !isMonDes){
        D_getOk.setScale(1.05,1.05);
        if(checkMouseClick()){
            player[now_player].exp += gete;
            player[now_player].money += getm;
            isGetItem = false;
            gameStates = 7;
        }
    }
    else D_getOk.setScale(1,1);
}

int Game::loseMoney(int x_case){
    int luckyy = player[now_player].getLuk();
    int x_lucky = rand() % 10 + 15;
    int x_luckyplayer;
    x_luckyplayer = (luckyy * 0.2) / 10;
    x_lucky += x_luckyplayer;
    switch (x_case){
        case 0 :
            if(player[now_player].level >= 20){
                return (player[now_player].money * 0.3) - x_lucky;
            }
            else if(player[now_player].level >= 10){
                return (player[now_player].money * 0.2) -x_lucky;
            }
            else{
                return (player[now_player].money * 0.1) - x_lucky;
            }
            break;

        case 1 :
            if(player[now_player].level >= 20){
                return (player[now_player].money * 0.5) - x_lucky;
            }
            else if(player[now_player].level >= 10){
                return (player[now_player].money * 0.3) - x_lucky;
            }
            else{
                return (player[now_player].money * 0.2) -x_lucky;
            }
            break;

        case 2 :
            if(player[now_player].level >= 20){
                return (player[now_player].money * 0.7) - x_lucky;
            }
            else if(player[now_player].level >= 10){
                return (player[now_player].money * 0.5) - x_lucky;
            }
            else{
                return (player[now_player].money * 0.2) - x_lucky;
            }
            break;

        default:
            if(player[now_player].level >= 20){
                return (player[now_player].money * 0.8) - x_lucky;
            }
            else if(player[now_player].level >= 10){
                return (player[now_player].money * 0.7) - x_lucky;
            }
            else{
                return (player[now_player].money * 0.5) - x_lucky;
            }
            break;
    }
}

int Game::getMoney(int x_case){
    int luckyy = player[now_player].getLuk();
    int x_lucky = rand() % 10 + 15;
    int x_luckyplayer;
    x_luckyplayer = (luckyy * 0.2) / 10;
    x_lucky += x_luckyplayer;
    switch (x_case){
        case 0 :
            if(player[now_player].level >= 20){
                return (rand() % 10 + 1) + x_lucky;
            }
            else if(player[now_player].level >= 10){
                return (rand() % 15 + 1)+ x_lucky;
            }
            else{
                return (rand() % 20 + 1) + x_lucky;
            }
            break;

        case 1 :
            if(player[now_player].level >= 20){
                return (rand() % 30 + 1) + x_lucky;
            }
            else if(player[now_player].level >= 10){
                return (rand() % 40 + 1) + x_lucky;
            }
            else{
                return (rand() % 45 + 1) + x_lucky;
            }
            break;

        case 2 :
            if(player[now_player].level >= 20 ){
                return (rand() % 20 + 1) + x_lucky;
            }
            else if(player[now_player].level >= 10){
                return (rand() % 30 + 1) + x_lucky;
            }
            else{
                return (rand() % 50 + 1)+ x_lucky;
            }
            break;

        case 3:
            if(player[now_player].level >= 20){
                return (rand() % 200 + 1) + x_lucky;
            }
            else if(player[now_player].level >= 10){
                return (rand() % 300 + 1) + x_lucky;
            }
            else{
                return (rand() % 350 + 1) + x_lucky;
            }
            break;

        case 4:
            if(player[now_player].level >= 20){
                return (rand() % 300 + 1) + x_lucky;
            }
            else if(player[now_player].level >= 10){
                return (rand() % 350 + 1) + x_lucky;
            }
            else{
                return (rand() % 400 + 1) + x_lucky;
            }
            break;
    }
    return 0;
}

int Game::loseExp(int x_case){
    switch (x_case){
        case 0 :
            if(player[now_player].level >= 20){
                return ((player[now_player].level - 1) * 100) + 800;
            }
            else if(player[now_player].level >= 10){
                return ((player[now_player].level - 1) * 100) + 600;
            }
            else{
                return ((player[now_player].level - 1) * 100) + 400;
            }
            break;
        case 1 :
            if(player[now_player].level >= 20){
                return ((player[now_player].level - 1) * 100) + 1200;
            }
            else if(player[now_player].level >= 10){
                return ((player[now_player].level - 1) * 100) + 1000;
            }
            else{
                return ((player[now_player].level -1 ) * 100) + 600;
            }
            break;
        case 2 :
            if(player[now_player].level >= 20){
                return ((player[now_player].level - 1) * 100) + 1400;
            }
            else if(player[now_player].level >= 10){
                return ((player[now_player].level - 1) * 100) + 1200;
            }
            else{
                return ((player[now_player].level - 1) * 100) +  1100;
            }
            break;
        case 3:
            if(player[now_player].level >= 20){
                return ((player[now_player].level - 1) * 100) + 1600;
            }
            else if(player[now_player].level >= 10){
                return ((player[now_player].level - 1) * 100) + 1400;
            }
            else{
                return ((player[now_player].level - 1) * 100) + 1100;
            }
            break;
        case 4:
            if(player[now_player].level >=20 ){
                return ((player[now_player].level - 1) * 50) + 2200;
            }
            else if(player[now_player].level >= 10){
                return ((player[now_player].level - 1) * 50) + 2000;
            }
            else{
                return ((player[now_player].level - 1) * 50) + 1800;
            }
            break;
    };
    return 0;
}

int Game::getExp(int x_case){
    switch (x_case){
        case 0 :
            if(player[now_player].level >= 20 ){
                return 1400;
            }
            else if(player[now_player].level >= 10){
                return 1000;
            }
            else{
                return 600;
            }
            break;
        case 1 :
            if(player[now_player].level >= 20){
                return 1600;
            }
            else if(player[now_player].level >= 10){
                return 1200;
            }
            else{
                return 800;
            }
            break;
        case 2 :
            if(player[now_player].level >= 20){
                return 1800;
            }
            else if(player[now_player].level >= 10){
                return 1400;
            }
            else{
                return 1000;
            }
            break;
        case 3:
            if(player[now_player].level >= 20){
                return 2600;
            }
            else if(player[now_player].level >= 10){
                return 2200;
            }
            else{
                return 1800;
            }
            break;
        case 4:
            if(player[now_player].level >=20){
                return 2900;
            }
            else if(player[now_player].level >= 10){
                return 2500;
            }
            else{
                return 2100;
            }
            break;
    };
    return 0;
}

void Game::death(){
    isDeathOpen = true;
}

void Game::updateDeath(){
    D_deathText.setOrigin(getObjWidth(D_deathText) / 2,getObjHeight(D_deathText) / 2);
    D_deathText.setPosition(windowMidWidth(),windowMidHeight() - 110);
    D_deathOk.setOrigin(getObjWidth(D_deathOk) / 2,getObjHeight(D_deathOk) / 2);
    D_deathOk.setPosition(windowMidWidth(),windowMidHeight() + 110);
    D_deathExp.setOrigin(getObjWidth(D_deathExp) / 2,getObjHeight(D_deathExp) / 2);
    D_deathExp.setPosition(windowMidWidth() - 150,windowMidHeight() - 20);
    D_deathExpValue.setString("-" + to_string(loseE));
    D_deathExpValue.setOrigin(getObjWidth(D_deathExpValue) / 2,getObjHeight(D_deathExpValue) / 2);
    D_deathExpValue.setPosition(windowMidWidth() + 150,D_deathExp.getPosition().y);
    D_deathMoney.setOrigin(getObjWidth(D_deathMoney) / 2,getObjHeight(D_deathMoney) / 2);
    D_deathMoney.setPosition(windowMidWidth() - 150,windowMidHeight() + 30);
    D_deathMoneyValue.setString("-" + to_string(loseMon));
    D_deathMoneyValue.setOrigin(getObjWidth(D_deathMoneyValue) / 2,getObjHeight(D_deathMoneyValue) / 2);
    D_deathMoneyValue.setPosition(windowMidWidth() + 150,D_deathMoney.getPosition().y);
    D_coinS.setPosition(D_deathMoneyValue.getPosition().x + 110,D_deathMoneyValue.getPosition().y + 3);
    if(D_deathOk.getGlobalBounds().contains(mousePos) && !isMenuOpen && !isDesOpen && !isMonDes){
        D_deathOk.setScale(1.05,1.05);
        if(checkMouseClick()){
            player[now_player].exp -= loseE;
            player[now_player].money -= loseMon;
            isDun = false;
            isDeathOpen = false;
            canUsePotion = true;
            player[now_player].allPath.push_back(-1);
            player[now_player].NestZ_nowPath = 0;
            gameStates = 7;
        }
    }
    else D_deathOk.setScale(1,1);
}

void Game::waitRPSAni(unsigned int time){
    totalTime += deltaTime;
    if(totalTime >= animationSpeed){
        totalTime -= animationSpeed;
        timeTemp.push_back(1);
    }
    if(timeTemp.size() == time){
        while(timeTemp.size() != 0)timeTemp.pop_back();
        totalTime = 0.0f;
        dunStates = 3;
    }
}

void Game::randomRPS(){
    totalTime += deltaTime;
    if(totalTime >= animationSpeed){
        totalTime -= animationSpeed;
        do{
            monsterRPS = rand() % 3;
        }while(monsterRPS == RPStempMon.back());
        RPStempMon.push_back(monsterRPS);
        switch(RPStempMon.back()){
            case 0:
                D_monsterRPS.setTexture(D_monRockT);
                break;
            case 1:
                D_monsterRPS.setTexture(D_monPaperT);
                break;
            case 2:
                D_monsterRPS.setTexture(D_monScissorsT);
                break;
        };
    }
    if(RPStempMon.size() == 21){
        dunStates = 2;
        totalTime = 0.0f;
        while(RPStempMon.size() != 1)RPStempMon.pop_back();
    }
}

void Game::askBuy(int index){
    isAskBuyOpen = true;
    itemBuyIndex = index;
}

void Game::updateAskBuy(int index){
    UI_askBuy.setOrigin(getObjWidth(UI_askBuy) / 2,getObjHeight(UI_askBuy) / 2);
    UI_askBuy.setPosition(windowMidWidth(),windowMidHeight() - 75);
    UI_askBuyOk.setOrigin(getObjWidth(UI_askBuyOk) / 2,getObjHeight(UI_askBuyOk) / 2);
    UI_askBuyOk.setPosition(windowMidWidth() - 200,windowMidHeight() + 75);
    UI_askBuyCancle.setOrigin(getObjWidth(UI_askBuyCancle) / 2,getObjHeight(UI_askBuyCancle) / 2);
    UI_askBuyCancle.setPosition(windowMidWidth() + 200,windowMidHeight() + 75);
    if(index < 2){
        UI_buyNum.setString(to_string(buyNum));
        UI_buyNum.setOrigin(getObjWidth(UI_buyNum) / 2,getObjHeight(UI_buyNum) / 2);
        UI_buyNum.setPosition(windowMidWidth() + 30,windowMidHeight() + 10);
    }
    int kind;
    int innerIndex;
    if(index < 8 && index > 1){
        kind = 0;
        innerIndex = index - 1;
    }
    else if(index < 16){
        kind = 1;
        innerIndex = index - 8;
    }
    else if(index < 23){
        kind = 2;
        innerIndex = index - 16;
    }
    if(UI_askBuyOk.getGlobalBounds().contains(mousePos)){
        UI_askBuyOk.setScale(1.05,1.05);
        if(checkMouseClick()){
            if(player[now_player].money >= shopPriceValue[index]){
               isAskBuyOpen = false;
               if(index > 1 && index != 23){
                   player[now_player].money -= shopPriceValue[index];
                   isShopOpen = false;
                   gameStates = 8;
                   ask(kind,innerIndex);
               }
               else if(index == 23){
                    player[now_player].money -= shopPriceValue[index];
                    player[now_player].star++;
               }
               else{
                   player[now_player].money -= shopPriceValue[index]*buyNum;
                   if(index == 0)player[now_player].red_potion += buyNum;
                   else player[now_player].green_potion += buyNum;
               }
               buyNum = 1;
            }
        }
    }
    else UI_askBuyOk.setScale(1,1);
    if(UI_askBuyCancle.getGlobalBounds().contains(mousePos)){
        UI_askBuyCancle.setScale(1.05,1.05);
        if(checkMouseClick()){
            isAskBuyOpen = false;
            gameStates = 6;
            buyNum = 1;
        }
    }
    else UI_askBuyCancle.setScale(1,1);
    if(index < 2){
        if(UI_UArrowS.getGlobalBounds().contains(mousePos)){
            UI_UArrowS.setScale(1.1,1.1);
            if(checkMouseClick())buyNum++;
        }
        else UI_UArrowS.setScale(1,1);
        if(UI_DArrowS.getGlobalBounds().contains(mousePos)){
            UI_DArrowS.setScale(1.1,1.1);
            if(checkMouseClick() && buyNum > 1)buyNum--;
        }
        else UI_DArrowS.setScale(1,1);
    }
}

void Game::updateShop(){
    UI_playerMoney.setString(to_string(player[now_player].money));
    UI_quitShop.setOrigin(getObjWidth(UI_quitShop) / 2,getObjHeight(UI_quitShop) / 2);
    UI_quitShop.setPosition(windowMidWidth() - 220,windowMidHeight() + 202);
    UI_playerMoney.setOrigin(getObjWidth(UI_playerMoney),getObjHeight(UI_playerMoney) / 2);
    UI_playerMoney.setPosition(windowMidWidth() + 230,windowMidHeight() + 202);
    UI_money.setOrigin(getObjWidth(UI_money),getObjHeight(UI_money) / 2);
    UI_money.setPosition(windowMidWidth() + 70,windowMidHeight() + 202);
    if(UI_quitShop.getGlobalBounds().contains(mousePos) && !isMenuOpen && !isAskBuyOpen && !isAskOpen){
        UI_quitShop.setScale(1.05,1.05);
        if(checkMouseClick()){
            isShopOpen = false;
            gameStates = 7;
        }
    }
    else UI_quitShop.setScale(1,1);
    for(int i = 0;i < 24;i++){
        if(UI_shopItem[i].getGlobalBounds().contains(mousePos) && !isMenuOpen && !isAskBuyOpen && !isAskOpen){
            UI_shopItem[i].setScale(1.05,1.05);
            if(i < 2){
                UI_shopName[i].setPosition(mouseIconSprite.getPosition().x,mouseIconSprite.getPosition().y - 80);
                UI_shopDes[i].setPosition(mouseIconSprite.getPosition().x,mouseIconSprite.getPosition().y - 50);
                UI_shopPrice[i].setPosition(mouseIconSprite.getPosition().x,mouseIconSprite.getPosition().y - 30);
            }
            else if(i < 8){
                UI_shopName[i].setPosition(mouseIconSprite.getPosition().x,mouseIconSprite.getPosition().y - 110);
                UI_shopDes[i].setPosition(mouseIconSprite.getPosition().x,mouseIconSprite.getPosition().y - 80);
                UI_shopPrice[i].setPosition(mouseIconSprite.getPosition().x,mouseIconSprite.getPosition().y - 30);
            }
            else if(i < 16){
                UI_shopName[i].setPosition(mouseIconSprite.getPosition().x,mouseIconSprite.getPosition().y - 110);
                UI_shopDes[i].setPosition(mouseIconSprite.getPosition().x,mouseIconSprite.getPosition().y - 80);
                UI_shopPrice[i].setPosition(mouseIconSprite.getPosition().x,mouseIconSprite.getPosition().y - 30);
            }
            else if(i < 23){
                UI_shopName[i].setPosition(mouseIconSprite.getPosition().x,mouseIconSprite.getPosition().y - 142);
                UI_shopDes[i].setPosition(mouseIconSprite.getPosition().x,mouseIconSprite.getPosition().y - 112);
                UI_shopPrice[i].setPosition(mouseIconSprite.getPosition().x,mouseIconSprite.getPosition().y - 32);
            }
            else if(i == 23){
                UI_shopName[i].setPosition(mouseIconSprite.getPosition().x,mouseIconSprite.getPosition().y - 80);
                UI_shopDes[i].setPosition(mouseIconSprite.getPosition().x,mouseIconSprite.getPosition().y - 50);
                UI_shopPrice[i].setPosition(mouseIconSprite.getPosition().x,mouseIconSprite.getPosition().y - 30);
            }
            if(checkMouseClick()){
                    askBuy(i);
            }
            this->gameWindow->draw(UI_shopName[i]);
            this->gameWindow->draw(UI_shopDes[i]);
            this->gameWindow->draw(UI_shopPrice[i]);
        }
        else UI_shopItem[i].setScale(1,1);
    }
}

void Game::shopAsk(){
    isShopAskOpen = true;
    updateShopAsk();
}

void Game::updateShopAsk(){
    UI_shopAsk.setOrigin(getObjWidth(UI_shopAsk) / 2,getObjHeight(UI_shopAsk) / 2);
    UI_shopAsk.setPosition(windowMidWidth(),windowMidHeight() - 75);
    UI_shopYes.setOrigin(getObjWidth(UI_shopYes) / 2,getObjHeight(UI_shopYes) / 2);
    UI_shopYes.setPosition(windowMidWidth() - 200,windowMidHeight() + 75);
    UI_shopNo.setOrigin(getObjWidth(UI_shopNo) / 2,getObjHeight(UI_shopNo) / 2);
    UI_shopNo.setPosition(windowMidWidth() + 200,windowMidHeight() + 75);
    if(UI_shopYes.getGlobalBounds().contains(mousePos) && !isMenuOpen){
        UI_shopYes.setScale(1.1,1.1);
        if(checkMouseClick()){
            isShopAskOpen = false;
            gameStates = 6;
        }
    }
    else UI_shopYes.setScale(1,1);
    if(UI_shopNo.getGlobalBounds().contains(mousePos) &&!isMenuOpen){
        UI_shopNo.setScale(1.1,1.1);
        if(checkMouseClick()){
            isShopAskOpen = false;
            gameStates = 7;
        }
    }
    else UI_shopNo.setScale(1,1);
}

void Game::dunAsk(int kind){
    isDunAskOpen = true;
    updateDunAsk(kind);
}

void Game::updateDunAsk(int kind){
    UI_dunAskMonS.setTexture(UI_dunAskMonT[kind]);
    UI_dunAskMonS.setOrigin(getObjWidth(UI_dunAskMonS) / 2,getObjHeight(UI_dunAskMonS) / 2);
    UI_dunAskMonS.setPosition(windowMidWidth(),windowMidHeight() + 10);
    UI_dunAsk.setOrigin(getObjWidth(UI_dunAsk) / 2,getObjHeight(UI_dunAsk) / 2);
    UI_dunAsk.setPosition(windowMidWidth(),windowMidHeight() - 75);
    UI_dunYes.setOrigin(getObjWidth(UI_dunYes) / 2,getObjHeight(UI_dunYes) / 2);
    UI_dunYes.setPosition(windowMidWidth() - 200,windowMidHeight() + 75);
    UI_dunNo.setOrigin(getObjWidth(UI_dunNo) / 2,getObjHeight(UI_dunNo) / 2);
    UI_dunNo.setPosition(windowMidWidth() + 200,windowMidHeight() + 75);
    if(UI_dunYes.getGlobalBounds().contains(mousePos) && !isMenuOpen){
        UI_dunYes.setScale(1.1,1.1);
        if(checkMouseClick()){
            if(kind == 3)askKind = player[now_player].bossIndex;
            else askKind = kind;
            playerSpeed = player[now_player].getAgi();
            monsterSpeed = monster[askKind].stat[1];
            for(int i=0;i<6;i++){
                 monster[i].stat[5] = monster[i].maxhp;
            }
            dunStates = 7;
            isDunAskOpen = false;
            gameStates = 5;
        }
    }
    else UI_dunYes.setScale(1,1);
    if(UI_dunNo.getGlobalBounds().contains(mousePos) &&!isMenuOpen){
        UI_dunNo.setScale(1.1,1.1);
        if(checkMouseClick()){
            isDunAskOpen = false;
            gameStates = 7;
        }
    }
    else UI_dunNo.setScale(1,1);
}

void Game::ask(int kind,int index,bool stateC){
    askKind = kind;
    askIndex = index;
    isAskOpen = true;
    stateChange = stateC;
}

void Game::updateAsk(){
    switch(askKind){
        case 0:
            UI_askWeaponS.setTexture(UI_swordT[askIndex]);
            UI_askWeaponS.setOrigin(getObjWidth(UI_askWeaponS) / 2,getObjHeight(UI_askWeaponS) / 2);
            UI_askWeaponS.setPosition(windowMidWidth(),windowMidHeight() + 10);
            break;
        case 1:
            UI_askShieldS.setTexture(UI_shieldT[askIndex]);
            UI_askShieldS.setOrigin(getObjWidth(UI_askShieldS) / 2,getObjHeight(UI_askShieldS) / 2);
            UI_askShieldS.setPosition(windowMidWidth(),windowMidHeight() + 10);
            break;
        case 2:
            UI_askAccS.setTexture(UI_accT[askIndex]);
            UI_askAccS.setOrigin(getObjWidth(UI_askAccS) / 2,getObjHeight(UI_askAccS) / 2);
            UI_askAccS.setPosition(windowMidWidth(),windowMidHeight() + 10);
            break;
    };
    UI_ask.setOrigin(getObjWidth(UI_ask) / 2,getObjHeight(UI_ask) / 2);
    UI_ask.setPosition(windowMidWidth(),windowMidHeight() - 75);
    UI_yes.setOrigin(getObjWidth(UI_yes) / 2,getObjHeight(UI_yes) / 2);
    UI_yes.setPosition(windowMidWidth() - 200,windowMidHeight() + 75);
    UI_no.setOrigin(getObjWidth(UI_no) / 2,getObjHeight(UI_no) / 2);
    UI_no.setPosition(windowMidWidth() + 200,windowMidHeight() + 75);
    if(UI_yes.getGlobalBounds().contains(mousePos) && !isMenuOpen){
        UI_yes.setScale(1.1,1.1);
        if(checkMouseClick()){
            switch(askKind){
                case 0:
                    player[now_player].weaponIndex = askIndex;
            break;
                case 1:
                    player[now_player].shieldIndex = askIndex;
                    player[now_player].hp+=shield[player[now_player].shieldIndex].shield_stat[0] * 10;
                    if(player[now_player].hp > player[now_player].HpMax())player[now_player].hp = player[now_player].HpMax();
            break;
                case 2:
                    player[now_player].accessoryIndex = askIndex;
                    player[now_player].hp+=player[now_player].getVit()+ player[now_player].std_vit*10-(player[now_player].hp-player[now_player].HpMax());
                    if(player[now_player].hp > player[now_player].HpMax())player[now_player].hp = player[now_player].HpMax();
            };
            isAskOpen = false;
            cout << gameStates << "\n";
            if(stateChange)gameStates = 7;
        }
    }
    else UI_yes.setScale(1,1);
    if(UI_no.getGlobalBounds().contains(mousePos) &&!isMenuOpen){
        UI_no.setScale(1.1,1.1);
        if(checkMouseClick()){
            isAskOpen = false;
            if(stateChange)gameStates = 7;
        }
    }
    else UI_no.setScale(1,1);

}

void Game::RandomMoney(){
    getMonValue = ranMoney();
    gameStates = 8;
    isGetMonOpen = true;
    getMonOk.setString("OK");
    getMonOk.setOrigin(getObjWidth(getMonOk) / 2,getObjHeight(getMonOk) / 2);
    getMonOk.setPosition(windowMidWidth(),windowMidHeight() + 50);
    getMonText.setString("You  get   " + to_string(getMonValue) + "   Coins");
    getMonText.setOrigin(getObjWidth(getMonText) / 2,getObjHeight(getMonText) / 2);
    getMonText.setPosition(windowMidWidth(),windowMidHeight() - 50);
}

int Game::ranMoney(){
    int money = 10 + (rand() % player[now_player].getLuk() * 1.2);
    //player[now_player].money += money;
    return money;
}

void Game::Heal(){
    healValue = Get_Heal(player[now_player]);
    gameStates = 8;
    isHealOpen = true;
    healOk.setString("OK");
    healOk.setOrigin(getObjWidth(healOk) / 2,getObjHeight(healOk) / 2);
    healOk.setPosition(windowMidWidth(),windowMidHeight() + 50);
    healText.setString("Healed   " + to_string(healValue) + "   HP");
    healText.setOrigin(getObjWidth(healText) / 2,getObjHeight(healText) / 2);
    healText.setPosition(windowMidWidth(),windowMidHeight() - 50);
}

void Game::updatePlayingState(){
    if(gameStates == 1){ //randomDice
        if(!randomStart)diceState();
        else if(randomStart){
            randomDice();
            this->gameWindow->draw(UI_diceValue);
        }
    }
    else if(gameStates == 2){ //ShowDiceNum
        this->gameWindow->draw(UI_diceValue);
        player[now_player].moveNum = diceTemp.back();
        while(diceTemp.size() != 1)diceTemp.pop_back();
        randomStart = false;
        moveTemp = diceNum;
        waitDiceAni(2);
    }
    else if(gameStates == 3){ //Move
        if(diceNum > 0){
            NestZwalk(diceNum);
        }
    }
    else if(gameStates == 4){ //checkPath
        switch(Path[player[now_player].NestZ_nowPath].pathEf){
            case 0:
                shopAsk();
                break;
            case 1:
                RandomMoney();
                break;
            case 2:
                useThisItem(false);
                gameStates = 7;
                break;
            case 3:
                Heal();
                break;
            case 4:
                dunAsk(0);
                break;
            case 5:
                dunAsk(player[now_player].bossIndex);
                break;
            case 6:
                dunAsk(player[now_player].bossIndex);
                break;
            case 7:
                dunAsk(player[now_player].bossIndex);
        };
    }
    else if(gameStates == 5){ //dungeon
        isDun = true;
        dungeon(askKind);
        //gameStates = 7;
    }
    else if(gameStates == 6){ //shop
        isShopOpen = true;
    }
    else if(gameStates == 7){ //end turn
        gameStates = 1;
        turn++;
    }
    else if(gameStates == 8){}
}

void Game::NestZwalk(int &diceMove){
    if(player[now_player].NestZ_nowPath == 0)nextPath = Path[player[now_player].NestZ_nowPath].nextPath(-1);
    else nextPath = Path[player[now_player].NestZ_nowPath].nextPath(player[now_player].allPath[player[now_player].allPath.size() - 2]);
    if(nextPath.size() == 1){
        moveDelay(diceMove);
    }
    else{
        moveDelayJunction(diceMove);
    }
}

void Game::moveDelay(int &diceMove){
    totalTime += deltaTime;
    if(totalTime >= 0.8f){
        totalTime -= 0.8f;
        timeTemp.push_back(1);
        if(player[now_player].NestZ_nowPath == 0)nextPath = Path[player[now_player].NestZ_nowPath].nextPath(-1);
        else nextPath = Path[player[now_player].NestZ_nowPath].nextPath(player[now_player].allPath[player[now_player].allPath.size() - 2]);
        player[now_player].NestZ_nowPath = nextPath.back();
        diceMove--;
        player[now_player].allPath.push_back(player[now_player].NestZ_nowPath);
    }
    if(timeTemp.size() == moveTemp){
        while(timeTemp.size() != 0)timeTemp.pop_back();
        totalTime = 0.0f;
        gameStates = 4;
    }
}

void Game::moveDelayJunction(int &diceMove){
    if(askTemp){
        isAskGo = true;
        askTemp = false;
    }
    if(!isAskGo){
        totalTime += deltaTime;
        if(totalTime >= 0.8f){
            totalTime -= 0.8f;
            timeTemp.push_back(1);
            player[now_player].NestZ_nowPath = playerChoosedPath;
            diceMove--;
            player[now_player].allPath.push_back(player[now_player].NestZ_nowPath);
            askTemp = true;
        }
        if(timeTemp.size() == moveTemp){
            while(timeTemp.size() != 0)timeTemp.pop_back();
            totalTime = 0.0f;
            gameStates = 4;
        }
    }
}

void Game::updateAskGo(){
    if(player[now_player].NestZ_nowPath == 0)nextPath = Path[player[now_player].NestZ_nowPath].nextPath(-1);
    else nextPath = Path[player[now_player].NestZ_nowPath].nextPath(player[now_player].allPath[player[now_player].allPath.size() - 2]);
    UI_askGoText.setOrigin(getObjWidth(UI_askGoText) / 2,getObjHeight(UI_askGoText) / 2);
    UI_askGoText.setPosition(windowMidWidth(),windowMidHeight() - 50);
    UI_askGoPath[0].setString("Path  " + to_string(nextPath.front()));
    UI_askGoPath[0].setOrigin(getObjWidth(UI_askGoPath[0]) / 2,getObjHeight(UI_askGoPath[0]) / 2);
    UI_askGoPath[0].setPosition(windowMidWidth() + 200,windowMidHeight() + 50);
    UI_askGoPath[1].setString("Path  " + to_string(nextPath.back()));
    UI_askGoPath[1].setOrigin(getObjWidth(UI_askGoPath[1]) / 2,getObjHeight(UI_askGoPath[1]) / 2);
    UI_askGoPath[1].setPosition(windowMidWidth() - 200,windowMidHeight() + 50);
    if(UI_askGoPath[0].getGlobalBounds().contains(mousePos)){
        UI_askGoPath[0].setScale(1.05,1.05);
        if(checkMouseClick()){
            isAskGo = false;
            playerChoosedPath = nextPath.front();
        }
    }
    else UI_askGoPath[0].setScale(1,1);
    if(UI_askGoPath[1].getGlobalBounds().contains(mousePos)){
        UI_askGoPath[1].setScale(1.05,1.05);
        if(checkMouseClick()){
            isAskGo = false;
            playerChoosedPath = nextPath.back();
        }
    }
    else UI_askGoPath[1].setScale(1,1);
}

void Game::setPath(){//0 shop : 1 money : 2 ranitem : 3 heal : dun1 4 : dun2 5 : dum3 6 : boos 7;
    Path[0] = {-1,1143,1806,-1,-1};
    Path[0].nextPathNum_1.push_back(1);
    Path[0].nextPathNum_2.push_back(1);

    Path[1] = {1,988,1806,0,2};
    Path[1].nextPathNum_1.push_back(2);
    Path[1].nextPathNum_1.push_back(52);
    Path[1].nextPathNum_2.push_back(52);

    Path[2] = {4,822,1806,1,3};
    Path[2].nextPathNum_1.push_back(3);
    Path[2].nextPathNum_2.push_back(1);

    Path[3] = {4,659,1806,2,4};
    Path[3].nextPathNum_1.push_back(4);
    Path[3].nextPathNum_2.push_back(2);

    Path[4] = {1,502,1806,3,5};
    Path[4].nextPathNum_1.push_back(5);
    Path[4].nextPathNum_2.push_back(3);

    Path[5] = {4,392,1697,4,6};
    Path[5].nextPathNum_1.push_back(6);
    Path[5].nextPathNum_2.push_back(4);

    Path[6] = {5,381,1556,5,7};
    Path[6].nextPathNum_1.push_back(7);
    Path[6].nextPathNum_2.push_back(5);

    Path[7] = {0,387,1410,6,8};
    Path[7].nextPathNum_1.push_back(8);
    Path[7].nextPathNum_2.push_back(6);

    Path[8] = {0,388,1265,7,9};
    Path[8].nextPathNum_1.push_back(9);
    Path[8].nextPathNum_2.push_back(7);

    Path[9] = {3,386,1120,8,10};
    Path[9].nextPathNum_1.push_back(10);
    Path[9].nextPathNum_2.push_back(8);

    Path[10] = {6,390,976,9,11};
    Path[10].nextPathNum_1.push_back(11);
    Path[10].nextPathNum_2.push_back(9);

    Path[11] = {4,391,829,10,12,53};
    Path[11].nextPathNum_1.push_back(12);
    Path[11].nextPathNum_1.push_back(53);
    Path[11].nextPathNum_2.push_back(10);

    Path[12] = {5,397,690,13,11,53};
    Path[12].nextPathNum_1.push_back(11);
    Path[12].nextPathNum_1.push_back(53);
    Path[12].nextPathNum_2.push_back(13);

    Path[13] = {5,398,549,12,14};
    Path[13].nextPathNum_1.push_back(14);
    Path[13].nextPathNum_2.push_back(12);

    Path[14] = {3,400,409,13,15};
    Path[14].nextPathNum_1.push_back(15);
    Path[14].nextPathNum_2.push_back(13);

    Path[15] = {0,530,324,14,16};
    Path[15].nextPathNum_1.push_back(16);
    Path[15].nextPathNum_2.push_back(14);

    Path[16] = {0,657,246,15,17};
    Path[16].nextPathNum_1.push_back(17);
    Path[16].nextPathNum_2.push_back(15);

    Path[17] = {0,788,314,16,18};
    Path[17].nextPathNum_1.push_back(18);
    Path[17].nextPathNum_2.push_back(16);

    Path[18] = {6,921,243,17,19};
    Path[18].nextPathNum_1.push_back(19);
    Path[18].nextPathNum_2.push_back(17);

    Path[19] = {5,1055,306,18,20};
    Path[19].nextPathNum_1.push_back(20);
    Path[19].nextPathNum_2.push_back(18);

    Path[20] = {6,1182,239,19,21};
    Path[20].nextPathNum_1.push_back(21);
    Path[20].nextPathNum_2.push_back(19);

    Path[21] = {3,1310,307,20,22};
    Path[21].nextPathNum_1.push_back(22);
    Path[21].nextPathNum_2.push_back(20);

    Path[22] = {1,1440,232,21,23};
    Path[22].nextPathNum_1.push_back(23);
    Path[22].nextPathNum_2.push_back(21);

    Path[23] = {6,1564,305,22,24};
    Path[23].nextPathNum_1.push_back(24);
    Path[23].nextPathNum_2.push_back(22);

    Path[24] = {4,1701,233,23,25};
    Path[24].nextPathNum_1.push_back(25);
    Path[24].nextPathNum_2.push_back(23);

    Path[25] = {4,1830,304,24,26};
    Path[25].nextPathNum_1.push_back(26);
    Path[25].nextPathNum_2.push_back(24);

    Path[26] = {5,1962,226,25,27};
    Path[26].nextPathNum_1.push_back(27);
    Path[26].nextPathNum_2.push_back(25);

    Path[27] = {3,2094,310,26,28};
    Path[27].nextPathNum_1.push_back(28);
    Path[27].nextPathNum_2.push_back(26);

    Path[28] = {3,2223,400,27,29,70};
    Path[28].nextPathNum_1.push_back(29);
    Path[28].nextPathNum_1.push_back(70);
    Path[28].nextPathNum_2.push_back(27);

    Path[29] = {1,2377,452,30,28,70};
    Path[29].nextPathNum_1.push_back(28);
    Path[29].nextPathNum_1.push_back(70);
    Path[29].nextPathNum_2.push_back(30);

    Path[30] = {1,2502,378,29,31};
    Path[30].nextPathNum_1.push_back(31);
    Path[30].nextPathNum_2.push_back(29);

    Path[31] = {1,2616,464,30,32};
    Path[31].nextPathNum_1.push_back(32);
    Path[31].nextPathNum_2.push_back(30);

    Path[32] = {0,2733,452,31,33};
    Path[32].nextPathNum_1.push_back(33);
    Path[32].nextPathNum_2.push_back(31);

    Path[33] = {0,2769,700,32,34};
    Path[33].nextPathNum_1.push_back(34);
    Path[33].nextPathNum_2.push_back(32);

    Path[34] = {4,2773,847,33,35};
    Path[34].nextPathNum_1.push_back(35);
    Path[34].nextPathNum_2.push_back(33);

    Path[35] = {6,2775,997,34,36};
    Path[35].nextPathNum_1.push_back(36);
    Path[35].nextPathNum_2.push_back(34);

    Path[36] = {6,2778,1145,35,37};
    Path[36].nextPathNum_1.push_back(37);
    Path[36].nextPathNum_2.push_back(35);

    Path[37] = {5,2781,1308,36,38};
    Path[37].nextPathNum_1.push_back(38);
    Path[37].nextPathNum_2.push_back(36);

    Path[38] = {4,2664,1394,37,39};
    Path[38].nextPathNum_1.push_back(39);
    Path[38].nextPathNum_2.push_back(37);

    Path[39] = {3,2533,1460,38,40};
    Path[39].nextPathNum_1.push_back(40);
    Path[39].nextPathNum_2.push_back(38);

    Path[40] = {3,2404,1526,39,41,75};
    Path[40].nextPathNum_1.push_back(41);
    Path[40].nextPathNum_1.push_back(75);
    Path[40].nextPathNum_2.push_back(39);

    Path[41] = {3,2263,1590,42,40,75};
    Path[41].nextPathNum_1.push_back(40);
    Path[41].nextPathNum_1.push_back(75);
    Path[41].nextPathNum_2.push_back(42);

    Path[42] = {4,2154,1713,41,43};
    Path[42].nextPathNum_1.push_back(43);
    Path[42].nextPathNum_2.push_back(41);

    Path[43] = {5,1995,1712,42,44};
    Path[43].nextPathNum_1.push_back(44);
    Path[43].nextPathNum_2.push_back(42);

    Path[44] = {3,1833,1712,43,45};
    Path[44].nextPathNum_1.push_back(45);
    Path[44].nextPathNum_2.push_back(43);

    Path[45] = {0,1704,1635,44,46};
    Path[45].nextPathNum_1.push_back(46);
    Path[45].nextPathNum_2.push_back(44);

    Path[46] = {0,1576,1560,45,47};
    Path[46].nextPathNum_1.push_back(47);
    Path[46].nextPathNum_2.push_back(45);

    Path[47] = {0,1456,1478,46,48,69};
    Path[47].nextPathNum_1.push_back(48);
    Path[47].nextPathNum_1.push_back(69);
    Path[47].nextPathNum_2.push_back(46);

    Path[48] = {1,1332,1398,49,47,69};
    Path[48].nextPathNum_1.push_back(69);
    Path[48].nextPathNum_1.push_back(47);
    Path[48].nextPathNum_2.push_back(49);

    Path[49] = {1,1206,1328,48,50};
    Path[49].nextPathNum_1.push_back(50);
    Path[49].nextPathNum_2.push_back(48);

    Path[50] = {1,1077,1401,49,51};
    Path[50].nextPathNum_1.push_back(51);
    Path[50].nextPathNum_2.push_back(49);

    Path[51] = {5,1053,1544,50,52};
    Path[51].nextPathNum_1.push_back(52);
    Path[51].nextPathNum_2.push_back(50);

    Path[52] = {5,991,1670,1,51};
    Path[52].nextPathNum_1.push_back(51);
    Path[52].nextPathNum_2.push_back(1);

    Path[53] = {1,526,763,54,11,12};
    Path[53].nextPathNum_1.push_back(11);
    Path[53].nextPathNum_1.push_back(12);
    Path[53].nextPathNum_2.push_back(54);

    Path[54] = {4,651,829,53,55};
    Path[54].nextPathNum_1.push_back(55);
    Path[54].nextPathNum_2.push_back(53);

    Path[55] = {5,786,755,54,56};
    Path[55].nextPathNum_1.push_back(56);
    Path[55].nextPathNum_2.push_back(54);

    Path[56] = {3,906,827,55,57};
    Path[56].nextPathNum_1.push_back(57);
    Path[56].nextPathNum_2.push_back(55);

    Path[57] = {3,1032,752,56,58};
    Path[57].nextPathNum_1.push_back(58);
    Path[57].nextPathNum_2.push_back(56);

    Path[58] = {7,1197,782,57,59};
    Path[58].nextPathNum_1.push_back(59);
    Path[58].nextPathNum_2.push_back(57);

    Path[59] = {7,1374,782,58,60};
    Path[59].nextPathNum_1.push_back(60);
    Path[59].nextPathNum_2.push_back(58);

    Path[60] = {7,1545,782,59,61};
    Path[60].nextPathNum_1.push_back(61);
    Path[60].nextPathNum_2.push_back(59);

    Path[61] = {7,1717,784,60,62};
    Path[61].nextPathNum_1.push_back(62);
    Path[61].nextPathNum_2.push_back(60);

    Path[62] = {7,1893,784,61,63};
    Path[62].nextPathNum_1.push_back(63);
    Path[62].nextPathNum_2.push_back(61);

    Path[63] = {3,2058,778,62,64,71};
    Path[63].nextPathNum_1.push_back(64);
    Path[63].nextPathNum_1.push_back(71);
    Path[63].nextPathNum_2.push_back(62);

    Path[64] = {3,2062,928,63,65,72};
    Path[64].nextPathNum_1.push_back(65);
    Path[64].nextPathNum_1.push_back(72);
    Path[64].nextPathNum_2.push_back(63);

    Path[65] = {5,1944,1015,66,64,72};
    Path[65].nextPathNum_1.push_back(64);
    Path[65].nextPathNum_1.push_back(72);
    Path[65].nextPathNum_2.push_back(66);

    Path[66] = {6,1802,1069,65,67};
    Path[66].nextPathNum_1.push_back(67);
    Path[66].nextPathNum_2.push_back(65);

    Path[67] = {1,1677,1136,66,68};
    Path[67].nextPathNum_1.push_back(68);
    Path[67].nextPathNum_2.push_back(66);

    Path[68] = {3,1558,1220,67,69};
    Path[68].nextPathNum_1.push_back(69);
    Path[68].nextPathNum_2.push_back(67);

    Path[69] = {4,1462,1332,68,47,48};
    Path[69].nextPathNum_1.push_back(47);
    Path[69].nextPathNum_1.push_back(48);
    Path[69].nextPathNum_2.push_back(68);

    Path[70] = {5,2259,548,71,28,29};
    Path[70].nextPathNum_1.push_back(28);
    Path[70].nextPathNum_1.push_back(29);
    Path[70].nextPathNum_2.push_back(71);

    Path[71] = {5,2187,700,63,70};
    Path[71].nextPathNum_1.push_back(70);
    Path[71].nextPathNum_2.push_back(63);

    Path[72] = {4,2093,1066,73,64,65};
    Path[72].nextPathNum_1.push_back(64);
    Path[72].nextPathNum_1.push_back(65);
    Path[72].nextPathNum_2.push_back(73);

    Path[73] = {4,2215,1155,72,74};
    Path[73].nextPathNum_1.push_back(74);
    Path[73].nextPathNum_2.push_back(72);

    Path[74] = {6,2256,1298,73,75};
    Path[74].nextPathNum_1.push_back(75);
    Path[74].nextPathNum_2.push_back(73);

    Path[75] = {1,2260,1442,74,40,41};
    Path[75].nextPathNum_1.push_back(40);
    Path[75].nextPathNum_1.push_back(41);
    Path[75].nextPathNum_2.push_back(74);
}

void Game::waitDiceAni(unsigned int time){
    totalTime += deltaTime;
    if(totalTime >= animationSpeed){
        totalTime -= animationSpeed;
        timeTemp.push_back(1);
    }
    if(timeTemp.size() == time){
        while(timeTemp.size() != 0)timeTemp.pop_back();
        totalTime = 0.0f;
        gameStates = 3;
    }
}

void Game::diceState(){
        this->gameWindow->draw(UI_diceS);
        if(UI_diceS.getGlobalBounds().contains(mousePos) && !isDesOpen && !isMenuOpen && !isAskOpen){
            UI_diceS.setScale(1.05,1.05);
            if(checkMouseClick()){
                    randomStart = true;
            }
        }
        else UI_diceS.setScale(1,1);
}

void Game::randomDice(){
    totalTime += deltaTime;
    if(totalTime >= animationSpeed){
        totalTime -= animationSpeed;
        do{
            diceNum = rand() % 6 + 1;
        }while(diceNum == diceTemp.back());
        UI_diceValue.setString(to_string(diceNum));
        this->gameWindow->draw(UI_diceValue);
        diceTemp.push_back(diceNum);
    }
    if(diceTemp.size() == 5){
        gameStates = 2;
        totalTime = 0.0f;
    }
}

void Game::updateView(){
    if(Mouse::getPosition(*this->gameWindow).x > windowWidth - 3 && camera.getCenter().x < 2040){
        camera.move(horizontalScrollSpeed,0);
    }
    else if(Mouse::getPosition(*this->gameWindow).x < 3 && camera.getCenter().x > windowMidWidth()){
        camera.move(-horizontalScrollSpeed,0);
    }
    if(Mouse::getPosition(*this->gameWindow).y > windowHeight - 3 && camera.getCenter().y < 1460){
        camera.move(0,verticalScrollSpeed);
    }
    else if(Mouse::getPosition(*this->gameWindow).y < 3 && camera.getCenter().y > windowMidHeight()){
        camera.move(0,-verticalScrollSpeed);
    }
}

void Game::updateEscape(){
    if(checkEscape()){
        if(isMenuOpen)isMenuOpen = false;
        else if(!isMenuOpen && !isDesOpen && !isMonDes)isMenuOpen = true;
        else if(!isMenuOpen && isDesOpen)isDesOpen = false;
        if(!isMenuOpen && isMonDes)isMonDes = false;
    }
}

void Game::updateMiniMenuClick(){
    for(int i = 0;i < 3;i++){
        if(miniMenuText[i].getGlobalBounds().contains(mousePos)){
            miniMenuText[i].setScale(1.02,1.02);
            if(checkMouseClick()){
                switch(i){
                    case 0:
                        isMenuOpen = false;
                        break;
                    case 1:
                        state.push(Setting);
                        break;
                    case 2:
                        resetCC();
                        resetIPN();
                        isMenuOpen = false;
                        while(state.top() != Menu)state.pop();
                        break;
                }
            }
        }
        else miniMenuText[i].setScale(1,1);
    }
}

void Game::drawUI(){
    UI_level.setString("LV. " + to_string(player[now_player].level));
    for(int i = 0;i < 3;i++){
        if(i <= player[now_player].star - 1)UI_starS[i].setColor(Color(255,255,255,255));
        else UI_starS[i].setColor(Color(128,128,128,128));
        UI_starS[i].setPosition((UI_level.getPosition().x + 100) + (i+1) * 60,UI_level.getPosition().y);
    }
    UI_name.setString(playerName[now_player]);
    UI_name.setOrigin(getObjWidth(UI_name) / 2,getObjHeight(UI_name) / 2);
    UI_charFaceS.setTexture(UI_charFaceT[player[now_player].character_number]);
    UI_charFaceS.setOrigin(getObjWidth(UI_charFaceS) / 2,getObjHeight(UI_charFaceS) / 2);
    UI_expBarS.setScale((double)player[now_player].exp / needexp[player[now_player].level - 1],1);
    UI_hpBarS.setScale((double)player[now_player].hp / player[now_player].HpMax(),1);
    UI_hpText.setPosition(UI_hpBorderS.getPosition().x - 130,UI_hpBorderS.getPosition().y);
    UI_hpValue.setPosition(UI_hpBorderS.getPosition().x + ((getObjWidth(UI_hpBorderS) / 2) - getObjWidth(UI_hpValue) / 2),UI_hpBorderS.getPosition().y + ((getObjHeight(UI_hpBorderS) / 2) - getObjHeight(UI_hpValue) / 2) - 17);
    UI_expText.setPosition(UI_hpText.getPosition().x,UI_expBorderS.getPosition().y);
    UI_expValue.setPosition(UI_expBorderS.getPosition().x + ((getObjWidth(UI_expBorderS) / 2) - getObjWidth(UI_expValue) / 2),UI_expBorderS.getPosition().y + ((getObjHeight(UI_expBorderS) / 2) - getObjHeight(UI_expValue) / 2) - 17);
    UI_hpSValue.setString(to_string(player[now_player].red_potion));
    UI_hpSValue.setOrigin(getObjWidth(UI_hpSValue) / 2,getObjHeight(UI_hpSValue) / 2);
    UI_hpSValue.setPosition(UI_HpSS.getPosition().x - 17,UI_HpSS.getPosition().y + 4);
    UI_hpLValue.setString(to_string(player[now_player].green_potion));
    UI_hpLValue.setOrigin(getObjWidth(UI_hpLValue) / 2,getObjHeight(UI_hpLValue) / 2);
    UI_hpLValue.setPosition(UI_HpLS.getPosition().x - 17,UI_HpLS.getPosition().y + 4);
    if(isDesOpen){
        UI_playerDesCharS.setTexture(charTexture[player[now_player].character_number]);
        UI_playerDesCharS.setOrigin(getObjWidth(UI_playerDesCharS) / 2,getObjHeight(UI_playerDesCharS) / 2);
        UI_playerDesCharS.setPosition(UI_playerDesBGS.getPosition().x,UI_playerDesBGS.getPosition().y - 160);
        UI_playerNameDes.setString(playerName[now_player]);
        UI_playerNameDes.setOrigin(getObjWidth(UI_playerNameDes) / 2,getObjHeight(UI_playerNameDes) / 2);
        UI_playerNameDes.setPosition(UI_playerDesBGS.getPosition().x + 5,UI_playerDesBGS.getPosition().y - 70);
        UI_statDes.setString("Level  :     " + to_string(player[now_player].level) + '\n' +
                             "Class  :     " + characters[player[now_player].character_number].clas + '\n' +
                             "ATK  :     " + to_string(player[now_player].getAtk()) + '\n' +
                             "Max HP  :     " + to_string(player[now_player].HpMax()) + '\n' +
                             "STR  :     " + to_string(player[now_player].std_str) + "  +  " + to_string((player[now_player].accessoryIndex > -1 ? accessory[player[now_player].accessoryIndex].extra_str:0) +
                             sword[player[now_player].weaponIndex].sword_stat[0]) + '\n' +
                             "VIT  :     " + to_string(player[now_player].std_vit) + "  +  " + to_string((player[now_player].accessoryIndex > -1 ? accessory[player[now_player].accessoryIndex].extra_vit:0) +
                             (player[now_player].shieldIndex > -1 ? shield[player[now_player].shieldIndex].shield_stat[0]:0)) + '\n' +
                             "MONEY  :     " + to_string(player[now_player].money) + "     Coins"
                             );
        UI_statDesR.setString("DEF  :     " + to_string(player[now_player].getDef()) + "\n\n" +
                              "AGI  :     " + to_string(player[now_player].std_agi) + "  +  " + to_string((player[now_player].accessoryIndex > -1 ? accessory[player[now_player].accessoryIndex].extra_agi:0) + sword[player[now_player].weaponIndex].sword_stat[1]) + '\n' +
                              "LUK  :     " + to_string(player[now_player].std_luk) + "  +  " + to_string((player[now_player].accessoryIndex > -1 ? accessory[player[now_player].accessoryIndex].extra_luck:0) + sword[player[now_player].weaponIndex].sword_stat[2])
                              );
        UI_statDes.setPosition(UI_playerDesBGS.getPosition().x - 210,UI_playerDesBGS.getPosition().y - 30);
        UI_statDesR.setPosition(UI_playerDesBGS.getPosition().x + 35,UI_playerDesBGS.getPosition().y + 50);
    }
    if(gameStates == 1){
        UI_diceValue.setOrigin(getObjWidth(UI_diceValue) / 2,getObjHeight(UI_diceValue) / 2);
        UI_diceValue.setPosition(windowMidWidth(),windowMidHeight());
    }
    else if(gameStates == 2){
        UI_diceValue.setScale(1.4,1.4);
    }
    else UI_diceValue.setScale(1,1);
    this->gameWindow->draw(UI_maxHpS);
    this->gameWindow->draw(UI_hpBarS);
    this->gameWindow->draw(UI_hpBorderS);
    this->gameWindow->draw(UI_hpText);
    this->gameWindow->draw(UI_maxExpS);
    this->gameWindow->draw(UI_expBarS);
    this->gameWindow->draw(UI_expBorderS);
    this->gameWindow->draw(UI_expText);
    this->gameWindow->draw(UI_charFaceS);
    this->gameWindow->draw(UI_name);
    this->gameWindow->draw(UI_level);
    for(int i = 0;i < 3;i++){
        this->gameWindow->draw(UI_starS[i]);
    }
    this->gameWindow->draw(UI_bagS);
    if(isBagOpen){
        UI_swordS.setTexture(UI_swordT[player[now_player].weaponIndex]);
        UI_swordS.setOrigin(getObjWidth(UI_swordS) / 2,getObjHeight(UI_swordS) / 2);
        UI_swordS.setScale(0.65,0.65);
        UI_swordS.setPosition(UI_HpSS.getPosition().x - 136,UI_HpSS.getPosition().y);
        if(player[now_player].shieldIndex != -1){
            UI_shieldS.setTexture(UI_shieldT[player[now_player].shieldIndex]);
            UI_shieldS.setOrigin(getObjWidth(UI_shieldS) / 2,getObjHeight(UI_shieldS) / 2);
            UI_shieldS.setScale(0.65,0.65);
            UI_shieldS.setPosition(UI_HpSS.getPosition().x - 68,UI_HpSS.getPosition().y);
        }
        if(player[now_player].accessoryIndex != -1){
            UI_accS.setTexture(UI_accT[player[now_player].accessoryIndex]);
            UI_accS.setOrigin(getObjWidth(UI_accS) / 2,getObjHeight(UI_accS) / 2);
            UI_accS.setScale(0.65,0.65);
            UI_accS.setPosition(UI_HpSS.getPosition().x + 136,UI_HpSS.getPosition().y);
        }
        this->gameWindow->draw(UI_invenS);
        if(player[now_player].red_potion == 0)UI_HpSS.setColor(Color(160,160,160,255));
        else UI_HpSS.setColor(Color(255,255,255,255));
        this->gameWindow->draw(UI_HpSS);
        if(player[now_player].green_potion == 0)UI_HpLS.setColor(Color(160,160,160,255));
        else UI_HpLS.setColor(Color(255,255,255,255));
        this->gameWindow->draw(UI_HpLS);
        this->gameWindow->draw(UI_hpSValue);
        this->gameWindow->draw(UI_hpLValue);
        this->gameWindow->draw(UI_swordS);
        if(player[now_player].shieldIndex != -1)this->gameWindow->draw(UI_shieldS);
        if(player[now_player].accessoryIndex != -1)this->gameWindow->draw(UI_accS);
    }
    if(!isMenuOpen)updateUI();
}

void Game::updateUI(){
    UI_hpValue.setString(to_string(player[now_player].hp) + "/" + to_string(player[now_player].HpMax()));
    UI_expValue.setString(to_string(player[now_player].exp) + "/" + to_string(needexp[player[now_player].level - 1]));
    for(int i = 0;i < 10;i++){
        if(player[now_player].weaponIndex != -1){
            UI_swordName[i].setPosition(mouseIconSprite.getPosition().x,mouseIconSprite.getPosition().y - 90);
            UI_swordDes[i].setPosition(mouseIconSprite.getPosition().x,mouseIconSprite.getPosition().y - 60);
        }
        if(player[now_player].shieldIndex != -1){
            UI_shieldName[i].setPosition(mouseIconSprite.getPosition().x,mouseIconSprite.getPosition().y - 90);
            UI_shieldDes[i].setPosition(mouseIconSprite.getPosition().x,mouseIconSprite.getPosition().y - 60);
        }
        if(player[now_player].accessoryIndex != -1){
            UI_accDes[i].setPosition(mouseIconSprite.getPosition().x,mouseIconSprite.getPosition().y - 92);
            UI_accName[i].setPosition(mouseIconSprite.getPosition().x,mouseIconSprite.getPosition().y - 122);
        }
        if(i < 2){
            UI_potionName[i].setPosition(mouseIconSprite.getPosition().x,mouseIconSprite.getPosition().y - 60);
            UI_potionDes[i].setPosition(mouseIconSprite.getPosition().x,mouseIconSprite.getPosition().y - 30);
        }
    }
    if(UI_maxHpS.getGlobalBounds().contains(mousePos)){
        this->gameWindow->draw(UI_hpValue);
    }
    if(UI_maxExpS.getGlobalBounds().contains(mousePos)){
        this->gameWindow->draw(UI_expValue);
    }
    if(UI_charFaceS.getGlobalBounds().contains(mousePos)){
        UI_charFaceS.setScale(1.05,1.05);
        if(checkMouseClick()){
            if(isDesOpen)isDesOpen = false;
            else{
                isDesOpen = true;
                isMonDes = false;
            }
        }
    }
    else UI_charFaceS.setScale(1,1);
    if(UI_bagS.getGlobalBounds().contains(mousePos)){
        UI_bagS.setScale(0.85,0.85);
        if(checkMouseClick()){
            if(isBagOpen)isBagOpen = false;
            else isBagOpen = true;
        }
    }
    else UI_bagS.setScale(0.8,0.8);
    if(UI_HpSS.getGlobalBounds().contains(mousePos)){
        if(player[now_player].red_potion > 0)UI_HpSS.setScale(0.7,0.7);
        if(checkMouseClick() && player[now_player].hp < player[now_player].HpMax()){
            if(player[now_player].red_potion > 0 && canUsePotion){
                player[now_player].red_potion--;
                usePotion(potion[0].potion_effect);
            }
        }
    }
    else UI_HpSS.setScale(0.65,0.65);
    if(UI_HpLS.getGlobalBounds().contains(mousePos)){
        if(player[now_player].green_potion > 0)UI_HpLS.setScale(0.7,0.7);
        if(checkMouseClick() && player[now_player].hp < player[now_player].HpMax()){
            if(player[now_player].green_potion > 0 && canUsePotion){
                player[now_player].green_potion--;
                usePotion(potion[1].potion_effect);
            }
        }
    }
    else UI_HpLS.setScale(0.65,0.65);
    if(isBagOpen){
        if(UI_swordS.getGlobalBounds().contains(mousePos)){
            this->gameWindow->draw(UI_swordName[player[now_player].weaponIndex]);
            this->gameWindow->draw(UI_swordDes[player[now_player].weaponIndex]);
        }
        if(UI_shieldS.getGlobalBounds().contains(mousePos) && player[now_player].shieldIndex != -1){
            this->gameWindow->draw(UI_shieldName[player[now_player].shieldIndex]);
            this->gameWindow->draw(UI_shieldDes[player[now_player].shieldIndex]);
        }
        if(UI_accS.getGlobalBounds().contains(mousePos) && player[now_player].accessoryIndex != -1){
            this->gameWindow->draw(UI_accName[player[now_player].accessoryIndex]);
            this->gameWindow->draw(UI_accDes[player[now_player].accessoryIndex]);
        }
        if(UI_HpSS.getGlobalBounds().contains(mousePos)){
            this->gameWindow->draw(UI_potionName[0]);
            this->gameWindow->draw(UI_potionDes[0]);
        }
        if(UI_HpLS.getGlobalBounds().contains(mousePos)){
            this->gameWindow->draw(UI_potionName[1]);
            this->gameWindow->draw(UI_potionDes[1]);
        }
    }
}

void Game::usePotion(int heal){
        if(heal + player[now_player].hp >= player[now_player].HpMax()){
            player[now_player].hp = player[now_player].HpMax();
        }
        else if(heal + player[now_player].hp < player[now_player].HpMax()){
            player[now_player].hp += heal;
        }
}

void Game::updateTurn(){
    now_player = turn % players;
}

void Game::setItemStat(){
    sword[0].name_object = "Fist";                                   sword[0].Des = "STR + 0\nAGI + 0\nLUK + 0";       sword[0].sword_stat[0] = 0;sword[0].sword_stat[1] = 0;sword[0].sword_stat[2] = 0;
    sword[1].name_object = "Durandal";     sword[1].price = 10;      sword[1].Des = "STR + 0\nAGI + 0\nLUK + 0";       sword[1].sword_stat[0] = 2;sword[1].sword_stat[1] = 0;sword[1].sword_stat[2] = 1;
    sword[2].name_object = "Muramasas";    sword[2].price = 10;     sword[2].Des = "STR + 0\nAGI + 0\nLUK + 0";       sword[2].sword_stat[0] = 3;sword[2].sword_stat[1] = 2;sword[2].sword_stat[2] = 2;
    sword[3].name_object = "Murasame";     sword[3].price = 10;      sword[3].Des = "STR + 0\nAGI + 0\nLUK + 0";       sword[3].sword_stat[0] = 4;sword[3].sword_stat[1] = 2;sword[3].sword_stat[2] = 1;
    sword[4].name_object = "Masamune";     sword[4].price = 10;      sword[4].Des = "STR + 0\nAGI + 0\nLUK + 0";       sword[4].sword_stat[0] = 3;sword[4].sword_stat[1] = 2;sword[4].sword_stat[2] = 4;
    sword[5].name_object = "Shusui";       sword[5].price = 10;     sword[5].Des = "STR + 0\nAGI + 0\nLUK + 0";       sword[5].sword_stat[0] = 6;sword[5].sword_stat[1] = 3;sword[5].sword_stat[2] = 3;
    sword[6].name_object = "Yubashiri";    sword[6].price = 10;      sword[6].Des = "STR + 0\nAGI + 0\nLUK + 0";       sword[6].sword_stat[0] = 5;sword[6].sword_stat[1] = 4;sword[6].sword_stat[2] = 4;
    sword[7].name_object = "Kitetsu Sandai";                         sword[7].Des = "STR + 0\nAGI + 0\nLUK + 0";       sword[7].sword_stat[0] = 9;sword[7].sword_stat[1] = 2;sword[7].sword_stat[2] = 4;
    sword[8].name_object = "Wado Ichimonji";                         sword[8].Des = "STR + 0\nAGI + 0\nLUK + 0";       sword[8].sword_stat[0] = 10;sword[8].sword_stat[1] = 3;sword[8].sword_stat[2] = 5;
    sword[9].name_object = "Excalibur";                              sword[9].Des = "STR + 0\nAGI + 0\nLUK + 0";       sword[9].sword_stat[0] = 20;sword[9].sword_stat[1] = -5;sword[9].sword_stat[2] = 3;

    potion[0].name_object ="Potion S" ;    potion[0].price = 10;      potion[0].Des = "HP + 10";                        potion[0].potion_effect = 10;
    potion[1].name_object ="Potion L";     potion[1].price = 10;      potion[1].Des = "HP + 30";                        potion[1].potion_effect = 30;

    shield[0].name_object = "Hand";        shield[0].price = 10;       shield[0].Des = "VIT + 0\nDEF + 0\nMAX HP + 0";  shield[0].shield_stat[0] = 0;shield[0].shield_stat[1]= 0;shield[0].shield_stat[2]= 0;
    shield[1].name_object = "Aegis Shield ";  shield[1].price = 10;    shield[1].Des = "VIT + 0\nDEF + 0\nMAX HP + 0";  shield[1].shield_stat[0] = 2;shield[1].shield_stat[1]= 3;shield[1].shield_stat[2]= 30;
    shield[2].name_object = "Saka Shield";    shield[2].price = 10;    shield[2].Des = "VIT + 0\nDEF + 0\nMAX HP + 0";  shield[2].shield_stat[0] = 3;shield[2].shield_stat[1]= 0;shield[2].shield_stat[2]= 50;
    shield[3].name_object = "Arachiki Shield"; shield[3].price = 10; shield[3].Des = "VIT + 0\nDEF + 0\nMAX HP + 0";  shield[3].shield_stat[0] = 4;shield[3].shield_stat[1]= 4;shield[3].shield_stat[2]= 40;
    shield[4].name_object = "Demose Shield";  shield[4].price = 10;   shield[4].Des = "VIT + 0\nDEF + 0\nMAX HP + 0";  shield[4].shield_stat[0] = 5;shield[4].shield_stat[1]= 2;shield[4].shield_stat[2]= 2;
    shield[5].name_object = "G.O.T Shield ";  shield[5].price = 10;    shield[5].Des = "VIT + 0\nDEF + 0\nMAX HP + 0";  shield[5].shield_stat[0] = 2;shield[5].shield_stat[1]= 7;shield[5].shield_stat[2]= 20;
    shield[6].name_object = "Power Shield ";  shield[6].price = 10;   shield[6].Des = "VIT + 0\nDEF + 0\nMAX HP + 0";  shield[6].shield_stat[0] = 7;shield[6].shield_stat[1]= 8;shield[6].shield_stat[2]= 50;
    shield[7].name_object = "DK Shield ";     shield[7].price = 10;    shield[7].Des = "VIT + 0\nDEF + 0\nMAX HP + 0";  shield[7].shield_stat[0] = 5;shield[7].shield_stat[1]= 10;shield[7].shield_stat[2]= 60;
    shield[8].name_object = "Invincible Shield ";                      shield[8].Des = "VIT + 0\nDEF + 0\nMAX HP + 0";  shield[8].shield_stat[0] = 3;shield[8].shield_stat[1]= 15;shield[8].shield_stat[2]= 100;
    shield[9].name_object = "Ultimate Ultra Extreme Super Power Invincible Shield";     shield[9].Des = "VIT + 0\nDEF + 0\nMAX HP + 0";    shield[9].shield_stat[0] = 20;shield[9].shield_stat[1]= 25;shield[9].shield_stat[2]= 200;

    accessory[0].name = "The balance";   accessory[0].price = 10;    accessory[0].Des = "AGI + 2\nATK + 0\nLUK + 2\nSTR + 2\nVIT + 2"; accessory[0].extra_agi = 2;accessory[0].extra_atk = 0;accessory[0].extra_luck = 2;accessory[0].extra_str = 2;accessory[0].extra_vit = 2;
    accessory[1].name = "Golden x";       accessory[1].price = 10;   accessory[1].Des = "AGI + 2\nATK + 0\nLUK + 2\nSTR + 2\nVIT + 1"; accessory[1].extra_agi = 0;accessory[1].extra_atk = 5;accessory[1].extra_luck = 3;accessory[1].extra_str = 2;accessory[1].extra_vit = 1;
    accessory[2].name = "Warrior necklace"; accessory[2].price = 10; accessory[2].Des = "AGI + 2\nATK + 0\nLUK + 2\nSTR + 2\nVIT + 5"; accessory[2].extra_agi = 0;accessory[2].extra_atk = 10;accessory[2].extra_luck = 0;accessory[2].extra_str = 5;accessory[2].extra_vit = 5;
    accessory[3].name = "Ninja necklace";  accessory[3].price = 10; accessory[3].Des = "AGI + 2\nATK + 0\nLUK + 2\nSTR + 2\nVIT + 0"; accessory[3].extra_agi = 7;accessory[3].extra_atk = 10;accessory[3].extra_luck = 3;accessory[3].extra_str = -4;accessory[3].extra_vit = 0;
    accessory[4].name = "LUCKY";          accessory[4].price = 10;  accessory[4].Des = "AGI + 2\nATK + 0\nLUK + 2\nSTR + 2\nVIT + 1"; accessory[4].extra_agi = 1;accessory[4].extra_atk = 0;accessory[4].extra_luck = 10;accessory[4].extra_str = 0;accessory[4].extra_vit = 1;
    accessory[5].name = "Power stone";     accessory[5].price = 10;  accessory[5].Des = "AGI + 2\nATK + 0\nLUK + 2\nSTR + 2\nVIT + 7"; accessory[5].extra_agi = -5;accessory[5].extra_atk = 14;accessory[5].extra_luck = -2;accessory[5].extra_str = 5;accessory[5].extra_vit = 7;
    accessory[6].name = "Mystery";        accessory[6].price = 10;   accessory[6].Des = "AGI + 2\nATK + 0\nLUK + 2\nSTR + 2\nVIT + 6"; accessory[6].extra_agi = 6;accessory[6].extra_atk =6;accessory[6].extra_luck = 6;accessory[6].extra_str = 6;accessory[6].extra_vit = 6;
    accessory[7].name = "Blood crystal";                               accessory[7].Des = "AGI + 2\nATK + 0\nLUK + 2\nSTR + 2\nVIT + 0"; accessory[7].extra_agi = 10;accessory[7].extra_atk = - 5;accessory[7].extra_luck = 5;accessory[7].extra_str = -2;accessory[7].extra_vit = 0;
    accessory[8].name = "Darkness totem";                            accessory[8].Des = "AGI + 7\nATK + 15\nLUK + 2\nSTR + 2\nVIT + 1"; accessory[8].extra_agi = 7;accessory[8].extra_atk = 15;accessory[8].extra_luck = 7;accessory[8].extra_str = 7;accessory[8].extra_vit = 1;
    accessory[9].name = "WHOSYOURDADDY";                             accessory[9].Des = "AGI + 17\nATK + 20\nLUK + 15\nSTR + 10\nVIT + 10";accessory[9].extra_agi = 17;accessory[9].extra_atk = 20;accessory[9].extra_luck = 15;accessory[9].extra_str = 10;accessory[9].extra_vit = 10;
}

void Game::initMob(){
	characters[0].clas="Berserker";characters[0].stat[0]=15;characters[0].stat[1]=5;characters[0].stat[2]=3;
	characters[0].stat[3]=7;characters[0].stat[4]=5;characters[0].stat[5]=75;
	characters[1].clas="HolyKnight";characters[1].stat[0]=8;characters[1].stat[1]=7;characters[1].stat[2]=3;
	characters[1].stat[3]=13;characters[1].stat[4]=5;characters[1].stat[5]=40;
	characters[2].clas="Thief";characters[2].stat[0]=5;characters[2].stat[1]=10;characters[2].stat[2]=14;
	characters[2].stat[3]=5;characters[2].stat[4]=5;characters[2].stat[5]=25;
	characters[3].clas="B";characters[3].stat[0]=7;characters[3].stat[1]=3;characters[3].stat[2]=10;
	characters[3].stat[3]=10;characters[3].stat[4]=5;characters[3].stat[5]=35;
	characters[4].clas="Merchant";characters[4].stat[0]=10;characters[4].stat[1]=10;characters[4].stat[2]=3;
	characters[4].stat[3]=7;characters[4].stat[4]=5;characters[4].stat[5]=50;
	characters[5].clas="B2";characters[5].stat[0]=6;characters[5].stat[1]=6;characters[5].stat[2]=6;
	characters[5].stat[3]=6;characters[5].stat[4]=6;characters[5].stat[5]=30;

	//atk hp agi luk def
    monster[0].name = "m1";monster[0].stat[0]=3;monster[0].stat[1]=4;monster[0].stat[2]=3;monster[0].stat[3]=40;monster[0].stat[4]=15;monster[0].stat[5]=150;monster[0].stat[6]=6;monster[0].lv=5;
	monster[1].name = "m1";monster[1].stat[0]=6;monster[1].stat[1]=12;monster[1].stat[2]=6;monster[1].stat[3]=80;monster[1].stat[4]=300;monster[1].stat[5]=1000;monster[1].stat[6]=12;monster[1].lv=15;
	monster[2].name = "m1";monster[2].stat[0]=10;monster[2].stat[1]=22;monster[2].stat[2]=18;monster[2].stat[3]=120;monster[2].stat[4]=500;monster[2].stat[5]=1200;monster[2].stat[6]=18;monster[2].lv=20;
	monster[3].name = "m1";monster[3].stat[0]=16;monster[3].stat[1]=27;monster[3].stat[2]=22;monster[3].stat[3]=300;monster[3].stat[4]=80;monster[3].stat[5]=3000;monster[3].stat[6]=22;monster[3].lv=30;
	monster[4].name = "m1";monster[4].stat[0]=20;monster[4].stat[1]=29;monster[4].stat[2]=25;monster[4].stat[3]=350;monster[4].stat[4]=100;monster[4].stat[5]=3500;monster[4].stat[6]=24;monster[4].lv=35;
	monster[5].name = "m1";monster[5].stat[0]=24;monster[5].stat[1]=31;monster[5].stat[2]=27;monster[5].stat[3]=400;monster[5].stat[4]=120;monster[5].stat[5]=4000;monster[5].stat[6]=26;monster[5].lv=40;
	monster[0].name = "m1";monster[0].maxhp = 400;monster[1].maxhp = 800;monster[2].maxhp = 1200;monster[3].maxhp = 3000;monster[4].maxhp = 3500;monster[5].maxhp=4000;
}

void Game::useThisItem(bool high_grade){
    int x = rand()%100+1;
    if(high_grade == false){
        if(x > 30){
            ask(0,1);
        }else if(x > 50){
            ask(0,2);
        }else if(x > 60){
            ask(0,3);
        }else if(x > 70){
            ask(0,4);
        }else if(x > 80){
            ask(0,5);
        }else if(x > 90){
            ask(0,6);
        }else if(x > 95){
            ask(0,7);
        }
    }else{
        if(x > 50){
            ask(0,8);
        }else if(x > 80){
            ask(0,9);
        }else{
            ask(0,10);
        }
    }
}
int Game::Get_Heal(Player & that_player){
    int x;
    if(that_player.character_number == 1){
        x = (rand()%20)+1;
        if(that_player.hp + x >  that_player.HpMax()){
            return that_player.HpMax() - that_player.hp;
        }else{
            return x;
        }
    }else{
        x = (rand()%10)+1;
        if(that_player.hp + x > that_player.HpMax()){
            return that_player.HpMax() - that_player.hp;
        }else{
            return x;
        }
    }
}

void Game::upstat(){
	//0 lv 1nowexp 2needexp
            if(player[now_player].level<30){
                if(player[now_player].exp>=(needexp[player[now_player].level-1])){
				player[now_player].level++;
				player[now_player].exp=player[now_player].exp-(needexp[player[now_player].level-1]);
				needexp[player[now_player].level-1]=(player[now_player].level-1)*50+100;
				defhp=player[now_player].HpMax();
                x++;
			}
        }
        else{ player[now_player].exp=1550;

        }
            if(player[now_player].exp<0){
				if(player[now_player].level==1){
					player[now_player].exp=0;
					player[now_player].hp=player[now_player].HpMax()/2;
				}
            else{player[now_player].level--;
				player[now_player].exp+=(needexp[player[now_player].level-1]);
				player[now_player].hp=player[now_player].HpMax()/2;
				x--;
				}
			}
        if(x>=1){
	 	if(player[now_player].character_number==0){
			player[now_player].std_str+=3;
			player[now_player].std_vit+=2;
			player[now_player].std_agi+=2;
			player[now_player].std_luk+=1;
			player[now_player].std_atk+=15;
            player[now_player].hp+=(player[now_player].HpMax()-defhp);

		}
	else if(player[now_player].character_number==1){
			player[now_player].std_str+=2;
			player[now_player].std_vit+=3;
			player[now_player].std_agi+=2;
			player[now_player].std_luk+=1;
			player[now_player].std_atk+=10;
            player[now_player].hp+=(player[now_player].HpMax()-defhp);
		}
	else if(player[now_player].character_number==2){
			player[now_player].std_str+=2;
			player[now_player].std_vit+=1;
			player[now_player].std_agi+=3;
			player[now_player].std_luk+=2;
			player[now_player].std_atk+=10;
            player[now_player].hp+=(player[now_player].HpMax()-defhp);
		}
	else if(player[now_player].character_number==3){
			player[now_player].std_str+=1;
			player[now_player].std_vit+=3;
			player[now_player].std_agi+=3;
			player[now_player].std_luk+=1;
			player[now_player].std_atk+=5;
            player[now_player].hp+=(player[now_player].HpMax()-defhp);
		}
	else if(player[now_player].character_number==4){
			player[now_player].std_str+=3;
			player[now_player].std_vit+=1;
			player[now_player].std_agi+=1;
			player[now_player].std_luk+=3;
			player[now_player].std_atk+=15;
            player[now_player].hp+=(player[now_player].HpMax()-defhp);
		}
	else if(player[now_player].character_number==5){
			player[now_player].std_str+=2;
			player[now_player].std_vit+=2;
			player[now_player].std_agi+=2;
			player[now_player].std_luk+=2;
			player[now_player].std_atk+=10;
            player[now_player].hp+=(player[now_player].HpMax()-defhp);
		}
		x=x-1;
	}
		if(x<0){
	 	if(player[now_player].character_number==0){
			player[now_player].std_str-=3;
			player[now_player].std_vit-=2;
			player[now_player].std_agi-=2;
			player[now_player].std_luk-=1;
			player[now_player].std_atk-=15;
		}
        else if(player[now_player].character_number==1){
			player[now_player].std_str-=2;
			player[now_player].std_vit-=3;
			player[now_player].std_agi-=2;
			player[now_player].std_luk-=1;
			player[now_player].std_atk-=10;
		}
	else if(player[now_player].character_number==2){
			player[now_player].std_str-=2;
			player[now_player].std_vit-=1;
			player[now_player].std_agi-=3;
			player[now_player].std_luk-=2;
			player[now_player].std_atk-=10;
		}
	else if(player[now_player].character_number==3){
			player[now_player].std_str-=1;
			player[now_player].std_vit-=3;
			player[now_player].std_agi-=3;
			player[now_player].std_luk-=1;
			player[now_player].std_atk-=5;
		}
	else if(player[now_player].character_number==4){
			player[now_player].std_str-=3;
			player[now_player].std_vit-=1;
			player[now_player].std_agi-=1;
			player[now_player].std_luk-=3;
			player[now_player].std_atk-=15;
		}
	else if(player[now_player].character_number==5){
			player[now_player].std_str-=2;
			player[now_player].std_vit-=2;
			player[now_player].std_agi-=2;
			player[now_player].std_luk-=2;
			player[now_player].std_atk-=10;
		}
		x=x+1;
	}
}
void Game::get_item_boss(){
    int b = player[now_player].getLuk()*0.3;
    int a = rand()%100+1;
    int c = a+b;
    int d;
    int ea;
    string e[4] = {"sword","potion","shield","accessory"};
    int i = rand()%3;
    //int command_item_boss;
    int potion_random = rand()%2;

    if(potion_random == 0){
         ea = rand()%3+1;
    }
    if(potion_random == 1){
         ea = rand()%6+1;
    }


    if(c >95){     //5
        d = 9;
        i = 3;
    }
    if(c > 85 && c <= 95){  //10
        d = 8;
        i =3;
    }
    if(c > 70 && c <= 85){ //15
        d = 7;
        i = 2;    }
    if(c > 50 && c <= 70){ //20
        d = rand()%3+4;
        i = 2;
    }
    if(c > 0 && c <= 50){ // 50
        d = rand()%3+1;
        i = 0;
    }
    if(e[i] == "sword"){
        ask(0,d,false);
    }
    if(e[i] == "potion"){
        cout << "You get a " << potion[potion_random].name_object << "  " << ea << " EA"<< endl;
        if(potion_random == 0){
        player[now_player].green_potion += ea;
        }
        if(potion_random == 1){
        player[now_player].red_potion += ea;
        }
    }
    if(e[i] == "shield"){
      ask(1,d,false);
    }
    if(e[i] == "accessory"){
      ask(2,d,false);
    }
}

#endif
