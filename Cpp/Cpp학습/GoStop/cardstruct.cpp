#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include "cursor.h"
#include <assert.h>
#include <iostream>
using namespace std;

// �Լ� ����

const int Speed = 1000;
const int PromptSpeed = 2000;
const int MaxCard = 48;
const int CardGap = 4;

// ȭ�� ������ ǥ���ϴ� Ŭ����
struct SCard
{
	char Name[4]; // ī�� ���� = '����' + '�ǹ�'
	SCard() { Name[0] = 0; } //�� ī��� �ǰ� ���� ��� ǥ�õ�
	SCard(const char* pName) { //Scard ������ �̸� �޾ƿ���
		strcpy(Name, pName);
	}
	int GetNumber() const { //���� �Ǵ�
		if (isdigit(Name[0])) return Name[0] - '0'; // isdigit(����)�� ���� ����
		if (Name[0] == 'J') return 10; //J(ǳ) 10
		if (Name[0] == 'D') return 11; //D(��) 11
		return 12; //(��)
	};
	int GetKind() const { //���� �Ǵ� (���ڿ� �ǹ̸� ���� '��' = 0 | '��' = 1 | '��' = 2)
		if (strcmp(Name + 1, "��") == 0) return 0; 
		else if (strcmp(Name + 1, "��") == 0) return 1;
		else if (strcmp(Name + 1, "��") == 0) return 2;
		else return 3;
	}
	friend ostream& operator <<(ostream& c, const SCard& C) { // ������ << ����
		return c << C.Name; // SCard.Name ����
	}
	bool operator ==(const SCard& Other) const { // ������ == ����
		return (strcmp(Name, Other.Name) == 0); // �а� ������ �Ǻ�
	}
	bool operator <(const SCard& Other) const { // ������ < ����
		if (GetNumber() < Other.GetNumber()) return true; // ���ڰ� ������ �Ǵ�
		if (GetNumber() > Other.GetNumber()) return false;
		if (GetKind() < Other.GetKind()) return true; 
		return false;
	}
};

// ȭ�� �ʱⰪ
SCard HwaToo[MaxCard] = {
	"1��","1��","1��","1��","2��","2��","2��","2��","3��","3��","3��","3��",
	"4��","4��","4��","4��","5��","5��","5��","5��","6��","6��","6��","6��",
	"7��","7��","7��","7��","8��","8��","8��","8��","9��","9��","9��","9��",
	"J��","J��","J��","J��","D��","D��","D��","D��","B��","B��","B��","B��"
};

//ī���� ����(��,�ٴ���,����)�� �����ϴ� Ŭ����
class CCardSet
{
protected:
	SCard Card[MaxCard]; // ��üī�� �迭
	int Num; // ���� ���տ� ���� ī�� ����
	const int sx, sy; // ī���� ��ġ ��ǥ
	CCardSet(int asx, int asy) : sx(asx), sy(asy) { Num = 0; } // ���� �ʱ�ȭ

public:
	int GetNum() { return Num; } // ī�� ���� �����͸� ���� ����
	SCard GetCard(int idx) { return Card[idx]; } 
	void Reset() { //ī�� �� �ʱ�ȭ
		for (int i = 0; i < MaxCard; i++) Card[i].Name[0] = 0;
		Num = 0;
	}
	//ī�� ������ ����
	void InsertCard(SCard C); // ī�� �߰�
	SCard RemoveCard(int idx); // ī�� ����
	int FindSameCard(SCard C, int* pSame); //���ڰ� ������ �˻�
	int FindFirstCard(const char* pName);
};

void CCardSet::InsertCard(SCard C) { //ī�� �߰� (���� �� �߰� ����)
	int i;

	if (C.Name[0] == 0) return; // ��ī���� ��� ����
	for (i = 0; i < Num; i++) { //ī���� ������ŭ üũ
		if (C < Card[i]) break; //�߰��� ī�庸�� ū ī�带 ã�� �� break
	}
	//memmove : �޸� �̵� �Լ� (�ٿ����� �޸�, ������ �޸�, ������ ����)
	memmove(&Card[i + 1], &Card[i], sizeof(SCard) * (Num - i)); // ���� ī���� �޸𸮸� ���� ī�� �޸𸮿� �߰�
	Card[i] = C; // ����ī�� �ڸ��� �߰��� ī�带 �Ҵ�
	Num++; // ī�� ���� ����
}

