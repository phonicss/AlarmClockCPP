#include "game.h"
#include <iostream>
#include <ctime>
#include <chrono>
#include <sstream>
#include <iomanip>
#include <typeinfo>
#include <vector>

void Game::initVariables(){
    this->window = nullptr;

    //game logic

    this-> hours = 12;
    this-> minutes = 30;
    this->time1 = "";
    this->time2 = "";
    this->time3 = "";
    this-> timeList[3];
    this-> mousePressed = true;
    this-> alarmOn1 = false;
    this-> alarmOn2 = false;
    this-> alarmOn3 = false;
    this-> alarmOn1Active = false;
    this-> alarmOn2Active = false;
    this-> alarmOn3Active = false;
    this-> lock = false; 
    this->catSound.setLoop(true);
    

    

}

void Game::initWindow(){
    this->videoMode.height = 500;
    this->videoMode.width = 400;
    this->window = new sf::RenderWindow(this->videoMode, "Cozy Clock", sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(5);
}

void Game::initFonts(){
    if (this->font.loadFromFile("C:\\Users\\ADMIN\\Desktop\\AlarmClock\\coding\\fonts\\Roadblock.otf")){
        std::cout << "File loaded fonts" << std::endl;
    } else {
        std::cout << "File failed to load fonts" << std::endl;
    }
     if (this->font2.loadFromFile("C:\\Users\\ADMIN\\Desktop\\AlarmClock\\coding\\fonts\\Fresh Honey.otf")){
        std::cout << "File loaded fonts" << std::endl;
    } else {
        std::cout << "File failed to load fonts" << std::endl;
    }
}

void Game::initSounds(){
    
    if (this->catMeow.loadFromFile("C:\\Users\\ADMIN\\Desktop\\AlarmClock\\coding\\sounds\\meowMeow.wav")) {
        std::cout << "Sound File is loaded" << std::endl;
        this->catSound.setBuffer(this->catMeow);
    } else {
        std::cout << "Sound File is not loaded" << std::endl;
    }
}

void Game::initImages(){
    if (this->catTexture.loadFromFile("C:\\Users\\ADMIN\\Desktop\\AlarmClock\\coding\\images\\caticon.png")){
           std::cout << "Image is loaded " << std::endl;
           this->catSprite.setTexture(catTexture, true);
           this->catSprite.setScale(0.2,0.2);
           this->catSprite.setPosition(200.f,25.f);
           
    } else {
        std::cout << "Iamge failed to load" << std::endl;
    }
    
}

void Game::initMainText(){
    this->mainText.setFont(this->font);
    this->mainText.setCharacterSize(60);
    this->mainText.setFillColor(sf::Color::White);
    this->mainText.setOutlineColor(sf::Color::Black);
    this->mainText.setOutlineThickness(1);
    this->mainText.setString("Cozy Clock");
    this->mainText.setPosition(40.f,20.f);
}

void Game::initCurrentTimeText(){
    this->currentTimeText.setFont(this->font);
    this->currentTimeText.setCharacterSize(40);
    this->currentTimeText.setFillColor(sf::Color::White);
    this->currentTimeText.setOutlineColor(sf::Color::Black);
    this->currentTimeText.setOutlineThickness(1);
    this->currentTimeText.setString("Tue Jul 23 20:24:42 2023");
    this->currentTimeText.setPosition(90.f,140.f);
}

void Game::initDisplay(){
    //displayFrame
    this->displayFrame.setSize(sf::Vector2f(350,280));
    this->displayFrame.setPosition(25.f,206.f);
    this->displayFrame.setFillColor(sf::Color(252, 180, 180));
    this->displayFrame.setOutlineColor(sf::Color::Black);
    this->displayFrame.setOutlineThickness(2);
    //display
    this->display.setSize(sf::Vector2f(110,50));
    this->display.setPosition(145.f,230.f);
    this->display.setFillColor(sf::Color::White);
    this->display.setOutlineColor(sf::Color::Black);
    this->display.setOutlineThickness(2);
    //displayList
    this->displayList.setSize(sf::Vector2f(300,120));
    this->displayList.setPosition(50.f,350.f);
    this->displayList.setFillColor(sf::Color::White);
    this->displayList.setOutlineColor(sf::Color::Black);
    this->displayList.setOutlineThickness(2);
    //init text for hours 
    this->alarmTimeH.setFont(this->font);
    this->alarmTimeH.setCharacterSize(30);
    this->alarmTimeH.setFillColor(sf::Color::White);
    this->alarmTimeH.setOutlineColor(sf::Color::Black);
    this->alarmTimeH.setOutlineThickness(1);
    this->alarmTimeH.setString("1");
    this->alarmTimeH.setPosition(153.f,240.f);
    //init text for minutes
    this->alarmTimeM.setFont(this->font);
    this->alarmTimeM.setCharacterSize(30);
    this->alarmTimeM.setFillColor(sf::Color::White);
    this->alarmTimeM.setOutlineColor(sf::Color::Black);
    this->alarmTimeM.setOutlineThickness(1);
    this->alarmTimeM.setString("1");
    this->alarmTimeM.setPosition(210.f,240.f);
    //init alarm semiColumn
    this->alarmSemiColumn.setFont(this->font);
    this->alarmSemiColumn.setCharacterSize(30);
    this->alarmSemiColumn.setFillColor(sf::Color::White);
    this->alarmSemiColumn.setOutlineColor(sf::Color::Black);
    this->alarmSemiColumn.setOutlineThickness(1);
    this->alarmSemiColumn.setString(":");
    this->alarmSemiColumn.setPosition(195.f,240.f);
    //init time list lines for alarm
    //line1
    this->timeListLine1.setFont(this->font);
    this->timeListLine1.setCharacterSize(30);
    this->timeListLine1.setFillColor(sf::Color::White);
    this->timeListLine1.setOutlineColor(sf::Color::Black);
    this->timeListLine1.setOutlineThickness(1);
    this->timeListLine1.setString("");
    this->timeListLine1.setPosition(145.f,355.f);
     //line2
    this->timeListLine2.setFont(this->font);
    this->timeListLine2.setCharacterSize(30);
    this->timeListLine2.setFillColor(sf::Color::White);
    this->timeListLine2.setOutlineColor(sf::Color::Black);
    this->timeListLine2.setOutlineThickness(1);
    this->timeListLine2.setString("");
    this->timeListLine2.setPosition(146.f,395.f);
     //line3
    this->timeListLine3.setFont(this->font);
    this->timeListLine3.setCharacterSize(30);
    this->timeListLine3.setFillColor(sf::Color::White);
    this->timeListLine3.setOutlineColor(sf::Color::Black);
    this->timeListLine3.setOutlineThickness(1);
    this->timeListLine3.setString("");
    this->timeListLine3.setPosition(145.f,435.f);
    //numbers for lines
     //number1
    this->number1.setFont(this->font);
    this->number1.setCharacterSize(30);
    this->number1.setFillColor(sf::Color::White);
    this->number1.setOutlineColor(sf::Color::Black);
    this->number1.setOutlineThickness(1);
    this->number1.setString("1");
    this->number1.setPosition(60.f,355.f);
     //number2
    this->number2.setFont(this->font);
    this->number2.setCharacterSize(30);
    this->number2.setFillColor(sf::Color::White);
    this->number2.setOutlineColor(sf::Color::Black);
    this->number2.setOutlineThickness(1);
    this->number2.setString("2");
    this->number2.setPosition(60.f,395.f);
     //number3
    this->number3.setFont(this->font);
    this->number3.setCharacterSize(30);
    this->number3.setFillColor(sf::Color::White);
    this->number3.setOutlineColor(sf::Color::Black);
    this->number3.setOutlineThickness(1);
    this->number3.setString("3");
    this->number3.setPosition(60.f,435.f);
    //buts for delete lines 
    //line 1
    this->lineDelete1.setSize(sf::Vector2f(30,30));
    this->lineDelete1.setPosition(300.f,355.f);
    this->lineDelete1.setFillColor(sf::Color::Red);
    this->lineDelete1.setOutlineColor(sf::Color::Black);
    this->lineDelete1.setOutlineThickness(2);
    //line 2
    this->lineDelete2.setSize(sf::Vector2f(30,30));
    this->lineDelete2.setPosition(300.f,395.f);
    this->lineDelete2.setFillColor(sf::Color::Red);
    this->lineDelete2.setOutlineColor(sf::Color::Black);
    this->lineDelete2.setOutlineThickness(2);
    //line 3
    this->lineDelete3.setSize(sf::Vector2f(30,30));
    this->lineDelete3.setPosition(300.f,435.f);
    this->lineDelete3.setFillColor(sf::Color::Red);
    this->lineDelete3.setOutlineColor(sf::Color::Black);
    this->lineDelete3.setOutlineThickness(2);

    //crosses for delete buttons
    this->cross1.setFont(this->font2);
    this->cross1.setCharacterSize(30);
    this->cross1.setFillColor(sf::Color::White);
    this->cross1.setOutlineColor(sf::Color::Black);
    this->cross1.setOutlineThickness(1);
    this->cross1.setString("X");
    this->cross1.setPosition(309.f,350.f);

    this->cross2.setFont(this->font2);
    this->cross2.setCharacterSize(30);
    this->cross2.setFillColor(sf::Color::White);
    this->cross2.setOutlineColor(sf::Color::Black);
    this->cross2.setOutlineThickness(1);
    this->cross2.setString("X");
    this->cross2.setPosition(309.f,392.f);

    this->cross3.setFont(this->font2);
    this->cross3.setCharacterSize(30);
    this->cross3.setFillColor(sf::Color::White);
    this->cross3.setOutlineColor(sf::Color::Black);
    this->cross3.setOutlineThickness(1);
    this->cross3.setString("X");
    this->cross3.setPosition(309.f,432.f);

}

void Game::initButtons(){
    //help
    this->helpButton.setRadius(15.f);
    this->helpButton.setPosition(365,10);
    this->helpButton.setFillColor(sf::Color::White);
    this->helpButton.setOutlineColor(sf::Color::Black);
    this->helpButton.setOutlineThickness(1);

    this->helpButtonText.setFont(this->font2);
    this->helpButtonText.setCharacterSize(35);
    this->helpButtonText.setFillColor(sf::Color::Black);
    this->helpButtonText.setString("?");
    this->helpButtonText.setPosition(375,00);

    //time set hours +
    this->plusH.setRadius(15.f);
    this->plusH.setPosition(112,220);
    this->plusH.setFillColor(sf::Color::White);
    this->plusH.setOutlineColor(sf::Color::Black);
    this->plusH.setOutlineThickness(1);

    this->plusHtext.setFont(this->font);
    this->plusHtext.setCharacterSize(60);
    this->plusHtext.setFillColor(sf::Color::Black);
    this->plusHtext.setString("+");
    this->plusHtext.setPosition(115,189);

    //time set hours -
    this->minusH.setRadius(15.f);
    this->minusH.setPosition(112,260);
    this->minusH.setFillColor(sf::Color::White);
    this->minusH.setOutlineColor(sf::Color::Black);
    this->minusH.setOutlineThickness(1);

    this->minusHtext.setFont(this->font);
    this->minusHtext.setCharacterSize(60);
    this->minusHtext.setFillColor(sf::Color::Black);
    this->minusHtext.setString("-");
    this->minusHtext.setPosition(115,230);

    //time set minutes +
    this->plusM.setRadius(15.f);
    this->plusM.setPosition(257,220);
    this->plusM.setFillColor(sf::Color::White);
    this->plusM.setOutlineColor(sf::Color::Black);
    this->plusM.setOutlineThickness(1);

    this->plusMtext.setFont(this->font);
    this->plusMtext.setCharacterSize(60);
    this->plusMtext.setFillColor(sf::Color::Black);
    this->plusMtext.setString("+");
    this->plusMtext.setPosition(260,189);

    //time set minutes -
    this->minusM.setRadius(15.f);
    this->minusM.setPosition(257,260);
    this->minusM.setFillColor(sf::Color::White);
    this->minusM.setOutlineColor(sf::Color::Black);
    this->minusM.setOutlineThickness(1);

    this->minusMtext.setFont(this->font);
    this->minusMtext.setCharacterSize(60);
    this->minusMtext.setFillColor(sf::Color::Black);
    this->minusMtext.setString("-");
    this->minusMtext.setPosition(260,230);

    //setAlarmButton
    this->setAlarmButton.setSize(sf::Vector2f(80,30));
    this->setAlarmButton.setPosition(158.f,290.f);
    this->setAlarmButton.setFillColor(sf::Color::White);
    this->setAlarmButton.setOutlineColor(sf::Color::Black);
    this->setAlarmButton.setOutlineThickness(2);

    //setAlarmButton text
    this->setAlarmText.setFont(this->font2);
    this->setAlarmText.setCharacterSize(30);
    this->setAlarmText.setFillColor(sf::Color::Black);
    this->setAlarmText.setString("Set Time!");
    this->setAlarmText.setPosition(162,283);
}

void Game::initAlarmNotofication(){

    //frame
    this->alarmNotification.setSize(sf::Vector2f(250,150));
    this->alarmNotification.setPosition(70.f,230.f);
    this->alarmNotification.setFillColor(sf::Color(235, 96, 91));
    this->alarmNotification.setOutlineColor(sf::Color::Black);
    this->alarmNotification.setOutlineThickness(5);

    //main text
    this->alarmNotificationText.setFont(this->font2);
    this->alarmNotificationText.setCharacterSize(50);
    this->alarmNotificationText.setFillColor(sf::Color::White);
    this->alarmNotificationText.setOutlineColor(sf::Color::Black);
    this->alarmNotificationText.setOutlineThickness(1);
    this->alarmNotificationText.setString("Alarm!");
    this->alarmNotificationText.setPosition(150,210);

    //alarm notification button
    this->alarmNotificationButton.setSize(sf::Vector2f(80,30));
    this->alarmNotificationButton.setPosition(155.f,340.f);
    this->alarmNotificationButton.setFillColor(sf::Color::White);
    this->alarmNotificationButton.setOutlineColor(sf::Color::Black);
    this->alarmNotificationButton.setOutlineThickness(2);

    //notification button text
    this->alarmNotButText.setFont(this->font2);
    this->alarmNotButText.setCharacterSize(50);
    this->alarmNotButText.setFillColor(sf::Color::White);
    this->alarmNotButText.setOutlineColor(sf::Color::Black);
    this->alarmNotButText.setOutlineThickness(1);
    this->alarmNotButText.setString("OK");
    this->alarmNotButText.setPosition(180,317);

    //alarm notification text for time
    this->alarmNotTime1.setFont(this->font2);
    this->alarmNotTime1.setCharacterSize(45);
    this->alarmNotTime1.setFillColor(sf::Color::White);
    this->alarmNotTime1.setOutlineColor(sf::Color::Black);
    this->alarmNotTime1.setOutlineThickness(1);
    this->alarmNotTime1.setString("");
    this->alarmNotTime1.setPosition(155,240);

    this->alarmNotTime2.setFont(this->font2);
    this->alarmNotTime2.setCharacterSize(45);
    this->alarmNotTime2.setFillColor(sf::Color::White);
    this->alarmNotTime2.setOutlineColor(sf::Color::Black);
    this->alarmNotTime2.setOutlineThickness(1);
    this->alarmNotTime2.setString("");
    this->alarmNotTime2.setPosition(155,265);

    this->alarmNotTime3.setFont(this->font2);
    this->alarmNotTime3.setCharacterSize(45);
    this->alarmNotTime3.setFillColor(sf::Color::White);
    this->alarmNotTime3.setOutlineColor(sf::Color::Black);
    this->alarmNotTime3.setOutlineThickness(1);
    this->alarmNotTime3.setString("");
    this->alarmNotTime3.setPosition(155,290);




}

void Game::closeAlarmNotification(){
    this->alarmNotTime1.setString("");
    this->alarmNotTime2.setString("");
    this->alarmNotTime3.setString("");
    this->lock = false;
    this->alarmOn1Active = false;
    this->alarmOn2Active = false;
    this->alarmOn3Active = false;
    this->catSound.stop();
}

void Game::updateMousePosititon(){
    this->mousePosWindow = sf::Mouse::getPosition(*this->window);
    this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);
}

