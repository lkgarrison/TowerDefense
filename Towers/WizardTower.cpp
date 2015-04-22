/* CSE 20212
 * Final Project
 * WizardTower.cpp
 * constructors and member functions
*/

#include "WizardTower.h"

//constructor that initializes an WizardTower (arguments = position)
WizardTower::WizardTower( SDL_Renderer** gRendererPtr, vector<Enemy> * enemiesTemp, int xpos, \
	int ypos) : Tower(gRendererPtr, enemiesTemp)
{
	//initialize private variables
	towerX = xpos;
	towerY = ypos;
	numKills = 0;
	damage = 50;
	attackDelay = 3;	//number of times it attacks per minute
	range = 160;
	cost = 100;
	gRenderer = gRendererPtr;
	enemies = enemiesTemp;

	gTower = loadTexture("img/wizardTower.png");
	gTowerRect = getRect(gTower, MAX_DIMENSION, towerX, towerY);	
}

// render the tower image to the screen
void WizardTower::render()
{
	SDL_RenderCopy(*gRenderer, gTower, NULL, &gTowerRect);
}
/*void WizardTower::attack()
{
	if (inRange(towerX, towerY, radius))
	{
		//attack the enemy
	}
}
double WizardTower::getDPS()
{
	return ((attackSpeed/60.0)*damage);
}
double WizardTower::getRadius()
{
	return radius;
}
int WizardTower::getCost()
{
	return cost;
}*/
