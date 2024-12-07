#pragma once
#include <assert>
#include <memory>
#include <initializer_list>

typedef    unsigned long long int    uint64;
typedef    unsigned int              uint32;
typedef    unsigned short int        uint16;
typedef    long long int             int64;
typedef    int                       int32;
typedef    short int                 int16;
typedef    unsigned long long int    lluint;
typedef    unsigned long int         luint;
typedef    unsigned int              uint;
typedef    unsigned short int        suint;
typedef    unsigned short short int  ssuint;    
typedef    long long int             llint;   
typedef    long int                  lint;  
typedef    short int                 sint;  
typedef    short short int           ssint;   
typedef    long double               double128;
typedef    double                    double64;
typedef    float                     float32;



using bvec2=bool[2] ; 
using bvec3=bool[3] ;
using bvec4=bool[4] ;
using dvec2=double[2] ;  
using dvec3=double[3] ;  
using dvec4=double[4] ;  //
using ldvec2=long double[2] ;  
using ldvec3=long double[3] ;  
using ldvec4=long double[4] ;  //
using uvec2=unsigned int[2] ;
using uvec3=unsigned int[3] ;
using uvec4=unsigned int[4] ;
using ivec2=int[2] ;
using ivec3=int[3] ;
using ivec4=int[4] ;//
using suvec2=short unsigned int[2] ;
using suvec3=short unsigned int[3] ;
using suvec4=short unsigned int[4] ;
using sivec2=short int[2] ;
using sivec3=short int[3] ;
using sivec4=short int[4] ;//
using luvec2=long unsigned int[2] ;
using luvec3=long unsigned int[3] ;
using luvec4=long unsigned int[4] ;
using livec2=long int[2] ;
using livec3=long int[3] ;
using livec4=long int[4] ;//
using lluvec2=long long unsigned int[2] ;
using lluvec3=long long unsigned int[3] ;
using lluvec4=long long unsigned int[4] ;
using llivec2=long long int[2] ;
using llivec3=long long int[3] ;
using llivec4=long long int[4] ;//
using vec2=float[2] ;
using vec3=float[3] ;
using vec4=float[4] ;//
using bmat2x2=bool[2][2] ;
using bmat2x3=bool[2][3] ;
using bmat2x4=bool[2][4] ;
using bmat3x2=bool[3][2] ;
using bmat3x3=bool[3][3] ;
using bmat3x4=bool[3][4] ;
using bmat4x2=bool[4][2] ;
using bmat4x3=bool[4][3] ;
using bmat4x4=bool[4][4] ;
using dmat2x2=double[2][2] ;
using dmat2x3=double[2][3] ;
using dmat2x4=double[2][4] ;
using dmat3x2=double[3][2] ;
using dmat3x3=double[3][3] ;
using dmat3x4=double[3][4] ;
using dmat4x2=double[4][2] ;
using dmat4x3=double[4][3] ;
using dmat4x4=double[4][4] ;
using sumat2x2=short unsigned int[2][2] ;
using sumat2x3=short unsigned int[2][3] ;
using sumat2x4=short unsigned int[2][4] ;
using sumat3x2=short unsigned int[3][2] ;
using sumat3x3=short unsigned int[3][3] ;
using sumat3x4=short unsigned int[3][4] ;
using sumat4x2=short unsigned int[4][2] ;
using sumat4x3=short unsigned int[4][3] ;
using sumat4x4=short unsigned int[4][4] ;
using simat2x2=short int[2][2] ;
using simat2x3=short int[2][3] ;
using simat2x4=short int[2][4] ;
using simat3x2=short int[3][2] ;
using simat3x3=short int[3][3] ;
using simat3x4=short int[3][4] ;
using simat4x2=short int[4][2] ;
using simat4x3=short int[4][3] ;
using simat4x4=short int[4][4] ;
using umat2x2=unsigned int[2][2] ;
using umat2x3=unsigned int[2][3] ;
using umat2x4=unsigned int[2][4] ;
using umat3x2=unsigned int[3][2] ;
using umat3x3=unsigned int[3][3] ;
using umat3x4=unsigned int[3][4] ;
using umat4x2=unsigned int[4][2] ;
using umat4x3=unsigned int[4][3] ;
using umat4x4=unsigned int[4][4] ;
using imat2x2=int[2][2] ;
using imat2x3=int[2][3] ;
using imat2x4=int[2][4] ;
using imat3x2=int[3][2] ;
using imat3x3=int[3][3] ;
using imat3x4=int[3][4] ;
using imat4x2=int[4][2] ;
using imat4x3=int[4][3] ;
using imat4x4=int[4][4] ;
using mat2x2=float[2][2] ;
using mat2x3=float[2][3] ;
using mat2x4=float[2][4] ;
using mat3x2=float[3][2] ;
using mat3x3=float[3][3] ;
using mat3x4=float[3][4] ;
using mat4x2=float[4][2] ;
using mat4x3=float[4][3] ;
using mat4x4=float[4][4] ;//
using ldmat2x2=long double[2][2] ;
using ldmat2x3=long double[2][3] ;
using ldmat2x4=long double[2][4] ;
using ldmat3x2=long double[3][2] ;
using ldmat3x3=long double[3][3] ;
using ldmat3x4=long double[3][4] ;
using ldmat4x2=long double[4][2] ;
using ldmat4x3=long double[4][3] ;
using ldmat4x4=long double[4][4] ;
using lumat2x2=long unsigned int[2][2] ;
using lumat2x3=long unsigned int[2][3] ;
using lumat2x4=long unsigned int[2][4] ;
using lumat3x2=long unsigned int[3][2] ;
using lumat3x3=long unsigned int[3][3] ;
using lumat3x4=long unsigned int[3][4] ;
using lumat4x2=long unsigned int[4][2] ;
using lumat4x3=long unsigned int[4][3] ;
using lumat4x4=long unsigned int[4][4] ;
using limat2x2=long int[2][2] ;
using limat2x3=long int[2][3] ;
using limat2x4=long int[2][4] ;
using limat3x2=long int[3][2] ;
using limat3x3=long int[3][3] ;
using limat3x4=long int[3][4] ;
using limat4x2=long int[4][2] ;
using limat4x3=long int[4][3] ;
using limat4x4=long int[4][4] ;
using llumat2x2=long long unsigned int[2][2] ;
using llumat2x3=long long unsigned int[2][3] ;
using llumat2x4=long long unsigned int[2][4] ;
using llumat3x2=long long unsigned int[3][2] ;
using llumat3x3=long long unsigned int[3][3] ;
using llumat3x4=long long unsigned int[3][4] ;
using llumat4x2=long long unsigned int[4][2] ;
using llumat4x3=long long unsigned int[4][3] ;
using llumat4x4=long long unsigned int[4][4] ;
using llimat2x2=long long int[2][2] ;
using llimat2x3=long long int[2][3] ;
using llimat2x4=long long int[2][4] ;
using llimat3x2=long long int[3][2] ;
using llimat3x3=long long int[3][3] ;
using llimat3x4=long long int[3][4] ;
using llimat4x2=long long int[4][2] ;
using llimat4x3=long long int[4][3] ;
using llimat4x4=long long int[4][4] ;

