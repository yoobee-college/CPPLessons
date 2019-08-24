// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSExtractionZone.h"
#include "CPPLesson02Character.h"
#include "CPPLesson02GameMode.h"
#include "Kismet/GameplayStatics.h"
#include "Components/BoxComponent.h"	

// Sets default values
AFPSExtractionZone::AFPSExtractionZone()
{

	OverlapComp = CreateDefaultSubobject<UBoxComponent>(TEXT("OverlapComp"));
	OverlapComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	OverlapComp->SetCollisionResponseToAllChannels(ECR_Ignore);
	OverlapComp->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	OverlapComp->SetBoxExtent(FVector(200.0f));
	RootComponent = OverlapComp;

	OverlapComp->OnComponentBeginOverlap.AddDynamic(this, &AFPSExtractionZone::HandleOverlap);

	OverlapComp->SetHiddenInGame(false);
}

// Called when the game starts or when spawned
void AFPSExtractionZone::BeginPlay()
{
	Super::BeginPlay();

}

void AFPSExtractionZone::HandleOverlap(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{

	ACPPLesson02Character* MyPawn = Cast<ACPPLesson02Character>(OtherActor);

	if (MyPawn == nullptr)
	{
		return;
	}
	
	if (MyPawn->bIsCarryingObjective)
	{
		ACPPLesson02GameMode* GM = Cast<ACPPLesson02GameMode>(GetWorld()->GetAuthGameMode());
		if (GM)
		{
			GM->CompleteMission(MyPawn);
		}
	}
	else
	{
		UGameplayStatics::PlaySound2D(this, ObjectiveMissingSound, 0.2f, 0.2f);
	}
	UE_LOG(LogTemp, Warning, TEXT("Overlapped with extraction zone"));
}

