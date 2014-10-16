#pragma once
#include "Decl.h"

// Similar to player, see player for anything that overlaps
class Bullet
{
	float m_x, m_y;		
	int m_w, m_h;		

	float m_speed;
	unsigned m_sprite;

	GameState *e_gs;	

public:

	Bullet(GameState *a_gs, unsigned a_sprite,
		float a_x, float a_y, int a_w, int a_h,
		float a_speed);

	void Update(float a_dt);
	void Draw();
	bool IsActive();
};