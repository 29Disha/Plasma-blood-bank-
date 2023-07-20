#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<time.h>
#include<string.h>
#include <stdlib.h>

struct Patient
{
	int patient_id;
	char patient_name[40];
	int age;
	char blood_group[4];
	char gender[2];

};

struct Donor
{
    int donor_id;
    char donor_name[40];
    int age;
    char blood_group[4];
    char gender[2];

};

typedef struct Patient PAT;
typedef struct Donor DNR;

void instructions_menu();
void read_donor_instruction();
void read_patient_instruction();

void patient_menu();
void donor_menu();

int add_data(PAT *);
int add_data1(DNR *);

void decrypt_pat(PAT *);
void decrypt_dnr(DNR *);

int write_data();
int write_data1();

int delete_data(int);
int delete_data1(int);

void show_all_data();
void show_all_data1();

void show_single_data(int);
void show_single_data1(int);

void m_age();
void m_name();
void m_bloodgroup();
void m_gender();
void m1_age();
void m1_name();
void m1_bloodgroup();
void m1_gender();

void modify_data();
void modify_data1();

void new_age(PAT *);
void new_age1(DNR *);

void new_name(PAT *);
void new_name1(DNR *);

void new_bloodgroup(PAT *);
void new_bloodgroup1(DNR *);

void new_gender(PAT *);
void new_gender1(DNR *);

void showing_donor(int);

char name[]=" ";


int main()
{
	system("color 04");
	srand(time(0));
	printf("%*s", 40+strlen(name)/2, name, 40-strlen(name)/2, "");
	printf("----------PLASMA DONATION-----------\n ");
	puts(" ");
	int ch;
	int flag=1;
	while(flag)
	{
		printf("%*s", 40+strlen(name)/2, name, 40-strlen(name)/2, "");
		printf("Instructions for Patients and Donors(Enter 1)\n");
		printf("%*s", 40+strlen(name)/2, name, 40-strlen(name)/2, "");
		printf("Information about Patient(Enter 2)\n");
		printf("%*s", 40+strlen(name)/2, name, 40-strlen(name)/2, "");
		printf("Information about Donor(Enter 3)\n");
		printf("%*s", 40+strlen(name)/2, name, 40-strlen(name)/2, "");
		printf("Press 4 to EXIT\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: instructions_menu();
            		    	break;

			case 2:	patient_menu();
				break;

			case 3: donor_menu();
				break;

			case 4: flag=0;
				break;
		
			default: printf("INVALID CHOICE!! TERMINATING!!");
				exit(0);
				
		}
	
   	}

	return 0;
}

void instructions_menu()
{
     int choice_3;
     system("cls");
     printf(" *****CHOOSE YOUR CHOICE*****\n");
     printf("%d>INSTRUCTIONS FOR DONORS \n",1);
     printf("%d>INSTRUCTIONS FOR PATIENTS \n",2);
     printf("%d> BACK TO MAIN MENU \n",3);
     scanf("%d",&choice_3);
     switch(choice_3)
     {
         case 1: read_donor_instruction();
		 printf("\n\n");
         	 break;

         case 2: read_patient_instruction();
		 printf("\n\n");
         	 break;

         case 3: break;

         default:
        	 printf("INVALID CHOICE! ");
         	 break;
     }
}

void read_donor_instruction()
{
	system("cls");
	printf(" *****DONOR INSTRUCTIONS*****\n\n\n\n");
        FILE*fp=fopen("donor_info.txt","r");
	char buffer[500];

        if (fp==NULL)
        {
        	printf("\n\nEMPTY FILE!!\n\n ");
    	}

    	else 
    	{
        	while(fgets(buffer,500,fp))
		{
       		 	fputs(buffer,stdout);
		}
	}

	fclose(fp);
}

void read_patient_instruction()
{
	system("cls");
	printf(" *****PATIENT INSTRUCTIONS*****\n\n\n\n");
	FILE*fp=fopen("patient_info.txt","r");
    	char buffer[500];

        if (fp==NULL)
        {
        	printf("\n\nEMPTY FILE!!\n\n ");
    	}

    	else 
    	{
        	while(fgets(buffer,500,fp))
		{
       		 	fputs(buffer,stdout);
		}
	}

	fclose(fp);
}