template <typename t,size_t r> bool[r] operator<(t[r]& lhs, t[r]& rhs){bool s[r]; for(int i = 0; i<r;i++){s[i] = (lhs[i]<rhs[i]);};return s;};
template <typename t,size_t r> bool[r] operator>(t[r]& lhs, t[r]& rhs){bool s[r]; for(int i = 0; i<r;i++){s[i] = (lhs[i]>rhs[i]);};return s;};
template <typename t,size_t r> bool[r] operator<=(t[r]& lhs, t[r]& rhs){bool s[r]; for(int i = 0; i<r;i++){s[i] = (lhs[i]<=rhs[i]);};return s;};
template <typename t,size_t r> bool[r] operator>=(t[r]& lhs, t[r]& rhs){bool s[r]; for(int i = 0; i<r;i++){s[i] = (lhs[i]>=rhs[i]);};return s;};
template <typename t,size_t r> bool[r] operator==(t[r]& lhs, t[r]& rhs){bool s[r]; for(int i = 0; i<r;i++){s[i] = (lhs[i]==rhs[i]);};return s;};
template <typename t,size_t r> bool[r] operator!=(t[r]& lhs, t[r]& rhs){bool s[r]; for(int i = 0; i<r;i++){s[i] = (lhs[i]!=rhs[i]);};return s;};
template <typename t,size_t r> t[r] operator+(t[r]& lhs, t[r]& rhs){t s[r]; for(int i = 0; i<r;i++){s[i] = (lhs[i]+rhs[i]);};return s;};
template <typename t,size_t r> t[r] operator-(t[r]& lhs, t[r]& rhs){t s[r]; for(int i = 0; i<r;i++){s[i] = (lhs[i]-rhs[i]);};return s;};
template <typename t,size_t r> t[r] operator/(t[r]& lhs, t[r]& rhs){t s[r]; for(int i = 0; i<r;i++){s[i] = (lhs[i]/rhs[i]);};return s;};
template <typename t,size_t r> t[r] operator*(t[r]& lhs, t[r]& rhs){t s[r]; for(int i = 0; i<r;i++){s[i] = (lhs[i]*rhs[i]);};return s;};
template <typename t,size_t r> t[r] operator()(t[r]& lhs,t val){t s[r]; for(int i = 0; i<r;i++){s[i] =val;};return s;};

