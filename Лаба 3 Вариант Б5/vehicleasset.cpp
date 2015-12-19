// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#include "vehicleasset.hpp"

/*****************************************************************************/


// TODO


/*****************************************************************************/

VehicleAsset::VehicleAsset(const std::string & _FullNameProperty, double _cost, int _yearOfUse)
	:Asset(_FullNameProperty, _cost)
	,m_YearsOfUse(_yearOfUse)
{
}

void VehicleAsset::CrashProperty()
{
	m_Accident = true;
}

void VehicleAsset::RepairingProperty()
{
	if (m_Accident)
		m_Accident = false;
	else
		throw std::logic_error(Messages::RepairingIdealRealEstate);
}

double VehicleAsset::GetCost()
{
	for (int i = 0; i < m_YearsOfUse - 1; i++)
	{
		m_CurrentCost -= (m_CurrentCost * 0.15);
	}
	if (m_Accident)
		m_CurrentCost = m_CurrentCost * 0.5;
	return m_CurrentCost;
}
