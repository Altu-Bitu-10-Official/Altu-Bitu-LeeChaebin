#include<iostream>
#include<cmath>
using namespace std;
/*
D: 다이어트 기간 
W0: 다이어트 전 체중 g
I0: 다이어트 전 일일에너지섭취량 (=일일기초대사량)
A0: 다이어트 전 일일활동대사량 =0Kcal
T: 기초대사량변화역치
I: 다이어트 중 일일에너지섭취량
A: 다이어트 중 일일활동대사량
dW 체중변화: +(일일에너지섭취량 - 일일에너지소비량)g/Kcal
|체중변화| > T: 일일기초대사량 + ⌊ 체중변화 / 2 ⌋ (소수점 버린다 ->floor)
일일에너지소비량: 일일기초대사량 + 일일활동대사량
사망: 체중<=0g or 일일기초대사량<=0Kcal ("Danger Diet"출력)
요요: 일일기초대사량 비교 >0 ("YOYO" 출력)
*/
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	//곱하기 or 숫자가 커지면(20억 이상) long long 쓰는 것이 안전
	long long W0, I0, T;
	long long D, I, A;

	cin >> W0 >> I0 >> T;
	cin >> D >> I >> A;

	//1-1. 기초 대사량(I0) 변화X -> 체중, 일일기초대사량
	long long W1 = W0; //체중, 체중변화
	W1 += (I - (I0 + A)) * D;

	if (W1 <= 0) //I0는 변하지 않았기 때문에 조건에서 생략 가능
		cout << "Danger Diet\n";
	else
		cout << W1 << " " << I0<<"\n";

	//1-2. 기초 대사량 변화O- 체중, 일일기초대사량
	long long W2 = W0;
	long long I2 = I0; //일일기초대사량
	for (int i = 0; i < D; i++) {
		long long dW = I - (I2 + A);
		W2 += dW;

		//	if (dW < 0)
		//		dW = -dW; -> 이렇게 짜면 I2 업데이트할 때 오류		
		if (abs(dW) > T)
			I2 += floor((double)dW / 2.0);


		if (W2 <= 0 || I2 <= 0) {
			cout << "Danger Diet\n";
			break;
		}
	}
	
	cout << W2 << " " << I2 << " ";
	if (I0 - I2 > 0)
		cout << "YOYO";
	else
		cout << "NO";

	return 0;
}
