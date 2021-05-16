#include "Researcher.hpp"

constexpr int CARDS_TO_THROW = 5;

namespace pandemic{
	Researcher& Researcher::discover_cure(Color c) {
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
}
