#include<stdio.h>
#include<string.h>
#define definePin 123456
int i,j,c;
int main_exit;
void menu();
char pass[20]="not match",password[20]="123";
struct date{

    int month,day,year;

           };
struct {

    char name[60];
    int acc_no,age;
    char address[60];
    char citizenship[15];
    double phone;
    char acc_type[10];
    float amt;
    struct date dob;
    struct date deposit;
    struct date withdraw;

    }add,upd,check,rem,transaction;

float interest(float t,float amount,int rate)
{
    float SI;
    SI=(rate*t*amount)/100.0;
    return (SI);

}


void new_acc()

{
    int choice;
    FILE *ptr;

    ptr=fopen("record.dat","a+");
    account_no:

    printf("ADD RECORD");
    printf("\nEnter the account number:");
    scanf("%d",&check.acc_no);
    while(fscanf(ptr,"%d %s %d %s %s %lf %f \n",&add.acc_no,add.name,&add.age,add.address,add.citizenship,&add.phone,&add.amt)!=EOF)
    {
        if (check.acc_no==add.acc_no)
            {printf("Account no. already in use!");

                goto account_no;

            }
    }
    add.acc_no=check.acc_no;
    printf("\nEnter the name:");
    scanf("%s",add.name);

    printf("\nEnter the age:");
    scanf("%d",&add.age);
    printf("\nEnter the address:");
    scanf("%s",add.address);
    printf("\nEnter the citizenship number:");
    scanf("%s",add.citizenship);
    printf("\nEnter the phone number: ");
    scanf("%lf",&add.phone);
    printf("\nEnter the amount to deposit:$");
    scanf("%f",&add.amt);

    fprintf(ptr,"%d %s %d %s %s %lf %f \n",add.acc_no,add.name,add.age,add.address,add.citizenship,add.phone,add.amt);


    fclose(ptr);
    printf("\nAccount created successfully!");
    add_invalid:
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);

    if (main_exit==1)
        menu();
    else if(main_exit==0)
            close();
    else
        {
            printf("\nInvalid!\a");
            goto add_invalid;
        }
}
void view_list()
{
    FILE *view;
    view=fopen("record.dat","r");
    int test=0;

    printf("\nACC. NO.\tNAME\t\t\tADDRESS\t\t\tPHONE\n");

    while(fscanf(view,"%d %s %d %s %s %lf %f \n",&add.acc_no,add.name,&add.age,add.address,add.citizenship,&add.phone,&add.amt)!=EOF)
    {
           printf("\n%6d\t %10s\t\t\t%10s\t\t%.0lf",add.acc_no,add.name,add.address,add.phone);
           test++;
       }

    fclose(view);
    if (test==0)
        {
            printf("\nNO RECORDS!!\n");}

    view_list_invalid:
     printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);

        if (main_exit==1)
            menu();
        else if(main_exit==0)
            close();
        else
        {
            printf("\nInvalid!\a");
            goto view_list_invalid;
        }
}
void edit(void)
{
    int choice,test=0;
    FILE *old,*newrec;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");

    printf("\nEnter the account no. of the customer whose info you want to change:");
    scanf("%d",&upd.acc_no);
    while(fscanf(old,"%d %s %d %s %s %lf %f \n",&add.acc_no,add.name,&add.age,add.address,add.citizenship,&add.phone,&add.amt)!=EOF)
    {
        if (add.acc_no==upd.acc_no)
        {   test=1;
            printf("\nWhich information do you want to change?\n1.Address\n2.Phone\n\nEnter your choice(1 for address and 2 for phone):");
            scanf("%d",&choice);

            if(choice==1)
                {printf("Enter the new address:");
                scanf("%s",upd.address);

                fprintf(newrec,"%d %s %d %s %s %lf %f \n",add.acc_no,add.name,add.age,upd.address,add.citizenship,add.phone,add.amt);



                printf("Changes saved!");
                }
            else if(choice==2)
                {
                    printf("Enter the new phone number:");
                scanf("%lf",&upd.phone);
                fprintf(newrec,"%d %s %d %s %s %lf %f \n",add.acc_no,add.name,add.age,add.address,add.citizenship,upd.phone,add.amt);


                printf("Changes saved!");
                }

        }
        else
            fprintf(newrec,"%d %s %d %s %s %lf %f \n",add.acc_no,add.name,add.age,add.address,add.citizenship,add.phone,add.amt);
 }
    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat","record.dat");

if(test!=1)
        {
            printf("\nRecord not found!!\a\a\a");
            edit_invalid:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&main_exit);

                 if (main_exit==1)

                    menu();
                else if (main_exit==2)
                    close();
                else if(main_exit==0)
                    edit();
                else
                    {printf("\nInvalid!\a");
                    goto edit_invalid;}
        }
    else
        {printf("\n\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);

        if (main_exit==1)
            menu();
        else
            close();
        }
}

