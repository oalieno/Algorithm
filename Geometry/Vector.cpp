struct Vector{
    double x,y;
    Vector(){}
    Vector(double x, double y):x(x),y(y){}
    Vector operator+(const Vector &v) const { return Vector(x+v.x,y+v.y); }
    Vector operator-(const Vector &v) const { return Vector(x-v.x,y-v.y); }
    Vector operator*(double c) const { return Vector(x*c,y*c); }
    Vector operator/(double c) const { return Vector(x/c,y/c); }
    double operator*(const Vector &v){ return x*v.x+y*v.y; }
    double operator^(const Vector &v){ return x*v.y-y*v.x; }
    double len(){ return sqrt(x*x+y*y); }
    double len2(){ return x*x+y*y; }
    Vector U(){ return *this/len(); }
    Vector T(){ return Vector(-y,x); }
    Vector rot(double a){ return Vector(cos(a)*x-sin(a)*y,sin(a)*x+cos(a)*y); }
};
