#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include "cursor.h"
#include <assert.h>
#include <iostream>
using namespace std;

// 함수 원형

const int Speed = 1000;
const int PromptSpeed = 2000;
const int MaxCard = 48;
const int CardGap = 4;

// 화투 한장을 표현하는 클래스
struct SCard
{
	char Name[4]; // 카드 한장 = '숫자' + '의미'
	SCard() { Name[0] = 0; } //빈 카드는 피가 없을 경우 표시됨
	SCard(const char* pName) { //Scard 생성자 이름 받아오기
		strcpy(Name, pName);
	}
	int GetNumber() const { //숫자 판단
		if (isdigit(Name[0])) return Name[0] - '0'; // isdigit(숫자)를 리턴 받음
		if (Name[0] == 'J') return 10; //J(풍) 10
		if (Name[0] == 'D') return 11; //D(똥) 11
		return 12; //(비)
	};
	int GetKind() const { //종류 판단 (숫자와 의미를 매핑 '광' = 0 | '십' = 1 | '오' = 2)
		if (strcmp(Name + 1, "광") == 0) return 0; 
		else if (strcmp(Name + 1, "십") == 0) return 1;
		else if (strcmp(Name + 1, "오") == 0) return 2;
		else return 3;
	}
	friend ostream& operator <<(ostream& c, const SCard& C) { // 연산자 << 설정
		return c << C.Name; // SCard.Name 전달
	}
	bool operator ==(const SCard& Other) const { // 연산자 == 설정
		return (strcmp(Name, Other.Name) == 0); // 패가 같은지 판별
	}
	bool operator <(const SCard& Other) const { // 연산자 < 설정
		if (GetNumber() < Other.GetNumber()) return true; // 숫자가 높은지 판단
		if (GetNumber() > Other.GetNumber()) return false;
		if (GetKind() < Other.GetKind()) return true; 
		return false;
	}
};

// 화투 초기값
SCard HwaToo[MaxCard] = {
	"1광","1오","1피","1피","2십","2오","2피","2피","3광","3오","3피","3피",
	"4십","4오","4피","4피","5십","5오","5피","5피","6십","6오","6피","6피",
	"7십","7오","7피","7피","8광","8십","8피","8피","9십","9오","9피","9피",
	"J십","J오","J피","J피","D광","D피","D피","D피","B광","B십","B오","B피"
};

//카드의 집합(덱,바닥패,손패)을 관리하는 클래스
class CCardSet
{
protected:
	SCard Card[MaxCard]; // 전체카드 배열
	int Num; // 현재 집합에 속한 카드 갯수
	const int sx, sy; // 카드의 위치 좌표
	CCardSet(int asx, int asy) : sx(asx), sy(asy) { Num = 0; } // 생성 초기화

public:
	int GetNum() { return Num; } // 카드 숫자 데이터를 전달 받음
	SCard GetCard(int idx) { return Card[idx]; } 
	void Reset() { //카드 값 초기화
		for (int i = 0; i < MaxCard; i++) Card[i].Name[0] = 0;
		Num = 0;
	}
	//카드 집합을 관리
	void InsertCard(SCard C); // 카드 추가
	SCard RemoveCard(int idx); // 카드 제거
	int FindSameCard(SCard C, int* pSame); //숫자가 같은지 검사
	int FindFirstCard(const char* pName);
};

void CCardSet::InsertCard(SCard C) { //카드 추가 (정렬 후 중간 삽입)
	int i;

	if (C.Name[0] == 0) return; // 빈카드일 경우 리턴
	for (i = 0; i < Num; i++) { //카드의 갯수만큼 체크
		if (C < Card[i]) break; //추가한 카드보다 큰 카드를 찾을 때 break
	}
	//memmove : 메모리 이동 함수 (붙여넣을 메모리, 복사할 메모리, 복사할 길이)
	memmove(&Card[i + 1], &Card[i], sizeof(SCard) * (Num - i)); // 기존 카드의 메모리를 다음 카드 메모리에 추가
	Card[i] = C; // 기존카드 자리에 추가한 카드를 할당
	Num++; // 카드 갯수 증가
}

SCard CCardSet::RemoveCard(int idx) { // 카드 제거
	assert(idx < Num);
	SCard C = Card[idx];
	// 지정카드를 제거
	memmove(&Card[idx], &Card[idx + 1], sizeof(SCard) * (Num - idx - 1));
	Num--; // 카드 갯수 감소
	return C; //제거한 카드를 반환
}

