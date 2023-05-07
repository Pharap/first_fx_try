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

//text to print when interacting with things
String Text = "";

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
    hero.direction = Direction::Up;
    //checkTile(hero);
    if (hero.y < yMin ) hero.y = yMax;
  }

  if(arduboy.justPressed(DOWN_BUTTON)){
    hero.direction = Direction::Down;
    //checkTile(hero);
    if (hero.y > yMax ) hero.y = yMin;
  }

  if(arduboy.justPressed(LEFT_BUTTON)){
    hero.facingLeft = true;
    hero.direction = Direction::Left;
    //checkTile(hero);
    if (hero.x < xMin ) hero.x = xMax;
  }

  if(arduboy.justPressed(RIGHT_BUTTON)){
    hero.facingLeft = false;
    hero.direction = Direction::Right;
    //checkTile(hero);
    if (hero.x > xMax ) hero.x = xMin;
  }

  //not sure if calling checkTile() like this is better than repeating it on every button press
  if(arduboy.justPressed(RIGHT_BUTTON)||arduboy.justPressed(LEFT_BUTTON)||arduboy.justPressed(DOWN_BUTTON)||arduboy.justPressed(UP_BUTTON)){
    checkTile(hero);
  }
}

const __FlashStringHelper * interactWith(Characters & character, TileType tile, uint8_t tileX, uint8_t tileY)
{
  // // If tile is not interactive
  // if(!isInteractive(tile))
  //   // Return an empty string
  //   return F("");

  // Otherwise, check the tile type, and respond accordingly
  switch(tile)
  {
    case TileType::Torch:
      return F("It's warm!");

    case TileType::Trap:
    {
      if (character.life > 0)
        character.life -= 1;

      return F("Ouch!");
    }

    case TileType::Chest:
      return F("Yup, that's a chest.");

    case TileType::Npc:
      return F("Hello!");

    case TileType::OpenDoor:
    {
      // Try to find the open door
      Door door;
      if(roomMap.findDoorAt(tileX, tileY, door))
      {
        // If a door was found, load the map it connects to
        loadIndexedMap(door.mapIndex);

        // Return some relevant message
        return F("Another room.");
      }
      else
      {
        // If no map was found, tell the player the door is broken
        return F("It's broken.");
      }
    }

    case TileType::ClosedDoor:
      return F("It's locked.");

    // In all other cases
    default:
      return F("There's nothing here.");
  }
}

void checkTile(Characters & character)
{
  // Calculate new position
  uint8_t newX = character.x;
  uint8_t newY = character.y;

  // Checks the next tile depending which direction the character is looking
  switch(character.direction)
  {
    case Direction::Left:
      newX = (character.x - character.step);
      break;

    case Direction::Right:
      newX = (character.x + character.step);
      break;

    case Direction::Up:
      newY = (character.y - character.step);
      break;

    case Direction::Down:
      newY = (character.y + character.step);
      break;
  }

  // Calculate tile coordinates of new position
  uint8_t tileX = (newX / tileWidth);
  uint8_t tileY = (newY / tileHeight);

  TileType tile = roomMap.getTile(tileX, tileY);

  // If position is non-solid (movement is allowed)...
  if(!isSolid(tile))
  {
    character.x = newX;
    character.y = newY;
  }
  
  // Try to interact with the tile
  Text = interactWith(character, tile, tileX, tileY);
}




void drawHero(){
  hero.frame = (hero.weapon) ?
	((hero.facingLeft) ? 2 : 3) :
	((hero.facingLeft) ? 0 : 1);

  FX::drawBitmap(hero.x, hero.y, FXhero, hero.frame, dbmNormal);
}

