//
// Created by Felicia Rulita on 2024/3/15.
//
#include "Map.h"

void Map::RenderMap(){
    int tileSize = 32;
    int width = Map::MAP_WIDTH;
    int height = Map::MAP_HEIGHT;

    Core::Texture soilTexture(GL_RGBA,32,32,soilPath);
    soilTexture.UpdateData(GL_RGBA,32,32,IMG_Load(soilPath));
    for(int x=0;x<height;x++){
        for(int y=0;y<width;y++){
            int posx = x*tileSize;
            int posy = y*tileSize;

            switch(this->map[x][y]){
                case 0:
                    soilTexture.Bind(0);
                    break;
            }

        }
    }





}
