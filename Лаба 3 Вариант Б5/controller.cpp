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

	for (auto const & pOwner : m_owners)
		if (_fullName == pOwner)
			throw std::logic_error(Messages::OwnerNameNotUnique);
	m_owners.push_back(_fullName);
}

void Controller::addRealEstate(std::string const & _ownerFullName, std::string const & _assetName, double _baseCost, RealEstateState _initialState)
{
	if (_ownerFullName.empty())
		throw std::logic_error(Messages::OwnerNameEmpty);

	if (_assetName.empty())
		throw std::logic_error(Messages::AssetNameEmpty);

	if (_baseCost < 0)
		throw std::logic_error(Messages::NegativeAssetBaseCost);

	Owner(_ownerFullName, _assetName, _baseCost)
	

}