void patient_menu()
{
			int choice_1,p_id;
			system("cls");
			printf("%*s", 40+strlen(name)/2, name, 40-strlen(name)/2, "");
			printf("----------PATIENT MENU-----------\n ");
			puts(" ");
			printf("%*s", 40+strlen(name)/2, name, 40-strlen(name)/2, "");
			printf(" *****CHOOSE YOUR CHOICE*****\n");
			printf("%*s", 40+strlen(name)/2, name, 40-strlen(name)/2, "");
      			printf("%d> ADD A PATIENT'S DATA  \n",1);
			printf("%*s", 40+strlen(name)/2, name, 40-strlen(name)/2, "");
      			printf("%d> SHOW ALL PATIENT DATA \n",2);
			printf("%*s", 40+strlen(name)/2, name, 40-strlen(name)/2, "");
      			printf("%d> SHOW A PARTICULAR PATIENT'S DATA \n",3);
			printf("%*s", 40+strlen(name)/2, name, 40-strlen(name)/2, "");
      			printf("%d> DELETE A PATIENT'S DATA  \n",4);
			printf("%*s", 40+strlen(name)/2, name, 40-strlen(name)/2, "");
      			printf("%d> MODIFY PATIENT DATA \n",5);
   	        	printf("%*s", 40+strlen(name)/2, name, 40-strlen(name)/2, "");
			printf("%d> BACK TO MAIN MENU \n",6);
   	        	printf("%*s", 40+strlen(name)/2, name, 40-strlen(name)/2, "");
			printf("%d> EXIT \n",7);

			printf("%*s", 40+strlen(name)/2, name, 40-strlen(name)/2, "");
      			printf("%d> CHECK FOR DONORS\n",8);

   	        	printf("%*s", 40+strlen(name)/2, name, 40-strlen(name)/2, "");
			scanf("%d",&choice_1);
			int result;
			switch(choice_1)
			{
				case 1: result=write_data();
					if(result==0)
					{
						printf("\n\nPATIENT RECORD ADDED SUCCESSFULLY\n\n\n\n");
						break;
					}
					else
						break;

				case 2: show_all_data();
					break;

				case 3: printf("\n Enter the ID of the patient:");
					scanf("%d",&p_id);
					show_single_data(p_id);
					break;

				case 4:printf("\n Enter the ID of the patient:");
					scanf("%d",&p_id);
					delete_data(p_id);
					break;

				case 5:	modify_data();
					break;
	
				case 6:break;
				
				case 7: exit(0);
				
				case 8:printf("\n Enter the ID of the patient:");
					scanf("%d",&p_id);
					showing_donor(p_id);
					break;
		
				default:printf("INVALID CHOICE!! TERMINATING!!");
					break;
			}

}

void donor_menu()
{
		int choice_2,d_id;
		system("cls");
		printf("%*s", 40+strlen(name)/2, name, 40-strlen(name)/2, "");
		printf("----------DONOR MENU-----------\n ");
		puts(" ");
		puts(" ");
		printf("%*s", 40+strlen(name)/2, name, 40-strlen(name)/2, "");
		printf(" *****CHOOSE YOUR CHOICE*****\n");
		printf("%d>ADD A DONOR'S DATA  \n",1);
    		printf("%*s", 40+strlen(name)/2, name, 40-strlen(name)/2, "");
          	printf("%d> SHOW ALL DONOR'S DATA \n",2);
    		printf("%*s", 40+strlen(name)/2, name, 40-strlen(name)/2, "");
          	printf("%d> SHOW A PARTICULAR DONOR'S DATA \n",3);
    		printf("%*s", 40+strlen(name)/2, name, 40-strlen(name)/2, "");
          	printf("%d> DELETE A DONOR'S DATA  \n",4);
    		printf("%*s", 40+strlen(name)/2, name, 40-strlen(name)/2, "");
          	printf("%d> MODIFY DONOR DATA \n",5);
    		printf("%*s", 40+strlen(name)/2, name, 40-strlen(name)/2, "");
		printf("%d> BACK TO MAIN MENU \n",6);
   	        printf("%*s", 40+strlen(name)/2, name, 40-strlen(name)/2, "");
		printf("%d> EXIT \n",7);
   	        printf("%*s", 40+strlen(name)/2, name, 40-strlen(name)/2, "");
		scanf("%d",&choice_2);
		int result;
		switch(choice_2)
		{
			case 1: result=write_data1();
				if(result==0)
				{
					printf("\n\nDONOR RECORD ADDED SUCCESSFULLY\n\n\n\n");
					break;
				}
				else
					break;

			case 2: show_all_data1();
				break;

			case 3: printf("\n Enter the ID of the donor:");
				scanf("%d",&d_id);
				show_single_data1(d_id);
				break;
	
			case 4:printf("\n Enter the ID of the donor:");
				scanf("%d",&d_id);
				delete_data1(d_id);
				break;

			case 5:	modify_data1();
				break;

			case 6:break;
				
			case 7: exit(0);
		
			default:printf("INVALID CHOICE!! TERMINATING!!");
				break;
		}
     
}


