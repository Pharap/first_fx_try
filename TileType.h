#pragma once

// For uint8_t
#include <stdint.h>

// Represents the type of an individual tile
enum class TileType : uint8_t
{
	TopCornerLeft = 0,
  TopMiddleWall = 1,
  TopCornerRight = 2,
  TopInnerLeft = 3,
  TopInnerRight = 4,
  MiddleLeftWall = 5,
  Floor = 6,
  MiddleRightWall = 7,
  BottomInnerLeft = 8,
  BottomInnerRight = 9,
  BottomLeftCorner = 10,
  BottomCenterWall = 11,
  BottomRightWall = 12,
  OpenDoor = 13,
  ClosedDoor = 14,
  Trap = 15,
  Npc = 16,
  Empty = 17,
  Chest = 18,
  Torch = 19,
  Invalid = 255,
};

constexpr uint8_t toTileIndex(TileType tileType)
{
	return static_cast<uint8_t>(tileType);
}

constexpr TileType fromTileIndex(uint8_t tileIndex)
{
	return static_cast<TileType>(tileIndex);
}

/*constexpr bool isSolid(TileType tileType)
{
	// Currently all tiles apart from 'None' are solid
	return (tileType != TileType::Floor);
}*/

// Note: Can't be 'constexpr' in C++11 because 'switch' is used
bool isSolid(TileType tileType)
{
	switch(tileType)
	{
		// List all the solid types
		case TileType::TopCornerLeft:
		case TileType::TopMiddleWall:
		case TileType::TopCornerRight:
    case TileType::TopInnerLeft:
    case TileType::TopInnerRight:
    case TileType::MiddleLeftWall:
    case TileType::MiddleRightWall:
    case TileType::BottomInnerLeft:
    case TileType::BottomInnerRight:
    case TileType::BottomLeftCorner:
    case TileType::BottomCenterWall:
    case TileType::BottomRightWall:
    //not sure on this ones yet
    case TileType::Npc:
		case TileType::Chest:
    case TileType::Torch:
  	case TileType::ClosedDoor:
			// Return 'true', because it's solid
			return true;
		
		// Any tile not listed above is non-solid
		default:
			// Return 'false', because it's not solid
			return false;
	}
}

bool isInteractive(TileType tileType)
{
	switch(tileType)
	{
		// List all the interactive types
		case TileType::Npc:
		case TileType::Chest:
    case TileType::Torch:
    case TileType::Trap:
  	case TileType::ClosedDoor:
			// Return 'true'
			return true;
		
		// Any tile not listed above is non-interactive
		default:
			// Return 'false'
			return false;
	}
}