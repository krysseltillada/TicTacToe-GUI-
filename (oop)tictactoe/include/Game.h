#ifndef GAME_H
#define GAME_H

#include "TileEngine.h"
#include "Collision.h"
#include "Fps.h"
#include "GridPattern.h"
#include "Score.h"
#include "GameMessage.h"

#include <SFML/Graphics.hpp>

#include <memory>
#include <string>
#include <iostream>
#include <tuple>

class Game
{
    public:
        Game() = default;
        ~Game() = default;

        static void Run ();
        static void Initialize ();
        static void EventHandler (sf::Event &, sf::RenderWindow &, sf::Vector2i &, bool &);
        static void EventHandler (sf::Event &, sf::RenderWindow &, bool &);
        static void Update (Collision &, const sf::Vector2i &,
                            sf::Sprite &, std::tuple <sf::Texture, sf::Texture, sf::Texture, sf::Texture, sf::Texture, sf::Texture> &,
                            char &, const size_t &, const size_t &, GridPattern &, bool &, std::tuple <bool, bool> &,
                            std::tuple <Score, Score> &,
                            std::tuple <GameMessage, GameMessage> &,
                            GameMessage &, GameMessage &);

        template <typename T, typename ...Tvar>
        static void Draw (sf::RenderWindow &, const T &, const Tvar &...);

        static void Draw (sf::RenderWindow &, const sf::RectangleShape &);
        static void Draw (sf::RenderWindow &, const sf::Text &);
        static void Draw (sf::RenderWindow &, const sf::Sprite &);

        static void Display (sf::RenderWindow &);


        static void Clear (sf::RenderWindow &);

    private:

        static const int width;
        static const int height;
};


#endif // GAME_H
