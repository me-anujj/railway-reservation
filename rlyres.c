#include<stdio.h>
#include"conio2.h"
#include"rlyres.h"
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

int enterchoice()
{
    int choice,i;
    textcolor(YELLOW);
    gotoxy(48,1);
    printf("RAILWAY RESERVATION SYSTEM\n");
    for(i=0;i<=119;i++)
        printf("-");

    printf("\nSelect an option.\n");
    printf("1- View Trains\n2- Book Tickets\n3- View ticket\n4- Search Ticket No\n5- View All Bookings");
    printf("\n6- View Trains Booking\n7- Cancel Ticket \n8- Cancel Train \n9- Quit\n\n");

    printf("Enter choice : ");
    scanf("%d",&choice);
    fflush(stdin);

   return choice;
}

void add_trains()
{
    FILE *fp;
    fp = fopen("D:\\Programs\\RailwayReservationSystem\\myproject\\alltrains.dat","rb");

    if(fp == NULL)
    {
        Train alltrains[4]={
            {"123","BPL","GWA",2100,1500},
            {"546","BPL","DEL",3500,2240},
            {"345","HBJ","AGR",1560,1135},
            {"896","HBJ","MUM",4500,3360},
                           };

    fp = fopen("D:\\Programs\\RailwayReservationSystem\\myproject\\alltrains.dat","wb");
    fwrite(alltrains,4*sizeof(Train),1,fp);
    //printf(" File saved successfully ! ");
    fclose(fp);
    }

    else
    {
        //printf("File already present ! ");
        fclose(fp);
    }
    return ;
}

void view_trains()
{
    int i;
  printf(" TRAIN N0");
  gotoxy(30,1);
  printf("FROM");
  gotoxy(45,1);
  printf("TO");
  gotoxy(65,1);
  printf("FIRST AC FAIR");
  gotoxy(90,1);
  printf("SECOND AC FAIR\n");

  for(i=0;i<=119;i++)
        printf("-");

        FILE *fp;
        fp = fopen("D:\\Programs\\RailwayReservationSystem\\myproject\\alltrains.dat","rb");
            if(fp == NULL)
            {
                textcolor(LIGHTRED);
                printf("ERROR!");
                return 1;
            }

            Train t;
            for(i=0;i<4;i++)
           {
            fread(&t,sizeof(t),1,fp);
                gotoxy(2,i+3);
            printf("  %s ",t.train_no);
                gotoxy(28,i+3);
            printf("  %s ",t.from);
                gotoxy(45,i+3);
            printf("%s",t.to);
                gotoxy(67,i+3);
            printf("%d",t.fac_fare);
                gotoxy(92,i+3);
            printf("%d\n",t.sac_fare);
           }

    fclose(fp);
    textcolor(WHITE);
    printf("\n\n\n  Press any key to go back to main screen. ");
    getch();

}

int check_train_no(char* trainno)
{
    FILE *fp = fopen("D:\\Programs\\RailwayReservationSystem\\myproject\\alltrains.dat","rb");

    Train tr;

    while(fread(&tr,sizeof(tr),1,fp)==1)
    {
        if(strcmp( tr.train_no,trainno)==0)
        {
            fclose(fp);
            return 1;
        }

    }

  fclose(fp);
   return 0;

}

