#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
namespace pandemic{
  class Researcher: public Player{
    public:
      Researcher(Board& board_,City city_):Player(board_,city_){}
	  Researcher& discover_cure(Color c) override;
	  string role() override {return "Researcher";}
  };
}
