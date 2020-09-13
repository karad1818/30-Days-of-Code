/* Today's topic is basics of computational geometry 
  here is resources : https://cp-algorithms.com/geometry/basic-geometry.html
*/

struct point_2D{
    ld x,y;
    //here we pass through reference 
    point_2D add_point(point_2D y){
        (*this).x+=y.x;
        (*this).y+=y.y;
        return (*this);
    }
    point_2D sub_point(point_2D y){
        (*this).x-=y.x;
        (*this).y-=y.y;
        return (*this);
    }
    point_2D multi_point(ld t){
        (*this).x*=t;
        (*this).y*=t;
        return (*this);
    }
    point_2D div_point(ld t){
        (*this).x/=t;
        (*this).y/=t;
        return (*this);
    }
    
    //dot_product
    ld dot_product(point_2D b){
        return (*this).x*b.x+(*this).y*b.y;
    }
    //cross_product
    // a * b = - b * a
    ld cross_product(point_2D b){
        return (*this).x*b.y-(*this).y*b.x;
    }
    //norm_of_vector
    ld norm(){
        return (*this).dot_product((*this));
    }
    ld length_of_vector(){
        return sqrt((*this).norm());
    }
    ld angle(point_2D a){
        return acos((*this).dot_product(a)/((*this).length_of_vector()*a.length_of_vector()));
    }
    
    //intersection point
    point_2D intersection(point_2D a1,point_2D d1,point_2D a2,point_2D d2){
        return a1.add_point(d1.multi_point((a2.sub_point(a1)).cross_product(d2) / d1.cross_product(d2)));
    }
};
