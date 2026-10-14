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

double power(double a, double b){
    return pow(a,b);
}   

double squareRoot(double x){
    if(x<0.0){
        return NAN;
    }
    return sqrt(x);
}

double cubeRoot(double x){
    return cbrt(x);
}

double absolute(double x){
    return fabs(x);
}

double logarithm(double x){
    if(x<=0.0){
        return NAN;
    }
    return log(x);
}

double logarithmBase10(double x){
    if(x<=0.0){
        return NAN;
    }
    return log10(x);
}

double logarithmBase2(double x){
    if(x<=0.0){
        return NAN;
    }
    return log2(x);
}

double exponential(double x){
    return exp(x);
}

double sine(double x){
    return sin(x);
}

double cosine(double x){
    return cos(x);
}

double tangent(double x){
    return tan(x);
}

double arcsine(double x){
    if(x<-1.0 || x>1.0){
        return NAN;
    }
    return asin(x);
}

double arccosine(double x){
    if(x<-1.0 || x>1.0){
        return NAN;
    }
    return acos(x);
}

double arctangent(double x){
    return atan(x);
}

double hypotenuse(double a, double b){
    return hypot(a,b);
}

//to clear the extra characters incase of alphanumeric inputs
void clearInputBuffer() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
        // Discard remaining characters
    }
}

