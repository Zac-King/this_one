#include "Bullet.h"

Bullet::Bullet(GameState *a_gs, unsigned a_sprite,
	float a_x, float a_y, int a_w, int a_h,
	float a_speed)
{
	e_gs = a_gs;
	m_speed = a_speed;
	m_x = a_x;
	m_y = a_y;
	m_w = a_w;
	m_h = a_h;
	m_sprite = a_sprite;
}

void Bullet::Update(float a_dt)
{
	m_y += m_speed * a_dt;
}

void Bullet::Draw()
{
	MoveSprite(m_sprite, m_x, m_y);
	DrawSprite(m_sprite);
}


bool Bullet::IsActive()
{
	//Where is this function called?
	//Why do we care?
	return m_y > 0 && m_y < g_h;
}