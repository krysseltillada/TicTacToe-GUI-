#include "GameMessage.h"

GameMessage::GameMessage () :
    pMessage (new std::string ()),
    pMessageFont (new sf::Font ()),
    pMessageText (new sf::Text ()),
    characterSize (0) { }

GameMessage::~GameMessage() { }

GameMessage::GameMessage (GameMessage &cObj) {
    pMessage.reset (cObj.pMessage.release ());
    pMessageFont.reset (cObj.pMessageFont.release ());
    pMessageText.reset (cObj.pMessageText.release ());
}

GameMessage &GameMessage::setMsg (const std::string &msg) {
    *this->pMessage = msg;

    pMessageText->setFont (*pMessageFont);
    pMessageText->setString (*pMessage);
    pMessageText->setCharacterSize (characterSize);

    return *this;
}

GameMessage &GameMessage::setMsg (const unsigned &msg) {
    std::ostringstream tostr;

    tostr << msg;

    *this->pMessage = tostr.str ();

    pMessageText->setFont (*pMessageFont);
    pMessageText->setString (*pMessage);
    pMessageText->setCharacterSize (characterSize);

    return *this;
}

GameMessage &GameMessage::loadFont (const std::string &file) {
    if (!pMessageFont->loadFromFile (file))
        throw std::runtime_error ("error loading file " + file);

    return *this;
}

GameMessage &GameMessage::setCharacterSize (const size_t &s) {
    this->characterSize = s;
    return *this;
}

GameMessage &GameMessage::setColor (sf::Color c) {
    pMessageText->setColor (c);
    return *this;
}

GameMessage &GameMessage::setPosition (const size_t &x, const size_t &y) {
    pMessageText->setPosition (x, y);
    return *this;
}

sf::Text GameMessage::getMsg () const {
    return *pMessageText;
}
