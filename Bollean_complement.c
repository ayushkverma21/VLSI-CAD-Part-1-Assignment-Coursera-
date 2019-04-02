#include <stdio.h>
#include <stdlib.h>
struct cubelist complement(struct cubelist);
int binate(struct cubelist);
struct cubelist positivecofactor(struct cubelist,int);
struct cubelist negativecofactor(struct cubelist,int);
struct cubelist andd(struct cubelist,int );
struct cubelist and(struct cubelist,int);
struct cubelist or(struct cubelist,struct cubelist);

struct cubelist{
int u[300][20];
};
struct cubelist c5,c6;

int i,k,j,b,c;

int main()
{
    struct cubelist a,cc;
    int z[20],ch,d;
int e,o=0,zz[200],t1,p1=-1,mm=0;
FILE *fp,*ff;
fp = fopen("part5.pcn","r");


fscanf(fp,"%d %d",&b,&c);

printf("%d %d\n",b,c);


for(i=0;i<200;i++){
    zz[i] = 0;
}


    for (i=0;i<c;i++){
       fscanf(fp,"%d",&d);
z[i] = d;

                for(k=0;k<d;k++){
                        fscanf(fp,"%d",&ch);
                        if(ch<0){
                          a.u[i][k] = 10;
                        }
                  else if(ch>0){
                    a.u[i][k] = 1;
                  }

                  printf("%d\t",a.u[i][k]);
                  }

for(j = d;j<b;j++){
    a.u[i][j] = 11;
    printf("%d \t",a.u[i][j]);
}
printf("\n");
}
printf("\n \n");
fclose(fp);
cc = complement(a);
for(i=0;i<c;i++){
    for(j=0;j<b;j++){
        printf("%d\t",cc.u[i][j]);
    }
    printf("\n");
}
ff=fopen("assign5.pcn","w");
fprintf(ff,"%d\n",b);


    for (i=0;i<200;i++){
            if(cc.u[i][0] != 0){
               o = o+1;
            }

    }
    fprintf(ff,"%d\n",o);

for(i=0;i<200;i++){
          if((cc.u[i][0]==1)|| (cc.u[i][0]==10)||(cc.u[i][0]==11)){
                p1++;
            }
    for (j=0;j<b;j++){

        e = cc.u[i][j];

        if((e==10) || (e==1)){

          zz[p1] = zz[p1]+1;

        }

    }
}
for(i=0;i<19;i++){
    printf("%d",zz[i]);
}
t1=0;

    for(i=0;i<=200;i++){
if((cc.u[i][0] == 10) || (cc.u[i][0] == 1)||(cc.u[i][0] == 11)){
    fprintf(ff,"%d\t",zz[t1]);
    t1++;

            for(j=0;j<b;j++){

        if(cc.u[i][j]==10){

            fprintf(ff,"%d\t",-(j+1));
        }

         else if(cc.u[i][j]==1){
            fprintf(ff,"%d\t",(j+1));

         }

    }

    fprintf(ff,"\n");}

}



return 0 ;
}

