// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#include "realestateasset.hpp"

/*****************************************************************************/


// TODO


/*****************************************************************************/






RealEstateAsset::RealEstateAsset(const std::string & _FullNameProperty, double _cost, RealEstateState _CurrentLevelProperty)
	:Asset(_FullNameProperty, _cost)
	, m_CurrentLevelProperty(_CurrentLevelProperty)
	, m_CurrentCost(_cost)
{
}

void RealEstateAsset::CrashProperty()
{
	if (!(m_CurrentLevelProperty == RealEstateState::CapitalRepairs))
		--m_CurrentLevelProperty;
}

void RealEstateAsset::RepairingProperty()
{
	if (m_CurrentLevelProperty == RealEstateState::Ideal)
		throw std::logic_error(Messages::RepairingIdealRealEstate);
	else
		++m_CurrentLevelProperty;
}

double RealEstateAsset::GetCost() const
{
	double temp = m_CurrentCost;
	switch (m_CurrentLevelProperty)
	{
	case RealEstateState::Ideal:
		break;
	case RealEstateState::CosmeticRepairs:
		temp -= (temp * 0.15);
		break;
	case RealEstateState::CapitalRepairs:
		temp -= (temp * 0.3);
		break;
	case RealEstateState::Construction:
		temp -= (temp * 0.5);
		break;
	default:
		break;
	}

	return temp;

}