Passenger *get_passenger_details()
{
    clrscr();

    gotoxy(90,1);
    textcolor(LIGHTGREEN);
    printf("Press 0 to exit");

    gotoxy(1,1);
    textcolor(YELLOW);
    static Passenger psn;
    printf("Enter passengers name: ");
    fflush(stdin);
    fgets(psn.p_name,20,stdin);
    char *pos;
    pos = strchr(psn.p_name ,'\n');
    *pos = '\0';
    if(strcmp(psn.p_name,"0")==0)
    {
       textcolor(LIGHTRED);
       gotoxy(1 , 25);
       printf("Reservation Canceled !!");
       getch();
       textcolor(YELLOW);
       return NULL;
    }

    int valid;
    printf("Enter gender(M/F):");
    do{
        valid = 1;
        fflush(stdin);
        scanf("%c",&psn.gender);
        if(psn.gender == '0')
        {
        textcolor(LIGHTRED);
        gotoxy(1 , 25);
        printf("\t\t\t\t\t\t\t\t");
        gotoxy(1,25);
        printf("Reservation Canceled !!");
        getch();
        textcolor(YELLOW);
        return NULL;
        }
        if(psn.gender != 'M' && psn.gender != 'F')
        {
            textcolor(LIGHTRED);
            gotoxy(1,25);
            printf("Error! Gender should be M or F(in uppercase)");
            valid=0;
            getch();
            textcolor(YELLOW);
            gotoxy(19,2);
            printf("\t\t\t\t\t");
            gotoxy(19,2);
        }
    }while(valid == 0);
    gotoxy(1,25);
    printf("\t\t\t\t\t\t\t");

    gotoxy(1,3);
    printf("Enter train number:");
    do{
        valid = 1 ;
        fflush(stdin);
        fgets(psn.train_no,20,stdin);
        char *pos;
        pos = strchr(psn.train_no ,'\n');
        *pos = '\0';
        if(strcmp(psn.train_no ,"0") == 0)
        {
        textcolor(LIGHTRED);
        gotoxy(1 , 25);
        printf("\t\t\t\t\t\t\t\t");
        gotoxy(1,25);
        printf("Reservation Canceled !!");
        getch();
        textcolor(YELLOW);
        return NULL;
        }

        if(check_train_no(psn.train_no) == 0)
        {
            gotoxy(1,25);
            valid = 0 ;
            textcolor(LIGHTRED);
            printf("Error! Invalid Train No.");
            gotoxy(20,3);
            printf("\t\t\t\t\t");
            gotoxy(20,3);
            textcolor(YELLOW);
        }
    }while(valid == 0);
    gotoxy(1,25);
    printf("\t\t\t\t\t");

    gotoxy(1,4);
    printf("Enter traveling class(First AC-F,Second AC-S):");
    do{
        valid = 1 ;
        fflush(stdin);
        scanf("%c",&psn.p_class);
         if(psn.p_class == '0')
        {
        textcolor(LIGHTRED);
        gotoxy(1 , 25);
        printf("\t\t\t\t\t\t\t\t");
        gotoxy(1,25);
        printf("Reservation Canceled !!");
        getch();
        textcolor(YELLOW);
        return NULL;
        }
        if(psn.p_class != 'F' && psn.p_class != 'S'){
            textcolor(LIGHTRED);
            gotoxy(1,25);
            printf("Error! Traveling class should be F or S(in uppercase)");
            valid=0;
            getch();
            textcolor(YELLOW);
            gotoxy(47,4);
            printf("\t\t\t\t\t");
            gotoxy(47,4);
        }
    }while(valid == 0);
    gotoxy(1,25);
    printf("\t\t\t\t\t\t\t\t\t");

    gotoxy(1,5);
    printf("Enter Address:");
    fflush(stdin);
    fgets(psn.address,50,stdin);

    pos = strchr(psn.address,'\n');
    *pos = '\0';

    if(strcmp(psn.address,"0") == 0){
        textcolor(LIGHTRED);
        gotoxy(1,25);
        printf("Reservation Canceled!!");
        getch();
        textcolor(YELLOW);
        return NULL;
            }

     gotoxy(1,6);
     printf("Enter age:");
     do{
        valid = 1;
        scanf("%d",&psn.age);
        if(psn.age == 0){
            textcolor(LIGHTRED);
            gotoxy(1 , 25);
            printf("Reservation Canceled !!");
            getch();
            textcolor(YELLOW);
            return NULL;
        }
        if(psn.age <= 0){
            valid = 0;
            gotoxy(1,25);
            textcolor(LIGHTRED);
            printf("Error! Age should be Positive.");
            getch();
            gotoxy(11,6);
            printf("\t\t\t\t\t");
            gotoxy(11,6);
            textcolor(YELLOW);
        }
     }while(valid == 0);
        gotoxy(1,25);
        printf("\t\t\t\t\t");

        gotoxy(1,7);
        printf("Enter mobile number:");
        do{
            fflush(stdin);
            fgets(psn.mob_no,12,stdin);
            pos = strchr(psn.mob_no,'\n');
            if(pos!=NULL)
                *pos = '\0' ;
            if(strcmp(psn.mob_no,"0") == 0){
                gotoxy(1,25);
                printf("\t\t\t\t\t\t\t");
                textcolor(LIGHTRED);
                printf("Reservation canceled!1");
                getch();
                textcolor(YELLOW);
                return NULL;
            }
            valid = check_mob_no(psn.mob_no);
            if(valid == 0){
                gotoxy(1,25);
                textcolor(LIGHTRED);
                printf("Error! Invalid mobile number.");
                getch();
                gotoxy(21,7);
                printf("\t\t\t\t\t\t\t");
                gotoxy(21,7);
                textcolor(YELLOW);
            }
        }while(valid == 0);

  return &psn;
}

