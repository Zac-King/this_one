#include "Bullet.h"
#include "Player.h"

Bullet::Bullet(GameState *a_gs, unsigned a_sprite,
	float a_x, float a_y, int a_w, int a_h,
	float a_speed, int a_direction)
{
	e_gs = a_gs;
	m_speed = a_speed;
	m_x = a_x;
	m_y = a_y;
	m_w = a_w;
	m_h = a_h;
	m_sprite = a_sprite;
	m_direction = a_direction;
}

void Bullet::Update(float a_dt)
{
	switch (m_direction)
	{
	case eUp   : m_y += m_speed * a_dt; break;
	case eDown : m_y -= m_speed * a_dt; break;
	case eLeft : m_x -= m_speed * a_dt; break;
	case eRight: m_x += m_speed * a_dt; break;
	}
}

void Bullet::Draw()
{
	MoveSprite(m_sprite, m_x, m_y);
	DrawSprite(m_sprite);
}


bool Bullet::IsActive()
{
	return m_x > 0 && m_x < g_w && m_y < g_h && m_y > 0;
}