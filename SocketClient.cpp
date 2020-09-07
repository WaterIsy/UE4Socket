// Fill out your copyright notice in the Description page of Project Settings.


#include "Public\SocketClient.h"
#include "Engine\Engine.h"
#include "Runtime\Networking\Public\Networking.h"
#include "Kismet/GameplayStatics.h"
#include "Components/StaticMeshComponent.h"
#include "Math/Vector.h"


// Sets default values
ASocketClient::ASocketClient()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SocketClient = NULL;
}

// Called when the game starts or when spawned
void ASocketClient::BeginPlay()
{
	Super::BeginPlay();

}

void ASocketClient::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	if (SocketClient)
	{
		//关闭，销毁
		SocketClient->Close();
		ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->DestroySocket(SocketClient);
	}

}

// Called every frame
void ASocketClient::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	TArray<AActor*> Actors;
	TArray<UStaticMeshComponent*> ArryActors;
	TArray<UStaticMeshComponent*>Component;
	TSubclassOf< UActorComponent*>test;

	UGameplayStatics::GetAllActorsWithTag(GetWorld(), TEXT("Sphere"), Actors);
	for (AActor* Actor : Actors)
	{
		Actor->GetComponents(Component);
		for (int32 b = 0; b < Component.Num(); b++)
		{
			UStaticMeshComponent* a = Component[b];
			//UE_LOG(LogTemp, Warning, TEXT("%s"), *(a->GetName()));
			//UE_LOG(LogTemp, Warning, TEXT("%s"), *(Sphere->GetName()));

		//	位置索引的顺序表如下：
		// 通过坐标字符串->向量->赋值给小球
			PSphere->SetWorldLocation(PointLocation); PSphere1->SetWorldLocation(PointLocation1); PSphere2->SetWorldLocation(PointLocation2);
			PSphere3->SetWorldLocation(PointLocation3); PSphere4->SetWorldLocation(PointLocation4); PSphere5->SetWorldLocation(PointLocation5);
			PSphere6->SetWorldLocation(PointLocation6); PSphere7->SetWorldLocation(PointLocation7); PSphere8->SetWorldLocation(PointLocation8);
			PSphere9->SetWorldLocation(PointLocation9); PSphere10->SetWorldLocation(PointLocation10); PSphere11->SetWorldLocation(PointLocation11);
			PSphere12->SetWorldLocation(PointLocation12); PSphere13->SetWorldLocation(PointLocation13); PSphere14->SetWorldLocation(PointLocation14);
			PSphere15->SetWorldLocation(PointLocation15); PSphere16->SetWorldLocation(PointLocation16); PSphere17->SetWorldLocation(PointLocation17);
			PSphere18->SetWorldLocation(PointLocation18); PSphere19->SetWorldLocation(PointLocation19); PSphere20->SetWorldLocation(PointLocation20);
			//	Sphere1 = Component[1];
			//	Sphere1->SetWorldLocation(PointLocation1);
		}
	}

}


bool ASocketClient::SocketCreate(FString IPStr, int32 port)
{
	FIPv4Address::Parse(IPStr, ip);

	TSharedRef<FInternetAddr> addr = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();
	addr->SetIp(ip.Value);//ip地址
	addr->SetPort(port);//端口

	SocketClient = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateSocket(NAME_Stream, TEXT("default"), false);

	if (SocketClient->Connect(*addr))
	{
		//在控制台打印连接成功
		GEngine->AddOnScreenDebugMessage(1, 2.0f, FColor::Green, TEXT("Server Connect Succeed!"));
		UE_LOG(LogTemp, Warning, TEXT("Server Connect Succeed!"));
		return true;
	}
	else
	{
		//在控制台打印连接失败
		GEngine->AddOnScreenDebugMessage(1, 2.0f, FColor::Green, TEXT("Server Connect Failed!"));
		UE_LOG(LogTemp, Warning, TEXT("Server Connect Failed!"));
		return false;
	}

}

//Socket发送逻辑
void ASocketClient::SocketSend(FString meesage)
{
	TCHAR* seriallizedChar = meesage.GetCharArray().GetData();
	int32 size = FCString::Strlen(seriallizedChar) + 1;
	int32 sent = 0;

	if (SocketClient->Send((uint8*)TCHAR_TO_UTF8(seriallizedChar), size, sent))
	{
		GEngine->AddOnScreenDebugMessage(1, 2.0f, FColor::Green, TEXT("_Send Succeed!"));
		UE_LOG(LogTemp, Warning, TEXT("_Send Succeed!"));
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(1, 2.0f, FColor::Green, TEXT("_Send Failed!"));
		UE_LOG(LogTemp, Warning, TEXT("_Send Failed!"));
	}
}

//Socket接收逻辑
void ASocketClient::SocketReceive(bool& bReceive, FString& recvMessage)
{
	//留空
	recvMessage = "";
	bReceive = false;

	if (!SocketClient)
	{
		return;
	}
	

	TArray<uint8> ReceiveData;
	uint32 size;
	uint8 element = 0;
	//当连接，则开始接收数据
	while (SocketClient->HasPendingData(size))
	{
		ReceiveData.Init(element, FMath::Min(size, 65507u));

		int32 read = 0;
		SocketClient->Recv(ReceiveData.GetData(), ReceiveData.Num(), read);

	}

	
	if (ReceiveData.Num() <= 0)
	{
		return;
	}
	
	FString log = "Total Data read! num: " + FString::FromInt(ReceiveData.Num() <= 0);

	GEngine->AddOnScreenDebugMessage(1, 2.0f, FColor::Green, log);
	UE_LOG(LogTemp, Warning, TEXT("Recv log:   %s"), *log);

	//转换为Fstring格式 
	const FString ReceivedUE4String = StringFromBinaryArray(ReceiveData);

	GEngine->AddOnScreenDebugMessage(1, 2.0f, FColor::Green, log);

	UE_LOG(LogTemp, Warning, TEXT("*** %s"), *log);

	recvMessage = ReceivedUE4String;

	 FString level = recvMessage;

	 //将字符串按"end"拆分为数组
	 level.ParseIntoArray(LevelArr, TEXT("end"), false);


	 //数组切片，分别放在坐标字符串中
	 Coor_Str0 = LevelArr[0];	 Coor_Str1 = LevelArr[1]; Coor_Str2 = LevelArr[2]; Coor_Str3 = LevelArr[3]; Coor_Str4 = LevelArr[4];
	 Coor_Str5 = LevelArr[5]; Coor_Str6 = LevelArr[6]; Coor_Str7 = LevelArr[7]; Coor_Str8 = LevelArr[8]; Coor_Str9 = LevelArr[9];
	 Coor_Str10 = LevelArr[10]; Coor_Str11 = LevelArr[11]; Coor_Str12 = LevelArr[12]; Coor_Str13 = LevelArr[13]; Coor_Str14 = LevelArr[14];
	 Coor_Str15 = LevelArr[15]; Coor_Str16 = LevelArr[16]; Coor_Str17 = LevelArr[17]; Coor_Str18 = LevelArr[18]; Coor_Str19 = LevelArr[19];
	 Coor_Str20 = LevelArr[20];

	bReceive = true;

	recvData = recvMessage;


}


FString ASocketClient::StringFromBinaryArray(TArray<uint8> BinaryArray)
{
	return FString(ANSI_TO_TCHAR(reinterpret_cast<const char*>(BinaryArray.GetData())));
}


