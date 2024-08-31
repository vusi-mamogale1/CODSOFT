#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>
#include <new>
#include <cstdlib>

using namespace std;

class List  //declaring a list class
{
private:
    string task;
    string status;

public:
    List() //initialising the member variables
    {
        this->task = "Add task";
        this->status = "Pending";
    }
    void _menu() const
    {
        cout<<"\n\n*************TO-DO-LIST************"<<endl;
        cout<<"1 Add task."
            <<"\n2 View tasks and status."
            <<"\n3 Complete task."
            <<"\n4 Remove task."<<endl;
    }

    void _addTask()
    {
        vector<string> _tasks;
        fstream file1("tasks.txt",ios::app);

        if(!file1.is_open())
        {
            cout<<"error opening file"<<endl;
            exit(1);
        }
        else
            {
            cin.ignore();
            do
            {
                cout<<"Add task or [press # to quit] : ";

                getline(cin,this->task);

                if(this->task =="#")
                {
                    break;
                }
                if(!this->task.empty())
                {
                    _tasks.push_back(this->task);
                }
            }while(!this->task.empty());

            if(this->task.empty())
            {
                cout<<"\n----------No task added----------"<<endl;
            }
            else
            {
                 cout<<"\n----------Task(s) added to database----------"<<endl;

                 for(int i=0;i<_tasks.size();i++)
                 {
                    file1<<_tasks[i]<<","<<this->status<<endl;
                 }

            }
        }
        file1.close();
    }

    void _viewTask()
    {
        string line;
        vector<string> taskName;
        vector<string> taskStatus;
        int pos, x=0;
        fstream readFile("tasks.txt", ios::in);

        if(!readFile.is_open())
        {
            cout<<"error opening file"<<endl;
            exit(1);
        }
        else
        {

            cout<<"----------Your tasks----------"<<endl;
            cin.ignore();
            while(getline(readFile, line))
            {

                pos = line.find(",");
                taskName.push_back(line.substr(0,pos));
                line.erase(0,pos+1);
                taskStatus.push_back(line.substr(0,line.length()));
                line.erase(0,line.length());
                x++;
            }

            if(taskName.empty())
            {
                cout<<"No tasks to view"<<endl;
            }

            for(int i=0; i< taskName.size();i++)
            {
                cout<<i+1<<") Task name : "<<taskName[i]<<" .......Status ["<<taskStatus[i]<<"]"<<endl;
            }
            cout<<"\n---------------------------------------------------------------------"<<endl;
        }
        readFile.close();
    }

    void _completeTask()
    {
        string line;
        vector<string> taskName;
        vector<string> taskStatus;
        int pos, opt, x, count=0;
        fstream readFile("tasks.txt", ios::in);

        if(!readFile.is_open())
        {
            cout<<"error opening file"<<endl;
            exit(1);
        }
        else
        {

            cout<<"----------Your tasks----------"<<endl;
            cin.ignore();
            while(getline(readFile, line))
            {

                pos = line.find(",");
                taskName.push_back(line.substr(0,pos));
                line.erase(0,pos+1);
                taskStatus.push_back(line.substr(0,line.length()));
                line.erase(0,line.length());
                x++;
            }

            readFile.close();
            cout<<"\nEnter a task id to complete : \n"<<endl;

            for(int i=0; i< taskName.size();i++)
            {
                if(taskStatus[i] =="Pending")
                {
                    cout<<"Task id: ("<<i+1<<") Task name : "<<taskName[i]<<" .......Status ["<<taskStatus[i]<<"]"<<endl;
                    count+=1;
                }
                else
                    continue;
            }
            if(count ==0)
            {
                cout<<"\n\nNo pending task..."<<endl;
            }
            else {

                cin>>opt;

                taskStatus[opt-1]="Completed";

                fstream outFile("tasks.txt", ios::out);
                for(int i=0; i< taskName.size();i++)
                {
                    outFile<<taskName[i]<<","<<taskStatus[i]<<endl;
                }
                cout<<"\nTask completed sucessfully..."<<endl;
                    cout<<"\n---------------------------------------------------------------------"<<endl;
            }

        }

        readFile.close();
    }

    void _removeTask()
    {


        string line;
        vector<string> taskName;
        vector<string> taskStatus;
        int pos, opt=0;
        fstream readFile("tasks.txt", ios::in);

        if(!readFile.is_open())
        {
            cout<<"error opening file"<<endl;
            exit(1);
        }
        else
        {

            cout<<"----------Delete a task----------\n\n"<<endl;
            cin.ignore();
            while(getline(readFile, line))
            {
                //this block of code extract data from external file and stores in the vectors
                pos = line.find(",");
                taskName.push_back(line.substr(0,pos));
                line.erase(0,pos+1);
                taskStatus.push_back(line.substr(0,line.length()));
                line.erase(0,line.length());

            }
            readFile.close();

            if(taskName.size() == 0 || taskStatus.size()==0) //check if the vectors have data
            {
                cout<<"There are no tasks"<<endl;
            }
            else
            {
                cout<<"Enter the task id to delete a task\n"<<endl;

                for(int i=0; i< taskName.size();i++)
                {
                    cout<<"Task id : "<<i<<") Task name : "<<taskName[i]<<" .......Status ["<<taskStatus[i]<<"]"<<endl;
                }

                cin>>opt;

                //removing record from a file
                taskName.erase(taskName.begin()+opt);
                taskStatus.erase(taskStatus.begin()+opt);


                fstream outFile("tasks.txt", ios::out);

                for(int i=0; i< taskName.size();i++)
                {
                    outFile<<taskName[i]<<","<<taskStatus[i]<<endl;
                }
                cout<<"\nTask deleted sucessfully..."<<endl;
                cout<<"\n---------------------------------------------------------------------"<<endl;
            }
        }
        readFile.close();

    }

    };

    int main() // main function
    {

        List a; //declaring a list object
        int opt;  //declaring an option variable

        a._menu();  //calling a menu method
        cin>>opt;

        while(opt != 0)
        {
            if(opt == 1)
            {
                a._addTask();  //calling add task method
            }
            else if(opt == 2)
            {
                a._viewTask();  //calling view task method
            }
            else if(opt == 3)
            {

                a._completeTask();  //calling complete task method
            }
            else if(opt == 4)
            {
                a._removeTask();  //calling remove task method
            }
            else
            {
                cout<<"Invalid option"<<endl;
            }

            a._menu();   //calling menu method
            cin>>opt;
        }



        return 0; //program end

        }





