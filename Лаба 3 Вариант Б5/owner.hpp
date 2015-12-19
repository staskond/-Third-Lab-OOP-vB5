// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _OWNER_HPP_
#define _OWNER_HPP_
#include <memory>
#include "asset.hpp"
#include <vector>
#include "messages.hpp"
/*****************************************************************************/


class Owner
	:public Asset
{

	
/*-----------------------------------------------------------------*/

public:
	Owner(const std::string _FullNameOwner, const std::string & _FullNameProperty, double _cost);//...
	void addProperty(Asset & _property);
private:
	const std::string m_FullNameOwner;
	std::vector<std::unique_ptr<Asset>> m_assets;
/*-----------------------------------------------------------------*/
};


/*****************************************************************************/

#endif // _OWNER_HPP_
