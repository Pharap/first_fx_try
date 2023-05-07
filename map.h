#pragma once

#include <stdint.h>
#include <avr/pgmspace.h>

#include "maps.h"
#include "Door.h"
#include "TileType.h"

class Map
{
  private:
    // A 2D array of tiles
    TileType map[mapHeight][mapWidth];

    // An array of doors, up to a maximum of 4
    Door doors[maxDoors];

  public:
    // Retrieves tile from map
    TileType getTile(uint8_t x, uint8_t y) const
    {
      // If coordinate is out of bounds
      if((x > mapWidth) || (y > mapHeight))
        // Return an invalid tile
        return TileType::Invalid;

      // Else, return the tile at the coordinates
      return this->map[y][x];
    }

    // Overwrites tile on map
    void setTile(uint8_t x, uint8_t y, TileType tile)
    {
      // If coordinate is out of bounds
      if((x > mapWidth) || (y > mapHeight))
        // Do nothing
        return;

      // Else, set the tile
      this->map[y][x] = tile;
    }

    // Loads map
    void load(MapData map)
    {
      // Copies map from progmem to ram
      memcpy_P(this->map, map.map, sizeof(this->map));

      // Copies doors from progmem to ram
      memcpy_P(this->doors, map.doors, sizeof(Door) * map.doorCount);
    }
};