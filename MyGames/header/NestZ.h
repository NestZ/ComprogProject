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
        void update();
        void updateSfmlEvent();
        void render();
        enum States {Menu, ChoosePlayers, ChooseCharacters, Setting};
        bool checkMouseClick();
        //Menu
        double getButtonWidth(Text);
        double getButtonHeight(Text);
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
        //ChooseCharacters
        double getSpriteWidth(Sprite);
        double getSpriteHeight(Sprite);
        void initChooseCharactersVariables();
        void drawChooseCharacters();
        void updatePlayerIcon();
        void setPlayerIcon(Sprite &, int);
        void chooseState(int);
        //randomPlayer
        void initRandomPlayerVariables();
        void drawRandomPlayers();
    private:
        //Menu
        Vector2i mousePosView;
        Vector2f mousePos;
        int menuCharacterSize;
        Font menuFont;
        Text menuButton[3];
        Texture menuBGTexture;
        Sprite menuBGSprite;
        //Window
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
        bool choosed[6];
        Texture charTexture[6];
        Sprite charSprite[6];
        Texture chooseCharacterBGTexture;
        Sprite chooseCharacterBGSprite;
        //randomPlayer
        vector<string> playerName;

};

Game::Game(){
    initVariables();
    initWindow();
}

void Game::initVariables(){
    initMenuVariables();
    initRandomPlayerVariables();
    initChoosePlayersVariables();
    initChooseCharactersVariables();
    initWindowVariables();
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

void Game::render(){
        this->gameWindow->clear();
        switch(state.top()){
            case Menu:
                drawMenu();
                break;
            case ChoosePlayers:
                drawChoosePlayers();
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

void Game::updateSfmlEvent(){
    while (this->gameWindow->pollEvent(sfEvent))
        {
            if (sfEvent.type == Event::Closed){
                this->gameWindow->close();
            }
        }
}

void Game::initMenuVariables(){
    menuCharacterSize = 45;
    menuFont.loadFromFile("font/8-BIT WONDER.TTF");
    menuBGTexture.loadFromFile("img/bg.jpg");
    menuBGSprite.setTexture(menuBGTexture);
}

void Game::drawMenu(){
    updateMenuButton();

    menuButton[0].setString("PLAY");
    menuButton[1].setString("SETTING");
    menuButton[2].setString("QUIT");

    for(int i = 0;i < 3;i++){
        setMenuButton(menuButton[i],i);
    }

    this->gameWindow->draw(menuBGSprite);
    for(int i = 0;i < 3;i++){
        this->gameWindow->draw(menuButton[i]);
    }
}

double Game::getButtonWidth(Text button){
    return button.getGlobalBounds().width;
}

double Game::getButtonHeight(Text button){
    return button.getGlobalBounds().height;
}

void Game::setMenuButton(Text &button, int index){
    button.setFont(menuFont);
    button.setOutlineColor(Color::White);
    button.setOutlineThickness(4);
    button.setLetterSpacing(1.5);
    button.setCharacterSize(menuCharacterSize);
    button.setOrigin(getButtonWidth(button)/2.0,getButtonHeight(button)/2.0);
    button.setPosition(windowWidth/2.0,(windowHeight/2.0 + index*90) + 25);
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

void Game::initChoosePlayersVariables(){
    choosePlayersBGTexture.loadFromFile("img/choosePlayersBG.jpg");
    choosePlayersBGSprite.setTexture(choosePlayersBGTexture);
    choosePlayersFontSize = 35;
    chooseButton[0].setString("2 Players");
    chooseButton[1].setString("3 Players");
    chooseButton[2].setString("4 Players");
}

void Game::drawChoosePlayers(){
    updateChoosePlayersButton();
    this->gameWindow->draw(choosePlayersBGSprite);
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
    text.setOrigin(getButtonWidth(text)/2.0,getButtonHeight(text)/2.0);
    text.setPosition(windowWidth / 2.0,(windowHeight / 4.0) * (index + 1));
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
                state.push(ChooseCharacters);
            }
        }
        else chooseButton[i].setFillColor(Color::Black);
    }
}

void Game::initRandomPlayerVariables(){

}

void Game::drawRandomPlayers(){
    string name;
    for(int i = 0;i < players;i++){
        cin >> name;
        playerName.push_back(name);
    }
}

void Game::initChooseCharactersVariables(){
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
    for(int i = 0;i < 6;i++){
        setPlayerIcon(charSprite[i],i);
        this->gameWindow->draw(charSprite[i]);
    }
    updatePlayerIcon();
}

void Game::setPlayerIcon(Sprite &sprite, int index){
    sprite.setOrigin(getSpriteWidth(sprite) / 2.0,getSpriteHeight(sprite) / 2.0);
    sprite.setPosition((index + 1) * (windowWidth / 7),windowHeight / 2);
}

double Game::getSpriteWidth(Sprite sprite){
    return sprite.getLocalBounds().width;
}

double Game::getSpriteHeight(Sprite sprite){
    return sprite.getLocalBounds().height;
}

void Game::updatePlayerIcon(){
    for(int i = 0;i < 6;i++){
        if(charSprite[i].getGlobalBounds().contains(mousePos)){
                charSprite[i].setScale(1.1,1.1);
        }
        else charSprite[i].setScale(1,1);
    }
}

void Game::chooseState(int index){
    /*if(checkMouseClick()){
        choosed[i] = true;
    }*/
}
#endif
