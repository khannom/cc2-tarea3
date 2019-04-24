#ifndef geometry_h
#define geometry_h 
class Point{
	private:
		int x,y;
	public:
		Point(int x=0,int y=0){this->x=x;this->y=y;}
		int get_x() const{return x;}
		int get_y() const{return y;}
		void set_x(const int new_x){x=new_x;}
		void set_y(const int new_y){y=new_y;} 
		void print();
};

class PointArray{
	private:
		int size;
		Point *pArray;
		void resize(const int n);
	public:
		PointArray(){size=0;pArray=new Point [0];}
		PointArray(const Point points[], const int size);
		PointArray(const PointArray &pv);
		~PointArray();
		void display()const;
		void push_back(const Point &p);
		void insert(const int position, const Point &p);
		void remove(const int pos);
		void clear();
		Point* get(const int position);
		const Point* get(const int position) const;
		int get_size(){return size;}
};

class Polygon{
	protected:
		static int track;
		PointArray points;
	public:
		Polygon(const PointArray &new_points):points(new_points){track++;}
		Polygon(const Point new_points[],const int n):points(new_points,n){track++;}
		Polygon(const Polygon &new_poly):points(new_poly.points){track++;}
		~Polygon(){track--;}
		virtual double area()=0;
		static int getNumPolygons(){return track;}
		int getNumSides(){return points.get_size();}
		const PointArray* getPoints(){return &points;}
		friend void printAttributes(Polygon *poly);
};


class Rectangle : public Polygon{
	public:
		Rectangle(const Point& p1,const Point& p2);
		Rectangle(const int p1x,const int p1y,const int p2x,const int p2y);
		double area();
};

class Triangle : public Polygon{
	public:
		Triangle(const Point& p1, const Point& p2, const Point& p3);
		double area();
};



#endif
