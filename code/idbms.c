
      total[i]=temp.array[i].total;
      percentage[i]=temp.array[i].percentage;
      y=temp.unique;
      strcpy(name[i],temp.array[i].name);
      strcpy(id[i],temp.array[i].id);
      strcpy(branch[i],temp.array[i].branch);
      strcpy(surname[i],temp.array[i].surname);
      naman[i]=temp.array[i].naman;
   }
   }
   fclose(fp);
}
void update_in_file()
{
   FILE *fp;
   fp=fopen("data.txt","w");
   boo temp; 
   for (int i = 0; i <100; i++)
   {

      temp.array[i].dsa=dsa[i];
      temp.array[i].dbms=dbms[i];
      temp.array[i].c=c[i];
      temp.array[i].total=total[i];
      temp.array[i].percentage=percentage[i];
      temp.unique=y;
      strcpy(temp.array[i].name,name[i]);
      strcpy(temp.array[i].id,id[i]);
      strcpy(temp.array[i].branch,branch[i]);    
      strcpy(temp.array[i].surname,surname[i]);
      temp.array[i].naman=naman[i];        
   }
   fwrite (&temp, sizeof(boo), 1, fp);  
   fclose(fp);
}

void new(int x)
{
      char a[100];
      char b[100];
      char c[100];
      char d[100];
      printf("\nEnter student id: ");
      scanf("%s",a);
      for (int i = 0; i < 100; i++)
      {
         if (strcmp(a,id[i])==0)
         {
            printf("\nStudent id already registered in the course\n");
            new(x);
         }
         
      }

      printf("Enter your FIRST name(without space): ");
      scanf("%s",b);
      printf("Enter your LAST name(without space): ");
      scanf("%s",c);
      printf("Enter student branch(CSE,CCE,ECE,ME,IN SMALL LETTERS): ");
      scanf("%s",d);
      printf("\n------STUDENT PROFILE CREATED SUCCESSFULLY------\n");
      printf("\n*************************************\n");
      strcpy(name[x],b);
      strcpy(id[x],a);
      strcpy(branch[x],d);
      strcpy(surname[x],c);
      naman[x]=1;      
      x++;
      y=x;
      update_in_file();
      int w;
      printf("\n0. Go back to MENU\n");
      printf("1. Want to add another student profile\n");
      printf("Please enter your choice: ");
      scanf("%d",&w);
      if (w==0)
      {  
         update_in_file();
         start();
      }
      else
      {
         new(y);
      }
}
void check()
{
      for (int i = 0; i < 100; i++)
      {
         if (naman[i]==1)
         {
               printf("--------------------\n");
               printf("\nStudent id: %s\nName: %s %s\nMarks in c: %f\nMarks in dsa: %f\nMarks in DBMS: %f\nTOTAL: %f\nPercentage: %f\n\n",id[i],name[i],surname[i],c[i],dsa[i],dbms[i],total[i],percentage[i]);

           }       
      }   
}

void head()
{
printf("------WELCOME-TO-STUDENT-DATABASE-MANAGEMENT-SYSTEM------\n");
}

void existing_student()
{
   printf("\n------EXISTING STUDENT PROFILE-------\n");
   printf("\n1. Search the student\n");
   printf("2. MODIFY the student database\n"); 
   printf("3. Go back to menu\n");
   printf("\nPlease enter your choice: ");
   int b;
   scanf("%d",&b);
   if (b==3)
   {
      start();
   }
   else if (b==1)
   {
      search_the_student();
   }
   else if (b==2)
   {
      modify();
   }
   else
   {
      existing_student();
   }
   
         
}

