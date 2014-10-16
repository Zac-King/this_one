#pragma once

#include "Aie.h"

/*
	Throughout this example project, various prefixes are used.

	g_ is for global		    (outside of all functions)
	m_ is for member variable   (in a class definition)
	e_ is an external reference (unmanaged pointer- a pointer we won't delete)
	a_ is for argument          (a function parameter)
*/

// These globals are for the screen width and  height.
// These names aren't very descriptive, but a global width/height
// Isn't likely to mean anything other than the screen dimensions.
const int g_w = 672;
const int g_h = 780;
// These are used for setting up the maximum sizes of static arrays
// for classes.
const int g_maxSprites = 64; // The most number of sprites we can manage.
const int g_maxBullets = 64; // The most number of bullets we can manage.s


/*
	This enum is used in an associative array as a part of
	the Asset class. Check out Assets.h for more details.
*/
enum eSpriteFlag { eNone,
				   ePlayer, eShot, eEnemy, // Add more enums here! background, title bar, etc.
				   eSize };


// Forward Declarations, this allows us to create pointers without
// knowing anything about the class.
class Assets;
class GameState;
class Player;
class Bullet;

