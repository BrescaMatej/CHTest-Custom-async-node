#include "TargetActor.h"

#include "Net/UnrealNetwork.h"

ATargetActor::ATargetActor()
{
	PrimaryActorTick.bCanEverTick = false;
	SetReplicates(true);
}

void ATargetActor::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const {

	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ATargetActor, bBoolValue);
}

bool ATargetActor::GetBoolValue() const
{
	return bBoolValue;
}

void ATargetActor::SetBoolValue(const bool NewValue)
{
	if (!HasAuthority()) return;
	
	if (bBoolValue != NewValue)
	{
		bBoolValue = NewValue;
		BoolValueChangedHandle.Broadcast();
	}
}