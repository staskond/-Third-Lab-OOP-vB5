// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#include "vehicleasset.hpp"

/*****************************************************************************/


// TODO


/*****************************************************************************/

VehicleAsset::VehicleAsset(const std::string & _FullNameProperty, double _cost, int _yearOfUse, bool _Accident)
	:Asset(_FullNameProperty, _cost)
	,m_YearsOfUse(_yearOfUse)
	,m_Accident(_Accident)
{
	if (m_YearsOfUse < 0)
		throw std::logic_error(Messages::NegativeVehicleUseYears);
}

void VehicleAsset::CrashProperty()
{
	m_Accident = true;
}

void VehicleAsset::RepairingProperty()
{
	if (m_Accident) {
		m_Accident = false;
		m_CurrentCost *= 2;
	}
	else
		throw std::logic_error(Messages::RepairingIdealRealEstate);
}

const double VehicleAsset::GetCost() const
{
	double temp = m_CurrentCost;
	for (int i = 0; i < m_YearsOfUse - 1; i++)
	{
		temp -= (temp * 0.15);
	}
	if (m_Accident)
		temp = temp * 0.5;
	return temp;
}
