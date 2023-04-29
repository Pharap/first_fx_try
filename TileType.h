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