///..........................DIU Special Bus Services....................................................
///..........................Header file.................................................................
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
///..........................End of Header file..........................................................
int rotID=0;
struct AdminRootAdd{
    int rootID;
    char rootname[30];
    float dist;
    int rent;
    struct AdminRootAdd* link;
};
struct AdminRootAdd* fst = NULL;
struct AdminRootAdd* lst = NULL;
///..........................Global variable for root....................................................
int rootSelct;
float distance;
int rent;
///..........................End Global variable for root................................................
///..........................Structure for Travel History................................................
struct rootadd{
    char ID[25];
    char rootName[30];
    float distance;
    int rent;
    int day;
    int month;
    int year;
    struct rootadd* link;
};
struct rootadd* NEW = NULL;
///..........................End Structure for Travel History............................................
///..........................Structure for create Student Account........................................
struct createAccount{
    char ID[25];
    char NAME[25];
    struct createAccount* link;
};
struct createAccount* head = NULL;
///...........................End Structure for create Student Account...................................
///...........................Some Important Users Defined Functions.....................................
void submain();
void home();
void registernewStudent();
void ShowregistedStudent();
void StudentTravelHistory();
void rootSelect();
void enteryourchoice();
int deletstudenthistory();
void firstInsertSomeStudent(char iD[],char namE[]);
void rootcreateAdim();
void firstAssignRoot();
void firstAssignRoot2();
///............................End of Some Important Users Defined Functions.............................
///..........................Global variable for delete history..........................................
char idd[20];
///..........................End Global variable for delete history......................................
///.............................Global variable For Admin................................................
    char adminname[25];
    char adminIdCreate[25];
    char adminpasswordCreate[25];
    char adminId[25];
    char adminpassword[25];
    void adminsignIn();
    void adminsignUp();
