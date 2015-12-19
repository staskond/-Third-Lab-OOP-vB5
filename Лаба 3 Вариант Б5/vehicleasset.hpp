// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _VEHICLEASSET_HPP_
#define _VEHICLEASSET_HPP_

/*****************************************************************************/

#include "asset.hpp"

/*****************************************************************************/


class VehicleAsset
	:	public Asset
{

/*-----------------------------------------------------------------*/

public:

	int GetYearsOfUse() { return m_YearsOfUse; };

	void CrashProperty() override;
	void RepairingProperty() override;
	int GetCost() override;
private:
	int m_CurrentCost;
	int m_YearsOfUse;
	bool m_Accident;//true if the property is damaged
/*-----------------------------------------------------------------*/
};


/*****************************************************************************/

#endif // _VEHICLEASSET_HPP_