int checksingle(int calc, double ans, double *x){
    int choice;
    if(calc==1){
        printf("The previous answer was : %lf", ans);
        printf("Do you want to reuse the previous answer?\n1. yes || 2. no :");
        if(scanf("%d", &choice)!=1){
            printf("\nINVALID INPUT");
            clearInputBuffer();
            return 0;
        }
        if(choice==1){
            *x=ans;
            return 1;
        }
        else if(choice==2){
            printf("\nEnter new number : ");
            if(scanf("%lf", x)!=1){
                printf("\nINVALID INPUT");
                clearInputBuffer(); 
                *x=0.0; return 0;
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
        printf("\nEnter new number : ");
        if(scanf("%lf", x)!=1){
            printf("\nINVALID INPUT");
            clearInputBuffer();
            *x=0.0; return 0;
        }
        else{
            return 1;
        }
    }
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
    double ans=0.0, result = 0.0, a, b, x;
    printf("\n1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Modulus\n6. Power\n7. Square Root\n8. Cube Root\n9. Absolute Value\n10. Natural Logarithm\n11. Logarithm Base 10\n12. Logarithm Base 2\n13. Exponential\n14. Sine\n15. Cosine\n16. Tangent\n17. Arcsine\n18. Arccosine\n19. Arctangent\n20. Hypotenuse\n21. STOP");
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
                            printf("\nMATH ERROR"); break;
                        }
                        else if(!isfinite(result)){
                            printf("\nMATH ERROR");break;
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
                            printf("\nMATH ERROR"); break;
                        }
                        else if(!isfinite(result)){
                            printf("\nMATH ERROR");break;
                        }
                        else{
                            ans = result; calc=1;
                        }
                    }
                    else{
                        break;
                    }
                    printf("\n%lf\n", ans); break;
        
            case 6 :ch = checkdouble(calc, ans, &a, &b);
                    if(ch==1){
                        result = power(a,b);
                        if(isnan(result)){
                            printf("\nMATH ERROR");
                            break;
                        }
                        else if(!isfinite(result)){
                            printf("\nMATH ERROR");
                            break;
                        }
                        else{
                            ans = result; calc = 1;
                        }
                    }
                    else{
                        break;
                    }
                    printf("\n%lf\n", ans); break;

            case 7 :ch = checksingle(calc, ans, &x);
                    if(ch==1){
                        result = squareRoot(x);
                        if(isnan(result)){
                            printf("\nMATH ERROR");
                            break;
                        }
                        else{
                            ans = result; calc = 1;
                        }
                    }
                    else{
                        break;
                    }
                    printf("\n%lf\n", ans); break;

            case 8 :ch = checksingle(calc, ans, &x);
                    if(ch==1){
                        ans = cubeRoot(x); calc = 1;
                    }
                    else{
                        break;
                    }
                    printf("\n%lf\n", ans); break;

            case 9 :ch = checksingle(calc, ans, &x);
                    if(ch==1){
                        ans = absolute(x); calc = 1;
                    }
                    else{
                        break;
                    }
                    printf("\n%lf\n", ans); break;

            case 10 :ch = checksingle(calc, ans, &x);
                    if(ch==1){
                        result = logarithm(x);
                        if(isnan(result)){
                            printf("\nMATH ERROR");
                            break;
                        }
                        else{
                            ans = result; calc = 1;
                        }
                    }
                    else{
                        break;
                    }
                    printf("\n%lf\n", ans); break;

            case 11 :ch = checksingle(calc, ans, &x);
                    if(ch==1){
                        result = logarithmBase10(x);
                        if(isnan(result)){
                            printf("\nMATH ERROR");
                            break;
                        }
                        else{
                            ans = result; calc = 1;
                        }
                    }
                    else{
                        break;
                    }
                    printf("\n%lf\n", ans); break;

            case 12 :ch = checksingle(calc, ans, &x);
                    if(ch==1){
                        result = logarithmBase2(x);
                        if(isnan(result)){
                            printf("\nMATH ERROR");
                            break;
                        }
                        else{
                            ans = result; calc = 1;
                        }
                    }
                    else{
                        break;
                    }
                    printf("\n%lf\n", ans); break;

            case 13 :ch = checksingle(calc, ans, &x);
                    if(ch==1){
                        result = exponential(x);
                        if(!isfinite(result)){
                            printf("\nMATH ERROR");
                            break;
                        }
                        else{
                            ans = result; calc = 1;
                        }
                    }
                    else{
                        break;
                    }
                    printf("\n%lf\n", ans); break;

            case 14 :ch = checksingle(calc, ans, &x);
                    if (ch==1){
                        ans = sine(x); calc=1;
                    }
                    else{
                        break;
                    }
                    printf("\n%lf\n", ans); break;

            case 15 :ch = checksingle(calc, ans, &x);
                    if (ch==1){
                        ans = cosine(x); calc=1;
                    }
                    else{
                        break;
                    }
                    printf("\n%lf\n", ans); break;

            case 16 :ch = checksingle(calc, ans, &x);
                    if (ch==1){
                        ans = tangent(x); calc=1;
                    }
                    else{
                        break;
                    }
                    printf("\n%lf\n", ans); break;

            case 17 :ch = checksingle(calc, ans, &x);
                    if(ch==1){
                        result = arcsine(x);
                        if(isnan(result)){
                            printf("\nMATH ERROR");
                            break;
                        }
                        else{
                            ans = result; calc = 1;
                        }
                    }
                    else{
                        break;
                    }
                    printf("\n%lf\n", ans); break;

            case 18 :ch = checksingle(calc, ans, &x);
                    if(ch==1){
                        result = arccosine(x);
                        if(isnan(result)){
                            printf("\nMATH ERROR");
                            break;
                        }
                        else{
                            ans = result; calc = 1;
                        }
                    }
                    else{
                        break;
                    }
                    printf("\n%lf\n", ans); break;

            case 19 :ch = checksingle(calc, ans, &x);
                    if(ch==1){
                        ans = arctangent(x); calc = 1;
                    }
                    else{
                        break;
                    }
                    printf("\n%lf\n", ans); break;

            case 20 :ch = checkdouble(calc, ans, &a, &b);
                    if(ch==1){
                        ans = hypotenuse(a,b); calc = 1;
                    }
                    else{
                        break;
                    }
                    printf("\n%lf\n", ans); break;

            case 21 :exit(0);
        
            default : printf("INVALID CHOICE"); //check if numeric but unavailale case
        }
    }

    return 0;
}