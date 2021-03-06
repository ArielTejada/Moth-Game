#include "SpringApp.h"
#include "Renderer.h"

SpringApp::SpringApp()
{
	SetKeyPressedCallback([this](const Moth::KeyPressedEvent& e) {
			switch (e.GetKeyCode())
			{
			case MOTH_KEY_LEFT:
				mHorizontalSpeed = -10;
				mHero.SetActiveImage(0);
				break;
			case MOTH_KEY_RIGHT:
				mHorizontalSpeed = 10;
				mHero.SetActiveImage(2);
				break;
			case MOTH_KEY_UP:
				mVerticalSpeed = 10;
				mHero.SetActiveImage(4);
				break;
			case MOTH_KEY_DOWN:
				mVerticalSpeed = -10;
				mHero.SetActiveImage(4);
				break;
			case MOTH_KEY_SPACE:
				if (win_Lose_Screen.GetActiveImage() == 1 || win_Lose_Screen.GetActiveImage() == 2)
				{
					exit(0);
				}
					
			case MOTH_KEY_ENTER:
				if (win_Lose_Screen.GetActiveImage() == 1 || win_Lose_Screen.GetActiveImage() == 2)
				{
					mHero.SetX(0);
					mHero.SetY(0);
					win_Lose_Screen.SetActiveImage(0);
					healthBar.SetActiveImage(0);
				}
					
			}
			});

	SetKeyReleasedCallback([this](const Moth::KeyReleasedEvent& e) {
			mHorizontalSpeed = 0;
			mVerticalSpeed = 0;
		});

	int x = 250;
	for (int i = 0; i < 6; i++)
	{
		mDangers[i].SetX(x);
		mDangers[i].SetY(400);
		x += 150;
	}
}

void SpringApp::OnUpdate()
{
	mHero.SetX(mHero.GetX() + mHorizontalSpeed);
	mHero.SetY(mHero.GetY() + mVerticalSpeed);

	// Moth flaps wings as it moves through map depending on its location

	if ((mHero.GetActiveImage() == 0) && (0 == mHero.GetX() % 30))
	{
		mHero.SetActiveImage(1);
	} 

	else if ((mHero.GetActiveImage() == 1) && (0 == mHero.GetX() % 40))
	{
		mHero.SetActiveImage(0);
	}
	
	else if ((mHero.GetActiveImage() == 2) && (0 == mHero.GetX() % 20))
	{
		mHero.SetActiveImage(3);
	}

	else if ((mHero.GetActiveImage() == 3) && (0 == mHero.GetX() % 50))
	{
		mHero.SetActiveImage(2);
	}

	else if ((mHero.GetActiveImage() == 4) && (0 == mHero.GetY() % 30))
	{
		mHero.SetActiveImage(5);
	}

	else if ((mHero.GetActiveImage() == 5) && (0 == mHero.GetY() % 50))
	{
		mHero.SetActiveImage(4);
	}

	if (mDangers[0].GetY() < 0)
		mDangers[0].SetY(620);
	else if (mDangers[0].GetY() > Moth::GameWindow::GetWindow()->GetHeight() - mDangers[0].GetHeight())
		mEnemyVSpeed0 *= -1;

	mDangers[0].SetY(mDangers[0].GetY() + mEnemyVSpeed0);

	if (mDangers[1].GetY() < 0)
		mDangers[1].SetY(620);
	else if (mDangers[1].GetY() > Moth::GameWindow::GetWindow()->GetHeight() - mDangers[1].GetHeight())
		mEnemyVSpeed1 *= -1;

	mDangers[1].SetY(mDangers[1].GetY() + mEnemyVSpeed1);

	if (mDangers[2].GetY() < 0)
		mDangers[2].SetY(620);
	else if (mDangers[2].GetY() > Moth::GameWindow::GetWindow()->GetHeight() - mDangers[2].GetHeight())
		mEnemyVSpeed2 *= -1;

	mDangers[2].SetY(mDangers[2].GetY() + mEnemyVSpeed2);

	if (mDangers[3].GetY() < 0)
		mDangers[3].SetY(620);
	else if (mDangers[3].GetY() > Moth::GameWindow::GetWindow()->GetHeight() - mDangers[3].GetHeight())
		mEnemyVSpeed3 *= -1;

	mDangers[3].SetY(mDangers[3].GetY() + mEnemyVSpeed3);

	if (mDangers[4].GetY() < 0)
		mDangers[4].SetY(620);
	else if (mDangers[4].GetY() > Moth::GameWindow::GetWindow()->GetHeight() - mDangers[4].GetHeight())
		mEnemyVSpeed4 *= -1;

	mDangers[4].SetY(mDangers[4].GetY() + mEnemyVSpeed4);

	if (mDangers[5].GetY() < 0)
		mDangers[5].SetY(620);
	else if (mDangers[5].GetY() > Moth::GameWindow::GetWindow()->GetHeight() - mDangers[5].GetHeight())
		mEnemyVSpeed5 *= -1;

	mDangers[5].SetY(mDangers[5].GetY() + mEnemyVSpeed5);

	// lose condition
	for (int i = 0; i < 6; i++)
	{
		if (Collide(mHero, mDangers[i]) && (healthBar.GetActiveImage() == 0))
		{
			healthBar.SetActiveImage(1);
			mDangers[i].SetY(620);
		}

		if (Collide(mHero, mDangers[i]) && (healthBar.GetActiveImage() == 1))
		{
			healthBar.SetActiveImage(2);
			mDangers[i].SetY(620);
		}

		if (Collide(mHero, mDangers[i]) && (healthBar.GetActiveImage() == 2))
		{
			win_Lose_Screen.SetActiveImage(1);
		}
	}

	// win condition
	if (mHero.GetX() > Moth::GameWindow::GetWindow()->GetWidth() && (mHero.GetY() < Moth::GameWindow::GetWindow()->GetHeight() - 400))
	{
		win_Lose_Screen.SetActiveImage(2);
	}

	background.Draw();
	mHero.Draw();
	umbrella.SetX(800);
	umbrella.Draw();
	healthBar.SetY(600);
	healthBar.Draw();
	win_Lose_Screen.Draw();

	for (int i = 0; i < 6; i++)
	{
		mDangers[i].Draw();
	}

}

bool SpringApp::Collide(const Entity& one, const Entity& another)
{
	int oneLeft{ one.GetX() };
	int oneRight{ one.GetX() + one.GetWidth()};
	int anotherLeft{ another.GetX() };
	int anotherRight{ another.GetX() + another.GetWidth() };

	int oneBottom{ one.GetY() };
	int oneTop{ one.GetY() + one.GetHeight() };
	int anotherBottom{ another.GetY() };
	int anotherTop{ another.GetY() + another.GetHeight() };

	bool collideX{ false };
	if (((oneLeft <= anotherLeft) && (anotherLeft <= oneRight)) ||
		((anotherLeft <= oneLeft) && (oneLeft <= anotherRight)))
		collideX = true;

	bool collideY{ false };
	if (((oneBottom <= anotherBottom) && (anotherBottom <= oneTop)) ||
		((anotherBottom <= oneBottom) && (oneBottom <= anotherTop)))
		collideY = true;

	return collideX && collideY;
}