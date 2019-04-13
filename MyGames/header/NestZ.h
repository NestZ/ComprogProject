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

struct itemStat{
    int sword_stat[3];
    int potion_effect;
    int shield_stat[3];
    string name_object;
    string Des;
};
itemStat sword[10];
itemStat shield[10];
itemStat potion[2];

struct accessory{
    string name;
    string Des;
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
        int now_path;
        int hp;
        int weaponIndex;
        int shieldIndex;
        int accessoryIndex;
        int star;
        int money;
        int std_str = 20;
        int std_vit = 20;
        int std_agi = 20;
        int std_luk = 20;
        int std_atk = 20;
        int std_def = 20;
        int red_potion;
        int green_potion;
        int moveNum;
        double pos_x;
        double pos_y;
        int now_player_path;
        bool isRandom = false;
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
    money = 0;
    red_potion = 10;
    green_potion = 10;
    star = 0;
    weaponIndex = 0;
    shieldIndex = -1;
    accessoryIndex = -1;
    hp = 10;
    //hp = HpMax();
}

int Player::getAtk(){
    return std_atk + getStr()/2 + (accessoryIndex > -1 ? accessory[accessoryIndex].extra_atk:0);
}
int Player::getDef(){
    return std_def + getVit() + (shieldIndex > -1 ? shield[shieldIndex].shield_stat[1]:0);
}
int Player::getAgi(){
    return std_agi + (accessoryIndex > -1 ? accessory[accessoryIndex].extra_agi:0) + sword[weaponIndex].sword_stat[1];
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
    return getVit()*5;
}
int now_player = 0;
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
        //Playing
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
        void setItemStat();
        void get_item_boss();
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
        Text cinText;
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
        bool randomStart;
        bool isBagOpen;
        bool isDesOpen;
        Font cordiaFont;
        vector<int> expMax;
        vector<int> diceTemp;
        int startExp;
        int UIFontSize;
        Texture mapTexture;
        Sprite mapSprite;
        Texture miniMenuT;
        Sprite miniMenuS;
        View camera;
        bool isMenuOpen;
        Text miniMenuText[3];
        int miniMenuFontSize;
        int arrIndex[3] = {-1,0,1};
        int turn;
        Player *player;
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
    animationSpeed = 0.3f;
    startExp = 100;
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
                if(index != 2 && setting[index] < 25){
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
                        break;
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
}

void Game::drawInsertName(){
    //resetIPN();
    setInsertNameText();
    this->gameWindow->draw(insertNameBGSprite);
    this->gameWindow->draw(backButtonSprite);
    updateBackButtonIPN();
    this->gameWindow->draw(cinText);
    this->gameWindow->draw(InsertedName);
    this->gameWindow->draw(mouseIconSprite);
}

