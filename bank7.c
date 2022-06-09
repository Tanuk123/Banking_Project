#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void createacc();
void deleteacc();
void viewacc();
void withdraw();
void deposit();
void transfer();
struct bank
{
	char name[50];
	char addr[100];
	int bal;
	double mobile;
	char branch[100];
	
};
struct bank b[100];
int t=0;
int an[20]={10000100,10000200,10000300,10000400,10000500,10000600};
int main()
{
	int ch;
	while(1)
	{       printf("\n\n\t\t\tSWISS BANK");
		printf("\n\n\t\t\t     Main Menu \n\n\t");
		printf("\tPress 1 to Create new account\n\n\t");
		printf("\tPress 2 to Delete account\n\n\t");
		printf("\tPress 3 to View account\n\n\t");
		printf("\tPress 4 to Withdraw money\n\n\t");
		printf("\tPress 5 to Deposit money\n\n\t");
		printf("\tPress 6 to Transfer money\n\n\t");
		printf("\tPress 7 to Exit\n\n\t");
		printf("\tEnter your choice : ");
		scanf("%d",&ch);
		switch (ch){
			case 1: createacc();
			        break;
			case 2: deleteacc();
			        break;
		        case 3: viewacc();
			        break;	
			case 4: withdraw();
			        break;		
			case 5: deposit();
			        break;
			case 6: transfer();
			        break;        
			case 7: exit(0);
			        break;
			default: printf("\n\nEnter valid choice.........\n");		
	        }					
        }
}
void createacc()
{
        FILE *fp;
	printf("\n\n");
	fp=fopen("jaya.txt","a");
	printf("* CREATING NEW ACCOUNT *");
	printf("\n\n\n   Enter your details->");
	printf("\n\n\n\tAccount no: %d ",an[t]);
	printf("\n\n\tHolder Name: ");
	scanf("%s",b[t].name);
	printf("\n\n\tAddress: ");
	scanf("%s",b[t].addr);
	printf("\n\n\tBranch: ");
	scanf("%s",b[t].branch);
	printf("\n\n\tMobile Number: ");
	scanf("%d",&b[t].mobile);
	fflush(stdin);
	amt:
	printf("\n\n\tenter opening Balance: ");
	scanf("%d",&b[t].bal);
	if(b[t].bal<2000){
		printf("2000 is minimum amount to deposit");
		goto amt;
	}
        fprintf(fp,"%d\t %s\t %s\t %s\t %d\t %d\n",an[t],b[t].name,b[t].addr,b[t].branch,b[t].mobile,b[t].bal);
        fclose(fp);
	 printf("\n\t** Account Created Successfully **");
	 printf("\n\n\t\t****** Thank You For Choosing Us ******");
	t++;
}
void deleteacc(){
        FILE *old;
        FILE *new_file;	
        int acc,i,j,flag=0;
        old=fopen("jaya.txt","r");
	new_file=fopen("newtanu.txt","w");
	printf("\n\n");
	printf("\n\n\nEnter the account no. which you want to delete : ");
	scanf("%d",&acc);
	for(i=0;i<t;i++)
	{
		if(an[i]==acc)
		{
			flag=1;
			break;
		}
	}
	if(flag==1)
	{
		for (j = i; j < t; j++)
        {
            an[j] = an[j+1];
            b[j].bal = b[j + 1].bal;
            strcpy(b[j].name, b[j + 1].name);
            strcpy(b[j].addr, b[j + 1].addr);
        }
        t--;
		fclose(old);
    fclose(new_file);
    remove("jaya.txt");
    rename("newtanu.txt","BANk.txt");
		printf("\n\n\n  Account deleted successfully.....");
	}
	else
		printf("\n\n\nAccount not found......");
}
void viewacc()
{
        int acc,i,flag=0;
	printf("\n\n");
	printf("* YOUR ACCOUNT DETAILS *");
	printf("\n\n\nEnter the account no. : ");
	scanf("%d",&acc);
	for(i=0;i<t;i++)
	{
		if(an[i]==acc)
		{
			flag=1;
			break;
		}
	}
	if(flag==1)
	{
		//printf("\n\n\nAccount no: %d",an[t]);
		printf("\n\nName: %s",b[i].name);
		printf("\n\nAddress: %s",b[i].addr);
		printf("\n\nBalance: %d",b[i].bal);
		printf("\n\nBranch: %s",b[i].branch);
	}
	else
		printf("\n\n\nAccount not found......");

}			
void withdraw(){	
        int acc,i,flag=0,amt;
	printf("\n\n");
	printf("* WITHDRAW MONEY *");
	printf("\n\n\nEnter the account no. : ");
	scanf("%d",&acc);
	for(i=0;i<t;i++)
	{
		if(an[i]==acc)
		{
			flag=1;
			break;
		}
	}
	if(flag==1)
	{
		printf("\n\nEnter the amount of money to withdraw: ");
		scanf("%d,",&amt);
		if(amt>b[i].bal)
			printf("\n\nNot enough money........");
		else
		{
			b[i].bal-=amt;
			printf("\n\nAmount deducted successfully.....");
			printf("\n\n\nAccount no: %d",an[t]);
			printf("\n\nName: %s",b[i].name);
			printf("\n\nAddress: %s",b[i].addr);
			printf("\n\nBalance: %d",b[i].bal);
		}
	}
	else
		printf("\n\n\nAccount not found......");
}
			
void deposit(){
	int acc,i,flag=0,amt;
	printf("\n\n");
	printf("* DEPOSIT MONEY *");
	printf("\n\n\nEnter the account no. : ");
	scanf("%d",&acc);
	for(i=0;i<t;i++)
	{
		if(an[i]==acc)
		{
			flag=1;
			break;
		}
	}
	if(flag==1)
	{
		printf("\n\nEnter the amount of money to deposit: ");
		scanf("%d,",&amt);
		b[i].bal+=amt;
		printf("\n\nAmount deposited successfully.....");
		printf("\n\n\nAccount no: %d",an[i]);
		printf("\n\nName: %s",b[i].name);
		printf("\n\nAddress: %s",b[i].addr);
		printf("\n\nBalance: %d",b[i].bal);
	}
	else
		printf("\n\n\nAccount not found......");
}
void transfer(){
        int acc,i,flag=0,tr;
        int ta=0;
        printf("\n\n");
	printf("* TRANSFER MONEY *");
	printf("\n\n\nEnter your account no. : ");
	scanf("%d",&acc);
        for(i=0;i<t;i++)
	{
		if(an[i]==acc)
		{
			flag=1;
			break;
		}
	}
	if(flag==1)
	{
		 printf("Enter Transfer Account Number:\n");
		 scanf("%d",&tr);
		 printf("Enter Amount you want to Transfer\n");
		 scanf("%d",&ta);
		 if(ta>b[i].bal)
			printf("\n\nNot enough money........");
		 else
			 b[i].bal-=ta;	
			 printf("\n\nAmount deducted successfully.....");
			 printf("\n\n\nAccount no: %d",tr);
			 printf("\n\nName: %s",b[i].name);
			 printf("\n\nAddress: %s",b[i].addr);
			 printf("\n\nBalance: %d",b[i].bal);
	}
        
        
        else
		 printf("\n\n\nAccount not found......");
}