void search_the_student()
{
   printf("\n*************************************\n");
   printf("\n-----SEARCH THE STUDENT-----\n");
   printf("\n*************************************\n");
   printf("1. By id\n");
   printf("2. By name\n");
   printf("3. By branch\n");
   printf("4. By threshold percentage\n");
   printf("5. Show the whole marks list\n");
   printf("6. By thresold percentage in a paricular branch\n");
   printf("7. Go back\n");
   int arch;   
   printf("\nPlease enter your choice: ");
   scanf("%d",&arch);
   if (arch==7)
   {
      existing_student();
   }
   else if (arch==2)
   {
      printf("\n*************************************");
      printf("\n1. Search by full name\n");
      printf("2. Search by first name\n");
      int yu;
      printf("\nplease enter your choice: ");
      scanf("%d",&yu);
      if (yu==1)
      {
         char a[100];
         char b[100];
         printf("\nPlease enter your first name: ");
         scanf("%s",a);
         printf("Please enter your last name: ");
         scanf("%s",b);
         for (int i = 0; i < 100; i++)
         {
            if (strcmp(name[i],a)==0 && strcmp(surname[i],b)==0)
            {
               printf("\nStudent id: %s\nName: %s %s\nBranch: %s\n\n",id[i],name[i],surname[i],branch[i]);
           } 
            
         }
         search_the_student();          
      }
      else if (yu==2)
      {
         char a[100];
         printf("\nPlease enter first name: ");
         scanf("%s",a);
         for (int i = 0; i < 100; i++)
         {
            if (strcmp(name[i],a)==0)
            {
               printf("\nStudent id: %s\nName: %s %s\nBranch: %s\n\n",id[i],name[i],surname[i],branch[i]);
           } 
            
         }
         search_the_student();
      }
      search_the_student();   
   }
   else if (arch==3)
   {
      char m[100];
      printf("\n*************************************");
      printf("\nPlease enter branch name(small letters): ");
      scanf("%s",m);
      for (int i = 0; i < 100; i++)
      {
         if (strcmp(branch[i],m)==0)
         {
               printf("\nStudent id: %s\nName: %s %s\nBranch: %s\n\n",id[i],name[i],surname[i],branch[i]);
           } 
      }
      search_the_student();      
   }
   else if (arch==4)
   {
      float ghj;
      printf("\n*************************************");
      printf("\nEnter thresold percentage: ");
      scanf("%f",&ghj);
      for (int i = 0; i < 100; i++)
      {
         if (percentage[i]>ghj)
         {
               printf("\nStudent id: %s\nName: %s %s\nMarks in c: %f\nMarks in dsa: %f\nMarks in DBMS: %f\nTOTAL: %f\nPercentage: %f\n\n",id[i],name[i],surname[i],c[i],dsa[i],dbms[i],total[i],percentage[i]);
           } 
      }
      search_the_student();        
   }
   else if (arch==1) 
   {
      char m[100];
      printf("\n*************************************");
      printf("\nPlease enter student id: ");
      scanf("%s",m);
      for (int i = 0; i < 100; i++)
      {
         if (strcmp(id[i],m)==0)
         {
               printf("\nStudent id: %s\nName: %s %s\nBranch: %s\n\n",id[i],name[i],surname[i],branch[i]);
           } 
      }
      search_the_student();            
   }
   else if (arch==5)
   {
      check();
      search_the_student();
   }
   else if (arch==6)
   {
       char poi[100];
       printf("\n*************************************");
       printf("\nEnter the name of branch: ");
       scanf("%s",poi);
       float gf;
       printf("Enter thresold percantage: ");
       scanf("%f",&gf);
       for (int i = 0; i < 100; i++)
       {
           if (strcmp(poi,branch[i])==0 && gf<percentage[i])   
           {
               printf("\nStudent id: %s\nName: %s %s\nMarks in c: %f\nMarks in dsa: %f\nMarks in DBMS: %f\nTOTAL: %f\nPercentage: %f\n\n",id[i],name[i],surname[i],c[i],dsa[i],dbms[i],total[i],percentage[i]);
           } 
           
       }
       
   }
   else
   {
      search_the_student();
   }
   

}

void start()
{
   printf("\n*************************************\n");
   update_in_code();
   printf("\n1. Create new student profile\n");
   printf("2. Access existing student profile\n");
   printf("3. Print all the data in a new file\n");
   printf("0. EXIT\n");
   printf("\n*************************************\n");
   printf("ENTER YOUR CHOICE: ");
   int a ;
   scanf("%d",&a);
   printf("*************************************\n");
   if (a==0)
   {
      update_in_file();
      return;
   }
   else if (a==1)
   {
      new(y);
   }
   else if(a==2)
   {
      existing_student();
   }
   else if (a==3)
   {
      createfile();
   }
   else
   {
      start();
   }
   
      
}

void allmarks()
{
    for (int i = 0; i < 100; i++)
    {
        if (naman[i]==1)
        {

            float z,x,m;
            printf("\n\nStudent id: %s\n",id[i]);
            while (1)
            {
            printf("Enter marks of C: ");
            scanf("%f",&z);
            if (z>=0 && z<=100)
            {
                break;
            }
            printf("\nMarks cannot exceed 100\n\n");               
            }
            while (1)
            {
            printf("Enter marks of DSA: ");
            scanf("%f",&x);
            if (x>=0 && x<=100)
            {
                break;
            }
            printf("\nMarks cannot exceed 100\n\n");                      
            }
            while (1)
            {
            printf("Enter marks of DBMS: ");
            scanf("%f",&m);
            if (m>=0 && m<=100)
            {
                break;
            }
            printf("\nMarks cannot exceed 100\n\n");                      
            }
            c[i]=z;
            dbms[i]=m;
            dsa[i]=x;
            total[i]=z+m+x;
            percentage[i]=(total[i]/3.0);
            update_in_file();            
        }
        
    }
    modify();
}