void Game::updateCurrentTime(){

    this->plusH.setFillColor(sf::Color::White);
    this->minusH.setFillColor(sf::Color::White);
    this->plusM.setFillColor(sf::Color::White);
    this->minusM.setFillColor(sf::Color::White);
    this->setAlarmButton.setFillColor(sf::Color::White); 
    
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);

    std::ostringstream oss;
    oss << std::put_time(&tm, "%H:%M:%S");
    auto str = oss.str();

    this->currentTimeText.setString(oss.str());

    if (str == this->time1){
        alarmOn1 = true;
        this->alarmOn1Active = true;
        std::cout << "MEOWW! 1" << std::endl;
        if (this->alarmOn1){
            this->catSound.play();
            this->alarmNotTime1.setString(this->time1);
            this->alarmOn1 = false;    
        }
        
    } else if ( str == this->time2) {
        alarmOn2 = true;
        this->alarmOn2Active = true;
        std::cout << "MEOWW! 2" << std::endl;
        if (this->alarmOn2){
            this->catSound.play();
            this->alarmNotTime2.setString(this->time2);
            this->alarmOn2 = false;    
        }
    } else if (str == this->time3) {
        alarmOn3 = true;
        this->alarmOn3Active = true;
        std::cout << "MEOWW! 3" << std::endl;
        if (this->alarmOn3){
            this->catSound.play();
            this->alarmNotTime3.setString(this->time3);
            this->alarmOn3 = false;    
        }
    }
    
}


