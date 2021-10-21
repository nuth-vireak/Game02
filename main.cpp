#include "Game.h"

//------------------------------------------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------------------------------------------
int main()
{
	std::srand(static_cast<unsigned>(time(NULL)));							// Initialize random seed
	Game game;																// Initialize game object

	//Main game loop
	while (game.running())													// Detect window is running
	{
		game.update();
		game.render();
	}
	
	//End of application
	return 0;
}