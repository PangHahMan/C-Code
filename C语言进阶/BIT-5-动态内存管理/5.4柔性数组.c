#include <stdio.h>
#include <stdlib.h>
//Ҳ�������û����˵���������飨flexible array��������������ȷʵ�Ǵ��ڵ�
// C99 �У��ṹ�е����һ��Ԫ��������δ֪��С�����飬��ͽ������������须��Ա��
/*
struct S
{
    int n;
    float s;
    int arr[];  //���������Ա �ڶ���д��int arr[0]
};

int main()
{
    return 0;
} */

// 1.����������ص㣺
/*
���ṹ�е����������Աǰ���������һ��������Ա��
��sizeof ���ص����ֽṹ��С����������������ڴ档
���������������Ա�Ľṹ��malloc ()���������ڴ�Ķ�̬���䣬���ҷ�����ڴ�Ӧ�ô��ڽṹ�Ĵ�С������Ӧ���������Ԥ�ڴ�С�� */

/*
typedef struct st_type
{
    int i;
    int a[0]; //���������Ա
} type_a;
printf("%d\n", sizeof(type_a)); //�������4 */

/* ����1
struct S
{
    int n;
    float s;
    int arr[]; //���������Ա
};

int main()
{
    struct S *ps = (struct S *)malloc(sizeof(struct S) + sizeof(int) * 4); //�����ṹ��Ŀռ� �����Զ�����������Ŀռ�
    if (ps == NULL)
    {
        return 1;
    }

    ps->n = 100;
    ps->s = 5.5f;
    int i = 0;
    for (i = 0; i < 4; i++)
    {
        scanf("%d", &(ps->arr[i]));
    }

    for (i = 0; i < 4; i++)
    {
        printf("%d ", *(ps->arr + i));
    }
    //����
    struct S *ptr = realloc(ps, sizeof(struct S) + 10 * sizeof(int)); //��չ�������������
    if (ptr == NULL)
    {
        return 1;
    }
    else
    {
        ps = ptr;
    }

    free(ps);
    ps = NULL;
    return 0;
}
 */



/* ����2
struct S
{
    int n;
    float s;
    int *arr;
};

int main()
{
        struct S *ps = (struct S*)malloc(sizeof(struct S));
    if (ps == NULL)
        return 1;

    ps->n = 100;
    ps->s = 5.5f;
    int *ptr = (int *)malloc(4 * sizeof(int));
    if (ptr == NULL)
    {
        return 1;
    }
    else
    {
        ps->arr = ptr;
    }
    //ʹ��
    int i = 0;
    for (i = 0; i < 4; i++)
    {
        scanf("%d", &(ps->arr[i]));
    }
    //����
    realloc(ps->arr,10*sizeof(int));
    //��ӡ
    printf("%d\n", ps->n);
    printf("%f\n", ps->s);
    for (i = 0; i < 4; i++)
    {
        printf("%d ", ps->arr[i]);
    }
    //�ͷ�
    free(ps->arr);
    ps->arr = NULL;
    free(ps);
    ps = NULL;
    return 0;
} */

/* 
���� ����1 �� ����2 �������ͬ���Ĺ��ܣ����� ����1 ��ʵ���������ô���
��һ���ô��ǣ������ڴ��ͷ�
������ǵĴ�������һ���������õĺ����У������������˶����ڴ���䣬���������ṹ�巵�ظ�
�û����û�����free�����ͷŽṹ�壬�����û�����֪�����101�ṹ���ڵĳ�ԱҲ��Ҫfree��������
����ָ���û�����������¡����ԣ�������ǰѽṹ����ڴ��Լ����ԱҪ���ڴ�һ���Է����
�ˣ������ظ��û�һ���ṹ��ָ�룬�û���һ��free�Ϳ��԰����е��ڴ�Ҳ���ͷŵ���
�ڶ����ô��ǣ����������ڷ����ٶ�.
�������ڴ���������߷����ٶȣ�Ҳ�����ڼ����ڴ���Ƭ������ʵ���Ҹ��˾���Ҳû����ˣ�����
���ܲ���Ҫ����ƫ�����ļӷ���Ѱַ�� */