SCard CCardSet::RemoveCard(int idx) { // ī�� ����
	assert(idx < Num);
	SCard C = Card[idx];
	// ����ī�带 ����
	memmove(&Card[idx], &Card[idx + 1], sizeof(SCard) * (Num - idx - 1));
	Num--; // ī�� ���� ����
	return C; //������ ī�带 ��ȯ
}

int CCardSet::FindSameCard(SCard C, int* pSame) {
	int i, num;
	int* p = pSame;

	for (i = 0, num = 0; i < Num; i++) {
		if (Card[i].GetNumber() == C.GetNumber()) {  //ī�� ���ڰ� ������ ��
			num++; // ī�尡 ��ġ�ϴ� ��ŭ num����
			*p++ = i;
		}
	}
	*p = -1;
	return num; //���� ����� ���� ��ȯ
}

// �κ� ���ڿ� �˻� ; ���ڳ� ������ ��ġ�ϴ� ������ ī�带 �˻�
int CCardSet::FindFirstCard(const char* pName) { 
	int i;

	for (i = 0; i < Num; i++) {
		if (strstr(Card[i].Name, pName) != NULL) {
			return i; // ��ġ�ϴ� ī���� ÷�ڸ� ����
		}
	}
	return -1; // ��ġ�Ѵ� ī�尡 ���� ��� -1 ��ȯ
}

//�߾ӿ� ī�带 �׾Ƴ��� ��
class CDeck : public CCardSet
{
public:
	CDeck(int asx, int asy) : CCardSet(asx, asy) { ; } //�ʱ�ȭ
	void Shuffle() { // ���� ī�带 �������� ����
		int i, n;
		// ��ü ī���� ������ randomize
		for (i = 0; i < MaxCard; i++) { 
			do {
				n = random(MaxCard);
			} while (Card[n].Name[0] != NULL);
			Card[n] = HwaToo[i]; //ȭ���� �� ī�尡 Card�� ������ġ
			Num++; // ī���� ����
		}
	}
	SCard Pop() { return RemoveCard(Num - 1); } //���� ī�� �̱�
	bool IsEmpty() { return Num == 0; } //ī�尡 0�� ��� ���� ����
	bool IsNotLast() { return Num > 1; } //������ ������ ����
	void Draw(bool bFlip) { // ???�� ���� ȭ�鿡 ǥ��
		gotoxy(sx, sy);
		cout << "??? " << (bFlip ? Card[Num - 1].Name : "   ");
	}
};

//�÷��̾� ����
class CPlayer : public CCardSet
{
public:
	CPlayer(int asx, int asy) : CCardSet(asx, asy) { ; } //�ʱ�ȭ
	void Draw(bool MyTurn) { // ī�� �߰�
		int i, x;
		for (i = 0, x = sx; i < Num; i++, x += CardGap) {
			gotoxy(x, sy);
			cout << Card[i]; // ī�带 ������ ǥ��
			if (MyTurn) { // �ڱ����� ��� �� ī�� �ؿ� ����ǥ��
				gotoxy(x, sy + 1);
				cout << '[' << i + 1 << ']';
			}
		}
	}
};

//���� ���� �ǿ� ��ġ�� ī��
class CBlanket : public CPlayer
{
public:
	CBlanket(int asx, int asy) : CPlayer(asx, asy) { ; }
	void Draw() { 
		CPlayer::Draw(false); //ī�带 ��� �����ֵ� ���� �÷��� ������ ���� �ʾ� false
	}
	void DrawSelNum(int* pSame) {
		int n;
		int* p;
		//2���� ī�带 ���� �� � ���� ���� �� ����
		for (n = 1, p = pSame; *p != -1; p++, n++) { 
			gotoxy(sx + *p * CardGap, sy - 1);
			cout << '[' << n << ']';
		}
	}
	// �÷��̾ �� ī�带 �ٴ� �ǿ� ������
	void DrawTempCard(int idx, SCard C) { 
		gotoxy(sx + idx * CardGap, sy + 1);
		cout << C;
	}
};

