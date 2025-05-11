#include "GameObject.h"
#include "GameConfig.h"

GameObject::GameObject(Game* r_pGame, point ref, int r_width, int r_height, color fc, color bc) : Drawable (r_pGame, ref, r_width, r_height)
{
	fillColor = fc;
	borderColor = bc;
}

void GameObject::setRefPoint(point p)
{
	RefPoint = p;
}

bool GameObject::isInside() const
{
	// Check if the point is inside the window
	if (  RefPoint.y + height < config.toolBarHeight || RefPoint.y > config.windHeight - config.statusBarHeight) {
		return false;
	}
	return true;
}

// you should implement this function knowing that each game object has refPoint, width and height 
// for simplicity, you can consider all game objects are rectangles
bool GameObject::CollisionDetection(const GameObject& other)
{
	// Check if the two rectangles overlap
	if (RefPoint.x < other.RefPoint.x + other.width &&
		RefPoint.x + width > other.RefPoint.x &&
		RefPoint.y < other.RefPoint.y + other.height &&
		height + RefPoint.y > other.RefPoint.y) {
		return true;
	}
	return false;
}
