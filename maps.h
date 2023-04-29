#pragma once

// For uint8_t
#include <stdint.h>

// For PROGMEM
#include <avr/pgmspace.h>

constexpr uint8_t mapWidth = 16;
constexpr uint8_t mapHeight = 8;

constexpr uint8_t map_0[mapHeight][mapWidth] PROGMEM{
  {0,1,1,1,1,1,1,14,1,1,1,1,1,1,1,2},
  {5,19,6,6,6,6,6,6,6,6,6,6,6,6,19,7},
  {5,6,6,6,6,6,6,6,6,6,6,6,6,6,6,7},
  {5,6,6,6,16,6,6,6,6,6,6,6,6,15,15,7},
  {5,6,18,6,6,6,6,6,6,6,6,15,15,15,6,7},
  {5,6,6,6,6,6,6,6,6,15,15,15,6,6,6,7},
  {5,19,6,6,6,6,6,6,6,15,6,6,6,6,19,7},
  {10,11,11,11,11,11,11,11,11,11,11,11,11,11,11,12}
};

constexpr uint8_t map_1[mapHeight][mapWidth] PROGMEM{
  {0,1,1,14,1,1,1,1,2,17,17,17,17,17,17,17},
  {5,19,6,6,6,6,6,15,7,17,17,17,17,17,17,17},
  {5,6,6,6,6,6,15,15,7,17,17,17,17,17,17,17},
  {5,6,6,6,6,6,15,15,8,1,1,1,1,1,1,2},
  {5,6,6,6,6,6,15,19,15,6,6,6,6,6,18,7},
  {5,6,6,6,6,6,6,15,6,6,6,6,6,6,6,7},
  {5,19,6,6,6,6,6,6,6,6,6,6,6,6,19,7},
  {10,11,11,11,11,11,11,13,11,11,11,11,11,11,11,12}
};

constexpr uint8_t mapCount = 2;
constexpr uint8_t firstMapIndex = 0;
constexpr uint8_t lastMapIndex = (mapCount - 1);

//array of maps
constexpr uint8_t * maps[mapCount] PROGMEM{
  &map_0[0][0],
  &map_1[0][0],
};

//pointer to map
const uint8_t * getMap(uint8_t index){
  return static_cast<const uint8_t *>(pgm_read_ptr(&maps[index]));
}