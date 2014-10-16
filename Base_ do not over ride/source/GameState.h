#pragma once
#include "Decl.h"

class GameState
{
	Player *m_player;	  
	Bullet *m_bullets[64]; 
		   
	Assets *e_assets; // What does the e_ mean? See 'decl' for help! 
	int m_padding;	 // Padding + g_w are used to determine movement boundaries	

public:

	GameState(int a_padding, Assets *a_assets);
	~GameState();

	int GetPadding();

	void SpawnBullet(int a_x, int a_y, float a_speed);
	


	void Update(float a_dt);
	void Draw();

};