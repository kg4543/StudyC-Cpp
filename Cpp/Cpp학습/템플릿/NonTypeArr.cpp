#include <stdio.h>

template <typename T,int N>

class Array
{
private:
	T ar[N];

public:
	void SetAt(int n, T v)
	{
		if (n < N && n >= 0)
			ar[n] = v;
	}
	T GetAt(int n)
	{
		return (n < N&& n >= 0 ? ar[n] : 0);
	}
};

void sub12()
{
	Array<int, 5> ari; // 배열 클래스 생성
	ari.SetAt(1, 1234);
	ari.SetAt(1000, 5678);
	printf("%d\n", ari.GetAt(1));
	printf("%d\n", ari.GetAt(5)); 
}