/*
     _________
    /___  ___/
       / /
   ___/ /___
  /________/

*/
#include <vector>
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include <iostream>
using namespace std;

int main(){
  /*
  Circle c1(1,1,5);
  Shape f1;
  cout<< c1.draw()<<endl;
  cout<< "El area es: " << c1.area() << endl;
  cout<< c1.draw();
  cout<< "Dibuja la figura"<< endl;
  cout<< f1.draw()<<endl;

  Rectangle r1(1,1,5,4);
  Shape f2;
  cout<< r1.draw()<<endl;
  cout<< "El area es: " << r1.area() << endl;
  cout<< r1.draw();
  cout<< "Dibuja la figura"<< endl;
  cout<< f2.draw()<<endl;
  */

 Circle c1(1,1,5);
 Shape* f1;
 f1 = &c1;
 cout << f1->draw();
 return 0;

 vector<Shape*> figuras;
 figuras.push_back(new Circle(2,3,6));
 figuras.push_back(new Rectangle(4,4,8,5));
 figuras.push_back(new Circle(2,2,3));
 figuras.push_back(new Rectangle(2,2,2,2));
 for(int i = 0; i<4; i++){
   cout << figuras[i]->draw() << " - ";
   cout << figuras[i] << endl;
   cout << figuras[i]->area() << endl;
   if(Circle* ptrCirc = dynamic_cast<Circle*>(figuras[i])){
     cout << "Circunferencia: " << ptrCirc -> circunferencia() << endl;
   }
 }

 cout << "Con for each" <<endl;
 for(auto &ptrFig : figuras){
   cout << ptrFig -> draw();
 }

 }