#include "TargetValueChangedAsync.h"
#include "CHTest/Actors/TargetActor.h"

UTargetValueChangedAsync::UTargetValueChangedAsync(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) , TargetActor(nullptr)
{
}

UTargetValueChangedAsync* UTargetValueChangedAsync::ValueChanged(ATargetActor* ListenTarget)
{
	if (ListenTarget)
	{
		UTargetValueChangedAsync* BpNode = NewObject<UTargetValueChangedAsync>();
		BpNode->TargetActor = ListenTarget;
		return BpNode;
	}
	UE_LOG(LogTemp, Warning, TEXT("UTargetValueChangedAsync::ValueChanged : : : ListenTarget is invalid!"));
	return nullptr;
}

void UTargetValueChangedAsync::Activate()
{
	Super::Activate(); 
	if (TargetActor)
	{
		RegisterWithGameInstance(TargetActor->GetWorld()->GetGameInstance());
		TargetActor->BoolValueChangedHandle.AddDynamic(this, &ThisClass::ExecuteValueChanged);
	}
	else
	{
		SetReadyToDestroy();
	}
}

void UTargetValueChangedAsync::ExecuteValueChanged()
{
	OnValueChanged.Broadcast();
	SetReadyToDestroy();
}
