
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
//#include "Object.h"
#include "Json.h"
#include "Runtime/Networking/Public/Networking.h"
#include "SocketClient.generated.h"


UCLASS()
class HANDTRACKINGCLIENT_API ASocketClient : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASocketClient();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:
	// Called every frame
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	virtual void Tick(float DeltaTime) override;


	//Socket模块
	UFUNCTION(BlueprintCallable, Category = "MySocket")
		bool SocketCreate(FString IPStr, int32 port);

	UFUNCTION(BlueprintCallable, Category = "MySocket")
		void SocketSend(FString meesage);

	UFUNCTION(BlueprintCallable, Category = "MySocket")
		void SocketReceive(bool& bReceive, FString& recvMessage);





	//接收数据暴露参
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MySocket")
		FString recvData;

	//坐标字符
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MySocket")
		FString Coor_Str0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MySocket")
		FString Coor_Str1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MySocket")
		FString Coor_Str2;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MySocket")
		FString Coor_Str3;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MySocket")
		FString Coor_Str4;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MySocket")
		FString Coor_Str5;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MySocket")
		FString Coor_Str6;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MySocket")
		FString Coor_Str7;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MySocket")
		FString Coor_Str8;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MySocket")
		FString Coor_Str9;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MySocket")
		FString Coor_Str10;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MySocket")
		FString Coor_Str11;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MySocket")
		FString Coor_Str12;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MySocket")
		FString Coor_Str13;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MySocket")
		FString Coor_Str14;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MySocket")
		FString Coor_Str15;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MySocket")
		FString Coor_Str16;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MySocket")
		FString Coor_Str17;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MySocket")
		FString Coor_Str18;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MySocket")
		FString Coor_Str19;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MySocket")
		FString Coor_Str20;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MySocket")
		AActor* Actors;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MySocket")
		UStaticMeshComponent* PointComponent;

	//坐标向量
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MySocket")
		FVector PointLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MySocket")
		FVector PointLocation1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MySocket")
		FVector PointLocation2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MySocket")
		FVector PointLocation3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MySocket")
		FVector PointLocation4;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MySocket")
		FVector PointLocation5;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MySocket")
		FVector PointLocation6;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MySocket")
		FVector PointLocation7;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MySocket")
		FVector PointLocation8;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MySocket")
		FVector PointLocation9;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MySocket")
		FVector PointLocation10;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MySocket")
		FVector PointLocation11;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MySocket")
		FVector PointLocation12;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MySocket")
		FVector PointLocation13;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MySocket")
		FVector PointLocation14;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MySocket")
		FVector PointLocation15;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MySocket")
		FVector PointLocation16;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MySocket")
		FVector PointLocation17;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MySocket")
		FVector PointLocation18;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MySocket")
		FVector PointLocation19;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MySocket")
		FVector PointLocation20;

	//小球的静态网格体
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MySocket")
		UStaticMeshComponent* PSphere;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MySocket")
		UStaticMeshComponent* PSphere1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MySocket")
		UStaticMeshComponent* PSphere2;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MySocket")
		UStaticMeshComponent* PSphere3;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MySocket")
		UStaticMeshComponent* PSphere4;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MySocket")
		UStaticMeshComponent* PSphere5;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MySocket")
		UStaticMeshComponent* PSphere6;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MySocket")
		UStaticMeshComponent* PSphere7;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MySocket")
		UStaticMeshComponent* PSphere8;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MySocket")
		UStaticMeshComponent* PSphere9;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MySocket")
		UStaticMeshComponent* PSphere10;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MySocket")
		UStaticMeshComponent* PSphere11;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MySocket")
		UStaticMeshComponent* PSphere12;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MySocket")
		UStaticMeshComponent* PSphere13;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MySocket")
		UStaticMeshComponent* PSphere14;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MySocket")
		UStaticMeshComponent* PSphere15;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MySocket")
		UStaticMeshComponent* PSphere16;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MySocket")
		UStaticMeshComponent* PSphere17;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MySocket")
		UStaticMeshComponent* PSphere18;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MySocket")
		UStaticMeshComponent* PSphere19;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MySocket")
		UStaticMeshComponent* PSphere20;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SocketArray")
		TArray<FString> LevelArr;

	FString StringFromBinaryArray(TArray<uint8> BinaryArray);
	FSocket* SocketClient;

	FIPv4Address ip;

};