//�÷��̾� �ٴ���(����)
class CPlayerPae : public CCardSet
{
private:
	int nGo; //�� Ƚ��

public:
	int OldScore; // �÷��̾� ���ھ�
	CPlayerPae(int asx, int asy) : CCardSet(asx, asy) { OldScore = 6; nGo = 0; } //�ʱ�ȭ
	void Reset() { CCardSet::Reset(); OldScore = 6; nGo = 0; } 
	int GetGo() { return nGo; } // �� Ƚ�� ����
	void IncreaseGo() { nGo++; } // �� Ƚ�� ����
	void Draw();
	SCard RemovePee();
	int CalcScore();
};

void CPlayerPae::Draw() {
	int i, kind;
	int x[4] = { sx,sx,sx,sx }, py = sy + 3;

	for (i = 0; i < Num; i++) {
		kind = Card[i].GetKind(); // ���� ����
		// ī�带 ���� �� ���� x����ġ �̵� , ������ ���� y�� ����
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
	gotoxy(sx + 23, sy); // ���� ǥ��
	cout << "����:" << CalcScore() << "��, " << nGo << "��";
}

SCard CPlayerPae::RemovePee() { 
	//���濡�� �������� �־�� �� ��
	int idx;

	idx = FindFirstCard("��");
	if (idx != -1) {
		return RemoveCard(idx);
	}
	return SCard(); // �ǰ� ���� ���
}

int CPlayerPae::CalcScore() { // ���� ���
	int i, kind, n[4] = { 0, };
	int NewScore;
	static int gscore[] = { 0,0,0,3,4,15 }; //�� ���� ���

	for (i = 0; i < Num; i++) {
		kind = Card[i].GetKind(); // ī�� ������ �޾ƿ�
		n[kind]++; 
	}
	NewScore = gscore[n[0]];
	// �� ���� ��� (�� - 1��)
	if (n[0] == 3 && FindFirstCard("B��") != -1) NewScore--; 
	if (n[1] >= 5) NewScore += (n[1] - 4);
	if (n[2] >= 5) NewScore += (n[2] - 4);
	if (n[3] >= 10) NewScore += (n[3] - 9);
	// ����
	if (FindFirstCard("8��") != -1 && FindFirstCard("5��") != -1 && FindFirstCard("2��") != -1) NewScore += 5;
	//ȫ��
	if (FindFirstCard("1��") != -1 && FindFirstCard("2��") != -1 && FindFirstCard("3��") != -1) NewScore += 3;
	//�ʴ�
	if (FindFirstCard("4��") != -1 && FindFirstCard("5��") != -1 && FindFirstCard("7��") != -1) NewScore += 3;
	//û��
	if (FindFirstCard("9��") != -1 && FindFirstCard("J��") != -1 && FindFirstCard("6��") != -1) NewScore += 3;
	return NewScore;
}

// ���� ����
CDeck Deck(18, 9); //ī�� ��
CPlayer South(5, 20), North(5, 1); //�÷��̾�
CBlanket Blanket(5, 12); //�ٴ� ������
CPlayerPae SouthPae(40, 14), NorthPae(40, 4); //�÷��̾� ����
bool SouthTurn; //�÷��̾� �� Ȯ��

// ����� �Լ�
void Initialize(); //���� ���� �������� ī�带 �������� �÷��̾�� ��ġ
void DrawScreen(); //ȭ���� ����� ��� ��ü�� Draw�Լ��� ���ʷ� ȣ��
void OutPrompt(const char* Mes, int Wait = 0); //���� �� ���� �޽���
int InputInt(const char* Mes, int start, int end); //���� �ϳ��� �Է¹޾� ������ �����Ŵ

// ���α׷��� �������ϴ� main �Լ�
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
	 
	randomize(); //�����߻��� �ʱ�ȭ
	Initialize(); // ī�� �ʱ�ȭ �� �� �й�
	// �÷��� ���� : �÷������� �ٲ㰡�� ���� ī�尡 �ִ� ������ ����
	for (SouthTurn = true; !Deck.IsEmpty(); SouthTurn = !SouthTurn) { 
		DrawScreen(); // �� ��ü�� ȭ�鿡 ǥ��
		if (SouthTurn) { //�÷��̾� ��
			Turn = &South;
			TurnPae = &SouthPae;
			OtherPae = &NorthPae;
		}
		else { //��� �÷��̾� ��
			Turn = &North;
			TurnPae = &NorthPae;
			OtherPae = &SouthPae;
		}

		// �÷��̾� ���� Ȯ��
		sprintf(Mes, "���� ���� ȭ���� �����ϼ���(1~%d,0:����) ", Turn->GetNum()); 
		ch = InputInt(Mes, 0, Turn->GetNum()); // ���� ����
		if (ch == 0) { // ���� Ȯ��
			if (InputInt("���� �����̴ϱ�?(0:��,1:�ƴϿ�)", 0, 1) == 0)
				return;
			else
				continue;
		}

		// �÷��̾ ī�带 ���� ����.
		UserTriple = DeckTriple = false; //������ �ѹ��� ����
		UserIdx = ch - 1;
		UserCard = Turn->GetCard(UserIdx); //UserCard : �÷��̾� ī�忡�� ������ ī��
		SameNum = Blanket.FindSameCard(UserCard, arSame);  //arSame : ��ġ�ϴ� ī��
		switch (SameNum) {
		case 0: // ��ġ�ϴ� ī�尡 ���� ���
			UserSel = -1; // ����ڰ� ������ ī�带 ����
			Blanket.InsertCard(Turn->RemoveCard(UserIdx)); //���� ����
			DrawScreen();
			break;
		case 1: // ��ġ�ϴ� ī�尡 �ϳ��� ���
			UserSel = arSame[0]; // ��ġ�ϴ� ī�带 ����
			break;
		case 2: // ��ġ�ϴ� ī�尡 ������ ���
			if (Blanket.GetCard(arSame[0]) == Blanket.GetCard(arSame[1])) {
				//��ġ�ϴ� ī���� ������ ��ġ
				UserSel = arSame[0];
			}
			else {
				Blanket.DrawSelNum(arSame); //��ġ�ϴ� ī�� �� �Ѱ��� ����
				sprintf(Mes, "� ī�带 �����Ͻðڽ��ϱ�?(1~%d)", SameNum);
				UserSel = arSame[InputInt(Mes, 1, SameNum) - 1];
			}
			break;
		case 3: // 3���� �ѹ��� �Դ� ���
			UserSel = arSame[1];
			UserTriple = true;
			break;
		}
		if (UserSel != -1) {
			Blanket.DrawTempCard(UserSel, UserCard); 
			//�ٴڿ� ��ġ�ϴ� ����� ������
		}
		delay(Speed); // ȭ���� �÷��̾� ���� ���� �ð�(Speed)��ŭ �Ͻ� ����

		// ��ũ���� ������ �����´�.
		Deck.Draw(true);
		delay(Speed);
		DeckCard = Deck.Pop(); // ���� ó�� ī�������� �޾ƿ�
		SameNum = Blanket.FindSameCard(DeckCard, arSame); // ī�尡 ��ġ�ϴ��� Ȯ��
		switch (SameNum) {
		case 0: //��ġ���� �ʴ� ���
			DeckSel = -1; 
			break;
		case 1: 
			DeckSel = arSame[0];
			if (DeckSel == UserSel) { 
				// ��ġ�ϴ� ī�尡 �÷��̾�ī��͵� ������ ���
				if (Deck.IsNotLast()) {
					Blanket.InsertCard(DeckCard);
					Blanket.InsertCard(Turn->RemoveCard(UserIdx));
					OutPrompt("�����߽��ϴ�.", PromptSpeed);
					continue;
				}
				else {
					DeckSel = -1; // ������ �а� ����
				}
			}
			break;
		case 2: //������ ī�尡 ��ġ�ϴ� ���
			if (UserSel == arSame[0]) { // �÷��̾� �п� ��ġ (����)
				DeckSel = arSame[1];
			}
			else if (UserSel == arSame[1]) { // �÷��̾� �п� ��ġ (����)
				DeckSel = arSame[0];
			}
			else { // ��ġ�ϴ� ī���� ������ ������ ���
				if (Blanket.GetCard(arSame[0]) == Blanket.GetCard(arSame[1])) {
					DeckSel = arSame[0];
				}
				else { // ��ġ�ϴ� ī�� �� ���� ����
					Blanket.DrawSelNum(arSame);
					sprintf(Mes, "� ī�带 �����Ͻðڽ��ϱ�?(1~%d)", SameNum);
					DeckSel = arSame[InputInt(Mes, 1, SameNum) - 1];
				}
			}
			break;
		case 3: // �ٴ��� ������ ��ġ�ϴ� ���
			DeckSel = arSame[1];
			DeckTriple = true;
			break;
		}
		if (DeckSel != -1) {
			Blanket.DrawTempCard(DeckSel, DeckCard); 
		}
		//ī���� ��ġ�� �÷��̾�� �����ش�.
		Deck.Draw(false);
		delay(Speed);

		// ��ġ�ϴ� ī�带 �ŵ� ���δ�. �� ���� ���� ���� ���� ���� �´�.
		if (UserSel != -1) {
			// ������ ���
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
			// ������ ���
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

		// ��, ����, �Ͼ��� ������ �����ϰ� ������ �Ǹ� ���´�.
		nSnatch = 0;
		if (Deck.IsNotLast()) {
			if (UserSel == -1 && SameNum == 1 && DeckCard.GetNumber() == UserCard.GetNumber()) {
				nSnatch++;
				OutPrompt("���Դϴ�.", PromptSpeed);
			}
			if (UserSel != -1 && SameNum == 2 && DeckCard.GetNumber() == UserCard.GetNumber()) {
				nSnatch++;
				OutPrompt("�����Դϴ�.", PromptSpeed);
			}
			if (Blanket.GetNum() == 0) {
				nSnatch++;
				OutPrompt("�Ͼ����Դϴ�.", PromptSpeed);
			}
			if (UserTriple || DeckTriple) {
				OutPrompt("�Ѳ����� �� ���� �Ծ����ϴ�.", PromptSpeed);
				nSnatch += UserTriple + DeckTriple;
			}
		}
		for (i = 0; i < nSnatch; i++) {
			TurnPae->InsertCard(OtherPae->RemovePee());
		}

		// ������ ����ϰ� ��, ���� ���θ� �����Ѵ�.
		NewScore = TurnPae->CalcScore(); //�÷��̾� ���ھ� ���
		if (Deck.IsNotLast() && NewScore > TurnPae->OldScore) { //������ 6���� ����
			DrawScreen();
			// �� / ���� ����
			if (InputInt("�߰� ������ ȹ���߽��ϴ�.(0:����, 1:���)", 0, 1) == 1) {
				TurnPae->OldScore = NewScore;
				TurnPae->IncreaseGo();
			}
			else {
				break;
			}
		}
	}
	DrawScreen();
	OutPrompt("������ �������ϴ�.", 0);
}

// �߰� �Լ�
void Initialize()
{
	int i;

	Deck.Shuffle(); //�� �ʱ�ȭ
	for (i = 0; i < 10; i++) {
		//������ �÷��̾� �� �̱�
		South.InsertCard(Deck.Pop()); 
		North.InsertCard(Deck.Pop());
		//�ٴ��� �̱�
		if (i < 8) Blanket.InsertCard(Deck.Pop());
	}
}

//�� ��Ȳ ȭ�� ���
void DrawScreen() 
{
	clrscr(); //ȭ���� �����
	South.Draw(SouthTurn);
	North.Draw(!SouthTurn);
	Blanket.Draw();
	Deck.Draw(false);
	SouthPae.Draw();
	NorthPae.Draw();
}

//�޽��� ����
void OutPrompt(const char* Mes, int Wait/*=0*/) 
{
	gotoxy(5, 23);
	for (int i = 5; i < 79; i++) { cout << ' '; }
	gotoxy(5, 23);
	cout << Mes; //�޽��� ���
	delay(Wait); //�Ͻ� ����
}

int InputInt(const char* Mes, int start, int end)
{
	int ch;

	OutPrompt(Mes);
	for (;;) {
		ch = tolower(_getch()); //tolower: �ҹ��ڷ� ��ȯ
		if (ch == 0xE0 || ch == 0) {
			ch = _getch();
			continue;
		}
		// a ���� �Է½� 10���� �� ���� ���ڴ� �� �״�� ��ȯ
		if (!(isdigit(ch) || ch == 'a')) continue; 
		if (ch == 'a') ch = 10; else ch = ch - '0';
		if (ch >= start && ch <= end) {
			return ch;
		}
		OutPrompt("��ȿ�� ��ȣ�Դϴ�. ������ ������ �°� �ٽ� �Է��� �ּ���."); //���� ó��
	}
}