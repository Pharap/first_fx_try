#pragma once


enum class Direction : uint8_t
{
	Up, Right, Down, Left
};


struct Characters
{   
    uint8_t w=8;
    uint8_t h=8;
    int16_t x=64;
    int16_t y=32;

    //uint8_t iframe=50;

    Direction direction;

    bool facingLeft = true;
    
    //bool enable = false;

    bool collide = false;

    bool weapon = false;

    uint8_t step = 8;

    uint8_t frame = 0;

    int8_t life = 3;

};

Characters hero;