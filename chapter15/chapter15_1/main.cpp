#include "Simple_window.h"
#include "Graph.h"

using namespace Graph_lib;

double one(double x) {return 1;}

double slope(double x) {return x/2;}

double square(double x){return x*x;}

double cos_slope(double x){return  slope(x)+cos(x);}

int main()
{
	int win_height=600, win_width=600;
	Point origo{win_width/2,win_height/2};

	Simple_window win (Point{100,100},win_width,win_height,"Function graphs");

	int notches=20;

	Axis x_sis (Axis::x, Point{100,300},400,notches,"1==20 pixels");
	x_sis.set_color(Color::red);
	win.attach(x_sis);

	Axis y_sis (Axis::y, Point{300,500},400,notches,"1==20 pixels");
	y_sis.set_color(Color::red);
	win.attach(y_sis);

	int range_min=-10, range_max=11;
	int points=400;
	int x_scaling=20, y_scaling=20;

	Function one_for_all(one,range_min,range_max,origo,points,x_scaling,y_scaling);
	one_for_all.set_color(Color::black);
	
	Function slopp(slope,range_min,range_max,origo,points,x_scaling,y_scaling);
	slopp.set_color(Color::black);
	
	Text label {Point {500,190}, "x/2"};
	label.set_color(Color::black);
	
	Function sqr(square,range_min,range_max,origo,points,x_scaling,y_scaling);
	sqr.set_color(Color::black);

	Function cosinus([](double x){return cos(x);},
		range_min, range_max, origo, points, x_scaling, y_scaling);
	cosinus.set_color(Color::blue);

	Function cslope(cos_slope,range_min,range_max,origo,points,x_scaling,y_scaling);
	cslope.set_color(Color::black);
	
	win.attach(one_for_all);
	win.attach(slopp);
	win.attach(label);
	win.attach(sqr);
	win.attach(cosinus);
	win.attach(cslope);

	win.wait_for_button();
}