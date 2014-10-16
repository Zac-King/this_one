
#if !defined(OSX)
	#include <crtdbg.h>
#endif


#include "Decl.h"
#include "GameState.h"
#include "Assets.h"
#include "Player.h"


int main(int argc, char* argv[])
{
	Initialise(g_w, g_h, false, "Space Invaders");
	SetBackgroundColour(SColour(0x00, 0x00, 0x00, 0xFF));


	// We set up our assets class here.
	Assets *assets = new Assets;
	// And can use it to load in all of our images.
	assets->LoadSprite("./images/cannon.png",		 64, 32, ePlayer);
	assets->LoadSprite("./images/invaders/invaders_5_00.png", 10, 14, eShot);

	// After assets are loaded in, the gameState can use them to setup all of our
	// other game objects.
	GameState *myGame = new GameState(20, assets);


	do
	{
		ClearScreen();
		float dt = GetDeltaTime();

		// Simply update and draw.
		myGame->Update(dt);
		myGame->Draw();

	} while (FrameworkUpdate() == false);


	// Manually delete the game and assets to ensure memory is freed up properly.
	delete myGame;
	delete assets;

	Shutdown();
	return 0;
}
