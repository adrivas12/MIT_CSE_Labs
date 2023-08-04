class TwoDShape
{
	private double width, height;
	double getWidth()
	{
		return width;
	}
	double getHeight()
	{
		return height;
	}
	void setWidth(double w)
	{
		width = w;
	}
	void setHeight(double h)
	{
		height = h;
	}
	void show()
	{
		System.out.println("Width and height are " + width + " and "+height);
	}
}

class Triangle extends TwoDShape
{
	String style;
	double area()
	{
		return getWidth()*getHeight()/2;
	}
	Triangle(String s, double w, double h)
	{
		setWidth(w);
		setHeight(h);
		style = s;
	}
	void show()
	{
		super.show();
		System.out.println("Triangle is "+style);
	}
}

class inheritanceEx
{
	public static void main(String[] args)
	{
		Triangle t1 = new Triangle("outlined", 8.0, 12.0);
		Triangle t2 = new Triangle("filled", 4.0, 4.0);
		t1.show();
		t2.show();
	}
}