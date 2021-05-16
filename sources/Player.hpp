#pragma once
#include <set>
#include "City.hpp"
#include "Color.hpp"
#include "Board.hpp"

using namespace std;

namespace pandemic{
  class Player{
  public:

  	Player(Board& b ,City c): _board(b), _currentCity(c){}

    virtual Player& drive(City c);
    virtual Player& fly_direct(City c);
    virtual Player& fly_charter(City c);
    virtual Player& fly_shuttle(City c);

    virtual Player& build();
    virtual Player& discover_cure(Color c);
    virtual Player& treat(City c);

    Player& take_card(City c);
    virtual string role() {return "Player";}

  virtual ~Player() = default;

  protected:
	Board& _board; /* aggregation (being held, but also exist outside) */
	City _currentCity;
	set<City> _playCards;
  };
}
