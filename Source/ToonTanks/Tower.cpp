// Fill out your copyright notice in the Description page of Project Settings.


#include "Tower.h"
#include "Tank.h"
#include "Kismet/GameplayStatics.h"

void ATower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	// 1. ��ũ������ �Ÿ� ���ϱ�
	if (Tank)
	{
		float Distance = FVector::Dist(GetActorLocation(), Tank->GetActorLocation());


		// 2. ��ũ�� �����Ÿ��� �ִ��� Ȯ��
		if (Distance <= FireRange)
		{
			// 3. �����Ÿ��� ������ ��ž ȸ��
			RotateTurret(Tank->GetActorLocation());

		}
	}
}

void ATower::BeginPlay()
{
	Super::BeginPlay();
	Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));
}
