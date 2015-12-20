// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _OWNER_HPP_
#define _OWNER_HPP_
#include <memory>
#include "asset.hpp"
#include <vector>
#include "messages.hpp"

/*****************************************************************************/



class Owner
{

	
/*-----------------------------------------------------------------*/

public:




	Owner(const std::string &_FullNameOwner);

	typedef std::vector< std::unique_ptr< Asset > >::const_iterator AssetIterator;

	AssetIterator assetsBegin() const ;

	AssetIterator assetsEnd() const;

	class IterableAssets
	{
	public:

		IterableAssets(AssetIterator _chaptersBegin, AssetIterator _chaptersEnd)
			: m_begin(_chaptersBegin), m_end(_chaptersEnd)
		{}

		AssetIterator begin() const { return m_begin; }
		AssetIterator end() const { return m_end; }

	private:

		AssetIterator m_begin, m_end;
	};

	IterableAssets getAssets() const;
	Asset const * UniqueAsset(std::string const & _assetName) const;
	Asset const * findAsset(std::string const & _name) const;
	void addProperty(std::unique_ptr< Asset > _assets);
	const std::string & GetFullNameOwner() const { return m_FullNameOwner; }
private:
	const std::string m_FullNameOwner;
	std::vector<std::unique_ptr<Asset>> m_assets;
/*-----------------------------------------------------------------*/
};

inline Owner::AssetIterator
Owner::assetsBegin() const
{
	return m_assets.begin();
}


inline Owner::IterableAssets
Owner::getAssets() const
{
	return IterableAssets(m_assets.begin(), m_assets.end());
}


inline Owner::AssetIterator
Owner::assetsEnd() const
{
	return m_assets.end();
}



/*****************************************************************************/

#endif // _OWNER_HPP_