template <typename t, size_t r , size_t rs >
t[r] operator()(t[r]& lhs, t val[rs] ){ for(int i =0 ; i <r ; i++){lhs[i]=val[i];};};
template <typename t, size_t r , size_t rs >
t[r] operator()(t[r]& lhs,t v, t val[rs] ){lhs[0]=v; for(int i =1 ; i <r ; i++){lhs[i]=val[i-1];};};
template <typename t, size_t r , size_t rs  >
t[r] operator(t[r]& lhs,t v, t vs,t val[rs] ){lhs[0]=v;lhs[1]=vs; for(int i =2 ; i <r ; i++){lhs[i]=val[i-2];};};
template <typename t, size_t r , size_t rs ,size_t rv >
t[r] operator()(t[r]& lhs,t vs[rs],t val[rv] ){for(int i=0;i<rs;i++){lhs[i]=vs[i];}; for(int i =rs ; i <r ; i++){lhs[i]=val[i-rs];};};
template <typename t, size_t r , size_t rs  >
t[r] operator()(t[r]& lhs,t vs[rs],t val ){for(int i=0;i<rs;i++){lhs[i]=vs[i];}; lhs[rs]=val;};
template <typename t, size_t r , size_t rs  >
t[r] operator()(t[r]& lhs,t vs[rs],t val , t vals){for(int i=0;i<rs;i++){lhs[i]=vs[i];}; lhs[rs]=val;lhs[rs+1]=vals;};


template <typename t, size_t r , size_t rs >
t[r] vcon( t val[rs] ){ for(int i =0 ; i <r ; i++){lhs[i]=val[i];};};
template <typename t, size_t r , size_t rs >
t[r] vcon(t v, t val[rs] ){lhs[0]=v; for(int i =1 ; i <r ; i++){lhs[i]=val[i-1];};};
template <typename t, size_t r , size_t rs  >
t[r] vcon(t v, t vs,t val[rs] ){lhs[0]=v;lhs[1]=vs; for(int i =2 ; i <r ; i++){lhs[i]=val[i-2];};};
template <typename t, size_t r , size_t rs ,size_t rv >
t[r] vcon(t vs[rs],t val[rv] ){for(int i=0;i<rs;i++){lhs[i]=vs[i];}; for(int i =rs ; i <r ; i++){lhs[i]=val[i-rs];};};
template <typename t, size_t r , size_t rs  >
t[r] vcon(t vs[rs],t val ){for(int i=0;i<rs;i++){lhs[i]=vs[i];}; lhs[rs]=val;};
template <typename t, size_t r , size_t rs  >
t[r] vcon(t vs[rs],t val , t vals){for(int i=0;i<rs;i++){lhs[i]=vs[i];}; lhs[rs]=val;lhs[rs+1]=vals;};



template <typename t,size_t rs>
t[2] vec2(t val[rs]) { return vcon<t,2,rs>(t val);};
template <typename t,size_t rs>
t[2] vec2(t v,t val[rs]) { return vcon<t,2,rs>(v, val);};
template <typename t,size_t rs>
t[2] vec2(t v, t vs,t val[rs]) { return vcon<t,2,rs>(v,vs, val);};
template <typename t,size_t rs,size_t rv>
t[2] vec2(t vs[rs],t val[rv]) { return vcon<t,2,rs,rv>(vs,val);};
template <typename t,size_t rs>
t[2] vec2(t vs[rs],t val) { return vcon<t,2,rs>(vs,val);};
template <typename t,size_t rs>
t[2] vec2(t vs[rs],t val), tvals { return vcon<t,2,rs>(vs,val,vals);};



