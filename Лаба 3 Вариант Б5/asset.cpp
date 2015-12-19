// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#include "asset.hpp"

/*****************************************************************************/


// TODO


/*****************************************************************************/

Asset::Asset(const std::string & _FullNameProperty, int _cost)
	:m_FullNameProperty(_FullNameProperty),
	m_cost(_cost)
{
	if (m_cost < 0)
		throw std::logic_error(Messages::NegativeAssetBaseCost);
}
