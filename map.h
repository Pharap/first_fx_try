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

    // Number of doors on current map
    uint8_t doorCount;

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

    // Returns the number of doors loaded
    uint8_t getDoorCount() const
    {
      return this->doorCount;
    }

    // Gets a loaded door
    // Warning: Be sure to check that (index < getDoorCount())
    Door & getDoor(uint8_t index)
    {
      return this->doors[index];
    }

    // Read-only version of the above
    const Door & getDoor(uint8_t index) const
    {
      return this->doors[index];
    }

    // Tries to locate a door at the specified position
    bool findDoorAt(uint8_t x, uint8_t y, Door & result)
    {
      // Iterate through all the doors on the map
      for(uint8_t index = 0; index < this->doorCount; ++index)
      {
        // Get the door
        Door & door = this->doors[index];

        // If the door is at the specified position
        if(door.x == x && door.y == y)
        {
          // Set the result
          result = door;

          // Return true for success
          return true;
        }
      }

      // No door was found, return false for failure
      return false;
    }

    // Loads map
    void load(MapData map)
    {
      // Copies map from progmem to ram
      memcpy_P(this->map, map.map, sizeof(this->map));

      // Copies doors from progmem to ram
      memcpy_P(this->doors, map.doors, sizeof(Door) * map.doorCount);

      // Tracks the number of loaded doors
      this->doorCount = map.doorCount;
    }
};