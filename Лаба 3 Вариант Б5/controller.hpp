// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _CONTROLLER_HPP_
#define _CONTROLLER_HPP_

/*****************************************************************************/

#include "realestatestate.hpp"

#include <string>
#include <unordered_set>
#include "owner.hpp"
#include "vehicleasset.hpp"
#include "realestateasset.hpp"
#include <unordered_map>

/*****************************************************************************/

class Owner;

class Controller
{


/*-----------------------------------------------------------------*/

public:

/*-----------------------------------------------------------------*/
	Controller() = default;

	Controller(const Controller &) = delete;

	Controller & operator = (const Controller &) = delete;

	~Controller() = default;

/*-----------------------------------------------------------------*/

	void createOwner ( std::string const & _fullName );
	
	void addRealEstate ( 
			std::string const & _ownerFullName
		,	std::string const & _assetName
		,	double _baseCost
		,	RealEstateState _initialState
	);

	void addVehicle (
			std::string const & _ownerFullName
		,	std::string const & _assetName
		,	double _baseCost
		,	int _yearsInUse
		,	bool _hadAccidents
	);

	std::unordered_set< std::string > getOwnerAssetNames ( std::string const & _ownerFullName  ) const;

	double getOwnerAssetsCurrentCost  ( std::string const & _ownerFullName ) const;

	double getAssetBaseCost  ( std::string const & _ownerFullName, std::string const & _assetName ) const;

	double getAssetCurrentCost  ( std::string const & _ownerFullName, std::string const & _assetName ) const;

	void repair ( std::string const & _ownerFullName, std::string const & _assetName );
	
	void damage ( std::string const & _ownerFullName, std::string const & _assetName );

	RealEstateState getRealEstateState ( std::string const & _ownerFullName, std::string const & _assetName ) const;

	int getVehicleYearsInUse ( std::string const & _ownerFullName, std::string const & _assetName ) const;

	bool isVehicleCrashed ( std::string const & _ownerFullName, std::string const & _assetName ) const;
	
	Owner * findOwner(std::string const & _name) const;
	Owner & resolveOwner(std::string const & _ownerName) const;
/*-----------------------------------------------------------------*/

private:

/*-----------------------------------------------------------------*/
	
//	std::vector<std::string> m_owners;
//	std::vector<std::unique_ptr<Owner>> m_pOwners;
	
	std::unordered_map< std::string, std::unique_ptr< Owner > > m_owners;
/*-----------------------------------------------------------------*/

	
};


/*****************************************************************************/

#endif //  _CONTROLLER_HPP_
