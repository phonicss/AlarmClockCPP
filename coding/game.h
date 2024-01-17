#pragma once

#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#ifndef GAME_H
#define GAME_H


class Game{
    private:
        //windows
        sf::RenderWindow* window;
        sf::VideoMode videoMode;
        sf::Event ev;
        //mouse
        sf::Vector2i mousePosWindow;
        sf::Vector2f mousePosView;
        //resources
        sf::Font font;
        sf::Font font2;
        sf::Texture catTexture;
        sf::Sprite catSprite;
        sf::SoundBuffer catMeow;
        sf::Sound catSound;
        //texts
        sf::Text mainText;
        sf::Text currentTimeText;
        sf::Text alarmTimeH;
        sf::Text alarmTimeM;
        sf::Text alarmSemiColumn;
        //TimeListTexts
        sf::Text timeListLine1;
        sf::Text timeListLine2;
        sf::Text timeListLine3;
        sf::Text number1;
        sf::Text number2;
        sf::Text number3;
        //TimeListButtonsForDeletingElements
        sf::RectangleShape lineDelete1;
        sf::RectangleShape lineDelete2;
        sf::RectangleShape lineDelete3;
        //display
        sf::RectangleShape displayFrame;
        sf::RectangleShape display;
        sf::RectangleShape displayList;

        //alarm Display
        sf::RectangleShape alarmNotification;
        sf::Text alarmNotificationText;
        sf::RectangleShape alarmNotificationButton;
        sf::Text alarmNotButText;
        sf::Text alarmNotTime1;
        sf::Text alarmNotTime2;
        sf::Text alarmNotTime3;

        //buttons
        sf::CircleShape helpButton;
        sf::Text helpButtonText;
        sf::CircleShape plusH;
        sf::CircleShape minusH;
        sf::Text plusHtext;
        sf::Text minusHtext;
        sf::CircleShape plusM;
        sf::CircleShape minusM;
        sf::Text plusMtext;
        sf::Text minusMtext;
        sf::RectangleShape setAlarmButton;
        sf::Text setAlarmText;

        // X for delete buttons
        sf::Text cross1;
        sf::Text cross2;
        sf::Text cross3;



        //game logic
        int hours;
        int minutes;
        bool mousePressed;
        bool alarmOn1;
        bool alarmOn2;
        bool alarmOn3;
        bool alarmOn1Active;
        bool alarmOn2Active;
        bool alarmOn3Active;
        bool lock;
        std::string time1;
        std::string time2;
        std::string time3;
        std::vector<std::string> timeList[3];
        
        //private Functions
        void initWindow();
        void initVariables();
        void initFonts();
        void initMainText();
        void initCurrentTimeText();
        void initImages();
        void initSounds();
        void initDisplay();
        void initButtons();
        void initAlarmNotofication();
       
    public:

        //constructor and destructor
        Game();
        virtual ~Game();

        //acssesors
        const bool running() const;

        //functions 
        void render();
        void update();
        void pollEvents();
        void updateMousePosititon();
        void updateCurrentTime();
        void updateAlarmClock();
        void setTime();
        void pushToTimeList();
        void closeAlarmNotification();
        void RenderUI(sf::RenderTarget& target);


};









#endif