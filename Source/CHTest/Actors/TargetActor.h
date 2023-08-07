#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TargetActor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FBoolValueChanged);

UCLASS()
class CHTEST_API ATargetActor : public AActor 
{
	GENERATED_BODY()

public:
	ATargetActor();
	UFUNCTION(BlueprintPure)
	bool GetBoolValue() const;
	UFUNCTION(BlueprintCallable)
	void SetBoolValue(const bool NewValue);

public:
	UPROPERTY(BlueprintAssignable)
	FBoolValueChanged BoolValueChangedHandle;

protected:
	UPROPERTY(Replicated)
	bool bBoolValue = false;
};