///..............................End of Global variable For Admin........................................
///..........................Main Function...............................................................
void main()
{
    system ("COLOR 1f");
    ///......Some Student Accounts...................................
    firstAssignRoot();
    firstAssignRoot2();
    char iD1[20]="171-15-1111";
    char namE1[20]="Amit";
    firstInsertSomeStudent(iD1,namE1);
    char iD2[20]="171-15-0000";
    char namE2[20]="Snigdha";
    firstInsertSomeStudent(iD2,namE2);
    char iD3[20]="163-15-8512";
    char namE3[20]="Partha";
    firstInsertSomeStudent(iD3,namE3);
    char iD4[20]="171-15-8998";
    char namE4[20]="Joy";
    firstInsertSomeStudent(iD4,namE4);
    char iD5[20]="171-15-8875";
    char namE5[20]="Sakil";
    firstInsertSomeStudent(iD5,namE5);
    char iD6[20]="171-15-8636";
    char namE6[20]="Mijan";
    firstInsertSomeStudent(iD6,namE6);
    char iD7[20]="171-15-8640";
    char namE7[20]="Adol";
    firstInsertSomeStudent(iD7,namE7);
    ///......End Some Student Accounts...............................
    submain();
}
///......................End of Main Function............................................................
///......................Sub-Main Function...............................................................
void submain()
{
    printf("****************************************************************************************************************\n************************************** Welcome to DIU special Bus Services *************************************\n****************************************************************************************************************\n");
    while(1){
    printf("\t\t\t\t\t................................\n");
    printf("\t\t\t\t\t....Admin Sign Up or Sign In....\n\t\t\t\t\t................................\n\n \t\t\t\t\t\t1. Sign In\n \t\t\t\t\t\t2. Sign Up\n \t\t\t\t\t\t0. Exit\n");
    int cho;
    printf("\n\t\t\t\t\tChoice Option : ");
    scanf("%d",&cho);
    if(cho==1) adminsignIn();
    if(cho==2) adminsignUp();
    if(cho==0){
        printf("\n\t\t\t\t\t*****Thank You*****\n");
        break;
    }
    }
}
///......................End of Sub-Main Function........................................................
///......................Admin Sign In Function..........................................................
void adminsignIn()
{
    printf("\n\t\t\t\t\tEnter Admin ID :");
    scanf("%s",&adminId);
    printf("\n\t\t\t\t\tEnter Password :");
    scanf("%s",&adminpassword);
    if(strcmp(adminId,adminIdCreate)==0 && strcmp(adminpasswordCreate,adminpassword)==0)
    {
        printf("\t\t\t\t\tLogin Success!\n");
        home();
    }else{
        printf("\n\t\t\t\t\tAdmin Id or Password is incorrect!\n");
    }
}
///.......................End of Admin Sign In Function..................................................
///.......................Admin Sign Up Function.........................................................
void adminsignUp()
{
    printf("\n\t\t\t\t\tEnter Bus Number : ");
    scanf("%s",&adminname);
    printf("\n\t\t\t\t\tEnter Admin ID : ");
    scanf("%s",&adminIdCreate);
    printf("\n\t\t\t\t\tEnter Admin New Password : ");
    scanf("%s",&adminpasswordCreate);
    printf("\n\t\t\t\t\tWelcome %s\n",adminname);
    home();
}
///.......................End of Admin Sign Up Function..................................................
///.......................Home option Function...........................................................
void home()
{
    printf(" .....................................................................................................................\n");
    printf(" 1.Home 2.Register New Student 3.Registered Student 4.Travel 5.Travel History 6. Delete History 7. Root Add 0.Sign Out\n");
    printf(" .....................................................................................................................\n");
    printf(" ..Home..\n");
    printf(" ........\n");
    printf("\n Bus Number : %s\n\n",adminname);
    printf("\tThe DIU special bus services.\n This Software store all student travel history and count every student travel cost.\n Only Admin control this software. \n\n\t..........\n");
    enteryourchoice();
}
///.......................End of Home option Function....................................................
///.......................Registration of new student Function...........................................
void registernewStudent()
{
    printf(" .....................................................................................................................\n");
    printf(" 1.Home 2.Register New Student 3.Registered Student 4.Travel 5.Travel History 6. Delete History 7. Root Add 0.Sign Out\n");
    printf(" .....................................................................................................................\n");
    printf(" ..Register New Student..\n");
    printf(" ........................\n");
    printf("\n Bus Number : %s\n\n",adminname);
    struct createAccount* newStudent = (struct createAccount*)malloc(sizeof(struct createAccount));
    printf("Enter Student University ID : ");
    scanf("%s",&newStudent->ID);
    printf("Enter Student Name : ");
    scanf("%s",&newStudent->NAME);
    newStudent->link = NULL;
    if(head==NULL)
    {
        head = newStudent;
    }else{
        newStudent->link = head;
        head = newStudent;
    }
    enteryourchoice();
}
///.......................End Registration of new student Function.......................................
void firstInsertSomeStudent(char iD[],char namE[])
{
    struct createAccount* firstAddStudent = (struct createAccount*)malloc(sizeof(struct createAccount));
    strcpy(firstAddStudent->ID,iD);
    strcpy(firstAddStudent->NAME,namE);
    firstAddStudent->link = NULL;
    if(head==NULL)
    {
        head = firstAddStudent;
    }else{
        firstAddStudent->link = head;
        head = firstAddStudent;
    }
}
///.......................Show already registered student Function.......................................
void ShowregistedStudent()
{
    printf(" .....................................................................................................................\n");
    printf(" 1.Home 2.Register New Student 3.Registered Student 4.Travel 5.Travel History 6. Delete History 7. Root Add 0.Sign Out\n");
    printf(" .....................................................................................................................\n");
    printf(" ..Registered Student..\n");
    printf(" ......................\n");
    printf("\n Bus Number : %s\n\n",adminname);
    struct createAccount* dis = head;
    int i=1;
    printf(" All Registered student :\n");
    printf(" ID\tStudent ID\tStudent Name\n");
    while(dis!=NULL)
    {
        printf(" %d\t%s\t%s\n",i,dis->ID,dis->NAME);
        i++;
        dis = dis->link;

    }
    enteryourchoice();
}
///.......................End of Show already registered student Function................................
///.......................Student travel history Function................................................
void StudentTravelHistory()
{
    printf(" .....................................................................................................................\n");
    printf(" 1.Home 2.Register New Student 3.Registered Student 4.Travel 5.Travel History 6. Delete History 7. Root Add 0.Sign Out\n");
    printf(" .....................................................................................................................\n");
    printf(" ..Travel History..\n");
    printf(" ..................\n");
    printf("\n Enter the ID, which student's travel history you want to sow : ");
    int TotalRent=0;
    char id[20];
    scanf("%s",&id);
    struct rootadd* sowHis = NEW;
    printf("\n History of ID is: %s\n",id);
    struct createAccount* namesw = head;
    while(namesw!=NULL){
        if(strcmp(namesw->ID,id)==0){
            printf(" Name \t\t: %s\n",namesw->NAME);
            break;
        }
        namesw = namesw->link;
    }
    printf("\n DD-MM-YYYY \t Place Name \t Distance \t Rent\n");
    while(sowHis!=NULL)
    {
        if(strcmp(id,sowHis->ID)==0)
        {
            printf("\n %d-%d-%d \t %s \t %.1f km. \t %d Taka",sowHis->day,sowHis->month,sowHis->year,sowHis->rootName,sowHis->distance,sowHis->rent);
            TotalRent+=sowHis->rent;
        }
        sowHis = sowHis->link;
    }
    if(TotalRent==0){
        printf("\n Oops!! No travel history of ID : %s\n\n",id);
    }else
    printf("\nTotal rent is : %d Taka.\n\n",TotalRent);
    enteryourchoice();

}
///.......................End of Student travel history Function.........................................
///.......................Add all student travel Function(one by one add)................................
void addRoot(int rotidd)
{
    SYSTEMTIME stime;
    GetSystemTime(&stime);
    struct createAccount* che = head;
    struct rootadd* add = (struct rootadd*)malloc(sizeof(struct rootadd));
    struct AdminRootAdd* tm = fst;
    while(tm!=NULL){
        if(tm->rootID==rotidd){
            break;
        }
        tm = tm->link;
    }
    printf("Enter student University ID : ");
    scanf("%s",&add->ID);
    while(1){
            if(che==NULL){
            printf("\nThere is no account of ID : %s. Please Create New account.\n",add->ID);
            break;}
    if(strcmp(add->ID,che->ID)==0){
    strcpy(add->rootName,tm->rootname);
    add->distance = tm->dist;
    add->rent = tm->rent;
    add->day = stime.wDay;
    add->month = stime.wMonth;
    add->year = stime.wYear;
    add->link = NULL;

    if(NEW==NULL){
        NEW = add;
    }else{
        add->link = NEW;
        NEW = add;
    }
    break;
    }
        che = che->link;
    }
}
///.......................End of Add all student travel Function(one by one add).........................
///.......................Choose all potion Function.....................................................
void enteryourchoice()
{
    printf(" Enter New choice : ");
    int co,deletcount,enterchoiceCount=1;
    scanf("%d",&co);
    switch(co)
    {
        case 1:
        home();
        break;
        case 2:
        registernewStudent();
        break;
        case 3:
        ShowregistedStudent();
        break;
        case 4:
        rootSelect();
        break;
        case 5:
        StudentTravelHistory();
        break;
        case 6:
            printf(" .....................................................................................................................\n");
            printf(" 1.Home 2.Register New Student 3.Registered Student 4.Travel 5.Travel History 6. Delete History 7. Root Add 0.Sign Out\n");
            printf(" .....................................................................................................................\n");
            printf(" ..Delete History..\n");
            printf(" ..................\n");
            printf("Enter student ID, whose history you want to delete : ");
            scanf("%s",&idd);
            while(1){
                deletcount=deletstudenthistory();
                if(deletcount==1) {
                    printf("All history deleted.\n");
                    break;
                }
            }
            enterchoiceCount++;
        break;
        case 7:
            rootcreateAdim();
            break;
        case 0:
        submain();
        break;
    }
    if(enterchoiceCount==2) enteryourchoice();
}
///.......................End of Choose all potion Function..............................................
///.......................Delete Student travel history Function(after payment)..........................
int deletstudenthistory()
{

    int cou=1,xeicuteOrNot=0;
    struct rootadd* del = NEW;
    struct rootadd* pre = NEW;
    while(del!=NULL)
    {
        if(strcmp(idd,del->ID)==0)
        {
            if(cou==1){
                NEW = NEW->link;
                del->link = NULL;
                free(del);
                xeicuteOrNot++;
                break;
            }else{
                pre->link = del->link;
                del->link = NULL;
                free(del);
                xeicuteOrNot++;
                break;
            }
        }
        cou++;
        pre = del;
        del = del->link;
    }
        if(xeicuteOrNot==0) return 1;
        else return 2;
    }
