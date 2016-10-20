#include <stdio.h>
#include <math.h>
int main()
{
    int n,i,j,k;
    printf("请输入菱形的高度:");
    scanf("%d", &n);
    n%2==0 ? n-=1 : 0 ; //保证行数位奇数
    for(i=0,k=-1*(n/2);i<n; i++, k++)
    {
        for(j=0; j<n; j++)
        {
            
            if( j == n/2-(n/2-abs(k)) || j == n/2+(n/2-abs(k)))
            {
                printf("█");
            } else {
                printf("▓");
            }
        }
        printf("\n");
    }
    return 0;
}
