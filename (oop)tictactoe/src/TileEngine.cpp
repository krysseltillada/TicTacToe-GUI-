#include "C:\Users\krysseltillada\Desktop\c++ primer 5th edition\game development\(oop)tictactoe\include\TileEngine.h"

TileEngine::TileEngine() :
    tileGrid (new std::vector <std::vector <sf::Sprite> >  ()),
    tileTexture (new sf::Texture ()),
    tileWidth (0),
    tileHeight (0)
    { std::cerr << "tile texture allocated " << std::endl << "tile Grid allocated " << std::endl; }

TileEngine::~TileEngine()  { std::cerr << "tile texture freed " << std::endl
                                       << "tile Grid freed " << std::endl
                                       << "tile location freed" << std::endl; }

TileEngine &TileEngine::setTextureFile (const std::string &fileName) {
    this->tileFileName = fileName;
    return *this;
}

TileEngine &TileEngine::setWidth (const size_t &w) {
    this->tileWidth = w;
    return *this;
}

TileEngine &TileEngine::setHeight (const size_t &h) {
    this->tileHeight = h;
    return *this;
}

TileEngine &TileEngine::setBorder (const size_t &b) {
    this->Border = b;
    return *this;
}

TileEngine &TileEngine::setScale (const size_t &s) {
    this->Scale = s;
    return *this;
}

TileEngine &TileEngine::setPosition (const size_t &x, const size_t &y) {
    this->Gridx = x;
    this->Gridy = y;
    return *this;
}

TileEngine &TileEngine::generateTile () {

    std::vector <sf::Sprite> tempTile;

    try {
        if (!tileTexture->loadFromFile (getFileTileName()))
            throw std::string ("error loading texture file " + getFileTileName());
    } catch (const std::string &err) {
        throw std::runtime_error (err);
    }

    for (unsigned x = 0; x != tileWidth; ++x) {
        for (unsigned y = 0; y != tileHeight; ++y) {
            sf::Sprite tile;
            tile.setScale (Scale, Scale);
            tile.setTexture (*tileTexture);
            tile.setPosition (Border * x + Gridx, Border * y + Gridy);
            tempTile.push_back (tile);
        }

        tileGrid->push_back (tempTile);
        tempTile.clear ();
    }

    return *this;
}


std::string &TileEngine::getFileTileName () {
    return this->tileFileName;
}


size_t TileEngine::getWidth () const {
    return tileGrid->size ();
}

size_t TileEngine::getHeight (const size_t &x) const {
    return tileGrid->at (x).size ();
}

sf::Sprite &TileEngine::getTile (const size_t &xTile, const size_t &yTile) {
    return tileGrid->at (xTile).at (yTile);
}


