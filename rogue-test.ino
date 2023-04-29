#include <ArduboyFX.h>
#include <Arduboy2.h>
#include "FXDATA/data.h"
#include "game.h"


void setup() {
  arduboy.begin();
  arduboy.setFrameRate(15);
  FX::begin(FX_DATA_PAGE);
  loadIndexedMap(firstMapIndex);
}


void loop() {
  if (!arduboy.nextFrame()) return;
  drawMap();
  move_hero();

  //arduboy.setCursor(0, 0);
  //arduboy.println(yMax);
  //arduboy.println(yMin);



  FX::drawBitmap(hero.x, hero.y, FXhero, hero.frame, dbmNormal);

  FX::display(CLEAR_BUFFER);
}
