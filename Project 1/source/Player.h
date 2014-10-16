#pragma once
#include "Decl.h"



class Player : public Entity
{
	float m_speed;

	float m_fDelay, m_fTimer;	// Firing controls
	float m_fSpeed;				// Fire Speed 

	int m_pad; // For boundary collision.
	
	e_direction m_facing = eUp;	// Defualt direction. 
	GameState *e_gs;			// Pointer to GameState

public:
	
	Player(GameState *a_gs, unsigned a_sprite, float a_x, float a_y, int a_w, int a_h, float a_speed, float a_fDelay);
	
	void Update(float a_dt);
	void Draw();
	void Fire();
};