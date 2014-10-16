#include "GameState.h"
#include "Player.h"
#include "Assets.h"
#include "Bullet.h"

int GameState::GetPadding() { return m_padding; }

GameState::GameState(int a_padding, Assets *a_assets)
{
	m_padding = a_padding;
	e_assets  = a_assets;

	m_player = new Player(this, e_assets->Get(ePlayer), g_w/2, 40, 64, 32, 150, 0.25f);

	for (int i = 0; i < g_maxBullets; ++i)
		m_bullets[i] = nullptr;
}

void GameState::Update(float a_dt)
{
	if (m_player)// What is this condition checking for?
		m_player->Update(a_dt); 

	for (int i = 0; i < g_maxBullets; ++i)
		if (m_bullets[i]) 
			m_bullets[i]->Update(a_dt);

}
void GameState::Draw()
{
	if (m_player) m_player->Draw();

	for (int i = 0; i < g_maxBullets; ++i)
		if (m_bullets[i])	// What is this condition checking for?
			m_bullets[i]->Draw();
}

void GameState::SpawnBullet(int a_x, int a_y, float a_speed)
{
	for (int i = 0; i < g_maxBullets; ++i)
	if (!m_bullets[i] || !m_bullets[i]->IsActive()) // What is this condition checking?
	{
		if (m_bullets[i] && !m_bullets[i]->IsActive()) // What is this condition checking?
		{
			delete m_bullets[i];
		}
		m_bullets[i] = new Bullet(this, e_assets->Get(eShot), a_x, a_y, 10, 14, a_speed);
		return;
	}
}

GameState::~GameState()
{
	delete m_player;

	for (int i = 0; i < g_maxBullets; ++i)
		if (m_bullets[i])
			delete m_bullets[i];

	// Why don't we "delete [] m_bullets;" ?
}