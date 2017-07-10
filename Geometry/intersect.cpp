VT intersect(const VT &v1,const VT &v2,const VT &v3,const VT &v4){
    double a123 = (v2-v1)^(v3-v1);
    double a124 = (v2-v1)^(v4-v1);
    return (v4*a123-v3*a124)/(a123-a124);
}
