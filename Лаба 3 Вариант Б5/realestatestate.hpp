// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _REAL_ESTATE_STATE_HPP_
#define _REAL_ESTATE_STATE_HPP_

/*****************************************************************************/


enum class RealEstateState
{
	Ideal
	, CosmeticRepairs
	, CapitalRepairs
	, Construction
};

inline RealEstateState operator --(RealEstateState  _State)
{
	auto  s = RealEstateState(static_cast<int> (_State) - 1);

	return s;
}


inline RealEstateState  operator ++(RealEstateState  _State)
{
	return (_State == RealEstateState::Construction) ? RealEstateState::Construction : RealEstateState(static_cast<int> (_State) + 1);

}
/*****************************************************************************/

#endif // _REAL_ESTATE_STATE_HPP_
