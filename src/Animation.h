#ifndef ANIMATION_H
#define ANIMATION_H

class Animation
{
    public:
        unsigned int animationSpeed;
        unsigned int index;
        unsigned int numFrames;

        Animation();
        Animation(unsigned int index, unsigned int numFrames, unsigned int animationSpeed);
};

#endif