int CCardSet::FindSameCard(SCard C, int* pSame) {
	int i, num;
	int* p = pSame;

	for (i = 0, num = 0; i < Num; i++) {
		if (Card[i].GetNumber() == C.GetNumber()) {  //카드 숫자가 같은지 비교
			num++; // 카드가 일치하는 만큼 num증가
			*p++ = i;
		}
	}
	*p = -1;
	return num; //같은 경우의 수를 반환
}

// 부분 문자열 검색 ; 숫자나 종류가 일치하는 최초의 카드를 검색
int CCardSet::FindFirstCard(const char* pName) { 
	int i;

	for (i = 0; i < Num; i++) {
		if (strstr(Card[i].Name, pName) != NULL) {
			return i; // 일치하는 카드의 첨자를 리턴
		}
	}
	return -1; // 일치한는 카드가 없을 경우 -1 반환
}

//중앙에 카드를 쌓아놓는 덱
class CDeck : public CCardSet
{
public:
	CDeck(int asx, int asy) : CCardSet(asx, asy) { ; } //초기화
	void Shuffle() { // 받을 카드를 램덤으로 셔플
		int i, n;
		// 전체 카드의 순서를 randomize
		for (i = 0; i < MaxCard; i++) { 
			do {
				n = random(MaxCard);
			} while (Card[n].Name[0] != NULL);
			Card[n] = HwaToo[i]; //화투의 각 카드가 Card로 랜덤배치
			Num++; // 카드의 갯수
		}
	}
	SCard Pop() { return RemoveCard(Num - 1); } //덱에 카드 뽑기
	bool IsEmpty() { return Num == 0; } //카드가 0일 경우 게임 종료
	bool IsNotLast() { return Num > 1; } //마지막 턴인지 구분
	void Draw(bool bFlip) { // ???로 덱을 화면에 표시
		gotoxy(sx, sy);
		cout << "??? " << (bFlip ? Card[Num - 1].Name : "   ");
	}
};

//플레이어 손패
class CPlayer : public CCardSet
{
public:
	CPlayer(int asx, int asy) : CCardSet(asx, asy) { ; } //초기화
	void Draw(bool MyTurn) { // 카드 추가
		int i, x;
		for (i = 0, x = sx; i < Num; i++, x += CardGap) {
			gotoxy(x, sy);
			cout << Card[i]; // 카드를 정보를 표기
			if (MyTurn) { // 자기턴일 경우 각 카드 밑에 숫자표기
				gotoxy(x, sy + 1);
				cout << '[' << i + 1 << ']';
			}
		}
	}
};

//게임 진행 판에 위치한 카드
class CBlanket : public CPlayer
{
public:
	CBlanket(int asx, int asy) : CPlayer(asx, asy) { ; }
	void Draw() { 
		CPlayer::Draw(false); //카드를 계속 보여주되 실제 플레이 진행은 하지 않아 false
	}
	void DrawSelNum(int* pSame) {
		int n;
		int* p;
		//2장의 카드를 먹을 때 어떤 것을 먹을 지 선택
		for (n = 1, p = pSame; *p != -1; p++, n++) { 
			gotoxy(sx + *p * CardGap, sy - 1);
			cout << '[' << n << ']';
		}
	}
	// 플레이어가 낸 카드를 바닥 판에 보여줌
	void DrawTempCard(int idx, SCard C) { 
		gotoxy(sx + idx * CardGap, sy + 1);
		cout << C;
	}
};

//플레이어 바닥패(점수)
class CPlayerPae : public CCardSet
{
private:
	int nGo; //고 횟수

public:
	int OldScore; // 플레이어 스코어
	CPlayerPae(int asx, int asy) : CCardSet(asx, asy) { OldScore = 6; nGo = 0; } //초기화
	void Reset() { CCardSet::Reset(); OldScore = 6; nGo = 0; } 
	int GetGo() { return nGo; } // 고 횟수 리턴
	void IncreaseGo() { nGo++; } // 고 횟수 증가
	void Draw();
	SCard RemovePee();
	int CalcScore();
};

