// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _ASSET_HPP_
#define _ASSET_HPP_
#include <string>
#include "messages.hpp"
#include "realestatestate.hpp"
#include <memory>
/*****************************************************************************/


class Asset
{
public:

	virtual ~Asset() = default;

	virtual int GetSumCostOfProperty() { return 0; };
	virtual void CrashProperty() { };
	virtual void RepairingProperty() {};
	virtual int GetCurrentCost() { return 0; };

	const std::string & _FullNameProperty() const { return m_FullNameProperty; };
	virtual int GetCost() { return m_cost; };

protected:
	Asset(const std::string & _FullNameProperty, int _cost);

private:
	const std::string & m_FullNameProperty;
	int m_cost;

	
};


/*****************************************************************************/


#endif // _ASSET_HPP_
