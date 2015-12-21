// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#include "realestateasset.hpp"

/*****************************************************************************/


// TODO


/*****************************************************************************/






RealEstateAsset::RealEstateAsset(const std::string & _FullNameProperty, double _cost, RealEstateState _CurrentLevelProperty)
	:Asset(_FullNameProperty, _cost)
	, m_CurrentLevelProperty(_CurrentLevelProperty)
{
}

void RealEstateAsset::CrashProperty()
{
	auto it = GetCurrentLevelProperty();
	m_CurrentLevelProperty = ++it;;
}

void RealEstateAsset::RepairingProperty()
{
	auto it = GetCurrentLevelProperty();
	if (it == RealEstateState::Ideal)
		throw std::logic_error(Messages::RepairingIdealRealEstate);
	else
		m_CurrentLevelProperty = --it;
}

double RealEstateAsset::GetCost() const
{
	double temp = GetBasicCost();
	switch (GetCurrentLevelProperty())
	{
	case RealEstateState::Ideal:
		return temp;
		break;
	case RealEstateState::CosmeticRepairs:
		temp -= (temp * 0.15);
		return temp;
		break;
	case RealEstateState::CapitalRepairs:
		temp -= (temp * 0.3);
		return temp;
		break;
	case RealEstateState::Construction:
		temp -= (temp * 0.5);
		return temp;
		break;
	default:
		break;
	}
	
}
