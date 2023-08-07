#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ListeningActor.generated.h"

class ATargetActor;
UCLASS()
class CHTEST_API AListeningActor : public AActor
{
	GENERATED_BODY()

public:
	AListeningActor();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	ATargetActor* TargetActor = nullptr;
};
