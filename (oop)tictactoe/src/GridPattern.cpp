#include "GridPattern.h"

GridPattern::GridPattern () :
    pGridPattern (new std::vector <std::vector <char> > ()),
    GridPatternHeight (0),
    GridPatternWidth (0),
    patternCount (0) { }

GridPattern::~GridPattern () { }

void GridPattern::Print () {

    for (unsigned x = 0; x != pGridPattern->size (); ++x) {
        for (unsigned y = 0; y != pGridPattern->at (x).size (); ++y) {
            std::cout << pGridPattern->at (x).at (y) << " ";
        }
        std::cout << std::endl;
    }

}

GridPattern &GridPattern::setHeight (const size_t &h) {
    this->GridPatternHeight = h;
    return *this;
}

GridPattern &GridPattern::setWidth  (const size_t &w) {
    this->GridPatternWidth = w;
    return *this;
}

GridPattern &GridPattern::Increase () {
    ++this->patternCount;
    return *this;
}

GridPattern &GridPattern::Decrease () {
    --this->patternCount;
    return *this;
}

GridPattern &GridPattern::generatePattern () {
    std::vector <char> tempPattern;

    for (unsigned x = 0; x != GridPatternWidth; ++x) {
            for (unsigned y = 0; y != GridPatternHeight; ++y) {
                tempPattern.push_back ('o');
            }

            pGridPattern->push_back (tempPattern);
            tempPattern.clear ();
    }

    return *this;
}

GridPattern &GridPattern::resetPattern () {
    pGridPattern->clear ();

    std::vector <char> tempPattern;

    for (unsigned x = 0; x != GridPatternWidth; ++x) {
            for (unsigned y = 0; y != GridPatternHeight; ++y) {
                tempPattern.push_back ('o');
            }

            pGridPattern->push_back (tempPattern);
            tempPattern.clear ();
    }

    patternCount = 0;

    return *this;
}

bool GridPattern::CheckPattern () {
   return   (( (pGridPattern->at (0).at(0) == 'x' && pGridPattern->at (0).at (1) == 'x' && pGridPattern->at (0).at(2) == 'x') ||
               (pGridPattern->at (1).at(0) == 'x' && pGridPattern->at (1).at (1) == 'x' && pGridPattern->at (1).at(2) == 'x') ||
               (pGridPattern->at (2).at(0) == 'x' && pGridPattern->at (2).at (1) == 'x' && pGridPattern->at (2).at(2) == 'x') ||
               (pGridPattern->at (0).at(0) == 'x' && pGridPattern->at (1).at (0) == 'x' && pGridPattern->at (2).at(0) == 'x') ||
               (pGridPattern->at (0).at(1) == 'x' && pGridPattern->at (1).at (1) == 'x' && pGridPattern->at (2).at(1) == 'x') ||
               (pGridPattern->at (0).at(2) == 'x' && pGridPattern->at (1).at (2) == 'x' && pGridPattern->at (2).at(2) == 'x') ||
               (pGridPattern->at (0).at(0) == 'x' && pGridPattern->at (1).at (1) == 'x' && pGridPattern->at (2).at(2) == 'x') ||
               (pGridPattern->at (0).at(2) == 'x' && pGridPattern->at (1).at (1) == 'x' && pGridPattern->at (2).at(0) == 'x'))
             ||
             ( (pGridPattern->at (0).at(0) == 'l' && pGridPattern->at (0).at (1) == 'l' && pGridPattern->at (0).at(2) == 'l') ||
               (pGridPattern->at (1).at(0) == 'l' && pGridPattern->at (1).at (1) == 'l' && pGridPattern->at (1).at(2) == 'l') ||
               (pGridPattern->at (2).at(0) == 'l' && pGridPattern->at (2).at (1) == 'l' && pGridPattern->at (2).at(2) == 'l') ||
               (pGridPattern->at (0).at(0) == 'l' && pGridPattern->at (1).at (0) == 'l' && pGridPattern->at (2).at(0) == 'l') ||
               (pGridPattern->at (0).at(1) == 'l' && pGridPattern->at (1).at (1) == 'l' && pGridPattern->at (2).at(1) == 'l') ||
               (pGridPattern->at (0).at(2) == 'l' && pGridPattern->at (1).at (2) == 'l' && pGridPattern->at (2).at(2) == 'l') ||
               (pGridPattern->at (0).at(0) == 'l' && pGridPattern->at (1).at (1) == 'l' && pGridPattern->at (2).at(2) == 'l') ||
               (pGridPattern->at (0).at(2) == 'l' && pGridPattern->at (1).at (1) == 'l' && pGridPattern->at (2).at(0) == 'l'))
             );
}

bool GridPattern::CheckPatternCount () {
    return patternCount == GridPatternHeight * GridPatternWidth;
}


char &GridPattern::getSymbol (const size_t &x, const size_t &y) {
    return pGridPattern->at (x).at (y);
}





