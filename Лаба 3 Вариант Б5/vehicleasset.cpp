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
	
	if (HasAccident())
		m_Accident = false;
	else
		throw std::logic_error(Messages::RepairingWorkingVehicle);

}

double VehicleAsset::GetCost() const
{
	double temp = GetBasicCost();
	for (int i = 0; i < m_YearsOfUse; i++)
	{
		temp -= (temp * 0.15);
	}
	if (m_Accident)
		temp = temp * 0.5;
	return temp;
}
