#include <stdio.h>

int input(char a[100],int b, char c[50]) {
    printf("======================\n");
    printf("�̸� : %s\n",a);
    printf("��ȣ : %d\n",b);
    printf("���� : %s\n",c);
    printf("======================\n");
}

int main() {
    char name[100];
    int num;
    char sex[50];

    do {
        printf("�̸��� �Է��ϼ���...\n");
        scanf("%s",&name);

        printf("��ȣ�� �Է��ϼ���...\n");
        scanf("%d",&num);

        printf("������ �Է��ϼ���...\n");
        scanf("%s",&sex);

        input(name,num,sex);

    } while (1);

    return 0;
}
