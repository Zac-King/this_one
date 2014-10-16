#pragma once
#include "Decl.h"

class Player
{
	float m_x, m_y; // Position
	int m_w, m_h; // Dimensions

	float m_speed;
	unsigned m_sprite;
	
	GameState *e_gs;	// Reference pointer to GameState

	float m_fDelay, m_fTimer; // Firing controls
	float m_fSpeed;

	int m_w2; // half width
	int m_pad; // For boundary collision.

public:

	Player(GameState *a_gs, unsigned a_sprite,
		   float a_x, float a_y, int a_w, int a_h,
		   float a_speed, float a_fDelay);
	
	
	void Update(float a_dt);
	
	
	void Draw();

	
	void Fire();
};