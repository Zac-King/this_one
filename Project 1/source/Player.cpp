#include "Player.h"
#include "GameState.h"

Player::Player(GameState *a_gs, unsigned a_sprite,
	float a_x, float a_y, int a_w, int a_h, float a_speed, float a_fDelay)
{
	//Setup our variables
	e_gs = a_gs;
	m_x = a_x;
	m_y = a_y;
	m_w = a_w;
	m_h = a_h;
	m_speed = a_speed;
	m_sprite = a_sprite;
	m_fSpeed = 300;		 // Shot speed
	m_fDelay = a_fDelay; // Firing delay
	m_fTimer = 0;        // Firing timer

	m_w2 = m_w / 2; // x +/- m_w2 gives us the left/right side of the ship


	if (e_gs) m_pad = e_gs->GetPadding(); // only use padding if e_gs isn't null
	else m_pad = 0; //otherwise we have no padding, use screen dimensions
}											

void Player::Fire()
{
	if (m_fTimer > m_fDelay) // What are we checking for here? what are these variables for?
	{
		m_fTimer = 0;
		e_gs->SpawnBullet(m_x, m_y, m_fSpeed, m_facing);
	}
}


void Player::Update(float a_dt)
{
	m_fTimer += a_dt; // Why are we incrementing m_fTimer

	if (IsKeyDown('A')) { m_x -= m_speed * a_dt;	m_facing = eLeft;  }
	if (IsKeyDown('D')) { m_x += m_speed * a_dt;	m_facing = eRight; }
	if (IsKeyDown('S')) { m_y -= m_speed * a_dt;    m_facing = eDown;  }
	if (IsKeyDown('W')) { m_y += m_speed * a_dt;    m_facing = eUp;    }
	if (IsKeyDown(' ')) Fire();

	// Check tos ee if we hit a boundary, this is concise- but if you expand
	// it a little bit, it doesn't look much different from what you have done already
	if (m_x <   0 + (m_pad + m_w2)) m_x =   0 + (m_pad + m_w2);
	if (m_x > g_w - (m_pad + m_w2)) m_x = g_w - (m_pad + m_w2);

	if (m_y <   0 + (m_pad + m_h)) m_y =   0 + (m_pad + m_h);
	if (m_y > g_h - (m_pad + m_h)) m_y = g_h - (m_pad + m_h);
}

void Player::Draw()
{
	MoveSprite(m_sprite,m_x, m_y);
	DrawSprite(m_sprite);
}