#pragma once

#include <stdint.h>
#include <avr/pgmspace.h>

#include "maps.h"
#include "TileType.h"

class Map{
  private: 
    TileType data[mapHeight][mapWidth];
  public:
    //retrieves tile from map
    TileType getTile(uint8_t x, uint8_t y) const{
      if((x > mapWidth)||(y > mapHeight)) return TileType::Invalid;

      return this->data[y][x];
    }
  //overwrite tile on map
  void setTile(uint8_t x, uint8_t y, TileType tile){
    if((x > mapWidth)||(y > mapHeight)) return;

    this->data[y][x] = tile;
  }

  //loads map
  void load(const uint8_t * data){
    //copies map from progmem to ram
    memcpy_P(this->data, data, sizeof(this->data));
  }
};