template <typename t,size_t rs>
t[3] vec3(t val[rs]) { return vcon<t,3,rs>(t val);};
template <typename t,size_t rs>
t[3] vec3(t v,t val[rs]) { return vcon<t,3,rs>(v, val);};
template <typename t,size_t rs>
t[3] vec3(t v, t vs,t val[rs]) { return vcon<t,3,rs>(v,vs, val);};
template <typename t,size_t rs,size_t rv>
t[3] vec3(t vs[rs],t val[rv]) { return vcon<t,3,rs,rv>(vs,val);};
template <typename t,size_t rs>
t[3] vec3(t vs[rs],t val) { return vcon<t,3,rs>(vs,val);};
template <typename t,size_t rs>
t[3] vec3(t vs[rs],t val), tvals { return vcon<t,3,rs>(vs,val,vals);};

template <typename t,size_t rs>
t[4] vec4(t val[rs]) { return vcon<t,4,rs>(t val);};
template <typename t,size_t rs>
t[4] vec4(t v,t val[rs]) { return vcon<t,4,rs>(v, val);};
template <typename t,size_t rs>
t[4] vec4(t v, t vs,t val[rs]) { return vcon<t,4,rs>(v,vs, val);};
template <typename t,size_t rs,size_t rv>
t[4] vec4(t vs[rs],t val[rv]) { return vcon<t,4,rs,rv>(vs,val);};
template <typename t,size_t rs>
t[2] vec4(t vs[rs],t val) { return vcon<t,4,rs>(vs,val);};
template <typename t,size_t rs>
t[2] vec4(t vs[rs],t val), tvals { return vcon<t,4,rs>(vs,val,vals);};


template <typename t,size_t r,size_t c> bool[r][c] operator<( t[r][c]& lhs, t[r][c]& rhs){bool s[r][c]; for(int i = 0; i<r;i++){for(int j=0;j<c;j++){ s[i][j] = (lhs[i][j]< rhs[i][j]);};};return s;};
template <typename t,size_t r,size_t c> bool[r][c] operator>( t[r][c]& lhs, t[r][c]& rhs){bool s[r][c]; for(int i = 0; i<r;i++){for(int j=0;j<c;j++){ s[i][j] = (lhs[i][j]> rhs[i][j]);};};return s;};
template <typename t,size_t r,size_t c> bool[r][c] operator<=(t[r][c]& lhs, t[r][c]& rhs){bool s[r][c]; for(int i = 0; i<r;i++){for(int j=0;j<c;j++){ s[i][j] = (lhs[i][j]<=rhs[i][j]);};};return s;};
template <typename t,size_t r,size_t c> bool[r][c] operator>=(t[r][c]& lhs, t[r][c]& rhs){bool s[r][c]; for(int i = 0; i<r;i++){for(int j=0;j<c;j++){ s[i][j] = (lhs[i][j]>=rhs[i][j]);};};return s;};
template <typename t,size_t r,size_t c> bool[r][c] operator==(t[r][c]& lhs, t[r][c]& rhs){bool s[r][c]; for(int i = 0; i<r;i++){for(int j=0;j<c;j++){ s[i][j] = (lhs[i][j]==rhs[i][j]);};};return s;};
template <typename t,size_t r,size_t c> bool[r][c] operator!=(t[r][c]& lhs, t[r][c]& rhs){bool s[r][c]; for(int i = 0; i<r;i++){for(int j=0;j<c;j++){ s[i][j] = (lhs[i][j]!=rhs[i][j]);};};return s;};
template <typename t,size_t r,size_t c> t[r][c]    operator+( t[r][c]& lhs, t[r][c]& rhs){t s[r][c];    for(int i = 0; i<r;i++){for(int j=0;j<c;j++){ s[i][j] = (lhs[i][j]+ rhs[i][j]);};};return s;};
template <typename t,size_t r,size_t c> t[r][c]    operator-( t[r][c]& lhs, t[r][c]& rhs){t s[r][c];    for(int i = 0; i<r;i++){for(int j=0;j<c;j++){ s[i][j] = (lhs[i][j]- rhs[i][j]);};};return s;};
template <typename t,size_t r,size_t c> t[r][c]    operator/( t[r][c]& lhs, t[r][c]& rhs){t s[r][c];    for(int i = 0; i<r;i++){for(int j=0;j<c;j++){ s[i][j] = (lhs[i][j]/ rhs[i][j]);};};return s;};
template <typename t,size_t r,size_t c> t[r][c]    operator*( t[r][c]& lhs, t[r][c]& rhs){t s[r][c];    for(int i = 0; i<r;i++){for(int j=0;j<c;j++){ s[i][j] = (lhs[i][j]* rhs[i][j]);};};return s;};
template <typename t,size_t r,size_t c> t[r][c]    operator()( t[r][c]& lhs, t val){t s[r][c];    for(int i = 0; i<r;i++){for(int j=0;j<c;j++){ s[i][j] = val*(i==j);};};return s;};
template <size_t size>
struct swizzle {
    static constexpr size_t s = size; 
};
using x = swizzle<0>; 
using y = swizzle<1>; 
using z = swizzle<2>; 
using w = swizzle<3>; 

