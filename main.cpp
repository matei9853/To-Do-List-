#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;


//ifstream fin("tasks.txt");
//ofstream fout("tasks.txt");

struct Task{
    string description;
    bool complete;
};

vector<Task> tasks;

void displayMenu();
void addTask();
void viewTasks();
void markComplete();
void deleteTask();
void saveTasks();
void loadTasks();


int main()
{
    loadTasks();

    int choice;

    while(true)
    {
        displayMenu();

        cout<<" Enter your choice : ";
        cin >> choice ;
        cin.ignore();

        switch( choice )
        {
            case 1:
                addTask();
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                markComplete();
                break;
            case 4:
                deleteTask();
                break;
            case 5:
                saveTasks();
                cout<<" Task Saved! \n";
                break;
            case 6:
                saveTasks();
                cout<<" Goodbye! \n";
                return 0;
            default:
                cout<<"Invalid choide! PLease try again! \n";
        }
        cout<<'\n'<<'\n';
    }

    return 0;
}


void displayMenu()
{
    cout<<'\n';
    cout<<"=======TO-DO LIST MANAGER MENU======="<<'\n';
    cout<<"Option 1 :   Add a task"<<'\n';
    cout<<"Option 2 :   View all tasks"<<'\n';
    cout<<"Option 3 :   Mark a task as complete"<<'\n';
    cout<<"Option 4 :   Delete a task"<<'\n';
    cout<<"Option 5 :   Save all tasks"<<'\n';
    cout<<"Option 6 :   Exit Menu"<<'\n';
    cout<<"====================================="<<'\n';
}

void loadTasks()
{
    ifstream fin("tasks.txt");

    if( !fin )
    {
        cout<<"First time running! No saved tasks found \n \n";
        return;
    }

    Task temp;

    while( getline( fin , temp.description) )
    {
        fin >> temp.complete;
        fin.ignore();
        tasks.push_back(temp);
    }

    fin.close();

    if( !tasks.empty() )
    {
        cout<< "Loaded " << tasks.size() << " from file!" <<'\n';
    }
}

void addTask()
{
    Task newTask;

    cout<<" Introduce Task : ";
    getline( cin , newTask.description );

    if( newTask.description.empty() )
    {
        cout<<" Invalid! Cannot be empty! "<<'\n';
        return;
    }

    newTask.complete = false;

    tasks.push_back( newTask );
    
    cout<< " Task added succesfully! "<<'\n';

    return;

}

void viewTasks()
{
    cout<< '\n' << "========Task list========"<<'\n';

    for(int i = 0 ; i < tasks.size() ; i++)
    {
        cout<< i + 1 << '.' << ' ';

        if( tasks[i].complete == true )
            cout << "[DONE]" << ' ';
        else
            cout << "[TO-DO]" << ' ';

        cout << tasks[i].description << '\n' ; 
    }

    return;
}

void markComplete()
{
    int i;

    if( tasks.empty() )
    {
        cout<< "No task to complete !";
        return;
    }

    viewTasks();

    cout << "Enter completed task number : ";
    cin>>i;

    if( i < 1 || i > tasks.size())
    {
        cout<<"Invalid task number!";
        return;
    }

    tasks[i - 1].complete = true;
    cout<<" Task completed ! Congratulations ! ";
}

void deleteTask()
{
    if( !tasks.size() )
    {
        cout<< " No file to delete! ";
        return;
    }

    viewTasks();

    int task_number;
    cout<< " Enter task number to delete: ";
    cin>>task_number;

    if( task_number < 1 || task_number > tasks.size() )
    {
        cout<<"Invalid task number!";
        return;
    }

    tasks.erase( tasks.begin() + (task_number - 1));

    cout<< " Task deleted succesfully !" ; 
}

void saveTasks()
{
    ofstream fout("tasks.txt");

    if( !fout )
    {
        cout<< "Error ! Could not save";
        return ;
    }

    for(int i = 0 ; i < tasks.size() ; i++ )
    {
        fout << tasks[i].description<<'\n';
        fout << tasks[i].complete<<'\n';
    }

    fout.close();
}