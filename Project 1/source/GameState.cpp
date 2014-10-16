#include "GameState.h"
#include "Player.h"
#include "Assets.h"
#include "Bullet.h"
#include "Enemy.h"

int GameState::GetPadding() { return m_padding; }

GameState::GameState(int a_padding, Assets *a_assets)
{
	m_padding = a_padding;
	e_assets  = a_assets;

	m_player = new Player(this, e_assets->Get(ePlayer), g_w/2, 40, 32, 32, 200, 0.15f);
	m_enemy  = new Enemy(e_assets->Get(eEnemy),  40, 250, 32, 32, 120, 0.15f, m_player);
	m_enemy2 = new Enemy(e_assets->Get(eEnemy), 600, 250, 32, 32, 120, 0.15f, m_player);

	for (int i = 0; i < g_maxBullets; ++i)
		m_bullets[i] = nullptr;
}

void GameState::Update(float a_dt)
{
	if (m_player)
		m_player->Update(a_dt); 

	m_enemy->Update(a_dt);
	m_enemy2->Update(a_dt);

	for (int i = 0; i < g_maxBullets; ++i)
		if (m_bullets[i]) 
			m_bullets[i]->Update(a_dt);
}

void GameState::Draw()
{
	if (m_player) m_player->Draw();

	m_enemy->Draw();
	m_enemy2->Draw();

	for (int i = 0; i < g_maxBullets; ++i)
		if (m_bullets[i])	
			m_bullets[i]->Draw();
}

void GameState::SpawnBullet(int a_x, int a_y, float a_speed, int direction)
{
	for (int i = 0; i < g_maxBullets; ++i)
	if (!m_bullets[i] || !m_bullets[i]->IsActive()) 
	{
		if (m_bullets[i] && !m_bullets[i]->IsActive())
		{delete m_bullets[i];}

		m_bullets[i] = new Bullet(this, e_assets->Get(eShot), a_x, a_y, 10, 14, a_speed, direction);
		return;
	}
}

//void GameState::SpawnEnemy(unsigned a_sprite, float a_x, float a_y, int a_w, int a_h, float a_speed, float a_fDelay, Player *a_p)
//{
//	m_enemy = new Enemy(e_assets->Get(eEnemy), 40, 250, 32, 32, 150, 0.15f, m_player);
//}

GameState::~GameState()
{
	delete m_player;
	delete m_enemy;
	delete m_enemy2;

	for (int i = 0; i < g_maxBullets; ++i)
		if (m_bullets[i])
			delete m_bullets[i];

	// Why don't we "delete [] m_bullets;" ?
}