int check_mob_no(char *p_mob)
{

    if(strlen(p_mob)!=10)
        return 0;

    while(*p_mob!='\0'){
        if(isdigit(*p_mob)==0)
            return 0;

        p_mob++ ;
    }
  return 1;
}

int get_booked_ticket_count(char *train_no,char tc)
{
    FILE *fp;
    fp = fopen("D:\\Programs\\RailwayReservationSystem\\myproject\\allbookings.dat","rb");
    if(fp == NULL){
        return 0;
    }
    Passenger pr;
    int count = 0 ;
    while(fread(&pr,sizeof(pr),1,fp)==1){
            if(strcmp(pr.train_no,train_no) == 0 && pr.p_class == tc)
                ++count ;
    }
    fclose(fp);
    return count;
}

int last_ticket_no()
{
    FILE *fp ;
    fp = fopen("D:\\Programs\\RailwayReservationSystem\\myproject\\allbookings.dat","rb");

    if(fp == NULL)
        return 0;

    Passenger pr;
    fseek(fp,-1*sizeof(pr),SEEK_END);
    fread(&pr,sizeof(pr),1,fp);
    fclose(fp);

  return pr.ticketno;
}

int book_ticket(Passenger p)
{
    int last_tckt;
    if(get_booked_ticket_count(p.train_no , p.p_class) == 3)
    {
        textcolor(LIGHTRED);
        printf("\n\n\n\nAll seats full in train no %s in %c class",p.train_no,p.p_class);
        return -1 ;
    }
    else{
       last_tckt = last_ticket_no();
       p.ticketno = ++last_tckt ;

       FILE *fp;
       fp = fopen("D:\\Programs\\RailwayReservationSystem\\myproject\\allbookings.dat","ab+");
       fwrite(&p,sizeof(p),1,fp);
       fclose(fp);

      return p.ticketno;
    }
}

int accept_ticket_no()
{
    clrscr();
    gotoxy(90,1);
    textcolor(LIGHTGREEN);
    printf("Press 0 to exit");
    textcolor(YELLOW);
    gotoxy(1,1);
    printf("Enter Ticket number:");
    int valid;
    int ticket_no ;
    do{
        valid = 1 ;
        fflush(stdin);
        scanf("%d",&ticket_no);
        if(ticket_no == 0){
            gotoxy(1,25);
            printf("\t\t\t\t\t\t\t");
            textcolor(LIGHTRED);
            gotoxy(3,25);
            printf("Canceling Input...");
            getch();
            textcolor(YELLOW);
          return 0;
        }
        if(ticket_no < 0){
            valid = 0;
            gotoxy(1,25);
            textcolor(LIGHTRED);
            printf("Error ticket number should be positive.");
            getch();
            gotoxy(21,1);
            printf("\t\t\t\t\t\t\t\t\t\t");
            gotoxy(21,1);
            textcolor(YELLOW);
        }
    }while(valid == 0);
  return ticket_no ;
}

void view_ticket(int ticket_no)
{
    FILE *fp ;
    fp = fopen("D:\\Programs\\RailwayReservationSystem\\myproject\\allbookings.dat","rb");
    if(fp == NULL){
            textcolor(LIGHTRED);
        printf("No bookings done yet");
      return ;
    }
    Passenger pr;
    int found = 0;
    while(fread(&pr,sizeof(pr),1,fp) == 1){
        if(pr.ticketno == ticket_no){
printf("\nNAME: %s\nGENDER: %c\nTRAIN NO: %s\nCLASS: %c\nADDRRESS: %s\nAGE: %d\nMOBILE NO: %s\nTICKET NO: %d\n",pr.p_name,pr.gender,pr.train_no,pr.p_class,pr.address,pr.age,pr.mob_no,pr.ticketno);
            printf("\n\n");
            found = 1 ;
          break ;
        }
    }
    if(found == 0)
    {
        textcolor(LIGHTRED);
        printf("\n No details of ticket no %d found!",ticket_no);
    }
 fclose(fp);
}

