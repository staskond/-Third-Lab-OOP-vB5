// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _VEHICLEASSET_HPP_
#define _VEHICLEASSET_HPP_

/*****************************************************************************/

#include "asset.hpp"
#include "messages.hpp"
/*****************************************************************************/


class VehicleAsset
	:	public Asset
{

/*-----------------------------------------------------------------*/

public:
	VehicleAsset(const std::string & _FullNameProperty, double _cost, int _yearOfUse, bool _Accident);
	int GetYearsOfUse() { return m_YearsOfUse; };
	void CrashProperty() override;
	void RepairingProperty() override;
	double GetCost() const override;
private:
	double m_CurrentCost;
	int m_YearsOfUse;
	bool m_Accident;//true if the property is damaged
/*-----------------------------------------------------------------*/
};


/*****************************************************************************/

#endif // _VEHICLEASSET_HPP_
