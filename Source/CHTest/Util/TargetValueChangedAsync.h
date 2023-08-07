#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "TargetValueChangedAsync.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FValueChangedOutputPin);

class ATargetActor;
UCLASS()
class CHTEST_API UTargetValueChangedAsync : public UBlueprintAsyncActionBase
{
	GENERATED_UCLASS_BODY()
public:
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "TargetActor"), Category = "Util")
	static UTargetValueChangedAsync* ValueChanged(ATargetActor* ListenTarget);

	void Activate() override;

private:
	UFUNCTION()
	void ExecuteValueChanged();

public:
	UPROPERTY(BlueprintAssignable)
	FValueChangedOutputPin OnValueChanged;
	
protected:
	UPROPERTY()
	ATargetActor* TargetActor = nullptr;
};