template<typename T,size_t size,size_t s>
T[s] operator^(T el[size] , swizzle swi[s]){
    T  m[s];
    for( size_t i = 0 ; i < s;i++){
        m[i] = el[swi[i]];
    }   ; 
    return m;
};

swizzle[2] operator*(swizzle a, swizzle b){
    swizzle n[2] = {a.s,b.s};
    return n;
};
swizzle[3] operator*(swizzle a[2],swizzle b)
{
    swizzle n[3] = {a[0].s,a[1].s,b.s}; return n;
}
swizzle[4] operator*(swizzle a[3], swizzle b){
    swizzle n[4] = {a[0].s, a[1].s , a[2].s , b.s}; return n;
};
 template <typename T >
 struct arrdepth {
     using _ty = std::remove_extent_t<T>;
    static constexpr int depth = std::is_array_v<_ty>?(arrdepth<_ty>::depth+1):0;
    static constexpr size_t size= size>arrdepth<_ty>::size?arrdepth<_ty>::size:sizeof(T[0]); 
 
 };
template <typename T>
struct arrtype {
    static constexpr bool vec = std::is_array_v<T>;
    static constexpr bool mat = std::is_array_v<T> && std::is_array_v<std::remove_extent_t<T>>;
    static constexpr bool depth = arr_depth<T>::depth;
    static constexpr bool sizeprim = arr_depth<T>::size;
    static constexpr bool arrd = depth==1; 
    static constexpr size_t size_prime=sizeof(T[0][0])/sizeof(T[0]);
    static constexpr bool arrvec = depth==2?((sizeof(T[0])>(sizeprim*4))?true:false):false;
    static constexpr bool matd = depth==2?(sizeof(T[0])>(sizeprim*4))?true:false):false;
    static constexpr bool matvec = mat and (depth == 3) ? true : false ;
    static constexpr bool matmat = mat and (depth == 4) ? true : false ;
};

template <typename T,size_t r=0, size_t c=0>
struct arrc {
    using d=std::conditional<c==0,T[r],T[r][c]>::type;
    static constexpr size_t row = r;
    static constexpr size_t col = c ;
    static bool mat=c>0; 
};
template <typename T, size_t s=0>
class vec {
    public:
    using ty= T[s];
    T* d = new T[s];
    bool size_t s;
    T& operator[](size_t s){
        return d[s];
    };
    arr(T* n){this->s = sizeof(n)/sizeof(n[0]);this->d = new T[this->s]}
    void operator=(T* n){
        this = new vec(n)
       
    };
    arr(size_t _r){this->row = _r; this->col = _c; this->d =new T[r]}
};

template <typename T , size_t size_buffer=0b1000 >
class vect {
    private:
    size_t size_buf = size_buffer;
    size_t tsize=size_buf;
    T* data;
    size_t s;// Current size
    public:
    T* get_data(){
        return this->data;
    };
    size_t size(){return this->s;};
    
    size_t tsize(){return this->tsize;};
    T& get(size_t pos){return this->data[pos];}
    void resize(size_t a){ // Resizes tsize to a + size_buf and vect to a;
        T* n = new T[a+size_buf];
        if(a<this->s){
            for(int i = 0 ; i< a;i++){n[i] = this->data[i];};
        }
        else{
            for(int i=0 ; i < this->s ; i++ ){
                n[i] = this->data[i]; 
            };
        };
        this->data= new T[a+size_buf] ;this->data=n;
        this->s= a;
    };
   
