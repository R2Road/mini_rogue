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
		using Grid = r2::Grid<Tile>;
		using ActorContainer = std::vector<class Actor*>;

		Room( const uint32_t width, const uint32_t height );

		//
		// Getter
		//
		std::size_t GetWidth() const
		{
			return mGrid.GetWidth();
		}
		std::size_t GetHeight() const
		{
			return mGrid.GetHeight();
		}
		std::size_t GetSize() const
		{
			return mGrid.GetSize();
		}

		//
		// Cell
		//
		const Grid::CellT& Get( const std::size_t x, const std::size_t y ) const
		{
			return mGrid.Get( x, y );
		}
		void Set( const std::size_t x, const std::size_t y, const Grid::CellT& new_value )
		{
			mGrid.Set( x, y, new_value );
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
		Grid mGrid;
		ActorContainer mActorContainer;
	};

	void RoomBuilder( Room* out_room );
}