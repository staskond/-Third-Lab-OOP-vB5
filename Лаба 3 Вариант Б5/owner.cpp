// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#include "owner.hpp"
#include <algorithm>
/*****************************************************************************/


// TODO


/*****************************************************************************/






Owner::Owner(const std::string & _FullNameOwner)
	:m_FullNameOwner(_FullNameOwner)
{
	if (m_FullNameOwner.empty())
		throw std::logic_error(Messages::OwnerNameEmpty);
}

Asset const * Owner::UniqueAsset(std::string const & _assetName) const
{
	auto it = std::find_if(
		m_assets.begin(), m_assets.end(),
		[&](auto const & _Asset)
	{
		return _Asset->GetFullNameProperty() == _assetName;
	}
	);

	if (it == m_assets.end())
		return nullptr;
	else
		throw std::logic_error(Messages::AssetNameNotUniqueWithinOwner);
}


Asset const * Owner::findAsset(std::string const & _name) const
{
	auto it = std::find_if(
		m_assets.begin(), m_assets.end(),
		[&](auto const & _asset)
	{
		return _asset->getName() == _name;
	}
	);

	if (it == m_assets.end())
		return nullptr;

	else
		return it->get();
}

void Owner::addProperty(std::unique_ptr<Asset> _assets)
{
	if (findAsset(_assets->GetFullNameProperty()))
		throw std::logic_error(Messages::AssetNameNotUniqueWithinOwner);

	m_assets.push_back(std::move(_assets));
}





/*
void Owner::addProperty(Asset & _property)
{
	for (auto const & pAsset : m_assets)
		if (_property.GetFullNameProperty() == pAsset->GetFullNameProperty())
			throw std::logic_error(Messages::AssetNameNotUniqueWithinOwner);
	m_assets.push_back(std::make_unique<Asset>(std::move(_property)));

}*/