void CPlayerPae::Draw() {
	int i, kind;
	int x[4] = { sx,sx,sx,sx }, py = sy + 3;

	for (i = 0; i < Num; i++) {
		kind = Card[i].GetKind(); // 종류 구분
		// 카드를 먹을 때 마다 x값위치 이동 , 종류에 따라 y값 변경
		if (kind < 3) {
			gotoxy(x[kind], sy + kind); 
			x[kind] += CardGap;
		}
		else {
			gotoxy(x[3], py);
			x[3] += CardGap;
			if (x[3] > 75) {
				x[3] = sx;
				py++;
			}
		}
		cout << Card[i];
	}
	gotoxy(sx + 23, sy); // 점수 표시
	cout << "점수:" << CalcScore() << "점, " << nGo << "고";
}

SCard CPlayerPae::RemovePee() { 
	//상대방에게 피한장을 주어야 할 때
	int idx;

	idx = FindFirstCard("피");
	if (idx != -1) {
		return RemoveCard(idx);
	}
	return SCard(); // 피가 없을 경우
}

int CPlayerPae::CalcScore() { // 점수 계산
	int i, kind, n[4] = { 0, };
	int NewScore;
	static int gscore[] = { 0,0,0,3,4,15 }; //광 점수 계산

	for (i = 0; i < Num; i++) {
		kind = Card[i].GetKind(); // 카드 종류를 받아옴
		n[kind]++; 
	}
	NewScore = gscore[n[0]];
	// 광 점수 계산 (비광 - 1점)
	if (n[0] == 3 && FindFirstCard("B광") != -1) NewScore--; 
	if (n[1] >= 5) NewScore += (n[1] - 4);
	if (n[2] >= 5) NewScore += (n[2] - 4);
	if (n[3] >= 10) NewScore += (n[3] - 9);
	// 고도리
	if (FindFirstCard("8십") != -1 && FindFirstCard("5십") != -1 && FindFirstCard("2십") != -1) NewScore += 5;
	//홍단
	if (FindFirstCard("1오") != -1 && FindFirstCard("2오") != -1 && FindFirstCard("3오") != -1) NewScore += 3;
	//초단
	if (FindFirstCard("4오") != -1 && FindFirstCard("5오") != -1 && FindFirstCard("7오") != -1) NewScore += 3;
	//청단
	if (FindFirstCard("9오") != -1 && FindFirstCard("J오") != -1 && FindFirstCard("6오") != -1) NewScore += 3;
	return NewScore;
}

// 전역 변수
CDeck Deck(18, 9); //카드 덱
CPlayer South(5, 20), North(5, 1); //플레이어
CBlanket Blanket(5, 12); //바닥 게임판
CPlayerPae SouthPae(40, 14), NorthPae(40, 4); //플레이어 손패
bool SouthTurn; //플레이어 턴 확인

// 도우미 함수
void Initialize(); //덱을 섞어 무작위로 카드를 무작위로 플레이어에게 배치
void DrawScreen(); //화면을 지우고 모든 객체의 Draw함수를 차례로 호출
void OutPrompt(const char* Mes, int Wait = 0); //상태 및 지시 메시지
int InputInt(const char* Mes, int start, int end); //정수 하나를 입력받아 게임을 진행시킴

