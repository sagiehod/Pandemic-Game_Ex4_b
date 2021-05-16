#include "Medic.hpp"
namespace pandemic{

Medic& Medic::treat(City c)
{
	Player::treat(c);
	_board[c] = 0;
	return *this;
}

Medic& Medic::drive(City c)
{
	Player::drive(c);
	if(_board.isCureFound(_board.getCityColor(c)))
	{
			_board[c] = 0;
	}
		return *this;
}

Medic& Medic::fly_direct(City c)
{
	Player::fly_direct(c);
	if(_board.isCureFound(_board.getCityColor(c)))
	{
		_board[c] = 0;
	}
	return *this;

}

Medic& Medic::fly_charter(City c)
{
	Player::fly_charter(c);
	if(_board.isCureFound(_board.getCityColor(c)))
	{
		_board[c] = 0;
	}
	return *this;

}

Medic& Medic::fly_shuttle(City c)
{
	Player::fly_shuttle(c);
	if(_board.isCureFound(_board.getCityColor(c)))
	{
		_board[c] = 0;
	}
	return *this;

}

}
