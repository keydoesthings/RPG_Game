#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Perception/AIPerceptionTypes.h"
#include "RPGAIController.generated.h"

UCLASS()
class YOURGAME_API ARPGAIController : public AAIController
{
	GENERATED_BODY()

public:
	ARPGAIController();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	virtual void OnPossess(APawn* InPawn) override;

	UFUNCTION()
	void OnTargetPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus);

private:
	class UAIPerceptionComponent* PerceptionComponent;
	class UAISenseConfig_Sight* SightConfig;

	AActor* PlayerActor;
};