int add_data(PAT *ps)
{
	
	system("cls");// clears the screen
	printf("\n ************* ADDING DATA ************* \n");
	int i=0;
 	printf("Enter Name :");
     	fflush(stdin);
     	gets(ps->patient_name);
	for(i = 0; (i < 100 && ps->patient_name[i] != '\0'); i++)
        	ps->patient_name[i] = ps->patient_name[i] + 100;

     	printf("Enter age :");
	int check_age_p;
	scanf("%d",&check_age_p);
	int flag=1;
	while (flag==1)
	{
		if(check_age_p>70)
		{
			printf("You are above 70 years of age!!\n");
			int choice;
			printf("1)Re-enter age\n2)Cancel registration and Back to Main Menu\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1: printf("\nEnter age :");
					scanf("%d",&check_age_p);		
					break;

				case 2: flag=0;	
					return 1;
		
				default: printf("\ninvalid choice\n");
			}
			
		}
		else
		{
			ps->age=check_age_p;
			flag=0;
		}
	}
	ps->age=ps->age+746578926;
	
     	
     	printf("Enter Gender(M/F/O) :");
     	char gender_check_p[2];
	scanf("%s",gender_check_p);
     	fflush(stdin);

	int flag_1=1;
	while (flag_1==1)
	{
		if ((strcmp(gender_check_p,"M")!=0 && strcmp(gender_check_p,"F")!=0 && strcmp(gender_check_p,"O")!=0 && strcmp(gender_check_p,"m")!=0 && strcmp(gender_check_p,"f")!=0 && strcmp(gender_check_p,"o")!=0))
		{
			printf("\nEnter valid Gender as M/F/O only\n");
			int choice;
			printf("\n1)Re-enter gender\n2)Cancel registration and Back to Main Menu\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1: printf("Enter Gender(M/F/O) :");
					scanf("%s",gender_check_p);	
					break;

				case 2: flag_1=0;	
					return 1;
		
				default: printf("\ninvalid choice\n");
			}
			
		}

		else
		{
			strcpy(ps->gender,gender_check_p);
			flag_1=0;
		}
	}
	
	for(i = 0; (i < 100 && ps->gender[i] != '\0'); i++)
        	ps->gender[i] = ps->gender[i] + 100;

	fflush(stdin);
	printf("Enter Blood Group(A/B/O/AB)");
     	char bg_check_p[4];
	gets(bg_check_p);
     	fflush(stdin);
	int flag_2=1;
	while (flag_2==1)
	{
		if (strcmp(bg_check_p,"A")!=0 && strcmp(bg_check_p,"B")!=0  && strcmp(bg_check_p,"O")!=0 && strcmp(bg_check_p,"AB")!=0 && strcmp(bg_check_p,"a")!=0 && strcmp(bg_check_p,"b")!=0 && strcmp(bg_check_p,"o")!=0 && strcmp(bg_check_p,"ab")!=0)
		{
			printf("\nEnter valid Blood group as A/B/O/AB only\n");
			int choice;
			printf("\n1)Re-enter blood group\n2)Cancel registration and Back to Main Menu\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1: printf("Enter Blood Group(A/B/O/AB): ");
					scanf("%s",bg_check_p);	
					break;

				case 2: flag_2=0;	
					return 1;
		
				default: printf("\ninvalid choice\n");
			}
			
		}

		else
		{
			strcpy(ps->blood_group,bg_check_p);
			flag_2=0;
		}
	}
	for(i = 0; (i < 100 && ps->blood_group[i] != '\0'); i++)
        	ps->blood_group[i] = ps->blood_group[i] + 100;

	ps->patient_id=(rand()%1000);
	printf("\033[0;33m");
	printf("\nYour ID will be : %d \n\n" ,ps->patient_id);
	printf("\033[0m");
	system("color 04");

}

