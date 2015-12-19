// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#include "vehicleasset.hpp"

/*****************************************************************************/


// TODO


/*****************************************************************************/

void VehicleAsset::CrashProperty()
{
	m_Accident = true;
}

void VehicleAsset::RepairingProperty()
{
	if (m_Accident)
		m_Accident = false;
}

void VehicleAsset::GetCost()
{
	for (int i = 0; i < m_YearsOfUse - 1; i++)
	{
		m_CurrentCost -= (m_CurrentCost * 0.15);
	}
}
