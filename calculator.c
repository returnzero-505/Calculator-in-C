#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double add(double a, double b){
    return a+b;
}

double subtract(double a, double b){
    return a-b;
}

double multiply(double a, double b){
    return a*b;
}

double divide(double a, double b){
    if(b==0.0){
        return NAN; //NAN means not a number and it's a part of math package
    }
    return a/b;
}

double mod(double a, double b){
    if(b==0.0){
        return NAN;
    }
    return fmod(a,b);
}

//to clear the extra characters incase of alphanumeric inputs
void clearInputBuffer() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
        // Discard remaining characters
    }
}

int checksingle(int calc, double ans, double x){
    
}

//we would e using call by reference over here, so that the values of a and b changes in main(), only for dual inputs
int checkdouble(int calc, double ans, double *a, double *b){
    int choice;
    if(calc==1){
        printf("\nThe previous result was : %lf", ans);
        printf("\nDo you want to reuse the previous result? \n1. yes || 2. no : ");
        if(scanf("%d", &choice)!=1){
            printf("\nINVALID INPUT");
            clearInputBuffer();
            return 0;
        }
        if(choice==1){
            *a=ans;
            printf("\nEnter second number : ");
            if(scanf("%lf", b)!=1){
                printf("\nINVALID INPUT");
                clearInputBuffer();
                *b=0.0; return 0;
            } 
            else{
                return 1;
            }
        }
        else if(choice==2){
            printf("\nEnter two numbers : ");
            if(scanf("%lf%lf", a, b)!=2){
                printf("\nINVALID INPUT");
                clearInputBuffer();
                *a=0.0; *b=0.0;
                return 0;
            } 
            else{
                return 1;
            }
        }
        else{
            printf("\nINVALID INPUT"); return 0;
        }
    }
    else{
        printf("\nEnter two numbers : ");
        if(scanf("%lf%lf", a, b)!=2){
            printf("\nINVALID INPUT");
            clearInputBuffer();
            *a=0.0;*b=0.0;
            return 0;
        } 
        else{
            return 1;
        }
    }
}

int main(){
    int n, ch, calc=0;
    double ans=0.0, result = 0.0, a, b;
    printf("\n1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Modulus\n6. STOP");
    while(1){
        printf("\nEnter your choice of calculation : ");
        if(scanf("%d", &n)!=1){
            printf("\nINVALID INPUT"); //alphabet checking
            clearInputBuffer(); 
            n=0;
            continue;
        }
        switch(n){
        
            case 1 :ch = checkdouble(calc, ans, &a, &b);
                    if (ch==1){
                        ans = add(a,b); calc=1;
                    }
                    else{
                        break;
                    }
                    printf("\n%lf\n", ans); break;
        
            case 2 :ch = checkdouble(calc, ans, &a, &b);
                    if (ch==1){
                        ans = subtract(a,b); calc=1;
                    }
                    else{
                        break;
                    }
                    printf("\n%lf\n", ans); break;

            case 3 :ch = checkdouble(calc, ans, &a, &b);
                    if (ch==1){
                        ans = multiply(a,b); calc=1;
                    }
                    else{
                        break;
                    }
                    printf("\n%lf\n", ans); break;

            case 4 :ch = checkdouble(calc, ans, &a, &b);
                    if (ch==1){
                        result = divide(a,b); 
                        if(isnan(result)){
                            printf("SYNTAX ERROR"); break;
                        }
                        else{
                            ans = result; calc=1;
                        }
                    }
                    else{
                        break;
                    }
                    printf("\n%lf\n", ans); break;

            case 5 :ch = checkdouble(calc, ans, &a, &b);
                    if (ch==1){
                        result = mod(a,b); 
                        if(isnan(result)){
                            printf("SYNTAX ERROR"); break;
                        }
                        else{
                            ans = result; calc=1;
                        }
                    }
                    else{
                        break;
                    }
                    printf("\n%lf\n", ans); break;
        
            case 6 :exit(0);
        
            default : printf("INVALID CHOICE"); //checkdouble if numeric but unavailale case
        }
    }

    return 0;
}