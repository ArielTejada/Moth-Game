#pragma once

#include "Moth.h"
#include "Entity.h"

class SpringApp : public Moth::MothApp
{
public:
	SpringApp();

	virtual void OnUpdate() override;

	bool Collide(const Entity& one, const Entity& another);

private:
	Entity background{ {"Assets/Images/Background1.png"}};
	Entity healthBar{ {"Assets/Images/HealthFull.png", "Assets/Images/Health1Hit.png", "Assets/Images/Health2Hit.png" }};
	Entity mHero{ {"Assets/Images/MothLeft.png", "Assets/Images/MothLeftFlap.png", "Assets/Images/MothRight.png",
		"Assets/Images/MothRightFlap.png", "Assets/Images/MothUp.png", "Assets/Images/MothUpFlap.png"} };
	Entity umbrella{ {"Assets/Images/umbrella.png"}};
	std::vector<Entity> mDangers{ {{"Assets/Images/drop.png"}}, { {"Assets/Images/drop.png"}}, 
		{ {"Assets/Images/drop.png"}}, { {"Assets/Images/drop.png"}}, { {"Assets/Images/drop.png"}}, { {"Assets/Images/drop.png"}} };
	Entity win_Lose_Screen{ {"Assets/Images/TransparentScreen.png", "Assets/Images/GameOver.png", "Assets/Images/YouWin.png"}};
	int mEnemyVSpeed0{ -3 };
	int mEnemyVSpeed1{ -7 };
	int mEnemyVSpeed2{ -6 };
	int mEnemyVSpeed3{ -4 };
	int mEnemyVSpeed4{ -3 };
	int mEnemyVSpeed5{ -6 };

	int mHorizontalSpeed{ 0 };  
	int mVerticalSpeed{ 0 };
};