int add_data1(DNR *ds)
{
	system("cls");// clears the screen
	printf("\n ************* ADDING DATA ************* \n");
 	printf("Enter Name :");
     	fflush(stdin);
     	gets(ds->donor_name);
	//encryption
	int i=0;
	for(i = 0; (i < 100 && ds->donor_name[i] != '\0'); i++)
        	ds->donor_name[i] = ds->donor_name[i] + 100;
     	printf("Enter age :");
	int check_age_d;
	scanf("%d",&check_age_d);
	int flag=1;
	while (flag==1)
	{
		if(check_age_d>70)
		{
			printf("You are above 70 years of age and cannot donate plasma!\n");
			int choice;
			printf("1)Re-enter age\n2)Cancel registration and Back to Main Menu\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1: printf("\nEnter age :");
					scanf("%d",&check_age_d);		
					break;

				case 2: flag=0;	
					return 1;
		
				default: printf("\ninvalid choice\n");
			}
			
		}
		else
		{
			ds->age=check_age_d;
			flag=0;
		}
	}
	ds->age=ds->age+746578926;
     	fflush(stdin);

     	printf("Enter Gender(M/F/O) :");
	char gender_check_d[2];
	gets(gender_check_d);
     	fflush(stdin);

	int flag_1=1;
	while (flag_1==1)
	{
		if ((strcmp(gender_check_d,"M")!=0 && strcmp(gender_check_d,"F")!=0 && strcmp(gender_check_d,"O")!=0 && strcmp(gender_check_d,"m")!=0 && strcmp(gender_check_d,"f")!=0 && strcmp(gender_check_d,"o")!=0))
		{
			printf("\nEnter valid Gender as M/F/O only\n");
			int choice;
			printf("\n1)Re-enter gender\n2)Cancel registration and Back to Main Menu\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1: printf("Enter Gender(M/F/O) :");
					scanf("%s",gender_check_d);	
					break;

				case 2: flag_1=0;	
					return 1;
		
				default: printf("\ninvalid choice\n");
			}
			
		}

		else
		{
			strcpy(ds->gender,gender_check_d);
			flag_1=0;
		}
	}
	
	
	fflush(stdin);
	for(i = 0; (i < 100 && ds->gender[i] != '\0'); i++)
        	ds->gender[i] = ds->gender[i] + 100;

	printf("Enter Blood Group(A/B/O/AB): ");
	char bg_check_d[4];
	gets(bg_check_d);
     	fflush(stdin);
	int flag_2=1;
	while (flag_2==1)
	{
		if (strcmp(bg_check_d,"A")!=0 && strcmp(bg_check_d,"B")!=0  && strcmp(bg_check_d,"O")!=0 && strcmp(bg_check_d,"AB")!=0 && strcmp(bg_check_d,"a")!=0 && strcmp(bg_check_d,"b")!=0 && strcmp(bg_check_d,"o")!=0 && strcmp(bg_check_d,"ab")!=0)
		{
			printf("\nEnter valid Blood group as A/B/O/AB only\n");
			int choice;
			printf("\n1)Re-enter blood group\n2)Cancel registration and Back to Main Menu\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1: printf("Enter Blood Group(A/B/O/AB): ");
					scanf("%s",bg_check_d);	
					break;

				case 2: flag_2=0;	
					return 1;
		
				default: printf("\ninvalid choice\n");
			}
			
		}

		else
		{
			strcpy(ds->blood_group,bg_check_d);
			flag_2=0;
		}
	}
	
	fflush(stdin);
	for(i = 0; (i < 100 && ds->blood_group[i] != '\0'); i++)
        	ds->blood_group[i] = ds->blood_group[i] + 100;

	ds->donor_id=(rand()%1000);
	printf("\033[0;33m");
	printf("\nYour ID will be : %d \n\n" ,ds->donor_id);
	printf("\033[0m");
	system("color 04");
	return 0;

}

void decrypt_pat(PAT *ps)
{
	printf("\n\n******DECRYPTED VERSION*****\n\n");
	int i=0;

	for(i = 0; (i < 100 && ps->patient_name[i] != '\0'); i++)
        	ps->patient_name[i] = ps->patient_name[i] - 100;
     	
	for(i = 0; (i < 100 && ps->gender[i] != '\0'); i++)
        	ps->gender[i] = ps->gender[i] - 100;
	
	for(i = 0; (i < 100 && ps->blood_group[i] != '\0'); i++)
        	ps->blood_group[i] = ps->blood_group[i] - 100;	
	ps->age=ps->age-746578926;
}

void decrypt_dnr(DNR *ds)
{	
	printf("\n\n******DECRYPTED VERSION*****\n\n");
	int i=0;
	for(i = 0; (i < 100 && ds->donor_name[i] != '\0'); i++)
        	ds->donor_name[i] = ds->donor_name[i] - 100;
     	
	for(i = 0; (i < 100 && ds->gender[i] != '\0'); i++)
        	ds->gender[i] = ds->gender[i] - 100;
	
	for(i = 0; (i < 100 && ds->blood_group[i] != '\0'); i++)
        	ds->blood_group[i] = ds->blood_group[i] - 100;
	ds->age=ds->age-746578926;
}

void new_name(PAT *ps)
{
	int i;
	printf("Enter new name :");
     	scanf("%s",&ps->patient_name);
	for(i = 0; (i < 100 && ps->patient_name[i] != '\0'); i++)
        	ps->patient_name[i] = ps->patient_name[i] + 100;

}

void new_name1(DNR *ds)
{
	printf("Enter new name :");
     	scanf("%s",&ds->donor_name);
	int i;
	for(i = 0; (i < 100 && ds->donor_name[i] != '\0'); i++)
        	ds->donor_name[i] = ds->donor_name[i] + 100;

}

