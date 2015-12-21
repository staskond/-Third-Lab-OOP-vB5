// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#include "controller.hpp"
#include "messages.hpp"

/*****************************************************************************/


// TODO


/*****************************************************************************/

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
	else
		throw std::logic_error(Messages::OwnerUnknown);
}



void Controller::createOwner(std::string const & _fullName)
{
	if (_fullName.empty())
		throw std::logic_error(Messages::OwnerNameEmpty);

		if (m_owners.find(_fullName) != m_owners.end())
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
	std::unique_ptr <Asset> EstateAsset = std::make_unique<RealEstateAsset>(_assetName, _baseCost, _initialState);
	m_owners.find(_ownerFullName)->second->addProperty(std::move(EstateAsset));
	
}

void Controller::addVehicle(std::string const & _ownerFullName, std::string const & _assetName, double _baseCost, int _yearsInUse, bool _hadAccidents)
{
	if (_ownerFullName.empty())
		throw std::logic_error(Messages::OwnerNameEmpty);

	if (_assetName.empty())
		throw std::logic_error(Messages::AssetNameEmpty);

	if (_baseCost < 0)
		throw std::logic_error(Messages::NegativeAssetBaseCost);

	auto temp = m_owners.find(_ownerFullName);
	temp->second->UniqueAsset(_assetName);
	std::unique_ptr<Asset> VAsset = std::make_unique<VehicleAsset>(_assetName, _baseCost, _yearsInUse, _hadAccidents);

	m_owners.find(_ownerFullName)->second->addProperty(std::move(VAsset));
}

std::unordered_set<std::string> Controller::getOwnerAssetNames(std::string const & _ownerFullName) const
{
	std::unordered_set<std::string> _names;

	const Owner & temp = resolveOwner(_ownerFullName);

	for (auto const & pAsset : temp.getAssets())
		_names.insert(pAsset->GetFullNameProperty());

	return _names;
}

double Controller::getOwnerAssetsCurrentCost(std::string const & _ownerFullName) const
{
	double sumCurrentCost = 0;

	const Owner & temp = resolveOwner(_ownerFullName);

	for (auto const & pAsset : temp.getAssets())
		sumCurrentCost += pAsset->GetCost();
	return sumCurrentCost;
}

double Controller::getAssetBaseCost(std::string const & _ownerFullName, std::string const & _assetName) const
{
	const Owner & temp = resolveOwner(_ownerFullName);
	return temp.findAsset(_assetName)->GetBasicCost();
}

double Controller::getAssetCurrentCost(std::string const & _ownerFullName, std::string const & _assetName) const
{
	const Owner & temp = resolveOwner(_ownerFullName);
	return temp.findAsset(_assetName)->GetCost();
}

void Controller::repair(std::string const & _ownerFullName, std::string const & _assetName)
{
	const Owner & temp = resolveOwner(_ownerFullName);

	temp.findAsset(_assetName)->RepairingProperty();
}

void Controller::damage(std::string const & _ownerFullName, std::string const & _assetName)
{
	const Owner & temp = resolveOwner(_ownerFullName);
	temp.findAsset(_assetName)->CrashProperty();
}

RealEstateState Controller::getRealEstateState(std::string const & _ownerFullName, std::string const & _assetName) const
{
	const Owner & temp = resolveOwner(_ownerFullName);

	const RealEstateAsset * pRAsset = dynamic_cast<const RealEstateAsset *>(temp.findAsset(_assetName));

	if (pRAsset)
		return pRAsset->GetCurrentLevelProperty();
	else
		throw std::logic_error(Messages::NotRealEstateAsset);
}

int Controller::getVehicleYearsInUse(std::string const & _ownerFullName, std::string const & _assetName) const
{
	const Owner & temp = resolveOwner(_ownerFullName);

	const VehicleAsset * pVAsset = dynamic_cast<const VehicleAsset *>(temp.findAsset(_assetName));

	if (pVAsset)
		return pVAsset->GetYearsOfUse();
	else
		throw std::logic_error(Messages::NotVehicleAsset);
}

bool Controller::isVehicleCrashed(std::string const & _ownerFullName, std::string const & _assetName) const
{
	const Owner & temp = resolveOwner(_ownerFullName);

	VehicleAsset * pVAsset = dynamic_cast<VehicleAsset *>(temp.findAsset(_assetName));

	if (pVAsset)
		if (pVAsset->HasAccident())
			return true;
		else
			return false;
	else
		throw std::logic_error(Messages::NotVehicleAsset);
}


