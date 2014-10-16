#pragma once
#include "Decl.h"

class Enemy : public Entity
{
	/*
	float m_x, m_y;	// Position
	int m_h, m_w;	// Dimensions
	int m_w2;  // Half width
	*/
	float m_fDelay;
	Player *m_target;

public:
	Enemy(unsigned a_sprite, float a_x, float a_y, int a_w, int a_h, float a_speed, float a_fDelay, Player *a_p);
	void Update(float a_dt);
	void Draw();
	void Pursue(float a_dt);
	void Attack();
	void Dead();

};