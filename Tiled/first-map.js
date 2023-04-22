(function(name,data){
 if(typeof onTileMapLoaded === 'undefined') {
  if(typeof TileMaps === 'undefined') TileMaps = {};
  TileMaps[name] = data;
 } else {
  onTileMapLoaded(name,data);
 }
 if(typeof module === 'object' && module && module.exports) {
  module.exports = data;
 }})("first-map",
{ "compressionlevel":-1,
 "height":8,
 "infinite":false,
 "layers":[
        {
         "data":[1, 2, 2, 15, 2, 2, 2, 2, 3, 18, 18, 18, 18, 18, 18, 18,
            6, 20, 7, 7, 7, 7, 7, 16, 8, 18, 18, 18, 18, 18, 18, 18,
            6, 7, 7, 7, 7, 7, 16, 16, 8, 18, 18, 18, 18, 18, 18, 18,
            6, 7, 7, 7, 7, 7, 16, 16, 9, 2, 2, 2, 2, 2, 2, 3,
            6, 7, 7, 7, 7, 7, 16, 20, 16, 7, 7, 7, 7, 7, 19, 8,
            6, 7, 7, 7, 7, 7, 7, 16, 7, 7, 7, 7, 7, 7, 7, 8,
            6, 20, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 20, 8,
            11, 12, 12, 14, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 13],
         "height":8,
         "id":1,
         "name":"Tile Layer 1",
         "opacity":1,
         "type":"tilelayer",
         "visible":true,
         "width":16,
         "x":0,
         "y":0
        }],
 "nextlayerid":2,
 "nextobjectid":1,
 "orientation":"orthogonal",
 "renderorder":"right-down",
 "tiledversion":"1.10.1",
 "tileheight":8,
 "tilesets":[
        {
         "columns":5,
         "firstgid":1,
         "image":"..\/src\/Dungeon_8x8.png",
         "imageheight":32,
         "imagewidth":40,
         "margin":0,
         "name":"tiles",
         "spacing":0,
         "tilecount":20,
         "tileheight":8,
         "tilewidth":8
        }],
 "tilewidth":8,
 "type":"map",
 "version":"1.10",
 "width":16
});