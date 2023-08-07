#include "ListeningActor.h"

AListeningActor::AListeningActor()
{
	PrimaryActorTick.bCanEverTick = false;
	bReplicates = true;
}