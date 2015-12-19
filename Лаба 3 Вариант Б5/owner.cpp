// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#include "owner.hpp"

/*****************************************************************************/


// TODO


/*****************************************************************************/

void Owner::addProperty(Asset & _property)
{

	m_Assets.push_back(std::make_unique<Asset>(std::move(_property)));

}
