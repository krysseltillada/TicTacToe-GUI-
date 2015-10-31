#ifndef TILEENGINE_H
#define TILEENGINE_H

#include <SFML/Graphics.hpp>

#include <vector>
#include <memory>
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

class TileEngine
{
    public:
        TileEngine();
        ~TileEngine();

        TileEngine &setTextureFile (const std::string &);
        TileEngine &setWidth (const size_t &);
        TileEngine &setHeight (const size_t &);
        TileEngine &setBorder (const size_t &);
        TileEngine &setScale (const size_t &);
        TileEngine &setPosition (const size_t &, const size_t &);

        TileEngine &generateTile ();

        std::string &getFileTileName ();

        size_t getWidth () const;
        size_t getHeight (const size_t &) const;

        sf::Sprite &getTile (const size_t &, const size_t &);

    private:
        std::unique_ptr <std::vector <std::vector <sf::Sprite > > > tileGrid;

        std::unique_ptr <sf::Texture> tileTexture;

        std::string tileFileName;

        unsigned tileWidth;
        unsigned tileHeight;

        unsigned Border;
        unsigned Scale;

        unsigned Gridx;
        unsigned Gridy;
};

#endif // TILEENGINE_H
