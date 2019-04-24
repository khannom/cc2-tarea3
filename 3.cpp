#include<iostream>
#include"geometry.h"
using namespace std;

int main(){
	Point p[3];
	cout<<"Ingrese los puntos de la esquina inferior izquierda y de la esquina superior derecha del rectangulo:\n";
	for(int i=0;i<2;i++){
		int x,y;
		cout<<"Ingrese la coordenada x e y:";cin>>x>>y;
		p[i].set_x(x);p[i].set_y(y);
	}
	Rectangle r1(p[0],p[1]);
	Polygon *a=&r1;
	printAttributes(a);
	cout<<"Ingrese los puntos de los vertices de un triangulo:\n";
	for(int i=0;i<3;i++){
		int x,y;
		cout<<"Ingrese la coordenada x e y:";cin>>x>>y;
		p[i].set_x(x);p[i].set_y(y);
	}
	Triangle t1(p[0],p[1],p[2]);
	a=&t1;
	printAttributes(a);
	return 0;
}