void modifyname()
{
   printf("\n*************************************");
    printf("\nPlease enter student id: ");
    char kl[100];
    scanf("%s",kl);
    char lk[100];
    printf("\nPlease enter new first name(without spaces): ");
    scanf("%s",lk);
    char boi[100];
    printf("Please enter surname: ");
    scanf("%s",boi);

    for (int i = 0; i < 100; i++)
    {
        if (strcmp(id[i],kl)==0)
        {
            strcpy(name[i],lk);
            strcpy(surname[i],boi);
            printf("\n Name updated succesfully\n\n");
            update_in_file();
            modify();
        }
        
    }
    printf("\nerror student id doeesnot exist\n");
    modify();
}
void modifybranch()
{
   printf("\n*************************************");
    printf("\nPlease enter student id: ");
    char kl[100];
    scanf("%s",kl);
    char lk[100];
    printf("Please enter new branch: ");
    scanf("%s",lk);
    for (int i = 0; i < 100; i++)
    {
        if (strcmp(id[i],kl)==0)
        {
            strcpy(branch[i],lk);
            printf("\n Branch updated succesfully\n\n");
            update_in_file();
            modify();
        }
        
    }
    printf("error student id doeesnot exist\n");
    modify();
}
void modifymarksof()
{
   printf("\n*************************************");
    printf("\nPlease enter student id: ");
    char kl[100];
    scanf("%s",kl);
    for (int i = 0; i < 100; i++)
    {
        if (strcmp(id[i],kl)==0)
        {
            float z,x,m;
            printf("student id: %s\n",id[i]);
            while (1)
            {
            printf("Enter marks of C: ");
            scanf("%f",&z);
            if (z>=0 && z<=100)
            {
                break;
            }
            printf("marks cannot exceed 100\n");               
            }
            while (1)
            {
            printf("Enter marks of DSA: ");
            scanf("%f",&x);
            if (x>=0 && x<=100)
            {
                break;
            }
            printf("marks cannot exceed 100\n");               
            }
            while (1)
            {
            printf("Enter marks of DBMS: ");
            scanf("%f",&m);
            if (m>=0 && m<=100)
            {
                break;
            }
            printf("marks cannot exceed 100\n");               
            }
            c[i]=z;
            dbms[i]=m;
            dsa[i]=x;
            total[i]=z+m+x;
            percentage[i]=(total[i]/3.0);
            update_in_file();
            printf("\nMarks updated successfully\n\n");
            modify();       
        }
        
    }
    printf("error student id doeesnot exist\n");
    modify();
}
void delete()
{
   printf("\n*************************************");
    printf("\nPlease enter student id: ");
    char kl[100];
    scanf("%s",kl);
    for (int i = 0; i < 100; i++)
    {
        if (strcmp(id[i],kl)==0)
        {
           for (int jcb = i; jcb < 100; jcb++)
           {
            strcpy(id[jcb],id[jcb+1]);
            strcpy(name[jcb],name[jcb+1]);
            strcpy(branch[jcb],branch[jcb+1]);
            strcpy(surname[jcb],surname[jcb+1]);
            dsa[jcb]=dsa[jcb+1];
            dbms[jcb]=dbms[jcb+1];
            c[jcb]=c[jcb+1];
            total[jcb]=total[jcb+1];
            percentage[jcb]=percentage[jcb+1];
            naman[jcb]=naman[jcb+1];
           }
           y=y-1;
            update_in_file();
            printf("\n------Student id deleted successfully------\n");
            modify();
        }
        
    }
    printf("error student id doeesnot exist\n");
    modify();
}

void modify()
{
   printf("\n*************************************");
    printf("\n1. Insert marks of all registered students\n");    
    printf("2. Modify NAME using student id\n");
    printf("3. Modify BRANCH using student id\n");
    printf("4. Modify marks using student id\n");
    printf("5. Delete a student profile using student id\n");
    printf("6. Back to menu\n");
    printf("\nPlease enter your choice: ");
    int b;
    scanf("%d",&b);
    if (b==0)
    {
        return;
    }
    else if (b==6)
    {
        existing_student();
    }
    else if (b==1)
    {
       allmarks();
    }
    else if (b==2)
    {
       modifyname();
    }
    else if (b==3)
    {
       modifybranch();
    }
    else if (b==4)
    {
       modifymarksof();
    }
    else if (b==5)
    {
       delete();
    }  
    else
    {
       modify();
    }
    
}

void createfile()
{
   FILE *fp;
   char file[100];
   printf("\nPlease enter the name for the file: ");
   scanf("%s",file);
   fp=fopen(file,"w");
   int x = 1;
   for (int i = 0; i < 100; i++)
   {
      if (naman[i]==1)
      {
         fprintf(fp,"Student No. %d\n",x);
         fprintf(fp,"Student ID: %s\n",id[i]);
         fprintf(fp,"Student Name: %s %s\n",name[i],surname[i]);
         fprintf(fp,"Student Branch: %s\n",branch[i]);
         fprintf(fp,"Marks in C: %f\n",c[i]);
         fprintf(fp,"Marks in DSA: %f\n",dsa[i]);
         fprintf(fp,"Marks in DBMS: %f\n",dbms[i]);
         fprintf(fp,"Total Marks %f\n",total[i]);
         fprintf(fp,"Percentage: %f%s\n\n\n",percentage[i],"%");
         x++;

      }
      
   }
   printf("\n----file created successfully----\n");
   fclose(fp);
   start();
}

void main()
{
   head();
   start();
   return;
}
