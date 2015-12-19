// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#include "realestateasset.hpp"

/*****************************************************************************/


// TODO


/*****************************************************************************/




RealEstateAsset::RealEstateAsset(const std::string & _FullNameProperty, int _cost, RealEstateState _CurrentLevelProperty)
	: Asset(_FullNameProperty, _cost)
	,m_CurrentLevelProperty(_CurrentLevelProperty)
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

double RealEstateAsset::GetCost()
{
	switch (m_CurrentLevelProperty)
	{
	case RealEstateState::Ideal:
		m_CurrentCost -= (m_CurrentCost * 0.0);
		break;
	case RealEstateState::CosmeticRepairs:
		m_CurrentCost -= (m_CurrentCost * 0.15);
		break;
	case RealEstateState::CapitalRepairs:
		m_CurrentCost -= (m_CurrentCost * 0.3);
		break;
	case RealEstateState::Construction:
		m_CurrentCost -= (m_CurrentCost * 0.5);
		break;
	default:
		break;
	}
	return m_CurrentCost;
}
