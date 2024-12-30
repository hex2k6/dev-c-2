#include "function.h"
#include <stdio.h>
#include <string.h>
//Logic ham

// Giao dien man hinh chinh
void lobbyMenu(int choice){
	printf("*** Convenience store management system ***\n");
	printf("\n\t\t CHOOSE YOUR ROLE\n");
	printf("\t\t==================\n");
	printf("\t\t[1].Category\n");
	printf("\t\t[2].Admin.\n");
	printf("\t\t[3].Exit.\n");
	printf("\t\t==================\n");
	printf("\t\tEnter The Choice: ");
}

// Giao dien dang nhap tai khoan admin
void loginAd(char userNameAD, char passWordAD){
	printf("*** Convenience store management system ***\n");
	printf("\n\t\t LOGIN ADMIN\n");
	printf("================================================\n");
	printf("\tEmail: ");
}

// Giao dien quan ly san pham cua Admin
void adminMenu(int choiceAdmin){
	printf("*** Convenience store management system ***\n");
	printf("\n\t\tProduct Management\n");
	printf("================================================\n");
	printf("[1].View product categories available in store\n"); // hien cac san pham dang co trong cua hang
	printf("[2].Add product.\n"); // them san pham
	printf("[3].Product repair.\n"); // sua san pham
	printf("[4].Delete product.\n"); // xoa san pham 
	printf("[5].Sort products.\n"); // sap xep san pham
	printf("[6].Exit.\n"); //Thoat
	printf("================================================\n");
	printf("Enter The Choice: ");
}
 // menu.01
void viewProduct(){
	FILE *ptr = fopen("product.dat","rb");
	if(ptr == NULL){
	printf("Error opening file.\n");
	}
	Product view;
	//in bang thong bao san pham 
	printf("*=======|======================================================================*|\n");
	printf("|  ID 	|       Name Product                     |                      Quantity|\n");
	printf("|=======|=======================================================================|\n");
	while( fread(&view, sizeof(Product), 1, ptr)== 1 ){
		printf("|% d | %s | %d |\n",
			view.id,
			view.nameProduct,
			view.quantity);
	printf("|-------|-----------------------------------------|-----------------------------|\n");	
	}
	printf("*=======|=========================================|============================*|\n");
	// Dong  file
	fclose(ptr);
}
 // menu.02	

void addproduct(){
	FILE *ptr = fopen("product.dat","ab+");
	if(ptr == NULL){
	printf("Error opening file.\n");
	return;
	}
	Product add[50];
	int n;
	printf("Enter the quantity of products you want to add:\n");
	scanf("%d", &n);
	getchar();
	for (int i=0; i<n; i++){
		printf("*Enter product information*\n");
		// ID san pham
		printf("ID: ");
		scanf("%d", &add[i].id);
		getchar();
		// Ten san pham
		printf("Name Product: ");
		fgets(add[i].nameProduct, sizeof(add[i].nameProduct), stdin);
		add[i].nameProduct[strcspn(add[i].nameProduct,"\n")] = '\0';
		fflush(stdin);
		// So luong san pham
		printf("Number of products: ");
		scanf("%d", &add[i].quantity);
		getchar();
	}
	fwrite(add, sizeof(Product), n, ptr);
	printf("\nProducts have been added successfully.\n");
	//Dong file
	fclose(ptr);
}
 // menu.03
void editproduct(){
	int addEdit;
	Product edit;
	FILE *ptr = fopen("product.dat", "rb+");
	if(ptr == NULL){
	printf("Error opening file.\n");
	return;
	}
	// Tinh so luong san pham co trong file
	fseek(ptr, 0, SEEK_END);
    int totalProducts = ftell(ptr) / sizeof(Product);
    fseek(ptr, 0, SEEK_SET);
	// Kiem tra admin muon sua san pham o vi tri nao
	printf("If you want to edit a product, please enter the ID: ");
	scanf("%d", &addEdit);
	while (addEdit < 1 || addEdit > totalProducts){
        printf("Invalid ID. Please enter a valid ID (1 to %d): ", totalProducts);
        scanf("%d", &addEdit);
    }
	// In ra man hinh san pham do luc chua sua
	printf("\nCurrent product details:\n"); 
	fseek(ptr, (addEdit - 1) * sizeof(Product), SEEK_SET);
    fread(&edit, sizeof(Product), 1, ptr);
	printf("*=======|======================================================================*|\n");
	printf("|  ID 	|       Name Product                     |                      Quantity|\n");
	printf("|=======|=======================================================================|\n");
	printf("|% d | %s | %d |\n",
		edit.id,
		edit.nameProduct,
		edit.quantity);
	printf("|-------|-----------------------------------------|-----------------------------|\n");	
	printf("*=======|=========================================|============================*|\n");
	// Sua san pham
	printf("\n*In the process of product repair*\n");
	getchar();
	printf("New product name: ");
	fgets(edit.nameProduct, sizeof(edit.nameProduct), stdin);
	edit.nameProduct[strcspn(edit.nameProduct, "\n")] = '\0';
	fflush(stdin);
	printf("Number of products: ");
	scanf("%d", &edit.quantity);
	getchar();
	// Luu san pham vao file
	fseek(ptr, (addEdit - 1) * sizeof(Product), SEEK_SET);
	fwrite(&edit, sizeof(Product), 1, ptr);
	// Dong file
	fclose(ptr);
}
