#ifdef TEXT
#include "text.glsl"
#ifdef ANSICODE
const int s=8;
#else
const int s=7;
#endif
#else
const int s = 0;
layout(location=s) vec4 bounding;
#endif
layout(location=s+1) bool set;
#ifdef HOVER
layout(location=s+2) vec2 mousepos;
#endif

void drawBox(){
    ivec2 m =ivec2(cur_pos.x,cur_pos.y)  ;    
    int si_fg_im = int(text_size.y/10);
    vec4 fg_im[si_fg_im] ;
    for(int i = 1 ; i <si_fg_im-1 ;i++){fg_im[i]=fg_col;}
    fg_im[0] = fg_col / vec4(2,2,2,1);
    fg_im[1] = fg_col / vec4(2,2,2,1); 
    for(int i = int(cur_pos.y); i < cur_pos.y + text_size.y ; i++){
    for(int j = int(cur_pos.x); i < cur_pos.x + text_size.y ; i++){
        imageStore(im,ivec2(i,j),bg_col);
    }
        float dif = m.x +i - m.y;
        ivec2 a=ivec2(m.x , i );
        ivec2 b=ivec2(m.x+text_size.y , i );
        ivec2 c=ivec2(dif, i );
        ivec2 d=ivec2(dif, i );
        imageStore(im,a,fg_col);
        imageStore(im,b,fg_col);
        imageStore(im,c,fg_col);
        imageStore(im,d,fg_col);
        if(set){
            if(i<(cur_pos.y + text_size.y /2)){
                imageStore((im, vec2(m.x + ( i-cur_pos.y)) ,(m.y +(text_size.y/2 - (i - m.y)) ), fg_im );
            }
            else {
                imageStore((im, vec2(( m.x + ( i-cur_pos.y)) ,(m.y +(i - m.y)  ),fg_im);
            }
        }
    }
    cur_pos.x+= text_size.x*3 ;
}


void main(){
    drawBox();
}