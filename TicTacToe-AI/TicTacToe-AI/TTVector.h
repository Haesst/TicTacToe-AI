#pragma once
class TTVector
{
public:
	int X;
	int Y;
public:
	TTVector(int x, int y) : X(x), Y(y) {}
	TTVector() : X(0), Y(0) {}

	void SetPosition(int x, int y);
	void SetX(int x);
	void SetY(int y);

	friend bool operator== (const TTVector& v1, const TTVector& v2)
	{
		return v1.X == v2.X && v1.Y == v2.Y;
	}

	friend bool operator< (const TTVector& v1, const TTVector& v2)
	{
		return (v1.X + v1.Y) < (v2.X + v2.Y);
	}

	friend bool operator> (const TTVector& v1, const TTVector& v2)
	{
		return (v1.X + v1.Y) > (v2.X + v2.Y);
	}
};