// 프로그램을 총지휘하는 main 함수
void main()
{
	int i, ch;
	int arSame[4], SameNum;
	char Mes[256];
	CPlayer* Turn;
	CPlayerPae* TurnPae, * OtherPae;
	int UserIdx, UserSel, DeckSel;
	SCard UserCard, DeckCard;
	bool UserTriple, DeckTriple;
	int nSnatch;
	int NewScore;
	 
	randomize(); //난수발생기 초기화
	Initialize(); // 카드 초기화 및 패 분배
	// 플레이 진행 : 플레이턴을 바꿔가며 덱에 카드가 있는 경우까지 진행
	for (SouthTurn = true; !Deck.IsEmpty(); SouthTurn = !SouthTurn) { 
		DrawScreen(); // 각 객체를 화면에 표기
		if (SouthTurn) { //플레이어 턴
			Turn = &South;
			TurnPae = &SouthPae;
			OtherPae = &NorthPae;
		}
		else { //상대 플레이어 턴
			Turn = &North;
			TurnPae = &NorthPae;
			OtherPae = &SouthPae;
		}

		// 플레이어 지시 확인
		sprintf(Mes, "내고 싶은 화투를 선택하세요(1~%d,0:종료) ", Turn->GetNum()); 
		ch = InputInt(Mes, 0, Turn->GetNum()); // 손패 선택
		if (ch == 0) { // 종료 확인
			if (InputInt("정말 끝낼겁니까?(0:예,1:아니오)", 0, 1) == 0)
				return;
			else
				continue;
		}

		// 플레이어가 카드를 한장 낸다.
		UserTriple = DeckTriple = false; //세장을 한번에 먹음
		UserIdx = ch - 1;
		UserCard = Turn->GetCard(UserIdx); //UserCard : 플레이어 카드에서 선택한 카드
		SameNum = Blanket.FindSameCard(UserCard, arSame);  //arSame : 일치하는 카드
		switch (SameNum) {
		case 0: // 일치하는 카드가 없는 경우
			UserSel = -1; // 사용자가 선택한 카드를 대입
			Blanket.InsertCard(Turn->RemoveCard(UserIdx)); //손패 감소
			DrawScreen();
			break;
		case 1: // 일치하는 카드가 하나인 경우
			UserSel = arSame[0]; // 일치하는 카드를 대입
			break;
		case 2: // 일치하는 카드가 복수인 경우
			if (Blanket.GetCard(arSame[0]) == Blanket.GetCard(arSame[1])) {
				//일치하는 카드의 종류도 일치
				UserSel = arSame[0];
			}
			else {
				Blanket.DrawSelNum(arSame); //일치하는 카드 중 한개를 선택
				sprintf(Mes, "어떤 카드를 선택하시겠습니까?(1~%d)", SameNum);
				UserSel = arSame[InputInt(Mes, 1, SameNum) - 1];
			}
			break;
		case 3: // 3장을 한번에 먹는 경우
			UserSel = arSame[1];
			UserTriple = true;
			break;
		}
		if (UserSel != -1) {
			Blanket.DrawTempCard(UserSel, UserCard); 
			//바닥에 일치하는 모습을 보여줌
		}
		delay(Speed); // 화면을 플레이어 보기 위해 시간(Speed)만큼 일시 정지

		// 데크에서 한장을 뒤집는다.
		Deck.Draw(true);
		delay(Speed);
		DeckCard = Deck.Pop(); // 덱에 처음 카드한장을 받아옴
		SameNum = Blanket.FindSameCard(DeckCard, arSame); // 카드가 일치하는지 확인
		switch (SameNum) {
		case 0: //일치하지 않는 경우
			DeckSel = -1; 
			break;
		case 1: 
			DeckSel = arSame[0];
			if (DeckSel == UserSel) { 
				// 일치하는 카드가 플레이어카드와도 동일한 경우
				if (Deck.IsNotLast()) {
					Blanket.InsertCard(DeckCard);
					Blanket.InsertCard(Turn->RemoveCard(UserIdx));
					OutPrompt("설사했습니다.", PromptSpeed);
					continue;
				}
				else {
					DeckSel = -1; // 가져올 패가 없다
				}
			}
			break;
		case 2: //복수의 카드가 일치하는 경우
			if (UserSel == arSame[0]) { // 플레이어 패와 일치 (따닥)
				DeckSel = arSame[1];
			}
			else if (UserSel == arSame[1]) { // 플레이어 패와 일치 (따닥)
				DeckSel = arSame[0];
			}
			else { // 일치하는 카드의 종류가 동일한 경우
				if (Blanket.GetCard(arSame[0]) == Blanket.GetCard(arSame[1])) {
					DeckSel = arSame[0];
				}
				else { // 일치하는 카드 중 한장 선택
					Blanket.DrawSelNum(arSame);
					sprintf(Mes, "어떤 카드를 선택하시겠습니까?(1~%d)", SameNum);
					DeckSel = arSame[InputInt(Mes, 1, SameNum) - 1];
				}
			}
			break;
		case 3: // 바닥의 세개와 일치하는 경우
			DeckSel = arSame[1];
			DeckTriple = true;
			break;
		}
		if (DeckSel != -1) {
			Blanket.DrawTempCard(DeckSel, DeckCard); 
		}
		//카드의 일치를 플레이어에게 보여준다.
		Deck.Draw(false);
		delay(Speed);

		// 일치하는 카드를 거둬 들인다. 세 장을 먹은 경우는 전부 가져 온다.
		if (UserSel != -1) {
			// 세장일 경우
			if (UserTriple) {
				for (i = 0; i < 3; i++) {
					TurnPae->InsertCard(Blanket.RemoveCard(UserSel - 1));
				}
			}
			else {
				TurnPae->InsertCard(Blanket.RemoveCard(UserSel));
			}
			TurnPae->InsertCard(Turn->RemoveCard(UserIdx));
			if (DeckSel != -1 && DeckSel > UserSel) {
				DeckSel -= (UserTriple ? 3 : 1);
			}
		}
		if (DeckSel != -1) {
			// 세장일 경우
			if (DeckTriple) {
				for (i = 0; i < 3; i++) {
					TurnPae->InsertCard(Blanket.RemoveCard(DeckSel - 1));
				}
			}
			else {
				TurnPae->InsertCard(Blanket.RemoveCard(DeckSel));
			}
			TurnPae->InsertCard(DeckCard);
		}
		else {
			Blanket.InsertCard(DeckCard);
		}

		// 쪽, 따닥, 싹쓸이 조건을 점검하고 상대방의 피를 뺏는다.
		nSnatch = 0;
		if (Deck.IsNotLast()) {
			if (UserSel == -1 && SameNum == 1 && DeckCard.GetNumber() == UserCard.GetNumber()) {
				nSnatch++;
				OutPrompt("쪽입니다.", PromptSpeed);
			}
			if (UserSel != -1 && SameNum == 2 && DeckCard.GetNumber() == UserCard.GetNumber()) {
				nSnatch++;
				OutPrompt("따닥입니다.", PromptSpeed);
			}
			if (Blanket.GetNum() == 0) {
				nSnatch++;
				OutPrompt("싹쓸이입니다.", PromptSpeed);
			}
			if (UserTriple || DeckTriple) {
				OutPrompt("한꺼번에 세 장을 먹었습니다.", PromptSpeed);
				nSnatch += UserTriple + DeckTriple;
			}
		}
		for (i = 0; i < nSnatch; i++) {
			TurnPae->InsertCard(OtherPae->RemovePee());
		}

		// 점수를 계산하고 고, 스톱 여부를 질문한다.
		NewScore = TurnPae->CalcScore(); //플레이어 스코어 계산
		if (Deck.IsNotLast() && NewScore > TurnPae->OldScore) { //점수가 6점을 넘음
			DrawScreen();
			// 고 / 스톱 결정
			if (InputInt("추가 점수를 획득했습니다.(0:스톱, 1:계속)", 0, 1) == 1) {
				TurnPae->OldScore = NewScore;
				TurnPae->IncreaseGo();
			}
			else {
				break;
			}
		}
	}
	DrawScreen();
	OutPrompt("게임이 끝났습니다.", 0);
}

