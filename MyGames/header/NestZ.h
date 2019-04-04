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
        Texture mapTexture;
        Sprite mapSprite;
        View camera;
        bool isMenuOpen;
        Text miniMenuText[3];
        int miniMenuFontSize;
        int arrIndex[3] = {-1,0,1};
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
    menuFontSize = 50;
    choosePlayersFontSize = 45;
    cinTextFontSize = 35;
    insertedNameFontSize = 35;
    choosingCharacterFontSize = 45;
    playerChoosedFontSize = 20;
    settingFontSize = 35;
    miniMenuFontSize = 35;
    menuFont.loadFromFile("font/8-BIT WONDER.TTF");
}

void Game::initWindow(){
    gameWindow = new RenderWindow(VideoMode(windowWidth,windowHeight),GameName,Style::Close);
    this->gameWindow->setVerticalSyncEnabled(false);
    this->gameWindow->setFramerateLimit(60);
    this->gameWindow->setKeyRepeatEnabled(true);
    this->gameWindow->setMouseCursorGrabbed(true);
    this->gameWindow->setMouseCursorVisible(false);
}

void Game::initWindowVariables(){
    state.push(Menu);
    gameWindow = NULL;
    windowWidth = 1280;
    windowHeight = 720;
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
    //Menu
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
    text.setPosition(windowMidWidth(),(windowMidHeight() + index*90) + 25);
}

void Game::updateMousePos(){
    mousePosView = Mouse::getPosition(*this->gameWindow);
    mousePos = this->gameWindow->mapPixelToCoords(mousePosView);
}

void Game::updateMenuButton(){
    for(int i = 0;i < 3;i++){
        if(menuButton[i].getGlobalBounds().contains(mousePos)){
            menuButton[i].setFillColor(Color::Red);
            if(checkMouseClick()){
                switch(i){
                    case 0: //play
                        this->gameWindow->clear();
                        state.push(ChoosePlayers);
                        break;
                    case 1: //setting
                        this->gameWindow->clear();
                        state.push(Setting);
                        break;
                    case 2: //quit
                        this->gameWindow->close();
                }
            }
        }
        else menuButton[i].setFillColor(Color::Black);
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
        settingText[i].setOutlineThickness(4);
        settingText[i].setFillColor(Color::Black);
        settingText[i].setCharacterSize(settingFontSize);
        settingText[i].setPosition(100,(windowHeight / 4) * (i + 1));
    }
    for(int i = 0;i < 3;i++){
        plusS[i].setTexture(plusT);
        minusS[i].setTexture(minusT);
        plusS[i].setOrigin(getObjWidth(plusS[i]) / 2,getObjHeight(plusS[i]) / 2);
        minusS[i].setOrigin(getObjWidth(minusS[i]) / 2,getObjHeight(minusS[i]) / 2);
        plusS[i].setPosition(1200,settingText[i].getPosition().y);
        minusS[i].setPosition(1000,settingText[i].getPosition().y);
        plusS[i].setScale(0.8,0.8);
        minusS[i].setScale(0.8,0.8);
    }
    int i = 0;
    char format[] = "%s : %d";
    ifstream fileIn("Setting.ini");
    while(getline(fileIn,settingString)){
        sscanf(settingString.c_str(),format,temp,&setting[i]);
        cout << temp << " " << setting[i] << '\n';
        i++;
    }
    fileIn.close();

    updateSettingValue();

    for(int i = 0;i < settingIndex;i++){
        settingValue[i].setFont(menuFont);
        settingValue[i].setOutlineColor(Color::White);
        settingValue[i].setOutlineThickness(4);
        settingValue[i].setFillColor(Color::Black);
        settingValue[i].setCharacterSize(settingFontSize);
        settingValue[i].setPosition(1100,settingText[i].getPosition().y);
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
            this->gameWindow->clear();
            state.pop();
        }
    }
    else backButtonSprite.setScale(0.6,0.6);
    if(checkEscape()){
        updateSettingIni();
        this->gameWindow->clear();
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
    text.setCharacterSize(choosePlayersFontSize);
    text.setOutlineColor(Color::White);
    text.setOutlineThickness(4);
    text.setLetterSpacing(1.5);
    text.setOrigin(getObjWidth(text)/2.0,getObjHeight(text)/2.0);
    text.setPosition(windowMidWidth(),(windowHeight / 4.0) * (index + 1));
}

