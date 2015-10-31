#include "Button.h"

Button::Button () :
    ifPressed (false),
    ifHover (false),
    ButtonWidth (0),
    ButtonHeight (0),
    xButton (0),
    yButton (0) { }

Button::~Button () { }

Button &Button::getEvent (sf::Event &event) {
    if (event.type == sf::Event::MouseMoved) {
        if (hitTesting.PointToRectangle (event.mouseMove.x, event.mouseMove.y,
                                     xButton, yButton,
                                     xButton + ButtonWidth,
                                     yButton + ButtonHeight)) {
                                         label.setColor(sf::Color (130, 255, 81));
                                                ifHover = true;

                                     } else {
                                         label.setColor (sf::Color (sf::Color::Red));
                                     }
    }

    if (ifHover) {
        if (sf::Mouse::isButtonPressed (sf::Mouse::Left))
            ifPressed = true;
    }

    if (ifPressed) {
            callBackState = state;
            ifPressed = false;
    }

}

sf::Text Button::getButton () {
    return label.getMsg ();
}

Button &Button::setState (const std::string &state) {
    this->state = state;
    return *this;
}

Button &Button::setWidth (const unsigned &w) {
    this->ButtonWidth = w;
    return *this;
}

Button &Button::setHeight (const unsigned &h) {
    this->ButtonHeight = h;
    return *this;
}

Button &Button::loadFont (const std::string &file) {
    label.loadFont(file);
    return *this;
}

Button &Button::setButtonText  (const std::string &text) {
    label.setMsg(text);
    return *this;
}

Button &Button::setTextButtonSize (const unsigned &s) {
    label.setCharacterSize (s);
    return *this;
}

Button &Button::setTextColor (sf::Color c) {
    label.setColor (c);
    return *this;
}

Button &Button::setPosition (const unsigned &x, const unsigned &y) {
    this->xButton = x;
    this->yButton = y;

    label.setPosition(xButton, yButton);

    return *this;
}

std::string Button::callBack () const {
    return this->callBackState;
}
