#ifndef GAMEMESSAGE_H
#define GAMEMESSAGE_H

#include <SFML/Graphics.hpp>

#include <memory>
#include <sstream>
#include <stdexcept>

class GameMessage
{
    public:
        GameMessage();
        ~GameMessage();

        GameMessage (GameMessage &);
        GameMessage (const GameMessage &);

        GameMessage &setMsg (const std::string &);
        GameMessage &setMsg (const unsigned &);
        GameMessage &loadFont (const std::string &);
        GameMessage &setCharacterSize (const size_t &);
        GameMessage &setColor (sf::Color);
        GameMessage &setPosition (const size_t &, const size_t &);

        sf::Text getMsg () const;

    private:
        std::unique_ptr <std::string> pMessage;
        std::unique_ptr <sf::Font>    pMessageFont;
        std::unique_ptr <sf::Text>    pMessageText;

        unsigned characterSize;
};

#endif // GAMEMESSAGE_H
