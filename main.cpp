#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"
#define OLC_PGEX_QUICKGUI
#include "pgex/olcPGEX_QuickGUI.h"

#include "iostream"
#include <stdio.h>
#include <string>
#include <vector>
#include "BaseEntity.h"
#include "Transform2D.h"
#include "PhyicsComponent.h"
#include "Vector3D.h"

//copied and modified from		https://www.codespeedy.com/hsv-to-rgb-in-cpp/
Vector3D HSVtoRGB(float H, float S, float V) {
	if (H > 360 || H < 0 || S>100 || S < 0 || V>100 || V < 0) {
		return Vector3D();
	}
	float s = S / 100;
	float v = V / 100;
	float C = s * v;
	float X = C * (1 - abs(fmod(H / 60.0, 2) - 1));
	float m = v - C;
	float r, g, b;
	if (H >= 0 && H < 60) {
		r = C, g = X, b = 0;
	}
	else if (H >= 60 && H < 120) {
		r = X, g = C, b = 0;
	}
	else if (H >= 120 && H < 180) {
		r = 0, g = C, b = X;
	}
	else if (H >= 180 && H < 240) {
		r = 0, g = X, b = C;
	}
	else if (H >= 240 && H < 300) {
		r = X, g = 0, b = C;
	}
	else {
		r = C, g = 0, b = X;
	}
	Vector3D col((r + m) * 255, (g + m) * 255, (b + m) * 255);
	return col;
}

class MainGame : public olc::PixelGameEngine
{
protected:
	olc::QuickGUI::Manager guiManager;
	//buttons
	olc::QuickGUI::Button* play = nullptr;
	olc::QuickGUI::Button* quit = nullptr;

	std::vector<BaseEntity> entities;
	const float physRate = 1.0f/30 ;
	float physTime = 0;
	void UpdateEntities(float timeElapsed) {
		physTime += timeElapsed;
		for (int i = 0; i < entities.size(); i++)
			entities[i].Update(timeElapsed);
		while (physTime > physRate) {
			for (int i = 0; i < entities.size(); i++) {
				entities[i].FixedUpdate();
			}
			physTime -= physRate;
		}
	}
	float H = 0;
public:
	MainGame()
	{
		// Name your application
		sAppName = "GAME: The game";
	}

public:
	bool OnUserCreate() override
	{
		play = new olc::QuickGUI::Button(guiManager, "play game", { 0.0f, 0.0f }, { 75.0f,30.0f });
		quit = new olc::QuickGUI::Button(guiManager, "quit game", { 0.0f, 30.0f }, { 75.0f,30.0f });

		BaseEntity* e = new BaseEntity();
		Transform2D* t = new Transform2D();
		PhyicsComponent* phys = new PhyicsComponent();

		t->SetPosition(5, 5);
		e->AddComponent(*t);
		e->AddComponent(*phys);
		entities.push_back(*e);
		// Called once at the start, so create things here
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		guiManager.Update(this);
		H += fElapsedTime*20;
		if (H > 360)
			H -= 360;
		Vector3D rgb = HSVtoRGB(H, 100, 100);
		Clear(olc::Pixel(rgb.x, rgb.y, rgb.z));
		
		DrawString({ ScreenWidth() / 2 - (GetTextSize("GAMING").x * 3) / 2, ScreenHeight() / 2 }, "GAMING", olc::WHITE, 3);
		DrawString({ ScreenWidth() / 2 - (GetTextSize("The game").x * 2) / 2, ScreenHeight() / 2 + (GetTextSize("GAMING").y * 3) + 1 }, "The game", olc::WHITE, 2);
		DrawString({ ScreenWidth() / 2 - (GetTextSize("(an epic game)").x) / 2, ScreenHeight() / 2 + ((GetTextSize("GAMING").y * 3) + GetTextSize("The game").y * 3) }, "(an epic game)", olc::WHITE, 1);
		DrawString({ ScreenWidth() - (GetTextSize("(c) toaster studios").x),ScreenHeight() - (GetTextSize("(c) toaster studios").y)}, "(c) toaster studios", olc::WHITE, 1);
		guiManager.Draw(this);
		if (play->bPressed) {
			Vector2D *pos = entities[0].GetComponent<Transform2D>()->GetPosition();
			PhyicsComponent *phys = entities[0].GetComponent<PhyicsComponent>();

			printf("{%f; %f}", pos->x, pos->y);
			printf("{Velocity: {%f; %f} }\n", phys->GetVelocity().x, phys->GetVelocity().y);
		}
		if (quit->bPressed) {
			int a = 0;
			return 1 / a;
		}
		// Called once per frame, draws random coloured pixels
		//for (int x = 0; x < ; x++)
		//	for (int y = 0; y < ScreenHeight(); y++)
		//		Draw(x, y, olc::Pixel(rand() % 256, rand() % 256, rand() % 256));
		
		UpdateEntities(fElapsedTime);
		return true;
	}
};

int main()
{
	MainGame demo;
	if (demo.Construct(256, 240, 4, 4))
		demo.Start();
	return 0;
}