void Game::updateChoosePlayersButton(){
    for(int i = 0;i < 3;i++){
        if(chooseButton[i].getGlobalBounds().contains(mousePos)){
            chooseButton[i].setFillColor(Color::Red);
            if(checkMouseClick()){
                switch(i){
                    case 0: //2 players
                        players = 2;
                        break;
                    case 1: //3 players
                        players = 3;
                        break;
                    case 2: //4 players
                        players = 4;
                        break;
                }
                this->gameWindow->clear();
                state.push(InsertName);
            }
        }
        else chooseButton[i].setFillColor(Color::Black);
    }
}

void Game::updateBackButtonHMP(){
    if(backButtonSprite.getGlobalBounds().contains(mousePos)){
        backButtonSprite.setScale(0.7,0.7);
        if(checkMouseClick()){
            this->gameWindow->clear();
            state.pop();
        }
    }
    else backButtonSprite.setScale(0.6,0.6);
    if(checkEscape()){
        this->gameWindow->clear();
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
    cinText.setPosition(windowMidWidth(),windowMidHeight());
    InsertedName.setFont(menuFont);
    InsertedName.setFillColor(Color::White);
    InsertedName.setCharacterSize(insertedNameFontSize);
    InsertedName.setOrigin(getObjWidth(InsertedName)/2.0,getObjHeight(InsertedName)/2.0);
    InsertedName.setPosition(windowMidWidth(),windowMidHeight() + 200);
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
            this->gameWindow->clear();
            state.push(ChooseCharacters);
        }
    }
}

void Game::updateBackButtonIPN(){
    if(backButtonSprite.getGlobalBounds().contains(mousePos)){
        backButtonSprite.setScale(0.7,0.7);
        if(checkMouseClick()){
            resetIPN();
            this->gameWindow->clear();
            state.pop();
        }
    }
    else backButtonSprite.setScale(0.6,0.6);
    if(checkEscape()){
        resetIPN();
        this->gameWindow->clear();
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
                playerChoosedName[chooseIndex].setPosition(charSprite[i].getPosition().x,charSprite[i].getPosition().y - 130);
                //setPlayer's Character
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
    mainPlayerNameText.setPosition(windowMidWidth(),100);
    for(int i = 0;i < players;i++){
        playerChoosedName[i].setFillColor(Color::Black);
        playerChoosedName[i].setOutlineColor(Color::White);
        playerChoosedName[i].setOutlineThickness(1.5);
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
            this->gameWindow->clear();
            state.pop();
        }
    }
    else backButtonSprite.setScale(0.6,0.6);
    if(checkEscape()){
        resetCC();
        resetIPN();
        this->gameWindow->clear();
        state.pop();
    }
}

void Game::resetCC(){
    chooseIndex = 0;
    for(int i = 0;i < 6;i++)choosed[i] = false;
}

/*#############################################################################################################
##########                                                                                          ###########
##########                                       PLAYING                                            ###########
##########                                                                                          ###########
#############################################################################################################*/

void Game::initPlayingVariables(){
    isMenuOpen = false;
    mapTexture.loadFromFile("img/Map.jpg");
    mapSprite.setTexture(mapTexture);
    mapSprite.setPosition(0,0);
    camera.setCenter(Vector2f(300,300));
    camera.setSize(Vector2f(300,300));
    camera.setViewport(FloatRect(0,0,1,1));
    miniMenuText[0].setString("Reseum");
    miniMenuText[1].setString("Setting");
    miniMenuText[2].setString("Exit Game");
    for(int i = 0;i < 3;i++){
        miniMenuText[i].setFillColor(Color::Black);
        miniMenuText[i].setOutlineColor(Color::White);
        miniMenuText[i].setOutlineThickness(2.5);
        miniMenuText[i].setFont(menuFont);
        miniMenuText[i].setCharacterSize(miniMenuFontSize);
    }
}

void Game::drawPlaying(){
    this->gameWindow->setView(camera);
    this->gameWindow->draw(mapSprite);
    this->gameWindow->setView(this->gameWindow->RenderTarget::getDefaultView());
    updateMiniMenu();
    if(isMenuOpen){
        for(int i = 0;i < 3;i++){
            miniMenuText[i].setOrigin(getObjWidth(miniMenuText[i]) / 2.0,getObjHeight(miniMenuText[i]) / 2.0);
            miniMenuText[i].setPosition(windowWidth / 2,windowHeight / 2 + 70 * arrIndex[i]);
            this->gameWindow->draw(miniMenuText[i]);
        }
    }
    else {
        updateView();
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
#endif
