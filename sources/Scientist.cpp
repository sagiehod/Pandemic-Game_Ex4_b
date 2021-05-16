#include "Scientist.hpp"
namespace pandemic{

	Scientist& Scientist::discover_cure(Color c)
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
		    if(cardsToDrop.size() < _n)
		    {
			    throw invalid_argument("not enough cards at player hand for cure\n");
		    }

		    auto i = 0;
		    for(auto iter = cardsToDrop.begin(); i < _n ; ++iter, ++i)
		    {
			    _playCards.erase(*iter);
		    }
		    _board.findCure(c);
	    }
	    return *this;

    }
}
