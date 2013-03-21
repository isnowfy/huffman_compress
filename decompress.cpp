#include<cstdio>
int l[512],r[512];
char c1,c2,c3,c4,ss1[256],ss2[256];
int main(){
    printf("please enter the compressed file name\n");
    scanf("%s",&ss1);
    printf("please enter the decompressed file name\n");
    scanf("%s",&ss2);
    freopen(ss1,"rb",stdin);
    freopen(ss2,"wb",stdout);
    for(int i=0;i<512;i++){
      scanf("%c%c%c%c",&c1,&c2,&c3,&c4);
      l[i]=c2;
      if(l[i]<0)l[i]+=256;
      r[i]=c4;
      if(r[i]<0)r[i]+=256;
      l[i]+=256*c1;
      r[i]+=256*c3;
    }
    scanf("%c",&c1);
    scanf("%c",&c2);
    int k1=510,temp,temp1;
    while(scanf("%c",&c3)!=EOF){
      temp=128,temp1=c1;
      if(temp1<0)
        temp1+=256;
      for(int j=0;j<8;j++){
        if(temp1/temp)
          k1=r[k1];
        else k1=l[k1];
        temp1%=temp;
        temp/=2;
        if(l[k1]==r[k1]){
          printf("%c",(char)(k1));
          k1=510;
        }
      }
      c1=c2;c2=c3;
    }
    temp=128,temp1=c1;
    if(temp1<0)
      temp1+=256;
    for(int j=0;j<c2;j++){
      if(temp1/temp)
        k1=r[k1];
      else k1=l[k1];
      temp1%=temp;
      temp/=2;
      if(l[k1]==r[k1]){
        printf("%c",(char)(k1));
        k1=510;
      }
    }
    return 0;
}