void Game::updateInsertNameTextBoxEvent(Event InsertNameEvent){
    if(InsertNameEvent.type == Event::TextEntered){
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
        cout << "player " << playerNamingIndex + 1 << " name's : " << playerName[playerNamingIndex] << "\n";
        if(playerNamingIndex < players - 1){
            playerNamingIndex++;
            setCinText(cinText,playerNamingIndex);
        }
        else {
            randomPick(playerName);
            state.push(ChooseCharacters);
        }
    }
    else if(!checkUsedName(name))cout << "kuy" << "\n";
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
    setCinText(cinText,playerNamingIndex);
    while(!playerName.empty()){
        playerName.pop_back();
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
    this->gameWindow->draw(chooseCharacterBGSprite);
    this->gameWindow->draw(backButtonSprite);
    updateBackButtonCC();
    updateChoosingState();
    updateChoosed();
    this->gameWindow->draw(mainPlayerNameText);
    for(int i = 0;i < 6;i++){
        setCharacterIcon(charSprite[i],i);
        this->gameWindow->draw(charSprite[i]);
    }
    this->gameWindow->draw(mouseIconSprite);
}

void Game::setCharacterIcon(Sprite &sprite, int index){
    sprite.setOrigin(getObjWidth(sprite) / 2.0,getObjHeight(sprite) / 2.0);
    sprite.setPosition((index + 1) * (windowWidth / 7),windowMidHeight());
}

void Game::randomPick(vector<string> &playerName){
    for(int i = 0;i < rand() % 100 + 1;i++){
        randomIndexST = rand() % players;

        do{
            randomIndexND = rand() % players;
        }while(randomIndexND == randomIndexST);

        Swap(playerName[randomIndexST],playerName[randomIndexND]);
    }
    for(unsigned int i = 0;i < playerName.size();i++)cout << playerName[i] << "\n";
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
                else state.push(Playing);
            }
        }
        else charSprite[i].setScale(1,1);
        if(choosed[i] == true)charSprite[i].setColor(Color(128,128,128,255));
        else charSprite[i].setColor(Color(255,255,255,255));
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
    expMax.push_back(startExp);
    while(expMax.size() != 29){
        expMax.push_back(expMax.back() * 1.2);
    }
    expMax.push_back(expMax.back());
    setItemStat();
    mapTexture.loadFromFile("img/Map.jpg");
    mapSprite.setTexture(mapTexture);
    mapSprite.setPosition(0,0);
    miniMenuT.loadFromFile("img/miniMenuBG.png");
    miniMenuS.setTexture(miniMenuT);
    miniMenuS.setOrigin(getObjWidth(miniMenuS) / 2,getObjHeight(miniMenuS) / 2);
    miniMenuS.setScale(0.9,0.7);
    miniMenuS.setColor(Color(255,255,255,128));
    camera.setCenter(Vector2f(300,300));
    camera.setSize(Vector2f(300,300));
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
        UI_starS[i].setScale(0.35,0.35);
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
    UI_name.setPosition(UI_charFaceS.getPosition().x,UI_charFaceS.getPosition().y + 110);
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
    UI_swordS.setScale(0.65,0.65);
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
    UI_shieldS.setScale(0.65,0.65);
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
    UI_accS.setScale(0.65,0.65);
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
}

void Game::drawPlaying(){
    updateLevel();
    updateTurn();
    this->gameWindow->setView(camera);
    this->gameWindow->draw(mapSprite);
    this->gameWindow->setView(this->gameWindow->RenderTarget::getDefaultView());
    drawUI();
    updateEscape();
    updatePlayingState();
    if(isDesOpen){
            this->gameWindow->draw(UI_playerDesBGS);
            this->gameWindow->draw(UI_playerDesCharS);
            this->gameWindow->draw(UI_playerNameDes);
            this->gameWindow->draw(UI_statDes);
            this->gameWindow->draw(UI_statDesR);
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
        updateView();
    }

    this->gameWindow->draw(mouseIconSprite);
}

void Game::updatePlayingState(){
    if(player[now_player].isRandom == false){
        if(!randomStart)diceState();
        else if(randomStart){
            randomDice();
            this->gameWindow->draw(UI_diceValue);
        }
    }
    else if(player[now_player].isRandom == true){
        player[now_player].moveNum = diceTemp.back();
        while(diceTemp.size() != 0)diceTemp.pop_back();
        randomStart = false;
        player[now_player].isRandom = false;
        turn++;
    }
}

void Game::diceState(){
        this->gameWindow->draw(UI_diceS);
        if(UI_diceS.getGlobalBounds().contains(mousePos) && !isDesOpen && !isMenuOpen){
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
        diceNum = rand() % 6 + 1;
        UI_diceValue.setString(to_string(diceNum));
        this->gameWindow->draw(UI_diceValue);
        diceTemp.push_back(diceNum);
        cout << now_player << " " << diceTemp.size() << "\n";
        }
    if(diceTemp.size() == 20)player[now_player].isRandom = true;
}