void Game::updateAlarmClock() {
   
    //set hours
    std::ostringstream ssh;
    if (this->hours < 10) {
        ssh << "0" << this->hours;  
    } else {
        ssh << this->hours; 
    }
    this->alarmTimeH.setString(ssh.str());

    //set minutes
    std::ostringstream ssm;
    if(this->minutes < 10) {
        ssm << "0" << this->minutes;  
    } else {
        ssm << this->minutes; 
    }    
    this->alarmTimeM.setString(ssm.str());

    //check buttons pressed

    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {


        if(this->alarmNotificationButton.getGlobalBounds().contains(this->mousePosView) && this->lock == true) {
            closeAlarmNotification();
        }


        if(this->plusH.getGlobalBounds().contains(this->mousePosView) && this->lock != true) {
            this->plusH.setFillColor(sf::Color::Red);
            this->mousePressed = true;
            if(this->hours == 24) {
                this->hours = 0;
            } else {
                this->hours++;      
            } 
                
        }

        if(this->minusH.getGlobalBounds().contains(this->mousePosView) && this->lock != true) {
            this->minusH.setFillColor(sf::Color::Red);
            this->mousePressed = true;
            if(this->hours <= 0) {
                this->hours = 23;
            } else {
                this->hours--;   
            }   
        }

        if(this->plusM.getGlobalBounds().contains(this->mousePosView) && this->lock != true) {
            this->plusM.setFillColor(sf::Color::Red);
            this->mousePressed = true;
            if(this->minutes == 59) {
                this->minutes = 0;
            } else {
                this->minutes++;   
            }   
        }

        if(this->minusM.getGlobalBounds().contains(this->mousePosView) && this->lock != true) {
            this->minusM.setFillColor(sf::Color::Red);
            this->mousePressed = true;
            if(this->minutes <= 0) {
                this->minutes = 59;
            } else {
                this->minutes--;   
            }   
        }

        if(this->setAlarmButton.getGlobalBounds().contains(this->mousePosView) && this->mousePressed == true && this->lock != true) {
            setTime(); 
        }

        if (this->lineDelete1.getGlobalBounds().contains(this->mousePosView) && this->lock != true) {
            this->catSound.stop();
            this->time1 = "";
            this->mousePressed = true; 
            pushToTimeList();
        }
        if (this->lineDelete2.getGlobalBounds().contains(this->mousePosView) && this->lock != true) {
            this->time2 = "";
            this->mousePressed = true;
            pushToTimeList();
        }
        if (this->lineDelete3.getGlobalBounds().contains(this->mousePosView) && this->lock != true) {
            this->time3 = "";
            this->mousePressed = true;
            pushToTimeList();
        }
    }
}

