#pragma once

#include "r2/r2_Grid.h"

namespace pmr
{
	using Tile = enum class Tile {
		Empty,
		Wall,
	};

	class Room
	{
	public:
		using Terrain = r2::Grid<Tile>;
		using ActorContainer = std::vector<class Actor*>;

		Room( const uint32_t width, const uint32_t height );

		//
		// Getter
		//
		std::size_t GetWidth() const
		{
			return mTerrain.GetWidth();
		}
		std::size_t GetHeight() const
		{
			return mTerrain.GetHeight();
		}
		std::size_t GetSize() const
		{
			return mTerrain.GetSize();
		}

		//
		// Terrain
		//
		const Terrain::CellT& Get( const std::size_t x, const std::size_t y ) const
		{
			return mTerrain.Get( x, y );
		}
		void Set( const std::size_t x, const std::size_t y, const Terrain::CellT& new_value )
		{
			mTerrain.Set( x, y, new_value );
		}

		//
		// Actor
		//
		const ActorContainer& GetActorContainer() const
		{
			return mActorContainer;
		}
		bool AddActor( Actor* const actor );

	private:
		Terrain mTerrain;
		ActorContainer mActorContainer;
	};

	void RoomBuilder( Room* out_room );
}