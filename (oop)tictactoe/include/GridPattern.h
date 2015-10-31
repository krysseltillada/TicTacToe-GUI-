#ifndef GRIDPATTERN_H
#define GRIDPATTERN_H

#include <iostream>
#include <vector>
#include <memory>

class GridPattern
{
    public:
        GridPattern ();
        ~GridPattern ();

        void Print ();

        GridPattern &setHeight (const size_t &);
        GridPattern &setWidth  (const size_t &);

        GridPattern &Increase ();
        GridPattern &Decrease ();

        GridPattern &generatePattern ();
        GridPattern &resetPattern ();

        bool CheckPattern ();
        bool CheckPatternCount ();

        char &getSymbol (const size_t &, const size_t &);

    private:
        std::unique_ptr <std::vector <std::vector <char> > > pGridPattern;

        unsigned GridPatternHeight;
        unsigned GridPatternWidth;
        unsigned patternCount;

};

#endif // GRIDPATTERN_H
