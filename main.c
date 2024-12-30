#include <stdio.h>
#include <stdlib.h>
#include "function.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	do{
		lobbyMenu(choice);
		scanf("%d", &choice);
		switch(choice){
			case 1:
				//Dang nhap admin
//				loginAd(userNameAD,passWordAD);
//				fflush(stdin);
//				fgets(userNameAD,sizeof(userNameAD),stdin);
//				printf("\tPassword: ");
//				fflush(stdin);
//				fgets(passWordAD,sizeof(passWordAD),stdin);
//				printf("================================================\n");
				do{
					// Lua chon cua admin
					adminMenu(choiceAdmin);
					scanf("%d", &choiceAdmin);
					
					switch(choiceAdmin){
						case 1:
							viewProduct();
							break;
						case 2:
							addproduct();
							break;
						case 3:
							editproduct();
							break;		
					}
				}while(choiceAdmin != 6);
				break;
			case 2:
				break;	
		}
	}while(choice != 3);
	return 0;
}
