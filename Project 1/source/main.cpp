
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

	Assets *assets = new Assets;
	assets->LoadSprite("./images/Player_TestSprite.png", 32, 32, ePlayer);
	assets->LoadSprite("./images/Enemy_TestSprite.png", 32, 32, eEnemy);
	assets->LoadSprite("./images/Bullet_TestSprite.png", 8, 8, eShot);
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
