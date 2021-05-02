#include <stdio.h>
#include <string.h>
#include "crudfuction.h"

int main() {
  Animal alist[100];
  alist[0].age = -1;
  alist[0].sex = 'K';
  alist[0].gratuity = -1;

  int count = 0,index =0, menu;
  int delok;

  //count = loadData(alist);
  index = count;

  while(1) {
    menu = selectMenu();
    if(menu == 0) break;
    if(menu == 2 || menu == 3 || menu == 4)
        if(count == 0) continue;

    if(menu == 1) count += createAnimal(&alist[index++]);
    
    else if(menu == 2) listAnimal(alist, index);
    
    else if(menu == 3) {
      int num = selectNumber(alist, index);
      if(num > 0) updateAnimal(&alist[num-1]);
    }

    else if(menu == 4) {
      int num = selectNumber(alist, index);
      if(num > 0) {
        printf("������ �����Ͻðڽ��ϱ�?(���� 1��) :");
        scanf("%d",&delok);
        if(delok == 1) {
          deleteAnimal(&alist[num-1]);
          count--;
        }
      }
    }

    else if(menu == 5) {
      //saveData(alist,index);
    }

    else if(menu == 6) {
      printf("\n1. �̸����� �˻�\n");
      printf("2. ǰ������ �˻�\n");
      printf("3. ���̷� �˻�\n");
      printf("���ڸ� �Է����ּ��� : ");
      scanf("%d", &delok); /*
      switch(delok) {
        case 1: searchName(alist, count); break;
        case 2: searchType(alist, count); break;
        case 3: serachAge(alist, count); break;
        default: break;
      } */

    }
  }
  printf("���α׷��� ����Ǿ����ϴ�.\n");
  return 0;
}
