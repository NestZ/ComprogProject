#ifndef NESTZ_GAME_H
#define NESTZ_GAME_H
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <stack>
#include <vector>

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
        void update();
        Event updateSfmlEvent();
        void render();
        enum States {Menu, ChoosePlayers, ChooseCharacters, Setting, InsertName};
        bool checkMouseClick();
        double windowMidWidth();
        double windowMidHeight();
        template <typename T>
        double getObjWidth(T);
        template <typename T>
        double getObjHeight(T);
        template <typename T>
        void Swap(T &, T&);
        //Menu
        void initMenuVariables();
        void checkMouseClick(int);
        void setMenuButton(Text &, int);
        void drawMenu();
        void updateMousePos();
        void updateMenuButton();
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
    private:
        //Menu
        Vector2i mousePosView;
        Vector2f mousePos;
        int menuFontSize;
        Font menuFont;
        Text menuButton[3];
        Texture menuBGTexture;
        Sprite menuBGSprite;
        //Window
        Texture backButtonTexture;
        Sprite backButtonSprite;
        bool MouseReleased;
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
        int randomIndexST;
        int randomIndexND;
        int chooseIndex;
        Text mainPlayerNameText;
        string mainPlayerNameString;
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
    initMenuVariables();
    initInsertNameVariables();
    initChoosePlayersVariables();
    initChooseCharactersVariables();
    initWindowVariables();
    initGlobalVariables();
}

void Game::initWindow(){
    gameWindow = new RenderWindow(VideoMode(windowWidth,windowHeight),GameName,Style::Close);
    this->gameWindow->setVerticalSyncEnabled(true);
    this->gameWindow->setKeyRepeatEnabled(false);
}

void Game::initWindowVariables(){
    state.push(Menu);
    gameWindow = NULL;
    windowWidth = 1280;
    windowHeight = 720;
    MouseReleased = true;
}

void Game::initGlobalVariables(){
    menuFontSize = 45;
    choosePlayersFontSize = 35;
    cinTextFontSize = 35;
    insertedNameFontSize = 30;
    choosingCharacterFontSize = 45;
    menuFont.loadFromFile("font/8-BIT WONDER.TTF");
    backButtonTexture.loadFromFile("img/BackButton.png");
    backButtonSprite.setTexture(backButtonTexture);
    backButtonSprite.setOrigin(getObjWidth(backButtonSprite) / 2.0,getObjHeight(backButtonSprite) / 2.0);
    backButtonSprite.setPosition(70,windowHeight - 70);
    backButtonSprite.setScale(0.7,0.7);
    backButtonSprite.setRotation(-45);
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
            case Setting:
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
                state.push(InsertName);
            }
        }
        else chooseButton[i].setFillColor(Color::Black);
    }
}

void Game::updateBackButtonHMP(){
    if(backButtonSprite.getGlobalBounds().contains(mousePos)){
        backButtonSprite.setScale(0.8,0.8);
        if(checkMouseClick()){
            state.pop();
        }
    }
    else backButtonSprite.setScale(0.7,0.7);
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
        backButtonSprite.setScale(0.8,0.8);
        if(checkMouseClick()){
            resetIPN();
            state.pop();
        }
    }
    else backButtonSprite.setScale(0.7,0.7);
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
    charSprite[0].setTexture(charTexture[0]);
    charTexture[1].loadFromFile("img/Char2.png");
    charSprite[1].setTexture(charTexture[1]);
    charTexture[2].loadFromFile("img/Char3.png");
    charSprite[2].setTexture(charTexture[2]);
    charTexture[3].loadFromFile("img/Char4.png");
    charSprite[3].setTexture(charTexture[3]);
    charTexture[4].loadFromFile("img/Char5.png");
    charSprite[4].setTexture(charTexture[4]);
    charTexture[5].loadFromFile("img/Char6.png");
    charSprite[5].setTexture(charTexture[5]);
    chooseCharacterBGTexture.loadFromFile("img/chooseCharacterBG.jpg");
    chooseCharacterBGSprite.setTexture(chooseCharacterBGTexture);

}

void Game::drawChooseCharacters(){
    this->gameWindow->draw(chooseCharacterBGSprite);
    updateChoosingState();
    this->gameWindow->draw(mainPlayerNameText);
    for(int i = 0;i < 6;i++){
        setCharacterIcon(charSprite[i],i);
        this->gameWindow->draw(charSprite[i]);
    }
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
        if(charSprite[i].getGlobalBounds().contains(mousePos)){
            charSprite[i].setScale(1.1,1.1);
        }
        else charSprite[i].setScale(1,1);
    }
}

void Game::updateChoosingState(){
    updateCharacterIcon();
    mainPlayerNameString = playerName[chooseIndex] + " turn";

    mainPlayerNameText.setString(mainPlayerNameString);

    mainPlayerNameText.setFillColor(Color::Black);
    mainPlayerNameText.setCharacterSize(choosingCharacterFontSize);
    mainPlayerNameText.setFont(menuFont);
    mainPlayerNameText.setOrigin(getObjWidth(mainPlayerNameText) / 2,getObjHeight(mainPlayerNameText) / 2);
    mainPlayerNameText.setPosition(windowMidWidth(),150);
    mainPlayerNameText.setOutlineColor(Color::White);
    mainPlayerNameText.setOutlineThickness(4);
    /*if(checkMouseClick()){
        choosed[i] = true;
    }*/
}
#endif