void transact(void)
{   int choice,test=0;
    FILE *old,*newrec;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");

        printf("Enter the account no. of the customer:");
    scanf("%d",&transaction.acc_no);
    while(fscanf(old,"%d %s %d %s %s %lf %f \n",&add.acc_no,add.name,&add.age,add.address,add.citizenship,&add.phone,&add.amt)!=EOF)
    {

            if(add.acc_no==transaction.acc_no)
            {   test=1;

                printf("\n\nDo you want to\n1.Deposit\n2.Withdraw?\n\nEnter your choice(1 for deposit and 2 for withdraw):");
                scanf("%d",&choice);
                if (choice==1)
                {
                    printf("Enter the amount you want to deposit:$ ");
                    scanf("%f",&transaction.amt);
                    add.amt+=transaction.amt;
                    fprintf(newrec,"%d %s %d %s %s %lf %f \n",add.acc_no,add.name,add.age,add.address,add.citizenship,add.phone,add.amt);

                    printf("\n\nDeposited successfully!");
                }
                else
                {
                    printf("Enter the amount you want to withdraw:$ ");
                    scanf("%f",&transaction.amt);
                    add.amt-=transaction.amt;
                    fprintf(newrec,"%d %s %d %s %s %lf %f \n",add.acc_no,add.name,add.age,add.address,add.citizenship,add.phone,add.amt);
                    printf("\n\nWithdrawn successfully!");
                }

            }
            else
            {
               fprintf(newrec,"%d %s %d %s %s %lf %f \n",add.acc_no,add.name,add.age,add.address,add.citizenship,add.phone,add.amt);
            }
   }
   fclose(old);
   fclose(newrec);
   remove("record.dat");
   rename("new.dat","record.dat");
   if(test!=1)
   {
       printf("\n\nRecord not found!!");
       transact_invalid:
      printf("\n\n\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
      scanf("%d",&main_exit);

      if (main_exit==0)
        transact();
    else if (main_exit==1)
        menu();
    else if (main_exit==2)
        close();
    else
    {
        printf("\nInvalid!");
        goto transact_invalid;
    }

   }
   else
   {
       printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);

        if (main_exit==1)
            menu();
        else
            close();
   }

}
void erase(void)
{
    FILE *old,*newrec;
    int test=0;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");
    printf("Enter the account no. of the customer you want to delete:");
    scanf("%d",&rem.acc_no);
    while(fscanf(old,"%d %s %d %s %s %lf %f \n",&add.acc_no,add.name,&add.age,add.address,add.citizenship,&add.phone,&add.amt)!=EOF)
    {
        if(add.acc_no!=rem.acc_no)
            fprintf(newrec,"%d %s %d %s %s %lf %f \n",add.acc_no,add.name,add.age,add.address,add.citizenship,add.phone,add.amt);

        else
            {test++;
            printf("\nRecord deleted successfully!\n");
            }
   }
   fclose(old);
   fclose(newrec);
   remove("record.dat");
   rename("new.dat","record.dat");
   if(test==0)
        {
            printf("\nRecord not found!!\a\a\a");
            erase_invalid:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&main_exit);

                 if (main_exit==1)
                    menu();
                else if (main_exit==2)
                    close();
                else if(main_exit==0)
                    erase();
                else
                    {printf("\nInvalid!\a");
                    goto erase_invalid;}
        }
    else
        {printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);

        if (main_exit==1)
            menu();
        else
            close();
        }

}

