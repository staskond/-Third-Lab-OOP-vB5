// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _OWNER_HPP_
#define _OWNER_HPP_
#include <memory>
#include "asset.hpp"
#include <vector>
#include "messages.hpp"
#include "realestateasset.hpp"
/*****************************************************************************/


class Owner
	:public Asset, RealEstateAsset
{

	
/*-----------------------------------------------------------------*/

public:
	Owner(const std::string &_FullNameOwner, const std::string & _FullNameProperty, double _cost);
//	Owner(std::string &_FullNameOwner, const std::string & _FullNameProperty, double _cost, RealEstateAsset _CurrentLevelProperty);//...

	void addProperty(Asset & _property);
	const std::string & GetFullNameOwner() const { return m_FullNameOwner; }
private:
	const std::string m_FullNameOwner;
	std::vector<std::unique_ptr<Asset>> m_assets;
/*-----------------------------------------------------------------*/
};


/*****************************************************************************/

#endif // _OWNER_HPP_
