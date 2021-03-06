#include <MBE/Input/MouseButtonPressedEvent.h>

std::ostream & mbe::event::operator<<(std::ostream & stream, const MouseButtonPressedEvent & event)
{
	stream << "MouseButtonPressedEvent:\tPosition: ";
	stream << event.GetClickPosition().x << ", " << event.GetClickPosition().y;
	stream << "\tButton: ";
	
	assert(mouseButtonStringDictionary.find(event.GetButton()) != mouseButtonStringDictionary.end() && "No string representation could be found for this button");
	stream << mouseButtonStringDictionary.find(event.GetButton())->second;

	stream << " (" << static_cast<unsigned int>(event.GetButton()) << ")";
	return stream;
}