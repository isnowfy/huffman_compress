#include<cstdio>
const int maxint=0x7fffffff;
int a[512],a1[512],b[512],l[512],r[512],p[512],k=0,source=0,sink=2048,kk=0;
int ll[300],d1=0,d2=0,c0;
char c,ss1[256],ss2[256];
int dfs(int k){
    if(k==510)
      return 0;
    int temp=dfs(p[k])+1;
    if(k==r[p[k]])
      ll[d2]=1;
    else ll[d2]=0;
    d2=(d2+1)%290;
    return temp;
}
int main(){
    printf("please enter the source file name\n");
    scanf("%s",&ss1);
    printf("please enter the compressed file name\n");
    scanf("%s",&ss2);
    freopen(ss1,"rb",stdin);
    freopen(ss2,"wb",stdout);
    a[511]=maxint;
    while(scanf("%c",&c)!=EOF){
      c0=c;
      if(c0<0) c0+=256;
      a[c0]++;
    }
    fclose(stdin);
    freopen(ss1,"rb",stdin);
    for(int i=0;i<256;i++){
      int min1=511,min2=511;
      for(int j=0;j<256+i;j++)
        if(!a1[j]&&a[j]<a[min1])
          min1=j;
      for(int j=0;j<256+i;j++)
        if(!a1[j]&&a[j]<a[min2]&&j!=min1)
          min2=j;
      a1[min1]=a1[min2]=1;
      a[256+i]=a[min1]+a[min2];
      l[256+i]=min1;
      r[256+i]=min2;
      p[min1]=256+i;
      p[min2]=256+i;
    }
    for(int i=0;i<512;i++)
      printf("%c%c%c%c",(char)(l[i]/256),(char)(l[i]%256),(char)(r[i]/256),(char)(r[i]%256));
    while(scanf("%c",&c)!=EOF){
      source++;
      c0=c;
      if(c0<0)
        c0+=256;
      k+=dfs(c0);
      while(k>7){
        kk=0;
        for(int i=0;i<8;i++){
          kk=kk*2+ll[d1];
          d1=(d1+1)%290;
        }
        printf("%c",(char)(kk));
        k-=8;
        sink++;
      }
    }
    kk=0;
    for(int i=0;i<k;i++){
      kk=kk*2+ll[d1];
      d1=(d1+1)%290;
    }
    for(int i=0;i<8-k;i++)
      kk*=2;
    printf("%c%c",(char)(kk),(char)(k));
    fclose(stdin);
    fclose(stdout);
    //freopen("CON","r",stdin);
    //freopen("CON","w",stdout);
    //printf("compression ratio:%lf\n",(double)(sink)/(double)(source));
    //getchar();
    return 0;
}
