#include "C:\Users\krysseltillada\Desktop\c++ primer 5th edition\game development\(oop)tictactoe\include\Game.h"

const int  Game::width = 800;
const int  Game::height = 600;

void Game::Run () {
    Initialize ();
}

void Game::Initialize () {
    std::unique_ptr <sf::RenderWindow> pGameWindow (new sf::RenderWindow (sf::VideoMode (width, height), "tic tac toe"));
    std::unique_ptr <sf::Event> pGameEvent (new sf::Event);

    std::unique_ptr <GridPattern> pGridPattern (new GridPattern ());
    std::unique_ptr <TileEngine>  ptileEngine (new TileEngine ());

    std::tuple <sf::Texture, sf::Texture, sf::Texture,
                sf::Texture, sf::Texture, sf::Texture> tileColor;

    std::tuple <bool, bool> PlayerTurn;

    std::tuple <Score, Score> playerScores;

    std::tuple <GameMessage,
                GameMessage> playerTextScores;

    std::unique_ptr <GameMessage> pGameMessage (new GameMessage ());
    std::unique_ptr <GameMessage> pGameMessage2 (new GameMessage ());
    std::unique_ptr <GameMessage> pGameMessage3 (new GameMessage ());

    bool IsMouseButtonPressed = false;
    bool IsKeyPressed = false;

    Collision tileCollision;
    Fps fps;

    sf::Vector2i mousePos;

    pGridPattern->setHeight(3);
    pGridPattern->setWidth(3);
    pGridPattern->generatePattern ();

    ptileEngine->setTextureFile ("Resources/spriteImage/cyantile_n.png");
    ptileEngine->setPosition(190, 120);
    ptileEngine->setBorder(140);
    ptileEngine->setWidth(3);
    ptileEngine->setHeight(3);
    ptileEngine->setScale (40 * 0.1);
    ptileEngine->generateTile();

    std::get <0> (tileColor).loadFromFile ("Resources/spriteImage/redtile_n.png");
    std::get <1> (tileColor).loadFromFile ("Resources/spriteImage/cyantile_n1.png");
    std::get <2> (tileColor).loadFromFile ("Resources/spriteImage/greentile_n.png");
    std::get <3> (tileColor).loadFromFile ("Resources/spriteImage/yellowtile_n.png");
    std::get <4> (tileColor).loadFromFile ("Resources/spriteImage/cyantile_p1.png");
    std::get <5> (tileColor).loadFromFile ("Resources/spriteImage/cyantile_p2.png");

    std::get <0> (PlayerTurn) = true;
    std::get <1> (PlayerTurn) = false;

    std::get <0> (playerTextScores).loadFont ("Resources/Fonts/space_age/space_age.ttf");
    std::get <0> (playerTextScores).setCharacterSize (50);
    std::get <0> (playerTextScores).setMsg (0);
    std::get <0> (playerTextScores).setPosition (100, 12);
    std::get <0> (playerTextScores).setColor (sf::Color (130, 255, 81));

    std::get <1> (playerTextScores).loadFont ("Resources/Fonts/space_age/space_age.ttf");
    std::get <1> (playerTextScores).setCharacterSize (50);
    std::get <1> (playerTextScores).setMsg (0);
    std::get <1> (playerTextScores).setPosition (635, 12);
    std::get <1> (playerTextScores).setColor (sf::Color (255, 50, 81));

    pGameMessage->loadFont ("Resources/Fonts/space_age/space_age.ttf");
    pGameMessage->setCharacterSize (50);
    pGameMessage->setPosition (245, 12);

    pGameMessage2->loadFont ("Resources/Fonts/space_age/space_age.ttf");
    pGameMessage2->setCharacterSize (30);
    pGameMessage2->setPosition (140, 550);

    pGameMessage3->loadFont ("Resources/Fonts/space_age/space_age.ttf");
    pGameMessage3->setCharacterSize (50);
    pGameMessage3->setPosition (130, 150);
    pGameMessage3->setMsg ("Tic Tac Toe \n\n Press any key");


    while (pGameWindow->isOpen ()) {

            while (pGameWindow->pollEvent (*pGameEvent)) {

             if (IsKeyPressed) {
                    Game::EventHandler (*pGameEvent, *pGameWindow, mousePos, IsMouseButtonPressed);

                 }

             else {
                    Game::EventHandler(*pGameEvent, *pGameWindow, IsKeyPressed);
             }

            }

            if (IsKeyPressed) {

                    pGameMessage3->setMsg (" ");

            for (unsigned x = 0; x != ptileEngine->getWidth(); ++x) {
                    for (unsigned y = 0; y != ptileEngine->getHeight(x); ++y) {
                        Game::Update(tileCollision, mousePos,
                                     ptileEngine->getTile(x, y), tileColor,
                                     pGridPattern->getSymbol(y, x), x, y, *pGridPattern,
                                     IsMouseButtonPressed, PlayerTurn,
                                     playerScores,
                                     playerTextScores,
                                     *pGameMessage,
                                     *pGameMessage2);

                        Game::Draw (*pGameWindow, ptileEngine->getTile(x, y),
                                     pGameMessage->getMsg (), std::get <0> (playerTextScores).getMsg (),
                                     std::get <1> (playerTextScores).getMsg (),
                                     pGameMessage2->getMsg ()
                                     );
                    }

            }

            }

            Game::Draw (*pGameWindow, pGameMessage3->getMsg ());

            /*

            std::cout << "fps: " << fps.getFps() << std::endl;
            fps.update();
            */

            Game::Display(*pGameWindow);
            Game::Clear (*pGameWindow);
    }

    IsMouseButtonPressed = false;
    IsKeyPressed = false;
}

