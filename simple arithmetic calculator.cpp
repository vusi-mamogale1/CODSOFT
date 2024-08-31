#include <iostream>
#include <string>

using namespace std;  //std namespace

int main()
{
    //declaring variable
    string equation, _operator, accum1, accum2="";
    int result;


    cout<<"Enter expression [eg 2+2 no space] : ";  //prompt user input
    cin>>equation;

    for(int i =0; i< equation.length(); i++)
    {
        if(isdigit(equation[i]))
        {
            accum1+=equation[i];;
        }
        else if(!isdigit(equation[i]))
        {
            _operator = equation[i];
            equation.erase(0,i+1);
            break;
        }
    }
    accum2 = equation;  // assing the last digits int0 accum2

    while(!equation.empty())
    {
        if(_operator =="+")
        {
            result = stoi(accum1) + stoi(accum2);   //convert string to int

        }
        else if(_operator == "-")
        {
            result = stoi(accum1) - stoi(accum2); //convert string to int

        }
        else if(_operator == "*")
        {
            result = stoi(accum1) * stoi(accum2); //convert string to int

        }
        else if(_operator=="/")
        {
          result = stoi(accum1) / stoi(accum2); //convert string to int

        }
        else
        {
            cout<<"Invalid operator";  //error operand message
            return 1;
        }

        cout<<accum1<<" "<<_operator<<" "<<accum2<<" = "<<result;  //display result

        equation.erase(); //clear the container
        _operator.erase();  //clear the container
        accum1.erase();      //clear the container
        accum2.erase(); //clear the container

        cout<<"\n-----------------------------"<<endl;

        cout<<"Enter expression [eg 2+2 no space] : ";
        cin>>equation;

        for(int i =0; i< equation.length(); i++)
        {
            if(isdigit(equation[i]))
            {
                accum1+=equation[i];;
            }
            else if(!isdigit(equation[i]))
            {
                _operator = equation[i];
                equation.erase(0,i+1);
                break;
            }
        }
        accum2 = equation;  // assingn the last digits int0 accum2
    }

    return 0; //program end
}