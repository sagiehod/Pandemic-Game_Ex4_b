#include "FieldDoctor.hpp"
namespace pandemic{
  FieldDoctor& FieldDoctor::treat(City c)
    {
  	    if(_currentCity != c && !_board.areConnected(_currentCity, c))
        {
	        throw invalid_argument("cities are not connected\n");
        }

	    if(_board[c] == 0)
	    {
		    throw invalid_argument("city has no disease to treat");
	    }
	    // if found cure to the disease of this city color
	    if (_board.isCureFound(_board.getCityColor(c)))
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
