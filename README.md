# To-Do-List-
First project . A simple 'to-do list' manager build in c++

# To-Do List Manager

A simple command-line to-do list application written in C++. This project helps you manage your daily tasks with features to add, view, complete, and delete tasks. All tasks are saved to a file for persistence.

## Features

-  Add new tasks
-  View all tasks with completion status
-  Mark tasks as complete
-  Delete tasks
-  Save tasks to file (automatic persistence)
-  Load tasks on startup

### Menu Options

1. **Add a task** - Enter a task description
2. **View all tasks** - Display all tasks with their status
3. **Mark task as complete** - Mark a specific task as done
4. **Delete a task** - Remove a task from the list
5. **Save tasks** - Manually save tasks to file
6. **Exit** - Save and quit the program

## File Storage

Tasks are automatically saved to `tasks.txt` in the same directory as the executable. The file is created automatically on first save.

## Example Usage
```
=======TO-DO LIST MANAGER MENU=======
Option 1 :   Add a task
Option 2 :   View all tasks
Option 3 :   Mark a task as complete
Option 4 :   Delete a task
Option 5 :   Save all tasks
Option 6 :   Exit Menu
=====================================
 Enter your choice : 1

 Introduce Task : Buy groceries
 Task added succesfully!

 Enter your choice : 2

========Task list========
1. [TO-DO] Buy groceries
```

## Technologies Used

- **Language**: C++
- **Libraries**: iostream, fstream, vector, string

## What I Learned

- Working with C++ vectors and structs
- File I/O operations (reading and writing to files)
- Menu-driven program design
- Data persistence across program sessions

## Future Improvements

- Add task priorities (high, medium, low)
- Add due dates for tasks
- Sort tasks by completion status or date
- Add search/filter functionality
- Improve UI with colors

## Author

Voicu Matei - 10.12.2025

## License

This project is open source and available for educational purposes.
