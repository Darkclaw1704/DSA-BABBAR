#include <iostream>
using namespace std;

int hwProblem1(){

    int number, row=1, col=1, output=1;
    cin>>number;

    while (row<=number)
    {
        col=1;
        while(col<=row){
            cout<<output<<" ";
            output+=1;
            col+=1;
        }
        cout<<endl;
        row+=1;
    }

    return 0;

}

int hwProblem2(){

    int number, row = 1, column , printNum;
    cin>>number;

    while (row <= number)
    {
        column = 1;
        printNum = row;
        while (column<=row)
        {
            cout<<printNum<< " " ;
            printNum+=1;
            column+=1;
        }
        cout<<endl;
        row+=1;

    }

    return 0;


}

int hwProblem3(){

    int number, row=1, column;
    cin>>number;

    char printCharacter = 65;

    while (row<=number)
    {
        column=1;
        printCharacter = 64 + row;
        while (column<=number)
        {
            cout<<printCharacter<<" ";
            column+=1;
        }
        row+=1;
        cout<<endl;
    }

    return 0;

}

int hwProblem4(){

    int number, row=1, column;
    char    printCharacter = 64;
    cin>>number;

    while (row<=number)
    {
        column = 1;
        while (column<=number)
        {
            printCharacter+=1;
            cout<<printCharacter<< " ";
            column+=1;
        }
        row+=1;
        cout<<endl;

    }


    return 0;

}

int hwProblem5(){

    int number, row=1, column;
    char character=65;
    cin>>number;

    while (row<=number)
    {
        column=1;
        while (column<=row)
        {
            cout<<character<< " ";
            column+=1;
        }
        cout<<endl;
        character+=1;
        row+=1;

    }


    return 0;

}

int hwProblem6(){

    int number, row=1, column;
    char character=65;

    cin>>number;

    while (row<=number)
    {
        column=1;
        while (column<=row)
        {
            cout<<character<<" ";
            character+=1;
            column+=1;
        }
        row+=1;

        cout<<endl;


    }


    return 0;

}

int hwProblem7(){

    int number, row=1, column;
    cin>>number;
    char character = 64 + number + 1;

    while (row<=number)
    {
        character -= row;
        column=1;
        while (column<=row)
        {
            cout<<character<<" ";
            character+=1;
            column+=1;
        }
        character = 64 + number + 1;
        cout<<endl;
        row+=1;
    }


    return 0;

}

int hwProblem8(){

    int number, row, column;
    cin>>number;
    row=number;

    while (row>=1)
    {
        column = 1;
        while (column<=row)
        {
            cout<<"* ";
            column+=1;
        }
        row-=1;
        cout<<endl;
    }

    // int counter = 1;

    // while (counter<=number)
    // {
    //     char x = "* "*(number-counter+1);
    //     cout<<x;
    //     counter+=1;
    // }


    return 0;

}

int hwProblem9(){
    int number, row=1, column,dashes;
    cin>>number;

    while (row<=number){
        column = 1 ;
        dashes=number - row + 1;

        while (dashes>=1){
            cout<<" ";
            dashes-=1;
            column+=1;
        }

        while (column<=number){
            cout<<"*";
            column+=1;
        }

        row+=1;
        cout<<endl;
    }

    return 0;
}

int hwProblem10(){
    int number, row=1, column, dashes;
    cin>>number;

    while (row<=number)
    {

        column=1;
        while(column<=number - row + 1){
            cout<< column <<" ";
            column+=1;
        }

        dashes=1;
        while (dashes<=(2*row)-2){
            cout<<"* ";
            column+=1;
            dashes+=1;
        }

        while (column<=2*number){
            cout<<2*number - column + 1<<" ";
            column+=1;
        }

        row+=1;
        cout<<endl;
    }
    return 0;
}

int main() {
    cout<<"enter number : ";

    hwProblem10();

    return 0;
}
