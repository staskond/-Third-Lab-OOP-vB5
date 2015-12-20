// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _REALESTATEASSET_HPP_
#define _REALESTATEASSET_HPP_

/*****************************************************************************/

#include "asset.hpp"
#include "realestatestate.hpp"
#include "owner.hpp"
#include <iostream>
/*****************************************************************************/


class RealEstateAsset
	: public Asset
{
public:
	RealEstateAsset(const std::string & _FullNameProperty, double _cost, RealEstateState _CurrentLevelProperty);
	RealEstateState GetCurrentLevelProperty() { return m_CurrentLevelProperty; };
	void CrashProperty() override;
	void RepairingProperty() override;
	double GetCost() const override;

/*-----------------------------------------------------------------*/

private:
	const double m_CurrentCost;
	RealEstateState m_CurrentLevelProperty;

/*-----------------------------------------------------------------*/
};


/*****************************************************************************/

#endif // _REALESTATEASSET_HPP_