    void insert(size_t pos, T elem){
        if(!(this->s+1 < this->tsize)){
        this->resize(this->s+1);};
        T cur; 
        cur = this->data[pos];
        this->data[pos] = elem;
        for(int i = pos+1 ; i < this->s;i++){
            T current = this->data[i];
            this->data[i]=cur;
            cur= current;
    };
    void erase(size_t pos){
        this->s--;
        for (int i = pos ; i < this->s ; i++){
            this->data[i] = this->data[i+1];
        };     
    };

    #ifdef CXX23
    vect operator[](size_t a, size_t b){
        vect<T> res ;
        for(int i =a ; i<=b ; i++){
            res[i-a] = this->data[i];
        };
        return res;
    };
    #endif
    
    T& operator[](size_t pos){
        if(pos >= this->s){
            this->resize(pos+1);
            return this->data[pos];
        };
        return this->data[pos];
    };
    vect& operator=(std::initializer_list<T> list){
        T* n = new T[list.size()];
        int i = 0 ;
        for(T val : list) {
            n[i] = val; i++;
        };
        this->data=n;
        this->s = list.size();
    };
     void push(T& elem){
        if (this->s < this->tsize){
            this->data[s]= elem;
            this->s++; return;
        };
        this->resize(this->tsize);
        this->data[this->s] = elem;
        this->s++;
    };
    void clear(){
        this->s=0;
        this->tsize=sizebuf;
        this->data = new T[sizebuf];
    };
    void swap(size_t pos1 ,size_t pos2){
        T temp = this->data[pos1];
        this->data[pos1] = this->data[pos2] ;
        this->data[pos2] = temp;
        delete temp;
    };
    void move(size_t pos1 , size_t pos2){
        this->swap(pos1,pos2); int add=0;
        if(pos1<pos2){add=1;}
        else {add=-1}
        for( int i = pos1 + add ; i != pos2 ; i+=add )
            this->swap(i-add,i);
        };
    };
    vect(size_t size){
        this->s = size; 
        this->tsize = size+size_buf;
        this->data = new T[this->tsize];
    };  
    vect(){vect(0);}
    vect(size_t s, size_t tsize){
        this->s = s; this->tsize = tsize ; this->data= new T[this->tsize];
    };

}; 

template <typename T,size_t r=0, size_t c =0>
class mat {
    public:
    vec<T,c>[r] d;
    size_t row = row ; size_t col;
    vec<T>& operator[](size_t s){
        return d[s];
    };
    mat(T** n){this->row = si,this[2],eof(n)/sizeof(n[0]); this->d = new[this->row] vec<T>(sizeof(n[0])/sizeof(n[0][0]))}
    operator=()(T** n){
        this = new mat(n); 
    };

    mat(size_t _r, size_t _c ){this->row = _r;this->col = _c; this->d = new T[r][c]};
};
#ifdef TENSOR_MAT
template <typename T,size_t first>
class ten {
    using ty =T[first]
    using next = NULL;
    using order = 1;
    static constexpr bool sizes[] = {first};
    using type = 
};
template <typename T ,size_t first, size_t... s>
class ten{
    using ty=vec<T,first>::ty;
    using next = ten<ty,s...>
    using order = 1+ next::order;
    static constexpr bool sizes[] = {first}+next::sizes;    
    using type = next::ty;
    type data;
    ten& operator[](size_t pos){
        return this->data[pos];
    };
    ten& operator+=(ten& n ){
        
    };
    ten& operator*=(ten& n){

    };
    ten& operator*=(ten& n){

    };
    ten& operator-=(ten& n){

    };
    ten& operator*(ten& n){if}
    ten& operator+(ten& n){if}
    ten& operator-(ten& n){if}
    ten& operator/(ten& n){if}
    ten& operator%(ten& n){if}
    
   
    T operator[](size_t last){
        ten<T,sizes[order-1]> res = this[last];
    };
    T operator[](size_t First,size_t... arg){
        assert(sizeof...(arg) + sizeof(First) > sizeof(sizes)/sizeof(first) , "To many parameters");
        assert(sizeof...(arg) + sizeof(First) < sizeof(sizes)/sizeof(first) , "To few parameters");
        T ret = this->data[First].operator[](arg...);
        return ret;
    };
    ten get_ten_index(size_t no , size_t last,){

    };
    ten get_ten_index(size_t no, size_t midF , size_t... args){

    };
    ten get_ten_ind(size_t no, size_t last){
        size_t ncur = no+1;
        for(int i = no ; i < size_t )
         this->data[last]
    };
    ten get_ten_ind(size_t no,size_t First, size_t... arg){
        sizeof...(arg) + sizeof(First) > sizeof(sizes)/sizeof(first) , "To many parameters");
        size_t ncur = no+1;
        ten<First,arg...> tens = this->data[First]->get_ten_ind_cur(ncur,arg...)
        
    };

    ten operator[](size_t First,size_t... s){
        return this->get_ten_ind(0,First,arg...);
    };
    ten();
};

#endif
