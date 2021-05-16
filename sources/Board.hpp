#pragma once
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <utility>

#include "City.hpp"
#include "Color.hpp"

namespace pandemic{

struct CityCard
{
  CityCard() = default;

	CityCard(Color p_color, std::unordered_set<City> p_neighbors):
		color(p_color),
		neighbors(std::move(p_neighbors))
	{}

/* copy swap idiom */
  CityCard(const CityCard& other)
  {
    color = other.color;
    neighbors = other.neighbors;
    disease = other.disease;
    hasResearchStation = other.hasResearchStation;
  }

  friend void swap(CityCard& first, CityCard& second)
  {
    using std::swap;
    swap(first.color, second.color);
    swap(first.disease, second.disease);
    swap(first.neighbors, second.neighbors);
    swap(first.hasResearchStation, second.hasResearchStation);
  }

  CityCard& operator=(CityCard other)
  {
    swap(*this, other);
    return *this;
  }

  CityCard(CityCard&& other):CityCard()
  {
    swap(*this, other);
  }

	Color color = Black;
	std::unordered_set<City> neighbors;
	int disease = 0;
	bool hasResearchStation = false;
};

  class Board{

public:
  Board();
  bool is_clean() const;
  void remove_cures();
  int & operator[](City city);
  friend std::ostream& operator<<(std::ostream& os,const Board& board);

  void findCure(Color diseaseColor);
  bool isCureFound(Color diseaseColor) const;
  void buildResearchStation(City c);
  bool hasResearchStation(City c) const;
  Color getCityColor(City c) const;
  bool areConnected(City first, City second) const;

private:
	  std::unordered_map<City, CityCard> _cities;
	  std::unordered_map<Color, bool> _cures;
  };
}
