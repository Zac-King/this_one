#pragma once
#include "Decl.h"

/*
	A class used for two purposes:

	Storing ALL references to ALL sprites loaded in.
	That way when it gets deleted, we an appropriately remove
	all those sprites from memory!

	The other thing is to provide easy access to specific sprites.
	We accomplish this using two separate arrays of pointers.
*/
class Assets
{
	unsigned *sprites[g_maxSprites];	// Static Array of Pointers
	unsigned *assoc[eSize];				// Static Array of Pointers
	int nSprites;						// Number of sprites

public:

	Assets();
	unsigned Get(eSpriteFlag s);	// Get an image that has a Flag
	unsigned LoadSprite(char *path, int w, int h, eSpriteFlag s = eNone, bool center = true);
	~Assets();
};