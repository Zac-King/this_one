#include "Assets.h"

Assets::Assets()
{
	// What is g_maxSprites?
	for (int i = 0; i < g_maxSprites; ++i)
	{
		sprites[i] = nullptr;	// What are we doing here?
		if (i < eSize) assoc[i] = nullptr;
	}
	nSprites = 0;	
}


unsigned Assets::Get(eSpriteFlag s)
{
	//Take a look at where this Get function is used-
	//What is happening?
	return *assoc[s];
}


unsigned Assets::LoadSprite(char *path, int w, int h, eSpriteFlag s, bool center)
{
	if (nSprites < 64)
	{
		// Put the sprite ID on the Heap
		unsigned *t = new unsigned(CreateSprite(path, w, h, center));

		sprites[nSprites++] = t;  // What is sprites storing?
		if (s != eNone)	
			assoc[s] = t; // What is assoc storing? What is 's'?			

		return *t; // What are we returning?
	}
	return 0;
}

Assets::~Assets()
{
	for (int i = 0; i < g_maxSprites; ++i)
		if (sprites[i])	// What are we checking for?
		{
			DestroySprite(*sprites[i]);						
			delete sprites[i];
		}
}