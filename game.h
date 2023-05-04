#pragma once

#include "map.h"
#include "maps.h"
#include "TileType.h"
#include "structures.h"



Arduboy2 arduboy;

void checkTile(Characters & character);

//uint8_t frame = 0;
//uint8_t herox = 64;
constexpr uint8_t step = 8;

constexpr uint8_t tileWidth = 8;
constexpr uint8_t tileHeight = 8;

constexpr uint8_t yMin = 0;
constexpr uint8_t yMax = (Arduboy2::height() - tileHeight);

constexpr uint8_t xMin = 0;
constexpr uint8_t xMax = (Arduboy2::width() - tileWidth);

Map roomMap;

uint8_t mapIndex = 0;

// Load the specified map
void loadIndexedMap(uint8_t index)
{
	roomMap.load(getMap(index));
}


void drawMap()
{
	for(uint8_t tileY = 0; tileY < mapHeight; ++tileY)
		for(uint8_t tileX = 0; tileX < mapWidth; ++tileX)
		{
			// Calculate the y position to draw the tile at.
			int16_t drawY = (tileY * tileHeight);

			// Calculate the x position to draw the tile at.
			int16_t drawX = (tileX * tileWidth);

			// Read the tile from the map.
			TileType tileType = roomMap.getTile(tileX, tileY);

			// Figure out the tile index.
			uint8_t tileIndex = toTileIndex(tileType);

			// Draw the tile at the calculated position.
			FX::drawBitmap(drawX, drawY, FXdungeon, tileIndex, dbmNormal);
		}
}

void moveHero(){
  arduboy.pollButtons();
  

  if(arduboy.pressed(A_BUTTON))
	{
		if(arduboy.justPressed(UP_BUTTON))
			if(mapIndex < lastMapIndex)
			{
				++mapIndex;
				loadIndexedMap(mapIndex);
			}

		if(arduboy.justPressed(DOWN_BUTTON))
			if(mapIndex > firstMapIndex)
			{
				--mapIndex;
				loadIndexedMap(mapIndex);
			}
	}
  if(arduboy.justPressed(B_BUTTON)){
    if (hero.weapon == false){
      hero.weapon = true;
    } else (hero.weapon = false);
  }

//movement
  if(arduboy.justPressed(UP_BUTTON)){
    hero.y -= hero.step;
    if (hero.y < yMin ) hero.y = yMax;
  }

  if(arduboy.justPressed(DOWN_BUTTON)){
    hero.y += hero.step;
    if (hero.y > yMax ) hero.y = yMin;
  }

  /*if(arduboy.justPressed(LEFT_BUTTON)){
    hero.facingLeft = true;
    hero.x -= hero.step;
    if (hero.x < xMin ) hero.x = xMax;
  }*/

  if(arduboy.justPressed(RIGHT_BUTTON)){
    hero.facingLeft = false;
    hero.x += hero.step;
    if (hero.x > xMax ) hero.x = xMin;
  }

  if(arduboy.justPressed(LEFT_BUTTON))
  {
    // Calculate new X position
    int newX = (hero.x - 8);

    // Calculate tile coordinates of new position
    uint8_t tileX = (newX / tileWidth);
    uint8_t tileY = (hero.y / tileHeight);

    // If position is non-solid (movement is allowed)...
    TileType tileChecked = roomMap.getTile(tileX, tileY);
    if(isSolid(tileChecked))
      // Move player
      hero.x = newX;
  }
}






void drawHero(){
  if(hero.weapon == false){
    if(hero.facingLeft == true){
      hero.frame = 0;
    }
    if(hero.facingLeft == false){
      hero.frame = 1;
    }
  }
  if(hero.weapon == true){
    if(hero.facingLeft == true){
      hero.frame = 2;
    }
    if(hero.facingLeft == false){
      hero.frame = 3;
    }
  }
  FX::drawBitmap(hero.x, hero.y, FXhero, hero.frame, dbmNormal);
}

