#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
namespace pandemic{
  class Dispatcher: public Player{
    public:
      Dispatcher(Board& board_,City city_):Player(board_,city_){}
      Dispatcher& fly_direct(City c) override;
	  string role() override {return "Dispatcher";}
  };
}