// 추가 함수
void Initialize()
{
	int i;

	Deck.Shuffle(); //덱 초기화
	for (i = 0; i < 10; i++) {
		//덱에서 플레이어 패 뽑기
		South.InsertCard(Deck.Pop()); 
		North.InsertCard(Deck.Pop());
		//바닥패 뽑기
		if (i < 8) Blanket.InsertCard(Deck.Pop());
	}
}

//현 상황 화면 출력
void DrawScreen() 
{
	clrscr(); //화면을 지우기
	South.Draw(SouthTurn);
	North.Draw(!SouthTurn);
	Blanket.Draw();
	Deck.Draw(false);
	SouthPae.Draw();
	NorthPae.Draw();
}

//메시지 전달
void OutPrompt(const char* Mes, int Wait/*=0*/) 
{
	gotoxy(5, 23);
	for (int i = 5; i < 79; i++) { cout << ' '; }
	gotoxy(5, 23);
	cout << Mes; //메시지 출력
	delay(Wait); //일시 정지
}

int InputInt(const char* Mes, int start, int end)
{
	int ch;

	OutPrompt(Mes);
	for (;;) {
		ch = tolower(_getch()); //tolower: 소문자로 변환
		if (ch == 0xE0 || ch == 0) {
			ch = _getch();
			continue;
		}
		// a 값을 입력시 10으로 그 이하 숫자는 값 그대로 반환
		if (!(isdigit(ch) || ch == 'a')) continue; 
		if (ch == 'a') ch = 10; else ch = ch - '0';
		if (ch >= start && ch <= end) {
			return ch;
		}
		OutPrompt("무효한 번호입니다. 지정한 범위에 맞게 다시 입력해 주세요."); //예외 처리
	}
}