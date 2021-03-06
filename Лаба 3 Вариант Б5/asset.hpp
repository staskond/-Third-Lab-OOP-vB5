// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _ASSET_HPP_
#define _ASSET_HPP_
#include <string>
#include "messages.hpp"
#include <memory>
/*****************************************************************************/


class Asset
{
public:
	
	virtual ~Asset() = default;
	virtual void CrashProperty() = 0;
	virtual void RepairingProperty() = 0;
	const std::string & GetFullNameProperty() const { return m_FullNameProperty; };
	virtual double GetCost() const = 0;
	const double GetBasicCost() const{ return m_cost; };

protected:
	Asset(const std::string & _FullNameProperty, double _cost);

private:
	const std::string m_FullNameProperty;
	const double m_cost;

	
};


/*****************************************************************************/


#endif // _ASSET_HPP_