void Game::setTime(){
    std::string timeString = alarmTimeH.getString() + ":" + alarmTimeM.getString() + ":" + "00";
    this->setAlarmButton.setFillColor(sf::Color::Red);
    this->mousePressed = false;
    if (this->time1 == "") {
        this->time1 = timeString;
    } else if (this->time2 == "") {
        this->time2 = timeString;
    } else if (this->time3 == "") {
        this->time3 = timeString;
    } else {
        std::cout << "time list is full" << std::endl;
    }
    pushToTimeList();  
}

void Game::pushToTimeList(){

    this->timeListLine1.setString(this->time1);
    this->timeListLine2.setString(this->time2);
    this->timeListLine3.setString(this->time3);

}

Game::Game(){
    this->initVariables();
    this->initWindow();
    this->initFonts();
    this->initImages();
    this->initMainText();
    this->initSounds();
    this->initCurrentTimeText();
    this->initDisplay();
    this->initButtons();
    this->initAlarmNotofication();

}



Game::~Game(){
    delete this->window;
}

const bool Game::running() const {
    return this->window->isOpen();
}



void Game::pollEvents(){
    while(this->window->pollEvent(this->ev)){
        switch(this->ev.type){
            case sf::Event::Closed:
                this->window->close();
            case sf::Event::KeyPressed:
                if(this->ev.key.code == sf::Keyboard::Escape){
                    this->window->close();
                }
            break;
        }
    }
}

