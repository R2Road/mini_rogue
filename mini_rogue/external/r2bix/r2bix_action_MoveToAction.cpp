#include "r2bix_action_MoveToAction.h"

#include "r2bix_node_Node.h"

namespace r2bix_action
{
	MoveToAction::MoveToAction() :
		mMoveAmount()
		, mStartPoint()
		, mEndPoint()
		, mTimer( 1.f )
	{}

	std::unique_ptr<MoveToAction> MoveToAction::Create()
	{
		std::unique_ptr<MoveToAction> ret( new ( std::nothrow ) MoveToAction() );
		return ret;
	}

	void MoveToAction::Enter()
	{
		mStartPoint = mOwnerNode->mTransformComponent->GetPosition();
		mMoveAmount = mEndPoint - mStartPoint;
		mTimer.Start();
	}
	bool MoveToAction::Update( const float delta_time )
	{
		if( mTimer.Update( delta_time ) )
		{
			mOwnerNode->mTransformComponent->SetPosition(
				mStartPoint.GetX() + ( mMoveAmount.GetX() * mTimer.GetElapsedTimeRate() )
				, mStartPoint.GetY() + ( mMoveAmount.GetY() * mTimer.GetElapsedTimeRate() )
			);
		}
		else
		{
			mOwnerNode->mTransformComponent->SetPosition( mEndPoint );
		}

		return mTimer.IsAlive();
	}
}