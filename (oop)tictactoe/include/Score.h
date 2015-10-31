#ifndef SCORE_H
#define SCORE_H

class Score
{
    public:
        Score ();
        ~Score ();

        Score &setMaxScore (const unsigned &);

        Score &Increase ();
        Score &Decrease ();

        unsigned getScore ();

    private:
        unsigned scoreCount;
        unsigned maxScore;
};

#endif // SCORE_H