char* accept_mob_no()
{
    clrscr();
    gotoxy(90,1);
    textcolor(LIGHTGREEN);
    printf("Press 0 to exit");
    textcolor(YELLOW);
    gotoxy(1,1);
        int valid = 0 ;
        static char mob_no[11];
        char *pos ;
    printf("Enter mobile number:");
    do{
        fflush(stdin);
        fgets(mob_no,11,stdin);
        pos = strchr(mob_no , '\n');
        if(pos != NULL)
            *pos = '\0' ;
        if(strcmp(mob_no , "0") == 0){
            gotoxy(1,25);
            printf("\t\t\t\t\t\t\t");
            textcolor(LIGHTRED);
            gotoxy(3,25);
            printf("Canceling Input...");
            getch();
            textcolor(YELLOW);
          return NULL;
        }
        valid = check_mob_no(mob_no);
        if(valid == 0){
            gotoxy(1,25);
            textcolor(LIGHTRED);
            printf("Error! Invalid mobile no");
            getch();
            gotoxy(21,1);
            printf("\t\t\t\t\t\t\t");
            gotoxy(21,1);
            textcolor(YELLOW);
        }
    }while(valid == 0);
    clrscr();
  return mob_no ;
}

int* get_ticket_no(char *p_mob_no)
{
    FILE *fp ;
    int count = 0 ;
    fp = fopen("D:\\Programs\\RailwayReservationSystem\\myproject\\allbookings.dat","rb");
    if(fp == NULL)
        return NULL ;
    Passenger pr ;
    while(fread(&pr,sizeof(pr),1,fp) == 1){
        if(strcmp(pr.mob_no , p_mob_no) == 0){
            ++count ;
        }
    }
    if(count == 0){
        fclose(fp);
        return NULL ;
    }
    rewind(fp);
    int *p = (int*)malloc((count+1)*sizeof(int));
    int i=0;
    while(fread(&pr,sizeof(pr),1,fp) == 1){
        if(strcmp(pr.mob_no , p_mob_no) == 0){
            *(p+i) = pr.ticketno ;
            i++;
        }
    }
    *(p+i) = -1 ;
    fclose(fp);
  return p;
}

void view_all_tickets(char *pmob_no, int *pticket_no)
{
    if(pticket_no == NULL){
        printf("No tickets booked against the mobile number %s",pmob_no);
        textcolor(WHITE);
        printf("\n\n");
        printf("Press any key to go back to main menu.");
        getch();
        textcolor(YELLOW);
     return ;
    }
    printf("Following tickets are booked for mobile number %s\n",pmob_no);
    int i=0;
    printf("Ticket no :\n");
    for(i=0 ; i< 12 ; i++)
        printf("=");
    printf("\n");
    for(i=0 ; *(pticket_no+i)!= -1 ;i++){
        printf("\t%d\n",*(pticket_no+i));
    }
    textcolor(WHITE);
    printf("\n\nPress any key to go back to main menu.");
    getch();
    textcolor(YELLOW);
  return ;
}

void view_all_bookings()
{
    clrscr();
    FILE *fp ;
    fp = fopen("D:\\Programs\\RailwayReservationSystem\\myproject\\allbookings.dat","rb");
    if(fp == NULL){
        textcolor(LIGHTRED);
        printf(" No bookings done yet");
        fclose(fp);
      return ;
    }
    Passenger pr ;
    int i;
    printf(" TRAIN NO");
    gotoxy(30,1);
    printf("TICKET NO");
    gotoxy(60,1);
    printf("CLASS");
    gotoxy(80,1);
    printf("NAME");
    gotoxy(100,1);
    printf("MOBILE\n");
    for(i=0;i<=119;i++)
        printf("-");
     i = 1 ;
    while(fread(&pr,sizeof(pr),1,fp) == 1){
                gotoxy(1,i+3);
            printf("%s",pr.train_no);
                gotoxy(30,i+3);
            printf("%d",pr.ticketno);
                gotoxy(60,i+3);
            printf("%c",pr.p_class);
                gotoxy(80,i+3);
            printf("%s",pr.p_name);
                gotoxy(100,i+3);
            printf("%s\n",pr.mob_no);
                i++ ;
    }
    fclose(fp);
  return  ;
}