void Game::RenderUI(sf::RenderTarget& target){
    target.draw(this->catSprite);
    target.draw(this->mainText);
    target.draw(this->currentTimeText);
    target.draw(this->displayFrame);
    target.draw(this->display);
    target.draw(this->displayList);
    target.draw(this->helpButton);
    target.draw(this->alarmTimeH);
    target.draw(this->alarmSemiColumn);
    target.draw(this->alarmTimeM);
    target.draw(this->helpButtonText);
    target.draw(this->plusH);
    target.draw(this->minusH);
    target.draw(this->plusHtext);
    target.draw(this->minusHtext);
    target.draw(this->plusM);
    target.draw(this->minusM);
    target.draw(this->plusMtext);
    target.draw(this->minusMtext);
    target.draw(this->setAlarmButton);
    target.draw(this->setAlarmText);
    target.draw(this->timeListLine1);
    target.draw(this->timeListLine2);
    target.draw(this->timeListLine3);
    target.draw(this->number1);
    target.draw(this->number2);
    target.draw(this->number3);
    target.draw(this->lineDelete1);
    target.draw(this->lineDelete2);
    target.draw(this->lineDelete3);
    target.draw(this->cross1);
    target.draw(this->cross2);
    target.draw(this->cross3);

    //draw alarm notification
    if (this->alarmOn1Active == true || this->alarmOn2Active == true || this->alarmOn3Active == true ) {
        this->lock = true;
        target.draw(this->alarmNotification);
        target.draw(this->alarmNotificationButton);
        target.draw(this->alarmNotificationText);
        target.draw(this->alarmNotButText);
        target.draw(this->alarmNotTime1);
        target.draw(this->alarmNotTime2);
        target.draw(this->alarmNotTime3);
    }
    
    
}



void Game::render(){
    this->window->clear(sf::Color(255, 155, 155));
    this->RenderUI(*this->window);
    this->window->display();
}


void Game::update(){
    this->pollEvents();
    this->updateMousePosititon();
    this->updateCurrentTime();
    this->updateAlarmClock();
}