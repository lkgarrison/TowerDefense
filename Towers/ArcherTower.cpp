/* CSE 20212
 * Final Project
 * ArcherTower.cpp
 * constructors and member functions
*/

#include "ArcherTower.h"

//constructor that initializes an ArcherTower (arguments = position)
ArcherTower::ArcherTower(SDL_Renderer** gRendererPtr, vector<Enemy*> * enemiesTemp, \
	vector<Tower*> * towersTemp, int xpos, int ypos) : Tower(gRendererPtr, enemiesTemp, towersTemp)
{
	//initialize properties (many are Tower protected variables)
	towerX = xpos;
	towerY = ypos;
	damage = 50;
	attackDelay = 2;	//number of times it attacks per minute
	range = 195;
	
	gTower = loadTexture("img/archerTower.png");
	gTowerRect = getRect(gTower, MAX_DIMENSION, towerX, towerY);
	gRange = loadTexture("img/range.png");                          // load in range radius image
    gRangeRect = getRect(gRange, 2*range, towerX, towerY);          // container for range radius with correct sizing
   
}

// render the tower image to the screen
void ArcherTower::render() {
	// only render Range radius if the flag is set (from handleMouseClick())
	if(renderRange) {
		SDL_RenderCopy(*gRenderer, gRange, NULL, &gRangeRect);
	}
	SDL_RenderCopy(*gRenderer, gTower, NULL, &gTowerRect);
}