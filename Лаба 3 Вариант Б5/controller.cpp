// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#include "controller.hpp"
#include "messages.hpp"

/*****************************************************************************/


// TODO


/*****************************************************************************/

void Controller::createOwner(std::string const & _fullName)
{
	if (_fullName.empty())
		throw std::logic_error(Messages::OwnerNameEmpty);

		if (findOwner(_fullName))
			throw std::logic_error(Messages::OwnerNameNotUnique);
	m_owners[_fullName] = std::make_unique< Owner >(_fullName);
}


void Controller::addRealEstate(std::string const & _ownerFullName, std::string const & _assetName, double _baseCost, RealEstateState _initialState)
{
	if (_ownerFullName.empty())
		throw std::logic_error(Messages::OwnerNameEmpty);



	if (_assetName.empty())
		throw std::logic_error(Messages::AssetNameEmpty);


	if (_baseCost < 0)
		throw std::logic_error(Messages::NegativeAssetBaseCost);

	auto temp = m_owners.find(_ownerFullName);
	temp->second->UniqueAsset(_assetName);
	m_owners[_ownerFullName] = std::make_unique< Owner >(_ownerFullName, _assetName, _baseCost, _initialState);

}

void Controller::addVehicle(std::string const & _ownerFullName, std::string const & _assetName, double _baseCost, int _yearsInUse, bool _hadAccidents)
{
	if (_ownerFullName.empty())
		throw std::logic_error(Messages::OwnerNameEmpty);

	if (_assetName.empty())
		throw std::logic_error(Messages::AssetNameEmpty);

	if (_baseCost < 0)
		throw std::logic_error(Messages::NegativeAssetBaseCost);

	m_owners[_ownerFullName] = std::make_unique< Owner >(_ownerFullName, _assetName, _baseCost, _yearsInUse, _hadAccidents);
}

std::unordered_set<std::string> Controller::getOwnerAssetNames(std::string const & _ownerFullName) const
{
	std::unordered_set<std::string> _names;

	const Owner & temp = resolveOwner(_ownerFullName);

	for (auto const & _pAsset : temp.getAssets())
		_names.insert(_pAsset->GetFullNameProperty());

	return _names;
}



Owner * Controller::findOwner(std::string const & _ownerFullName) const
{
	auto it = m_owners.find(_ownerFullName);
	return (it == m_owners.end()) ? nullptr : it->second.get();
}

Owner & Controller::resolveOwner(std::string const & _ownerFullName) const
{
	Owner * pOwner = findOwner(_ownerFullName);
	if (pOwner)
		return *pOwner;

	throw std::logic_error(Messages::OwnerUnknown);
}