#pragma once
#include "Enemy.h"
#include "Player.h"

Enemy::Enemy(unsigned a_sprite, float a_x, float a_y, int a_w, int a_h, float a_speed, float a_fDelay, Player *a_p)
{
	m_x = a_x;
	m_y = a_y;
	m_w = a_w;
	m_h = a_h;
	m_speed = a_speed;
	m_sprite = a_sprite;
	m_target = a_p;
}

void Enemy::Pursue(float a_dt)
{
	if ((m_target->getX()) - m_x < 20) m_x -= m_speed * a_dt;	//Move towrads Target's X coordinates 
	if (m_x - (m_target->getX()) < 20) m_x += m_speed * a_dt;

	if ((m_target->getY()) - m_y < 20) m_y -= m_speed * a_dt;	//Move towrads Target's Y coordinates 
	if (m_y - (m_target->getY()) < 20) m_y += m_speed * a_dt;
}

//Distance formula?
/*
	sqrt((x-x1)*(x-x1) + (y-y1)*(y-y1))
*/

void Enemy::Update(float a_dt)
{
	if (distanceBetween(m_target) < 150) // Sensing range
		Pursue(a_dt);
}

void Enemy::Draw()
{
	MoveSprite(m_sprite, m_x, m_y);
	DrawSprite(m_sprite);
}