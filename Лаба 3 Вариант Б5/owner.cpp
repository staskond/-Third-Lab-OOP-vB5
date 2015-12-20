// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#include "owner.hpp"

/*****************************************************************************/


// TODO


/*****************************************************************************/







Owner::Owner(const std::string &_FullNameOwner, const std::string & _FullNameProperty, double _cost)
	:Asset(_FullNameProperty,_cost)
	,m_FullNameOwner(_FullNameOwner)
{
	if (m_FullNameOwner.empty())
		throw std::logic_error(Messages::OwnerNameEmpty);
}

Owner::Owner(std::string & _FullNameOwner, const std::string & _FullNameProperty, double _cost, RealEstateAsset _CurrentLevelProperty)
	:RealEstateAsset(_FullNameProperty, _cost, _CurrentLevelProperty),
	m_FullNameOwner(_FullNameOwner)
{
}




void Owner::addProperty(Asset & _property)
{
	for (auto const & pAsset : m_assets)
		if (_property.GetFullNameProperty() == pAsset->GetFullNameProperty())
			throw std::logic_error(Messages::AssetNameNotUniqueWithinOwner);
	m_assets.push_back(std::make_unique<Asset>(std::move(_property)));

}
 