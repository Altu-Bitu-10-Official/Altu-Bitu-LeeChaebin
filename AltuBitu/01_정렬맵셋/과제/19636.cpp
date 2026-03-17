#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
//D일 다이어트
//다이어트 전 체중 W0g
//일일 에너지 섭취량 I0Kcal -> IKcal
//= 일일 기초 대사량
//일일 활동 대사량 A0 = 0Kcal -> AKcal
//체중 -> + (일일에너지섭취량-일일에너지소비량) g/Kcal
//일일에너지소비량 = 일일기초대사량+일일활동대사량
//|(일일 에너지 섭취량 − 일일 에너지 소비량)|이 기초 대사량 변화 역치 T Kcal 초과라면, 
//일일 기초 대사량은 L (일일 에너지 섭취량 − 일일 에너지 소비량) / 2 ⌋ 만큼 더해진다.
//체중이 0 g 이하인 경우, 일일 기초 대사량이 0 Kcal 이하인 경우 -> 사망
//일일 기초 대사량의 변화를 고려하지 않았을 때와 일일 기초 대사량의 변화를 고려했을 때 
//1. 각각의 예상 체중과 일일 기초 대사량
//2. 다이어트 전 데시의 원래 생활로 돌아간다면 몸무게가 증가하는 요요 현상이 일어날지

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	//곱하기 or 숫자가 커지면(20억 이상) long long 쓰는 것이 안전

	long long w0, i0, t;
	//전 체중, 전 일일에너지섭취량 일일기초대사량, 기초대사량 변화역치
	cin >> w0 >> i0 >> t;

	long long d, i, a;
	//다이어트기간, 일일에너지섭취량, 일일활동대사량
	cin >> d >> i >> a;

	//1-1. 기초 대사량 변화 고려X
	long long w1 = w0;
	w1 = w0 + (i - (i0 + a)) * d;

	if (w1 <= 0 || i0 <= 0)
		cout << "Danger Diet";
	else
		cout << w1 << " " << i0;

	//1-2. 기초 대사량 변화 고려O
	long long w2 = w0;
	long long i2 = i0;

	




	return 0;
}