void new_age(PAT *ps)
{
	printf("Enter new age :");
     	scanf("%d",&ps->age);
	ps->age=ps->age+746578926;
}

void new_age1(DNR *ds)
{
	printf("Enter new age :");
     	scanf("%d",&ds->age);
	ds->age=ds->age+746578926;

}

void new_bloodgroup(PAT *ps)
{
	int i;
	printf("Enter new bloodgroup :");
     	scanf("%s",&ps->blood_group);
	for(i = 0; (i < 100 && ps->blood_group[i] != '\0'); i++)
        	ps->blood_group[i] = ps->blood_group[i] + 100;

}


void new_bloodgroup1(DNR *ds)
{
	printf("Enter new bloodgroup :");
     	scanf("%s",&ds->blood_group);
	int i;
	for(i = 0; (i < 100 && ds->blood_group[i] != '\0'); i++)
        	ds->blood_group[i] = ds->blood_group[i] + 100;


}

void new_gender(PAT *ps)
{
	int i;
	printf("Enter new gender :");
     	scanf("%s",&ps->gender);
	for(i = 0; (i < 100 && ps->gender[i] != '\0'); i++)
        	ps->gender[i] = ps->gender[i] + 100;


}

void new_gender1(DNR *ds)
{
	printf("Enter new gender :");
     	scanf("%s" ,ds->gender);
	int i;
	for(i = 0; (i < 100 && ds->gender[i] != '\0'); i++)
        	ds->gender[i] = ds->gender[i] + 100;

}

int write_data()
{
	PAT P;
	FILE *fp;
	fp=fopen("patient_data.bin","ab");
	int res=add_data(&P);
	if(res==0)
	{
		fwrite(&P,sizeof(P),1,fp);
		if(fwrite!=0)
			printf("\ncontents written succesfully in the file\n");
		else
			printf("error writing the file!");
		
		fclose(fp);
		return 0;
	}
	else
	{
		return 1;
	}


}

int write_data1()
{
	DNR D;
	FILE *fp;
	fp=fopen( "donor_data.bin","ab");
	int res=add_data1(&D);
	if(res==0)
	{
		fwrite(&D,sizeof(D),1,fp);
		if(fwrite!=0)
			printf("\ncontents written succesfully in the file\n");
		else
			printf("error writing the file!");
		
		fclose(fp);
		return 0;
	}
	else
	{
		return 1;
	}

}

void show_all_data()
{
	system("cls");
	PAT P;
	FILE *fp;
	int flag=0;
	fp=fopen("patient_data.bin","r");
	if(fp==NULL)
	{
		printf("\n\n EMPTY FILE!!\n\n\n\n");
	}
	
	else
	{
		printf("\n \n-------------PATIENTS DATA-------------\n \n");
		while(fread(&P,sizeof(P),1,fp))
		{
			flag=1;
			decrypt_pat(&P);
			printf("\n Patient ID=%d \n Patient Name=%s \n Patient Age=%d \n Patient Gender=%s \n Patient Bloodgroup=%s \n\n\n\n",P.patient_id,P.patient_name,P.age,P.gender,P.blood_group);
		}
	}
	
	if(flag==0)
			printf("\n\n----------EMPTY!! NO RECORDS!!------------\n\n\n\n");

	fclose(fp);

}

void show_all_data1()
{
	system("cls");
	DNR D;
	FILE *fp;
	fp=fopen("donor_data.bin","r");
	int flag=0;

	if(fp==NULL)
	{
		printf("\n\n EMPTY FILE!!\n\n\n\n");
	}
	
	else
	{
		printf("\n \n-------------DONOR DATA-------------\n \n");

		while(fread(&D,sizeof(D),1,fp))
		{
			flag=1;
			decrypt_dnr(&D);
			printf("\n donor ID=%d \n donor Name=%s \n donor Age=%d \n donor Gender=%s \n donor Bloodgroup=%s \n",D.donor_id,D.donor_name,D.age,D.gender,D.blood_group);
		}
	
	}
	
	if(flag==0)
			printf("\n\n----------EMPTY!! NO RECORDS!!------------\n\n\n\n");


	fclose(fp);

}


void show_single_data(int p_id)
{
	system("cls");
	FILE *fp;
	PAT P;
	int flag=0;

	fp=fopen("patient_data.bin","r");

	if(fp==NULL)
	{
		printf("\n\n EMPTY FILE!!\n\n\n\n");
	}
	
	else
	{
		printf("\n------------------THE REQUIRED PATIENT'S DATA----------------------\n\n");
		while(fread(&P,sizeof(P),1,fp))
		{
			flag=1;
			if(P.patient_id==p_id)
			{
				printf("\n\n******ENCRYPTED VERSION*****\n\n");
				printf("\n Patient ID=%d \n Patient Name=%s \n Patient Age=%d \n Patient Gender=%s \n Patient Bloodgroup=%s \n",P.patient_id,P.patient_name,P.age,P.gender,P.blood_group);
				decrypt_pat(&P);
				printf("\n Patient ID=%d \n Patient Name=%s \n Patient Age=%d \n Patient Gender=%s \n Patient Bloodgroup=%s \n",P.patient_id,P.patient_name,P.age,P.gender,P.blood_group);
			}
		}
	}
	if(flag==0)
			printf("\n\n----------NOT AVAILABLE------------\n\n\n\n");

	fclose(fp);
}

