#include "DisplayScreen.hpp"

DisplayScreen::DisplayScreen(void) {}

void DisplayScreen::show(Text screenText, bool isSound, RenderWindow& window)
{
	window.draw(mScreenBack);
	window.draw(screenText);
	if (isSound)
	{
		mAudio.play();
	}
}