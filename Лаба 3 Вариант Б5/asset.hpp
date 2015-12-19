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

	virtual int GetSumCostOfProperty() = 0;
	virtual void CrashProperty() = 0;
	virtual void RepairingProperty() = 0;

	const std::string & GetFullNameProperty() const { return m_FullNameProperty; };
	virtual double GetCost() { return m_cost; };

protected:
	Asset(const std::string & _FullNameProperty, double _cost);

private:
	const std::string & m_FullNameProperty;
	double m_cost;

	
};


/*****************************************************************************/


#endif // _ASSET_HPP_