char* accept_train_no()
{
    printf("Enter Train number:");
    int valid;
    static char train_no[10];
    do{
        fflush(stdin);
        scanf("%s",train_no);
        if(strcmp(train_no,"0") == 0){
            gotoxy(1,25);
            printf("\t\t\t\t\t\t\t\t\t");
            gotoxy(1,25);
            textcolor(LIGHTRED);
            printf("Canceling input...");
            getch();
            textcolor(YELLOW);
          return NULL;
        }
          valid = check_train_no(train_no);
          if(valid == 0){
            gotoxy(1,25);
            textcolor(LIGHTRED);
            printf("Error! invalid train number.");
            getch();
            gotoxy(20,1);
            printf("\t\t\t\t\t\t");
            gotoxy(20,1);
            textcolor(YELLOW);
          }
        }while(valid == 0);
        clrscr();
  return train_no;
}

void view_booking(char *train_no)
{
    clrscr();
    FILE *fp ;
    fp = fopen("D:\\Programs\\RailwayReservationSystem\\myproject\\allbookings.dat","rb");
    if(fp == NULL){
        printf("No bookings done yet");
        getch();
        fclose(fp);
     return ;
    }
    Passenger pr ;
    int i;
    printf("TICKET NO");
    gotoxy(25,1);
    printf("CLASS");
    gotoxy(40,1);
    printf("NAME");
    gotoxy(65,1);
    printf("GENDER");
    gotoxy(80,1);
    printf("AGE");
    gotoxy(100,1);
    printf("MOBILE\n");
    for(i=0;i<=119;i++)
        printf("-");
     i = 1;
    while(fread(&pr,sizeof(pr),1,fp) == 1){
        if(strcmp(pr.train_no , train_no) == 0){
                printf("%d",pr.ticketno);
                gotoxy(25,i+2);
                printf("%c",pr.p_class);
                gotoxy(40,i+2);
                printf("%s",pr.p_name);
                gotoxy(65,i+2);
                printf("%c",pr.gender);
                gotoxy(80,i+2);
                printf("%d",pr.age);
                gotoxy(100,i+2);
                printf("%s\n",pr.mob_no);
                    i++ ;
        }
    }
    if(i == 1){
        printf("No details of train number %s found",train_no);
    }
    getch();
  fclose(fp);
  return ;
}

int cancel_ticket(int ticket_no)
{
    FILE *fp1 , *fp2;
    fp1 = fopen("D:\\Programs\\RailwayReservationSystem\\myproject\\allbookings.dat","rb+");
    if(fp1 == NULL){
        textcolor(LIGHTRED);
        printf("No bookings done yet");
        fclose(fp1);
      return -1;
    }
    fp2 = fopen("D:\\Programs\\RailwayReservationSystem\\myproject\\temp.dat","wb+");
    Passenger pr;
    int found = 0;
    while(fread(&pr,sizeof(pr),1,fp1) == 1){
        if(pr.ticketno != ticket_no){
            fwrite(&pr,sizeof(pr),1,fp2);
        }
        else
            found = 1 ;
    }
    fclose(fp1);
    fclose(fp2);
    if(found == 0){
        remove("D:\\Programs\\RailwayReservationSystem\\myproject\\temp.dat");
    }
    else{
        remove("D:\\Programs\\RailwayReservationSystem\\myproject\\allbookings.dat");
        rename("D:\\Programs\\RailwayReservationSystem\\myproject\\temp.dat","D:\\Programs\\RailwayReservationSystem\\myproject\\allbookings.dat");

    }
 return found ;
}

int cancel_train(char *ptrain_no)
{
    FILE *fp1 , *fp2;
    fp1 = fopen("D:\\Programs\\RailwayReservationSystem\\myproject\\allbookings.dat","rb+");
    if(fp1 == NULL)
    {
        textcolor(LIGHTRED);
        printf("No bookings done yet.");
     return -1 ;
    }
    fp2 = fopen("D:\\Programs\\RailwayReservationSystem\\myproject\\temp.dat","wb+");
    Passenger pr;
    int found=0 ;
    while(fread(&pr,sizeof(pr),1,fp1) == 1){
        if(strcmp(ptrain_no , pr.train_no) != 0){
            fwrite(&pr,sizeof(pr),1,fp2);
        }
        else
            found = 1 ;
    }
    fclose(fp1);
    fclose(fp2);
    if(found == 0){
        remove("D:\\Programs\\RailwayReservationSystem\\myproject\\temp.dat");
    }
    else if(found == 1){
        remove("D:\\Programs\\RailwayReservationSystem\\myproject\\allbookings.dat");
        rename("D:\\Programs\\RailwayReservationSystem\\myproject\\temp.dat","D:\\Programs\\RailwayReservationSystem\\myproject\\allbookings.dat");
    }
  return found;
}
