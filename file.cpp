/* 
01/21/2017
*/
#include <stdio.h>
#include <joystick.hpp> 

int main()
{

	bool connected = sf::Joystick::isConnected(0);


	// Check if the joystick is connected. 
	if (connected) {
		// Check the number of buttons of the joystick.
		unsigned int buttonCount = sf::Joystick::getButtonCount(0);
		
		
		// check if joystick number 0 has a Z axis
		bool hasZ = sf::Joystick::hasAxis(0, sf::Joystick::Z);

		// is button 1 of joystick number 0 pressed?
		if (sf::Joystick::isButtonPressed(0, 1))
		{
			// Move up!
		} else if (sf::Joystick::isButtonPressed(0,2)) {
			// Move down!
		} else if (sf::Joystick::isButtonPressed(0,3)) {
			// Move left!
		} else if (sf::Joystick::isButtonPressed(0,4)) {
			// right
		} else {
			// Wrong direction.
		}

		// what's the current position of the X and Y axes of joystick number 0?
		float x = sf::Joystick::getAxisPosition(0, sf::Joystick::X);
		float y = sf::Joystick::getAxisPosition(0, sf::Joystick::Y);
		character.move(x, y);



	} else {
		// The joystick is not connected
		return 1; 
	} 
	
	
	
	
	
	return 0;
}