void show_single_data1(int d_id)
{
	system("cls");
	FILE *fp;
	DNR D;
	int flag=0;
	fp=fopen("donor_data.bin","r");

	if(fp==NULL)
	{
		printf("\n\n EMPTY FILE!!\n\n\n\n");
	}
	
	else
	{	
		printf("\n------------------THE REQUIRED DONOR'S DATA----------------------\n\n");
		while(fread(&D,sizeof(D),1,fp))
		{
			flag=1;
			if(D.donor_id==d_id)
			{
				printf("\n\n******ENCRYPTED VERSION*****\n\n");
				printf("\n donor ID=%d \n Donor Name=%s \n Donor Age=%d \n Donor Gender=%s \n Donor Bloodgroup=%s \n",D.donor_id,D.donor_name,D.age,D.gender,D.blood_group);
				decrypt_dnr(&D);
				printf("\n donor ID=%d \n Donor Name=%s \n Donor Age=%d \n Donor Gender=%s \n Donor Bloodgroup=%s \n",D.donor_id,D.donor_name,D.age,D.gender,D.blood_group);
			}
		}
	}	

	if(flag==0)
			printf("\n\n----------NOT AVAILABLE------------\n\n\n\n");

	fclose(fp);
}


int delete_data(int p_id)
{
	system("cls");
	PAT P;
	FILE *fp;
	FILE *fp_tmp;
	int found=0;
	fp=fopen("patient_data.bin","r");
	printf("\n ************* DELETING DATA ************* \n");
	if(fp==NULL)
	{
		printf("NO DATA IN FILE!");
		return 0;
	}
	fp_tmp=fopen("tmp_pat.bin", "wb");
	if(fp_tmp==NULL)
	{
		printf("NO DATA IN FILE!");
	}

	while (fread(&P,sizeof(P),1,fp))
	{
		if (P.patient_id==p_id)
		{
			printf("A record with requested ID found and deleted \n\n\n\n");
			found=1;
		}
		else
		{
			fwrite(&P, sizeof(P), 1, fp_tmp);
		}
	}

	if (!found)
	{
		printf("No record found with the requested ID: %d \n\n\n\n", p_id);
	}

	fclose(fp);
	fclose(fp_tmp);
	remove("patient_data.bin");
	rename("tmp_pat.bin","patient_data.bin");
}

int delete_data1(int d_id)
{
	system("cls");
	DNR D;
	FILE *fp;
	FILE *fp_tmp;
	int found=0;
	fp=fopen( "donor_data.bin","r");
	printf("\n ** DELETING DATA ** \n");
	if(fp==NULL)
	{
		printf("NO DATA IN FILE!");
		return 0;
	}
	fp_tmp=fopen("tmp_DNR.bin", "wb");
	if(fp_tmp==NULL)
	{
		printf("NO DATA IN FILE!");
	}

	while (fread(&D,sizeof(D),1,fp))
	{
		if (D.donor_id==d_id)
		{
			printf("A record with requested ID found and deleted \n\n\n\n");
			found=1;
		}
		else
		{
			fwrite(&D, sizeof(D), 1, fp_tmp);
		}
	}
	if (!found)
	{
		printf("No record found with the requested ID: %d \n\n\n\n", d_id);
	}

	fclose(fp);
	fclose(fp_tmp);
	remove( "donor_data.bin");
	rename("tmp_DNR.bin", "donor_data.bin");
}



void modify_data()
{

	puts(" ");
	printf("%*s", 40+strlen(name)/2, name, 40-strlen(name)/2, "");
	printf(" *****CHOOSE YOUR CHOICE*****\n");
	puts(" ");
	printf("%*s", 40+strlen(name)/2, name, 40-strlen(name)/2, "");
      	printf("%d> MODIFY THE PATIENT NAME  \n",1);
	printf("%*s", 40+strlen(name)/2, name, 40-strlen(name)/2, "");
      	printf("%d> MODIFY THE PATIENT AGE \n",2);
	printf("%*s", 40+strlen(name)/2, name, 40-strlen(name)/2, "");
      	printf("%d> MODIFY THE PATIENT BLOODGROUP \n",3);
	printf("%*s", 40+strlen(name)/2, name, 40-strlen(name)/2, "");
      	printf("%d> MODIFY PATIENT GENDER \n",4);
	printf("%*s", 40+strlen(name)/2, name, 40-strlen(name)/2, "");
	printf("%d> BACK TO MAIN MENU \n",5);
	printf("%*s", 40+strlen(name)/2, name, 40-strlen(name)/2, "");
     	int choice;
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:m_name();
			 break;

		case 2:	m_age();
			break;

		case 3: m_bloodgroup();
			break;

		case 4:m_gender();
			break;	

		case 5: break;

		default:printf("INVALID CHOICE!!");
			break;
	}




}

