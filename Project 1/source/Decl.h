#pragma once
#include "Aie.h"
#include <cmath>

const int g_w = 782;		// Global Screen Width
const int g_h = 672;		// Global Screen Height

const int g_maxSprites = 64; // Global Sprite max
const int g_maxBullets = 64; // Global Bullet max

enum eSpriteFlag { eNone, ePlayer, eShot, eEnemy, eSize };
enum e_direction { eUp, eDown, eLeft, eRight };

// Forward Declarations
class Assets;
class GameState;
class Player;
class Enemy;
class Bullet;


class Entity
{
protected:
	float m_x, m_y;	// Position
	float m_speed;
	int m_h, m_w;	// Dimensions
	int m_w2;  // Half width
	unsigned m_sprite;

public:
	virtual void Update(float a_dt)	{}
	virtual void Draw()	{}
	virtual void onHit()	{}

	int getX() { return m_x; }
	int getY() { return m_y; }

	int distanceBetween(const Entity *e)
	{
		return sqrt((m_x - e->m_x)*(m_x - e->m_x) + (m_y - e->m_y)*(m_y - e->m_y));
	}
};