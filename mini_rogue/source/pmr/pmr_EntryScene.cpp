#include "pmr_EntryScene.h"

#include "r2bix/r2base_Director.h"

#include "pmr_TextureTable.h"
#include "pmr_TextureFrameAnimationTable.h"

#include "pmr_CompanyScene.h"

namespace pmr
{
	class EntrySceneComponent : public r2base::Component<EntrySceneComponent>
	{
	public:
		EntrySceneComponent( r2base::Node& owner_node ) : r2base::Component<EntrySceneComponent>( owner_node ) {}

		//
		//
		//
		void Update( const float delta_time ) override
		{
			r2base::iComponent::Update( delta_time );

			//
			// Table Load
			//
			pmr::TextureTable::GetInstance().Load();
			pmr::TextureFrameAnimationTable::GetInstance().Load();

			//
			// Scene
			//
			auto next_scene = pmr::CompanyScene::Create( mOwnerNode.GetDirector() );

			//
			// Go Next 
			//
			mOwnerNode.GetDirector().Setup( std::move( next_scene ) );
		}
	};

	r2node::SceneNodeUp EntryScene::Create( r2base::Director& director )
	{
		auto ret( r2node::SceneNode::Create( director ) );
		if( ret )
		{
			ret->AddComponent<EntrySceneComponent>();
		}

		return ret;
	}
}