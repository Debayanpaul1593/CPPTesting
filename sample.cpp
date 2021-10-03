#include<iostream>
#include<string>
#define add(a, b) a + b
#define multiply(a, b) a*b
#define divide(a, b) a/b
#define subtract(a, b) a-b
#define rem(a, b) a%b
#define deb(a) cout<<#a<<" "<<a<<endl;
#define println(a) cout<<a<<endl;
#define print(a) cout<<a;
#define log(a, b) cout<<a<<" "<<b<<endl; 
#define fo(n) for(int i = 0; i<n; i++)
#define PI 3.14159265
//#define pA(arr) (for(int i=0; i<arr.length; i++) print(arr[i] + ", "))
using namespace std;
class Rect{
int width, height;
public:
  Rect();
  Rect(int, int);
  void set_values(int, int);
  int get_area(){
    return width * height;
  }
};

Rect::Rect(){
  width = 5;
  height = 5;
}

//overloaded constructor
Rect::Rect(int a, int b){
  width = a;
  height = b;
}

void Rect::set_values(int _width, int _height){
  width = _width;
  height = _height;
}

class Circle{
  double radius;
public:
  Circle(double r){ radius = r; }
  double circumference(){ return 2 * PI * radius; }
};

class Triangle{
  int height;
  int base;
public:
  Triangle(int, int);
  double area(){
    return 0.5 * base * height;
  }
};

Triangle:: Triangle(int b, int h):base(b), height(h){};

int main(){
  println(add(5, 6));
  println(multiply(7, 8));
  println(subtract(9, 4));
  println(divide(7, 4));
  println(rem(7, 4));

  //classes

  Rect rect, rect2;
  Rect rect3 (5, 6);
  rect.set_values(5, 3);
  println(rect.get_area());
  println(rect2.get_area());
  println(rect3.get_area());

  fo(6) println("Hello");
  int arr[5] = {6, 8, 12, 45, 22};
  //pA(arr);

  //methods of initialisation
  Circle circle1(5.0);//functional declaration, def constr not called
  Circle circle2 = 4.0;
  Circle circle3 {3.0};//uniform initialisation, def constr called
  Circle circle4 = {2.0};

  println(circle1.circumference());
  println(circle2.circumference());
  println(circle3.circumference());
  println(circle4.circumference());

  //member initialisation in constructors
  Triangle triangle {4, 6};
  println(triangle.area());

  //class pointers
  Rect obj{3, 4};
  Rect *foo, *bar, *baz;
  foo = &obj;
  bar = new Rect(5, 6);
  baz = new Rect[2]{{2, 5}, {3, 6}};
  log("obj's area", obj.get_area());
  log("*foo's area", foo->get_area());
  log("*bar's area", bar->get_area());
  log("baz[0]'s area", baz[0].get_area());
  log("baz[1]'s area", baz[1].get_area());
  delete bar;
  delete[] baz;
  return 1;
}