///.......................End of Delete Student travel history Function(after payment)...................
///.......................Select where student want to travel Function...................................
void rootSelect()
{
    struct AdminRootAdd* tp = fst;
    printf(" .....................................................................................................................\n");
    printf(" 1.Home 2.Register New Student 3.Registered Student 4.Travel 5.Travel History 6. Delete History 7. Root Add 0.Sign Out\n");
    printf(" .....................................................................................................................\n");
    printf(" ..Travel..\n");
    printf(" ..........\n");
    printf(".........\n");
    printf("Our root: \n");
    printf("...........................................................................\n");
        while(tp!=NULL){
            printf(" %d. %s",tp->rootID,tp->rootname);
            tp =tp->link;
        }
    printf("\n...........................................................................\n");
    printf("\nSelect where to or from you start Travel : ");
    scanf("%d",&rootSelct);
    addRoot(rootSelct);
    enteryourchoice();
}
void rootcreateAdim()
{
    rotID++;
    struct AdminRootAdd* ad = (struct AdminRootAdd*)malloc(sizeof(struct AdminRootAdd));
    printf("\nEnter root name : ");
    scanf("%s",&ad->rootname);
    printf("\nEnter root distance : ");
    scanf("%f",&ad->dist);
    printf("\nEnter root rent : ");
    scanf("%d",&ad->rent);
    ad->rootID = rotID;
    ad->link = NULL;
    if(fst==NULL){
        fst = ad;
        lst = ad;
    }else{
        lst->link = ad;
        lst = ad;
    }
    enteryourchoice();
}
void firstAssignRoot()
{
    rotID++;
    struct AdminRootAdd* dad = (struct AdminRootAdd*)malloc(sizeof(struct AdminRootAdd));
    strcpy(dad->rootname,"Shamoli");
    dad->dist=3.3;
    dad->rent=10;
    dad->rootID = rotID;
    dad->link = NULL;
    if(fst==NULL){
        fst = dad;
        lst = dad;
    }else{
        lst->link = dad;
        lst = dad;
    }

}
void firstAssignRoot2()
{
    rotID++;
    struct AdminRootAdd* dad = (struct AdminRootAdd*)malloc(sizeof(struct AdminRootAdd));
    strcpy(dad->rootname,"Kallayanpur");
    dad->dist=3.5;
    dad->rent=15;
    dad->rootID = rotID;
    dad->link = NULL;
    if(fst==NULL){
        fst = dad;
        lst = dad;
    }else{
        lst->link = dad;
        lst = dad;
    }

}