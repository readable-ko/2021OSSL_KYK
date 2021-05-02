#include <stdio.h>
#include <string.h>
#include "crudfuction.h"

int selectMenu() {
  int menu;
  printf("\n �ݷ����� ã�� ���α׷��Դϴ�. \n");
  printf("1. ���� ���� ���\n");
  printf("2. ���� ���� ��ȸ\n");
  printf("3. ���� ���� ����\n");
  printf("4. ���� ���� ����\n");
  printf("5. ���� ��� ����\n");
  printf("6. �˻�\n");
  printf("0. ����\n");
  printf("���Ͻô� �޴��� �������ּ���. : ");
  scanf("%d",&menu);
  return menu;
}

int createAnimal(Animal *a) {
  printf("���� ������ �̸��� �Է����ּ���: ");
  scanf("%s", a->name);
  printf("���� ������ ���̸� �Է����ּ���: ");
  scanf("%d", &a->age);
  printf("���� ������ ǰ���� �Է����ּ���: ");
  scanf("%s", a->breed);
  
  while(1) {
    printf("���� ������ ������ �Է����ּ���");
    printf("(������ ��� m, ������ ��� w�� �Է����ּ���.): ");
    scanf("%c", &a->sex);
    if(a->sex == 'm' || a->sex == 'w' || a->sex == 'M' || a->sex == 'W') break;
  }
  
  printf("���� ������ ã�� ��� ��ʱ��� �Է����ּ���: ");
  scanf("%d", &a->gratuity);

  return 1;
}

void readAnimal(Animal a) {
  if(a.age == -1 && a.gratuity == -1 && a.sex == 'K')
    printf("���� �Էµ� ������ �����ϴ�.\n");
  else {
    printf("/\t%s\t/\t%d\t/\t%s\t/\t%c\t/\t%d\t/",
    a.name, a.age, a.breed, a.sex, a.gratuity);
  }
}

int updateAnimal(Animal *a) {
  printf("���� ������ �̸��� �Է����ּ���: ");
  scanf("%s", a->name);
  printf("���� ������ ���̸� �Է����ּ���: ");
  scanf("%d", &a->age);
  printf("���� ������ ǰ���� �Է����ּ���: ");
  scanf("%s", a->breed);
  
  while(1) {
    printf("���� ������ ������ �Է����ּ���");
    printf("(������ ��� m, ������ ��� w�� �Է����ּ���.): ");
    scanf("%c", &a->sex);
    if(a->sex == 'm' || a->sex == 'w') break;
  }
  
  printf("���� ������ ã�� ��� ��ʱ��� �Է����ּ���: ");
  scanf("%d", &a->gratuity);

  printf("->������ �Ϸ�Ǿ����ϴ�! \n");
  return 1;
}

int deleteAnimal(Animal *a) {
  a->age = -1;
  a->gratuity = -1;
  a->sex = 'K';
  printf("�����Ͱ� �����Ǿ����ϴ�! \n");
  return 1;
}

void listAnimal(Animal *alist, int count) {
  printf("��ȣ/\t�̸�\t/\t����\t/\tǰ��\t/\t����\t/\t��ʱ�\t/\n");
  for(int i = 0; i < count; ++i) {
    if(alist[i].age == -1 && alist[i].gratuity == -1 && alist[i].sex == 'K') continue;
    printf("%2d", i+1);
    readAnimal(alist[i]);
  }
}

int selectNumber(Animal *alist, int count) {
  int num;
  listAnimal(alist, count);
  printf("������ �����Ͻðڽ��ϱ�? :");
  scanf("%d", &num);
  return num;
}