#include "Dispatcher.hpp"
namespace pandemic{

	Dispatcher& Dispatcher::fly_direct(City c)
	{
		if(c == _currentCity)
		{
			throw invalid_argument("cannot fly from city to itself\n");
		}

		if(_board.hasResearchStation(_currentCity))
		{
			_currentCity = c;
		}
		else if(_playCards.find(c) != _playCards.end())
		{
			_playCards.erase(c);
			_currentCity = c;
		}
		else
		{
			throw invalid_argument("player has no such a city card at hand and no research station\n");
		}

        return *this;
    }
}