void Game::EventHandler (sf::Event &event, sf::RenderWindow &window, sf::Vector2i &mousepos,  bool &IsMouseButtonPressed) {
    if (event.type == sf::Event::Closed) {
        window.close ();
    }

    if (event.type == sf::Event::MouseMoved) {
        mousepos.x = event.mouseMove.x;
        mousepos.y = event.mouseMove.y;
    }

    if (sf::Mouse::isButtonPressed (sf::Mouse::Left)) {
            if (sf::Event::MouseButtonReleased)
                IsMouseButtonPressed = true;
    }

}

void Game::EventHandler (sf::Event &event, sf::RenderWindow &window, bool &IsKeyPressed) {
    if (event.type == sf::Event::KeyPressed)
        IsKeyPressed = true;
}

void Game::Update (Collision &collision, const sf::Vector2i &mousepos,
                   sf::Sprite &tile, std::tuple <sf::Texture, sf::Texture, sf::Texture, sf::Texture, sf::Texture, sf::Texture> &tileColor,
                   char &s, const size_t &x,
                   const size_t &y, GridPattern &pattern,
                   bool &isMouseButtonPressed, std::tuple <bool, bool> &PlayerTurn,
                   std::tuple <Score, Score> &playerScores,
                   std::tuple <GameMessage, GameMessage> &playerTextScores,
                   GameMessage &gameMessage,
                   GameMessage &gameMessage2) {

    if (collision.PointToRectangle(mousepos.x,
                                   mousepos.y,
                                   tile.getPosition ().x,
                                   tile.getPosition ().y,
                                   tile.getGlobalBounds ().width,
                                   tile.getGlobalBounds ().height)) {


                                        if (isMouseButtonPressed) {
                                           if (pattern.getSymbol (y, x) == 'x' ||
                                               pattern.getSymbol (y, x) == 'l') {
                                                   gameMessage2.setMsg ("dont click that again");
                                               }
                                           else {
                                                if (std::get <0> (PlayerTurn)) {
                                                s = 'x';
                                                std::get <0> (PlayerTurn) = false;
                                                std::get <1> (PlayerTurn) = true;
                                                pattern.Increase ();
                                                gameMessage2.setColor (sf::Color (130, 255, 81));
                                                gameMessage2.setMsg (" ");

                                                } else if (std::get <1> (PlayerTurn)) {
                                                s = 'l';
                                                std::get <1> (PlayerTurn) = false;
                                                std::get <0> (PlayerTurn) = true;
                                                pattern.Increase ();
                                                gameMessage2.setColor (sf::Color (255, 50, 81));
                                                gameMessage2.setMsg (" ");
                                                }
                                           }

                                            isMouseButtonPressed = false;

                                        }
                                       std::cout << mousepos.x << " " << mousepos.y << std::endl;

                                        if (std::get <0> (PlayerTurn))
                                            tile.setTexture (std::get <2> (tileColor));
                                        else if (std::get <1> (PlayerTurn))
                                            tile.setTexture (std::get <0> (tileColor));
                                        else
                                            tile.setTexture (std::get <1> (tileColor));


                                   }

                                  else {

                                         if (pattern.getSymbol(y, x) == 'x')
                                                    tile.setTexture (std::get <4> (tileColor));
                                         else if (pattern.getSymbol(y, x) == 'l')
                                                    tile.setTexture (std::get <5> (tileColor));
                                         else
                                                    tile.setTexture (std::get <1> (tileColor));

                                }

          if (pattern.CheckPattern()) {
                if (s == 'x') {
                    std::get <0> (playerScores).Increase ();
                    std::get <0> (playerTextScores).setMsg (std::get <0> (playerScores).getScore ());
                    pattern.resetPattern();
                }
                else if (s == 'l') {
                    std::get <1> (playerScores).Increase ();
                    std::get <1> (playerTextScores).setMsg (std::get <1> (playerScores).getScore ());
                    pattern.resetPattern();
                }
          }

              if (pattern.CheckPatternCount ())
                pattern.resetPattern ();

              if (std::get <0> (PlayerTurn)) {
                gameMessage.setColor (sf::Color (130, 255, 81));
                gameMessage.setMsg ("player 1");
              }
              else if (std::get <1> (PlayerTurn)) {
                gameMessage.setColor (sf::Color (255, 50, 81));
                gameMessage.setMsg ("player 2");
              }

}

void Game::Draw (sf::RenderWindow &gWindow, const sf::Text &text) {
    gWindow.draw (text);
}

void Game::Draw (sf::RenderWindow &gWindow, const sf::RectangleShape &tile) {
    gWindow.draw (tile);
}

void Game::Draw (sf::RenderWindow &gWindow, const sf::Sprite &tile) {
    gWindow.draw (tile);
}

template <typename T, typename ...Tvar>
void Game::Draw (sf::RenderWindow &gWindow, const T &t, const Tvar &...tvar) {
    gWindow.draw (t);
    Draw (gWindow, tvar...);
}

void Game::Display (sf::RenderWindow &gWindow) {
    gWindow.display ();
}

void Game::Clear (sf::RenderWindow &gWindow) {
    gWindow.clear ();
}




