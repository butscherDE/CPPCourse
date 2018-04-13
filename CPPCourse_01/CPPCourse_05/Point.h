#pragma once
template<typename T>
class Point
{
public:
	Point(T x, T y) : m_x(x), m_y(y)
	{

	}
	~Point()
	{

	}

	T get_x() const
	{
		return m_x;
	}

	T get_y() const
	{
		return m_y;
	}

	Point<T> add_point(Point<T> that) const
	{
		int x = get_x() + that.get_x();
		int y = get_y() + that.get_y();

		return Point(x, y);
	}

private:
	const T m_x;
	const T m_y;
};

