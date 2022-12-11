#pragma once

#include <list>
#include <memory>
#include <type_traits>

#include "r2/r2_PointInt.h"
#include "r2bix_component_TransformComponent.h"

//
// # 2022.02.28 by R2Road
//
// ������Ʈ ��� �ý����� �ẻ ������ ������ ����� �� ������ ������ ���⼭ �غ���.
//
// ���� ������Ʈ�� �����Ͽ� Ư�� ����� ���� ǥ�� ��带 �����Ѵ�.
// ����� ���� ����� ������ ������ ������ �������.
//

namespace r2bix
{
	class Director;
}

namespace r2component
{
	class TransformComponent;
}

namespace r2bix_render
{
	class Camera;
	class iRenderTarget;
}

namespace r2bix_node
{
	using NodeUp = std::unique_ptr<class Node>;
	class Node
	{
	protected:
		using ComponentContainerT = std::list<r2bix_component::ComponentUp>;
		using ChildContainerT = std::list<NodeUp>;

		Node( r2bix::Director& director );

	public:
		virtual ~Node() {}

	static std::unique_ptr<Node> Create( r2bix::Director& director );

	public:
		virtual bool Init();
		virtual void Update( const float delta_time );
		virtual void Render( const r2bix_render::Camera* const camera, r2bix_render::iRenderTarget* const render_target, r2::PointInt offset );

		//
		//
		//
		r2bix::Director& GetDirector() const { return mDirector; }
		bool IsVisible() const { return mbVisible; }
		void SetVisible( const bool visible )
		{
			mbVisible = visible;
		}

		//
		//
		//
		template<typename ComponentT>
		ComponentT* const GetComponent() const
		{
			for( auto& c : mComponentContainer )
			{
				if( r2bix_component::ComponentStaticID<ComponentT>::Get() == c->GetStaticID() )
				{
					return static_cast<ComponentT*>( c.get() );
				}
			}

			return nullptr;
		}
		template<typename ComponentT>
		ComponentT* AddComponent()
		{
			static_assert( std::is_base_of<r2bix_component::iComponent, ComponentT>() );

			if( GetComponent<ComponentT>() )
			{
				return nullptr;
			}

			auto component = ComponentT::Create( *this );
			auto ret = component.get();
			mComponentContainer.push_back( std::move( component ) );

			return ret;
		}

		//
		//
		//
		int GetChildCount() const
		{
			return static_cast<int>( mChildContainer.size() );
		}
		const ChildContainerT& GetChildContainer() const
		{
			return mChildContainer;
		}
		template<typename NodeT>
		Node* AddChild()
		{
			return AddChild<NodeT>( 0 );
		}
		template<typename NodeT>
		Node* AddChild( const int32_t z_order )
		{
			static_assert( std::is_base_of<r2bix_node::Node, NodeT>() );

			auto child_node = NodeT::Create( mDirector );
			child_node->mTransformComponent->SetZ( z_order );

			auto ret = child_node.get();

			//
			// Find Insert Pivot
			//
			auto cur = mChildContainer.begin();
			for( auto end = mChildContainer.end(); end != cur; ++cur )
			{
				if( z_order > ( *cur )->mTransformComponent->GetZ() )
				{
					continue;
				}

				if( z_order < ( *cur )->mTransformComponent->GetZ() )
				{
					break;
				}

				//if( z_order == ( *cur )->mTransformComponent->GetZ() )
				{
					auto temp = cur;
					++temp;
					for( ; end != temp; ++temp )
					{
						if( z_order != ( *cur )->mTransformComponent->GetZ() )
						{
							break;
						}
					}
					cur = temp;
				}

				break;
			}

			//
			// Insert
			//
			if( cur == mChildContainer.end() )
			{
				mChildContainer.push_back( std::move( child_node ) );
			}
			else
			{
				mChildContainer.insert( cur, std::move( child_node ) );
			}

			return ret;
		}

	protected:
		r2bix::Director& mDirector;
		bool mbVisible;
		ComponentContainerT mComponentContainer;
		ChildContainerT mChildContainer;
	public:
		r2bix_component::TransformComponent* mTransformComponent;
	};
}