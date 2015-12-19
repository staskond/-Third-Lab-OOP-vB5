// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#include "owner.hpp"

/*****************************************************************************/


// TODO


/*****************************************************************************/

Owner::Owner(const std::string _FullNameOwner)
	:m_FullNameOwner(_FullNameOwner)
{
}

Owner::Owner(const std::string _FullNameOwner, const std::string & _FullNameProperty, int _cost)
	:Asset(_FullNameProperty,_cost)
	,m_FullNameOwner(_FullNameOwner)
{
}

void Owner::addProperty(Asset & _property)
{

	m_Assets.push_back(std::make_unique<Asset>(std::move(_property)));

}
