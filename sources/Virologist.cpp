#include "Virologist.hpp"
namespace pandemic{

	Virologist& Virologist::treat(City c)
	{
		if(c != _currentCity && _playCards.find(c) == _playCards.end())
		{
			throw invalid_argument("the virologist has no such a city card at hand\n");
		}

		if(_board[c] == 0)
		{
			throw invalid_argument("city has no disease to treat");
		}

		_playCards.erase(c);

		// if found cure to the disease of this city color
		if (_board.isCureFound(_board.getCityColor(_currentCity)))
		{
			_board[c] = 0;
		}
		else
		{
			_board[c]--;
		}
		return *this;
	}
}
