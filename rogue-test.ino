#include <ArduboyFX.h>
#include <Arduboy2.h>
#include "FXDATA/data.h"


// make an instance of arduboy used for many functions
Arduboy2 arduboy;
uint8_t frame = 0;
uint8_t herox = 64;
uint8_t heroy = 32;
#define DUNGEON_WIDTH    16
#define DUNGEON_HEIGHT  8
uint8_t level = 1;
#define showmap map_0

uint8_t map_0[DUNGEON_HEIGHT][DUNGEON_WIDTH] = {
  {0,1,1,1,1,1,1,14,1,1,1,1,1,1,1,2},
  {5,19,6,6,6,6,6,6,6,6,6,6,6,6,19,7},
  {5,6,6,6,6,6,6,6,6,6,6,6,6,6,6,7},
  {5,6,6,6,16,6,6,6,6,6,6,6,6,15,15,7},
  {5,6,18,6,6,6,6,6,6,6,6,15,15,15,6,7},
  {5,6,6,6,6,6,6,6,6,15,15,15,6,6,6,7},
  {5,19,6,6,6,6,6,6,6,15,6,6,6,6,19,7},
  {10,11,11,11,11,11,11,11,11,11,11,11,11,11,11,12}
};

uint8_t map_1[DUNGEON_HEIGHT][DUNGEON_WIDTH] = {
  {0,1,1,14,1,1,1,1,2,17,17,17,17,17,17,17},
  {5,19,6,6,6,6,6,15,7,17,17,17,17,17,17,17},
  {5,6,6,6,6,6,15,15,7,17,17,17,17,17,17,17},
  {5,6,6,6,6,6,15,15,8,1,1,1,1,1,1,2},
  {5,6,6,6,6,6,15,19,15,6,6,6,6,6,18,7},
  {5,6,6,6,6,6,6,15,6,6,6,6,6,6,6,7},
  {5,19,6,6,6,6,6,6,6,6,6,6,6,6,19,7},
  {10,11,11,13,11,11,11,14,11,11,11,11,11,11,11,12}
};


#define TILE_SIZE  8

void drawworld() {
  for (int y = 0; y < DUNGEON_HEIGHT; y++) {
    for (int x = 0; x < DUNGEON_WIDTH; x++) {
      //Sprites::drawOverwrite(x * TILE_SIZE, y * TILE_SIZE, dungeon, world[y][x]);
      FX::drawBitmap(x * TILE_SIZE, y * TILE_SIZE, FXdungeon, showmap[y][x], dbmNormal);

      
    }
  }
}

void move_hero(){
  arduboy.pollButtons();

  if(arduboy.justPressed(B_BUTTON)){
    if (frame < 1){
      frame++;
    } else (frame = 0);
  }
  if(arduboy.justPressed(A_BUTTON)){
    if (level < 1){
      level++;
    } else (level = 0);
  }
  if(arduboy.justPressed(UP_BUTTON)){
    heroy -=8;
    if (heroy == 248 ) heroy = 56;
  }
  if(arduboy.justPressed(DOWN_BUTTON)){
    heroy +=8;
    if (heroy == 64 ) heroy = 0;
  }
  if(arduboy.justPressed(LEFT_BUTTON)){
    herox -=8;
    if (herox == 248 ) herox = 120;

  }
  if(arduboy.justPressed(RIGHT_BUTTON)){
    herox +=8;
    if (herox == 128 ) herox = 0;
  }
}
// This function runs once in your game.
// use it for anything that needs to be set only once in your game.
void setup() {
  // initiate arduboy instance
  arduboy.begin();
  arduboy.setFrameRate(15);
  FX::begin(FX_DATA_PAGE);

  

  // here we set the frame rate to 15, we do not need to run at
  // default 60 and it saves us battery life
  //arduboy.setFrameRate(15);

  
}


// our main game loop, this runs once every cycle/frame.
// this is where our game logic goes.

//uint8_t tilemapBuffer[rows];

void loop() {
  if (!arduboy.nextFrame()) return;
  drawworld(3);
  move_hero();
  arduboy.setCursor(0, 0);
  //arduboy.println(heroy);
  //arduboy.println(herox);


  FX::drawBitmap(herox, heroy, FXhero, frame, dbmNormal);

  FX::display(CLEAR_BUFFER);
}
