// Copyright of Simone Durante

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IDamagebleActor.generated.h"

// This class does not need to be modified.
UINTERFACE(BlueprintType)
class UIDamagebleActor : public UInterface
{
	GENERATED_BODY()

	UIDamagebleActor(const FObjectInitializer& ObjectInitializer);
};

/**
 * 
 */
class BATTLETANKS_API IIDamagebleActor
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Health")
	float GetHealthPercent();
};
