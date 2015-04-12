#include <iostream>
using namespace std;

int maxSubArray(int **a,int n,int m)
{
  int **p=new int*[n];
  int i,j;
  if(m==0||n==0)
    return 0;
  //����p[i][j]	
  for(i=0;i<n;i++)
  {
    p[i]=new int[m];
    for(j=0;j<m;j++)
    {
      if(i==0)
      {
        if(j==0)
          p[i][j]=a[i][j];
        else
          p[i][j]=p[i][j-1]+a[i][j];
      }
      else
      {
        if(j==0)
          p[i][j]=p[i-1][j]+a[i][j];
        else
          p[i][j]=p[i][j-1]+p[i-1][j]-p[i-1][j-1]+a[i][j];
      }
    }
  }
  //�����ά�������������ĺ�
  int temp;
  int max=a[0][0];
  int ans;
  //���m==1
  if(m==1)
  {
    for(i=0;i<n;i++)
    {
      for(j=i;j<n;j++)
      {
        if(i==0)
        {
          temp=p[j][m-1];
        }
        else
        {
          temp=p[j][m-1]-p[i-1][m-1];
        }
        if(ans<temp)
          ans=temp;
      }
    }
  }
  else
  {
    for(i=0;i<n;i++)
    {
      for(j=i;j<n;j++)
      {
        if(i==0)
        {
          temp=p[j][m-1]-p[j][m-2];
        }
        else
        {
          temp=p[j][m-1]-p[j][m-2]-p[i-1][m-1]+p[i-1][m-2];
        }
        for(int k=m-2;k>=0;k--)
        {
          if(temp<0)
            temp=0;
          if(i==0)
          {
            if(k==0)
              temp+=p[j][k];
            else
              temp+=p[j][k]-p[j][k-1];
          }
          else
          {
            if(k==0)
              temp+=p[j][k]-p[i-1][k];
            else
              temp+=p[j][k]-p[j][k-1]-p[i-1][k]+p[i-1][k-1];
          }
          if(ans<temp)
            ans=temp;
        }
      }
    }
  }
  return ans;
}

int main()
{
  int n,m;
  printf("�������ά�����������������\n");
  scanf("%d %d",&n,&m);
  int i,j;
  int **a=new int*[n];
  printf("������%d*%d����ά����Ԫ�أ�\n",n,m);
  for(i=0;i<n;i++)
  {
    a[i]=new int[m];

    for(j=0;j<m;j++)
    {
      scanf("%d",&a[i][j]);
    }
  }
  int ans=maxSubArray(a,n,m);
  printf("��ά��������������֮���ǣ�%d\n",ans);
  return 0;
}