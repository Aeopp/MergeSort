#include <iostream>
#include <math.h>
#include <vector>
using namespace  std;
void MergeSort(int Arr[], int Left, int Right);
void MergeToArray(int Arr[], int Left, int Mid, int Right)
{
	// Left 와 Right 를 비교 한다 
	// 작은 것을 Left~ Mid  큰것을 Mid + 1 ~ Right 에 담는다.
	// 왼쪽이 더 우선순위가 높다면
	/*if(Arr[Right] > Arr[Left])
	{
		std::swap(Arr[Right], Arr[Left]);
	}*/
	// Left 가 Right 보다 크다면 Left~Mid 까지를 Left 영역으로 정복
	// Mid  + 1   ~  Right 까지를 Right 영역으로 정복
	//if(Arr[Right] > Arr[Left])
	//{
	//	//MergeToArray(Arr,Left,Mid,Right);
	//	for(int i=Left;i<=Mid;++i)
	//	{
	//		std::swap(Arr[i] ,Arr[Mid + i + 1]);
	//	}
	//}
	//
	// Mid(Left) 부분과 Mid + 1 (Right ) 부분을 비교한다.
	// Right 부분이 크다면 Right 부분과 Left 부분을 바꾼다.
	//
	
	//
	//if (Left == Right)return;
	//
	//auto Temp = [&](int lhs, int rhs)
	//{
	//	int Temp = Arr[lhs];
	//	Arr[lhs] = Arr[rhs];
	//	Arr[rhs] = Temp;
	//};
	//
	//if(Left==0 && Right==1)
	//{
	//	if (Arr[1] > Arr[0])
	//	{
	//		Temp(0, 1);
	//		
	//		/*std::swap(Arr[0], Arr[1]);*/
	//	}return;
	//}
	//
	//if (Arr[Mid + 1] > Arr[Mid])
	//{
	//	for(int i=Left;i<=Mid;++i)
	//	{
	//		// std::swap(Arr[i], Arr[i + Mid + 1]);
	//		Temp(i, i + Mid + 1);
	//	}
	//	return;
	//}
	//
	// 병합할 어레이 사이즈 만큼의 새로운 어레이를 만듭니다.
	// ( Right - Mid  ) * 2 으로 사이즈를 잡는다.  (어레이의 사이즈)
	// 왼쪽 어레이와 오른쪽 어레이를 동시에 비교 합니다.
	// 루프의 진행 조건은 Temp(그릇) 의 인덱스가 TempSize 보다 < < < 미만 이여야 하며
	// LArrIndex 가 Mid 보다 작거나 같아야 하며 RArrIndex 가 Right 보다도 작거나 같아야 합니다.
	// 왼쪽과 오른쪽중 우선순위가 큰것을 TempIndex 의 인덱스로 Temp 에 삽입하고
	// TempIndex 를 증가시키고 우선순위가 컸던 것의 배열의 인덱스만 증가시킵니다.
	// LArrIndex 가 Mid 를 > > 초과 한다면
	// RArrIndex 의 값을 후위연산으로 증가시키면서 TempIndex 의 인덱스로 어레이에
	// 삽입합니다.
	 // int TempSize  =  (Right - Mid) * 2;
	  int TempSize  =  Right+1;
	int *Temp= new int[TempSize];
	int TempIndex = Left;
	int LArrIndex = Left;
	int RArrIndex = Mid+1;
	while(TempIndex<=Right) //  && LArrIndex<=Mid && RArrIndex<=Right)
	{
		if(LArrIndex <= Mid && RArrIndex <= Right)
		{
			if (Arr[LArrIndex] >= Arr[RArrIndex])
			{
				Temp[TempIndex++] = Arr[LArrIndex++];
			}
			else
				Temp[TempIndex++] = Arr[RArrIndex++];
		}
		else if(LArrIndex>Mid)
		{
			for (int i = RArrIndex; i <= Right; ++i)
				Temp[TempIndex++] = Arr[i];
			// Temp[TempIndex++] = Arr[RArrIndex++];
		}
		else if(RArrIndex>Right)
		{
			for (int i = LArrIndex; i <= Mid; ++i)
				Temp[TempIndex++] = Arr[i];
			// Temp[TempIndex++] = Arr[LArrIndex++];
		}
	}
	
	for(int i=Left;i<=Right;i++)
	{
		Arr[i] = Temp[i];
	}
	 delete[] Temp;
	 // delete[] Temp;
	//Temp = nullptr;
}
void MergeSort(int Arr[], int Left, int Right)
{
	// 탈출 조건은 Left < Right 가 False 일때
	// 좌 우 분할 한다  Left = Left , Mid  Right = Mid + 1 , Right;
	// Mid = Left + Right / 2 
	// 분할이 끝나면 정복한다
	if (Left < Right)
	{
		int Mid = (Left + Right) / 2;

		MergeSort(Arr, Left, Mid);
		MergeSort(Arr, Mid + 1, Right);

		MergeToArray(Arr, Left, Mid, Right);
	}
	return;
};
using namespace std;

template<class T>
void Test(typename std::vector<T>::iterator tt,std::vector<T> a)
{
	
}

int main()
{
	int Arr[8] = { 4,3,7,1,2,9,10,15};
	for(const auto&E : Arr)
	{
		cout << E << endl;
	}
	cout << endl << endl;
	
	 MergeSort(Arr, 0, 7);
	for (const auto& E : Arr)
	{
		cout << E << endl;
	}
	vector<char>::iterator aa;
	
	Test(aa,vector<char>());
	
}
