//
//  main.c
//  InterestCalc
//
//  Created by Zain Hemani on 2014-10-23.
//  Copyright (c) 2014 Zain Hemani. All rights reserved.
//

#include <stdio.h>
int main() {
    
    //Creating and Initializing Variables
    float loan=-1, yearInt=-1, monthPay=-1, n=-1, mir;
    int ptr=0;
    
    //While loop to make sure the loan value is positive
    while (loan < 0) {
        printf("Please enter the amount of the loan: "); scanf("%f", &loan);
    }
    
    //While loop to make sure yearly interest rate is positive
    while (yearInt < 0) {
        printf("Please enter the yearly interest rate (as a whole number): ");
        scanf("%f", &yearInt);
        yearInt=yearInt / 100;
    }
    
    //While loop to make sure the monthly payment is positive
    while (monthPay < 0) {
        printf("Please enter the monthly payment amount: ");
        scanf("%f", &monthPay);
    }
    
    //While loop to make sure n is positive
    while (n < 0) {
        printf("Please enter the number of monthly payments: "); scanf("%f", &n);
    }
    
    //newLoan variable to keep track of the new loan value
    float newLoanAmount;
    //Calculate interest amount based on n and while loan is >mp
    mir=yearInt / 12;
    while(ptr < n && loan > 0) {
        newLoanAmount=((loan * (1 + mir)) - monthPay);
        if (newLoanAmount > 0) {
            ptr++;
            printf("The loan balance after %d month(s) is: %.2f\n", ptr, newLoanAmount);
            loan=newLoanAmount;
        }
        else {
            printf("The last payment is: %.2f\n", loan * (1 + mir));
            loan=newLoanAmount;
        }
    }
    return 0;
}

