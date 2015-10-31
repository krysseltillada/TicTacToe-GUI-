#ifndef BUTTON_H
#define BUTTON_H

#include "GameMessage.h"
#include "Collision.h"

#include <SFML/Graphics.hpp>

#include <string>
#include <iostream>

class Button
{
    public:
        Button();
        ~Button();

        Button &getEvent (sf::Event &);
        sf::Text getButton ();

        Button &setState (const std::string &);
        Button &setWidth (const unsigned &);
        Button &loadFont (const std::string &);
        Button &setHeight (const unsigned &);
        Button &setButtonText  (const std::string &);
        Button &setTextButtonSize (const unsigned &);
        Button &setTextColor (sf::Color);
        Button &setPosition (const unsigned &, const unsigned &);

        std::string callBack () const;

    private:

        GameMessage label;
        Collision hitTesting;

        bool ifPressed;
        bool ifHover;

        std::string state;
        std::string callBackState;

        unsigned ButtonWidth;
        unsigned ButtonHeight;

        unsigned xButton;
        unsigned yButton;

};

#endif // BUTTON_H