void modify_data1()
{

	puts(" ");
	printf("%*s", 40+strlen(name)/2, name, 40-strlen(name)/2, "");
	printf(" *CHOOSE YOUR CHOICE*\n");
	puts(" ");
	printf("%*s", 40+strlen(name)/2, name, 40-strlen(name)/2, "");
      	printf("%d> MODIFY THE DONOR NAME  \n",1);
	printf("%*s", 40+strlen(name)/2, name, 40-strlen(name)/2, "");
      	printf("%d> MODIFY THE DONOR AGE \n",2);
	printf("%*s", 40+strlen(name)/2, name, 40-strlen(name)/2, "");
      	printf("%d> MODIFY THE DONOR BLOODGROUP \n",3);
	printf("%*s", 40+strlen(name)/2, name, 40-strlen(name)/2, "");
      	printf("%d> MODIFY DONOR GENDER \n",4);
	printf("%*s", 40+strlen(name)/2, name, 40-strlen(name)/2, "");
	printf("%d> BACK TO MAIN MENU \n",5);
	printf("%*s", 40+strlen(name)/2, name, 40-strlen(name)/2, "");
     	int choice;

	scanf("%d",&choice);
	switch(choice)
	{
		case 1:m1_name();
			 break;

		case 2:	m1_age();
			break;

		case 3: m1_bloodgroup();
			break;

		case 4:m1_gender();
			break;

		case 5: break;

		default:printf("INVALID CHOICE!!");
			break;
	}




}

void m_name()
{
	PAT P;
	int p_id;
	int flag=0;
	printf("\n Enter the ID of the patient:");
	fflush(stdin);
	scanf("%d",&(p_id));
	FILE *fp;

	fp=fopen("patient_data.bin","rb+");

	while (fread(&P,sizeof(P),1,fp))
	{
		if(P.patient_id==p_id)
		{
			flag=1;
			new_name(&P);
			fseek(fp,-sizeof(P),1);
			fwrite(&P,sizeof(P),1,fp);
			printf("\nNAME UPDATED!!\n");
			break;


		}
	}
	if(ferror(fp))
	{
		printf("Error occured");
	}

	if(flag==0)
		printf("\nInvalid id!!\n");
	fclose(fp);

}

void m1_name()
{
	DNR D;
	int d_id;
	int flag=0;
	printf("\n Enter the ID of the donor:");
	fflush(stdin);
	scanf("%d",&(d_id));
	FILE *fp;

	fp=fopen( "donor_data.bin","rb+");

	while (fread(&D,sizeof(D),1,fp))
	{
		if(D.donor_id==d_id)
		{
			flag=1;
			new_name1(&D);
			fseek(fp,-sizeof(D),1);
			fwrite(&D,sizeof(D),1,fp);
			printf("\nNAME UPDATED!!\n");
			break;


		}
	}
	if(flag==0)
		printf("\nInvalid id!!\n");
	fclose(fp);

}


void m_age()
{
	PAT P;
	int p_id_1;
	int flag=0;
	printf("\n Enter the ID of the patient:");
	fflush(stdin);
	scanf("%d",&(p_id_1));
	FILE *fp;

	fp=fopen("patient_data.bin","rb+");

	while (fread(&P,sizeof(P),1,fp))
	{
		if(P.patient_id==p_id_1)
		{
			flag=1;
			new_age(&P);
			fseek(fp,-sizeof(P),1);
			fwrite(&P,sizeof(P),1,fp);
			printf("\nAGE UPDATED!!\n");
			break;


		}
	}
	if(flag==0)
		printf("\nInvalid id!!\n");
	fclose(fp);

}