struct cubelist complement(struct cubelist cube){
    struct cubelist P,N,cj,cji;
int m = 0,l=0,ss=0,kkc=0,sf=0;
for(i=0;i<c;i++){
        if((cube.u[i][0]==11) ||(cube.u[i][0]==10) || (cube.u[i][0]==1))
{
    m = m+1;
}}
 for(j=0;j<b;j++){
            if((cube.u[0][j]==1)||(cube.u[0][j]==10)){
                kkc++;
            }
        }
 if(m==1){


            for(j=0;j<b;j++){
                if(cube.u[0][j] == 10){
                    cube.u[0][j] = 1;

                }
                else if(cube.u[0][j]==1){
                    cube.u[0][j]=10;

                }
            }


    for(i=0;i<kkc;i++){
            for(j=0;j<b;j++){
        if(cube.u[0][j]==1){

            cji.u[i][j] = cube.u[0][j];
            sf = sf+1;


        }

        else{
           cji.u[i][j] = 11;
        }

    }}
    for(sf=0;sf<kkc;sf++){
            for(j=0;j<b;j++){
        if(cube.u[0][j]==10){

            cji.u[sf][j] = cube.u[0][j];


        }

        else{
           cji.u[i][j] = 11;
        }

    }

    }
    return cji;
 }
 else if((kkc==1)&&(m!=1)){


   for(i=1;i<=c;i++){
    for(j=0;j<b;j++){
        if(cube.u[0][j]== cube.u[i][j] ){
          ss = ss+1;
        }

    }
   }
  if((ss+b)== m*b ){
for(i=0;i<c;i++){
            for(j=0;j<b;j++){
                if(cube.u[i][j] == 10){
                    cube.u[i][j] == 1;
                }
                else if(cube.u[i][j]==1){
                    cube.u[i][j]=10;
                }
            }
        }


      return cube;}}

else{

l = binate(cube);



c5 = negativecofactor(cube,l);

c6 = positivecofactor(cube,l);

struct cubelist n = complement(c5);

struct cubelist p = complement(c6);

 P = and(p,l);

N = andd(n,l);



  cj =  or(P,N);
return cj;

}

}
int binate(struct cubelist cube3){
int g[20],n1,n2;
int gz[20];
int largest,t;
for(j=0;j<b;j++){
        g[j] = 0;
        gz[j]=0;
    for(i=0;i<c;i++){
        if(cube3.u[i][j]==1){
            g[j] = g[j]+1;

        }
        else if(cube3.u[i][j] == 10){
            g[j]=g[j] + 1;
            gz[j] = gz[j]+1;

        }
    }
}
largest = g[0];

for(k=0;k<b;k++){
    if(g[k]>largest){
        largest=g[k];
       t=k;
       }}
    for(j=0;j<b;j++){
            if(g[t] == g[j]){
           n1= (g[t]-gz[t])-gz[t];
    n2=(g[j]-gz[j])-gz[j];
        if(n1<0){
           n1 = -1*n1;
    }
     if(n2<0){
           n2 = -1* n2;
    }

    if(n1>n2){
        t=j;
    }


}
}
printf("%d\n",t);
return t;
}
struct cubelist positivecofactor(struct cubelist cube1,int q){
    struct cubelist sky;
    int bin=0;
for(i=0;i<c;i++){

        if(cube1.u[i][q] == 10){
                for(j=0;j<b;j++){
            cube1.u[i][j] = 0;}}

    else if(cube1.u[i][q]== 1){
       cube1.u[i][q]=11;
    }}
    for(i=0;i<c;i++){
        if((cube1.u[i][0] == 11)||(cube1.u[i][0] == 10)||(cube1.u[i][0] == 1)){
            for(j=0;j<b;j++){
                sky.u[bin][j]= cube1.u[i][j];
            }
            bin++;
        }
    }


return sky;
}

struct cubelist negativecofactor(struct cubelist cube2,int q){
    struct cubelist sk;
    int bi=0;
for(i=0;i<c;i++){

        if(cube2.u[i][q] == 1){
                for(j=0;j<b;j++){
            cube2.u[i][j] = 0;}}

    else if(cube2.u[i][q]==10){
       cube2.u[i][q]=11;
    }
}
 for(i=0;i<c;i++){
        if((cube2.u[i][0] == 11)||(cube2.u[i][0] == 10)||(cube2.u[i][0] == 1)){
            for(j=0;j<b;j++){
                sk.u[bi][j]= cube2.u[i][j];
            }
            bi++;
        }
    }

return sk;

}



struct cubelist and(struct cubelist c7,int w){

    for(i=0;i<200;i++){
            if(c7.u[i][w]==11){
        c7.u[i][w]=1;}
    }
return c7;
}
struct cubelist andd(struct cubelist c8,int w){
    for(i=0;i<200;i++){
            if(c8.u[i][w]==11){
        c8.u[i][w]=10;
    }}
return c8;
}
struct cubelist or(struct cubelist c9,struct cubelist ca){

struct cubelist cb;
int k6=0;
for(i=0;i<200;i++){
    if((c9.u[i][0]== 11)||(c9.u[i][0]== 1)||(c9.u[i][0]== 10)){


    for(j=0;j<b;j++){

     cb.u[k6][j] = c9.u[i][j];

}
k6++;
  }

  if((ca.u[i][0]== 11)||(ca.u[i][0]== 1)||(ca.u[i][0]== 10)){


    for(j=0;j<b;j++){

     cb.u[k6][j] = ca.u[i][j];

}
k6++;
  }
}
return cb;
}
