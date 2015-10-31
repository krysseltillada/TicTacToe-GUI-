#ifndef COLLISION_H
#define COLLISION_H

class Collision
{
    public:
        Collision () = default;

        inline
        bool InRange (float val ,float min, float max) {
            return (val <= max && val >= min);
        }

        inline
        bool PointToRectangle (float mouseX, float mouseY, float bx, float by, float bw, float bh) {
            return (InRange (mouseX, bx, bx + bw) &&
                    InRange (mouseY, by, by + bh));
        }
};

#endif // COLLISION_H
