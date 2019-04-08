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
};
itemStat sword[10];
itemStat shield[10];
itemStat potion[2];

struct accessoryStat{
    int extra_vit = 0;
    int extra_atk = 0;
    int extra_luck = 0;
    int extra_str = 0;
    int extra_agi = 0;
}accessoryStat[10];

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
        int std_str;
        int std_vit;
        int std_agi;
        int std_luk;
        int std_atk;
        int std_def;
        int red_potion;
        int green_potion;
        double pos_x;
        double pos_y;
        int now_player_path;
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
    red_potion = 0;
    green_potion = 0;
    star = 0;
    weaponIndex = 0;
    shieldIndex = 0;
    accessoryIndex = 0;
    hp = HpMax();
}

int Player::getAtk(){
    return std_atk + getStr()/2 + accessoryStat[accessoryIndex].extra_atk;
}
int Player::getDef(){
    return std_def + getVit() + shield[shieldIndex].shield_stat[1];
}
int Player::getAgi(){
    return std_agi + accessoryStat[accessoryIndex].extra_agi + sword[weaponIndex].sword_stat[1];
}
int Player::getStr(){
    return  std_str + accessoryStat[accessoryIndex].extra_str + sword[weaponIndex].sword_stat[0];
}
int Player::getLuk(){
    return std_luk + accessoryStat[accessoryIndex].extra_luck + sword[weaponIndex].sword_stat[2];
}
int Player::getVit(){
    return std_vit + accessoryStat[accessoryIndex].extra_vit + shield[shieldIndex].shield_stat[0];
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
        enum States {Menu, ChoosePlayers, ChooseCharacters, Setting, InsertName, Playing};
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
        //Playing
        void drawPlaying();
        void initPlayingVariables();
        void updateView();
        void updateMiniMenu();
        void updateMiniMenuClick();
        void updateUI();
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
        vector<int> expMax;
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
        Player *player;
        Text UI_name;
        Text UI_hpText;
        Text UI_level;
        Text UI_class;
        Text UI_expText;
        Text UI_hpValue;
        Text UI_expValue;
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
    initPlayingVariables();
    initWindowVariables();
    initSettingVariables();
    initGlobalVariables();
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
    menuFont.loadFromFile("font/ka1.TTF");
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
    if(insertedChar == 13 && name.size() > 0){
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
    startExp = 100;
    expMax.push_back(startExp);
    while(expMax.size() != 29){
        expMax.push_back(expMax.back() * 1.5);
    }
    isMenuOpen = false;
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
    UI_hpBarS.setPosition(360,85);
    UI_hpText.setString("HP");
    UI_hpText.setFillColor(Color::Black);
    UI_hpText.setOutlineColor(Color::White);
    UI_hpText.setOutlineThickness(3.5);
    UI_hpText.setFont(menuFont);
    UI_hpText.setCharacterSize(UIFontSize);
    UI_hpValue.setFillColor(Color::Black);
    UI_hpValue.setOutlineColor(Color::White);
    UI_hpValue.setOutlineThickness(2);
    UI_hpValue.setFont(menuFont);
    UI_hpValue.setCharacterSize(UIFontSize - 15);
    UI_expBorderT.loadFromFile("img/HpBorder.png");
    UI_expBorderS.setTexture(UI_expBorderT);
    UI_expBorderS.setPosition(UI_hpBorderS.getPosition().x,UI_hpBorderS.getPosition().y + 55);
    UI_maxExpT.loadFromFile("img/HpBarMax.png");
    UI_maxExpS.setTexture(UI_maxHpT);
    UI_maxExpS.setPosition(UI_expBorderS.getPosition().x,UI_expBorderS.getPosition().y);
    UI_expBarT.loadFromFile("img/ExpBar.png");
    UI_expBarS.setTexture(UI_expBarT);
    UI_expBarS.setPosition(UI_expBorderS.getPosition().x,UI_expBorderS.getPosition().y);
    UI_expText.setString("EXP");
    UI_expText.setFillColor(Color::Black);
    UI_expText.setOutlineColor(Color::White);
    UI_expText.setOutlineThickness(3.5);
    UI_expText.setFont(menuFont);
    UI_expText.setCharacterSize(UIFontSize);
    UI_expValue.setFillColor(Color::Black);
    UI_expValue.setOutlineColor(Color::White);
    UI_expValue.setOutlineThickness(2);
    UI_expValue.setFont(menuFont);
    UI_expValue.setCharacterSize(UIFontSize - 15);
}

void Game::drawPlaying(){
    this->gameWindow->setView(camera);
    this->gameWindow->draw(mapSprite);
    this->gameWindow->setView(this->gameWindow->RenderTarget::getDefaultView());
    updateMiniMenu();
    if(isMenuOpen){
        miniMenuS.setPosition(windowWidth / 2,windowHeight / 2);
        this->gameWindow->draw(miniMenuS);
        for(int i = 0;i < 3;i++){
            miniMenuText[i].setOrigin(getObjWidth(miniMenuText[i]) / 2.0,getObjHeight(miniMenuText[i]) / 2.0);
            miniMenuText[i].setPosition(windowWidth / 2,windowHeight / 2 + 100 * arrIndex[i]);
            updateMiniMenuClick();
            this->gameWindow->draw(miniMenuText[i]);
        }
        updateUI();
    }
    else {
        updateView();
        updateUI();
    }
    this->gameWindow->draw(mouseIconSprite);
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

void Game::updateMiniMenu(){
    if(checkEscape()){
        if(isMenuOpen)isMenuOpen = false;
        else isMenuOpen = true;
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

void Game::updateUI(){
    player[0].hp = 100;
    player[0].exp = 50;
    UI_level.setString("LV. " + to_string(player[now_player].level));
    UI_name.setString(playerName[now_player]);
    UI_name.setOrigin(getObjWidth(UI_name) / 2,getObjHeight(UI_name) / 2);
    UI_charFaceS.setTexture(UI_charFaceT[player[now_player].character_number]);
    UI_charFaceS.setOrigin(getObjWidth(UI_charFaceS) / 2,getObjHeight(UI_charFaceS) / 2);
    UI_expBarS.setScale((double)player[now_player].exp / expMax[player[now_player].level - 1],1);
    UI_hpBarS.setScale((double)player[now_player].hp / player[now_player].HpMax(),1);
    UI_hpText.setPosition(UI_hpBorderS.getPosition().x - 130,UI_hpBorderS.getPosition().y);
    UI_hpValue.setPosition(UI_hpBorderS.getPosition().x + ((getObjWidth(UI_hpBorderS) / 2) - getObjWidth(UI_hpValue) / 2),UI_hpBorderS.getPosition().y + ((getObjHeight(UI_hpBorderS) / 2) - getObjHeight(UI_hpValue) / 2) - 3);
    UI_expText.setPosition(UI_hpText.getPosition().x,UI_expBorderS.getPosition().y);
    UI_expValue.setPosition(UI_expBorderS.getPosition().x + ((getObjWidth(UI_expBorderS) / 2) - getObjWidth(UI_expValue) / 2),UI_expBorderS.getPosition().y + ((getObjHeight(UI_expBorderS) / 2) - getObjHeight(UI_expValue) / 2) - 3);
    UI_hpValue.setString(to_string(player[now_player].hp) + "/" + to_string(player[now_player].HpMax()));
    UI_expValue.setString(to_string(player[now_player].exp) + "/" + to_string(expMax[player[now_player].level - 1]));
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
    if(UI_maxHpS.getGlobalBounds().contains(mousePos)){
        this->gameWindow->draw(UI_hpValue);
    }
    if(UI_maxExpS.getGlobalBounds().contains(mousePos)){
        this->gameWindow->draw(UI_expValue);
    }
}

void Game::setItemStat(){
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
    potion[1].name_object ="Red potion";         potion[1].potion_effect = 10;

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
