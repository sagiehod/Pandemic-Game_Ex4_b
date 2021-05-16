#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
namespace pandemic{

  class Scientist: public Player{
    public:
      Scientist(Board& board,City city,int n):Player(board, city), _n(n){}
	  Scientist& discover_cure(Color c) override;
	  string role() override {return "Scientist";}

  private:
	  int _n;
  };
}
