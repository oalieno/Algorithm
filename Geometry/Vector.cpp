struct VT{
    double x,y;
    VT(){}
    VT(double x, double y):x(x),y(y){}
    VT operator+(const VT &v) const { return VT(x+v.x,y+v.y); }
    VT operator-(const VT &v) const { return VT(x-v.x,y-v.y); }
    VT operator*(double c) const { return VT(x*c,y*c); }
    VT operator/(double c) const { return VT(x/c,y/c); }
    double operator*(const VT &v) const { return x*v.x+y*v.y; }
    double operator^(const VT &v) const { return x*v.y-y*v.x; }
    double len(){ return sqrt(x*x+y*y); }
    double len2(){ return x*x+y*y; }
    VT U(){ return *this/len(); }
    VT T(){ return VT(-y,x); }
    VT rot(double a){ return VT(cos(a)*x-sin(a)*y,sin(a)*x+cos(a)*y); }
};
