#include <stdio.h>
#include<stdlib.h>
#include"conio2.h"
#include"rlyres.h"

int main()
{
    int choice,check,ticket_no;
    int result ;
    int *pticket_no ;
    char *pmob_no , *ptrain_no;
    Passenger *psn;
    add_trains();
    while(1){
       clrscr();
       choice = enterchoice();
       if(choice == 9){
            exit(0);
       }
           switch(choice){
                case 1 :
                        clrscr();
                        view_trains();
                        break;
                case 2 :
                        clrscr();
                        psn = get_passenger_details();
                        if(psn != NULL){
                            check = book_ticket(*psn);
                            if(check == -1 ){
                                printf("\nBooking Failed!");
                                getch();
                            }
                            else{
                                clrscr();
                                textcolor(LIGHTGREEN);
                                printf("Ticket successfully booked\n");
                                printf("your ticket number is %d",check);
                                textcolor(WHITE);
                                printf("\n\n\n Press any key to go back...");
                                getch();
                            }
                        }
                        break;
                case 3 :
                        clrscr();
                        ticket_no = accept_ticket_no();
                        if(ticket_no != 0){
                            view_ticket(ticket_no);
                        }
                        textcolor(WHITE);
                        printf("\n\n Press any key to go back to main menu.");
                        getch();
                        clrscr();
                        break;
                case 4 :
                        clrscr();
                        pmob_no = accept_mob_no();
                        if(pmob_no!=NULL){
                            pticket_no = get_ticket_no(pmob_no);
                            view_all_tickets(pmob_no,pticket_no);
                        }
                        break;
                case 5 :
                        view_all_bookings();
                        textcolor(WHITE);
                        printf("\n\nPress any key to go back to the main menu.");
                        getch();
                        break;
                case 6 :
                        clrscr();
                        gotoxy(90,1);
                        textcolor(LIGHTGREEN);
                        printf("PRESS 0 TO EXIT");
                        gotoxy(1,1);
                        textcolor(YELLOW);
                       ptrain_no = accept_train_no();
                       if(ptrain_no!= NULL )
                        view_booking(ptrain_no);
                       getch();
                        break;
                case 7 :
                        clrscr();
                       ticket_no = accept_ticket_no();
                       if(ticket_no != 0){
                        result = cancel_ticket(ticket_no);
                        if(result == 0){
                            textcolor(LIGHTRED);
                            printf("\n\n Sorry! No ticket booked against the ticket number %d",ticket_no);
                        }
                        else if(result == 1){
                            textcolor(LIGHTGREEN);
                            printf("\n\n Ticket number %d is successfully canceled!!",ticket_no);

                        }
                        textcolor(WHITE);
                        printf("\n\n Press any key to go back to main menu.");
                       }
                        getch();
                        clrscr();
                        break;
                case 8 :
                        clrscr();
                        gotoxy(90,1);
                        textcolor(LIGHTGREEN);
                        printf("PRESS 0 TO EXIT");
                        gotoxy(1,1);
                        textcolor(YELLOW);
                       ptrain_no = accept_train_no();
                       if(ptrain_no != NULL){
                            result = cancel_train(ptrain_no);
                            if(result == 0){
                                textcolor(LIGHTRED);
                                printf("\n\n Sorry! NO tickets booked in the train number %s",ptrain_no);
                            }
                            else if(result == 1){
                                textcolor(LIGHTGREEN);
                                printf("\n\n Train number %s successfully canceled",ptrain_no);
                            }
                            textcolor(WHITE);
                            printf("\n\n Press any key to go back to main menu.");
                       }
                        getch();
                        clrscr();
                        break;

                default :
                        textcolor(LIGHTRED);
                        printf(" \nYou have entered wrong choice !! try Again ");
                        getch();
                        clrscr();
                        enterchoice();
           }

    }

    return 0;
}