void m1_age()
{
	
	DNR D;
	int d_id_1;
	int flag=0;
	printf("\n Enter the ID of the patient:");
	fflush(stdin);
	scanf("%d",&(d_id_1));
	FILE *fp;

	fp=fopen("donor_data.bin","rb+");

	while (fread(&D,sizeof(D),1,fp))
	{
		if(D.donor_id==d_id_1)
		{
			flag=1;
			new_age1(&D);
			fseek(fp,-sizeof(D),1);
			fwrite(&D,sizeof(D),1,fp);
			printf("\nAGE UPDATED!!\n");
			break;


		}
	}
	if(flag==0)
		printf("\nInvalid id!!\n");
	fclose(fp);

}
void m_bloodgroup()
{
	PAT P;
	int p_id_2;
	int flag=0;
	printf("\n Enter the ID of the patient:");
	fflush(stdin);
	scanf("%d",&(p_id_2));
	FILE *fp;

	fp=fopen("patient_data.bin","rb+");

	while (fread(&P,sizeof(P),1,fp))
	{
		if(P.patient_id==p_id_2)
		{
			flag=1;
			new_bloodgroup(&P);
			fseek(fp,-sizeof(P),1);
			fwrite(&P,sizeof(P),1,fp);
			printf("\nBLOOD GROUP UPDATED!!\n");
			break;


		}
	}
	if(flag==0)
		printf("\nInvalid id!!\n");
	fclose(fp);

}

void m1_bloodgroup()
{
	DNR D;
	int d_id_2;
	int flag=0;
	printf("\n Enter the ID of the donor:");
	fflush(stdin);
	scanf("%d",&(d_id_2));
	FILE *fp;

	fp=fopen("donor_data.bin","rb+");

	while (fread(&D,sizeof(D),1,fp))
	{
		if(D.donor_id==d_id_2)
		{
			flag=1;
			new_bloodgroup1(&D);
			fseek(fp,-sizeof(D),1);
			fwrite(&D,sizeof(D),1,fp);
			printf("\nBLOOD GROUP UPDATED!!\n");
			break;


		}
	}
	if(flag==0)
		printf("\nInvalid id!!\n");
	fclose(fp);

}


void m_gender()
{
	PAT P;
	int p_id_3;
	int flag=0;
	printf("\n Enter the ID of the patient:");
	fflush(stdin);
	scanf("%d",&(p_id_3));
	FILE *fp;

	fp=fopen("patient_data.bin","rb+");

	while (fread(&P,sizeof(P),1,fp))
	{
		if(P.patient_id==p_id_3)
		{
			flag=1;
			new_gender(&P);
			fseek(fp,-sizeof(P),1);
			fwrite(&P,sizeof(P),1,fp);
			printf("\nGENDER UPDATED!!\n");
			break;


		}
	}
	if(flag==0)
		printf("\nInvalid id!!\n");
	fclose(fp);

}

void m1_gender()
{
	DNR D;
	int d_id_3;
	int flag=0;
	printf("\n Enter the ID of the donor:");
	fflush(stdin);
	scanf("%d",&(d_id_3));
	FILE *fp;

	fp=fopen( "donor_data.bin","rb+");

	while (fread(&D,sizeof(D),1,fp))
	{
		if(D.donor_id==d_id_3)
		{
			flag=1;
			new_gender1(&D);
			fseek(fp,-sizeof(D),1);
			fwrite(&D,sizeof(D),1,fp);
			printf("\nGENDER UPDATED!!\n");
			break;


		}
	}
	if(flag==0)
		printf("\nInvalid id!!\n");
	fclose(fp);

}


void showing_donor(int p_id)
{
	system("cls");
	printf("\n ************* DISPLAYING DONORS FOR GIVEN PATIENT ID ************* \n");
	FILE* fp1=fopen("patient_data.bin","r");
	FILE* fp2=fopen("donor_data.bin","r");
	char bgcheck[4];
	PAT P;
	DNR D;
	int found=0;
	
	if(fp1==NULL||fp2==NULL)
	{
		printf("\n\nNO DATA IN EITHER DONOR OR PATIENT FILE!\n\n\n\n");
		
	}
	
	else
	{

		while (fread(&P,sizeof(P),1,fp1))
		{
			if (P.patient_id==p_id)
			{
				printf("\n\nA record with requested ID %d found!! \n\n\n\n",p_id);
				found=1;
				strcpy(bgcheck,P.blood_group);
			}
		
		}
	
		if (!found)
		{
			printf("\n\nNo record found with the requested ID: %d !!\n\n\n\n", p_id);
		}

		int count=0;
		int i=1;
	
		while (fread(&D,sizeof(D),1,fp2))
		{
			if (strcmp(bgcheck,D.blood_group)==0)
			{
				count++;
				printf("ID %d: %d\n",i,D.donor_id);
				i++;
			}
		}	
	
		if (found==1&&count==0)
	
			printf("\n\nThe required blood plasma is not available at the moment! \n\n\n\n");
	
		if(count>0)
			printf("\n\nWe have %d donor/donors for your blood type! Please refer above for the suitable donor ids\n\n\n",count);
	}

	fclose(fp1);
	fclose(fp2);

}