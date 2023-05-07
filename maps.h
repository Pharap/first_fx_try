#pragma once

// For uint8_t
#include <stdint.h>

// For PROGMEM
#include <avr/pgmspace.h>

// For Door
#include "Door.h"

constexpr uint8_t mapWidth = 16;
constexpr uint8_t mapHeight = 8;
constexpr uint8_t maxDoors = 4;

struct MapData
{
  public:
    const uint8_t * map;
    const Door * doors;
    uint8_t doorCount;

  public:
    // Default constructor
    MapData() = default;

    // Special templated constructor infers the number of doors from the size of the array
    template<uint8_t doorCount>
    constexpr MapData(const uint8_t (& map)[mapHeight][mapWidth], const Door (&doors)[doorCount]) :
      map { &map[0][0] },
      doors { &doors[0] },
      doorCount { doorCount }
    {
      // Use a compile-time assertion to ensure that the map
      // doesn't have too many doors.
      static_assert(doorCount <= maxDoors, "Too many doors!");
    }
};

constexpr uint8_t map_0[mapHeight][mapWidth] PROGMEM
{
  {0,1,1,1,1,1,1,14,1,1,1,1,1,1,1,2},
  {5,19,6,6,6,6,6,6,6,6,6,6,6,6,19,7},
  {5,6,6,6,6,6,6,6,6,6,6,6,6,6,6,7},
  {5,6,6,6,16,6,6,6,6,6,6,6,6,15,15,7},
  {5,6,18,6,6,6,6,6,6,6,6,15,15,15,6,7},
  {5,6,6,6,6,6,6,6,6,15,15,15,6,6,6,7},
  {5,19,6,6,6,6,6,6,6,15,6,6,6,6,19,7},
  {10,11,11,11,11,11,11,11,11,11,11,11,11,11,11,12}
};

constexpr Door map_0_doors[] PROGMEM
{
  // X, Y, map
  // Door at tile (7, 0) leads to map 1
  { 7, 0, 1 }
};

constexpr uint8_t map_1[mapHeight][mapWidth] PROGMEM
{
  {0,1,1,14,1,1,1,1,2,17,17,17,17,17,17,17},
  {5,19,6,6,6,6,6,15,7,17,17,17,17,17,17,17},
  {5,6,6,6,6,6,15,15,7,17,17,17,17,17,17,17},
  {5,6,6,6,6,6,15,15,8,1,1,1,1,1,1,2},
  {5,6,6,6,6,6,15,19,15,6,6,6,6,6,18,7},
  {5,6,6,6,6,6,6,15,6,6,6,6,6,6,6,7},
  {5,19,6,6,6,6,6,6,6,6,6,6,6,6,19,7},
  {10,11,11,11,11,11,11,13,11,11,11,11,11,11,11,12}
};

constexpr Door map_1_doors[] PROGMEM
{
  // X, Y, map
  // Door at tile (3, 0) leads to map 0
  { 3, 0, 0 }
};

constexpr uint8_t mapCount = 2;
constexpr uint8_t firstMapIndex = 0;
constexpr uint8_t lastMapIndex = (mapCount - 1);

// Array of map references
constexpr MapData maps[mapCount] PROGMEM
{
  { map_0, map_0_doors },
  { map_1, map_1_doors },
};

// Read MapData
MapData getMap(uint8_t index)
{
  MapData result;
  memcpy_P(&result, &maps[index], sizeof(result));
  return result;
}