void see(void)
{
    FILE *ptr;
    int test=0,rate;
    int choice;
    float time;
    float intrst;
    ptr=fopen("record.dat","r");

    printf("Enter the account number:");
    scanf("%d",&check.acc_no);

    while(fscanf(ptr,"%d %s %d %s %s %lf %f \n",&add.acc_no,add.name,&add.age,add.address,add.citizenship,&add.phone,&add.amt)!=EOF)
    {
        if(add.acc_no==check.acc_no)
        {
            test=1;
            printf("\nAccount NO.:%d\nName:%s \nAge:%d \nAddress:%s \nCitizenship No:%s \nPhone number:%lf \nAmount deposited:$ %.2f \n\n",add.acc_no,add.name,add.age,add.address,add.citizenship,add.phone,add.amt);
        }
    }

    fclose(ptr);
     if(test!=1)
        {
            printf("\nRecord not found!!\a\a\a");
            see_invalid:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&main_exit);

                 if (main_exit==1)
                    menu();
                else if (main_exit==2)
                    close();
                else if(main_exit==0)
                    see();
                else
                    {

                        printf("\nInvalid!\a");
                        goto see_invalid;}
        }
    else
        {printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);}
        if (main_exit==1)
        {

            menu();
        }

        else
           {


            close();
            }

}


void close(void)
{
    printf("\n\n\t\t Developed by mahmudul hasan !\n\n");
    }


void menu(void)
{   int choice;

    printf("\n\nACCOUNT BANK MANAGEMENT SYSTEM");
    printf("\n WELCOME TO THE MAIN MENU");
    printf("\n1.New account\n2.Update information\n3.Transactions\n4.Check the details\n5.Removing existing account\n6.View customer's list\n7.Exit\n Enter your choice:");
    scanf("%d",&choice);


    switch(choice)
    {
        case 1:new_acc();
        break;
        case 2:edit();
        break;
        case 3:transact();
        break;
        case 4:see();
        break;
        case 5:erase();
        break;
        case 6:view_list();
        break;
        case 7:close();
        break;

    }

}
char initializeAdmin()
{
    printf("\n1:To Login \n2:Forget Password? \n3:Exit\n");
    printf("\t\t Choice >> :");

    scanf("%d",&c);
    if(c==1) {

        printf("\n\n\t\t Input password:");
        scanf("%s",pass);

    }
    else if(c==2) {

        int sysPin;
        printf("\n\t\t Input the system pin:");
        scanf("%d",&sysPin);
        if(sysPin==definePin) {
                printf("\t\t ");


            printf("\n\t\t Wow !,You got the password.\n");
            printf("\n\t\t Your password: %s ",password);

            printf("\n\n\t\t want to login now?[yes/no]?");
            char cc[10];
            char yes[10] = "yes";
            scanf("%s",cc);
            if(strcmp(cc,yes)==0) {
                strcpy(pass,password);
            }
            else {

                initializeAdmin();
            }
        }
        else {

            initializeAdmin();
        }
    }
    else if(c==3) {

        close();
    }
    else{

        initializeAdmin();
    }

}
int main()
{

    int i=0;
    initializeAdmin();
    if(c==3) return 0;
    if (strcmp(pass,password)==0)
        {printf("\n\nPassword Match!\nLOADING");


            menu();
        }
    else
        {   printf("\n\nWrong password!!\a\a\a");
            login_try:
            printf("\nEnter 1 to try again and 0 to exit:");
            scanf("%d",&main_exit);
            if (main_exit==1)
                    {


                        main();
                    }

            else if (main_exit==0)
                    {

                    close();}
            else
                    {printf("\nInvalid!");

                    goto login_try;}

        }
        return 0;
}
