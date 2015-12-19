// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _ASSET_HPP_
#define _ASSET_HPP_
#include <string>
#include "messages.hpp"
/*****************************************************************************/


class Asset
{
public:

	Asset(const std::string & _FullNameProperty, int _cost);
	virtual ~Asset() = default;

	virtual int GetSumCostOfProperty() { return 0; };
	virtual int CrashProperty() { return 0; };
	virtual int RepairingProperty() { return 0; };

	const std::string & _FullNameProperty() const { return m_FullNameProperty; };
	int GetCost() const { return m_cost; };

private:

	const std::string & m_FullNameProperty;
	int m_cost;

	
};


/*****************************************************************************/


#endif // _ASSET_HPP_