void Game::updateLevel(){
    if(player[now_player].exp >= expMax[player[now_player].level - 1] && player[now_player].level < 29){
        player[now_player].exp -= expMax[player[now_player].level - 1];
        player[now_player].level++;
    }
    else if(player[now_player].level == 29 && player[now_player].exp >= expMax[player[now_player].level - 1]){
        player[now_player].exp = expMax.back();
        player[now_player].level++;
    }
    else if(player[now_player].level == 30){
        player[now_player].exp = expMax.back();
    }
}

void Game::updateView(){
    if(Mouse::getPosition(*this->gameWindow).x > windowWidth - 3){
        camera.move(horizontalScrollSpeed,0);
    }
    else if(Mouse::getPosition(*this->gameWindow).x < 3){
        camera.move(-horizontalScrollSpeed,0);
    }
    if(Mouse::getPosition(*this->gameWindow).y > windowHeight - 3){
        camera.move(0,verticalScrollSpeed);
    }
    else if(Mouse::getPosition(*this->gameWindow).y < 3){
        camera.move(0,-verticalScrollSpeed);
    }
}

void Game::updateEscape(){
    if(checkEscape()){
        if(isMenuOpen)isMenuOpen = false;
        else if(!isMenuOpen && !isDesOpen)isMenuOpen = true;
        else if(!isMenuOpen && isDesOpen)isDesOpen = false;
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
    UI_diceValue.setOrigin(getObjWidth(UI_diceValue) / 2,getObjHeight(UI_diceValue) / 2);
    UI_diceValue.setPosition(windowMidWidth(),windowMidHeight());
    UI_name.setString(playerName[now_player]);
    UI_name.setOrigin(getObjWidth(UI_name) / 2,getObjHeight(UI_name) / 2);
    UI_charFaceS.setTexture(UI_charFaceT[player[now_player].character_number]);
    UI_charFaceS.setOrigin(getObjWidth(UI_charFaceS) / 2,getObjHeight(UI_charFaceS) / 2);
    UI_expBarS.setScale((double)player[now_player].exp / expMax[player[now_player].level - 1],1);
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
    if(player[now_player].weaponIndex != -1){
        UI_swordS.setTexture(UI_swordT[player[now_player].weaponIndex]);
        UI_swordS.setOrigin(getObjWidth(UI_swordS) / 2,getObjHeight(UI_swordS) / 2);
        UI_swordS.setPosition(UI_HpSS.getPosition().x - 136,UI_HpSS.getPosition().y);
    }
    if(player[now_player].shieldIndex != -1){
        UI_shieldS.setTexture(UI_shieldT[player[now_player].shieldIndex]);
        UI_shieldS.setOrigin(getObjWidth(UI_shieldS) / 2,getObjHeight(UI_shieldS) / 2);
        UI_shieldS.setPosition(UI_HpSS.getPosition().x - 68,UI_HpSS.getPosition().y);
    }
    if(player[now_player].accessoryIndex != -1){
        UI_accS.setTexture(UI_accT[player[now_player].accessoryIndex]);
        UI_accS.setOrigin(getObjWidth(UI_accS) / 2,getObjHeight(UI_accS) / 2);
        UI_accS.setPosition(UI_HpSS.getPosition().x + 136,UI_HpSS.getPosition().y);
    }
    if(isDesOpen){
        UI_playerDesCharS.setTexture(charTexture[player[now_player].character_number]);
        UI_playerDesCharS.setOrigin(getObjWidth(UI_playerDesCharS) / 2,getObjHeight(UI_playerDesCharS) / 2);
        UI_playerDesCharS.setPosition(UI_playerDesBGS.getPosition().x,UI_playerDesBGS.getPosition().y - 160);
        UI_playerNameDes.setString(playerName[now_player]);
        UI_playerNameDes.setOrigin(getObjWidth(UI_playerNameDes) / 2,getObjHeight(UI_playerNameDes) / 2);
        UI_playerNameDes.setPosition(UI_playerDesBGS.getPosition().x + 5,UI_playerDesBGS.getPosition().y - 70);
        UI_statDes.setString("Level  :     " + to_string(player[now_player].level) + '\n' +
                             "Class  :     " + '\n' +
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
        this->gameWindow->draw(UI_shieldS);
        this->gameWindow->draw(UI_accS);
    }
    if(!isMenuOpen)updateUI();
}

void Game::updateUI(){
    UI_hpValue.setString(to_string(player[now_player].hp) + "/" + to_string(player[now_player].HpMax()));
    UI_expValue.setString(to_string(player[now_player].exp) + "/" + to_string(expMax[player[now_player].level - 1]));
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
            else isDesOpen = true;
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
            if(player[now_player].red_potion > 0){
                player[now_player].red_potion--;
                usePotion(potion[0].potion_effect);
            }
        }
    }
    else UI_HpSS.setScale(0.65,0.65);
    if(UI_HpLS.getGlobalBounds().contains(mousePos)){
        if(player[now_player].green_potion > 0)UI_HpLS.setScale(0.7,0.7);
        if(checkMouseClick() && player[now_player].hp < player[now_player].HpMax()){
            if(player[now_player].green_potion > 0){
                player[now_player].green_potion--;
                usePotion(potion[1].potion_effect);
            }
        }
    }
    else UI_HpLS.setScale(0.65,0.65);
    if(isBagOpen){
        if(UI_swordS.getGlobalBounds().contains(mousePos) && player[now_player].weaponIndex != -1){
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
    sword[0].name_object = "Fist";               sword[0].Des = "STR + 0\nAGI + 0\nLUK + 0";       sword[0].sword_stat[0] = 0;sword[0].sword_stat[1] = 0;sword[0].sword_stat[2] = 0;
    sword[1].name_object = "Durandal";           sword[1].Des = "STR + 0\nAGI + 0\nLUK + 0";       sword[1].sword_stat[0] = 2;sword[1].sword_stat[1] = 0;sword[1].sword_stat[2] = 1;
    sword[2].name_object = "Muramasas";          sword[2].Des = "STR + 0\nAGI + 0\nLUK + 0";       sword[2].sword_stat[0] = 3;sword[2].sword_stat[1] = 2;sword[2].sword_stat[2] = 2;
    sword[3].name_object = "Murasame";           sword[3].Des = "STR + 0\nAGI + 0\nLUK + 0";       sword[3].sword_stat[0] = 4;sword[3].sword_stat[1] = 2;sword[3].sword_stat[2] = 1;
    sword[4].name_object = "Masamune";           sword[4].Des = "STR + 0\nAGI + 0\nLUK + 0";       sword[4].sword_stat[0] = 3;sword[4].sword_stat[1] = 2;sword[4].sword_stat[2] = 4;
    sword[5].name_object = "Shusui";             sword[5].Des = "STR + 0\nAGI + 0\nLUK + 0";       sword[5].sword_stat[0] = 6;sword[5].sword_stat[1] = 3;sword[5].sword_stat[2] = 3;
    sword[6].name_object = "Yubashiri";          sword[6].Des = "STR + 0\nAGI + 0\nLUK + 0";       sword[6].sword_stat[0] = 5;sword[6].sword_stat[1] = 4;sword[6].sword_stat[2] = 4;
    sword[7].name_object = "Kitetsu Sandai";     sword[7].Des = "STR + 0\nAGI + 0\nLUK + 0";       sword[7].sword_stat[0] = 9;sword[7].sword_stat[1] = 2;sword[7].sword_stat[2] = 4;
    sword[8].name_object = "Wado Ichimonji";     sword[8].Des = "STR + 0\nAGI + 0\nLUK + 0";       sword[8].sword_stat[0] = 10;sword[8].sword_stat[1] = 3;sword[8].sword_stat[2] = 5;
    sword[9].name_object = "Excalibur";          sword[9].Des = "STR + 0\nAGI + 0\nLUK + 0";       sword[9].sword_stat[0] = 20;sword[9].sword_stat[1] = -5;sword[9].sword_stat[2] = 3;

    potion[0].name_object ="Potion S" ;          potion[0].Des = "HP + 10";                        potion[0].potion_effect = 10;
    potion[1].name_object ="Potion L";           potion[1].Des = "HP + 30";                        potion[1].potion_effect = 30;


    shield[0].name_object = "Hand";               shield[0].Des = "VIT + 0\nDEF + 0\nMAX HP + 0";  shield[0].shield_stat[0] = 0;shield[0].shield_stat[1]= 0;shield[0].shield_stat[2]= 0;
    shield[1].name_object = "Aegis Shield ";      shield[1].Des = "VIT + 0\nDEF + 0\nMAX HP + 0";  shield[1].shield_stat[0] = 2;shield[1].shield_stat[1]= 3;shield[1].shield_stat[2]= 30;
    shield[2].name_object = "Saka Shield";        shield[2].Des = "VIT + 0\nDEF + 0\nMAX HP + 0";  shield[2].shield_stat[0] = 3;shield[2].shield_stat[1]= 0;shield[2].shield_stat[2]= 50;
    shield[3].name_object = "Arachiki Shield";    shield[3].Des = "VIT + 0\nDEF + 0\nMAX HP + 0";  shield[3].shield_stat[0] = 4;shield[3].shield_stat[1]= 4;shield[3].shield_stat[2]= 40;
    shield[4].name_object = "Demose Shield";      shield[4].Des = "VIT + 0\nDEF + 0\nMAX HP + 0";  shield[4].shield_stat[0] = 5;shield[4].shield_stat[1]= 2;shield[4].shield_stat[2]= 2;
    shield[5].name_object = "G.O.T Shield ";      shield[5].Des = "VIT + 0\nDEF + 0\nMAX HP + 0";  shield[5].shield_stat[0] = 2;shield[5].shield_stat[1]= 7;shield[5].shield_stat[2]= 20;
    shield[6].name_object = "Power Shield ";      shield[6].Des = "VIT + 0\nDEF + 0\nMAX HP + 0";  shield[6].shield_stat[0] = 7;shield[6].shield_stat[1]= 8;shield[6].shield_stat[2]= 50;
    shield[7].name_object = "DK Shield ";         shield[7].Des = "VIT + 0\nDEF + 0\nMAX HP + 0";  shield[7].shield_stat[0] = 5;shield[7].shield_stat[1]= 10;shield[7].shield_stat[2]= 60;
    shield[8].name_object = "Invincible Shield "; shield[8].Des = "VIT + 0\nDEF + 0\nMAX HP + 0";  shield[8].shield_stat[0] = 3;shield[8].shield_stat[1]= 15;shield[8].shield_stat[2]= 100;
    shield[9].name_object = "Ultimate Ultra Extreme Super Power Invincible Shield";     shield[9].Des = "VIT + 0\nDEF + 0\nMAX HP + 0";    shield[9].shield_stat[0] = 20;shield[9].shield_stat[1]= 25;shield[9].shield_stat[2]= 200;


    accessory[0].name = "The balance";     accessory[0].Des = "AGI + 2\nATK + 0\nLUK + 2\nSTR + 2\nVIT + 2"; accessory[0].extra_agi = 2;accessory[0].extra_atk = 0;accessory[0].extra_luck = 2;accessory[0].extra_str = 2;accessory[0].extra_vit = 2;
    accessory[1].name = "Golden x";        accessory[0].Des = "AGI + 2\nATK + 0\nLUK + 2\nSTR + 2\nVIT + 1"; accessory[1].extra_agi = 0;accessory[1].extra_atk = 5;accessory[1].extra_luck = 3;accessory[1].extra_str = 2;accessory[1].extra_vit = 1;
    accessory[2].name = "Warrior necklace";accessory[0].Des = "AGI + 2\nATK + 0\nLUK + 2\nSTR + 2\nVIT + 5"; accessory[2].extra_agi = 0;accessory[2].extra_atk = 10;accessory[2].extra_luck = 0;accessory[2].extra_str = 5;accessory[2].extra_vit = 5;
    accessory[3].name = "Ninja necklace";  accessory[0].Des = "AGI + 2\nATK + 0\nLUK + 2\nSTR + 2\nVIT - 2"; accessory[3].extra_agi = 7;accessory[3].extra_atk = 10;accessory[3].extra_luck = 3;accessory[3].extra_str = -2;accessory[3].extra_vit = -2;
    accessory[4].name = "LUCKY";           accessory[0].Des = "AGI + 2\nATK + 0\nLUK + 2\nSTR + 2\nVIT + 1"; accessory[4].extra_agi = 1;accessory[4].extra_atk = 0;accessory[4].extra_luck = 10;accessory[4].extra_str = 0;accessory[4].extra_vit = 1;
    accessory[5].name = "Power stone";     accessory[0].Des = "AGI + 2\nATK + 0\nLUK + 2\nSTR + 2\nVIT + 7"; accessory[5].extra_agi = -5;accessory[5].extra_atk = 14;accessory[5].extra_luck = -2;accessory[5].extra_str = 5;accessory[5].extra_vit = 7;
    accessory[6].name = "Mystery";         accessory[0].Des = "AGI + 2\nATK + 0\nLUK + 2\nSTR + 2\nVIT + 6"; accessory[6].extra_agi = 6;accessory[6].extra_atk =6;accessory[6].extra_luck = 6;accessory[6].extra_str = 6;accessory[6].extra_vit = 6;
    accessory[7].name = "Blood crystal";   accessory[0].Des = "AGI + 2\nATK + 0\nLUK + 2\nSTR + 2\nVIT - 15"; accessory[7].extra_agi = 10;accessory[7].extra_atk = 0;accessory[7].extra_luck = 5;accessory[7].extra_str = -2;accessory[7].extra_vit = -15;
    accessory[8].name = "Darkness totem";  accessory[0].Des = "AGI + 7\nATK + 15\nLUK + 2\nSTR + 2\nVIT + 1"; accessory[8].extra_agi = 7;accessory[8].extra_atk = 15;accessory[8].extra_luck = 7;accessory[8].extra_str = 7;accessory[8].extra_vit = 1;
    accessory[9].name = "WHOSYOURDADDY";accessory[0].Des = "AGI + 17\nATK + 20\nLUK + 15\nSTR + 10\nVIT + 10";accessory[9].extra_agi = 17;accessory[9].extra_atk = 20;accessory[9].extra_luck = 15;accessory[9].extra_str = 10;accessory[9].extra_vit = 10;
}

void Game::get_item_boss(){
    int b = player[now_player].getLuk()*0.7;
    int a = rand()%100+1;
    int c = a+b;
    int d;
    int ea;
    string e[3] = {"sword","potion","shield"};
    int i = rand()%3;
    int command_item_boss;
    int potion_random = rand()%2;

    if(potion_random == 0){
         ea = rand()%3+1;
    }
    if(potion_random == 1){
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
        if(command_item_boss == 1){
        player[now_player].weaponIndex = d;
        }
        else player[now_player].weaponIndex = player[now_player].weaponIndex;
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
        cout << "You get the " << shield[d].name_object << "Stat : VIT = " << shield[d].shield_stat[0] << "  DEF = " << shield[d].shield_stat[1] << "  HP = " << shield[d].shield_stat[2] << endl;
        cout << "Choose (1):OK (2):Cancel " ;
        cin >> command_item_boss;
        if(command_item_boss == 1){
        player[now_player].shieldIndex = d;
        }
        else player[now_player].shieldIndex = player[now_player].shieldIndex;
    }
}
#endif
