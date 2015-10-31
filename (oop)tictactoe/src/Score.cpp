#include "Score.h"

Score::Score () :
    scoreCount (0), maxScore (0) { }

Score::~Score() { }

Score &Score::setMaxScore (const unsigned &s) {
    this->maxScore = s;
    return *this;
}

Score &Score::Increase () {
    ++this->scoreCount;
    return *this;
}

Score &Score::Decrease () {
    --this->scoreCount;
    return *this;
}

unsigned Score::getScore () {
    return this->scoreCount;
}
