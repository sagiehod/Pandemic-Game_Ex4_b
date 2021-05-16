#include "OperationsExpert.hpp"
namespace pandemic{
	OperationsExpert& OperationsExpert::build()
    {
	    if(!_board.hasResearchStation(_currentCity))
	    {
		    _board.buildResearchStation(_currentCity);
		}
		return *this;
    }
}
