//cursor.h
#pragma once
#include<string>
#include<sstream>

using namespace std;
class Cursor
{
public:
	class LongLong{
private:
	long high;
	unsigned long low;

	public:
		long getHigh()const { return high; }
		unsigned long getLow() const { return low; }
		void setHigh(long h) { high = h; }
		void setLow(unsigned long l) { low = l; }

		bool Init(long h, unsigned long l);
		void Read();
		void Display() const;
		string toString()const;

		long long toInt64() const;
		static LongLong fromInt64(long long val);

		LongLong add(const LongLong& r)const;
		LongLong sub(const LongLong& r)const;
		LongLong mul(const LongLong& r)const;
		LongLong div(const LongLong& r)const;
		LongLong mod(const LongLong& r)const;

		bool isGreater(const LongLong& r) const;
		bool isLess(const LongLong& r)const;
		bool isEqual(const LongLong& r)const;
		bool isNotEqual(const LongLong& r)const;
	};
private:
	LongLong x;
	LongLong y;
	string view;
	int size;
	bool visible;

public:
	LongLong getX() const { return x; }
	LongLong getY()const { return y; }
	string getview() const { return view; }
	int getSize() const { return size;}
	bool isVisible() const { return visible; }

	bool setX(const LongLong& newX);
	bool setY(const LongLong& newY);
	bool setView(const string& newView);
	bool setSize(int newSize);

	bool Init(LongLong nx, LongLong ny, string nView, int nSize);
	void Read();
	void Display() const;
	string toString() const;

	void changeCoords(const LongLong& nx, const LongLong& ny);
	void changeView(const string& nView);
	void changeSize(int nSize);
	void hide();
	void restore();

};

