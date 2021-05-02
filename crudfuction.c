#include <stdio.h>
#include <string.h>
#include "crudfuction.h"

int selectMenu() {
  int menu;
  printf("\n 반려동물 찾기 프로그램입니다. \n");
  printf("1. 실종 동물 등록\n");
  printf("2. 실종 동물 조회\n");
  printf("3. 실종 동물 수정\n");
  printf("4. 실종 동물 삭제\n");
  printf("5. 실종 명단 저장\n");
  printf("6. 검색\n");
  printf("0. 종료\n");
  printf("원하시는 메뉴를 선택해주세요. : ");
  scanf("%d",&menu);
  return menu;
}

int createAnimal(Animal *a) {
  printf("실종 동물의 이름을 입력해주세요: ");
  scanf("%s", a->name);
  printf("실종 동물의 나이를 입력해주세요: ");
  scanf("%d", &a->age);
  printf("실종 동물의 품종을 입력해주세요: ");
  scanf("%s", a->breed);
  
  while(1) {
    printf("실종 동물의 성별을 입력해주세요");
    printf("(남자의 경우 m, 여자의 경우 w를 입력해주세요.): ");
    scanf("%c", &a->sex);
    if(a->sex == 'm' || a->sex == 'w' || a->sex == 'M' || a->sex == 'W') break;
  }
  
  printf("실종 동물을 찾을 경우 사례금을 입력해주세요: ");
  scanf("%d", &a->gratuity);

  return 1;
}

void readAnimal(Animal a) {
  if(a.age == -1 && a.gratuity == -1 && a.sex == 'K')
    printf("현재 입력된 동물이 없습니다.\n");
  else {
    printf("/\t%s\t/\t%d\t/\t%s\t/\t%c\t/\t%d\t/",
    a.name, a.age, a.breed, a.sex, a.gratuity);
  }
}

int updateAnimal(Animal *a) {
  printf("실종 동물의 이름을 입력해주세요: ");
  scanf("%s", a->name);
  printf("실종 동물의 나이를 입력해주세요: ");
  scanf("%d", &a->age);
  printf("실종 동물의 품종을 입력해주세요: ");
  scanf("%s", a->breed);
  
  while(1) {
    printf("실종 동물의 성별을 입력해주세요");
    printf("(남자의 경우 m, 여자의 경우 w를 입력해주세요.): ");
    scanf("%c", &a->sex);
    if(a->sex == 'm' || a->sex == 'w') break;
  }
  
  printf("실종 동물을 찾을 경우 사례금을 입력해주세요: ");
  scanf("%d", &a->gratuity);

  printf("->수정이 완료되었습니다! \n");
  return 1;
}

int deleteAnimal(Animal *a) {
  a->age = -1;
  a->gratuity = -1;
  a->sex = 'K';
  printf("데이터가 삭제되었습니다! \n");
  return 1;
}

void listAnimal(Animal *alist, int count) {
  printf("번호/\t이름\t/\t나이\t/\t품종\t/\t성별\t/\t사례금\t/\n");
  for(int i = 0; i < count; ++i) {
    if(alist[i].age == -1 && alist[i].gratuity == -1 && alist[i].sex == 'K') continue;
    printf("%2d", i+1);
    readAnimal(alist[i]);
  }
}

int selectNumber(Animal *alist, int count) {
  int num;
  listAnimal(alist, count);
  printf("무엇을 선택하시겠습니까? :");
  scanf("%d", &num);
  return num;
}