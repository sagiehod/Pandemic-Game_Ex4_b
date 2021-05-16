#include <algorithm>
#include "Board.hpp"

namespace pandemic{

	Board::Board()
	{
		/* initialize neighbors graph */
		_cities[Algiers] = {Black, {Madrid, Paris, Istanbul, Cairo}};
		_cities[Atlanta] = {Blue,{Chicago, Miami, Washington}};
		_cities[Baghdad] = {Black,{Tehran, Istanbul, Cairo, Riyadh, Karachi}};
		_cities[Bangkok] = {Red,{Kolkata, Chennai, Jakarta, HoChiMinhCity, HongKong}};
		_cities[Beijing] = {Red,{Shanghai, Seoul}};
		_cities[Bogota] = {Yellow,{MexicoCity, Lima, Miami, SaoPaulo, BuenosAires}};
		_cities[BuenosAires] = {Yellow,{Bogota, SaoPaulo}};
		_cities[Cairo] = {Black,{Algiers, Istanbul, Baghdad, Khartoum, Riyadh}};
		_cities[Chennai] = {Black,{Mumbai, Delhi, Kolkata, Bangkok, Jakarta}};
		_cities[Chicago] = {Blue,{SanFrancisco, LosAngeles, MexicoCity, Atlanta, Montreal}};
		_cities[Delhi] = {Black,{Tehran, Karachi, Mumbai, Chennai, Kolkata}};
		_cities[Essen] = {Blue,{London, Paris, Milan, StPetersburg}};
		_cities[HoChiMinhCity] = {Red,{Jakarta, Bangkok, HongKong, Manila}};
		_cities[HongKong] = {Red,{Bangkok, Kolkata, HoChiMinhCity, Shanghai, Manila, Taipei}};
		_cities[Istanbul] = {Black,{Milan, Algiers, StPetersburg, Cairo, Baghdad, Moscow}};
		_cities[Jakarta] = {Red,{Chennai, Bangkok, HoChiMinhCity, Sydney}};
		_cities[Johannesburg] = {Yellow,{Kinshasa, Khartoum}};
		_cities[Karachi] = {Black,{Tehran, Baghdad, Riyadh, Mumbai, Delhi}};
		_cities[Khartoum] = {Yellow,{Cairo, Lagos, Kinshasa, Johannesburg}};
		_cities[Kinshasa] = {Yellow,{Lagos, Khartoum, Johannesburg}};
		_cities[Kolkata] = {Black,{Delhi, Chennai, Bangkok, HongKong}};
		_cities[Lagos] = {Yellow,{SaoPaulo, Khartoum, Kinshasa}};
		_cities[Lima] = {Yellow,{MexicoCity, Bogota, Santiago}};
		_cities[London] = {Blue,{NewYork, Madrid, Essen, Paris}};
		_cities[LosAngeles] = {Yellow,{SanFrancisco, Chicago, MexicoCity, Sydney}};
		_cities[Madrid] = {Blue,{London, NewYork, Paris, SaoPaulo, Algiers}};
		_cities[Manila] = {Red,{Taipei, HongKong, SanFrancisco, HoChiMinhCity, Sydney}};
		_cities[MexicoCity] = {Yellow,{LosAngeles, Chicago, Miami, Lima, Bogota}};
		_cities[Miami] = {Yellow,{Atlanta, MexicoCity, Washington, Bogota}};
		_cities[Milan] = {Blue,{Essen, Paris, Istanbul}};
		_cities[Montreal] = {Blue,{Chicago, Washington, NewYork}};
		_cities[Moscow] = {Black,{StPetersburg, Istanbul, Tehran}};
		_cities[Mumbai] = {Black,{Karachi, Delhi, Chennai}};
		_cities[NewYork] = {Blue,{Montreal, Washington, London, Madrid}};
		_cities[Osaka] = {Red,{Taipei, Tokyo}};
		_cities[Paris] = {Blue,{Algiers, Essen, Madrid, Milan, London}};
		_cities[Riyadh] = {Black,{Baghdad, Cairo, Karachi}};
		_cities[SanFrancisco] = {Blue,{LosAngeles, Chicago, Tokyo, Manila}};
		_cities[Santiago] = {Yellow,{Lima}};
		_cities[SaoPaulo] = {Yellow,{Bogota, BuenosAires, Lagos, Madrid}};
		_cities[Seoul] = {Red,{Beijing, Shanghai, Tokyo}};
		_cities[Shanghai] = {Red,{Beijing, HongKong, Taipei, Seoul, Tokyo}};
		_cities[StPetersburg] = {Blue,{Essen, Istanbul, Moscow}};
		_cities[Sydney] = {Red,{Jakarta, Manila, LosAngeles}};
		_cities[Taipei] = {Red,{Shanghai, HongKong, Osaka, Manila}};
		_cities[Tehran] = {Black,{Baghdad, Moscow, Karachi, Delhi}};
		_cities[Tokyo] = {Red,{Seoul, Shanghai, Osaka, SanFrancisco}};
		_cities[Washington] = {Blue,{Atlanta, NewYork, Montreal, Miami}};

		/* initialize cures according to color disease */
		_cures[Black] = false;
		_cures[Red] = false;
		_cures[Blue] = false;
		_cures[Yellow] = false;
	}


  bool Board::is_clean() const{
	const auto pred = [](const auto& city){
		return city.second.disease == 0;
		};
	return std::all_of(_cities.cbegin(), _cities.cend(), pred);
	}

  int & Board::operator[](City city){
    return this->_cities[city].disease;
  }
  void Board::remove_cures(){
		for(auto& [color, isCure] : _cures)
		{
			isCure = false;
		}
  }
  std::ostream& operator<<(std::ostream& os,const Board& board)
  {

	  // disease level in each city, and research lab if exist
	  for (const auto& city: board._cities)
	  {
		  os << "[" << city.first << ',' << city.second.disease << "]\n";
		  if (city.second.hasResearchStation){
			  os << "has research station\n";
		  }
	  }

	  // cures found so far
	  for (const auto&[color, isCure] : board._cures)
	  {
		  os << color << ":" << isCure;
	  }

	  return os;
  }

	void Board::findCure(Color diseaseColor)
	{
		_cures[diseaseColor] = true;
	}

	bool Board::isCureFound(Color diseaseColor) const
	{
		return _cures.at(diseaseColor);
	}

	void Board::buildResearchStation(City c)
	{
		_cities[c].hasResearchStation = true;
	}

	bool Board::hasResearchStation(City c) const
	{
		return _cities.at(c).hasResearchStation;
	}

	Color Board::getCityColor(City c) const
	{
		return _cities.at(c).color;
	}

	bool Board::areConnected(City first, City second) const
	{
		return _cities.at(first).neighbors.find(second) != _cities.at(first).neighbors.end();
	}
}
