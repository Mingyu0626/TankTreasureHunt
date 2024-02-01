// Fill out your copyright notice in the Description page of Project Settings.


#include "Tower.h"
#include "Tank.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"

void ATower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	// 1. ��ũ�� ��ȿ�ϰ�, Ÿ���� �����Ÿ� �ȿ� �ִ��� Ȯ��
	if (InFireRange())
	{
		// 2. �����Ÿ� �ȿ� ������ ��ž ȸ��
		RotateTurret(Tank->GetActorLocation());
	}
}

void ATower::HandleDestruction()
{
	Super::HandleDestruction();
	Destroy();
}

void ATower::BeginPlay()
{
	Super::BeginPlay();
	Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));
	GetWorldTimerManager().SetTimer(
		FireRateTimerHandle, 
		this, &ATower::CheckFireCondition, 
		FireRate, 
		true);
}

void ATower::CheckFireCondition()
{
	// 1. ��ũ�� ��ȿ�ϰ�, Ÿ���� �����Ÿ� �ȿ� �ִ��� Ȯ��
	if (InFireRange())
	{
		// 2. �����Ÿ� �ȿ� ������ Fire ȣ��
		Fire();	
	}
}

bool ATower::InFireRange()
{
	if (Tank)
	{
		return FVector::Dist(GetActorLocation(), Tank->GetActorLocation()) <= FireRange;
	}
	return false;
}
