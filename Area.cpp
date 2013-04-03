//=============================================================================
#include "Area.h"
#include <iostream>
using namespace std;
//=============================================================================
Area Area::AreaControl;

//=============================================================================
Area::Area() {
    AreaSize = 0;
    
    
}

//=============================================================================
bool Area::OnLoad(char* File) {
    //clears area resources
    OnCleanup();
	
	//opens File
    FILE* FileHandle = fopen(File, "r");

    //kicks back if file is empty
    if(FileHandle == NULL) {
        return false;
    }

    char TilesetFile[255];

    //reads .maps file
    fscanf(FileHandle, "%s\n", TilesetFile);

    if((Surf_Tileset = Surface::OnLoad(TilesetFile)) == false) {
        fclose(FileHandle);

        return false;
    }
	
	//reads area size from .area
    fscanf(FileHandle, "%d\n", &AreaSize);
	
	//runs through each tile in the area
    for(int X = 0;X < AreaSize;X++) {
        for(int Y = 0;Y < AreaSize;Y++) {
            char MapFile[255];
			
            fscanf(FileHandle, "%s ", MapFile);

            Map tempMap;
            if(tempMap.OnLoad(MapFile) == false) {
                fclose(FileHandle);

                return false;
            }

            tempMap.Surf_Tileset = Surf_Tileset;

            MapList.push_back(tempMap);
        }
        fscanf(FileHandle, "\n");
    }

    fclose(FileHandle);

    return true;
}


//-----------------------------------------------------------------------------
void Area::OnRender(SDL_Surface* Surf_Display, int CameraX, int CameraY, int PlayerX, int PlayerY) {
	int MapWidth  = MAP_WIDTH * TILE_SIZE;
	int MapHeight = MAP_HEIGHT * TILE_SIZE;
	
	
	int FirstID = -CameraX / MapWidth;
		FirstID = FirstID + ((-CameraY / MapHeight) * AreaSize);
	
	if (PlayerX>CameraX+WWIDTH)
		{
			ID=FirstID + 1;
		}else
	if (PlayerX<CameraX)
		{
			ID=FirstID - 1;
		}else
	if (PlayerY>CameraY+WHEIGHT)
		{
			ID=FirstID + AreaSize;
		}else
	if (PlayerY<CameraY)
		{
			ID=FirstID - AreaSize;
		}else{
			ID=FirstID;
		}
		
	//for(int i = 0;i < 4;i++) {
		//int ID = FirstID + ((i / 2) * AreaSize) + (i % 2);
		
		//if(ID < 0 || ID >= MapList.size()) continue;
		
		int X = ((ID % AreaSize) * MapWidth) + CameraX;
		int Y = ((ID / AreaSize) * MapHeight) + CameraY;
		
		cout << ID << "\n";
		cout << X << "\n";
		cout << Y << "\n";
		
		MapList[ID].OnRender(Surf_Display, X, Y);
	//}
}

//-----------------------------------------------------------------------------
void Area::OnCleanup() {
	if(Surf_Tileset) {
		SDL_FreeSurface(Surf_Tileset);
	}

	MapList.clear();
}

//=============================================================================
Map* Area::GetMap(int X, int Y) {
	int MapWidth  = MAP_WIDTH * TILE_SIZE;
	int MapHeight = MAP_HEIGHT * TILE_SIZE;

    int ID = X / MapWidth;
        ID = ID + ((Y / MapHeight) * AreaSize);

    if(ID < 0 || ID >= MapList.size()) {
        return NULL;
    }

    return &MapList[ID];
}

//-----------------------------------------------------------------------------
Tile* Area::GetTile(int X, int Y) {
	int MapWidth  = MAP_WIDTH * TILE_SIZE;
	int MapHeight = MAP_HEIGHT * TILE_SIZE;

	Map* Map = GetMap(X, Y);

	if(Map == NULL) return NULL;

	X = X % MapWidth;
	Y = Y % MapHeight;

    return Map->GetTile(X, Y);
}

//=============================================================================
