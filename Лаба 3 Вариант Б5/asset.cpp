// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#include "asset.hpp"

/*****************************************************************************/


// TODO


/*****************************************************************************/





Asset::Asset(std::string & _FullNameProperty, double _cost)
	:m_FullNameProperty(_FullNameProperty),
	m_cost(_cost)
{
	if (m_cost < 0)
		throw std::logic_error(Messages::NegativeAssetBaseCost);

	if (_FullNameProperty.empty())
		throw std::logic_error(Messages::AssetNameEmpty);
}
