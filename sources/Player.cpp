#include "Player.hpp"

constexpr int CARDS_TO_THROW = 5;


namespace pandemic{

	Player& Player::drive(City c)
	{
		if(_board.areConnected(_currentCity, c))
		{
			_currentCity = c;
		}
		else
		{
			throw invalid_argument("cities are not connected\n");
		}
			return *this;
	}

	Player& Player::fly_direct(City c)
	{
		if(c == _currentCity && _playCards.find(c) != _playCards.end())
		{
			throw invalid_argument("cannot fly from city to itself\n");
		}

		if(_playCards.find(c) != _playCards.end())
		{
			_playCards.erase(c);
			_currentCity = c;
		}
		else
		{
			throw invalid_argument("player has no such a city card at hand\n");
		}
		return *this;

	}

	Player& Player::fly_charter(City c)
	{
		if(c == _currentCity)
		{
			throw invalid_argument("cannot fly from city to itself\n");
		}

		if(_playCards.find(_currentCity) != _playCards.end())
		{
			_playCards.erase(_currentCity);
			_currentCity = c;
		}
		else
		{
			throw invalid_argument("player has no such a city card at hand\n");
		}
		return *this;
	}

	Player& Player::fly_shuttle(City c)
	{
		if(c == _currentCity)
		{
			throw invalid_argument("cannot fly from city to itself\n");
		}

		if(_board.hasResearchStation(_currentCity) && _board.hasResearchStation(c))
		{
			_currentCity = c;
		}
		else
		{
			throw invalid_argument("current city or destination city has no research station");
		}
		return *this;
	}

	Player& Player::build()
	{
		if(!_board.hasResearchStation(_currentCity))
		{
			if(_playCards.find(_currentCity) != _playCards.end())
			{
				_playCards.erase(_currentCity);
				_board.buildResearchStation(_currentCity);
			}
			else
			{
				throw invalid_argument("cannot build, no suitable card for current city");
			}
		}
		return *this;
	}

	Player& Player::discover_cure(Color c)
	{
		if(!_board.hasResearchStation(_currentCity))
		{
			throw invalid_argument("current city has no research station\n");
		}

		if(!_board.isCureFound(c))
		{
			unordered_set<City> cardsToDrop;
			// find all cards with the specified color
			for(const auto& card : _playCards)
			{
				if(_board.getCityColor(card) == c)
				{
					cardsToDrop.insert(card);
				}
			}
			if(cardsToDrop.size() < CARDS_TO_THROW)
			{
				throw invalid_argument("not enough cards at player hand for cure\n");
			}

			auto i = 0;
			for(auto iter = cardsToDrop.begin(); i < CARDS_TO_THROW ; ++iter, ++i)
			{
				_playCards.erase(*iter);
			}
			_board.findCure(c);
		}
		return *this;
	}

	Player& Player::treat(City c)
	{
		if(c != _currentCity)
		{
			throw invalid_argument("the player is not in the currnet city\n");
		}

		if(_board[_currentCity] == 0)
		{
			throw invalid_argument("city has no disease to treat");
		}
		// if found cure to the disease of this city color
		if (_board.isCureFound(_board.getCityColor(_currentCity)))
		{
			_board[_currentCity] = 0;
		}
		else
		{
			_board[_currentCity]--;
		}
		return *this;
	}

	Player& Player::take_card(City c)
	{
		_playCards.insert(c);
		return *this;
	}
}
