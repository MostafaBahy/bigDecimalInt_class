#include"BigDecimalInt.h"
using namespace std;


int main() {




    bool exit = true;
    BigDecimalInt ob, ob2, ob3;
    string str_num1, str_num2;



    // to test the class manually
    while (exit){
        string choice;

        cout<<"1. to add two big decimal numbers\n"
              "2. to subtract two big decimal numbers\n"
              "3. to compare between two big decimal numbers\n"
              "4. to get the size of a number\n"
              "5. to get the sign of a number\n"
              "6. Exit\n";

        cout<<"choose from the above menu if you want to test the class manually\n"
              "exit if you want to transmit to the auto test\n";
        cout<<"Enter your choice:- ";
        cin>>choice;


        // to check if the choice is correct or not (defensive)
        while (true){
            if (choice.length() > 1  ){
                cin.clear();
                cout << "wrong input :( Please just select a choice form the above :- ";
                cin >> choice;
            }
            else if (choice.substr(0,1) == "1"||choice.substr(0,1) == "2"||choice.substr(0,1) == "3" ||choice.substr(0,1) == "4"
                     ||choice.substr(0,1) == "5"||choice.substr(0,1) == "6")
            {
                break;
            }
            else{
                cin.clear();
                cout << "wrong input :( Please just select a choice form the above:- ";
                cin >> choice;
            }
        }


        if(choice =="1"){

            cout << "please enter the first big decimal number: ";
            cin >>str_num1;

            cout << "please enter the second big decimal number: ";
            cin >>str_num1;

            BigDecimalInt num1(str_num1),num2(str_num2);

//        to check the assignment operator of the class
            ob=num1;
            ob2=num2;

//        to check the plus operator of the class
            ob3 = ob + ob2;

//        to check the << operator of the class
            cout << ob<<" + " <<ob2<<" = " <<ob3<<endl;

        }

        if(choice =="2"){

            cout << "please enter the first big decimal number: ";
            cin >>str_num1;

            cout << "please enter the second big decimal number: ";
            cin >>str_num1;

            BigDecimalInt num1(str_num1),num2(str_num2);

//        to check the assignment operator of the class
            ob = num1;
            ob2 = num2;

//        to check the plus operator of the class
            ob3 = ob - ob2;

//        to check the << operator of the class
            cout << ob<<" - " <<ob2<<" = " <<ob3<<endl;

        }

        if(choice =="3"){


            cout << "please enter the first big decimal number: ";
            cin >>str_num1;

            cout << "please enter the second big decimal number: ";
            cin >>str_num1;

            BigDecimalInt num1(str_num1),num2(str_num2);

//        to check the assignment operator of the class
            ob = num1;
            ob2 = num2;




//        to check the > operator of the class
            if(ob>ob2){
                cout<< ob <<" is greater than " << ob2 <<endl;
            }

                //        to check the < operator of the class
            else if(ob<ob2){
                cout<< ob2 <<" is greater than " << ob <<endl;
            }

                //        to check the == operator of the class
            else if(ob==ob2){
                cout<< ob2 <<" is equal to " << ob <<endl;
            }
        }



        if(choice =="4"){
            cout << "please enter a big decimal number you want to know its size:  ";
            cin >>str_num1;
            BigDecimalInt num1(str_num1);


            //        to check the assignment operator of the class
            ob = num1;

            cout<< ob.size()<<endl;
        }


        if(choice =="5"){
            cout << "please enter a big decimal number you want to know its size:  ";
            cin >>str_num1;
            BigDecimalInt num1(str_num1);


            //        to check the assignment operator of the class
            ob = num1;

            cout<< ob.sign()<<endl;

        }

        if(choice =="6"){
            exit = false ;
        }


    }

    // ten test cases
    vector<string>vector_of_test_cases={"123456789012345678901234567890","-200000000000000000000000000000",
                                        "+113456789011345678901134567890","-6818267191839917000",
                                        "+583996284901973910","-241020189520031152002",
                                        "-11111111111111111111111111111111011111111111111111121",
                                        "2424242424242424242424242424242424242",
                                        "6000000000000000000900000000000000000000000000000000009",
                                        "69696969696969696969696969696996969696969969696996969696996996"};



// to test the class automatically
for (int i = 0; i  < 10  ;i++){

    BigDecimalInt number1(vector_of_test_cases[i]),number2(vector_of_test_cases[i+1]),number3;

    number3 = number1 + number2;
    cout << number1 << " + " <<number2<< " = " << number3 << endl;

    number3 = number1 - number2;
    cout << number1 << " - " << number2 << " = " << number3 << endl;

    //        to check the > operator of the class
    if(number1 > number2){
        cout<< number1 <<" is greater than " << number2 <<endl;
    }

        //        to check the < operator of the class
    else if(number1 < number2){
        cout<< number2 <<" is greater than " << number1 <<endl;
    }

        //        to check the == operator of the class
    else if(number1 == number2){
        cout<< number1 <<" is equal to " << number2 <<endl;
    }


    cout<<"the size of  "<<number1<<" is "<<number1.size()<<endl;

    cout<<"the size of  "<<number2<<" is "<<number2.size()<<endl;

    cout<<"the sign of  "<<number1<<" is "<<number1.sign()<<endl;

    cout<<"the sign of  "<<number2<<" is "<<number2.sign()<<endl;

    cout<<"\n\n";



}









    return 0;
}
