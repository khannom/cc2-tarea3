#include<iostream>
#include<math.h>
#include"geometry.h"
using namespace std;

void Point::print(){
	cout<<"("<<x<<","<<y<<")"<<endl;
}

PointArray::PointArray(const Point points[], const int size){
	pArray = new Point [size];
	this->size=size;
	for(int i=0;i<size;i++){
		pArray[i]=points[i];
	}
}

PointArray::PointArray(const PointArray &pv){
	this->size=pv.size;
	pArray = new Point [size];
	for(int i=0;i<size;i++){
		pArray[i]=(pv.pArray)[i];
	}
}

PointArray::~PointArray(){
	delete [] pArray;
}

void PointArray::display() const {
	for(int i=0;i<size;i++){
		pArray[i].print();
	}
}

void PointArray::resize(const int n){
	Point *aux=new Point [n];
	int min = size>n?n:size;
	for(int i=0;i<min;i++){
		aux[i]=pArray[i];
	}
	size=n;
	delete [] pArray;
	pArray=aux;
}

void PointArray::push_back(const Point &p){
	this->resize(size+1);
	pArray[size-1]=p;
}

void PointArray::insert(const int position, const Point &p){
	if(position>=size || position<0){
		cout<<"Indice fuera de rango.\n";
	}
	else{
		for(int i=size-1;i>=position;i--){
			pArray[i]=pArray[i-1];
		}
		pArray[position]=p;
	}
}

void PointArray::remove(const int pos){
	if(pos>=size || pos<0){
		cout<<"Indice fuera de rango.\n";
	}
	else{
		for(int i=pos;i<size-1;i++){
			pArray[i]=pArray[i+1];
		}
		this->resize(size-1);
	}
}

void PointArray::clear(){
	this->resize(0);
}

Point* PointArray::get(const int position){
	if(position>=size || position<0){
		return NULL;
	}
	else{
		return pArray+position;
	}
}

const Point* PointArray::get(const int position) const{
	if(position>=size || position<0){
		return NULL;
	}
	else{
		return pArray+position;
	}
}

int Polygon::track=0;

Point constructorPoints[4];

Point* updatePoints(const Point& p1, const Point& p2, const Point& p3, const Point& p4=Point(0,0)){
	constructorPoints [0] = p1 ;
	constructorPoints [1] = p2 ;
	constructorPoints [2] = p3 ;
	constructorPoints [3] = p4 ;
	return constructorPoints;
}

Rectangle::Rectangle(const Point& p1,const Point& p2):Polygon(updatePoints(p1,Point(p1.get_x(),p2.get_y()),p2,Point(p2.get_x(),p1.get_y())),4){}

Rectangle::Rectangle(const int p1x,const int p1y,const int p2x,const int p2y):Polygon(updatePoints(Point(p1x,p1y),Point(p1x,p2y),Point(p2x,p2y),Point(p2x,p1y)),4){}

double Rectangle::area(){
	int width = (points.get(2)->get_x())-(points.get(0)->get_x());
	int height = (points.get(2)->get_y())-(points.get(0)->get_y());
	return abs((double)width*height);
}

Triangle::Triangle(const Point& p1, const Point& p2, const Point& p3):Polygon(updatePoints(p1,p2,p3),3){}

double Triangle::area(){
	int dx01 = points.get(0)->get_x() - points.get(1) -> get_x(),
dx12 = points.get(1) -> get_x() - points.get(2) -> get_x(),
dx20 = points.get(2) -> get_x() - points.get(0) -> get_x();

int dy01 = points.get(0) -> get_y() - points.get(1) -> get_y(),
dy12 = points.get(1) -> get_y() - points.get(2) -> get_y(),
dy20 = points.get(2) -> get_y() - points.get(0) -> get_y();

double a = sqrt ( dx01 * dx01 + dy01 * dy01 ) ,
b =  sqrt ( dx12 * dx12 + dy12 * dy12 ) ,
c =  sqrt ( dx20 * dx20 + dy20 * dy20 ) ;
double s = ( a + b + c ) / 2;
return sqrt ( s * (s - a ) * (s - b ) * (s - c ) );
}

void printAttributes(Polygon *poly){
	cout<<"Imprimiendo area y puntos del polígono:\n\n";
	cout<<"El area del poligono es: "<<poly->area()<<endl;
	cout<<"Los puntos del poligono son:\n";
	(poly->getPoints())->display();
}






